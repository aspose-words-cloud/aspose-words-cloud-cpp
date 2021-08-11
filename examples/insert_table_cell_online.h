std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestCell = std::make_shared< aspose::words::cloud::models::TableCellInsert >();


std::shared_ptr< requests::InsertTableCellOnlineRequest > insertRequest(
    new requests::InsertTableCellOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), requestCell
    )
);
wordsApi->insertTableCellOnline(insertRequest);