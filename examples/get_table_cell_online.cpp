auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::GetTableCellOnlineRequest > request(
    new requests::GetTableCellOnlineRequest(
        requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0)
    )
);
wordsApi->getTableCellOnline(request);