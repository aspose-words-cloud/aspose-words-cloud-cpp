#include "TestBase.h"

/// <summary>
/// Example of how to get document statistics
/// </summary>
class DocumentStatisticsTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\Statistics"));
};

/// <summary>
/// Test for getting document statistics
/// </summary>
TEST_F(DocumentStatisticsTest, TestGetDocumentStatistics) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentStatistics.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentStatisticsRequest> request(new GetDocumentStatisticsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<StatDataResponse> actual = get_api()->getDocumentStatistics(request).get();

	ASSERT_EQ(200, actual->getCode());
}
