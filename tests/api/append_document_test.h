/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="append_document_test.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
/// Example of how to append document.
/// </summary>
class AppendDocumentTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/AppendDocument";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for appending document.
/// </summary>
TEST_F(AppendDocumentTests, TestAppendDocument) {
    std::wstring remoteFileName = L"TestAppendDocument.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestDocumentListDocumentEntries0FileReference = std::make_shared< aspose::words::cloud::models::FileReference >(std::make_shared< std::wstring >(remoteDataFolder + L"/" + remoteFileName));
    auto requestDocumentListDocumentEntries0 = std::make_shared< aspose::words::cloud::models::DocumentEntry >();
    requestDocumentListDocumentEntries0->setFileReference(requestDocumentListDocumentEntries0FileReference);
    requestDocumentListDocumentEntries0->setImportFormatMode(std::make_shared< aspose::words::cloud::models::DocumentEntry::ImportFormatMode >(aspose::words::cloud::models::DocumentEntry::ImportFormatMode::KEEP_SOURCE_FORMATTING));
    auto requestDocumentListDocumentEntries = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::DocumentEntry>> >();
    requestDocumentListDocumentEntries->push_back(requestDocumentListDocumentEntries0);
    auto requestDocumentList = std::make_shared< aspose::words::cloud::models::DocumentEntryList >();
    requestDocumentList->setDocumentEntries(requestDocumentListDocumentEntries);
    std::shared_ptr<requests::AppendDocumentRequest> request(new requests::AppendDocumentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        requestDocumentList,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->appendDocument(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestAppendDocument.docx") == 0);
}

/// <summary>
/// Test for appending document online.
/// </summary>
TEST_F(AppendDocumentTests, TestAppendDocumentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestDocumentListDocumentEntries0FileReferenceStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestDocumentListDocumentEntries0FileReference = std::make_shared< aspose::words::cloud::models::FileReference >(requestDocumentListDocumentEntries0FileReferenceStream);
    auto requestDocumentListDocumentEntries0 = std::make_shared< aspose::words::cloud::models::DocumentEntry >();
    requestDocumentListDocumentEntries0->setFileReference(requestDocumentListDocumentEntries0FileReference);
    requestDocumentListDocumentEntries0->setImportFormatMode(std::make_shared< aspose::words::cloud::models::DocumentEntry::ImportFormatMode >(aspose::words::cloud::models::DocumentEntry::ImportFormatMode::KEEP_SOURCE_FORMATTING));
    auto requestDocumentListDocumentEntries = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::DocumentEntry>> >();
    requestDocumentListDocumentEntries->push_back(requestDocumentListDocumentEntries0);
    auto requestDocumentList = std::make_shared< aspose::words::cloud::models::DocumentEntryList >();
    requestDocumentList->setDocumentEntries(requestDocumentListDocumentEntries);
    std::shared_ptr<requests::AppendDocumentOnlineRequest> request(new requests::AppendDocumentOnlineRequest(
        requestDocument,
        requestDocumentList,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->appendDocumentOnline(request);
}
