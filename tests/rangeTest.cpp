/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="rangeTest.cpp">
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
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

/// <summary>
/// Example of how to work wtih range
/// </summary>
class RangeTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements/Range")),
		tableFolder = STCONVERT("DocumentElements/Range");
};

/// <summary>
/// Test for getting range text
/// </summary>
TEST_F(RangeTest, TestGetRangeText) {
	utility::string_t
		localName = STCONVERT("RangeGet.doc"),
		remoteName = STCONVERT("TestGetRangeText.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetRangeTextRequest> request =
		std::make_shared<GetRangeTextRequest>(remoteName,STCONVERT("id0.0.0"), STCONVERT("id0.0.1"), dataFolder,
			boost::none, boost::none, boost::none);

	AsposeResponse<RangeTextResponse> actual = get_api()->getRangeText(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
	ASSERT_EQ(STCONVERT("This is HEADER "), actual.body->getText());
}

/// <summary>
/// Test for removing range
/// </summary>
TEST_F(RangeTest, TestRemoveRange) {
	utility::string_t
		localName = STCONVERT("RangeGet.doc"),
		remoteName = STCONVERT("TestRemoveRange.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RemoveRangeRequest> request =
		std::make_shared<RemoveRangeRequest>(remoteName, STCONVERT("id0.0.0"), STCONVERT("id0.0.1"), dataFolder,
			boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<DocumentResponse> actual = get_api()->removeRange(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for saving As range
/// </summary>
TEST_F(RangeTest, TestSaveAsRange) {
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	const std::string uuid_string = boost::uuids::to_string(uuid);

	utility::string_t
		localName = STCONVERT("RangeGet.doc"),
		remoteName = STCONVERT("TestSaveAsRange.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<RangeDocument> docParams = std::shared_ptr<RangeDocument>(new RangeDocument());
	docParams->setDocumentName(path_combine_url(dataFolder, STCONVERT("newDoc" + uuid_string + ".docx")));

	std::shared_ptr<SaveAsRangeRequest> request =
		std::make_shared<SaveAsRangeRequest>(remoteName, STCONVERT("id0.0.0"), docParams, STCONVERT("id0.0.1"), dataFolder,
			boost::none, boost::none, boost::none);

	AsposeResponse<DocumentResponse> actual = get_api()->saveAsRange(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for replacing with text
/// </summary>
TEST_F(RangeTest, TestReplaceWithText) {
	utility::string_t
		localName = STCONVERT("RangeGet.doc"),
		remoteName = STCONVERT("TestReplacingWithText.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(tableFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ReplaceRange> replacement = std::shared_ptr<ReplaceRange>(new ReplaceRange());
	replacement->setText(STCONVERT("Replaced header"));

	std::shared_ptr<ReplaceWithTextRequest> request =
		std::make_shared<ReplaceWithTextRequest>(remoteName, STCONVERT("id0.0.0"), replacement, STCONVERT("id0.0.1"), dataFolder,
			boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<DocumentResponse> actual = get_api()->replaceWithText(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}