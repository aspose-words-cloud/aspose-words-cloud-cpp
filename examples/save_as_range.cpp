auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentParameters = std::make_shared< aspose::words::cloud::models::RangeDocument >();
requestDocumentParameters->setDocumentName(std::make_shared< std::wstring >(L"/NewDoc.docx"));
std::shared_ptr< requests::SaveAsRangeRequest > saveRequest(
    new requests::SaveAsRangeRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"id0.0.0"), requestDocumentParameters, std::make_shared< std::wstring >(L"id0.0.1")
    )
);
wordsApi->saveAsRange(saveRequest);