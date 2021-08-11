std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"DocumentElements/Runs/Run.doc"), std::istream::binary));
auto requestRun = std::make_shared< aspose::words::cloud::models::RunUpdate >();
requestRun->setText(std::make_shared< std::wstring >(L"run with text"));

std::shared_ptr< requests::UpdateRunOnlineRequest > updateRequest(
    new requests::UpdateRunOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"paragraphs/1"), requestRun, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateRunOnline(updateRequest);