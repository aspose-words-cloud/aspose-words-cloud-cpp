auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListLevelUpdate >();
requestListUpdate->setAlignment(std::make_shared< aspose::words::cloud::models::ListLevelUpdate::Alignment >(aspose::words::cloud::models::ListLevelUpdate::Alignment::RIGHT));

std::shared_ptr< requests::UpdateListLevelRequest > updateRequest(
    new requests::UpdateListLevelRequest(
        std::make_shared< std::wstring >(L"TestGetLists.doc"), std::make_shared< int32_t >(1), std::make_shared< int32_t >(1), requestListUpdate
    )
);
wordsApi->updateListLevel(updateRequest);