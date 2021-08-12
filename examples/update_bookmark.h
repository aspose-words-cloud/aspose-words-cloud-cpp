auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring bookmarkName = L"aspose";

auto requestBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
requestBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
requestBookmarkData->setText(std::make_shared< std::wstring >(L"This will be the text for Aspose"));

std::shared_ptr< requests::UpdateBookmarkRequest > updateRequest(
    new requests::UpdateBookmarkRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(bookmarkName), requestBookmarkData
    )
);
wordsApi->updateBookmark(updateRequest);