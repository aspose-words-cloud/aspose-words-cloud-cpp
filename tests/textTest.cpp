/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="textTest.cpp">
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
/// Example of how to work with text
/// </summary>
class TextTest : public InfrastructureTest {
protected:
	utility::string_t textFolder = STCONVERT("DocumentElements/Text"),
		remoteTextFolder = path_combine_url(remoteBaseTestDataFolder, textFolder);
};

/// <summary>
/// Test for getting text from document
/// </summary>
TEST_F(TextTest, TestGetDocumentTextItems) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentTextItems.docx"),
		fullName = path_combine_url(remoteTextFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetRunsRequest> request=
			std::make_shared<GetRunsRequest>(remoteName, STCONVERT("sections/0/paragraphs/0"), remoteTextFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<RunsResponse> actual = get_api()->getRuns(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for replacing text
/// </summary>
TEST_F(TextTest, TestPostReplaceText) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostReplaceText.docx"),
		fullName = path_combine_url(remoteTextFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);

	std::shared_ptr<ReplaceTextParameters> body = std::make_shared<ReplaceTextParameters>();
	body->setOldValue(STCONVERT("aspose"));
	body->setNewValue(STCONVERT("aspose new"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ReplaceTextRequest> request= std::make_shared<ReplaceTextRequest>(remoteName, body, remoteTextFolder, boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);

	AsposeResponse<ReplaceTextResponse> actual = get_api()->replaceText(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for searching
/// </summary>
TEST_F(TextTest, TestSearch) {
	utility::string_t
		localName = STCONVERT("SampleWordDocument.docx"),
		remoteName = STCONVERT("TestSearch.docx"),
		fullName = path_combine_url(remoteTextFolder, remoteName),
		filePath = path_combine(get_data_dir(textFolder), localName),
		pattern = STCONVERT("aspose");

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<SearchRequest> request=
			std::make_shared<SearchRequest>(remoteName, pattern, remoteTextFolder, boost::none,
		boost::none, boost::none);

	AsposeResponse<SearchResponse> actual = get_api()->search(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}