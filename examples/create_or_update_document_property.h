auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

auto requestProperty = std::make_shared< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate >();
requestProperty->setValue(std::make_shared< std::wstring >(L"Imran Anwar"));

std::shared_ptr< requests::CreateOrUpdateDocumentPropertyRequest > createRequest(
    new requests::CreateOrUpdateDocumentPropertyRequest(
        std::make_shared< std::wstring >(remoteFileName), std::make_shared< std::wstring >(L"AsposeAuthor"), requestProperty, std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->createOrUpdateDocumentProperty(createRequest);