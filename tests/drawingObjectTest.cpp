/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="drawingObjectTest.cpp">
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
/// Example of how to get drawing objects
/// </summary>
class DrawingObjectsTest : public InfrastructureTest {
protected:
    const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder , STCONVERT("DocumentElements/DrawingObjects"));
    const utility::string_t drawingFolder = STCONVERT("DocumentElements/DrawingObjects");
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

	std::shared_ptr<GetDocumentDrawingObjectsRequest> request=
			std::make_shared<GetDocumentDrawingObjectsRequest>(remoteName, STCONVERT("sections/0"), dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<DrawingObjectsResponse> actual = get_api()->getDocumentDrawingObjects(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request=
			std::make_shared<GetDocumentDrawingObjectByIndexRequest>(remoteName, STCONVERT("sections/0"), objectIndex,
		dataFolder, boost::none, boost::none, boost::none);

	AsposeResponse<DrawingObjectResponse> actual = get_api()->getDocumentDrawingObjectByIndex(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for rendering drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectByIndexWithFormat) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestRenderDrawingObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		format = STCONVERT("png");

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderDrawingObjectRequest> request=
			std::make_shared<RenderDrawingObjectRequest>(remoteName, format, STCONVERT("sections/0"), objectIndex,
		dataFolder, boost::none, boost::none, boost::none, boost::none);

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

	std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request=
			std::make_shared<GetDocumentDrawingObjectOleDataRequest>(remoteName, STCONVERT("sections/0"), objectIndex,
		dataFolder, boost::none, boost::none, boost::none);

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

	std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request=
			std::make_shared<GetDocumentDrawingObjectImageDataRequest>(remoteName, STCONVERT("sections/0"), objectIndex,
		dataFolder, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->getDocumentDrawingObjectImageData(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for updating drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestPutDrawingObject) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutDrawingObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		image = STCONVERT("aspose-cloud.png"),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DrawingObjectUpdate> body= std::make_shared<DrawingObjectUpdate>();
	std::shared_ptr<UpdateDrawingObjectRequest> request=
			std::make_shared<UpdateDrawingObjectRequest>(remoteName, body,
		generate_http_content_from_file(path_combine(get_data_dir(commonFolder), image)),
		STCONVERT(""), 0, dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<DrawingObjectResponse> actual = get_api()->updateDrawingObject(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<DeleteDrawingObjectRequest> request=
			std::make_shared<DeleteDrawingObjectRequest>(remoteName, STCONVERT(""), objectIndex, dataFolder,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteDrawingObject(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for adding drawing object
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

	std::shared_ptr<DrawingObjectInsert> body= std::make_shared<DrawingObjectInsert>();
	std::shared_ptr<InsertDrawingObjectRequest> request=
			std::make_shared<InsertDrawingObjectRequest>(remoteName, body,
		generate_http_content_from_file(imagePath), STCONVERT(""), dataFolder,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<DrawingObjectResponse> actual = get_api()->insertDrawingObject(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting drawing objects without node path from document 
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectsWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectsWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectsWithoutNodePathRequest> request =
		std::make_shared<GetDocumentDrawingObjectsWithoutNodePathRequest>(remoteName, dataFolder, boost::none,
			boost::none, boost::none);

	AsposeResponse<DrawingObjectsResponse> actual = get_api()->getDocumentDrawingObjectsWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting drawing object by specified index 
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectByIndexWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectByIndexWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectByIndexWithoutNodePathRequest> request =
		std::make_shared<GetDocumentDrawingObjectByIndexWithoutNodePathRequest>(remoteName, objectIndex,
			dataFolder, boost::none, boost::none, boost::none);

	AsposeResponse<DrawingObjectResponse> actual = get_api()->getDocumentDrawingObjectByIndexWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for rendering drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestRenderDrawingObjectWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestRenderDrawingObject.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		format = STCONVERT("png");

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderDrawingObjectWithoutNodePathRequest> request =
		std::make_shared<RenderDrawingObjectWithoutNodePathRequest>(remoteName, format, objectIndex,
			dataFolder, boost::none, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->renderDrawingObjectWithoutNodePath(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for reading drawing object's image data
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectOleDataWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("sample_EmbeddedOLE.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectOleDataWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(drawingFolder), localName);

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectOleDataWithoutNodePathRequest> request =
		std::make_shared<GetDocumentDrawingObjectOleDataWithoutNodePathRequest>(remoteName, objectIndex,
			dataFolder, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->getDocumentDrawingObjectOleDataWithoutNodePath(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for getting drawing object image data
/// </summary>
TEST_F(DrawingObjectsTest, TestGetDocumentDrawingObjectImageDataWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentDrawingObjectImageDataWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	int32_t objectIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentDrawingObjectImageDataWithoutNodePathRequest> request =
		std::make_shared<GetDocumentDrawingObjectImageDataWithoutNodePathRequest>(remoteName, objectIndex,
			dataFolder, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->getDocumentDrawingObjectImageDataWithoutNodePath(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for updating drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestPutDrawingObjectWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutDrawingObjectWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		image = STCONVERT("aspose-cloud.png"),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DrawingObjectUpdate> body= std::make_shared<DrawingObjectUpdate>();
	std::shared_ptr<UpdateDrawingObjectWithoutNodePathRequest> request =
		std::make_shared<UpdateDrawingObjectWithoutNodePathRequest>(remoteName, body,
			generate_http_content_from_file(path_combine(get_data_dir(commonFolder), image)),
			0, dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<DrawingObjectResponse> actual = get_api()->updateDrawingObjectWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestDeleteDrawingObjectWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteDrawingObjectWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t objectIndex = 0;
	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteDrawingObjectWithoutNodePathRequest> request =
		std::make_shared<DeleteDrawingObjectWithoutNodePathRequest>(remoteName, objectIndex, dataFolder,
			boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteDrawingObjectWithoutNodePath(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for inserting drawing object
/// </summary>
TEST_F(DrawingObjectsTest, TestPostDrawingObjectWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostDrawingObjectWithoutNodePath.docx"),
		image = STCONVERT("aspose-cloud.png"),
		fullName = path_combine_url(dataFolder, remoteName),
		imagePath = path_combine(get_data_dir(commonFolder), image),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);
	
	std::shared_ptr<DrawingObjectInsert> body= std::make_shared<DrawingObjectInsert>();
	std::shared_ptr<InsertDrawingObjectWithoutNodePathRequest> request =
		std::make_shared<InsertDrawingObjectWithoutNodePathRequest>(remoteName, body,
			generate_http_content_from_file(imagePath), dataFolder,
			boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<DrawingObjectResponse> actual = get_api()->insertDrawingObjectWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}