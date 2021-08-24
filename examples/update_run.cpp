auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestRun = std::make_shared< aspose::words::cloud::models::RunUpdate >();
requestRun->setText(std::make_shared< std::wstring >(L"run with text"));
std::shared_ptr< requests::UpdateRunRequest > updateRequest(
    new requests::UpdateRunRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1"), std::make_shared< int32_t >(0), requestRun
    )
);
wordsApi->updateRun(updateRequest);