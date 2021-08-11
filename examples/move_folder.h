auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::MoveFolderRequest > moveRequest(
    new requests::MoveFolderRequest(
        std::make_shared< std::wstring >(L"/TestMoveFolderDest_Sample"), std::make_shared< std::wstring >(L"/TestMoveFolderSrc")
    )
);
wordsApi->moveFolder(moveRequest);