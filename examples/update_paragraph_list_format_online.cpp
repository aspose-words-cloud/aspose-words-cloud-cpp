auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.doc"), std::istream::binary));
auto requestListFormatDto = std::make_shared< aspose::words::cloud::models::ListFormatUpdate >();
requestListFormatDto->setListId(std::make_shared< int32_t >(2));
std::shared_ptr< requests::UpdateParagraphListFormatOnlineRequest > updateRequest(
    new requests::UpdateParagraphListFormatOnlineRequest(
        requestDocument, requestListFormatDto, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateParagraphListFormatOnline(updateRequest);