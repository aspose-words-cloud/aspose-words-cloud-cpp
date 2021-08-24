auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Common/test_multi_pages.docx"), std::istream::binary));
auto requestSaveOptionsData = std::make_shared< aspose::words::cloud::models::SaveOptionsData >();
requestSaveOptionsData->setSaveFormat(std::make_shared< std::wstring >(L"pdf"));
requestSaveOptionsData->setFileName(std::make_shared< std::wstring >(L"/TestSaveAs.pdf"));
std::shared_ptr< requests::SaveAsOnlineRequest > saveRequest(
    new requests::SaveAsOnlineRequest(
        requestDocument, requestSaveOptionsData
    )
);
wordsApi->saveAsOnline(saveRequest);