auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

auto requestPageNumber = std::make_shared< aspose::words::cloud::models::PageNumber >();
requestPageNumber->setAlignment(std::make_shared< std::wstring >(L"center"));
requestPageNumber->setFormat(std::make_shared< std::wstring >(L"{PAGE} of {NUMPAGES}"));

std::shared_ptr< requests::InsertPageNumbersRequest > insertRequest(
    new requests::InsertPageNumbersRequest(
        std::make_shared< std::wstring >(remoteFileName), requestPageNumber, std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->insertPageNumbers(insertRequest);