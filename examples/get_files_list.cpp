auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetFilesListRequest > request(
    new requests::GetFilesListRequest(
        std::make_shared< std::wstring >(L"")
    )
);
wordsApi->getFilesList(request);