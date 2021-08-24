auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestTabStopInsertDto = std::make_shared< aspose::words::cloud::models::TabStopInsert >();
requestTabStopInsertDto->setAlignment(std::make_shared< aspose::words::cloud::models::TabStopBase::Alignment >(aspose::words::cloud::models::TabStopBase::Alignment::LEFT));
requestTabStopInsertDto->setLeader(std::make_shared< aspose::words::cloud::models::TabStopBase::Leader >(aspose::words::cloud::models::TabStopBase::Leader::NONE));
requestTabStopInsertDto->setPosition(std::make_shared< double >(72));
std::shared_ptr< requests::InsertOrUpdateParagraphTabStopOnlineRequest > insertRequest(
    new requests::InsertOrUpdateParagraphTabStopOnlineRequest(
        requestDocument, requestTabStopInsertDto, std::make_shared< int32_t >(0)
    )
);
wordsApi->insertOrUpdateParagraphTabStopOnline(insertRequest);