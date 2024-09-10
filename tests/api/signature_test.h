/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="signature_test.h">
*   Copyright (c) 2024 Aspose.Words for Cloud
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
/// Example of how to work with signatures.
/// </summary>
class SignatureTests : public InfrastructureTest {
protected:
    std::wstring remoteFolder = remoteBaseTestDataFolder + L"/DocumentActions/Signature";
    std::wstring localFolder = L"DocumentActions/Signature";
    std::wstring signedDocument = L"signedDocument.docx";
    std::wstring unsignedDocument = L"unsignedDocument.docx";
    std::wstring certificateName = L"morzal.pfx";
    std::wstring certificatePassword = L"aw";

};

/// <summary>
/// Test for getting all document signatures.
/// </summary>
TEST_F(SignatureTests, TestGetSignatures) {
    std::wstring remoteName = L"TestGetSignatures.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + signedDocument,
        remoteFolder + L"/" + remoteName
    );

    std::shared_ptr<requests::GetSignaturesRequest> request(new requests::GetSignaturesRequest(
        std::make_shared< std::wstring >(remoteName),
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSignatures(request);
    ASSERT_TRUE(actual->getSignatures() != nullptr);
    ASSERT_EQ(1, actual->getSignatures()->size());
}

/// <summary>
/// Test for getting all document signatures online.
/// </summary>
TEST_F(SignatureTests, TestGetSignaturesOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFolder + L"/" + signedDocument)), std::istream::binary));
    std::shared_ptr<requests::GetSignaturesOnlineRequest> request(new requests::GetSignaturesOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getSignaturesOnline(request);
    ASSERT_TRUE(actual->getSignatures() != nullptr);
    ASSERT_EQ(1, actual->getSignatures()->size());
}

/// <summary>
/// Test for removing all document signatures.
/// </summary>
TEST_F(SignatureTests, TestRemoveAllSignatures) {
    std::wstring remoteName = L"TestRemoveAllSignatures.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + signedDocument,
        remoteFolder + L"/" + remoteName
    );

    std::shared_ptr<requests::RemoveAllSignaturesRequest> request(new requests::RemoveAllSignaturesRequest(
        std::make_shared< std::wstring >(remoteName),
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->removeAllSignatures(request);
    ASSERT_TRUE(actual->getSignatures() != nullptr);
    ASSERT_EQ(0, actual->getSignatures()->size());
}

/// <summary>
/// Test for removing all document signatures online.
/// </summary>
TEST_F(SignatureTests, TestRemoveAllSignaturesOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFolder + L"/" + signedDocument)), std::istream::binary));
    std::shared_ptr<requests::RemoveAllSignaturesOnlineRequest> request(new requests::RemoveAllSignaturesOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->removeAllSignaturesOnline(request);
    ASSERT_TRUE(actual->getModel()->getSignatures() != nullptr);
    ASSERT_EQ(0, actual->getModel()->getSignatures()->size());
}

/// <summary>
/// Test for signing document.
/// </summary>
TEST_F(SignatureTests, TestSignDocument) {
    std::wstring remoteName = L"TestSignDocument.docx";
    std::wstring remoteCertificateName = L"TestCertificate.pfx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + unsignedDocument,
        remoteFolder + L"/" + remoteName
    );
    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + certificateName,
        remoteFolder + L"/" + remoteCertificateName
    );

    std::shared_ptr<requests::SignDocumentRequest> request(new requests::SignDocumentRequest(
        std::make_shared< std::wstring >(remoteName),
        std::make_shared< std::wstring >(remoteFolder + L"/" + remoteCertificateName),
        std::make_shared< std::wstring >(certificatePassword),
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->signDocument(request);
    ASSERT_TRUE(actual->getSignatures() != nullptr);
    ASSERT_EQ(1, actual->getSignatures()->size());
}

/// <summary>
/// Test for signing document online.
/// </summary>
TEST_F(SignatureTests, TestSignDocumentOnline) {
    std::wstring remoteCertificateName = L"TestCertificateOnline.pfx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + certificateName,
        remoteFolder + L"/" + remoteCertificateName
    );

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFolder + L"/" + unsignedDocument)), std::istream::binary));
    std::shared_ptr<requests::SignDocumentOnlineRequest> request(new requests::SignDocumentOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(remoteFolder + L"/" + remoteCertificateName),
        std::make_shared< std::wstring >(certificatePassword),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->signDocumentOnline(request);
    ASSERT_TRUE(actual->getModel()->getSignatures() != nullptr);
    ASSERT_EQ(1, actual->getModel()->getSignatures()->size());
}
