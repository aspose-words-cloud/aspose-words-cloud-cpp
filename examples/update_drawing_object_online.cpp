auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
requestDrawingObject->setLeft(std::make_shared< double >(0));
auto requestImageFile = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Common/aspose-cloud.png"), std::istream::binary));
std::shared_ptr< requests::UpdateDrawingObjectOnlineRequest > updateRequest(
    new requests::UpdateDrawingObjectOnlineRequest(
        requestDocument, requestDrawingObject, requestImageFile, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateDrawingObjectOnline(updateRequest);