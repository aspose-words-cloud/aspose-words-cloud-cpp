auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestTable = std::make_shared< aspose::words::cloud::models::TableInsert >();
requestTable->setColumnsCount(std::make_shared< int32_t >(5));
requestTable->setRowsCount(std::make_shared< int32_t >(4));
std::shared_ptr< requests::InsertTableOnlineRequest > insertRequest(
    new requests::InsertTableOnlineRequest(
        requestDocument, requestTable
    )
);
wordsApi->insertTableOnline(insertRequest);