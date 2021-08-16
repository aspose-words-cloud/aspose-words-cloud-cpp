/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="math_object_test.h">
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
/// Example of how to work with MathObjects.
/// </summary>
class MathObjectTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/MathObjects";
    std::wstring localFile = L"DocumentElements/MathObjects/MathObjects.docx";

};

/// <summary>
/// Test for getting mathObjects.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjects) {
    std::wstring remoteFileName = L"TestGetOfficeMathObjects.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetOfficeMathObjectsRequest> request(new requests::GetOfficeMathObjectsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getOfficeMathObjects(request);
    ASSERT_TRUE(actual->getOfficeMathObjects() != nullptr);
    ASSERT_TRUE(actual->getOfficeMathObjects()->getList() != nullptr);
    ASSERT_EQ(16, actual->getOfficeMathObjects()->getList()->size());
    ASSERT_TRUE(actual->getOfficeMathObjects()->getList()->at(0)->getNodeId()->compare(L"0.0.0.0") == 0);
}

/// <summary>
/// Test for getting mathObjects online.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjectsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetOfficeMathObjectsOnlineRequest> request(new requests::GetOfficeMathObjectsOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getOfficeMathObjectsOnline(request);
}

/// <summary>
/// Test for getting mathObjects without node path.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjectsWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetOfficeMathObjectsWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetOfficeMathObjectsRequest> request(new requests::GetOfficeMathObjectsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getOfficeMathObjects(request);
    ASSERT_TRUE(actual->getOfficeMathObjects() != nullptr);
    ASSERT_TRUE(actual->getOfficeMathObjects()->getList() != nullptr);
    ASSERT_EQ(16, actual->getOfficeMathObjects()->getList()->size());
    ASSERT_TRUE(actual->getOfficeMathObjects()->getList()->at(0)->getNodeId()->compare(L"0.0.0.0") == 0);
}

/// <summary>
/// Test for getting mathObject.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObject) {
    std::wstring remoteFileName = L"TestGetOfficeMathObject.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetOfficeMathObjectRequest> request(new requests::GetOfficeMathObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getOfficeMathObject(request);
    ASSERT_TRUE(actual->getOfficeMathObject() != nullptr);
    ASSERT_TRUE(actual->getOfficeMathObject()->getNodeId()->compare(L"0.0.0.0") == 0);
}

/// <summary>
/// Test for getting mathObject online.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjectOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetOfficeMathObjectOnlineRequest> request(new requests::GetOfficeMathObjectOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getOfficeMathObjectOnline(request);
}

/// <summary>
/// Test for getting mathObject without node path.
/// </summary>
TEST_F(MathObjectTests, TestGetOfficeMathObjectWithoutNodePath) {
    std::wstring remoteFileName = L"TestGetOfficeMathObjectWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetOfficeMathObjectRequest> request(new requests::GetOfficeMathObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getOfficeMathObject(request);
    ASSERT_TRUE(actual->getOfficeMathObject() != nullptr);
    ASSERT_TRUE(actual->getOfficeMathObject()->getNodeId()->compare(L"0.0.0.0") == 0);
}

/// <summary>
/// Test for rendering mathObject.
/// </summary>
TEST_F(MathObjectTests, TestRenderMathObject) {
    std::wstring remoteFileName = L"TestRenderMathObject.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderMathObjectRequest> request(new requests::RenderMathObjectRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderMathObject(request);
}

/// <summary>
/// Test for rendering mathObject.
/// </summary>
TEST_F(MathObjectTests, TestRenderMathObjectOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::RenderMathObjectOnlineRequest> request(new requests::RenderMathObjectOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"png"),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->renderMathObjectOnline(request);
}

/// <summary>
/// Test for rendering mathObject without node path.
/// </summary>
TEST_F(MathObjectTests, TestRenderMathObjectWithoutNodePath) {
    std::wstring remoteFileName = L"TestRenderMathObjectWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::RenderMathObjectRequest> request(new requests::RenderMathObjectRequest(
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

    auto actual = getApi()->renderMathObject(request);
}

/// <summary>
/// Test for deleting mathObject.
/// </summary>
TEST_F(MathObjectTests, TestDeleteOfficeMathObject) {
    std::wstring remoteFileName = L"TestDeleteOfficeMathObject.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteOfficeMathObjectRequest> request(new requests::DeleteOfficeMathObjectRequest(
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

getApi()->deleteOfficeMathObject(request);
}

/// <summary>
/// Test for deleting mathObject online.
/// </summary>
TEST_F(MathObjectTests, TestDeleteOfficeMathObjectOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteOfficeMathObjectOnlineRequest> request(new requests::DeleteOfficeMathObjectOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(L""),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteOfficeMathObjectOnline(request);
}

/// <summary>
/// Test for deleting mathObject without node path.
/// </summary>
TEST_F(MathObjectTests, TestDeleteOfficeMathObjectWithoutNodePath) {
    std::wstring remoteFileName = L"TestDeleteOfficeMathObjectWithoutNodePath.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteOfficeMathObjectRequest> request(new requests::DeleteOfficeMathObjectRequest(
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

getApi()->deleteOfficeMathObject(request);
}
