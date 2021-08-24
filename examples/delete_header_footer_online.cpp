auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.doc"), std::istream::binary));
std::shared_ptr< requests::DeleteHeaderFooterOnlineRequest > deleteRequest(
    new requests::DeleteHeaderFooterOnlineRequest(
        requestDocument, std::make_shared< std::wstring >(L""), std::make_shared< int32_t >(0)
    )
);
wordsApi->deleteHeaderFooterOnline(deleteRequest);