std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
std::shared_ptr< requests::InsertWatermarkImageOnlineRequest > insertRequest(
    new requests::InsertWatermarkImageOnlineRequest(
        requestDocumentStream, requestImageFileStream
    )
);
wordsApi->insertWatermarkImageOnline(insertRequest);