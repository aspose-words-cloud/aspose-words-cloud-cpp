auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestReplaceText = std::make_shared< aspose::words::cloud::models::ReplaceTextParameters >();
requestReplaceText->setOldValue(std::make_shared< std::wstring >(L"Testing"));
requestReplaceText->setNewValue(std::make_shared< std::wstring >(L"Aspose testing"));

std::shared_ptr< requests::ReplaceTextRequest > replaceRequest(
    new requests::ReplaceTextRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestReplaceText
    )
);
wordsApi->replaceText(replaceRequest);