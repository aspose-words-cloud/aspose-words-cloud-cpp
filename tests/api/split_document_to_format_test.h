/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="split_document_to_format_test.h">
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
/// Example of how to split document and return result with specified format and page range.
/// </summary>
class SplitDocumentToFormatTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/SplitDocument";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for document splitting.
/// </summary>
TEST_F(SplitDocumentToFormatTests, TestSplitDocument) {
    std::wstring remoteFileName = L"TestSplitDocument.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::SplitDocumentRequest> request(new requests::SplitDocumentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(L"text"),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/TestSplitDocument.text"),
        std::make_shared< int32_t >(1),
        std::make_shared< int32_t >(2),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->splitDocument(request);
    ASSERT_TRUE(actual->getSplitResult() != nullptr);
    ASSERT_TRUE(actual->getSplitResult()->getPages() != nullptr);
    ASSERT_EQ(2, actual->getSplitResult()->getPages()->size());
}

/// <summary>
/// Test for document splitting online.
/// </summary>
TEST_F(SplitDocumentToFormatTests, TestSplitDocumentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::SplitDocumentOnlineRequest> request(new requests::SplitDocumentOnlineRequest(
        requestDocument,
        std::make_shared< std::wstring >(L"text"),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/TestSplitDocument.text"),
        std::make_shared< int32_t >(1),
        std::make_shared< int32_t >(2),
        nullptr,
        nullptr
    ));

    auto actual = getApi()->splitDocumentOnline(request);
}
