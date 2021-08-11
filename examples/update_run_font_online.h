std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestFontDto = std::make_shared< aspose::words::cloud::models::Font >();
requestFontDto->setBold(std::make_shared< bool >(true));

std::shared_ptr< requests::UpdateRunFontOnlineRequest > updateRequest(
    new requests::UpdateRunFontOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"paragraphs/0"), requestFontDto, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateRunFontOnline(updateRequest);