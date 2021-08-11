std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Common/aspose-cloud.png"), std::istream::binary));
auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectInsert >();
requestDrawingObject->setHeight(std::make_shared< double >(0));
requestDrawingObject->setLeft(std::make_shared< double >(0));
requestDrawingObject->setTop(std::make_shared< double >(0));
requestDrawingObject->setWidth(std::make_shared< double >(0));
requestDrawingObject->setRelativeHorizontalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition::MARGIN));
requestDrawingObject->setRelativeVerticalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition::MARGIN));
requestDrawingObject->setWrapType(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::WrapType >(aspose::words::cloud::models::DrawingObjectInsert::WrapType::INLINE));

std::shared_ptr< requests::InsertDrawingObjectRequest > insertRequest(
    new requests::InsertDrawingObjectRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), requestDrawingObject, requestImageFileStream
    )
);
wordsApi->insertDrawingObject(insertRequest);