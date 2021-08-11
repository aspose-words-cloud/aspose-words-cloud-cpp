auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring folderToCopy = L"/TestCopyFolder";

std::shared_ptr< requests::CopyFolderRequest > copyRequest(
    new requests::CopyFolderRequest(
        std::make_shared< std::wstring >(folderToCopy + L"Dest"), std::make_shared< std::wstring >(folderToCopy + L"Src")
    )
);
wordsApi->copyFolder(copyRequest);