#include "TestBase.h"

/// <summary>
/// Example of how to work with runs
/// </summary>
class RunTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Runs")),
		runFolder = STCONVERT("DocumentElements\\Runs");
};

/// <summary>
/// Test for updating run
/// </summary>
TEST_F(RunTest, TestPostRun) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestPostRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);

	std::shared_ptr<io::swagger::client::api::Run > run(new io::swagger::client::api::Run);
	run->setText(STCONVERT("run with text"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostRunRequest> request(new PostRunRequest(remoteName, run, STCONVERT("paragraphs/1"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<RunResponse> actual = get_api()->postRun(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for adding run
/// </summary>
TEST_F(RunTest, TestPutRun) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestPutRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);

	std::shared_ptr<io::swagger::client::api::Run > run(new io::swagger::client::api::Run);
	run->setText(STCONVERT("run with text"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutRunRequest> request(new PutRunRequest(remoteName, STCONVERT("paragraphs/1"), run, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<RunResponse> actual = get_api()->putRun(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting run
/// </summary>
TEST_F(RunTest, TestDeleteRun) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestPostRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteRunRequest> request(new DeleteRunRequest(remoteName, STCONVERT("paragraphs/1"), index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteRun(request).get();

	ASSERT_EQ(200, actual->getCode());
}