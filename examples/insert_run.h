auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestRun = std::make_shared< aspose::words::cloud::models::RunInsert >();
requestRun->setText(std::make_shared< std::wstring >(L"run with text"));

std::shared_ptr< requests::InsertRunRequest > insertRequest(
    new requests::InsertRunRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"paragraphs/1"), requestRun
    )
);
wordsApi->insertRun(insertRequest);