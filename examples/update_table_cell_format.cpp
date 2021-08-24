auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestFormat = std::make_shared< aspose::words::cloud::models::TableCellFormat >();
requestFormat->setBottomPadding(std::make_shared< double >(5.0));
requestFormat->setFitText(std::make_shared< bool >(true));
requestFormat->setHorizontalMerge(std::make_shared< aspose::words::cloud::models::TableCellFormat::HorizontalMerge >(aspose::words::cloud::models::TableCellFormat::HorizontalMerge::FIRST));
requestFormat->setWrapText(std::make_shared< bool >(true));
std::shared_ptr< requests::UpdateTableCellFormatRequest > updateRequest(
    new requests::UpdateTableCellFormatRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"sections/0/tables/2/rows/0"), std::make_shared< int32_t >(0), requestFormat
    )
);
wordsApi->updateTableCellFormat(updateRequest);