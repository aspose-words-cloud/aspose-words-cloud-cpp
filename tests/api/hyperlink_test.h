/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="hyperlink_test.h">
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
/// Example of how to work with hyperlinks.
/// </summary>
class HyperlinkTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentElements/Hyperlink";
    std::wstring localFile = L"Common/test_doc.docx";

};

/// <summary>
/// Test for getting hyperlink by specified index.
/// </summary>
TEST_F(HyperlinkTests, TestGetDocumentHyperlinkByIndex) {
    std::wstring remoteFileName = L"TestGetDocumentHyperlinkByIndex.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentHyperlinkByIndexRequest> request(new requests::GetDocumentHyperlinkByIndexRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< int32_t >(0),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentHyperlinkByIndex(request);
    ASSERT_TRUE(actual->getHyperlink() != nullptr);
    ASSERT_TRUE(actual->getHyperlink()->getDisplayText()->compare(L"Aspose") == 0);
}

/// <summary>
/// Test for getting hyperlink by specified index online.
/// </summary>
TEST_F(HyperlinkTests, TestGetDocumentHyperlinkByIndexOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetDocumentHyperlinkByIndexOnlineRequest> request(new requests::GetDocumentHyperlinkByIndexOnlineRequest(
        requestDocument,
        std::make_shared< int32_t >(0),
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentHyperlinkByIndexOnline(request);
}

/// <summary>
/// Test for getting hyperlinks.
/// </summary>
TEST_F(HyperlinkTests, TestGetDocumentHyperlinks) {
    std::wstring remoteFileName = L"TestGetDocumentHyperlinks.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentHyperlinksRequest> request(new requests::GetDocumentHyperlinksRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentHyperlinks(request);
    ASSERT_TRUE(actual->getHyperlinks() != nullptr);
    ASSERT_TRUE(actual->getHyperlinks()->getHyperlinkList() != nullptr);
    ASSERT_EQ(2, actual->getHyperlinks()->getHyperlinkList()->size());
    ASSERT_TRUE(actual->getHyperlinks()->getHyperlinkList()->at(0)->getDisplayText()->compare(L"Aspose") == 0);
}

/// <summary>
/// Test for getting hyperlinks online.
/// </summary>
TEST_F(HyperlinkTests, TestGetDocumentHyperlinksOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    std::shared_ptr<requests::GetDocumentHyperlinksOnlineRequest> request(new requests::GetDocumentHyperlinksOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentHyperlinksOnline(request);
}
