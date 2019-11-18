/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="convertDocumentTest.cpp">
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

class ConvertDocumentTest : public InfrastructureTest {
protected:
	const utility::string_t baseFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\ConvertDocument")),
		convertFolder = STCONVERT("DocumentActions/ConvertDocument");
};

/// <summary>
/// Test for converting document to one of the available formats
/// </summary>
TEST_F(ConvertDocumentTest, TestPostDocumentSaveAs) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostDocumentSaveAs.docx"),
		fullName = path_combine_url(baseFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".pdf")),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<SaveOptionsData> saveOptionsData= std::make_shared<SaveOptionsData>();
	saveOptionsData->setSaveFormat(STCONVERT("pdf"));
	saveOptionsData->setFileName(destFileName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<SaveAsRequest> request=
			std::make_shared<SaveAsRequest>(remoteName, saveOptionsData, baseFolder,
					boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<SaveResponse> actual = get_api()->saveAs(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for converting document to one of the available formats
/// </summary>
TEST_F(ConvertDocumentTest, TestPostDocumentSaveAsFromPdfToDoc) {
	utility::string_t
		localName = STCONVERT("45.pdf"),
		remoteName = STCONVERT("TestPostDocumentSaveAsFromPdfToDoc.pdf"),
		fullName = path_combine_url(baseFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".docx")),
		filePath = path_combine(get_data_dir(convertFolder), localName);

	std::shared_ptr<SaveOptionsData> saveOptionsData= std::make_shared<SaveOptionsData>();
	saveOptionsData->setSaveFormat(STCONVERT("docx"));
	saveOptionsData->setFileName(destFileName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<SaveAsRequest> request=
			std::make_shared<SaveAsRequest>(remoteName, saveOptionsData, baseFolder,
					boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<SaveResponse> actual = get_api()->saveAs(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// A test for PutConvertDocument
/// </summary>
TEST_F(ConvertDocumentTest, TestPutConvertDocument) {
	utility::string_t format = STCONVERT("pdf");
	std::shared_ptr<ConvertDocumentRequest> request(
		new ConvertDocumentRequest(generate_http_content_from_file(path_combine(get_data_dir(convertFolder), STCONVERT("test_uploadfile.docx"))),
			format, boost::none, boost::none, boost::none, boost::none));

	auto result = get_api()->convertDocument(request).get();
	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for saving document as a tiff file
/// </summary>
TEST_F(ConvertDocumentTest, TestPutDocumentAsTiff) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPutDocumentAsTiff.docx"),
		fullName = path_combine_url(baseFolder, remoteName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".tiff")),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	std::shared_ptr<TiffSaveOptionsData> saveOptionsData= std::make_shared<TiffSaveOptionsData>();
	saveOptionsData->setSaveFormat(STCONVERT("tiff"));
	saveOptionsData->setFileName(STCONVERT("abc.tiff"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<SaveAsTiffRequest> request= std::make_shared<SaveAsTiffRequest>(remoteName, saveOptionsData, baseFolder, boost::none, boost::none
		, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none
		, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<SaveResponse> actual = get_api()->saveAsTiff(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}
