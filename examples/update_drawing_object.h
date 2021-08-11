std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
requestDrawingObject->setLeft(std::make_shared< double >(0));

std::shared_ptr< requests::UpdateDrawingObjectRequest > updateRequest(
    new requests::UpdateDrawingObjectRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestDrawingObject, requestImageFileStream, std::make_shared< int32_t >(0)
    )
);
wordsApi->updateDrawingObject(updateRequest);