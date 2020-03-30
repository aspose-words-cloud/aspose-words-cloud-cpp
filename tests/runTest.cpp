/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="runTest.cpp">
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
/// Example of how to work with runs
/// </summary>
class RunTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentElements/Runs")),
		runFolder = STCONVERT("DocumentElements/Runs");
};

/// <summary>
/// Test for updating run
/// </summary>
TEST_F(RunTest, TestPostRun) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestPostRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);

	std::shared_ptr<aspose::words::cloud::api::RunUpdate > run = std::make_shared<aspose::words::cloud::api::RunUpdate>();
	run->setText(STCONVERT("run with text"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<UpdateRunRequest> request=
			std::make_shared<UpdateRunRequest>(remoteName, run, STCONVERT("paragraphs/1"), 0, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<RunResponse> actual = get_api()->updateRun(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for inserting run
/// </summary>
TEST_F(RunTest, TestPutRun) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestPutRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);

	std::shared_ptr<aspose::words::cloud::api::RunInsert > run = std::make_shared<aspose::words::cloud::api::RunInsert>();
	run->setText(STCONVERT("run with text"));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<InsertRunRequest> request= std::make_shared<InsertRunRequest>(remoteName, STCONVERT("paragraphs/1"), run, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<RunResponse> actual = get_api()->insertRun(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for deleting run
/// </summary>
TEST_F(RunTest, TestDeleteRun) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestPostRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<DeleteRunRequest> request= std::make_shared<DeleteRunRequest>(remoteName, STCONVERT("paragraphs/1"), index, dataFolder, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	std::shared_ptr<web::http::http_response> actual = get_api()->deleteRun(request).get();

	ASSERT_EQ(200, actual->status_code());
}

/// <summary>
/// Test for getting run
/// </summary>
TEST_F(RunTest, TestGetRun) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestGetRun.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetRunRequest> request = std::make_shared<GetRunRequest>(remoteName, STCONVERT("paragraphs/1"), index, dataFolder,
		boost::none, boost::none, boost::none);

	AsposeResponse<RunResponse> actual = get_api()->getRun(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for getting run font
/// </summary>
TEST_F(RunTest, TestGetRunFont) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestGetRunFont.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);
	int32_t index = 0;

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<GetRunFontRequest> request = std::make_shared<GetRunFontRequest>(remoteName, STCONVERT("paragraphs/1"), index, dataFolder,
		boost::none, boost::none, boost::none);

	AsposeResponse<FontResponse> actual = get_api()->getRunFont(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}

/// <summary>
/// Test for updating run font
/// </summary>
TEST_F(RunTest, TestUpdateRunFont) {
	utility::string_t
		localName = STCONVERT("Run.doc"),
		remoteName = STCONVERT("TestPostRunFont.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(runFolder), localName);

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<Font> font = std::shared_ptr<Font>(new Font());
	font->setBold(true);

	std::shared_ptr<UpdateRunFontRequest> request =
		std::make_shared<UpdateRunFontRequest>(remoteName, font, STCONVERT("paragraphs/1"), 0, dataFolder, boost::none,
			boost::none, boost::none, boost::none, boost::none, boost::none);

	AsposeResponse<FontResponse> actual = get_api()->updateRunFont(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}