auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestProperty = std::make_shared< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate >();
requestProperty->setValue(std::make_shared< std::wstring >(L"Imran Anwar"));
std::shared_ptr< requests::CreateOrUpdateDocumentPropertyOnlineRequest > createRequest(
    new requests::CreateOrUpdateDocumentPropertyOnlineRequest(
        requestDocument, std::make_shared< std::wstring >(L"AsposeAuthor"), requestProperty
    )
);
wordsApi->createOrUpdateDocumentPropertyOnline(createRequest);