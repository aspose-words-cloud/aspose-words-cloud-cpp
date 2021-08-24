auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::ExecuteMailMergeRequest > mailMergeRequest(
    new requests::ExecuteMailMergeRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"TestExecuteTemplateData.txt")
    )
);
wordsApi->executeMailMerge(mailMergeRequest);