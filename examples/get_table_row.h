auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetTableRowRequest > request(
    new requests::GetTableRowRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"tables/1"), std::make_shared< int32_t >(0)
    )
);
wordsApi->getTableRow(request);