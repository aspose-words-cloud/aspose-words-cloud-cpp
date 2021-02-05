/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="commentTests.cpp">
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
/// Example of how to get comments from document.
/// </summary>
class CommentTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/Comments");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for getting comment by specified comment's index.
/// </summary>
TEST_F(CommentTests, TestGetComment) {
    utility::string_t remoteFileName = STCONVERT("TestGetComment.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetCommentRequest > request(new GetCommentRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getComment(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getComment()));
   ASSERT_EQ(STCONVERT("Comment 1") + STCONVERT("\r\n\r\n"), actual.body->getComment()->getText());
}

/// <summary>
/// Test for getting comment by specified comment's index online.
/// </summary>
TEST_F(CommentTests, TestGetCommentOnline) {
    std::shared_ptr< GetCommentOnlineRequest > request(new GetCommentOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getCommentOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting all comments from document.
/// </summary>
TEST_F(CommentTests, TestGetComments) {
    utility::string_t remoteFileName = STCONVERT("TestGetComments.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetCommentsRequest > request(new GetCommentsRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getComments(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getComments()));
   ASSERT_TRUE(IsNotNull(actual.body->getComments()->getCommentList()));
   ASSERT_EQ(1, actual.body->getComments()->getCommentList().size());
   ASSERT_EQ(STCONVERT("Comment 1") + STCONVERT("\r\n\r\n"), actual.body->getComments()->getCommentList()[0]->getText());
}

/// <summary>
/// Test for getting all comments from document online.
/// </summary>
TEST_F(CommentTests, TestGetCommentsOnline) {
    std::shared_ptr< GetCommentsOnlineRequest > request(new GetCommentsOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getCommentsOnline(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding comment.
/// </summary>
TEST_F(CommentTests, TestInsertComment) {
    utility::string_t remoteFileName = STCONVERT("TestInsertComment.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestCommentRangeStartNode = std::make_shared< NodeLink >();
    requestCommentRangeStartNode->setNodeId(STCONVERT("0.3.0.3"));

    auto requestCommentRangeStart = std::make_shared< DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(0);

    auto requestCommentRangeEndNode = std::make_shared< NodeLink >();
    requestCommentRangeEndNode->setNodeId(STCONVERT("0.3.0.3"));

    auto requestCommentRangeEnd = std::make_shared< DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(0);

    auto requestComment = std::make_shared< CommentInsert >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(STCONVERT("IA"));
    requestComment->setAuthor(STCONVERT("Imran Anwar"));
    requestComment->setText(STCONVERT("A new Comment"));

    std::shared_ptr< InsertCommentRequest > request(new InsertCommentRequest(
        remoteFileName,
        requestComment,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertComment(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getComment()));
   ASSERT_EQ(STCONVERT("A new Comment") + STCONVERT("\r\n"), actual.body->getComment()->getText());
   ASSERT_TRUE(IsNotNull(actual.body->getComment()->getRangeStart()));
   ASSERT_TRUE(IsNotNull(actual.body->getComment()->getRangeStart()->getNode()));
   ASSERT_EQ(STCONVERT("0.3.0.4"), actual.body->getComment()->getRangeStart()->getNode()->getNodeId());
}

/// <summary>
/// Test for adding comment online.
/// </summary>
TEST_F(CommentTests, TestInsertCommentOnline) {
    auto requestCommentRangeStartNode = std::make_shared< NodeLink >();
    requestCommentRangeStartNode->setNodeId(STCONVERT("0.3.0.3"));

    auto requestCommentRangeStart = std::make_shared< DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(0);

    auto requestCommentRangeEndNode = std::make_shared< NodeLink >();
    requestCommentRangeEndNode->setNodeId(STCONVERT("0.3.0.3"));

    auto requestCommentRangeEnd = std::make_shared< DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(0);

    auto requestComment = std::make_shared< CommentInsert >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(STCONVERT("IA"));
    requestComment->setAuthor(STCONVERT("Imran Anwar"));
    requestComment->setText(STCONVERT("A new Comment"));

    std::shared_ptr< InsertCommentOnlineRequest > request(new InsertCommentOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        requestComment,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->insertCommentOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating comment.
/// </summary>
TEST_F(CommentTests, TestUpdateComment) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateComment.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestCommentRangeStartNode = std::make_shared< NodeLink >();
    requestCommentRangeStartNode->setNodeId(STCONVERT("0.3.0"));

    auto requestCommentRangeStart = std::make_shared< DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(0);

    auto requestCommentRangeEndNode = std::make_shared< NodeLink >();
    requestCommentRangeEndNode->setNodeId(STCONVERT("0.3.0"));

    auto requestCommentRangeEnd = std::make_shared< DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(0);

    auto requestComment = std::make_shared< CommentUpdate >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(STCONVERT("IA"));
    requestComment->setAuthor(STCONVERT("Imran Anwar"));
    requestComment->setText(STCONVERT("A new Comment"));

    std::shared_ptr< UpdateCommentRequest > request(new UpdateCommentRequest(
        remoteFileName,
        0,
        requestComment,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateComment(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getComment()));
   ASSERT_EQ(STCONVERT("A new Comment") + STCONVERT("\r\n"), actual.body->getComment()->getText());
   ASSERT_TRUE(IsNotNull(actual.body->getComment()->getRangeStart()));
   ASSERT_TRUE(IsNotNull(actual.body->getComment()->getRangeStart()->getNode()));
   ASSERT_EQ(STCONVERT("0.3.0.1"), actual.body->getComment()->getRangeStart()->getNode()->getNodeId());
}

/// <summary>
/// Test for updating comment online.
/// </summary>
TEST_F(CommentTests, TestUpdateCommentOnline) {
    auto requestCommentRangeStartNode = std::make_shared< NodeLink >();
    requestCommentRangeStartNode->setNodeId(STCONVERT("0.3.0"));

    auto requestCommentRangeStart = std::make_shared< DocumentPosition >();
    requestCommentRangeStart->setNode(requestCommentRangeStartNode);
    requestCommentRangeStart->setOffset(0);

    auto requestCommentRangeEndNode = std::make_shared< NodeLink >();
    requestCommentRangeEndNode->setNodeId(STCONVERT("0.3.0"));

    auto requestCommentRangeEnd = std::make_shared< DocumentPosition >();
    requestCommentRangeEnd->setNode(requestCommentRangeEndNode);
    requestCommentRangeEnd->setOffset(0);

    auto requestComment = std::make_shared< CommentUpdate >();
    requestComment->setRangeStart(requestCommentRangeStart);
    requestComment->setRangeEnd(requestCommentRangeEnd);
    requestComment->setInitial(STCONVERT("IA"));
    requestComment->setAuthor(STCONVERT("Imran Anwar"));
    requestComment->setText(STCONVERT("A new Comment"));

    std::shared_ptr< UpdateCommentOnlineRequest > request(new UpdateCommentOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        requestComment,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

auto actual = get_api()->updateCommentOnline(request).get();
ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// A test for DeleteComment.
/// </summary>
TEST_F(CommentTests, TestDeleteComment) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteComment.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteCommentRequest > request(new DeleteCommentRequest(
        remoteFileName,
        0,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   get_api()->deleteComment(request).get();
}

/// <summary>
/// A test for DeleteComment online.
/// </summary>
TEST_F(CommentTests, TestDeleteCommentOnline) {
    std::shared_ptr< DeleteCommentOnlineRequest > request(new DeleteCommentOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        0,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteCommentOnline(request).get();
}

/// <summary>
/// A test for DeleteComments.
/// </summary>
TEST_F(CommentTests, TestDeleteComments) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteComment.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteCommentsRequest > request(new DeleteCommentsRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   get_api()->deleteComments(request).get();
}

/// <summary>
/// A test for DeleteComments online.
/// </summary>
TEST_F(CommentTests, TestDeleteCommentsOnline) {
    std::shared_ptr< DeleteCommentsOnlineRequest > request(new DeleteCommentsOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, localFile)),
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteCommentsOnline(request).get();
}
