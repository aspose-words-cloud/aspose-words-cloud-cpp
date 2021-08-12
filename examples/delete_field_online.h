std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
std::shared_ptr< requests::DeleteFieldOnlineRequest > deleteRequest(
    new requests::DeleteFieldOnlineRequest(
        requestDocumentStream, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
    )
);
wordsApi->deleteFieldOnline(deleteRequest);