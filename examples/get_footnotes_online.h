std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"/Footnote.doc"), std::istream::binary));
std::shared_ptr< requests::GetFootnotesOnlineRequest > request(
    new requests::GetFootnotesOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"")
    )
);
wordsApi->getFootnotesOnline(request);