std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestPageSetup = std::make_shared< aspose::words::cloud::models::PageSetup >();
requestPageSetup->setRtlGutter(std::make_shared< bool >(true));
requestPageSetup->setLeftMargin(std::make_shared< double >(10));
requestPageSetup->setOrientation(std::make_shared< aspose::words::cloud::models::PageSetup::Orientation >(aspose::words::cloud::models::PageSetup::Orientation::LANDSCAPE));
requestPageSetup->setPaperSize(std::make_shared< aspose::words::cloud::models::PageSetup::PaperSize >(aspose::words::cloud::models::PageSetup::PaperSize::A5));

std::shared_ptr< requests::UpdateSectionPageSetupOnlineRequest > updateRequest(
    new requests::UpdateSectionPageSetupOnlineRequest(
        requestDocumentStream, std::make_shared< int32_t >(0), requestPageSetup
    )
);
wordsApi->updateSectionPageSetupOnline(updateRequest);