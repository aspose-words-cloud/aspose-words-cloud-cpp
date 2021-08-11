auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestCompareData = std::make_shared< aspose::words::cloud::models::CompareData >();
requestCompareData->setAuthor(std::make_shared< std::wstring >(L"author"));
requestCompareData->setComparingWithDocument(std::make_shared< std::wstring >(L"TestCompareDocument2.doc"));
requestCompareData->setDateTime(std::make_shared< std::wstring >(L"2015-10-26T00:00:00.0000000Z"));

std::shared_ptr< requests::CompareDocumentRequest > compareRequest(
    new requests::CompareDocumentRequest(
        std::make_shared< std::wstring >(L"TestCompareDocument1.doc"), requestCompareData, std::make_shared< std::wstring >(L"/TestCompareDocumentOut.doc")
    )
);
wordsApi->compareDocument(compareRequest);