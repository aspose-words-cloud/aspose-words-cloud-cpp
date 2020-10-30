/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="commentTests.cpp">
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
   ASSERT_EQ(true, actual.body->getComment() != nullptr);
   ASSERT_EQ(0, actual.body->getComment()->getText().rfind(STCONVERT("Comment 1"), 0));
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
   ASSERT_EQ(true, actual.body->getComments() != nullptr);
   ASSERT_EQ(true, actual.body->getComments()->getCommentList() != nullptr);
   ASSERT_EQ(1, actual.body->getComments()->getCommentList().size());
   ASSERT_EQ(0, actual.body->getComments()->getCommentList()[0]->getText().rfind(STCONVERT("Comment 1"), 0));
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
   ASSERT_EQ(true, actual.body->getComment() != nullptr);
   ASSERT_EQ(0, actual.body->getComment()->getText().rfind(STCONVERT("A new Comment"), 0));
   ASSERT_EQ(true, actual.body->getComment()->getRangeStart() != nullptr);
   ASSERT_EQ(true, actual.body->getComment()->getRangeStart()->getNode() != nullptr);
   ASSERT_EQ(0, actual.body->getComment()->getRangeStart()->getNode()->getNodeId().rfind(STCONVERT("0.3.0.4"), 0));
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
   ASSERT_EQ(true, actual.body->getComment() != nullptr);
   ASSERT_EQ(0, actual.body->getComment()->getText().rfind(STCONVERT("A new Comment"), 0));
   ASSERT_EQ(true, actual.body->getComment()->getRangeStart() != nullptr);
   ASSERT_EQ(true, actual.body->getComment()->getRangeStart()->getNode() != nullptr);
   ASSERT_EQ(0, actual.body->getComment()->getRangeStart()->getNode()->getNodeId().rfind(STCONVERT("0.3.0.1"), 0));
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
