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

	std::shared_ptr<PutProtectDocumentRequest> request=
			std::make_shared<PutProtectDocumentRequest>(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, destFileName);

	std::shared_ptr<ProtectionDataResponse> actual = get_api()->putProtectDocument(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<ProtectionDataResponse> actual = get_api()->getDocumentProtection(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<PostChangeDocumentProtectionRequest> request=
			std::make_shared<PostChangeDocumentProtectionRequest>(remoteName, body, dataFolder,
					boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<ProtectionDataResponse> actual = get_api()->postChangeDocumentProtection(request).get();

	ASSERT_EQ(200, actual->getCode());
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

	std::shared_ptr<DeleteUnprotectDocumentRequest> request=
			std::make_shared<DeleteUnprotectDocumentRequest>(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<ProtectionDataResponse> actual = get_api()->deleteUnprotectDocument(request).get();

	ASSERT_EQ(200, actual->getCode());
}