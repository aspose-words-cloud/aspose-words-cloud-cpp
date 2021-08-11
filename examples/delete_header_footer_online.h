std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"DocumentElements/HeaderFooters/HeadersFooters.doc"), std::istream::binary));
std::shared_ptr< requests::DeleteHeaderFooterOnlineRequest > deleteRequest(
    new requests::DeleteHeaderFooterOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L""), std::make_shared< int32_t >(0)
    )
);
wordsApi->deleteHeaderFooterOnline(deleteRequest);