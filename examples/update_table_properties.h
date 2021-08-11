auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestProperties = std::make_shared< aspose::words::cloud::models::TableProperties >();
requestProperties->setAlignment(std::make_shared< aspose::words::cloud::models::TableProperties::Alignment >(aspose::words::cloud::models::TableProperties::Alignment::RIGHT));
requestProperties->setAllowAutoFit(std::make_shared< bool >(false));
requestProperties->setBidi(std::make_shared< bool >(true));
requestProperties->setBottomPadding(std::make_shared< double >(1.0));
requestProperties->setCellSpacing(std::make_shared< double >(2.0));
requestProperties->setStyleOptions(std::make_shared< aspose::words::cloud::models::TableProperties::StyleOptions >(aspose::words::cloud::models::TableProperties::StyleOptions::COLUMN_BANDS));

std::shared_ptr< requests::UpdateTablePropertiesRequest > updateRequest(
    new requests::UpdateTablePropertiesRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(1), requestProperties
    )
);
wordsApi->updateTableProperties(updateRequest);