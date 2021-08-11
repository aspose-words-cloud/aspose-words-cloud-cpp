auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

std::shared_ptr< requests::ExecuteMailMergeRequest > mailMergeRequest(
    new requests::ExecuteMailMergeRequest(
        std::make_shared< std::wstring >(remoteFileName), std::make_shared< std::wstring >(L"TestExecuteTemplateData.txt"), std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->executeMailMerge(mailMergeRequest);