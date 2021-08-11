std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartUpdate >();
requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));

std::shared_ptr< requests::UpdateCustomXmlPartOnlineRequest > updateRequest(
    new requests::UpdateCustomXmlPartOnlineRequest(
        requestDocumentStream, std::make_shared< int32_t >(0), requestCustomXmlPart
    )
);
wordsApi->updateCustomXmlPartOnline(updateRequest);