#include "TestBase.h"

/// <summary>
/// Example of how to work with merge fields
/// </summary>
class MailMergeFiledsTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\MailMerge")),
		mailMergeFolder = STCONVERT("DocumentActions/MailMerge");
};

/// <summary>
/// Test for getting mailmerge fields
/// </summary>
TEST_F(MailMergeFiledsTest, TestGetDocumentFieldNames) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentFieldNames.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentFieldNamesRequest> request=
			std::make_shared<GetDocumentFieldNamesRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<FieldNamesResponse> actual = get_api()->getDocumentFieldNames(request).get();

	ASSERT_EQ(200, actual->getCode());

}

/// <summary>
/// Test for putting new fileds
/// </summary>
TEST_F(MailMergeFiledsTest, TestPutDocumentFieldNames) {
	std::shared_ptr<HttpContent> file = generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleExecuteTemplate.docx")));

	std::shared_ptr<PutDocumentFieldNamesRequest> request=
			std::make_shared<PutDocumentFieldNamesRequest>(file, boost::none);

	std::shared_ptr<FieldNamesResponse> actual = get_api()->putDocumentFieldNames(request).get();

	ASSERT_EQ(200, actual->getCode());

}