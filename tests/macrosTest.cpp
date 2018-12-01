#include "TestBase.h"

/// <summary>
/// Example of how to work with macros
/// </summary>
class MacrosTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Macros"));
};

/// <summary>
/// Test for deleting macros
/// </summary>
TEST_F(MacrosTest, TestDeleteDocumentMacros) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteDocumentMacros.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteDocumentMacrosRequest> request(new DeleteDocumentMacrosRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteDocumentMacros(request).get();

	ASSERT_EQ(200, actual->getCode());
}