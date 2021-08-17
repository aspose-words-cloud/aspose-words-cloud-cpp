/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compatibility_test.h">
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
/// Example of how to work with compatibility options.
/// </summary>
class CompatibilityTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/Compatibility";
    std::wstring localFile = L"Common/test_multi_pages.docx";

};

/// <summary>
/// Test for optimize document to specific MS Word version.
/// </summary>
TEST_F(CompatibilityTests, TestOptimizeDocument) {
    std::wstring remoteFileName = L"TestOptimizeDocument.docx";

    uploadFileToStorage(
        localTestDataFolder + L"/" + localFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestOptions = std::make_shared< aspose::words::cloud::models::OptimizationOptions >();
    requestOptions->setMsWordVersion(std::make_shared< aspose::words::cloud::models::OptimizationOptions::MsWordVersion >(aspose::words::cloud::models::OptimizationOptions::MsWordVersion::WORD2002));
    std::shared_ptr<requests::OptimizeDocumentRequest> request(new requests::OptimizeDocumentRequest(
        std::make_shared< std::wstring >(remoteFileName),
        nullptr,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

getApi()->optimizeDocument(request);
}

/// <summary>
/// Test for optimize document to specific MS Word version.
/// </summary>
TEST_F(CompatibilityTests, TestOptimizeDocumentOnline) {
    auto requestDocument = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(localFile)), std::istream::binary));
    auto requestOptions = std::make_shared< aspose::words::cloud::models::OptimizationOptions >();
    requestOptions->setMsWordVersion(std::make_shared< aspose::words::cloud::models::OptimizationOptions::MsWordVersion >(aspose::words::cloud::models::OptimizationOptions::MsWordVersion::WORD2002));
    std::shared_ptr<requests::OptimizeDocumentOnlineRequest> request(new requests::OptimizeDocumentOnlineRequest(
        requestDocument,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->optimizeDocumentOnline(request);
}
