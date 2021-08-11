auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetDocumentWithFormatRequest > request(
    new requests::GetDocumentWithFormatRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"text"), std::make_shared< std::wstring >(L"/TestGetDocumentWithFormatAndOutPath.text")
    )
);
wordsApi->getDocumentWithFormat(request);