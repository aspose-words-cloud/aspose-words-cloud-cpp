#include "TestBase.h"

class DocumentPropertiesTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\DocumentProperties"));
};

/// <summary>
/// Test for getting document properties
/// </summary>
TEST_F(DocumentPropertiesTest, TestGetDocumentProperties)
{
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentProperties.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentPropertiesRequest> request=
			std::make_shared<GetDocumentPropertiesRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<DocumentPropertiesResponse> actual = get_api()->getDocumentProperties(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// A test for GetDocumentProperty
/// </summary>
TEST_F(DocumentPropertiesTest, TestGetDocumentProperty)
{
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentProperty.docx"),
		propertyName = STCONVERT("Author"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentPropertyRequest> request=
			std::make_shared<GetDocumentPropertyRequest>(remoteName, propertyName, dataFolder, boost::none,
		boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->getDocumentProperty(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting document property
/// </summary>
TEST_F(DocumentPropertiesTest, TestDeleteDocumentProperty) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteDocumentProperty.docx"),
		propertyName = STCONVERT("testProp"),
		fullName = path_combine_url(dataFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteDocumentPropertyRequest> request=
			std::make_shared<DeleteDocumentPropertyRequest>(remoteName, propertyName, dataFolder,
					boost::none, boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteDocumentProperty(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for updating document property
/// </summary>
TEST_F(DocumentPropertiesTest, TestPutUpdateDocumentProperty) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutUpdateDocumentProperty.docx"),
		propertyName = STCONVERT("AsposeAuthor"),
		fullName = path_combine_url(dataFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<DocumentProperty> body= std::make_shared<DocumentProperty>();
	body->setName(STCONVERT("Author"));
	body->setValue(STCONVERT("Imran Anwar"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request=
			std::make_shared<CreateOrUpdateDocumentPropertyRequest>(
		remoteName, propertyName, body, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	std::shared_ptr<DocumentPropertyResponse> actual = get_api()->createOrUpdateDocumentProperty(request).get();

	ASSERT_EQ(200, actual->getCode());
}