auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::DeleteFileRequest > deleteRequest(
    new requests::DeleteFileRequest(
        std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->deleteFile(deleteRequest);