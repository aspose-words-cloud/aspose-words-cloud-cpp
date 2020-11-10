/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="buildReportTests.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "../TestBase.h"

/// <summary>
/// Example of how to perform mail merge.
/// </summary>
class BuildReportTests : public InfrastructureTest {
protected:
    utility::string_t remoteDataFolder = remoteBaseTestDataFolder + STCONVERT("/DocumentActions/Reporting");
    utility::string_t reportingFolder = STCONVERT("DocumentActions/Reporting");

};

/// <summary>
/// Test for build report online.
/// </summary>
TEST_F(BuildReportTests, TestBuildReportOnline) {
    utility::string_t localDocumentFile = STCONVERT("ReportTemplate.docx");
    utility::string_t localDataFile = get_file_text(path_combine(LocalTestDataFolder, reportingFolder + STCONVERT("/ReportData.json")));

    auto requestReportEngineSettings = std::make_shared< ReportEngineSettings >();
    requestReportEngineSettings->setDataSourceType(STCONVERT("Json"));
    requestReportEngineSettings->setDataSourceName(STCONVERT("persons"));

    std::shared_ptr< BuildReportOnlineRequest > request(new BuildReportOnlineRequest(
        generate_http_content_from_file(path_combine(LocalTestDataFolder, reportingFolder + STCONVERT("/") + localDocumentFile)),
        localDataFile,
        requestReportEngineSettings,
        boost::none
    ));

   get_api()->buildReportOnline(request).get();
}

/// <summary>
/// Test for build report.
/// </summary>
TEST_F(BuildReportTests, TestBuildReport) {
    utility::string_t localDocumentFile = STCONVERT("ReportTemplate.docx");
    utility::string_t remoteFileName = STCONVERT("TestBuildReport.docx");
    utility::string_t localDataFile = get_file_text(path_combine(LocalTestDataFolder, reportingFolder + STCONVERT("/ReportData.json")));

    UploadFileToStorage(
        remoteDataFolder + STCONVERT("/") + remoteFileName,
        path_combine(LocalTestDataFolder, reportingFolder + STCONVERT("/") + localDocumentFile)
    );

    std::vector<utility::string_t> requestReportEngineSettingsReportBuildOptions;
    requestReportEngineSettingsReportBuildOptions.push_back(STCONVERT("AllowMissingMembers"));
    requestReportEngineSettingsReportBuildOptions.push_back(STCONVERT("RemoveEmptyParagraphs"));

    auto requestReportEngineSettings = std::make_shared< ReportEngineSettings >();
    requestReportEngineSettings->setDataSourceType(STCONVERT("Json"));
    requestReportEngineSettings->setReportBuildOptions(requestReportEngineSettingsReportBuildOptions);

    std::shared_ptr< BuildReportRequest > request(new BuildReportRequest(
        remoteFileName,
        localDataFile,
        requestReportEngineSettings,
        remoteDataFolder,
        boost::none,
        boost::none,
        boost::none,
        boost::none
    ));

   auto actual = get_api()->buildReport(request).get();
   ASSERT_EQ(200, actual.httpResponse->status_code());
   ASSERT_TRUE(IsNotNull(actual.body->getDocument()));
   ASSERT_EQ(STCONVERT("TestBuildReport.docx"), actual.body->getDocument()->getFileName());
}
