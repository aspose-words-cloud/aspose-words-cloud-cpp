auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));

auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
requestCommentRangeStart->setNode(requestCommentRangeStartNode);
requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));

auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));

auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));

auto requestComment = std::make_shared< aspose::words::cloud::models::CommentUpdate >();
requestComment->setRangeStart(requestCommentRangeStart);
requestComment->setRangeEnd(requestCommentRangeEnd);
requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));

std::shared_ptr< requests::UpdateCommentRequest > updateRequest(
    new requests::UpdateCommentRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< int32_t >(0), requestComment
    )
);
wordsApi->updateComment(updateRequest);