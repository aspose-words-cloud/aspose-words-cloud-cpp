/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="documentProtectionTests.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "../TestBase.h"

/// <summary>
/// Example of how to set document protection.
/// </summary>
class DocumentProtectionTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentElements/DocumentProtection");
    utility::string_t localFile = STCONVERT("Common/test_multi_pages.docx");

};

/// <summary>
/// Test for setting document protection.
/// </summary>
TEST_F(DocumentProtectionTests, TestProtectDocument) {
    utility::string_t remoteFileName = STCONVERT("TestProtectDocument.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestProtectionRequest = std::make_shared< ProtectionRequest >();
    requestProtectionRequest->setNewPassword(STCONVERT("123"));

    std::shared_ptr< ProtectDocumentRequest > request(new ProtectDocumentRequest(
        remoteFileName,
        requestProtectionRequest,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        baseTestOutPath + STCONVERT("/") + remoteFileName
    ));

   auto actual = get_api()->protectDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting document protection.
/// </summary>
TEST_F(DocumentProtectionTests, TestGetDocumentProtection) {
    utility::string_t remoteFileName = STCONVERT("TestGetDocumentProtection.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    std::shared_ptr< GetDocumentProtectionRequest > request(new GetDocumentProtectionRequest(
        remoteFileName,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->getDocumentProtection(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for changing document protection.
/// </summary>
TEST_F(DocumentProtectionTests, TestChangeDocumentProtection) {
    utility::string_t remoteFileName = STCONVERT("TestChangeDocumentProtection.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFile)
    );

    auto requestProtectionRequest = std::make_shared< ProtectionRequest >();
    requestProtectionRequest->setNewPassword(STCONVERT("321"));

    std::shared_ptr< ProtectDocumentRequest > request(new ProtectDocumentRequest(
        remoteFileName,
        requestProtectionRequest,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->protectDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting unprotect document.
/// </summary>
TEST_F(DocumentProtectionTests, TestDeleteUnprotectDocument) {
    utility::string_t localFilePath = STCONVERT("DocumentActions/DocumentProtection/SampleProtectedBlankWordDocument.docx");
    utility::string_t remoteFileName = STCONVERT("TestDeleteUnprotectDocument.docx");

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, localFilePath)
    );

    auto requestProtectionRequest = std::make_shared< ProtectionRequest >();
    requestProtectionRequest->setPassword(STCONVERT("aspose"));

    std::shared_ptr< UnprotectDocumentRequest > request(new UnprotectDocumentRequest(
        remoteFileName,
        requestProtectionRequest,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->unprotectDocument(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
}
