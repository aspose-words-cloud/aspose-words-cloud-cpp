auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"aspose"));
std::shared_ptr< requests::UnprotectDocumentRequest > unprotectRequest(
    new requests::UnprotectDocumentRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestProtectionRequest
    )
);
wordsApi->unprotectDocument(unprotectRequest);