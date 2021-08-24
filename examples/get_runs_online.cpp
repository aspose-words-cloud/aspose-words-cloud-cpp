auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::GetRunsOnlineRequest > request(
    new requests::GetRunsOnlineRequest(
        requestDocument, std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
    )
);
wordsApi->getRunsOnline(request);