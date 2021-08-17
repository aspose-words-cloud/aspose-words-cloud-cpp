/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="custom_xml_parts_test.h">
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
/// Example of how to use custom xml parts in documents.
/// </summary>
class CustomXmlPartsTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/CustomXmlParts";
    std::wstring localFile = L"DocumentElements/CustomXmlParts/MultipleCustomXmlParts.docx";

};

/// <summary>
/// Test for getting custom xml part by specified index.
/// </summary>
TEST_F(CustomXmlPartsTests, TestGetCustomXmlPart) {
    std::wstring remoteFileName = L"TestGetCustomXmlPart.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetCustomXmlPartRequest> request(new requests::GetCustomXmlPartRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getCustomXmlPart(request);
    ASSERT_TRUE(actual->getCustomXmlPart() != nullptr);
    ASSERT_TRUE(actual->getCustomXmlPart()->getId()->compare(L"aspose") == 0);
    ASSERT_TRUE(actual->getCustomXmlPart()->getData()->compare(L"<Metadata><Author>author1</Author><Initial>initial</Initial><DateTime>2015-01-22T00:00:00</DateTime><Text>text</Text></Metadata>") == 0);
}

/// <summary>
/// Test for getting custom xml part by specified index online.
/// </summary>
TEST_F(CustomXmlPartsTests, TestGetCustomXmlPartOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetCustomXmlPartOnlineRequest> request(new requests::GetCustomXmlPartOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getCustomXmlPartOnline(request);
    ASSERT_TRUE(actual->getCustomXmlPart() != nullptr);
    ASSERT_TRUE(actual->getCustomXmlPart()->getId()->compare(L"aspose") == 0);
    ASSERT_TRUE(actual->getCustomXmlPart()->getData()->compare(L"<Metadata><Author>author1</Author><Initial>initial</Initial><DateTime>2015-01-22T00:00:00</DateTime><Text>text</Text></Metadata>") == 0);
}

/// <summary>
/// Test for getting all custom xml parts from document.
/// </summary>
TEST_F(CustomXmlPartsTests, TestGetCustomXmlParts) {
    std::wstring remoteFileName = L"TestGetCustomXmlParts.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetCustomXmlPartsRequest> request(new requests::GetCustomXmlPartsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getCustomXmlParts(request);
    ASSERT_TRUE(actual->getCustomXmlParts() != nullptr);
    ASSERT_TRUE(actual->getCustomXmlParts()->getCustomXmlPartsList() != nullptr);
    ASSERT_EQ(2, actual->getCustomXmlParts()->getCustomXmlPartsList()->size());
    ASSERT_TRUE(actual->getCustomXmlParts()->getCustomXmlPartsList()->at(0)->getId()->compare(L"aspose") == 0);
    ASSERT_TRUE(actual->getCustomXmlParts()->getCustomXmlPartsList()->at(0)->getData()->compare(L"<Metadata><Author>author1</Author><Initial>initial</Initial><DateTime>2015-01-22T00:00:00</DateTime><Text>text</Text></Metadata>") == 0);
}

/// <summary>
/// Test for getting all custom xml parts from document online.
/// </summary>
TEST_F(CustomXmlPartsTests, TestGetCustomXmlPartsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetCustomXmlPartsOnlineRequest> request(new requests::GetCustomXmlPartsOnlineRequest(
        requestDocument,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getCustomXmlPartsOnline(request);
    ASSERT_TRUE(actual->getCustomXmlParts() != nullptr);
    ASSERT_TRUE(actual->getCustomXmlParts()->getCustomXmlPartsList() != nullptr);
    ASSERT_EQ(2, actual->getCustomXmlParts()->getCustomXmlPartsList()->size());
    ASSERT_TRUE(actual->getCustomXmlParts()->getCustomXmlPartsList()->at(0)->getId()->compare(L"aspose") == 0);
    ASSERT_TRUE(actual->getCustomXmlParts()->getCustomXmlPartsList()->at(0)->getData()->compare(L"<Metadata><Author>author1</Author><Initial>initial</Initial><DateTime>2015-01-22T00:00:00</DateTime><Text>text</Text></Metadata>") == 0);
}

/// <summary>
/// Test for adding custom xml part.
/// </summary>
TEST_F(CustomXmlPartsTests, TestInsertCustomXmlPart) {
    std::wstring remoteFileName = L"TestInsertCustomXmlPart.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartInsert >();
    requestCustomXmlPart->setId(std::make_shared< std::wstring >(L"hello"));
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr<requests::InsertCustomXmlPartRequest> request(new requests::InsertCustomXmlPartRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertCustomXmlPart(request);
    ASSERT_TRUE(actual->getCustomXmlPart() != nullptr);
    ASSERT_TRUE(actual->getCustomXmlPart()->getId()->compare(L"hello") == 0);
    ASSERT_TRUE(actual->getCustomXmlPart()->getData()->compare(L"<data>Hello world</data>") == 0);
}

/// <summary>
/// Test for adding custom xml part online.
/// </summary>
TEST_F(CustomXmlPartsTests, TestInsertCustomXmlPartOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartInsert >();
    requestCustomXmlPart->setId(std::make_shared< std::wstring >(L"hello"));
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr<requests::InsertCustomXmlPartOnlineRequest> request(new requests::InsertCustomXmlPartOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->insertCustomXmlPartOnline(request);
    ASSERT_TRUE(actual->getModel()->getCustomXmlPart() != nullptr);
    ASSERT_TRUE(actual->getModel()->getCustomXmlPart()->getId()->compare(L"hello") == 0);
    ASSERT_TRUE(actual->getModel()->getCustomXmlPart()->getData()->compare(L"<data>Hello world</data>") == 0);
}

/// <summary>
/// Test for updating custom xml part.
/// </summary>
TEST_F(CustomXmlPartsTests, TestUpdateCustomXmlPart) {
    std::wstring remoteFileName = L"TestUpdateCustomXmlPart.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartUpdate >();
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr<requests::UpdateCustomXmlPartRequest> request(new requests::UpdateCustomXmlPartRequest(
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

    auto actual = getApi()->updateCustomXmlPart(request);
    ASSERT_TRUE(actual->getCustomXmlPart() != nullptr);
    ASSERT_TRUE(actual->getCustomXmlPart()->getId()->compare(L"aspose") == 0);
    ASSERT_TRUE(actual->getCustomXmlPart()->getData()->compare(L"<data>Hello world</data>") == 0);
}

/// <summary>
/// Test for updating custom xml part online.
/// </summary>
TEST_F(CustomXmlPartsTests, TestUpdateCustomXmlPartOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestCustomXmlPart = std::make_shared< aspose::words::cloud::models::CustomXmlPartUpdate >();
    requestCustomXmlPart->setData(std::make_shared< std::wstring >(L"<data>Hello world</data>"));
    std::shared_ptr<requests::UpdateCustomXmlPartOnlineRequest> request(new requests::UpdateCustomXmlPartOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->updateCustomXmlPartOnline(request);
    ASSERT_TRUE(actual->getModel()->getCustomXmlPart() != nullptr);
    ASSERT_TRUE(actual->getModel()->getCustomXmlPart()->getId()->compare(L"aspose") == 0);
    ASSERT_TRUE(actual->getModel()->getCustomXmlPart()->getData()->compare(L"<data>Hello world</data>") == 0);
}

/// <summary>
/// A test for DeleteCustomXmlPart.
/// </summary>
TEST_F(CustomXmlPartsTests, TestDeleteCustomXmlPart) {
    std::wstring remoteFileName = L"TestDeleteCustomXmlPart.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteCustomXmlPartRequest> request(new requests::DeleteCustomXmlPartRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

getApi()->deleteCustomXmlPart(request);
}

/// <summary>
/// A test for DeleteCustomXmlPart online.
/// </summary>
TEST_F(CustomXmlPartsTests, TestDeleteCustomXmlPartOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteCustomXmlPartOnlineRequest> request(new requests::DeleteCustomXmlPartOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteCustomXmlPartOnline(request);
}

/// <summary>
/// A test for DeleteCustomXmlParts.
/// </summary>
TEST_F(CustomXmlPartsTests, TestDeleteCustomXmlParts) {
    std::wstring remoteFileName = L"TestDeleteCustomXmlPart.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::DeleteCustomXmlPartsRequest> request(new requests::DeleteCustomXmlPartsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

getApi()->deleteCustomXmlParts(request);
}

/// <summary>
/// A test for DeleteCustomXmlParts online.
/// </summary>
TEST_F(CustomXmlPartsTests, TestDeleteCustomXmlPartsOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::DeleteCustomXmlPartsOnlineRequest> request(new requests::DeleteCustomXmlPartsOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->deleteCustomXmlPartsOnline(request);
}
