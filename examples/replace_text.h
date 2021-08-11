auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

auto requestReplaceText = std::make_shared< aspose::words::cloud::models::ReplaceTextParameters >();
requestReplaceText->setOldValue(std::make_shared< std::wstring >(L"Testing"));
requestReplaceText->setNewValue(std::make_shared< std::wstring >(L"Aspose testing"));

std::shared_ptr< requests::ReplaceTextRequest > replaceRequest(
    new requests::ReplaceTextRequest(
        std::make_shared< std::wstring >(remoteFileName), requestReplaceText, std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->replaceText(replaceRequest);