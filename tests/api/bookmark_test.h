﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="bookmark_test.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to get all bookmarks from document.
/// </summary>
class BookmarkTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Bookmarks";
    std::wstring localFile = L"Common/test_multi_pages.docx";
    std::wstring bookmarkName = L"aspose";

};

/// <summary>
/// Test for getting bookmarks from document.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarks) {
    std::wstring remoteFileName = L"TestGetDocumentBookmarks.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetBookmarksRequest> request(new requests::GetBookmarksRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBookmarks(request);
}

/// <summary>
/// Test for getting bookmarks from document online.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarksOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetBookmarksOnlineRequest> request(new requests::GetBookmarksOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBookmarksOnline(request);
}

/// <summary>
/// Test for getting bookmark by specified name.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarkByName) {
    std::wstring remoteFileName = L"TestGetDocumentBookmarkByName.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetBookmarkByNameRequest> request(new requests::GetBookmarkByNameRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(bookmarkName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBookmarkByName(request);
}

/// <summary>
/// Test for getting bookmark by specified name online.
/// </summary>
TEST_F(BookmarkTests, TestGetBookmarkByNameOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetBookmarkByNameOnlineRequest> request(new requests::GetBookmarkByNameOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(bookmarkName),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getBookmarkByNameOnline(request);
}

/// <summary>
/// Test for updating existed bookmark.
/// </summary>
TEST_F(BookmarkTests, TestUpdateBookmark) {
    std::wstring remoteFileName = L"TestUpdateDocumentBookmark.docx";
    std::wstring bookmarkText = L"This will be the text for Aspose";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
    requestBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
    requestBookmarkData->setText(std::make_shared< std::wstring >(bookmarkText));
    std::shared_ptr<requests::UpdateBookmarkRequest> request(new requests::UpdateBookmarkRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(bookmarkName),
        requestBookmarkData,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateBookmark(request);
}

/// <summary>
/// Test for updating existed bookmark online.
/// </summary>
TEST_F(BookmarkTests, TestUpdateBookmarkOnline) {
    std::wstring remoteFileName = L"TestUpdateDocumentBookmark.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestBookmarkData = std::make_shared< aspose::words::cloud::models::BookmarkData >();
    requestBookmarkData->setName(std::make_shared< std::wstring >(bookmarkName));
    requestBookmarkData->setText(std::make_shared< std::wstring >(L"This will be the text for Aspose"));
    std::shared_ptr<requests::UpdateBookmarkOnlineRequest> request(new requests::UpdateBookmarkOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(bookmarkName),
        requestBookmarkData,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateBookmarkOnline(request);
}

/// <summary>
/// Test for deleting bookmark by specified name.
/// </summary>
TEST_F(BookmarkTests, TestDeleteBookmark) {
    std::wstring remoteFileName = L"TestDeleteBookmark.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteBookmarkRequest> request(new requests::DeleteBookmarkRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(bookmarkName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteBookmark(request);
}

/// <summary>
/// Test for deleting bookmark by specified name online.
/// </summary>
TEST_F(BookmarkTests, TestDeleteBookmarkOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteBookmarkOnlineRequest> request(new requests::DeleteBookmarkOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(bookmarkName),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteBookmarkOnline(request);
}

/// <summary>
/// Test for deleting all bookmarks from document.
/// </summary>
TEST_F(BookmarkTests, TestDeleteBookmarks) {
    std::wstring remoteFileName = L"TestDeleteBookmarks.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteBookmarksRequest> request(new requests::DeleteBookmarksRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteBookmarks(request);
}

/// <summary>
/// Test for deleting all bookmarks from document online.
/// </summary>
TEST_F(BookmarkTests, TestDeleteBookmarksOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteBookmarksOnlineRequest> request(new requests::DeleteBookmarksOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteBookmarksOnline(request);
}

/// <summary>
/// Test for inserting new bookmark.
/// </summary>
TEST_F(BookmarkTests, TestInsertBookmark) {
    std::wstring remoteFileName = L"TestInsertBookmark.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestBookmarkStartRange = std::make_shared< aspose::words::cloud::models::PositionInsideNode >();
    requestBookmarkStartRange->setNodeId(std::make_shared< std::wstring >(L"0.0.0.0"));
    requestBookmarkStartRange->setOffset(std::make_shared< int32_t >(0));
    auto requestBookmarkEndRange = std::make_shared< aspose::words::cloud::models::PositionInsideNode >();
    requestBookmarkEndRange->setNodeId(std::make_shared< std::wstring >(L"0.0.0.0"));
    requestBookmarkEndRange->setOffset(std::make_shared< int32_t >(0));
    auto requestBookmark = std::make_shared< aspose::words::cloud::models::BookmarkInsert >();
    requestBookmark->setStartRange(requestBookmarkStartRange);
    requestBookmark->setEndRange(requestBookmarkEndRange);
    requestBookmark->setName(std::make_shared< std::wstring >(L"new_bookmark"));
    requestBookmark->setText(std::make_shared< std::wstring >(L"Some text"));
    std::shared_ptr<requests::InsertBookmarkRequest> request(new requests::InsertBookmarkRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestBookmark,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertBookmark(request);
}

/// <summary>
/// Test for inserting new bookmark online.
/// </summary>
TEST_F(BookmarkTests, TestInsertBookmarkOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestBookmarkStartRange = std::make_shared< aspose::words::cloud::models::PositionInsideNode >();
    requestBookmarkStartRange->setNodeId(std::make_shared< std::wstring >(L"0.0.0.0"));
    requestBookmarkStartRange->setOffset(std::make_shared< int32_t >(0));
    auto requestBookmarkEndRange = std::make_shared< aspose::words::cloud::models::PositionInsideNode >();
    requestBookmarkEndRange->setNodeId(std::make_shared< std::wstring >(L"0.0.0.0"));
    requestBookmarkEndRange->setOffset(std::make_shared< int32_t >(0));
    auto requestBookmark = std::make_shared< aspose::words::cloud::models::BookmarkInsert >();
    requestBookmark->setStartRange(requestBookmarkStartRange);
    requestBookmark->setEndRange(requestBookmarkEndRange);
    requestBookmark->setName(std::make_shared< std::wstring >(L"new_bookmark"));
    requestBookmark->setText(std::make_shared< std::wstring >(L"Some text"));
    std::shared_ptr<requests::InsertBookmarkOnlineRequest> request(new requests::InsertBookmarkOnlineRequest(
        requestDocument,
        requestBookmark,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertBookmarkOnline(request);
}
