auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
std::wstring bookmarkName = L"aspose";

auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(L"Sample.docx"), std::istream::binary));
auto requestBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
requestBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
requestBookmarkData->setText(std::make_shared< std::wstring >(L"This will be the text for Aspose"));
std::shared_ptr< requests::UpdateBookmarkOnlineRequest > updateRequest(
    new requests::UpdateBookmarkOnlineRequest(
        requestDocument, std::make_shared< std::wstring >(bookmarkName), requestBookmarkData, std::make_shared< std::wstring >(L"Sample.docx")
    )
);
wordsApi->updateBookmarkOnline(updateRequest);