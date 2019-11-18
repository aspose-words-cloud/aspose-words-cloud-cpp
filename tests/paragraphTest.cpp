/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="paragraphTest.cpp">
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
/// Example of how to work with paragraph
/// </summary>
class ParagraphTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements\\Paragraphs")),
		fieldFolder = STCONVERT("DocumentElements/Fields");
};

/// <summary>
/// Test for getting paragraph
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphByIndex) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphByIndex.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphRequest> request=
			std::make_shared<GetParagraphRequest>(remoteName, STCONVERT("sections/0"), index, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<ParagraphResponse> actual = get_api()->getParagraph(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting all paragraphs
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphs) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphs.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphsRequest> request=
			std::make_shared<GetParagraphsRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, STCONVERT("sections/0"));

	AsposeResponse<ParagraphLinkCollectionResponse> actual = get_api()->getParagraphs(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting first paragraph
/// </summary>
TEST_F(ParagraphTest, TestGetDocumentParagraphWithoutNodePath) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphWithoutNodePath.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphWithoutNodePathRequest> request=
			std::make_shared<GetParagraphWithoutNodePathRequest>(remoteName, index, dataFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<ParagraphResponse> actual = get_api()->getParagraphWithoutNodePath(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting paragraph
/// </summary>
TEST_F(ParagraphTest, TestDeleteParagraph) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDeleteParagraph.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteParagraphRequest> request=
			std::make_shared<DeleteParagraphRequest>(remoteName, STCONVERT(""), 0, dataFolder, boost::none, boost::none,
					boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteParagraph(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for paragraph rendering
/// </summary>
TEST_F(ParagraphTest, TestRenderParagraph) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestRenderParagraph.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		format = STCONVERT("png");
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RenderParagraphRequest> request=
			std::make_shared<RenderParagraphRequest>(remoteName, format, STCONVERT(""), index,
		dataFolder, boost::none, boost::none, boost::none, boost::none);

	HttpContent result = get_api()->renderParagraph(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for getting paragraph format settings
/// </summary>
TEST_F(ParagraphTest, TestGetParagraphFormat) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentParagraphs.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetParagraphFormatRequest> request=
			std::make_shared<GetParagraphFormatRequest>(remoteName, STCONVERT(""), 0,
		dataFolder, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphFormatResponse> actual = get_api()->getParagraphFormat(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating  paragraph format settings
/// </summary>
TEST_F(ParagraphTest, TestUpdateParagraphFormat) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestUpdateParagraphFormat.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<ParagraphFormat> body= std::make_shared<ParagraphFormat>();
	body->setAlignment(STCONVERT("Right"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateParagraphFormatRequest> request=
			std::make_shared<UpdateParagraphFormatRequest>(remoteName, body, STCONVERT(""), 0,
		dataFolder, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<ParagraphFormatResponse> actual = get_api()->updateParagraphFormat(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

