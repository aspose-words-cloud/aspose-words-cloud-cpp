std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
std::shared_ptr< requests::GetHeaderFootersOnlineRequest > request(
    new requests::GetHeaderFootersOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"")
    )
);
wordsApi->getHeaderFootersOnline(request);