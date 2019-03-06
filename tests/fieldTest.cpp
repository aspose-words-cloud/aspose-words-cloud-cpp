/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="fieldTest.cpp">
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

/// <summary>
/// Example of how to work with field
/// </summary>
class FieldTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Fields")),
		textFolder = STCONVERT("DocumentElements/Text"),
		fieldFolder = STCONVERT("DocumentElements/Fields");
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

	std::shared_ptr<GetFieldsRequest> request=
			std::make_shared<GetFieldsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0"));

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

	std::shared_ptr<GetFieldRequest> request=
			std::make_shared<GetFieldRequest>(remoteName, fieldIndex, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0/paragraphs/0"));

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

	std::shared_ptr<Field> body= std::make_shared<Field>();
	body->setResult(STCONVERT("3"));
	body->setFieldCode(STCONVERT("{ NUMPAGES }"));
	body->setNodeId(STCONVERT("0.0.3"));


	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PutFieldRequest> request=
			std::make_shared<PutFieldRequest>(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none,
		STCONVERT("sections/0/paragraphs/0"), boost::none);

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

	std::shared_ptr<Field> body= std::make_shared<Field>();
	body->setResult(STCONVERT("3"));
	body->setFieldCode(STCONVERT("{ NUMPAGES }"));
	body->setNodeId(STCONVERT("0.0.3"));


	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostFieldRequest> request=
			std::make_shared<PostFieldRequest>(remoteName, body, fieldIndex, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none,
		STCONVERT("sections/0/paragraphs/0"));

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

	std::shared_ptr<PageNumber> body= std::make_shared<PageNumber>();
	body->setAlignment(STCONVERT("center"));
	body->setFormat(STCONVERT("{PAGE} of {NUMPAGES}"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<PostInsertPageNumbersRequest> request=
			std::make_shared<PostInsertPageNumbersRequest>(remoteName, body, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

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

	std::shared_ptr<DeleteFieldRequest> request=
			std::make_shared<DeleteFieldRequest>(remoteName, fieldIndex, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none,
		STCONVERT("sections/0/paragraphs/0"));

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

	std::shared_ptr<DeleteFieldsRequest> request=
			std::make_shared<DeleteFieldsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, STCONVERT("paragraphs/0"));

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

	std::shared_ptr<DeleteFieldsRequest> request=
			std::make_shared<DeleteFieldsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none,
		STCONVERT("sections/0/paragraphs/0"));

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

	std::shared_ptr<DeleteFieldsRequest> request=
			std::make_shared<DeleteFieldsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, STCONVERT("sections/0"));

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

	std::shared_ptr<DeleteFieldsRequest> request=
			std::make_shared<DeleteFieldsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

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

	std::shared_ptr<PostUpdateDocumentFieldsRequest> request=
			std::make_shared<PostUpdateDocumentFieldsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	std::shared_ptr<DocumentResponse> actual = get_api()->postUpdateDocumentFields(request).get();

	ASSERT_EQ(200, actual->getCode());
}