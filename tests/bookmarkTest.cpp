#include "TestBase.h"
class BookmarkTest : public InfrastructureTest {
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp\\SdkTests\\TestData"), STCONVERT("DocumentElements\\Bookmarks"));
	}
};

/// <summary>
/// Test for getting bookmarks from document
/// </summary>
TEST_F(BookmarkTest, TestGetDocumentBookmarks) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentBookmarks.docx"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);
	std::shared_ptr<GetDocumentBookmarksRequest> req=
			std::make_shared<GetDocumentBookmarksRequest>(remoteName, get_data_folder(), boost::none,
					boost::none, boost::none);

	auto requestTask = get_api()->getDocumentBookmarks(req);

	std::shared_ptr<BookmarksResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting bookmark by specified name
/// </summary>
TEST_F(BookmarkTest, TestGetDocumentBookmarkByName) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentBookmarkByName.docx"),
		fullName = path_combine(get_data_folder(), remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		bookmark = STCONVERT("aspose");

	UploadFileToStorage(fullName, filePath);
	std::shared_ptr<GetDocumentBookmarkByNameRequest> req=
			std::make_shared<GetDocumentBookmarkByNameRequest>(remoteName, bookmark, get_data_folder(),
					boost::none, boost::none, boost::none);

	auto requestTask = get_api()->getDocumentBookmarkByName(req);

	std::shared_ptr<BookmarkResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating existed bookmark
/// </summary>
TEST_F(BookmarkTest, TestPostUpdateDocumentBookmark) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentBookmarkByName.docx"),
		fullName = path_combine(get_data_folder(), remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		bookmarkName = STCONVERT("aspose"),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<BookmarkData> body= std::make_shared<BookmarkData>();
	body->setName(bookmarkName);
	body->setText(STCONVERT("This will be the text for Aspose"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostUpdateDocumentBookmarkRequest> request=
			std::make_shared<PostUpdateDocumentBookmarkRequest>(remoteName, body, bookmarkName, this->get_data_folder(),
		boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);
	auto requestTask = get_api()->postUpdateDocumentBookmark(request);
	std::shared_ptr<BookmarkResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual->getCode());
}
