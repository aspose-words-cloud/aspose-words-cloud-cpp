/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="document_protection_test.h">
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
/// Example of how to set document protection.
/// </summary>
class DocumentProtectionTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/DocumentProtection";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for setting document protection.
/// </summary>
TEST_F(DocumentProtectionTests, TestProtectDocument) {
    std::wstring remoteFileName = L"TestProtectDocument.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"123"));
    requestProtectionRequest->setProtectionType(std::make_shared< std::wstring >(L"ReadOnly"));
    std::shared_ptr<requests::ProtectDocumentRequest> request(new requests::ProtectDocumentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestProtectionRequest,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName)
    ));

    auto actual = getApi()->protectDocument(request);
    ASSERT_TRUE(actual->getProtectionData() != nullptr);
    ASSERT_TRUE(actual->getProtectionData()->getProtectionType()->compare(L"ReadOnly") == 0);
}

/// <summary>
/// Test for setting document protection.
/// </summary>
TEST_F(DocumentProtectionTests, TestProtectDocumentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setNewPassword(std::make_shared< std::wstring >(L"123"));
    std::shared_ptr<requests::ProtectDocumentOnlineRequest> request(new requests::ProtectDocumentOnlineRequest(
        requestDocument,
        requestProtectionRequest,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->protectDocumentOnline(request);
}

/// <summary>
/// Test for getting document protection.
/// </summary>
TEST_F(DocumentProtectionTests, TestGetDocumentProtection) {
    std::wstring localFilePath = L"DocumentActions/DocumentProtection/SampleProtectedBlankWordDocument.docx";
    std::wstring remoteFileName = L"TestGetDocumentProtection.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFilePath,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentProtectionRequest> request(new requests::GetDocumentProtectionRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentProtection(request);
}

/// <summary>
/// Test for getting document protection.
/// </summary>
TEST_F(DocumentProtectionTests, TestGetDocumentProtectionOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetDocumentProtectionOnlineRequest> request(new requests::GetDocumentProtectionOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentProtectionOnline(request);
}

/// <summary>
/// Test for deleting unprotect document.
/// </summary>
TEST_F(DocumentProtectionTests, TestDeleteUnprotectDocument) {
    std::wstring localFilePath = L"DocumentActions/DocumentProtection/SampleProtectedBlankWordDocument.docx";
    std::wstring remoteFileName = L"TestDeleteUnprotectDocument.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFilePath,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"aspose"));
    std::shared_ptr<requests::UnprotectDocumentRequest> request(new requests::UnprotectDocumentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestProtectionRequest,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->unprotectDocument(request);
    ASSERT_TRUE(actual->getProtectionData() != nullptr);
    ASSERT_TRUE(actual->getProtectionData()->getProtectionType()->compare(L"NoProtection") == 0);
}

/// <summary>
/// Test for deleting unprotect document.
/// </summary>
TEST_F(DocumentProtectionTests, TestDeleteUnprotectDocumentOnline) {
    std::wstring localFilePath = L"DocumentActions/DocumentProtection/SampleProtectedBlankWordDocument.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFilePath)), std::istream::binary));
    auto requestProtectionRequest = std::make_shared< aspose::words::cloud::models::ProtectionRequest >();
    requestProtectionRequest->setPassword(std::make_shared< std::wstring >(L"aspose"));
    std::shared_ptr<requests::UnprotectDocumentOnlineRequest> request(new requests::UnprotectDocumentOnlineRequest(
        requestDocument,
        requestProtectionRequest,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->unprotectDocumentOnline(request);
}
