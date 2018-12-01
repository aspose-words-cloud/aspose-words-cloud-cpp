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

	std::shared_ptr<GetCommentRequest> request(new GetCommentRequest(remoteName, commentIndex, get_data_folder(),
		boost::none, boost::none, boost::none));
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

	std::shared_ptr<GetCommentsRequest> request(new GetCommentsRequest(remoteName, get_data_folder(),
		boost::none, boost::none, boost::none));
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

	std::shared_ptr<NodeLink> nodeLink(new NodeLink);
	nodeLink->setNodeId(STCONVERT("0.0.3"));

	std::shared_ptr<DocumentPosition> position(new DocumentPosition);
	position->setNode(nodeLink);
	position->setOffset(0);



	std::shared_ptr<Comment> body(new Comment);
	body->setRangeStart(position);
	body->setRangeEnd(position);
	body->setInitial(STCONVERT("IA"));
	body->setAuthor(STCONVERT("Imran Anwar"));
	body->setText(STCONVERT("A new Comment"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutCommentRequest> request(new PutCommentRequest(remoteName, body, get_data_folder(),
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

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

	std::shared_ptr<NodeLink> nodeLink(new NodeLink);
	nodeLink->setNodeId(STCONVERT("0.0.3"));

	std::shared_ptr<DocumentPosition> position(new DocumentPosition);
	position->setNode(nodeLink);
	position->setOffset(0);



	std::shared_ptr<Comment> body(new Comment);
	body->setRangeStart(position);
	body->setRangeEnd(position);
	body->setInitial(STCONVERT("IA"));
	body->setAuthor(STCONVERT("Imran Anwar"));
	body->setText(STCONVERT("A new Comment"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostCommentRequest> request(new PostCommentRequest(remoteName, commentIndex, body, get_data_folder(),
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

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

	std::shared_ptr<DeleteCommentRequest> request(new DeleteCommentRequest(remoteName, commentIndex, get_data_folder(),
		boost::none, boost::none, boost::none, destFileName, boost::none, boost::none));
	auto requestTask = get_api()->deleteComment(request);
	std::shared_ptr<AsposeResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual->getCode());
}
