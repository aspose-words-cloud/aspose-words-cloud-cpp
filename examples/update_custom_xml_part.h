auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartUpdate >();
requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));

std::shared_ptr< requests::UpdateCustomXmlPartRequest > updateRequest(
    new requests::UpdateCustomXmlPartRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestCustomXmlPart
    )
);
wordsApi->updateCustomXmlPart(updateRequest);