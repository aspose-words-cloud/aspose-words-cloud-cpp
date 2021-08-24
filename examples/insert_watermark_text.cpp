auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestWatermarkText = std::make_shared< aspose::words::cloud::models::WatermarkText >();
requestWatermarkText->setText(std::make_shared< std::wstring >(L"This is the text"));
requestWatermarkText->setRotationAngle(std::make_shared< double >(90.0));
std::shared_ptr< requests::InsertWatermarkTextRequest > insertRequest(
    new requests::InsertWatermarkTextRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestWatermarkText
    )
);
wordsApi->insertWatermarkText(insertRequest);