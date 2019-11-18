/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="bookmarkTest.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/
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
	std::shared_ptr<GetBookmarksRequest> req=
			std::make_shared<GetBookmarksRequest>(remoteName, get_data_folder(), boost::none,
					boost::none, boost::none);

	auto requestTask = get_api()->getBookmarks(req);

	AsposeResponse<BookmarksResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual.httpResponse->status_code());
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
	std::shared_ptr<GetBookmarkByNameRequest> req=
			std::make_shared<GetBookmarkByNameRequest>(remoteName, bookmark, get_data_folder(),
					boost::none, boost::none, boost::none);

	auto requestTask = get_api()->getBookmarkByName(req);

	AsposeResponse<BookmarkResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<UpdateBookmarkRequest> request=
			std::make_shared<UpdateBookmarkRequest>(remoteName, body, bookmarkName, this->get_data_folder(),
		boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);
	auto requestTask = get_api()->updateBookmark(request);
	AsposeResponse<BookmarkResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual.httpResponse->status_code());
}
