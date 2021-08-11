auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetListsRequest > request(
    new requests::GetListsRequest(
        std::make_shared< std::wstring >(L"TestGetLists.doc")
    )
);
wordsApi->getLists(request);