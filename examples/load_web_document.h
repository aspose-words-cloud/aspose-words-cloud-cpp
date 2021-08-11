auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDataSaveOptions = std::make_shared< aspose::words::cloud::models::SaveOptionsData >();
requestDataSaveOptions->setFileName(std::make_shared< std::wstring >(L"google.doc"));
requestDataSaveOptions->setSaveFormat(std::make_shared< std::wstring >(L"doc"));
requestDataSaveOptions->setDmlEffectsRenderingMode(std::make_shared< std::wstring >(L"1"));
requestDataSaveOptions->setDmlRenderingMode(std::make_shared< std::wstring >(L"1"));
requestDataSaveOptions->setUpdateSdtContent(std::make_shared< bool >(false));
requestDataSaveOptions->setZipOutput(std::make_shared< bool >(false));

auto requestData = std::make_shared< aspose::words::cloud::models::LoadWebDocumentData >();
requestData->setLoadingDocumentUrl(std::make_shared< std::wstring >(L"http://google.com"));
requestData->setSaveOptions(requestDataSaveOptions);

std::shared_ptr< requests::LoadWebDocumentRequest > loadRequest(
    new requests::LoadWebDocumentRequest(
        requestData
    )
);
wordsApi->loadWebDocument(loadRequest);