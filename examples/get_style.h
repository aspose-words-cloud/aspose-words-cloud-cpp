auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetStyleRequest > request(
    new requests::GetStyleRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"Heading 1")
    )
);
wordsApi->getStyle(request);