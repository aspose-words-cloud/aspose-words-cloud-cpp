std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestFormat = std::make_shared< aspose::words::cloud::models::TableRowFormat >();
requestFormat->setAllowBreakAcrossPages(std::make_shared< bool >(true));
requestFormat->setHeadingFormat(std::make_shared< bool >(true));
requestFormat->setHeight(std::make_shared< double >(10));
requestFormat->setHeightRule(std::make_shared< aspose::words::cloud::models::TableRowFormat::HeightRule >(aspose::words::cloud::models::TableRowFormat::HeightRule::AUTO));

std::shared_ptr< requests::UpdateTableRowFormatOnlineRequest > updateRequest(
    new requests::UpdateTableRowFormatOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"sections/0/tables/2"), requestFormat, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateTableRowFormatOnline(updateRequest);