auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Common/aspose-cloud.png"), std::istream::binary));
std::shared_ptr< requests::InsertWatermarkImageOnlineRequest > insertRequest(
    new requests::InsertWatermarkImageOnlineRequest(
        requestDocument, requestImageFile
    )
);
wordsApi->insertWatermarkImageOnline(insertRequest);