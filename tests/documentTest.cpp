#include "TestBase.h"

/// <summary>
/// Example of how to get document
/// </summary>
class DocumentTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\Document"));
};

/// <summary>
/// Test for getting document
/// </summary>
TEST_F(DocumentTest, TestGetDocument) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocument.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentRequest> request=
			std::make_shared<GetDocumentRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<DocumentResponse> actual = get_api()->getDocument(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for creating word document
/// </summary>
TEST_F(DocumentTest, TestPutCreateDocument) {
	utility::string_t
		remoteName = STCONVERT("TestPutCreateDocument.docx");

	std::shared_ptr<PutCreateDocumentRequest> request=
			std::make_shared<PutCreateDocumentRequest>(boost::none, remoteName, dataFolder);

	std::shared_ptr<DocumentResponse> actual = get_api()->putCreateDocument(request).get();

	ASSERT_EQ(200, actual->getCode());
}
