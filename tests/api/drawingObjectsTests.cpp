/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="drawingObjectsTests.cpp">
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
/// Example of how to get drawing objects.
/// </summary>
class DrawingObjectsTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/DrawingObjectss");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");
    utility::string_t localDrawingFile = STCONVERT("DocumentElements/DrawingObjects/sample_EmbeddedOLE.docx");

};

/// <summary>
/// Test for getting drawing objects from document.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjects) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjects.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectsRequest > request(new GetDocumentDrawingObjectsRequest(
        remoteFileName,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentDrawingObjects(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting drawing objects from document without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectsWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectsWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectsRequest > request(new GetDocumentDrawingObjectsRequest(
        remoteFileName,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentDrawingObjects(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting drawing object by specified index.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectByIndex) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectByIndex.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectByIndexRequest > request(new GetDocumentDrawingObjectByIndexRequest(
        remoteFileName,
        0,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentDrawingObjectByIndex(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting drawing object by specified index without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectByIndexWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectByIndexWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectByIndexRequest > request(new GetDocumentDrawingObjectByIndexRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentDrawingObjectByIndex(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting drawing object by specified index and format.
/// </summary>
TEST_F(DrawingObjectsTests, TestRenderDrawingObject) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectByIndexWithFormat.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderDrawingObjectRequest > request(new RenderDrawingObjectRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderDrawingObject(request).get();
}

/// <summary>
/// Test for getting drawing object by specified index and format without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestRenderDrawingObjectWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectByIndexWithFormatWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< RenderDrawingObjectRequest > request(new RenderDrawingObjectRequest(
        remoteFileName,
        STCONVERT("png"),
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->renderDrawingObject(request).get();
}

/// <summary>
/// Test for reading drawing object's image data.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectImageData) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectImageData.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectImageDataRequest > request(new GetDocumentDrawingObjectImageDataRequest(
        remoteFileName,
        0,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->getDocumentDrawingObjectImageData(request).get();
}

/// <summary>
/// Test for reading drawing object's image data without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectImageDataWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectImageDataWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectImageDataRequest > request(new GetDocumentDrawingObjectImageDataRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->getDocumentDrawingObjectImageData(request).get();
}

/// <summary>
/// Test for getting drawing object OLE data.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectOleData) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectOleData.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localDrawingFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectOleDataRequest > request(new GetDocumentDrawingObjectOleDataRequest(
        remoteFileName,
        0,
        STCONVERT("sections/0"),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->getDocumentDrawingObjectOleData(request).get();
}

/// <summary>
/// Test for getting drawing object OLE data without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectOleDataWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentDrawingObjectOleDataWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localDrawingFile)
    );

    std::shared_ptr< GetDocumentDrawingObjectOleDataRequest > request(new GetDocumentDrawingObjectOleDataRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->getDocumentDrawingObjectOleData(request).get();
}

/// <summary>
/// Test for adding drawing object.
/// </summary>
TEST_F(DrawingObjectsTests, TestInsertDrawingObject) {
    utility::string_t remoteFileName = STCONVERT("TestInsetDrawingObject.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestDrawingObject = std::make_shared< DrawingObjectInsert >();
    requestDrawingObject->setHeight(0);
    requestDrawingObject->setLeft(0);
    requestDrawingObject->setTop(0);
    requestDrawingObject->setWidth(0);
    requestDrawingObject->setRelativeHorizontalPosition(STCONVERT("Margin"));
    requestDrawingObject->setRelativeVerticalPosition(STCONVERT("Margin"));
    requestDrawingObject->setWrapType(STCONVERT("Inline"));

    std::shared_ptr< InsertDrawingObjectRequest > request(new InsertDrawingObjectRequest(
        remoteFileName,
        requestDrawingObject,
        generate_http_content_from_file(path_combine(LocalTestDataFolder, STCONVERT("Common/aspose-cloud.png"))),
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertDrawingObject(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for adding drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestInsertDrawingObjectWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestInsetDrawingObjectWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestDrawingObject = std::make_shared< DrawingObjectInsert >();
    requestDrawingObject->setHeight(0);
    requestDrawingObject->setLeft(0);
    requestDrawingObject->setTop(0);
    requestDrawingObject->setWidth(0);
    requestDrawingObject->setRelativeHorizontalPosition(STCONVERT("Margin"));
    requestDrawingObject->setRelativeVerticalPosition(STCONVERT("Margin"));
    requestDrawingObject->setWrapType(STCONVERT("Inline"));

    std::shared_ptr< InsertDrawingObjectRequest > request(new InsertDrawingObjectRequest(
        remoteFileName,
        requestDrawingObject,
        generate_http_content_from_file(path_combine(LocalTestDataFolder, STCONVERT("Common/aspose-cloud.png"))),
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->insertDrawingObject(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting drawing object.
/// </summary>
TEST_F(DrawingObjectsTests, TestDeleteDrawingObject) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteDrawingObject.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteDrawingObjectRequest > request(new DeleteDrawingObjectRequest(
        remoteFileName,
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteDrawingObject(request).get();
}

/// <summary>
/// Test for deleting drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestDeleteDrawingObjectWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestDeleteDrawingObjectWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< DeleteDrawingObjectRequest > request(new DeleteDrawingObjectRequest(
        remoteFileName,
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   get_api()->deleteDrawingObject(request).get();
}

/// <summary>
/// Test for updating drawing object.
/// </summary>
TEST_F(DrawingObjectsTests, TestUpdateDrawingObject) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateDrawingObject.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestDrawingObject = std::make_shared< DrawingObjectUpdate >();
    requestDrawingObject->setLeft(0);

    std::shared_ptr< UpdateDrawingObjectRequest > request(new UpdateDrawingObjectRequest(
        remoteFileName,
        requestDrawingObject,
        generate_http_content_from_file(path_combine(LocalTestDataFolder, STCONVERT("Common/aspose-cloud.png"))),
        0,
        STCONVERT(""),
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateDrawingObject(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestUpdateDrawingObjectWithoutNodePath) {
    utility::string_t remoteFileName = STCONVERT("TestUpdateDrawingObjectWithoutNodePath.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestDrawingObject = std::make_shared< DrawingObjectUpdate >();
    requestDrawingObject->setLeft(0);

    std::shared_ptr< UpdateDrawingObjectRequest > request(new UpdateDrawingObjectRequest(
        remoteFileName,
        requestDrawingObject,
        generate_http_content_from_file(path_combine(LocalTestDataFolder, STCONVERT("Common/aspose-cloud.png"))),
        0,
        boost::none,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->updateDrawingObject(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
