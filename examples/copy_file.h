auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::CopyFileRequest > copyRequest(
    new requests::CopyFileRequest(
        std::make_shared< std::wstring >(L"/TestCopyFileDest.docx"), std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->copyFile(copyRequest);