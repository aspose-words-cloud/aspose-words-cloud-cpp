/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="document_properties_test.h">
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
/// Example of how to get document properties.
/// </summary>
class DocumentPropertiesTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/DocumentProperties";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for getting document properties.
/// </summary>
TEST_F(DocumentPropertiesTests, TestGetDocumentProperties) {
    std::wstring remoteFileName = L"TestGetDocumentProperties.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentPropertiesRequest> request(new requests::GetDocumentPropertiesRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentProperties(request);
    ASSERT_TRUE(actual->getDocumentProperties() != nullptr);
    ASSERT_TRUE(actual->getDocumentProperties()->getList() != nullptr);
    ASSERT_EQ(24, actual->getDocumentProperties()->getList()->size());
    ASSERT_TRUE(actual->getDocumentProperties()->getList()->at(0) != nullptr);
    ASSERT_TRUE(actual->getDocumentProperties()->getList()->at(0)->getName()->compare(L"Author") == 0);
    ASSERT_TRUE(actual->getDocumentProperties()->getList()->at(0)->getValue()->compare(L"") == 0);
}

/// <summary>
/// Test for getting document properties online.
/// </summary>
TEST_F(DocumentPropertiesTests, TestGetDocumentPropertiesOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    std::shared_ptr<requests::GetDocumentPropertiesOnlineRequest> request(new requests::GetDocumentPropertiesOnlineRequest(
        documentStream,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentPropertiesOnline(request);
}

/// <summary>
/// A test for GetDocumentProperty.
/// </summary>
TEST_F(DocumentPropertiesTests, TestGetDocumentProperty) {
    std::wstring remoteFileName = L"TestGetDocumentProperty.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentPropertyRequest> request(new requests::GetDocumentPropertyRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"Author"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentProperty(request);
    ASSERT_TRUE(actual->getDocumentProperty() != nullptr);
    ASSERT_TRUE(actual->getDocumentProperty()->getName()->compare(L"Author") == 0);
    ASSERT_TRUE(actual->getDocumentProperty()->getValue()->compare(L"") == 0);
}

/// <summary>
/// A test for GetDocumentProperty online.
/// </summary>
TEST_F(DocumentPropertiesTests, TestGetDocumentPropertyOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    std::shared_ptr<requests::GetDocumentPropertyOnlineRequest> request(new requests::GetDocumentPropertyOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"Author"),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentPropertyOnline(request);
}

/// <summary>
/// Test for deleting document property.
/// </summary>
TEST_F(DocumentPropertiesTests, TestDeleteDocumentProperty) {
    std::wstring remoteFileName = L"TestDeleteDocumentProperty.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteDocumentPropertyRequest> request(new requests::DeleteDocumentPropertyRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"testProp"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

getApi()->deleteDocumentProperty(request);
}

/// <summary>
/// Test for deleting document property online.
/// </summary>
TEST_F(DocumentPropertiesTests, TestDeleteDocumentPropertyOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    std::shared_ptr<requests::DeleteDocumentPropertyOnlineRequest> request(new requests::DeleteDocumentPropertyOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"testProp"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteDocumentPropertyOnline(request);
}

/// <summary>
/// Test for updating document property.
/// </summary>
TEST_F(DocumentPropertiesTests, TestUpdateDocumentProperty) {
    std::wstring remoteFileName = L"TestUpdateDocumentProperty.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestProperty = std::make_shared< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate >();
    requestProperty->setValue(std::make_shared< std::wstring >(L"Imran Anwar"));

    std::shared_ptr<requests::CreateOrUpdateDocumentPropertyRequest> request(new requests::CreateOrUpdateDocumentPropertyRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"AsposeAuthor"),
        requestProperty,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->createOrUpdateDocumentProperty(request);
    ASSERT_TRUE(actual->getDocumentProperty() != nullptr);
    ASSERT_TRUE(actual->getDocumentProperty()->getName()->compare(L"AsposeAuthor") == 0);
    ASSERT_TRUE(actual->getDocumentProperty()->getValue()->compare(L"Imran Anwar") == 0);
}

/// <summary>
/// Test for updating document property online.
/// </summary>
TEST_F(DocumentPropertiesTests, TestUpdateDocumentPropertyOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    auto requestProperty = std::make_shared< aspose::words::cloud::models::DocumentPropertyCreateOrUpdate >();
    requestProperty->setValue(std::make_shared< std::wstring >(L"Imran Anwar"));

    std::shared_ptr<requests::CreateOrUpdateDocumentPropertyOnlineRequest> request(new requests::CreateOrUpdateDocumentPropertyOnlineRequest(
        documentStream,
        std::make_shared< std::wstring >(L"AsposeAuthor"),
        requestProperty,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->createOrUpdateDocumentPropertyOnline(request);
}
