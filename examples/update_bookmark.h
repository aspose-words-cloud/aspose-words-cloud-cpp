auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring bookmarkName = L"aspose";
std::wstring remoteFileName = L"Sample.docx";

auto requestBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
requestBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
requestBookmarkData->setText(std::make_shared< std::wstring >(L"This will be the text for Aspose"));

std::shared_ptr< requests::UpdateBookmarkRequest > updateRequest(
    new requests::UpdateBookmarkRequest(
        std::make_shared< std::wstring >(remoteFileName), std::make_shared< std::wstring >(bookmarkName), requestBookmarkData, std::make_shared< std::wstring >(remoteFileName)
    )
);
wordsApi->updateBookmark(updateRequest);