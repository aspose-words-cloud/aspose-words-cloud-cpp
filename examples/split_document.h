auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::SplitDocumentRequest > splitRequest(
    new requests::SplitDocumentRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"text"), std::make_shared< std::wstring >(L"/TestSplitDocument.text"), std::make_shared< int32_t >(1), std::make_shared< int32_t >(2)
    )
);
wordsApi->splitDocument(splitRequest);