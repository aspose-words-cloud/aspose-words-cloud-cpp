auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestPageSetup = std::make_shared< aspose::words::cloud::models::PageSetup >();
requestPageSetup->setRtlGutter(std::make_shared< bool >(true));
requestPageSetup->setLeftMargin(std::make_shared< double >(10.0));
requestPageSetup->setOrientation(std::make_shared< aspose::words::cloud::models::PageSetup::Orientation >(aspose::words::cloud::models::PageSetup::Orientation::LANDSCAPE));
requestPageSetup->setPaperSize(std::make_shared< aspose::words::cloud::models::PageSetup::PaperSize >(aspose::words::cloud::models::PageSetup::PaperSize::A5));
std::shared_ptr< requests::UpdateSectionPageSetupRequest > updateRequest(
    new requests::UpdateSectionPageSetupRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestPageSetup
    )
);
wordsApi->updateSectionPageSetup(updateRequest);