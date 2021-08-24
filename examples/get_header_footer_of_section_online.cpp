auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.doc"), std::istream::binary));
std::shared_ptr< requests::GetHeaderFooterOfSectionOnlineRequest > request(
    new requests::GetHeaderFooterOfSectionOnlineRequest(
        requestDocument, std::make_shared< int32_t >(0), std::make_shared< int32_t >(0)
    )
);
wordsApi->getHeaderFooterOfSectionOnline(request);