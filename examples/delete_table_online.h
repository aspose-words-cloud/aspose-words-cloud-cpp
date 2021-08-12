std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::DeleteTableOnlineRequest > deleteRequest(
    new requests::DeleteTableOnlineRequest(
        requestDocumentStream, std::make_shared< int32_t >(1)
    )
);
wordsApi->deleteTableOnline(deleteRequest);