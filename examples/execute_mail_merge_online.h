std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestTemplateStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"TestExecuteTemplate.doc"), std::istream::binary));
auto requestDataStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"TestExecuteTemplateData.txt"), std::istream::binary));
std::shared_ptr< requests::ExecuteMailMergeOnlineRequest > mailMergeRequest(
    new requests::ExecuteMailMergeOnlineRequest(
        requestTemplateStream, requestDataStream
    )
);
wordsApi->executeMailMergeOnline(mailMergeRequest);