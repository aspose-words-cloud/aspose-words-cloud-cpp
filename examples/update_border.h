auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestBorderPropertiesColor = std::make_shared< aspose::words::cloud::models::XmlColor >();
requestBorderPropertiesColor->setWeb(std::make_shared< std::wstring >(L"#AABBCC"));

auto requestBorderProperties = std::make_shared< aspose::words::cloud::models::Border >();
requestBorderProperties->setBorderType(std::make_shared< aspose::words::cloud::models::Border::BorderType >(aspose::words::cloud::models::Border::BorderType::LEFT));
requestBorderProperties->setColor(requestBorderPropertiesColor);
requestBorderProperties->setDistanceFromText(std::make_shared< double >(6.0));
requestBorderProperties->setLineStyle(std::make_shared< aspose::words::cloud::models::Border::LineStyle >(aspose::words::cloud::models::Border::LineStyle::DASH_DOT_STROKER));
requestBorderProperties->setLineWidth(std::make_shared< double >(2.0));
requestBorderProperties->setShadow(std::make_shared< bool >(true));

std::shared_ptr< requests::UpdateBorderRequest > updateRequest(
    new requests::UpdateBorderRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"left"), requestBorderProperties, std::make_shared< std::wstring >(L"tables/1/rows/0/cells/0")
    )
);
wordsApi->updateBorder(updateRequest);