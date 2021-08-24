auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestFormat = std::make_shared< aspose::words::cloud::models::TableRowFormat >();
requestFormat->setAllowBreakAcrossPages(std::make_shared< bool >(true));
requestFormat->setHeadingFormat(std::make_shared< bool >(true));
requestFormat->setHeight(std::make_shared< double >(10.0));
requestFormat->setHeightRule(std::make_shared< aspose::words::cloud::models::TableRowFormat::HeightRule >(aspose::words::cloud::models::TableRowFormat::HeightRule::EXACTLY));
std::shared_ptr< requests::UpdateTableRowFormatRequest > updateRequest(
    new requests::UpdateTableRowFormatRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2"), std::make_shared< int32_t >(0), requestFormat
    )
);
wordsApi->updateTableRowFormat(updateRequest);