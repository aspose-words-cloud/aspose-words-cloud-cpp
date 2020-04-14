/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="reportingTest.cpp">
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
/// Example of how to perform reporting
/// </summary>
class ReportingTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("DocumentActions/Reporting")),
		reportingFolder = STCONVERT("DocumentActions/Reporting");
};

/// <summary>
/// Test for reporting online
/// </summary>
TEST_F(ReportingTest, TestBuildReportOnline) {
	std::shared_ptr<ReportEngineSettings> settings = std::make_shared<ReportEngineSettings>();
	settings->setDataSourceType(STCONVERT("Json"));
    settings->setDataSourceName(STCONVERT("persons"));

	std::shared_ptr<BuildReportOnlineRequest> request =
			std::make_shared<BuildReportOnlineRequest>(
		generate_http_content_from_file(path_combine(get_data_dir(reportingFolder), STCONVERT("ReportTemplate.docx")), STCONVERT("template")),
		get_file_text(path_combine(get_data_dir(reportingFolder), STCONVERT("ReportData.json"))),
		settings,
		boost::none);

	HttpContent result = get_api()->buildReportOnline(request).get();

	ASSERT_TRUE(result.getData()->peek());
}

/// <summary>
/// Test for reporting
/// </summary>
TEST_F(ReportingTest, TestBuildReport) {
	utility::string_t
		localName = STCONVERT("ReportTemplate.docx"),
		remoteName = STCONVERT("TestBuildReport.docx"),
		fullName = path_combine_url(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(reportingFolder), localName),
		destFileName = path_combine_url(baseTestOutPath, remoteName),
		data = get_file_text(path_combine(get_data_dir(reportingFolder), STCONVERT("ReportData.json")));

	UploadFileToStorage(fullName, filePath);

	std::shared_ptr<ReportEngineSettings> settings = std::make_shared<ReportEngineSettings>();
	settings->setDataSourceType(STCONVERT("Json"));

	auto buildOptions = std::vector<std::shared_ptr<ReportBuildOptions>>();
	buildOptions.push_back(ReportBuildOptions::AllowMissingMembers);
	buildOptions.push_back(ReportBuildOptions::RemoveEmptyParagraphs);
	settings->setReportBuildOptions(buildOptions);

	std::shared_ptr<BuildReportRequest> request = std::make_shared<BuildReportRequest>(
		remoteName,
		data, 
		settings,
		dataFolder,
		boost::none,
		boost::none,
		boost::none,
		boost::none);

	AsposeResponse<DocumentResponse> actual = get_api()->buildReport(request).get();

	ASSERT_EQ(200, actual.httpResponse->status_code());
}