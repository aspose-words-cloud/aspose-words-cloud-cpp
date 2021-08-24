auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestStyleUpdate = std::make_shared< aspose::words::cloud::models::StyleUpdate >();
requestStyleUpdate->setName(std::make_shared< std::wstring >(L"My Style"));
std::shared_ptr< requests::UpdateStyleRequest > updateRequest(
    new requests::UpdateStyleRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"Heading 1"), requestStyleUpdate
    )
);
wordsApi->updateStyle(updateRequest);