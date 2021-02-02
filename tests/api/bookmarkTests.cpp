/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="bookmarkTests.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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
   ASSERT_TRUE(IsNotNull(actual.body->getBookmarks()));
   ASSERT_EQ(3, actual.body->getBookmarks()->getBookmarkList().size());
   ASSERT_EQ(STCONVERT("aspose"), actual.body->getBookmarks()->getBookmarkList()[1]->getName());
}

/// <summary>
/// Test for getting bookmark by specified name.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarkByName) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentBookmarkByName.docx");
    utility::string_t bookmarkName = STCONVERT("aspose");

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
   ASSERT_TRUE(IsNotNull(actual.body->getBookmark()));
   ASSERT_EQ(bookmarkName, actual.body->getBookmark()->getName());
}

/// <summary>
/// Test for updating existed bookmark.
/// </summary>
TEST_F(BookmarkTests, TestUpdateBookmark) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateDocumentBookmark.docx");
    utility::string_t bookmarkName = STCONVERT("aspose");
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
        requestBookmarkData,
        bookmarkName,
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
   ASSERT_TRUE(IsNotNull(actual.body->getBookmark()));
   ASSERT_EQ(bookmarkName, actual.body->getBookmark()->getName());
   ASSERT_EQ(bookmarkText, actual.body->getBookmark()->getText());
}
