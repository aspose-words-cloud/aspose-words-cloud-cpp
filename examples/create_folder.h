auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::CreateFolderRequest > createRequest(
    new requests::CreateFolderRequest(
        std::make_shared< std::wstring >(L"/TestCreateFolder")
    )
);
wordsApi->createFolder(createRequest);