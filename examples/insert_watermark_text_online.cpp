auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestWatermarkText = std::make_shared< aspose::words::cloud::models::WatermarkText >();
requestWatermarkText->setText(std::make_shared< std::wstring >(L"This is the text"));
requestWatermarkText->setRotationAngle(std::make_shared< double >(90));
std::shared_ptr< requests::InsertWatermarkTextOnlineRequest > insertRequest(
    new requests::InsertWatermarkTextOnlineRequest(
        requestDocument, requestWatermarkText
    )
);
wordsApi->insertWatermarkTextOnline(insertRequest);