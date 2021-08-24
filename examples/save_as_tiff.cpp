auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestSaveOptions = std::make_shared< aspose::words::cloud::models::TiffSaveOptionsData >();
requestSaveOptions->setSaveFormat(std::make_shared< std::wstring >(L"tiff"));
requestSaveOptions->setFileName(std::make_shared< std::wstring >(L"/abc.tiff"));
std::shared_ptr< requests::SaveAsTiffRequest > saveRequest(
    new requests::SaveAsTiffRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestSaveOptions
    )
);
wordsApi->saveAsTiff(saveRequest);