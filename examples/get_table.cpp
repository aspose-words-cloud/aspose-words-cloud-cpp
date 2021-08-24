auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetTableRequest > request(
    new requests::GetTableRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(1)
    )
);
wordsApi->getTable(request);