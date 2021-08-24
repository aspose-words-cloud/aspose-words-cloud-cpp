auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetTableRowFormatRequest > request(
    new requests::GetTableRowFormatRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2"), std::make_shared< int32_t >(0)
    )
);
wordsApi->getTableRowFormat(request);