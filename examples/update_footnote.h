auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteUpdate >();
requestFootnoteDto->setText(std::make_shared< std::wstring >(L"new text is here"));

std::shared_ptr< requests::UpdateFootnoteRequest > updateRequest(
    new requests::UpdateFootnoteRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestFootnoteDto
    )
);
wordsApi->updateFootnote(updateRequest);