/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="documentProtectionTest.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
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
#include "TestBase.h"

class DocumentProtectionTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\DocumentProtection")),
		protectionFolder = STCONVERT("DocumentActions/DocumentProtection");
};

/// <summary>
/// Test for setting document protection
/// </summary>
TEST_F(DocumentProtectionTest, TestPutProtectDocument) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutProtectDocument.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ProtectionRequest> body = std::make_shared<ProtectionRequest>();
	body->setNewPassword(STCONVERT("123"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ProtectDocumentRequest> request=
			std::make_shared<ProtectDocumentRequest>(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, destFileName);

	AsposeResponse<ProtectionDataResponse> actual = get_api()->protectDocument(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting document protection
/// </summary>
TEST_F(DocumentProtectionTest, TestGetDocumentProtection) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentProtection.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentProtectionRequest> request=
			std::make_shared<GetDocumentProtectionRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<ProtectionDataResponse> actual = get_api()->getDocumentProtection(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for changing document protection
/// </summary>
TEST_F(DocumentProtectionTest, TestPostChangeDocumentProtection) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostChangeDocumentProtection.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ProtectionRequest> body = std::make_shared<ProtectionRequest>();
	body->setNewPassword(STCONVERT(""));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ProtectDocumentRequest> request=
			std::make_shared<ProtectDocumentRequest>(remoteName, body, dataFolder,
					boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ProtectionDataResponse> actual = get_api()->protectDocument(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting unprotect document
/// </summary>
TEST_F(DocumentProtectionTest, TestDeleteUnprotectDocument) {
	utility::string_t
		localName = STCONVERT("SampleProtectedBlankWordDocument.docx"),
		remoteName = STCONVERT("TestDeleteUnprotectDocument.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(protectionFolder), localName);

	std::shared_ptr<ProtectionRequest> body = std::make_shared<ProtectionRequest>();
	body->setPassword(STCONVERT("aspose"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UnprotectDocumentRequest> request=
			std::make_shared<UnprotectDocumentRequest>(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	AsposeResponse<ProtectionDataResponse> actual = get_api()->unprotectDocument(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}