/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="tableBorderTests.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "../TestBase.h"

/// <summary>
/// Example of how to work with table borders.
/// </summary>
class TableBorderTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/Tables");
    utility::string_t localFile = STCONVERT("DocumentElements/Tables/TablesGet.docx");

};

/// <summary>
/// Test for getting borders.
/// </summary>
TEST_F(TableBorderTests, TestGetBorders) {
    utility::string_t remoteFileName = STCONVERT("TestGetBorders.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetBordersRequest > request(new GetBordersRequest(
        remoteFileName,
        STCONVERT("tables/1/rows/0/cells/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getBorders(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getBorders());
   ASSERT_TRUE(actual.body->getBorders()->getList());
   ASSERT_EQ(6, actual.body->getBorders()->getList().size());
   ASSERT_TRUE(actual.body->getBorders()->getList()[0]->getColor());
   ASSERT_EQ(STCONVERT("#000000"), actual.body->getBorders()->getList()[0]->getColor()->getWeb());
}

/// <summary>
/// Test for getting border.
/// </summary>
TEST_F(TableBorderTests, TestGetBorder) {
    utility::string_t remoteFileName = STCONVERT("TestGetBorder.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetBorderRequest > request(new GetBorderRequest(
        remoteFileName,
        STCONVERT("left"),
        STCONVERT("tables/1/rows/0/cells/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getBorder(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getBorder());
   ASSERT_TRUE(actual.body->getBorder()->getColor());
   ASSERT_EQ(STCONVERT("#000000"), actual.body->getBorder()->getColor()->getWeb());
}

/// <summary>
/// Test for deleting borders.
/// </summary>
TEST_F(TableBorderTests, TestDeleteBorders) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteBorders.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteBordersRequest > request(new DeleteBordersRequest(
        remoteFileName,
        STCONVERT("tables/1/rows/0/cells/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteBorders(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getBorders());
   ASSERT_TRUE(actual.body->getBorders()->getList());
   ASSERT_EQ(6, actual.body->getBorders()->getList().size());
   ASSERT_TRUE(actual.body->getBorders()->getList()[0]->getColor());
   ASSERT_EQ(STCONVERT(""), actual.body->getBorders()->getList()[0]->getColor()->getWeb());
}

/// <summary>
/// Test for deleting border.
/// </summary>
TEST_F(TableBorderTests, TestDeleteBorder) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteBorder.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteBorderRequest > request(new DeleteBorderRequest(
        remoteFileName,
        STCONVERT("left"),
        STCONVERT("tables/1/rows/0/cells/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteBorder(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getBorder());
   ASSERT_TRUE(actual.body->getBorder()->getColor());
   ASSERT_EQ(STCONVERT(""), actual.body->getBorder()->getColor()->getWeb());
}

/// <summary>
/// Test for updating border.
/// </summary>
TEST_F(TableBorderTests, TestUpdateBorder) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateBorder.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestBorderPropertiesColor = std::make_shared< XmlColor >();
    requestBorderPropertiesColor->setAlpha(2);

    auto requestBorderProperties = std::make_shared< Border >();
    requestBorderProperties->setBorderType(STCONVERT("Left"));
    requestBorderProperties->setColor(requestBorderPropertiesColor);
    requestBorderProperties->setDistanceFromText(6.0);
    requestBorderProperties->setLineStyle(STCONVERT("DashDotStroker"));
    requestBorderProperties->setLineWidth(2.0);
    requestBorderProperties->setShadow(true);

    std::shared_ptr< UpdateBorderRequest > request(new UpdateBorderRequest(
        remoteFileName,
        requestBorderProperties,
        STCONVERT("left"),
        STCONVERT("tables/1/rows/0/cells/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateBorder(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(actual.body->getBorder());
   ASSERT_TRUE(actual.body->getBorder()->getColor());
   ASSERT_EQ(STCONVERT("#000002"), actual.body->getBorder()->getColor()->getWeb());
   ASSERT_EQ(6.0, actual.body->getBorder()->getDistanceFromText());
   ASSERT_EQ(2.0, actual.body->getBorder()->getLineWidth());
   ASSERT_TRUE(actual.body->getBorder()->getShadow());
}
