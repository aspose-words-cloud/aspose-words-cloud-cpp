/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compareDocumentTest.cpp">
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
class CompareDocumentTest : public InfrastructureTest {
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp/SdkTests/TestData"), STCONVERT("DocumentActions/CompareDocument"));
	}
	const utility::string_t compareFolder = STCONVERT("DocumentActions/CompareDocument");
};

/// <summary>
/// Test for document comparison
/// </summary>
TEST_F(CompareDocumentTest, TestCompareDocument) {
	utility::string_t
		localName1 = STCONVERT("compareTestDoc1.doc"),
		localName2 = STCONVERT("compareTestDoc2.doc"),
		remoteName1 = STCONVERT("TestCompareDocument1.doc"),
		remoteName2 = STCONVERT("TestCompareDocument2.doc"),
		fullName1 = path_combine_url(get_data_folder(), remoteName1),
		fullName2 = path_combine_url(get_data_folder(), remoteName2),
		destFileName = path_combine_url(baseTestOutPath, STCONVERT("TestCompareDocumentOut.doc")),
		filePath1 = path_combine(get_data_dir(compareFolder), localName1),
		filePath2 = path_combine(get_data_dir(compareFolder), localName2);

	std::shared_ptr<CompareData> compareData= std::make_shared<CompareData>();
	compareData->setAuthor(STCONVERT("author"));
	compareData->setComparingWithDocument(fullName2);
	compareData->setDateTime(utility::datetime::from_string(STCONVERT("Mon, 26 Oct 2015 00:00:00 GMT")));

	UploadFileToStorage(fullName1, filePath1);
	UploadFileToStorage(fullName2, filePath2);

	std::shared_ptr<CompareDocumentRequest> request=
			std::make_shared<CompareDocumentRequest>(remoteName1, compareData, get_data_folder(),
					boost::none, boost::none, boost::none, destFileName);
	auto requestTask = get_api()->compareDocument(request);

	AsposeResponse<DocumentResponse> actual = requestTask.get();
	ASSERT_EQ(200, actual.httpResponse->status_code());
}
