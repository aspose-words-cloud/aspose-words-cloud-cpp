#include "TestBase.h"

/// <summary>
/// Example of how to perform mail merge
/// </summary>
class ExecuteMailMergeTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\MailMerge")),
		mailMergeFolder = STCONVERT("DocumentActions/MailMerge");
};

/// <summary>
/// Test for executing mail merge online
/// </summary>
TEST_F(ExecuteMailMergeTest, TestPutExecuteMailMergeOnline) {
	std::shared_ptr<PutExecuteMailMergeOnlineRequest> request(new PutExecuteMailMergeOnlineRequest(
		generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleExecuteTemplate.docx")), STCONVERT("template")),
		generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleExecuteTemplateData.txt")), STCONVERT("data")),
		boost::none, boost::none, boost::none));

	HttpContent result = get_api()->putExecuteMailMergeOnline(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for executing mail merge
/// </summary>
TEST_F(ExecuteMailMergeTest, TestPostDocumentExecuteMailMerge) {
	utility::string_t
		localName = STCONVERT("SampleMailMergeTemplate.docx"),
		remoteName = STCONVERT("TestPostDocumentExecuteMailMerge.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(mailMergeFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		fileContent = get_file_text(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleMailMergeTemplateData.txt")));

	UploadFileToStorage(fullName, filePath);
	std::shared_ptr<PostDocumentExecuteMailMergeRequest> request(new PostDocumentExecuteMailMergeRequest(remoteName,
		fileContent, dataFolder, boost::none, boost::none, boost::none, false, boost::none, boost::none, boost::none, destFileName));

	std::shared_ptr<DocumentResponse> actual = get_api()->postDocumentExecuteMailMerge(request).get();

	ASSERT_EQ(200, actual->getCode());
}