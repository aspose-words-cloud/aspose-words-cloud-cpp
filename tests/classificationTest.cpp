/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="classificationTest.cpp">
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
class ClassificationTests : public InfrastructureTest
{
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp/SdkTests/TestData"), STCONVERT(commonFolder.generic_string()));
	}
};

/// <summary>
/// Test for raw text classification
/// </summary>
TEST_F(ClassificationTests, TestClassify) {
	std::shared_ptr<ClassifyRequest> request=
			std::make_shared<ClassifyRequest>(STCONVERT("Try text classification"), STCONVERT("3"));
	auto requestTask = get_api()->classify(request);
	AsposeResponse<ClassificationResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for document classification.
/// </summary>
TEST_F(ClassificationTests, TestClassifyDocument) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("Source.docx"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ClassifyDocumentRequest> request=
			std::make_shared<ClassifyDocumentRequest>(remoteName, get_data_folder(),
		boost::none, boost::none, boost::none, STCONVERT("3"), boost::none);
	auto requestTask = get_api()->classifyDocument(request);
	AsposeResponse<ClassificationResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for document classification with taxonomy "documents".
/// </summary>
TEST_F(ClassificationTests, TestClassifyTaxonomyDocuments) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("Source.docx"),
		taxonomy = STCONVERT("documents"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ClassifyDocumentRequest> request= std::make_shared<ClassifyDocumentRequest>(remoteName, get_data_folder(),
		boost::none, boost::none, boost::none, STCONVERT("3"), taxonomy);
	auto requestTask = get_api()->classifyDocument(request);
	AsposeResponse<ClassificationResponse> actual = requestTask.get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}
