/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="classification_test.h">
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
/// Example of how to classify text.
/// </summary>
class ClassificationTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/Common";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for raw text classification.
/// </summary>
TEST_F(ClassificationTests, TestClassify) {
    std::shared_ptr<requests::ClassifyRequest> request(new requests::ClassifyRequest(
        std::make_shared< std::wstring >(L"Try text classification"),
        std::make_shared< std::wstring >(L"3")
    ));

    auto actual = getApi()->classify(request);
    ASSERT_TRUE(actual->getBestClassName()->compare(L"Science") == 0);
    ASSERT_TRUE(actual->getBestResults() != nullptr);
    ASSERT_EQ(3, actual->getBestResults()->size());
}

/// <summary>
/// Test for document classification.
/// </summary>
TEST_F(ClassificationTests, TestClassifyDocument) {
    std::wstring remoteFileName = L"TestClassifyDocument.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::ClassifyDocumentRequest> request(new requests::ClassifyDocumentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(L"3"),
        nullptr
    ));

    auto actual = getApi()->classifyDocument(request);
    ASSERT_TRUE(actual->getBestClassName()->compare(L"Hobbies_&_Interests") == 0);
    ASSERT_TRUE(actual->getBestResults() != nullptr);
    ASSERT_EQ(3, actual->getBestResults()->size());
}

/// <summary>
/// Test for document classification online.
/// </summary>
TEST_F(ClassificationTests, TestClassifyDocumentOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile).c_str(), std::istream::binary));
    std::shared_ptr<requests::ClassifyDocumentOnlineRequest> request(new requests::ClassifyDocumentOnlineRequest(
        documentStream,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(L"3"),
        nullptr
    ));

    auto actual = getApi()->classifyDocumentOnline(request);
}
