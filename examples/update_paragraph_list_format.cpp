auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestListFormatDto = std::make_shared< aspose::words::cloud::models::ListFormatUpdate >();
requestListFormatDto->setListId(std::make_shared< int32_t >(2));
std::shared_ptr< requests::UpdateParagraphListFormatRequest > updateRequest(
    new requests::UpdateParagraphListFormatRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestListFormatDto
    )
);
wordsApi->updateParagraphListFormat(updateRequest);