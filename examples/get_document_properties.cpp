auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetDocumentPropertiesRequest > request(
    new requests::GetDocumentPropertiesRequest(
        std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->getDocumentProperties(request);