/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="appendDocumentTest.cpp">
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

class AppendDocumentTest : public InfrastructureTest
{
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp\\SdkTests\\TestData"), STCONVERT("DocumentActions\\AppendDocument"));
	}
};

/// <summary>
/// Test for appending document
/// </summary>
TEST_F(AppendDocumentTest, TestPostAppendDocument) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestPostAppendDocument.docx"),
		fullName = path_combine(get_data_folder(), remoteName),
		destFileName = path_combine_url(baseTestOutPath, remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);
	std::shared_ptr<DocumentEntryList> body= std::make_shared<DocumentEntryList>();
	std::shared_ptr<DocumentEntry> entry= std::make_shared<DocumentEntry>();
	entry->setHref(fullName);
	entry->setImportFormatMode(STCONVERT("KeepSourceFormatting"));

	std::vector<std::shared_ptr<DocumentEntry>> entries;
	entries.push_back(entry);
	body->setDocumentEntries(entries);

	UploadFileToStorage(fullName, filePath);

    std::shared_ptr<AppendDocumentRequest> request= std::make_shared<AppendDocumentRequest>(remoteName, body, get_data_folder(), boost::none,
		boost::none, boost::none, destFileName, boost::none, boost::none);
	auto requestTask = get_api()->appendDocument(request);
	AsposeResponse<DocumentResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}
