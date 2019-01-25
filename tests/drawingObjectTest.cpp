#include "TestBase.h"

/// <summary>
/// Example of how to get drawing objects
/// </summary>
class DrawingObjectsTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\DrawingObjects")),
		drawingFolder = STCONVERT("DocumentElements") +
				SYSTEM_DELIMITER +  STCONVERT("DrawingObjects");
};

/// <summary>
/// Test for getting drawing objects from document
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjects) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjects.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectsRequest> request(new GetDocumentDrawingObjectsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<DrawingObjectsResponse> actual = get_api()->getDocumentDrawingObjects(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting drawing object by specified index
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectByIndex) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectByIndex.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request(new GetDocumentDrawingObjectByIndexRequest(remoteName, objectIndex,
		dataFolder, boost::none, boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<DrawingObjectResponse> actual = get_api()->getDocumentDrawingObjectByIndex(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting drawing object by specified index and format
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectByIndexWithFormat) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectByIndexWithFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		format = STCONVERT("png");

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderDrawingObjectRequest> request(new RenderDrawingObjectRequest(remoteName, format, objectIndex,
		dataFolder, boost::none, boost::none, boost::none, STCONVERT("sections/0"), boost::none));

	HttpContent result = get_api()->renderDrawingObject(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for reading drawing object's image dat
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectOleData) {
	utility::string_t
		localName = STCONVERT("sample_EmbeddedOLE.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectOleData.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(drawingFolder), localName);

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request(new GetDocumentDrawingObjectOleDataRequest(remoteName, objectIndex,
		dataFolder, boost::none, boost::none, boost::none, STCONVERT("sections/0")));

	HttpContent result = get_api()->getDocumentDrawingObjectOleData(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for getting drawing object OLE data
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectImageData) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectImageData.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request(new GetDocumentDrawingObjectImageDataRequest(remoteName, objectIndex,
		dataFolder, boost::none, boost::none, boost::none, STCONVERT("sections/0")));

	HttpContent result = get_api()->getDocumentDrawingObjectImageData(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for adding drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestPutDrawingObject) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutDrawingObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		image = STCONVERT("aspose-cloud.png"),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutDrawingObjectRequest> request(new PutDrawingObjectRequest(remoteName, STCONVERT("{\"Left\": 0}"),
		generate_http_content_from_file(path_combine(get_data_dir(commonFolder), image)), dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<DrawingObjectResponse> actual = get_api()->putDrawingObject(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestDeleteDrawingObject) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteDrawingObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t objectIndex = 0;
	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteDrawingObjectRequest> request(new DeleteDrawingObjectRequest(remoteName, objectIndex, dataFolder,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteDrawingObject(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestPostDrawingObject) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostDrawingObject.docx"),
		image = STCONVERT("aspose-cloud.png"),
		fullName = path_combine_url(dataFolder, remoteName),
		imagePath = path_combine(get_data_dir(commonFolder), image),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostDrawingObjectRequest> request(new PostDrawingObjectRequest(remoteName, STCONVERT("{\"Left\": 0}"),
		generate_http_content_from_file(imagePath), 0, dataFolder,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<DrawingObjectResponse> actual = get_api()->postDrawingObject(request).get();

	ASSERT_EQ(200, actual->getCode());
}