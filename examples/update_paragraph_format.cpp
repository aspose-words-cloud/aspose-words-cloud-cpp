auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestParagraphFormatDto = std::make_shared< aspose::words::cloud::models::ParagraphFormatUpdate >();
requestParagraphFormatDto->setAlignment(std::make_shared< aspose::words::cloud::models::ParagraphFormatBase::Alignment >(aspose::words::cloud::models::ParagraphFormatBase::Alignment::RIGHT));
std::shared_ptr< requests::UpdateParagraphFormatRequest > updateRequest(
    new requests::UpdateParagraphFormatRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestParagraphFormatDto
    )
);
wordsApi->updateParagraphFormat(updateRequest);