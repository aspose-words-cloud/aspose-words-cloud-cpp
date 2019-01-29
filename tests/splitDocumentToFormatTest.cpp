#include "TestBase.h"

/// <summary>
/// Example of how to split document and return result with specified format and page rang
/// </summary>
class SplitDocumentToFormatTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\SplitDocument"));
};

/// <summary>
/// Test for document splitting
/// </summary>
TEST_F(SplitDocumentToFormatTest, TestPostSplitDocument)
{
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostSplitDocument.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		format = STCONVERT("text"),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".text"));

	int32_t from = 1,
		to = 2;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostSplitDocumentRequest> request=
			std::make_shared<PostSplitDocumentRequest>(remoteName, dataFolder, boost::none, boost::none,
		boost::none, destFileName, format, from, to, boost::none, boost::none);

	std::shared_ptr<SplitDocumentResponse> actual = get_api()->postSplitDocument(request).get();

	ASSERT_EQ(200, actual->getCode());
}