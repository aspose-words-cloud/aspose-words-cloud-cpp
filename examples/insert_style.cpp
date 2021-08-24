auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestStyleInsert = std::make_shared< aspose::words::cloud::models::StyleInsert >();
requestStyleInsert->setStyleName(std::make_shared< std::wstring >(L"My Style"));
requestStyleInsert->setStyleType(std::make_shared< aspose::words::cloud::models::StyleInsert::StyleType >(aspose::words::cloud::models::StyleInsert::StyleType::PARAGRAPH));
std::shared_ptr< requests::InsertStyleRequest > insertRequest(
    new requests::InsertStyleRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestStyleInsert
    )
);
wordsApi->insertStyle(insertRequest);