auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::GetSectionsRequest > request(
    new requests::GetSectionsRequest(
        std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->getSections(request);