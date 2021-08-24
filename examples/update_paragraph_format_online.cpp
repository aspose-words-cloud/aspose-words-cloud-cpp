auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestParagraphFormatDto = std::make_shared< aspose::words::cloud::models::ParagraphFormatUpdate >();
requestParagraphFormatDto->setAlignment(std::make_shared< aspose::words::cloud::models::ParagraphFormatBase::Alignment >(aspose::words::cloud::models::ParagraphFormatBase::Alignment::RIGHT));
std::shared_ptr< requests::UpdateParagraphFormatOnlineRequest > updateRequest(
    new requests::UpdateParagraphFormatOnlineRequest(
        requestDocument, requestParagraphFormatDto, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateParagraphFormatOnline(updateRequest);