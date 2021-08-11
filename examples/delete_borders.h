auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::DeleteBordersRequest > deleteRequest(
    new requests::DeleteBordersRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
    )
);
wordsApi->deleteBorders(deleteRequest);