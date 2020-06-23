/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="splitDocumentToFormatTest.cpp">
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
/// Example of how to split document and return result with specified format and page rang
/// </summary>
class SplitDocumentToFormatTest : public InfrastructureTest {
protected:
	const utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions/SplitDocument"));
};

/// <summary>
/// Test for document splitting
/// </summary>
TEST_F(SplitDocumentToFormatTest, TestPostSplitDocument)
{
	utility::string_t
		localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostSplitDocument.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		format = STCONVERT("text"),
		filePath = path_combine(get_data_dir(commonFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, cutFileExtension(remoteName) + STCONVERT(".text"));

	int32_t from = 1,
		to = 2;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<SplitDocumentRequest> request=
			std::make_shared<SplitDocumentRequest>(remoteName, format, dataFolder, boost::none, boost::none,
		boost::none, destFileName, from, to, boost::none, boost::none);

	AsposeResponse<SplitDocumentResponse> actual = get_api()->splitDocument(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}