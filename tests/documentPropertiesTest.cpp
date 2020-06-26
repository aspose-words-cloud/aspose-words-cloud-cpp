/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="documentPropertiesTest.cpp">
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

class DocumentPropertiesTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements/DocumentProperties"));
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

	AsposeResponse<DocumentPropertiesResponse> actual = get_api()->getDocumentProperties(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	AsposeResponse<DocumentPropertyResponse> actual = get_api()->getDocumentProperty(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
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

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteDocumentProperty(request).get();

	ASSERT_EQ(200, actual->status_code());
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

	std::shared_ptr<DocumentPropertyCreateOrUpdate> body= std::make_shared<DocumentPropertyCreateOrUpdate>();
	body->setValue(STCONVERT("Imran Anwar"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request=
			std::make_shared<CreateOrUpdateDocumentPropertyRequest>(
		remoteName, propertyName, body, dataFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	AsposeResponse<DocumentPropertyResponse> actual = get_api()->createOrUpdateDocumentProperty(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}