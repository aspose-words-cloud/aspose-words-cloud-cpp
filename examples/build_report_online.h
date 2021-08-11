std::wstring documentsDir = L"...";
auto config = std::make_shared<ApiConfiguration>(/*clientId*/ L"####-####-####-####-####", /*clientSecret*/ L"##################");
auto wordsApi = std::make_shared<WordsApi>(config);
auto requestTemplateStream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(documentsDir + L"/" + L"Sample.docx"), std::istream::binary));
auto requestReportEngineSettings = std::make_shared< aspose::words::cloud::models::ReportEngineSettings >();
requestReportEngineSettings->setDataSourceType(std::make_shared< aspose::words::cloud::models::ReportEngineSettings::DataSourceType >(aspose::words::cloud::models::ReportEngineSettings::DataSourceType::JSON));
requestReportEngineSettings->setDataSourceName(std::make_shared< std::wstring >(L"persons"));

std::shared_ptr< requests::BuildReportOnlineRequest > buildReportRequest(
    new requests::BuildReportOnlineRequest(
        requestTemplateStream, std::make_shared< std::wstring >(L"Data.json"), requestReportEngineSettings
    )
);
wordsApi->buildReportOnline(buildReportRequest);