/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="executeMailMergeTest.cpp">
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
/// Example of how to perform mail merge
/// </summary>
class ExecuteMailMergeTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions\\MailMerge")),
		mailMergeFolder = STCONVERT("DocumentActions/MailMerge");
};

/// <summary>
/// Test for executing mail merge online
/// </summary>
TEST_F(ExecuteMailMergeTest, TestPutExecuteMailMergeOnline) {
	std::shared_ptr<PutExecuteMailMergeOnlineRequest> request=
			std::make_shared<PutExecuteMailMergeOnlineRequest>(
		generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleExecuteTemplate.docx")), STCONVERT("template")),
		generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleExecuteTemplateData.txt")), STCONVERT("data")),
		boost::none, boost::none, boost::none);

	HttpContent result = get_api()->putExecuteMailMergeOnline(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for executing mail merge
/// </summary>
TEST_F(ExecuteMailMergeTest, TestPostDocumentExecuteMailMerge) {
	utility::string_t
		localName = STCONVERT("SampleMailMergeTemplate.docx"),
		remoteName = STCONVERT("TestPostDocumentExecuteMailMerge.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(mailMergeFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		fileContent = get_file_text(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleMailMergeTemplateData.txt")));

	UploadFileToStorage(fullName, filePath);
	std::shared_ptr<PostDocumentExecuteMailMergeRequest> request=
			std::make_shared<PostDocumentExecuteMailMergeRequest>(remoteName,
		fileContent, dataFolder, boost::none, boost::none, boost::none, false, boost::none,
		boost::none, boost::none, destFileName);

	std::shared_ptr<DocumentResponse> actual = get_api()->postDocumentExecuteMailMerge(request).get();

	ASSERT_EQ(200, actual->getCode());
}