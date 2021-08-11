auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestTabStopInsertDto = std::make_shared< aspose::words::cloud::models::TabStopInsert >();
requestTabStopInsertDto->setAlignment(std::make_shared< aspose::words::cloud::models::TabStopBase::Alignment >(aspose::words::cloud::models::TabStopBase::Alignment::LEFT));
requestTabStopInsertDto->setLeader(std::make_shared< aspose::words::cloud::models::TabStopBase::Leader >(aspose::words::cloud::models::TabStopBase::Leader::NONE));
requestTabStopInsertDto->setPosition(std::make_shared< double >(100.0));

std::shared_ptr< requests::InsertOrUpdateParagraphTabStopRequest > insertRequest(
    new requests::InsertOrUpdateParagraphTabStopRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestTabStopInsertDto
    )
);
wordsApi->insertOrUpdateParagraphTabStop(insertRequest);