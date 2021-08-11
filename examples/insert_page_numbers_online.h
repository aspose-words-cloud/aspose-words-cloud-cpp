std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/Sample.docx"), std::istream::binary));
auto requestPageNumber = std::make_shared< aspose::words::cloud::models::PageNumber >();
requestPageNumber->setAlignment(std::make_shared< std::wstring >(L"center"));
requestPageNumber->setFormat(std::make_shared< std::wstring >(L"{PAGE} of {NUMPAGES}"));

std::shared_ptr< requests::InsertPageNumbersOnlineRequest > insertRequest(
    new requests::InsertPageNumbersOnlineRequest(
        requestDocumentStream, requestPageNumber
    )
);
wordsApi->insertPageNumbersOnline(insertRequest);