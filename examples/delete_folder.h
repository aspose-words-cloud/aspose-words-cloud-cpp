auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::DeleteFolderRequest > deleteRequest(
    new requests::DeleteFolderRequest(
        std::make_shared< std::wstring >(L"")
    )
);
wordsApi->deleteFolder(deleteRequest);