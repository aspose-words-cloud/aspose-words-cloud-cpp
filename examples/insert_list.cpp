auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestListInsert = std::make_shared< aspose::words::cloud::models::ListInsert >();
requestListInsert->setTemplate(std::make_shared< aspose::words::cloud::models::ListInsert::Template >(aspose::words::cloud::models::ListInsert::Template::OUTLINE_LEGAL));
std::shared_ptr< requests::InsertListRequest > insertRequest(
    new requests::InsertListRequest(
        std::make_shared< std::wstring >(L"TestGetLists.doc"), requestListInsert
    )
);
wordsApi->insertList(insertRequest);