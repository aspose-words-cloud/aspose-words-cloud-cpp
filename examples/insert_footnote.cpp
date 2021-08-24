auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteInsert >();
requestFootnoteDto->setFootnoteType(std::make_shared< aspose::words::cloud::models::FootnoteBase::FootnoteType >(aspose::words::cloud::models::FootnoteBase::FootnoteType::ENDNOTE));
requestFootnoteDto->setText(std::make_shared< std::wstring >(L"test endnote"));
std::shared_ptr< requests::InsertFootnoteRequest > insertRequest(
    new requests::InsertFootnoteRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestFootnoteDto
    )
);
wordsApi->insertFootnote(insertRequest);