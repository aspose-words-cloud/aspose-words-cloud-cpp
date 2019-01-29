#include "TestBase.h"

/// <summary>
/// Example of how to work with watermarks
/// </summary>
class WatermarkTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\Watermark"));
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

	std::shared_ptr<PostInsertDocumentWatermarkImageRequest> request=
			std::make_shared<PostInsertDocumentWatermarkImageRequest>(remoteName, file,
		dataFolder, boost::none, boost::none, boost::none, destFileName, boost::none, boost::none, rotationAngle, boost::none);

	std::shared_ptr<DocumentResponse> actual = get_api()->postInsertDocumentWatermarkImage(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<PostInsertDocumentWatermarkImageRequest> request=
			std::make_shared<PostInsertDocumentWatermarkImageRequest>(remoteName, boost::none, dataFolder,
		boost::none, boost::none, boost::none, destFileName, boost::none, boost::none, rotationAngle, fullImagePath);

	std::shared_ptr<DocumentResponse> actual = get_api()->postInsertDocumentWatermarkImage(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<PostInsertDocumentWatermarkTextRequest> request=
			std::make_shared<PostInsertDocumentWatermarkTextRequest>(remoteName, body,
		dataFolder, boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<DocumentResponse> actual = get_api()->postInsertDocumentWatermarkText(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<DeleteDocumentWatermarkRequest> request=
			std::make_shared<DeleteDocumentWatermarkRequest>(remoteName,
		dataFolder, boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteDocumentWatermark(request).get();

	ASSERT_EQ(200, actual->getCode());
}