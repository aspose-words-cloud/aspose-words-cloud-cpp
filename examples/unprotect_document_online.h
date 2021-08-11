std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"aspose"));

std::shared_ptr< requests::UnprotectDocumentOnlineRequest > unprotectRequest(
    new requests::UnprotectDocumentOnlineRequest(
        requestDocumentStream, requestProtectionRequest
    )
);
wordsApi->unprotectDocumentOnline(unprotectRequest);