/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="commentTest.cpp">
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
class CommentTest : public InfrastructureTest
{
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp\\SdkTests\\TestData"), STCONVERT("DocumentElements\\Comments"));
	}
};

/// <summary>
/// Test for getting comment by specified comment's index
/// </summary>
TEST_F(CommentTest, TestGetComment) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetComment.docx"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t commentIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetCommentRequest> request=
			std::make_shared<GetCommentRequest>(remoteName, commentIndex, get_data_folder(),
		boost::none, boost::none, boost::none);
	auto requestTask = get_api()->getComment(request);
	std::shared_ptr<CommentResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting all comments from document
/// </summary>
TEST_F(CommentTest, TestGetComments) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetComments.docx"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetCommentsRequest> request=
			std::make_shared<GetCommentsRequest>(remoteName, get_data_folder(),
		boost::none, boost::none, boost::none);
	auto requestTask = get_api()->getComments(request);
	std::shared_ptr<CommentsResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding comment
/// </summary>
TEST_F(CommentTest, TestPutComment) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutComment.docx"),
		fullName = path_combine(get_data_folder(), remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<NodeLink> nodeLink= std::make_shared<NodeLink>();
	nodeLink->setNodeId(STCONVERT("0.0.3"));

	std::shared_ptr<DocumentPosition> position= std::make_shared<DocumentPosition>();
	position->setNode(nodeLink);
	position->setOffset(0);



	std::shared_ptr<Comment> body= std::make_shared<Comment>();
	body->setRangeStart(position);
	body->setRangeEnd(position);
	body->setInitial(STCONVERT("IA"));
	body->setAuthor(STCONVERT("Imran Anwar"));
	body->setText(STCONVERT("A new Comment"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutCommentRequest> request=
			std::make_shared<PutCommentRequest>(remoteName, body, get_data_folder(),
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	auto requestTask = get_api()->putComment(request);
	std::shared_ptr<CommentResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding comment
/// </summary>
TEST_F(CommentTest, TestPostComment) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostComment.docx"),
		fullName = path_combine(get_data_folder(), remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t commentIndex = 0;

	std::shared_ptr<NodeLink> nodeLink= std::make_shared<NodeLink>();
	nodeLink->setNodeId(STCONVERT("0.0.3"));

	std::shared_ptr<DocumentPosition> position= std::make_shared<DocumentPosition>();
	position->setNode(nodeLink);
	position->setOffset(0);



	std::shared_ptr<Comment> body= std::make_shared<Comment>();
	body->setRangeStart(position);
	body->setRangeEnd(position);
	body->setInitial(STCONVERT("IA"));
	body->setAuthor(STCONVERT("Imran Anwar"));
	body->setText(STCONVERT("A new Comment"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostCommentRequest> request=
			std::make_shared<PostCommentRequest>(remoteName, commentIndex, body, get_data_folder(),
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	auto requestTask = get_api()->postComment(request);
	std::shared_ptr<CommentResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// A test for DeleteComment
/// </summary>
TEST_F(CommentTest, TestDeleteComment) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteComment.docx"),
		fullName = path_combine(get_data_folder(), remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	int32_t commentIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteCommentRequest> request=
			std::make_shared<DeleteCommentRequest>(remoteName, commentIndex, get_data_folder(),
		boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);
	auto requestTask = get_api()->deleteComment(request);
	std::shared_ptr<AsposeResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}
