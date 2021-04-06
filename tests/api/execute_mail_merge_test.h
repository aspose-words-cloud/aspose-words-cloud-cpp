/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="execute_mail_merge_test.h">
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
/// Example of how to perform mail merge.
/// </summary>
class ExecuteMailMergeTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/MailMerge";
    std::wstring mailMergeFolder = L"DocumentActions/MailMerge";

};

/// <summary>
/// Test for executing mail merge online.
/// </summary>
TEST_F(ExecuteMailMergeTests, TestExecuteMailMergeOnline) {
    std::wstring localDocumentFile = L"SampleExecuteTemplate.docx";
    std::wstring localDataFile = L"SampleExecuteTemplateData.txt";

    auto templateStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(mailMergeFolder + L"/" + localDocumentFile).c_str(), std::istream::binary));
    auto dataStream = std::shared_ptr<std::istream>(new std::ifstream(getDataDir(mailMergeFolder + L"/" + localDataFile).c_str(), std::istream::binary));
    std::shared_ptr<requests::ExecuteMailMergeOnlineRequest> request(new requests::ExecuteMailMergeOnlineRequest(
        templateStream,
        dataStream,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->executeMailMergeOnline(request);
}

/// <summary>
/// Test for executing mail merge.
/// </summary>
TEST_F(ExecuteMailMergeTests, TestExecuteMailMerge) {
    std::wstring localDocumentFile = L"SampleExecuteTemplate.docx";
    std::wstring remoteFileName = L"TestExecuteMailMerge.docx";
    std::wstring localDataFile = getFileTextUtf16(localTestDataFolder + L"/" + mailMergeFolder + L"/SampleMailMergeTemplateData.txt");

    uploadFileToStorage(
        localTestDataFolder + L"/" + mailMergeFolder + L"/" + localDocumentFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::ExecuteMailMergeRequest> request(new requests::ExecuteMailMergeRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(localDataFile),
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< bool >(false),
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName)
    ));

    auto actual = getApi()->executeMailMerge(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestExecuteMailMerge.docx") == 0);
}
