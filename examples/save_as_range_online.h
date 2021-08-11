std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"DocumentElements/Range/RangeGet.doc"), std::istream::binary));
auto requestDocumentParameters = std::make_shared< aspose::words::cloud::models::RangeDocument >();
requestDocumentParameters->setDocumentName(std::make_shared< std::wstring >(L"/NewDoc.docx"));

std::shared_ptr< requests::SaveAsRangeOnlineRequest > saveRequest(
    new requests::SaveAsRangeOnlineRequest(
        requestDocumentStream, std::make_shared< std::wstring >(L"id0.0.0"), requestDocumentParameters, std::make_shared< std::wstring >(L"id0.0.1")
    )
);
wordsApi->saveAsRangeOnline(saveRequest);