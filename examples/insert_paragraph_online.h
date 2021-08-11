std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestParagraph = std::make_shared< aspose::words::cloud::models::ParagraphInsert >();
requestParagraph->setText(std::make_shared< std::wstring >(L"This is a new paragraph for your document"));

std::shared_ptr< requests::InsertParagraphOnlineRequest > insertRequest(
    new requests::InsertParagraphOnlineRequest(
        requestDocumentStream, requestParagraph, std::make_shared< std::wstring >(L"sections/0")
    )
);
wordsApi->insertParagraphOnline(insertRequest);