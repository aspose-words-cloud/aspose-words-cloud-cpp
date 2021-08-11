auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetHeaderFootersRequest > request(
    new requests::GetHeaderFootersRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"")
    )
);
wordsApi->getHeaderFooters(request);