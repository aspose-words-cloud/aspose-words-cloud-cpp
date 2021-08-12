std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
auto requestRangeText = std::make_shared< aspose::words::cloud::models::ReplaceRange >();
requestRangeText->setText(std::make_shared< std::wstring >(L"Replaced header"));

std::shared_ptr< requests::ReplaceWithTextOnlineRequest > replaceRequest(
    new requests::ReplaceWithTextOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"id0.0.0"), requestRangeText, std::make_shared< std::wstring >(L"id0.0.1")
    )
);
wordsApi->replaceWithTextOnline(replaceRequest);