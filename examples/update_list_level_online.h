std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListLevelUpdate >();
requestListUpdate->setAlignment(std::make_shared< aspose::words::cloud::models::ListLevelUpdate::Alignment >(aspose::words::cloud::models::ListLevelUpdate::Alignment::RIGHT));

std::shared_ptr< requests::UpdateListLevelOnlineRequest > updateRequest(
    new requests::UpdateListLevelOnlineRequest(
        requestDocumentStream, std::make_shared< int32_t >(1), requestListUpdate, std::make_shared< int32_t >(1)
    )
);
wordsApi->updateListLevelOnline(updateRequest);