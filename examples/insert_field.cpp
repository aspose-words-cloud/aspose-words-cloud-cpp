auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestField = std::make_shared< aspose::words::cloud::models::FieldInsert >();
requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));
std::shared_ptr< requests::InsertFieldRequest > insertRequest(
    new requests::InsertFieldRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestField
    )
);
wordsApi->insertField(insertRequest);