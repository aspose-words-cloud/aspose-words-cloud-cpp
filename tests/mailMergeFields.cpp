/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="mailMergeFields.cpp">
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
/// Example of how to work with merge fields
/// </summary>
class MailMergeFiledsTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions/MailMerge")),
		mailMergeFolder = STCONVERT("DocumentActions/MailMerge");
};

/// <summary>
/// Test for getting mailmerge fields
/// </summary>
TEST_F(MailMergeFiledsTest, TestGetDocumentFieldNames) {
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestGetDocumentFieldNames.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetDocumentFieldNamesRequest> request=
			std::make_shared<GetDocumentFieldNamesRequest>(remoteName, dataFolder, boost::none,
		boost::none, boost::none, boost::none);

	AsposeResponse<FieldNamesResponse> actual = get_api()->getDocumentFieldNames(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());

}

/// <summary>
/// Test for getting mailmerge fields online
/// </summary>
TEST_F(MailMergeFiledsTest, TestGetDocumentFieldNamesOnline) {
	std::shared_ptr<HttpContent> file = generate_http_content_from_file(path_combine(get_data_dir(mailMergeFolder), STCONVERT("SampleExecuteTemplate.docx")));

	std::shared_ptr<GetDocumentFieldNamesOnlineRequest> request=
			std::make_shared<GetDocumentFieldNamesOnlineRequest>(file, true);

	AsposeResponse<FieldNamesResponse> actual = get_api()->getDocumentFieldNamesOnline(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());

}