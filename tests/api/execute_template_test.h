/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="execute_template_test.h">
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
/// Example of how to perform template execution.
/// </summary>
class ExecuteTemplateTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/MailMerge";
    std::wstring mailMergeFolder = L"DocumentActions/MailMerge";

};

/// <summary>
/// Test for posting execute template.
/// </summary>
TEST_F(ExecuteTemplateTests, TestExecuteTemplate) {
    std::wstring localDocumentFile = L"TestExecuteTemplate.doc";
    std::wstring remoteFileName = L"TestExecuteTemplate.docx";
    std::wstring localDataFile = getFileTextUtf16(localTestDataFolder + L"/" + mailMergeFolder + L"/TestExecuteTemplateData.txt");

    uploadFileToStorage(
        localTestDataFolder + L"/" + mailMergeFolder + L"/" + localDocumentFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    std::shared_ptr<requests::ExecuteMailMergeRequest> request(new requests::ExecuteMailMergeRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(localDataFile),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        std::make_shared< std::wstring >(baseTestOutPath + L"/" + remoteFileName)
    ));

    auto actual = getApi()->executeMailMerge(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestExecuteTemplate.docx") == 0);
}

/// <summary>
/// Test for execute template online.
/// </summary>
TEST_F(ExecuteTemplateTests, TestExecuteTemplateOnline) {
    std::wstring localDocumentFile = L"SampleMailMergeTemplate.docx";
    std::wstring localDataFile = L"SampleExecuteTemplateData.txt";

    auto requestTemplate = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(mailMergeFolder + L"/" + localDocumentFile)), std::istream::binary));
    auto requestData = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(mailMergeFolder + L"/" + localDataFile)), std::istream::binary));
    std::shared_ptr<requests::ExecuteMailMergeOnlineRequest> request(new requests::ExecuteMailMergeOnlineRequest(
        requestTemplate,
        requestData,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->executeMailMergeOnline(request);
}
