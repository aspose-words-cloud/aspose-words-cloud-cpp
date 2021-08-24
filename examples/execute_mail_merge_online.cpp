auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestTemplate = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"TestExecuteTemplate.doc"), std::istream::binary));
auto requestData = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"TestExecuteTemplateData.txt"), std::istream::binary));
std::shared_ptr< requests::ExecuteMailMergeOnlineRequest > mailMergeRequest(
    new requests::ExecuteMailMergeOnlineRequest(
        requestTemplate, requestData
    )
);
wordsApi->executeMailMergeOnline(mailMergeRequest);