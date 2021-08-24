auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::ClassifyRequest > classifyRequest(
    new requests::ClassifyRequest(
        std::make_shared< std::wstring >(L"Try text classification"), std::make_shared< std::wstring >(L"3")
    )
);
wordsApi->classify(classifyRequest);