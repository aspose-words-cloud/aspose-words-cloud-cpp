auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestCell = std::make_shared< aspose::words::cloud::models::TableCellInsert >();

std::shared_ptr< requests::InsertTableCellRequest > insertRequest(
    new requests::InsertTableCellRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), requestCell
    )
);
wordsApi->insertTableCell(insertRequest);