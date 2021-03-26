/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="drawing_objects_test.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "../test_base.h"

/// <summary>
/// Example of how to get drawing objects.
/// </summary>
class DrawingObjectsTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/DrawingObjectss";
    std::wstring localFile = L"Common/test_multi_pages.docx";
    std::wstring localDrawingFile = L"DocumentElements/DrawingObjects/sample_EmbeddedOLE.docx";

};

/// <summary>
/// Test for getting drawing objects from document.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjects) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjects.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectsRequest> request(new requests::GetDocumentDrawingObjectsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjects(request);
}



/// <summary>
/// Test for getting drawing objects from document without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectsWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectsRequest> request(new requests::GetDocumentDrawingObjectsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjects(request);
}

/// <summary>
/// Test for getting drawing object by specified index.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectByIndex) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectByIndex.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectByIndexRequest> request(new requests::GetDocumentDrawingObjectByIndexRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectByIndex(request);
}



/// <summary>
/// Test for getting drawing object by specified index without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectByIndexWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectByIndexWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectByIndexRequest> request(new requests::GetDocumentDrawingObjectByIndexRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectByIndex(request);
}

/// <summary>
/// Test for getting drawing object by specified index and format.
/// </summary>
TEST_F(DrawingObjectsTests, TestRenderDrawingObject) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectByIndexWithFormat.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderDrawingObjectRequest> request(new requests::RenderDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderDrawingObject(request);
}



/// <summary>
/// Test for getting drawing object by specified index and format without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestRenderDrawingObjectWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectByIndexWithFormatWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderDrawingObjectRequest> request(new requests::RenderDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderDrawingObject(request);
}

/// <summary>
/// Test for reading drawing object's image data.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectImageData) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectImageData.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectImageDataRequest> request(new requests::GetDocumentDrawingObjectImageDataRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectImageData(request);
}



/// <summary>
/// Test for reading drawing object's image data without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectImageDataWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectImageDataWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectImageDataRequest> request(new requests::GetDocumentDrawingObjectImageDataRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectImageData(request);
}

/// <summary>
/// Test for getting drawing object OLE data.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectOleData) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectOleData.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localDrawingFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectOleDataRequest> request(new requests::GetDocumentDrawingObjectOleDataRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectOleData(request);
}



/// <summary>
/// Test for getting drawing object OLE data without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectOleDataWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetDocumentDrawingObjectOleDataWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localDrawingFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentDrawingObjectOleDataRequest> request(new requests::GetDocumentDrawingObjectOleDataRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectOleData(request);
}

/// <summary>
/// Test for adding drawing object.
/// </summary>
TEST_F(DrawingObjectsTests, TestInsertDrawingObject) {
    auto imageFileStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(L"Common/aspose-cloud.png"), std::istream::binary));
    std::wstring remoteFileName = L"TestInsetDrawingObject.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectInsert >();
    requestDrawingObject->setHeight(std::make_shared< double >(0));
    requestDrawingObject->setLeft(std::make_shared< double >(0));
    requestDrawingObject->setTop(std::make_shared< double >(0));
    requestDrawingObject->setWidth(std::make_shared< double >(0));
    requestDrawingObject->setRelativeHorizontalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition::MARGIN));
    requestDrawingObject->setRelativeVerticalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition::MARGIN));
    requestDrawingObject->setWrapType(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::WrapType >(aspose::words::cloud::models::DrawingObjectInsert::WrapType::INLINE));

    std::shared_ptr<requests::InsertDrawingObjectRequest> request(new requests::InsertDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestDrawingObject,
        imageFileStream,
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertDrawingObject(request);
}



/// <summary>
/// Test for adding drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestInsertDrawingObjectWithoutNodePath) {
    auto imageFileStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(L"Common/aspose-cloud.png"), std::istream::binary));
    std::wstring remoteFileName = L"TestInsetDrawingObjectWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectInsert >();
    requestDrawingObject->setHeight(std::make_shared< double >(0));
    requestDrawingObject->setLeft(std::make_shared< double >(0));
    requestDrawingObject->setTop(std::make_shared< double >(0));
    requestDrawingObject->setWidth(std::make_shared< double >(0));
    requestDrawingObject->setRelativeHorizontalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition::MARGIN));
    requestDrawingObject->setRelativeVerticalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition::MARGIN));
    requestDrawingObject->setWrapType(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::WrapType >(aspose::words::cloud::models::DrawingObjectInsert::WrapType::INLINE));

    std::shared_ptr<requests::InsertDrawingObjectRequest> request(new requests::InsertDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestDrawingObject,
        imageFileStream,
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertDrawingObject(request);
}

/// <summary>
/// Test for deleting drawing object.
/// </summary>
TEST_F(DrawingObjectsTests, TestDeleteDrawingObject) {
    std::wstring remoteFileName = L"TestDeleteDrawingObject.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteDrawingObjectRequest> request(new requests::DeleteDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteDrawingObject(request);
}



/// <summary>
/// Test for deleting drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestDeleteDrawingObjectWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteDrawingObjectWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteDrawingObjectRequest> request(new requests::DeleteDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->deleteDrawingObject(request);
}

/// <summary>
/// Test for updating drawing object.
/// </summary>
TEST_F(DrawingObjectsTests, TestUpdateDrawingObject) {
    auto imageFileStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(L"Common/aspose-cloud.png"), std::istream::binary));
    std::wstring remoteFileName = L"TestUpdateDrawingObject.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
    requestDrawingObject->setLeft(std::make_shared< double >(0));

    std::shared_ptr<requests::UpdateDrawingObjectRequest> request(new requests::UpdateDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestDrawingObject,
        imageFileStream,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateDrawingObject(request);
}



/// <summary>
/// Test for updating drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestUpdateDrawingObjectWithoutNodePath) {
    auto imageFileStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(L"Common/aspose-cloud.png"), std::istream::binary));
    std::wstring remoteFileName = L"TestUpdateDrawingObjectWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
    requestDrawingObject->setLeft(std::make_shared< double >(0));

    std::shared_ptr<requests::UpdateDrawingObjectRequest> request(new requests::UpdateDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestDrawingObject,
        imageFileStream,
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateDrawingObject(request);
}
