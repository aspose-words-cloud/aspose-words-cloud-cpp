#include "TestBase.h"

/// <summary>
/// Example of how to accept all revisions in document
/// </summary>
class RevisionTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\Revisions"));
};

/// <summary>
/// Test for accepting revisions in document
/// </summary>
TEST_F(RevisionTest, TestAcceptAllRevisions) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestAcceptAllRevisions.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<AcceptAllRevisionsRequest> request(new AcceptAllRevisionsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, destFileName));

	std::shared_ptr<RevisionsModificationResponse> actual = get_api()->acceptAllRevisions(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for rejecting revisions in document
/// </summary>
TEST_F(RevisionTest, TestRejectAllRevisions) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestRejectAllRevisions.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RejectAllRevisionsRequest> request(new RejectAllRevisionsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, destFileName));

	std::shared_ptr<RevisionsModificationResponse> actual = get_api()->rejectAllRevisions(request).get();

	ASSERT_EQ(200, actual->getCode());
}
