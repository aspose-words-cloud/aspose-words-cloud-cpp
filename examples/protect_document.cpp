auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"123"));
requestProtectionRequest->setProtectionType(std::make_shared< std::wstring >(L"ReadOnly"));
std::shared_ptr< requests::ProtectDocumentRequest > protectRequest(
    new requests::ProtectDocumentRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestProtectionRequest
    )
);
wordsApi->protectDocument(protectRequest);