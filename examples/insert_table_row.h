auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestRow = std::make_shared< aspose::words::cloud::models::TableRowInsert >();
requestRow->setColumnsCount(std::make_shared< int32_t >(5));

std::shared_ptr< requests::InsertTableRowRequest > insertRequest(
    new requests::InsertTableRowRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2"), requestRow
    )
);
wordsApi->insertTableRow(insertRequest);