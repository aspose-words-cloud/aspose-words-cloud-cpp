auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::MoveFileRequest > moveRequest(
    new requests::MoveFileRequest(
        std::make_shared< std::wstring >(L"/TestMoveFileDest_Sample.docx"), std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->moveFile(moveRequest);