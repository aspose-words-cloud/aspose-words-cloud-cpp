/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compress_document_test.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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
/// Example of how to compress document for reduce document size.
/// </summary>
class CompressDocumentTests : public InfrastructureTest {
protected:
    std::wstring remoteFolder = remoteBaseTestDataFolder + L"/DocumentActions/CompressDocument";
    std::wstring localFolder = L"DocumentActions/CompressDocument";

};

/// <summary>
/// Test for compression document.
/// </summary>
TEST_F(CompressDocumentTests, TestCompressDocument) {
    std::wstring localName = L"TestCompress.docx";
    std::wstring remoteName = L"TestCompress.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + localName,
        remoteFolder + L"/" + remoteName
    );

    auto requestCompressOptions = std::make_shared< aspose::words::cloud::models::CompressOptions >();

    std::shared_ptr<requests::CompressDocumentRequest> request(new requests::CompressDocumentRequest(
        std::make_shared< std::wstring >(remoteName),
        requestCompressOptions,
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->compressDocument(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
}

/// <summary>
/// Test for compression document online.
/// </summary>
TEST_F(CompressDocumentTests, TestCompressDocumentOnline) {
    std::wstring localName = L"TestCompress.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFolder + L"/" + localName)), std::istream::binary));
    auto requestCompressOptions = std::make_shared< aspose::words::cloud::models::CompressOptions >();

    std::shared_ptr<requests::CompressDocumentOnlineRequest> request(new requests::CompressDocumentOnlineRequest(
        requestDocument,
        requestCompressOptions,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->compressDocumentOnline(request);
}
