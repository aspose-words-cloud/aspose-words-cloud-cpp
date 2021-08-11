std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

std::shared_ptr< requests::InsertWatermarkImageRequest > insertRequest(
    new requests::InsertWatermarkImageRequest(
        std::make_shared< std::wstring >(remoteFileName), nullptr, std::make_shared< std::wstring >(remoteFileName), std::make_shared< std::wstring >(L"Sample.png")
    )
);
wordsApi->insertWatermarkImage(insertRequest);