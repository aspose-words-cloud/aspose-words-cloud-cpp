std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"compareTestDoc1.doc"), std::istream::binary));
auto requestComparingDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"compareTestDoc2.doc"), std::istream::binary));
auto requestCompareData = std::make_shared< aspose::words::cloud::models::CompareData >();
requestCompareData->setAuthor(std::make_shared< std::wstring >(L"author"));
requestCompareData->setComparingWithDocument(std::make_shared< std::wstring >(L"TestCompareDocument2.doc"));
requestCompareData->setDateTime(std::make_shared< std::wstring >(L"2015-10-26T00:00:00.0000000Z"));

std::shared_ptr< requests::CompareDocumentOnlineRequest > compareRequest(
    new requests::CompareDocumentOnlineRequest(
        requestDocumentStream, requestCompareData, requestComparingDocumentStream, std::make_shared< std::wstring >(L"/TestCompareDocumentOut.doc")
    )
);
wordsApi->compareDocumentOnline(compareRequest);