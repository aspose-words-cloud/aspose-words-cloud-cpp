/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="watermarkTest.cpp">
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
/// Example of how to work with watermarks
/// </summary>
class WatermarkTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions/Watermark"));
};

/// <summary>
/// Test for adding watermark image
/// </summary>
TEST_F(WatermarkTest, TestPostInsertDocumentWatermarkImage) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostInsertDocumentWatermarkImage.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		image = STCONVERT("aspose-cloud.png");
	double rotationAngle = 0;

	auto file = generate_http_content_from_file(path_combine(get_data_dir(commonFolder), image));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertWatermarkImageRequest> request=
			std::make_shared<InsertWatermarkImageRequest>(remoteName, file,
		dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, rotationAngle, boost::none);

	AsposeResponse<DocumentResponse> actual = get_api()->insertWatermarkImage(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding watermark image from storage
/// </summary>
TEST_F(WatermarkTest, TestPostInsertWatermarkImage) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostInsertWatermarkImage.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		image = STCONVERT("aspose-cloud.png"),
		remoteImage = STCONVERT("TestPostInsertWatermarkImage.png"),
		fullImagePath = path_combine_url(dataFolder, remoteImage),
		localImagePath = path_combine(get_data_dir(commonFolder), image);
	double rotationAngle = 0;

	auto file = generate_http_content_from_file(path_combine(get_data_dir(commonFolder), image));

	UploadFileToStorage(fullName, filePath);
	UploadFileToStorage(fullImagePath, localImagePath);

	std::shared_ptr<InsertWatermarkImageRequest> request=
			std::make_shared<InsertWatermarkImageRequest>(remoteName, boost::none, dataFolder,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, rotationAngle, fullImagePath);

	AsposeResponse<DocumentResponse> actual = get_api()->insertWatermarkImage(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding watermark test
/// </summary>
TEST_F(WatermarkTest, TestPostInsertWatermarkText) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostInsertWatermarkText.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<WatermarkText> body = std::make_shared<WatermarkText>();
	body->setText(STCONVERT("This is the text"));
	body->setRotationAngle(90);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertWatermarkTextRequest> request=
			std::make_shared<InsertWatermarkTextRequest>(remoteName, body,
		dataFolder, boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);

	AsposeResponse<DocumentResponse> actual = get_api()->insertWatermarkText(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting watermark
/// </summary>
TEST_F(WatermarkTest, TestDeleteDocumentWatermark) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteDocumentWatermark.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteWatermarkRequest> request=
			std::make_shared<DeleteWatermarkRequest>(remoteName,
		dataFolder, boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);

	AsposeResponse<DocumentResponse> actual = get_api()->deleteWatermark(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}