std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestOptions = std::make_shared< aspose::words::cloud::models::OptimizationOptions >();
requestOptions->setMsWordVersion(std::make_shared< aspose::words::cloud::models::OptimizationOptions::MsWordVersion >(aspose::words::cloud::models::OptimizationOptions::MsWordVersion::WORD2002));

std::shared_ptr< requests::OptimizeDocumentOnlineRequest > optimizeRequest(
    new requests::OptimizeDocumentOnlineRequest(
        requestDocumentStream, requestOptions
    )
);
wordsApi->optimizeDocumentOnline(optimizeRequest);