auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Common/test_multi_pages.docx"), std::istream::binary));
auto requestSaveOptions = std::make_shared< aspose::words::cloud::models::TiffSaveOptionsData >();
requestSaveOptions->setSaveFormat(std::make_shared< std::wstring >(L"tiff"));
requestSaveOptions->setFileName(std::make_shared< std::wstring >(L"/abc.tiff"));
std::shared_ptr< requests::SaveAsTiffOnlineRequest > saveRequest(
    new requests::SaveAsTiffOnlineRequest(
        requestDocument, requestSaveOptions
    )
);
wordsApi->saveAsTiffOnline(saveRequest);