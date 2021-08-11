std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestStyleInsert = std::make_shared< aspose::words::cloud::models::StyleInsert >();
requestStyleInsert->setStyleName(std::make_shared< std::wstring >(L"My Style"));
requestStyleInsert->setStyleType(std::make_shared< aspose::words::cloud::models::StyleInsert::StyleType >(aspose::words::cloud::models::StyleInsert::StyleType::PARAGRAPH));

std::shared_ptr< requests::InsertStyleOnlineRequest > insertRequest(
    new requests::InsertStyleOnlineRequest(
        requestDocumentStream, requestStyleInsert
    )
);
wordsApi->insertStyleOnline(insertRequest);