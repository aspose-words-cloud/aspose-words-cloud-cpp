auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestStyleApply = std::make_shared< aspose::words::cloud::models::StyleApply >();
requestStyleApply->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));

std::shared_ptr< requests::ApplyStyleToDocumentElementRequest > applyStyleRequest(
    new requests::ApplyStyleToDocumentElementRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1/paragraphFormat"), requestStyleApply
    )
);
wordsApi->applyStyleToDocumentElement(applyStyleRequest);