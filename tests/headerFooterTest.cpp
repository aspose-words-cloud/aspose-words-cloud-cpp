#include "TestBase.h"

/// <summary>
/// Example of how to work with headers and footers
/// </summary>
class HeaderFooterTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\HeaderFooter"));
};

/// <summary>
/// Test for deleting headers and footers
/// </summary>
TEST_F(HeaderFooterTest, TestDeleteHeadersFooters) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteHeadersFooters.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteHeadersFootersRequest> request(new DeleteHeadersFootersRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none, STCONVERT("sections/0"), boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteHeadersFooters(request).get();

	ASSERT_EQ(200, actual->getCode());

}