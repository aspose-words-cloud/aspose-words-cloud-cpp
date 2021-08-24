auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::shared_ptr< requests::InsertWatermarkImageRequest > insertRequest(
    new requests::InsertWatermarkImageRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), nullptr, std::make_shared< std::wstring >(L"Sample.png")
    )
);
wordsApi->insertWatermarkImage(insertRequest);