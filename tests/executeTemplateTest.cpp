#include "TestBase.h"

/// <summary>
/// Example of how to perfom template execution
/// </summary>
class ExecuteTemplateTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\MailMerge")),
		mailMergeFolder = STCONVERT("DocumentActions/MailMerge");
};

/// <summary>
/// Test for posting execute template
/// </summary>
TEST_F(ExecuteTemplateTest, TestPostExecuteTemplate)
{
	utility::string_t
		localName = STCONVERT("TestExecuteTemplate.doc"),
		remoteName = STCONVERT("TestGetTestPostExecuteTemplateDocument.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(mailMergeFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		data = get_file_text(path_combine(get_data_dir(mailMergeFolder), STCONVERT("TestExecuteTemplateData.txt")));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostExecuteTemplateRequest> request=
			std::make_shared<PostExecuteTemplateRequest>(remoteName, data, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, destFileName);

	std::shared_ptr<DocumentResponse> actual = get_api()->postExecuteTemplate(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for putting execute template
/// </summary>
TEST_F(ExecuteTemplateTest, TestPutExecuteTemplateOnline) {
	std::shared_ptr<PutExecuteTemplateOnlineRequest> request=
			std::make_shared<PutExecuteTemplateOnlineRequest>(
		generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleMailMergeTemplate.docx")), STCONVERT("template")),
		generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleExecuteTemplateData.txt")), STCONVERT("data")),
		boost::none, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->putExecuteTemplateOnline(request).get();

	ASSERT_TRUE(result.getData()->peek());
}