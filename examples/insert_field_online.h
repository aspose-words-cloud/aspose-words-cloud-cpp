std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"/GetField.docx"), std::istream::binary));
auto requestField = std::make_shared< aspose::words::cloud::models::FieldInsert >();
requestField->setFieldCode(std::make_shared< std::wstring >(L"{ NUMPAGES }"));

std::shared_ptr< requests::InsertFieldOnlineRequest > insertRequest(
    new requests::InsertFieldOnlineRequest(
        requestDocumentStream, requestField, std::make_shared< std::wstring >(L"sections/0/paragraphs/0")
    )
);
wordsApi->insertFieldOnline(insertRequest);