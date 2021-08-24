auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartInsert >();
requestCustomXmlPart->setId(std::make_shared< std::wstring >(L"hello"));
requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
std::shared_ptr< requests::InsertCustomXmlPartRequest > insertRequest(
    new requests::InsertCustomXmlPartRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestCustomXmlPart
    )
);
wordsApi->insertCustomXmlPart(insertRequest);