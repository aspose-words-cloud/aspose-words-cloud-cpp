/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="tableBorderTest.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/
#include "TestBase.h"

/// <summary>
/// Example of how to work with table borders
/// <remarks>These methods are applicable to cells and rows</remarks>
/// </summary>
class TableBorderTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Tables")),
		tableFolder = STCONVERT("DocumentElements/Tables");
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

	std::shared_ptr<GetBordersRequest> request=
			std::make_shared<GetBordersRequest>(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), dataFolder,
					boost::none, boost::none, boost::none);

	AsposeResponse<BordersResponse> actual = get_api()->getBorders(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<GetBorderRequest> request=
			std::make_shared<GetBorderRequest>(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), 0, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<BorderResponse> actual = get_api()->getBorder(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<DeleteBordersRequest> request=
			std::make_shared<DeleteBordersRequest>(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<BordersResponse> actual = get_api()->deleteBorders(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<DeleteBorderRequest> request= std::make_shared<DeleteBorderRequest>(remoteName, STCONVERT("tables/1/rows/0/cells/0/"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<BorderResponse> actual = get_api()->deleteBorder(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<XmlColor> color= std::make_shared<XmlColor>();
	color->setAlpha(2);

	std::shared_ptr<Border> border= std::make_shared<Border>();
	border->setBorderType(STCONVERT("Left"));
	border->setColor(color);
	border->setDistanceFromText(6);
	border->setLineStyle(STCONVERT("DashDotStroker"));
	border->setLineWidth(2);
	border->setShadow(true);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateBorderRequest> request=
			std::make_shared<UpdateBorderRequest>(remoteName, border, STCONVERT("tables/1/rows/0/cells/0/"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<BorderResponse> actual = get_api()->updateBorder(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}