auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestStyleCopy = std::make_shared< aspose::words::cloud::models::StyleCopy >();
requestStyleCopy->setStyleName(std::make_shared< std::wstring >(L"Heading 1"));

std::shared_ptr< requests::CopyStyleRequest > copyRequest(
    new requests::CopyStyleRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestStyleCopy
    )
);
wordsApi->copyStyle(copyRequest);