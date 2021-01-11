/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="bookmarkTests.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "../TestBase.h"

/// <summary>
/// Example of how to get all bookmarks from document.
/// </summary>
class BookmarkTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Bookmarks");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");
    utility::string_t bookmarkName = STCONVERT("aspose");

};

/// <summary>
/// Test for getting bookmarks from document.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarks) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentBookmarks.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetBookmarksRequest > request(new GetBookmarksRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getBookmarks(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting bookmarks from document online.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarksOnline) {
    std::shared_ptr< GetBookmarksOnlineRequest > request(new GetBookmarksOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getBookmarksOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting bookmark by specified name.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarkByName) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentBookmarkByName.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetBookmarkByNameRequest > request(new GetBookmarkByNameRequest(
        remoteFileName,
        bookmarkName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getBookmarkByName(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting bookmark by specified name online.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarkByNameOnline) {
    std::shared_ptr< GetBookmarkByNameOnlineRequest > request(new GetBookmarkByNameOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        bookmarkName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getBookmarkByNameOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating existed bookmark.
/// </summary>
TEST_F(BookmarkTests, TestUpdateBookmark) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateDocumentBookmark.docx");
    utility::string_t bookmarkText = STCONVERT("This will be the text for Aspose");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestBookmarkData = std::make_shared< BookmarkData >();
    requestBookmarkData->setName(bookmarkName);
    requestBookmarkData->setText(bookmarkText);

    std::shared_ptr< UpdateBookmarkRequest > request(new UpdateBookmarkRequest(
        remoteFileName,
        bookmarkName,
        requestBookmarkData,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateBookmark(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating existed bookmark online.
/// </summary>
TEST_F(BookmarkTests, TestUpdateBookmarkOnline) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateDocumentBookmark.docx");

    auto requestBookmarkData = std::make_shared< BookmarkData >();
    requestBookmarkData->setName(bookmarkName);
    requestBookmarkData->setText(STCONVERT("This will be the text for Aspose"));

    std::shared_ptr< UpdateBookmarkOnlineRequest > request(new UpdateBookmarkOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        bookmarkName,
        requestBookmarkData,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

auto actual = get_api()->updateBookmarkOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}
