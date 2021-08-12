std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.doc"), std::istream::binary));
auto requestFootnoteDto = std::make_shared< aspose::words::cloud::models::FootnoteInsert >();
requestFootnoteDto->setFootnoteType(std::make_shared< aspose::words::cloud::models::FootnoteBase::FootnoteType >(aspose::words::cloud::models::FootnoteBase::FootnoteType::ENDNOTE));
requestFootnoteDto->setText(std::make_shared< std::wstring >(L"test endnote"));

std::shared_ptr< requests::InsertFootnoteOnlineRequest > insertRequest(
    new requests::InsertFootnoteOnlineRequest(
        requestDocumentStream, requestFootnoteDto
    )
);
wordsApi->insertFootnoteOnline(insertRequest);