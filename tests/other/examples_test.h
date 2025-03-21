﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="examples_test.h">
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
#include "aspose_words_cloud.h"
using namespace aspose::words::cloud;
#include "../test_base.h"

class ExamplesTest : public InfrastructureTest {
protected:
    std::wstring localTestExamplesFolder = getSdkRoot() + L"/examples_data";
};

TEST_F(ExamplesTest, TestExampleAcceptAllRevisions) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    std::wstring fileName = L"test_doc.docx";

    // Upload original document to cloud storage.
    auto myVar1 = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + fileName), std::istream::binary));
    auto myVar2 = std::make_shared< std::wstring >(fileName);
    std::shared_ptr< requests::UploadFileRequest > uploadFileRequest(
        new requests::UploadFileRequest(
            myVar1, myVar2
        )
    );
    wordsApi->uploadFile(uploadFileRequest);

    // Calls AcceptAllRevisions method for document in cloud.
    auto myVar3 = std::make_shared< std::wstring >(fileName);
    std::shared_ptr< requests::AcceptAllRevisionsRequest > request(
        new requests::AcceptAllRevisionsRequest(
            myVar3
        )
    );
    wordsApi->acceptAllRevisions(request);
}

TEST_F(ExamplesTest, TestExampleAcceptAllRevisionsOnline) {
    std::wstring documentsDir = localTestExamplesFolder;
    auto wordsApi = getApi();
    uploadFileToStorage(documentsDir + L"/test_doc.docx", L"test_doc.docx");
    std::wstring fileName = L"test_doc.docx";

    // Calls AcceptAllRevisionsOnline method for document in cloud.
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + fileName), std::istream::binary));
    std::shared_ptr< requests::AcceptAllRevisionsOnlineRequest > request(
        new requests::AcceptAllRevisionsOnlineRequest(
            requestDocument
        )
    );
    auto acceptAllRevisionsOnlineResult = wordsApi->acceptAllRevisionsOnline(request);
    {
        char buffer[1024];
        std::ofstream fileWriter("test_result.docx", std::ofstream::binary);
        const auto& fileData = *acceptAllRevisionsOnlineResult->getDocument()->begin();
        while(fileData.second->read(buffer, sizeof(buffer))) {
            fileWriter.write(buffer, sizeof(buffer));
        }
        fileWriter.write(buffer, fileData.second->gcount());
        fileWriter.close();
    }
}