auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::DeleteBorderRequest > deleteRequest(
    new requests::DeleteBorderRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"left"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
    )
);
wordsApi->deleteBorder(deleteRequest);