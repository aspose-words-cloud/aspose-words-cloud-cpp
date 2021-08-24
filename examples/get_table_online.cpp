auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::GetTableOnlineRequest > request(
    new requests::GetTableOnlineRequest(
        requestDocument, std::make_shared< int32_t >(1)
    )
);
wordsApi->getTableOnline(request);