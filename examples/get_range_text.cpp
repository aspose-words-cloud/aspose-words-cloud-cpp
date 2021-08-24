auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetRangeTextRequest > request(
    new requests::GetRangeTextRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"id0.0.0"), std::make_shared< std::wstring >(L"id0.0.1")
    )
);
wordsApi->getRangeText(request);