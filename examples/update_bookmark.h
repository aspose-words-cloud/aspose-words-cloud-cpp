auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring remoteFileName = L"Sample.docx";
std::wstring bookmarkName = L"aspose";

auto testBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
testBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
testBookmarkData->setText(std::make_shared< std::wstring >(L"New Bookmark Text"));

std::shared_ptr< requests::UpdateBookmarkRequest > updateBookmark(
    new requests::UpdateBookmarkRequest(
        std::make_shared< std::wstring >(remoteFileName), std::make_shared< std::wstring >(bookmarkName), testBookmarkData
    )
);
wordsApi->updateBookmark(updateBookmark);