auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestField = std::make_shared< aspose::words::cloud::models::FieldUpdate >();
requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));

std::shared_ptr< requests::UpdateFieldRequest > updateRequest(
    new requests::UpdateFieldRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestField, std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
    )
);
wordsApi->updateField(updateRequest);