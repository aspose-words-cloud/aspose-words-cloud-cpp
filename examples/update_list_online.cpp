auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.doc"), std::istream::binary));
auto requestListUpdate = std::make_shared< aspose::words::cloud::models::ListUpdate >();
requestListUpdate->setIsRestartAtEachSection(std::make_shared< bool >(true));
std::shared_ptr< requests::UpdateListOnlineRequest > updateRequest(
    new requests::UpdateListOnlineRequest(
        requestDocument, std::make_shared< int32_t >(1), requestListUpdate
    )
);
wordsApi->updateListOnline(updateRequest);