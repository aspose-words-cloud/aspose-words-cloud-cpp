auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::CreateDocumentRequest > createRequest(
    new requests::CreateDocumentRequest(
        std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->createDocument(createRequest);