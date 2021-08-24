auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::DeleteParagraphTabStopOnlineRequest > deleteRequest(
    new requests::DeleteParagraphTabStopOnlineRequest(
        requestDocument, std::make_shared< double >(72.0), std::make_shared< int32_t >(0)
    )
);
wordsApi->deleteParagraphTabStopOnline(deleteRequest);