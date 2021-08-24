auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::DeleteParagraphTabStopRequest > deleteRequest(
    new requests::DeleteParagraphTabStopRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< double >(72.0), std::make_shared< int32_t >(0)
    )
);
wordsApi->deleteParagraphTabStop(deleteRequest);