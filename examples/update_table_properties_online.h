std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestProperties = std::make_shared< aspose::words::cloud::models::TableProperties >();
requestProperties->setAlignment(std::make_shared< aspose::words::cloud::models::TableProperties::Alignment >(aspose::words::cloud::models::TableProperties::Alignment::RIGHT));
requestProperties->setAllowAutoFit(std::make_shared< bool >(false));
requestProperties->setBidi(std::make_shared< bool >(true));
requestProperties->setBottomPadding(std::make_shared< double >(1));
requestProperties->setCellSpacing(std::make_shared< double >(2));
requestProperties->setStyleOptions(std::make_shared< aspose::words::cloud::models::TableProperties::StyleOptions >(aspose::words::cloud::models::TableProperties::StyleOptions::COLUMN_BANDS));

std::shared_ptr< requests::UpdateTablePropertiesOnlineRequest > updateRequest(
    new requests::UpdateTablePropertiesOnlineRequest(
        requestDocumentStream, requestProperties, std::make_shared< int32_t >(1), std::make_shared< std::wstring >(L"")
    )
);
wordsApi->updateTablePropertiesOnline(updateRequest);