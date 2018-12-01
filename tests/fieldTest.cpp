#include "TestBase.h"

/// <summary>
/// Example of how to work with field
/// </summary>
class FieldTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Fields")),
		textFolder = STCONVERT("DocumentElements\\Text"),
		fieldFolder = STCONVERT("DocumentElements\\Fields");
};

/// <summary>
/// Test for getting fields
/// </summary>
TEST_F(FieldTest, TestGetFields) {
	utility::string_t
		localName = STCONVERT("GetField.docx"),
		remoteName = STCONVERT("TestGetFields.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFieldsRequest> request(new GetFieldsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<FieldsResponse> actual = get_api()->getFields(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for getting field by index
/// </summary>
TEST_F(FieldTest, TestGetField) {
	utility::string_t
		localName = STCONVERT("GetField.docx"),
		remoteName = STCONVERT("TestGetField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	int32_t fieldIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetFieldRequest> request(new GetFieldRequest(remoteName, fieldIndex, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0/paragraphs/0")));

	std::shared_ptr<FieldResponse> actual = get_api()->getField(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for putting field
/// </summary>
TEST_F(FieldTest, TestPutField) {
	utility::string_t
		localName = STCONVERT("SampleWordDocument.docx"),
		remoteName = STCONVERT("TestPutField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(textFolder), localName);

	std::shared_ptr<Field> body(new Field);
	body->setResult(STCONVERT("3"));
	body->setFieldCode(STCONVERT("{ NUMPAGES }"));
	body->setNodeId(STCONVERT("0.0.3"));


	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutFieldRequest> request(new PutFieldRequest(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, STCONVERT("sections/0/paragraphs/0"), boost::none));

	std::shared_ptr<FieldResponse> actual = get_api()->putField(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for posting field
/// </summary>
TEST_F(FieldTest, TestPostField) {
	utility::string_t
		localName = STCONVERT("GetField.docx"),
		remoteName = STCONVERT("TestPostField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	int32_t fieldIndex = 0;

	std::shared_ptr<Field> body(new Field);
	body->setResult(STCONVERT("3"));
	body->setFieldCode(STCONVERT("{ NUMPAGES }"));
	body->setNodeId(STCONVERT("0.0.3"));


	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostFieldRequest> request(new PostFieldRequest(remoteName, body, fieldIndex, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none, STCONVERT("sections/0/paragraphs/0")));

	std::shared_ptr<FieldResponse> actual = get_api()->postField(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for posting insert page numbers field
/// </summary>
TEST_F(FieldTest, TestPostInsertPageNumbers) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostInsertPageNumbers.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<PageNumber> body(new PageNumber());
	body->setAlignment(STCONVERT("center"));
	body->setFormat(STCONVERT("{PAGE} of {NUMPAGES}"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostInsertPageNumbersRequest> request(new PostInsertPageNumbersRequest(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none));

	std::shared_ptr<DocumentResponse> actual = get_api()->postInsertPageNumbers(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting field
/// </summary>
TEST_F(FieldTest, TestDeleteField) {
	utility::string_t
		localName = STCONVERT("GetField.docx"),
		remoteName = STCONVERT("TestDeleteField.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(fieldFolder), localName);

	int32_t fieldIndex = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFieldRequest> request(new DeleteFieldRequest(remoteName, fieldIndex, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, STCONVERT("sections/0/paragraphs/0")));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteField(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting paragraph fields
/// </summary>
TEST_F(FieldTest, TestDeleteParagraphFields) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteParagraphFields.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFieldsRequest> request(new DeleteFieldsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, STCONVERT("paragraphs/0")));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteFields(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting sections fields
/// </summary>
TEST_F(FieldTest, TestDeleteSectionParagraphFields) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteSectionParagraphFields.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFieldsRequest> request(new DeleteFieldsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, STCONVERT("sections/0/paragraphs/0")));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteFields(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting paragraph fields in section
/// </summary>
TEST_F(FieldTest, TestDeleteSectionFields) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteSectionFields.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFieldsRequest> request(new DeleteFieldsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, STCONVERT("sections/0")));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteFields(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for deleting fields
/// </summary>
TEST_F(FieldTest, TestDeleteDocumentFields) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteDocumentFields.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteFieldsRequest> request(new DeleteFieldsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none));

	std::shared_ptr<AsposeResponse> actual = get_api()->deleteFields(request).get();

	ASSERT_EQ(200, actual->getCode());
}

/// <summary>
/// Test for posting updated fields
/// </summary>
TEST_F(FieldTest, TestPostUpdateDocumentFields) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostUpdateDocumentFields.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostUpdateDocumentFieldsRequest> request(new PostUpdateDocumentFieldsRequest(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none));

	std::shared_ptr<DocumentResponse> actual = get_api()->postUpdateDocumentFields(request).get();

	ASSERT_EQ(200, actual->getCode());
}