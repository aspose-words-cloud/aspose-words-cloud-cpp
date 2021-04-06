/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="document_statistics_test.h">
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
/// Example of how to get document statistics.
/// </summary>
class DocumentStatisticsTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/Statistics";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for document classification.
/// </summary>
TEST_F(DocumentStatisticsTests, TestGetDocumentStatistics) {
    std::wstring remoteFileName = L"TestGetDocumentStatistics.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::GetDocumentStatisticsRequest> request(new requests::GetDocumentStatisticsRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentStatistics(request);
    ASSERT_TRUE(actual->getStatData() != nullptr);
    ASSERT_EQ(10, *(actual->getStatData()->getWordCount()));
}

/// <summary>
/// Test for document classification online.
/// </summary>
TEST_F(DocumentStatisticsTests, TestGetDocumentStatisticsOnline) {
    auto documentStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(localFile), std::istream::binary));
    std::shared_ptr<requests::GetDocumentStatisticsOnlineRequest> request(new requests::GetDocumentStatisticsOnlineRequest(
        documentStream,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->getDocumentStatisticsOnline(request);
}
