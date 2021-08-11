std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"DocumentElements/Lists/ListsGet.doc"), std::istream::binary));
auto requestListInsert = std::make_shared< aspose::words::cloud::models::ListInsert >();
requestListInsert->setTemplate(std::make_shared< aspose::words::cloud::models::ListInsert::Template >(aspose::words::cloud::models::ListInsert::Template::OUTLINE_LEGAL));

std::shared_ptr< requests::InsertListOnlineRequest > insertRequest(
    new requests::InsertListOnlineRequest(
        requestDocumentStream, requestListInsert
    )
);
wordsApi->insertListOnline(insertRequest);