/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="build_report_test.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#pragma once
#include "../test_base.h"

/// <summary>
/// Example of how to perform mail merge.
/// </summary>
class BuildReportTests : public InfrastructureTest {
protected:
    std::wstring remoteDataFolder = remoteBaseTestDataFolder + L"/DocumentActions/Reporting";
    std::wstring reportingFolder = L"DocumentActions/Reporting";

};

/// <summary>
/// Test for build report online.
/// </summary>
TEST_F(BuildReportTests, TestBuildReportOnline) {
    std::wstring localDocumentFile = L"ReportTemplate.docx";
    std::wstring localDataFile = getFileTextUtf16(localTestDataFolder + L"/" + reportingFolder + L"/ReportData.json");

    auto requestTemplate = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(getDataDir(reportingFolder + L"/" + localDocumentFile)), std::istream::binary));
    auto requestReportEngineSettings = std::make_shared< aspose::words::cloud::models::ReportEngineSettings >();
    requestReportEngineSettings->setDataSourceType(std::make_shared< aspose::words::cloud::models::ReportEngineSettings::DataSourceType >(aspose::words::cloud::models::ReportEngineSettings::DataSourceType::JSON));
    requestReportEngineSettings->setDataSourceName(std::make_shared< std::wstring >(L"persons"));
    std::shared_ptr<requests::BuildReportOnlineRequest> request(new requests::BuildReportOnlineRequest(
        requestTemplate,
        std::make_shared< std::wstring >(localDataFile),
        requestReportEngineSettings,
        nullptr
    ));

    auto actual = getApi()->buildReportOnline(request);
}

/// <summary>
/// Test for build report.
/// </summary>
TEST_F(BuildReportTests, TestBuildReport) {
    std::wstring localDocumentFile = L"ReportTemplate.docx";
    std::wstring remoteFileName = L"TestBuildReport.docx";
    std::wstring localDataFile = getFileTextUtf16(localTestDataFolder + L"/" + reportingFolder + L"/ReportData.json");

    uploadFileToStorage(
        localTestDataFolder + L"/" + reportingFolder + L"/" + localDocumentFile,
        remoteDataFolder + L"/" + remoteFileName
    );

    auto requestReportEngineSettingsReportBuildOptions = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::ReportBuildOptions>> >();
    requestReportEngineSettingsReportBuildOptions->push_back(std::make_shared< aspose::words::cloud::models::ReportBuildOptions >(aspose::words::cloud::models::ReportBuildOptions::ALLOW_MISSING_MEMBERS));
    requestReportEngineSettingsReportBuildOptions->push_back(std::make_shared< aspose::words::cloud::models::ReportBuildOptions >(aspose::words::cloud::models::ReportBuildOptions::REMOVE_EMPTY_PARAGRAPHS));
    auto requestReportEngineSettings = std::make_shared< aspose::words::cloud::models::ReportEngineSettings >();
    requestReportEngineSettings->setDataSourceType(std::make_shared< aspose::words::cloud::models::ReportEngineSettings::DataSourceType >(aspose::words::cloud::models::ReportEngineSettings::DataSourceType::JSON));
    requestReportEngineSettings->setReportBuildOptions(requestReportEngineSettingsReportBuildOptions);
    std::shared_ptr<requests::BuildReportRequest> request(new requests::BuildReportRequest(
        std::make_shared< std::wstring >(remoteFileName),
        std::make_shared< std::wstring >(localDataFile),
        requestReportEngineSettings,
        std::make_shared< std::wstring >(remoteDataFolder),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr
    ));

    auto actual = getApi()->buildReport(request);
    ASSERT_TRUE(actual->getDocument() != nullptr);
    ASSERT_TRUE(actual->getDocument()->getFileName()->compare(L"TestBuildReport.docx") == 0);
}
