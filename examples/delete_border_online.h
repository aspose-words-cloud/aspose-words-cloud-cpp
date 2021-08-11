std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::DeleteBorderOnlineRequest > deleteRequest(
    new requests::DeleteBorderOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"left"), std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
    )
);
wordsApi->deleteBorderOnline(deleteRequest);