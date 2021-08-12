auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestFontDto = std::make_shared< aspose::words::cloud::models::Font >();
requestFontDto->setBold(std::make_shared< bool >(true));

std::shared_ptr< requests::UpdateRunFontRequest > updateRequest(
    new requests::UpdateRunFontRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/0"), std::make_shared< int32_t >(0), requestFontDto
    )
);
wordsApi->updateRunFont(updateRequest);