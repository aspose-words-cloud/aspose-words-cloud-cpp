auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestParagraph = std::make_shared< aspose::words::cloud::models::ParagraphInsert >();
requestParagraph->setText(std::make_shared< std::wstring >(L"This is a new paragraph for your document"));
std::shared_ptr< requests::InsertParagraphRequest > insertRequest(
    new requests::InsertParagraphRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestParagraph
    )
);
wordsApi->insertParagraph(insertRequest);