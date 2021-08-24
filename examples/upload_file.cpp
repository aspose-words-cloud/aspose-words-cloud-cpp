auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestFileContent = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::UploadFileRequest > uploadRequest(
    new requests::UploadFileRequest(
        requestFileContent, std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->uploadFile(uploadRequest);