auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

auto requestDocumentListDocumentEntries0 = std::make_shared< aspose::words::cloud::models::DocumentEntry >();
requestDocumentListDocumentEntries0->setHref(std::make_shared< std::wstring >(remoteFileName));
requestDocumentListDocumentEntries0->setImportFormatMode(std::make_shared< std::wstring >(L"KeepSourceFormatting"));
auto requestDocumentListDocumentEntries = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::DocumentEntry>> >();
requestDocumentListDocumentEntries->push_back(requestDocumentListDocumentEntries0);
auto requestDocumentList = std::make_shared< aspose::words::cloud::models::DocumentEntryList >();
requestDocumentList->setDocumentEntries(requestDocumentListDocumentEntries);
std::shared_ptr< requests::AppendDocumentRequest > appendRequest(
    new requests::AppendDocumentRequest(
        std::make_shared< std::wstring >(remoteFileName), requestDocumentList
    )
);
wordsApi->appendDocument(appendRequest);