auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestReportEngineSettingsReportBuildOptions = std::make_shared< std::vector<std::shared_ptr<aspose::words::cloud::models::ReportBuildOptions>> >();
requestReportEngineSettingsReportBuildOptions->push_back(std::make_shared< aspose::words::cloud::models::ReportBuildOptions >(aspose::words::cloud::models::ReportBuildOptions::ALLOW_MISSING_MEMBERS));
requestReportEngineSettingsReportBuildOptions->push_back(std::make_shared< aspose::words::cloud::models::ReportBuildOptions >(aspose::words::cloud::models::ReportBuildOptions::REMOVE_EMPTY_PARAGRAPHS));
auto requestReportEngineSettings = std::make_shared< aspose::words::cloud::models::ReportEngineSettings >();
requestReportEngineSettings->setDataSourceType(std::make_shared< aspose::words::cloud::models::ReportEngineSettings::DataSourceType >(aspose::words::cloud::models::ReportEngineSettings::DataSourceType::JSON));
requestReportEngineSettings->setReportBuildOptions(requestReportEngineSettingsReportBuildOptions);
std::shared_ptr< requests::BuildReportRequest > buildReportRequest(
    new requests::BuildReportRequest(
        std::make_shared< std::wstring >(L"Sample.docx"), std::make_shared< std::wstring >(L"Data.json"), requestReportEngineSettings
    )
);
wordsApi->buildReport(buildReportRequest);