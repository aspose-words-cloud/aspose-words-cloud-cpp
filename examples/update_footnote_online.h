std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteUpdate >();
requestFootnoteDto->setText(std::make_shared< std::wstring >(L"new text is here"));

std::shared_ptr< requests::UpdateFootnoteOnlineRequest > updateRequest(
    new requests::UpdateFootnoteOnlineRequest(
        requestDocumentStream, requestFootnoteDto, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateFootnoteOnline(updateRequest);