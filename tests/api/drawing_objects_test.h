/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="drawing_objects_test.h">
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

#pragma once
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
/// Test for getting drawing objects from document online.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectsOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetDocumentDrawingObjectsOnlineRequest> request(new requests::GetDocumentDrawingObjectsOnlineRequest(
        requestDocumentStream,
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectsOnline(request);
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
/// Test for getting drawing object by specified index online.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectByIndexOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetDocumentDrawingObjectByIndexOnlineRequest> request(new requests::GetDocumentDrawingObjectByIndexOnlineRequest(
        requestDocumentStream,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectByIndexOnline(request);
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
/// Test for getting drawing object by specified index and format online.
/// </summary>
TEST_F(DrawingObjectsTests, TestRenderDrawingObjectOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::RenderDrawingObjectOnlineRequest> request(new requests::RenderDrawingObjectOnlineRequest(
        requestDocumentStream,
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderDrawingObjectOnline(request);
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
/// Test for reading drawing object's image data online.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectImageDataOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetDocumentDrawingObjectImageDataOnlineRequest> request(new requests::GetDocumentDrawingObjectImageDataOnlineRequest(
        requestDocumentStream,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectImageDataOnline(request);
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
/// Test for getting drawing object OLE data online.
/// </summary>
TEST_F(DrawingObjectsTests, TestGetDocumentDrawingObjectOleDataOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localDrawingFile)), std::istream::binary));
    std::shared_ptr<requests::GetDocumentDrawingObjectOleDataOnlineRequest> request(new requests::GetDocumentDrawingObjectOleDataOnlineRequest(
        requestDocumentStream,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L"sections/0"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentDrawingObjectOleDataOnline(request);
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
    std::wstring remoteFileName = L"TestInsetDrawingObject.docx";

    auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
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
        requestImageFileStream,
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
/// Test for adding drawing object online.
/// </summary>
TEST_F(DrawingObjectsTests, TestInsertDrawingObjectOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectInsert >();
    requestDrawingObject->setHeight(std::make_shared< double >(0));
    requestDrawingObject->setLeft(std::make_shared< double >(0));
    requestDrawingObject->setTop(std::make_shared< double >(0));
    requestDrawingObject->setWidth(std::make_shared< double >(0));
    requestDrawingObject->setRelativeHorizontalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeHorizontalPosition::MARGIN));
    requestDrawingObject->setRelativeVerticalPosition(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition >(aspose::words::cloud::models::DrawingObjectInsert::RelativeVerticalPosition::MARGIN));
    requestDrawingObject->setWrapType(std::make_shared< aspose::words::cloud::models::DrawingObjectInsert::WrapType >(aspose::words::cloud::models::DrawingObjectInsert::WrapType::INLINE));

    std::shared_ptr<requests::InsertDrawingObjectOnlineRequest> request(new requests::InsertDrawingObjectOnlineRequest(
        requestDocumentStream,
        requestDrawingObject,
        requestImageFileStream,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertDrawingObjectOnline(request);
}

/// <summary>
/// Test for adding drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestInsertDrawingObjectWithoutNodePath) {
    std::wstring remoteFileName = L"TestInsetDrawingObjectWithoutNodePath.docx";

    auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
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
        requestImageFileStream,
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
/// Test for deleting drawing object online.
/// </summary>
TEST_F(DrawingObjectsTests, TestDeleteDrawingObjectOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteDrawingObjectOnlineRequest> request(new requests::DeleteDrawingObjectOnlineRequest(
        requestDocumentStream,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteDrawingObjectOnline(request);
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
    std::wstring remoteFileName = L"TestUpdateDrawingObject.docx";

    auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
    requestDrawingObject->setLeft(std::make_shared< double >(0));

    std::shared_ptr<requests::UpdateDrawingObjectRequest> request(new requests::UpdateDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestDrawingObject,
        requestImageFileStream,
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
/// Test for updating drawing object online.
/// </summary>
TEST_F(DrawingObjectsTests, TestUpdateDrawingObjectOnline) {
    auto requestDocumentStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
    requestDrawingObject->setLeft(std::make_shared< double >(0));

    std::shared_ptr<requests::UpdateDrawingObjectOnlineRequest> request(new requests::UpdateDrawingObjectOnlineRequest(
        requestDocumentStream,
        requestDrawingObject,
        requestImageFileStream,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateDrawingObjectOnline(request);
}

/// <summary>
/// Test for updating drawing object without node path.
/// </summary>
TEST_F(DrawingObjectsTests, TestUpdateDrawingObjectWithoutNodePath) {
    std::wstring remoteFileName = L"TestUpdateDrawingObjectWithoutNodePath.docx";

    auto requestImageFileStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/aspose-cloud.png")), std::istream::binary));
    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDrawingObject = std::make_shared< aspose::words::cloud::models::DrawingObjectUpdate >();
    requestDrawingObject->setLeft(std::make_shared< double >(0));

    std::shared_ptr<requests::UpdateDrawingObjectRequest> request(new requests::UpdateDrawingObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestDrawingObject,
        requestImageFileStream,
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
