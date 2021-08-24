auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestRow = std::make_shared< aspose::words::cloud::models::TableRowInsert >();
requestRow->setColumnsCount(std::make_shared< int32_t >(5));
std::shared_ptr< requests::InsertTableRowOnlineRequest > insertRequest(
    new requests::InsertTableRowOnlineRequest(
        requestDocument, std::make_shared< std::wstring >(L"sections/0/tables/2"), requestRow
    )
);
wordsApi->insertTableRowOnline(insertRequest);