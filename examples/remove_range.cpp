auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::RemoveRangeRequest > removeRequest(
    new requests::RemoveRangeRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"id0.0.0"), std::make_shared< std::wstring >(L"id0.0.1")
    )
);
wordsApi->removeRange(removeRequest);