auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestOptions = std::make_shared< aspose::words::cloud::models::OptimizationOptions >();
requestOptions->setMsWordVersion(std::make_shared< aspose::words::cloud::models::OptimizationOptions::MsWordVersion >(aspose::words::cloud::models::OptimizationOptions::MsWordVersion::WORD2002));

std::shared_ptr< requests::OptimizeDocumentRequest > optimizeRequest(
    new requests::OptimizeDocumentRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestOptions
    )
);
wordsApi->optimizeDocument(optimizeRequest);