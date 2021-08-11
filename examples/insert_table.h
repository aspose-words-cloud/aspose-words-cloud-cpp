auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestTable = std::make_shared< aspose::words::cloud::models::TableInsert >();
requestTable->setColumnsCount(std::make_shared< int32_t >(5));
requestTable->setRowsCount(std::make_shared< int32_t >(4));

std::shared_ptr< requests::InsertTableRequest > insertRequest(
    new requests::InsertTableRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestTable
    )
);
wordsApi->insertTable(insertRequest);