/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="watermarkTests.cpp">
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
/// Example of how to work with watermarks.
/// </summary>
class WatermarkTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/Watermark");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for adding watermark image.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkImage) {
    utility::string_t remoteFileName = STCONVERT("TestInsertWatermarkImage.docx");
    utility::string_t remoteImagePath = remoteDataFolder + STCONVERT("/TestInsertWatermarkImage.png");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );
    UploadFileToStorage(
        remoteImagePath,
        path_combine(LocalTestDataFolder, STCONVERT("Common/aspose-cloud.png"))
    );

    std::shared_ptr< InsertWatermarkImageRequest > request(new InsertWatermarkImageRequest(
        remoteFileName,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none,
        boost::none,
        remoteImagePath
    ));

   auto actual = get_api()->insertWatermarkImage(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getDocument() != nullptr);
   ASSERT_EQ(0, actual.body->getDocument()->getFileName().rfind(STCONVERT("TestInsertWatermarkImage.docx"), 0));
}

/// <summary>
/// Test for adding watermark text.
/// </summary>
TEST_F(WatermarkTests, TestInsertWatermarkText) {
    utility::string_t remoteFileName = STCONVERT("TestInsertWatermarkText.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestWatermarkText = std::make_shared< WatermarkText >();
    requestWatermarkText->setText(STCONVERT("This is the text"));
    requestWatermarkText->setRotationAngle(90);

    std::shared_ptr< InsertWatermarkTextRequest > request(new InsertWatermarkTextRequest(
        remoteFileName,
        requestWatermarkText,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertWatermarkText(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getDocument() != nullptr);
   ASSERT_EQ(0, actual.body->getDocument()->getFileName().rfind(STCONVERT("TestInsertWatermarkText.docx"), 0));
}

/// <summary>
/// Test for deleting watermark.
/// </summary>
TEST_F(WatermarkTests, TestDeleteWatermark) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteWatermark.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteWatermarkRequest > request(new DeleteWatermarkRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->deleteWatermark(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_EQ(true, actual.body->getDocument() != nullptr);
   ASSERT_EQ(0, actual.body->getDocument()->getFileName().rfind(STCONVERT("TestDeleteWatermark.docx"), 0));
}
