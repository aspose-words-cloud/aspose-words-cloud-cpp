#include "TestBase.h"

/// <summary>
/// Example of how to work with table borders
/// <remarks>These methods are applicable to cells and rows</remarks>
/// </summary>
class TableBorderTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Tables")),
		tableFolder = STCONVERT("DocumentElements\\Tables");
};

/// <summary>
/// Test for getting borders
/// </summary>
TEST_F(TableBorderTest, TestGetTableBorders) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTableBorders.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetBordersRequest> request(new GetBordersRequest(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), dataFolder, boost::none,
		boost::none, boost::none));

	std::shared_ptr<BordersResponse> actual = get_api()->getBorders(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting border
/// </summary>
TEST_F(TableBorderTest, TestGetTableBorder) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestGetTableBorder.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetBorderRequest> request(new GetBorderRequest(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), 0, dataFolder, boost::none,
		boost::none, boost::none));

	std::shared_ptr<BorderResponse> actual = get_api()->getBorder(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting borders
/// </summary>
TEST_F(TableBorderTest, TestDeleteTableBorders) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestDeleteTableBorders.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteBordersRequest> request(new DeleteBordersRequest(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<BordersResponse> actual = get_api()->deleteBorders(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting border
/// </summary>
TEST_F(TableBorderTest, TestDeleteTableBorder) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestDeleteTableBorder.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteBorderRequest> request(new DeleteBorderRequest(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<BorderResponse> actual = get_api()->deleteBorder(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating border
/// </summary>
TEST_F(TableBorderTest, TestUpdateTableBorder) {
	utility::string_t
		localName = STCONVERT("TablesGet.docx"),
		remoteName = STCONVERT("TestUpdateTableBorder.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	std::shared_ptr<XmlColor> color(new XmlColor);
	color->setAlpha(2);

	std::shared_ptr<Border> border(new Border);
	border->setBorderType(STCONVERT("Left"));
	border->setColor(color);
	border->setDistanceFromText(6);
	border->setLineStyle(STCONVERT("DashDotStroker"));
	border->setLineWidth(2);
	border->setShadow(true);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateBorderRequest> request(new UpdateBorderRequest(remoteName, border, STCONVERT("tables/1/rows/0/cells/0/"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<BorderResponse> actual = get_api()->updateBorder(request).get();

	ASSERT_EQ(200, actual->getCode());
}