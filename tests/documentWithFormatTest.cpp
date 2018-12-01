#include "TestBase.h"

/// <summary>
/// Example of how to get document with different format
/// </summary>
class DocumentWithFormatTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\DocumentWithFormat"));
};

/// <summary>
/// Test for getting document with specified format
/// </summary>
TEST_F(DocumentWithFormatTest, TestGetDocumentWithFormat) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentWithFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		format = STCONVERT("text");

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentWithFormatRequest> request(new GetDocumentWithFormatRequest(remoteName, format, dataFolder, boost::none, boost::none,
		boost::none, boost::none, boost::none));

	HttpContent result = get_api()->getDocumentWithFormat(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for getting document with specified format and outPath
/// </summary>
TEST_F(DocumentWithFormatTest, TestGetDocumentWithFormatAndOutPath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentWithFormatAndOutPath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".text")),
		format = STCONVERT("text");

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentWithFormatRequest> request(new GetDocumentWithFormatRequest(remoteName, format, dataFolder, boost::none, boost::none,
		boost::none, destFileName, boost::none));

	get_api()->getDocumentWithFormat(request).get();
	bool result = GetIsExists(destFileName);

	ASSERT_TRUE(result) << "File doesn't exist on storage";
}

/// <summary>
/// Test for getting document with specified format and storage
/// </summary>        
TEST_F(DocumentWithFormatTest, DISABLED_TestGetDocumentFormatUsingStorage) {
	ASSERT_FALSE(true);
}