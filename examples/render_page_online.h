std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"DocumentElements/Text/SampleWordDocument.docx"), std::istream::binary));
std::shared_ptr< requests::RenderPageOnlineRequest > renderRequest(
    new requests::RenderPageOnlineRequest(
        requestDocumentStream, std::make_shared< int32_t >(1), std::make_shared< std::wstring >(L"bmp")
    )
);
wordsApi->renderPageOnline(renderRequest);