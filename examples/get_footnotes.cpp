auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetFootnotesRequest > request(
    new requests::GetFootnotesRequest(
        std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->getFootnotes(request);