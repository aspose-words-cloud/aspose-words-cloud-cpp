std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestDocumentListDocumentEntries0 = std::make_shared< aspose::words::cloud::models::DocumentEntry >();
requestDocumentListDocumentEntries0->setHref(std::make_shared< std::wstring >(L"Sample.docx"));
requestDocumentListDocumentEntries0->setImportFormatMode(std::make_shared< std::wstring >(L"KeepSourceFormatting"));

auto requestDocumentListDocumentEntries = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::DocumentEntry>> >();
requestDocumentListDocumentEntries->push_back(requestDocumentListDocumentEntries0);

auto requestDocumentList = std::make_shared< aspose::words::cloud::models::DocumentEntryList >();
requestDocumentList->setDocumentEntries(requestDocumentListDocumentEntries);

std::shared_ptr< requests::AppendDocumentOnlineRequest > appendRequest(
    new requests::AppendDocumentOnlineRequest(
        requestDocumentStream, requestDocumentList
    )
);
wordsApi->appendDocumentOnline(appendRequest);