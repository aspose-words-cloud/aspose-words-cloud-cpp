std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestStyleUpdate = std::make_shared< aspose::words::cloud::models::StyleUpdate >();
requestStyleUpdate->setName(std::make_shared< std::wstring >(L"My Style"));

std::shared_ptr< requests::UpdateStyleOnlineRequest > updateRequest(
    new requests::UpdateStyleOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"Heading 1"), requestStyleUpdate
    )
);
wordsApi->updateStyleOnline(updateRequest);