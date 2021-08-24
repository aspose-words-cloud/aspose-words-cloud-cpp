auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestSaveOptionsData = std::make_shared< aspose::words::cloud::models::SaveOptionsData >();
requestSaveOptionsData->setSaveFormat(std::make_shared< std::wstring >(L"docx"));
requestSaveOptionsData->setFileName(std::make_shared< std::wstring >(L"/TestSaveAsFromPdfToDoc.docx"));
std::shared_ptr< requests::SaveAsRequest > saveRequest(
    new requests::SaveAsRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestSaveOptionsData
    )
);
wordsApi->saveAs(saveRequest);