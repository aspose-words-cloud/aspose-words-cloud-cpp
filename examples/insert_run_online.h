std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"DocumentElements/Runs/Run.doc"), std::istream::binary));
auto requestRun = std::make_shared< aspose::words::cloud::models::RunInsert >();
requestRun->setText(std::make_shared< std::wstring >(L"run with text"));

std::shared_ptr< requests::InsertRunOnlineRequest > insertRequest(
    new requests::InsertRunOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"paragraphs/1"), requestRun
    )
);
wordsApi->insertRunOnline(insertRequest);