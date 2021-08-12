std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestField = std::make_shared< aspose::words::cloud::models::FieldUpdate >();
requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));

std::shared_ptr< requests::UpdateFieldOnlineRequest > updateRequest(
    new requests::UpdateFieldOnlineRequest(
        requestDocumentStream, requestField, std::make_shared< int32_t >(0), std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
    )
);
wordsApi->updateFieldOnline(updateRequest);