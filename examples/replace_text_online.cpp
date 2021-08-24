auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestReplaceText = std::make_shared< aspose::words::cloud::models::ReplaceTextParameters >();
requestReplaceText->setOldValue(std::make_shared< std::wstring >(L"aspose"));
requestReplaceText->setNewValue(std::make_shared< std::wstring >(L"aspose new"));
std::shared_ptr< requests::ReplaceTextOnlineRequest > replaceRequest(
    new requests::ReplaceTextOnlineRequest(
        requestDocument, requestReplaceText
    )
);
wordsApi->replaceTextOnline(replaceRequest);