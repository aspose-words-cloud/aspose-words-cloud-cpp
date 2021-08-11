std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestStyleApply = std::make_shared< aspose::words::cloud::models::StyleApply >();
requestStyleApply->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));

std::shared_ptr< requests::ApplyStyleToDocumentElementOnlineRequest > applyStyleRequest(
    new requests::ApplyStyleToDocumentElementOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"), requestStyleApply
    )
);
wordsApi->applyStyleToDocumentElementOnline(applyStyleRequest);