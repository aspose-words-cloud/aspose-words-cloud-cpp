auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";

std::shared_ptr< requests::DeleteWatermarkRequest > deleteRequest(
    new requests::DeleteWatermarkRequest(
        std::make_shared< std::wstring >(remoteFileName), std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->deleteWatermark(deleteRequest);