/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="convert_document_test.h">
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
/// Example of how to convert document to one of the available formats.
/// </summary>
class ConvertDocumentTests : public InfrastructureTest {
protected:
    std::wstring remoteFolder = remoteBaseTestDataFolder + L"/DocumentActions/ConvertDocument";
    std::wstring localFolder = L"DocumentActions/ConvertDocument";

};

/// <summary>
/// Test for converting document to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAs) {
    std::wstring localName = L"test_multi_pages.docx";
    std::wstring remoteName = L"TestSaveAs.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localName,
        remoteFolder + L"/" + remoteName
    );

    auto requestSaveOptionsData = std::make_shared< aspose::words::cloud::models::PdfSaveOptionsData >();
    requestSaveOptionsData->setFileName(std::make_shared< std::wstring >(baseTestOutPath + L"/TestSaveAs.pdf"));
    std::shared_ptr<requests::SaveAsRequest> request(new requests::SaveAsRequest(
        std::make_shared< std::wstring >(remoteName),
        requestSaveOptionsData,
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->saveAs(request);
    ASSERT_TRUE(actual->getSaveResult() != nullptr);
    ASSERT_TRUE(actual->getSaveResult()->getDestDocument() != nullptr);
}

/// <summary>
/// Test for converting document online to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAsOnline) {
    std::wstring localName = L"test_multi_pages.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/" + localName)), std::istream::binary));
    auto requestSaveOptionsData = std::make_shared< aspose::words::cloud::models::PdfSaveOptionsData >();
    requestSaveOptionsData->setFileName(std::make_shared< std::wstring >(baseTestOutPath + L"/TestSaveAs.pdf"));
    std::shared_ptr<requests::SaveAsOnlineRequest> request(new requests::SaveAsOnlineRequest(
        requestDocument,
        requestSaveOptionsData,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->saveAsOnline(request);
}

/// <summary>
/// Test for converting document to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAsDocx) {
    std::wstring localName = L"45.pdf";
    std::wstring remoteName = L"TestSaveAsFromPdfToDoc.pdf";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFolder + L"/" + localName,
        remoteFolder + L"/" + remoteName
    );

    auto requestSaveOptionsData = std::make_shared< aspose::words::cloud::models::DocxSaveOptionsData >();
    requestSaveOptionsData->setFileName(std::make_shared< std::wstring >(baseTestOutPath + L"/TestSaveAsFromPdfToDoc.docx"));
    std::shared_ptr<requests::SaveAsRequest> request(new requests::SaveAsRequest(
        std::make_shared< std::wstring >(remoteName),
        requestSaveOptionsData,
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->saveAs(request);
    ASSERT_TRUE(actual->getSaveResult() != nullptr);
    ASSERT_TRUE(actual->getSaveResult()->getDestDocument() != nullptr);
}

/// <summary>
/// Test for converting document to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAsTiff) {
    std::wstring localName = L"test_multi_pages.docx";
    std::wstring remoteName = L"TestSaveAsTiff.pdf";

    uploadFileToStorage(
        localTestDataFolder + L"/" + L"Common/" + localName,
        remoteFolder + L"/" + remoteName
    );

    auto requestSaveOptions = std::make_shared< aspose::words::cloud::models::TiffSaveOptionsData >();
    requestSaveOptions->setFileName(std::make_shared< std::wstring >(baseTestOutPath + L"/abc.tiff"));
    std::shared_ptr<requests::SaveAsTiffRequest> request(new requests::SaveAsTiffRequest(
        std::make_shared< std::wstring >(remoteName),
        requestSaveOptions,
        std::make_shared< std::wstring >(remoteFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->saveAsTiff(request);
    ASSERT_TRUE(actual->getSaveResult() != nullptr);
    ASSERT_TRUE(actual->getSaveResult()->getDestDocument() != nullptr);
}

/// <summary>
/// Test for converting document to one of the available formats.
/// </summary>
TEST_F(ConvertDocumentTests, TestSaveAsTiffOnline) {
    std::wstring localName = L"test_multi_pages.docx";

    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(L"Common/" + localName)), std::istream::binary));
    auto requestSaveOptions = std::make_shared< aspose::words::cloud::models::TiffSaveOptionsData >();
    requestSaveOptions->setFileName(std::make_shared< std::wstring >(baseTestOutPath + L"/abc.tiff"));
    std::shared_ptr<requests::SaveAsTiffOnlineRequest> request(new requests::SaveAsTiffOnlineRequest(
        requestDocument,
        requestSaveOptions,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->saveAsTiffOnline(request);
}

/// <summary>
/// A test for ConvertDocument.
/// </summary>
TEST_F(ConvertDocumentTests, TestConvertDocument) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFolder + L"/test_uploadfile.docx")), std::istream::binary));
    std::shared_ptr<requests::ConvertDocumentRequest> request(new requests::ConvertDocumentRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"pdf"),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->convertDocument(request);
}
