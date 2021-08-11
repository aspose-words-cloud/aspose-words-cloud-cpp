std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));

auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
requestCommentRangeStart->setNode(requestCommentRangeStartNode);
requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));

auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));

auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));

auto requestComment = std::make_shared< aspose::words::cloud::models::CommentInsert >();
requestComment->setRangeStart(requestCommentRangeStart);
requestComment->setRangeEnd(requestCommentRangeEnd);
requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));

std::shared_ptr< requests::InsertCommentOnlineRequest > insertRequest(
    new requests::InsertCommentOnlineRequest(
        requestDocumentStream, requestComment
    )
);
wordsApi->insertCommentOnline(insertRequest);