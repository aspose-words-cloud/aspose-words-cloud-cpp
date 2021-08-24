auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListUpdate >();
requestListUpdate->setIsRestartAtEachSection(std::make_shared< bool >(true));
std::shared_ptr< requests::UpdateListRequest > updateRequest(
    new requests::UpdateListRequest(
        std::make_shared< std::wstring >(L"TestGetLists.doc"), std::make_shared< int32_t >(1), requestListUpdate
    )
);
wordsApi->updateList(updateRequest);