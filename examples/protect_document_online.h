std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
requestProtectionRequest->setNewPassword(std::make_shared< std::wstring >(L"123"));

std::shared_ptr< requests::ProtectDocumentOnlineRequest > protectRequest(
    new requests::ProtectDocumentOnlineRequest(
        requestDocumentStream, requestProtectionRequest
    )
);
wordsApi->protectDocumentOnline(protectRequest);