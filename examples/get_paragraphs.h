auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetParagraphsRequest > request(
    new requests::GetParagraphsRequest(
        std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->getParagraphs(request);