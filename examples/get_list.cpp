auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetListRequest > request(
    new requests::GetListRequest(
        std::make_shared< std::wstring >(L"TestGetLists.doc"), std::make_shared< int32_t >(1)
    )
);
wordsApi->getList(request);