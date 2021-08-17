/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="comment_test.h">
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to get comments from document.
/// </summary>
class CommentTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/Comments";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for getting comment by specified comment's index.
/// </summary>
TEST_F(CommentTests, TestGetComment) {
    std::wstring remoteFileName = L"TestGetComment.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetCommentRequest> request(new requests::GetCommentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getComment(request);
    ASSERT_TRUE(actual->getComment() != nullptr);
    ASSERT_TRUE(actual->getComment()->getText()->compare(L"Comment 1" + std::wstring(L"\r\n\r\n")) == 0);
}

/// <summary>
/// Test for getting comment by specified comment's index online.
/// </summary>
TEST_F(CommentTests, TestGetCommentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetCommentOnlineRequest> request(new requests::GetCommentOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getCommentOnline(request);
}

/// <summary>
/// Test for getting all comments from document.
/// </summary>
TEST_F(CommentTests, TestGetComments) {
    std::wstring remoteFileName = L"TestGetComments.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetCommentsRequest> request(new requests::GetCommentsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getComments(request);
    ASSERT_TRUE(actual->getComments() != nullptr);
    ASSERT_TRUE(actual->getComments()->getCommentList() != nullptr);
    ASSERT_EQ(1, actual->getComments()->getCommentList()->size());
    ASSERT_TRUE(actual->getComments()->getCommentList()->at(0)->getText()->compare(L"Comment 1" + std::wstring(L"\r\n\r\n")) == 0);
}

/// <summary>
/// Test for getting all comments from document online.
/// </summary>
TEST_F(CommentTests, TestGetCommentsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetCommentsOnlineRequest> request(new requests::GetCommentsOnlineRequest(
        requestDocument,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getCommentsOnline(request);
}

/// <summary>
/// Test for adding comment.
/// </summary>
TEST_F(CommentTests, TestInsertComment) {
    std::wstring remoteFileName = L"TestInsertComment.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(nullptr);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(nullptr);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentInsert >();
    requestComment->setRangeStart(nullptr);
    requestComment->setRangeEnd(nullptr);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr<requests::InsertCommentRequest> request(new requests::InsertCommentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertComment(request);
    ASSERT_TRUE(actual->getComment() != nullptr);
    ASSERT_TRUE(actual->getComment()->getText()->compare(L"A new Comment" + std::wstring(L"\r\n")) == 0);
    ASSERT_TRUE(actual->getComment()->getRangeStart() != nullptr);
    ASSERT_TRUE(actual->getComment()->getRangeStart()->getNode() != nullptr);
    ASSERT_TRUE(actual->getComment()->getRangeStart()->getNode()->getNodeId()->compare(L"0.3.0.4") == 0);
}

/// <summary>
/// Test for adding comment online.
/// </summary>
TEST_F(CommentTests, TestInsertCommentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(nullptr);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0.3"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(nullptr);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentInsert >();
    requestComment->setRangeStart(nullptr);
    requestComment->setRangeEnd(nullptr);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr<requests::InsertCommentOnlineRequest> request(new requests::InsertCommentOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertCommentOnline(request);
}

/// <summary>
/// Test for updating comment.
/// </summary>
TEST_F(CommentTests, TestUpdateComment) {
    std::wstring remoteFileName = L"TestUpdateComment.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(nullptr);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(nullptr);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentUpdate >();
    requestComment->setRangeStart(nullptr);
    requestComment->setRangeEnd(nullptr);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr<requests::UpdateCommentRequest> request(new requests::UpdateCommentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateComment(request);
    ASSERT_TRUE(actual->getComment() != nullptr);
    ASSERT_TRUE(actual->getComment()->getText()->compare(L"A new Comment" + std::wstring(L"\r\n")) == 0);
    ASSERT_TRUE(actual->getComment()->getRangeStart() != nullptr);
    ASSERT_TRUE(actual->getComment()->getRangeStart()->getNode() != nullptr);
    ASSERT_TRUE(actual->getComment()->getRangeStart()->getNode()->getNodeId()->compare(L"0.3.0.1") == 0);
}

/// <summary>
/// Test for updating comment online.
/// </summary>
TEST_F(CommentTests, TestUpdateCommentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestCommentRangeStartNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeStartNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeStart = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeStart->setNode(nullptr);
    requestCommentRangeStart->setOffset(std::make_shared< int32_t >(0));
    auto requestCommentRangeEndNode = std::make_shared< aspose::words::cloud::models::NodeLink >();
    requestCommentRangeEndNode->setNodeId(std::make_shared< std::wstring >(L"0.3.0"));
    auto requestCommentRangeEnd = std::make_shared< aspose::words::cloud::models::DocumentPosition >();
    requestCommentRangeEnd->setNode(nullptr);
    requestCommentRangeEnd->setOffset(std::make_shared< int32_t >(0));
    auto requestComment = std::make_shared< aspose::words::cloud::models::CommentUpdate >();
    requestComment->setRangeStart(nullptr);
    requestComment->setRangeEnd(nullptr);
    requestComment->setInitial(std::make_shared< std::wstring >(L"IA"));
    requestComment->setAuthor(std::make_shared< std::wstring >(L"Imran Anwar"));
    requestComment->setText(std::make_shared< std::wstring >(L"A new Comment"));
    std::shared_ptr<requests::UpdateCommentOnlineRequest> request(new requests::UpdateCommentOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateCommentOnline(request);
}

/// <summary>
/// A test for DeleteComment.
/// </summary>
TEST_F(CommentTests, TestDeleteComment) {
    std::wstring remoteFileName = L"TestDeleteComment.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteCommentRequest> request(new requests::DeleteCommentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

getApi()->deleteComment(request);
}

/// <summary>
/// A test for DeleteComment online.
/// </summary>
TEST_F(CommentTests, TestDeleteCommentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteCommentOnlineRequest> request(new requests::DeleteCommentOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteCommentOnline(request);
}

/// <summary>
/// A test for DeleteComments.
/// </summary>
TEST_F(CommentTests, TestDeleteComments) {
    std::wstring remoteFileName = L"TestDeleteComment.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteCommentsRequest> request(new requests::DeleteCommentsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

getApi()->deleteComments(request);
}

/// <summary>
/// A test for DeleteComments online.
/// </summary>
TEST_F(CommentTests, TestDeleteCommentsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteCommentsOnlineRequest> request(new requests::DeleteCommentsOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteCommentsOnline(request);
}
