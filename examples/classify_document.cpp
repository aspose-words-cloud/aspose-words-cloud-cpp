auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::ClassifyDocumentRequest > classifyRequest(
    new requests::ClassifyDocumentRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"3")
    )
);
wordsApi->classifyDocument(classifyRequest);