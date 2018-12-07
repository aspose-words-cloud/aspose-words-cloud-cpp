#include "TestBase.h"



std::shared_ptr<ApiConfiguration> get_config()
{
	ifstream fileStream("servercreds.json");
	std::shared_ptr<ApiConfiguration> config(new ApiConfiguration);

	if (!fileStream.is_open())
	{
		cout << "File is not open" << endl;
		return nullptr;
	}
	string lines, line;
	while (getline(fileStream, line))
	{
		lines += line;
	}
	web::json::value fileJson = web::json::value::parse(utility::conversions::to_string_t(lines));
	config.reset(new ApiConfiguration);

	config->setAppKey(fileJson[L"AppKey"].as_string());
	config->setBaseUrl(fileJson[L"BaseUrl"].as_string());
	config->setAppSid(fileJson[L"AppSid"].as_string());
	config->setUserAgent(STCONVERT("CppAsposeClient"));
	config->setApiVersion(STCONVERT("v1"));

	web::http::client::http_client_config conf;

	conf.set_timeout(chrono::seconds(60));
	config->setHttpConfig(conf);

	return config;
}

vector<utility::string_t> split(utility::string_t stringToSplit)
{
	vector<utility::string_t> parts;
	utility::string_t temp;
	wstringstream wss(stringToSplit);
	while (getline(wss, temp, L'\\'))
	{
		parts.push_back(temp);
	}
	return parts;
}

utility::string_t join(vector<utility::string_t> parts, utility::string_t delim)
{
	utility::string_t str;

	for (vector<utility::string_t>::iterator it = parts.begin(); it != parts.end(); ++it)
	{
		str += *it + delim;
	}

	return str.substr(0, str.size() - 1);
}

utility::string_t cutFileExtension(utility::string_t filename)
{
	return filename.substr(0, filename.find(L'.'));
}

utility::string_t InfrastructureTest::get_sdk_root()
{
	utility::string_t workingDir = STCONVERT(_getcwd(nullptr, 0));
	vector<utility::string_t> dirParts = split(workingDir);
	size_t lastIndex = dirParts.size() - 1;
	while (dirParts[lastIndex--] != STCONVERT("tests"))
	{
		dirParts.pop_back();
	}
	dirParts.pop_back();

	return join(dirParts);
}
utility::string_t InfrastructureTest::get_data_folder()
{
	return STCONVERT("");
}
utility::string_t InfrastructureTest::path_combine(utility::string_t base, utility::string_t stringToAdd)
{
	return base + STCONVERT("/") + stringToAdd;
}
utility::string_t InfrastructureTest::path_combine_url(utility::string_t base, utility::string_t stringToAdd)
{
	return base + STCONVERT("\\") + stringToAdd;
}

utility::string_t InfrastructureTest::get_data_dir(utility::string_t subfolder)
{
	return path_combine(LocalTestDataFolder, subfolder);
}

std::shared_ptr<HttpContent> InfrastructureTest::generate_http_content_from_file(utility::string_t filePath,
	utility::string_t filename, utility::string_t contentType)
{
	ifstream checkStream(filePath);
	if (!checkStream.good())
		throw STCONVERT("Cannot open file ") + filePath + STCONVERT(" to upload");
	checkStream.close();

	std::shared_ptr<HttpContent> content(new HttpContent);
	std::shared_ptr<istream> stream(new ifstream(filePath, std::ifstream::binary));
	content->setData(stream);
	content->setContentDisposition(STCONVERT("form-data"));

	content->setContentType(contentType);

	if (!filename.empty())
		content->setFileName(filename);

	return content;
}

utility::string_t InfrastructureTest::get_file_text(utility::string_t file)
{
	std::ifstream fileStream(file);
	utility::string_t s((std::istreambuf_iterator<char>(fileStream)),
		std::istreambuf_iterator<char>());
	return s;
}

void InfrastructureTest::UploadFileToStorage(utility::string_t path, utility::string_t filePath)
{

	std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;
	map<utility::string_t, utility::string_t> queryParams, headerParams, formParams;
	std::shared_ptr<HttpContent> fileToUpload = generate_http_content_from_file(filePath);
	fileParams.push_back(std::make_pair(STCONVERT("file"), fileToUpload));
	queryParams[utility::conversions::to_string_t("path")] = path;

	std::shared_ptr<ApiClient> client = get_client();
	client->callApi(client->getConfiguration()->getBaseUrl() + L"/v1.1/storage/file",
		L"PUT", queryParams, nullptr, headerParams, formParams, fileParams, L"multipart/form-data")
		.then([=](web::http::http_response response) {
		if (response.status_code() >= 400)
			throw ApiException(response.status_code(), utility::conversions::to_string_t("error requesting token: ") + response.reason_phrase(), std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
	})
		.wait();
	//else
	//{
	//cout << "Unable to open file";
	//throw L"Unable to find " + filePath;
	//}
}


bool InfrastructureTest::GetIsExists(utility::string_t path)
{

	std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;
	map<utility::string_t, utility::string_t> queryParams, headerParams, formParams;
	queryParams[utility::conversions::to_string_t("path")] = path;

	std::shared_ptr<ApiClient> client = get_client();
	return (client->callApi(client->getConfiguration()->getBaseUrl() + L"/v1.1/storage/exist",
		L"GET", queryParams, nullptr, headerParams, formParams, fileParams, L"application/json")
		.then([=](web::http::http_response response) {
		if (response.status_code() >= 400)
			throw ApiException(response.status_code(), utility::conversions::to_string_t("error requesting token: ") + response.reason_phrase(), std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		return response.extract_json();
	}).then([=](web::json::value ans) {
		
		return ans.has_field(STCONVERT("FileExist")) && 
			ans[STCONVERT("FileExist")][STCONVERT("IsExist")].as_bool();
	}).get());
}

std::shared_ptr<ApiConfiguration> InfrastructureTest::get_configuration()
{
	return m_Config;
}
std::shared_ptr<ApiClient> InfrastructureTest::get_client()
{
	if (client == nullptr) {
		client.reset(new ApiClient);
		client->setConfiguration(get_configuration());
	}
	return client;
}
std::shared_ptr<WordsApi> InfrastructureTest::get_api()
{
	if (api == nullptr)
	{
		api.reset(new WordsApi(get_client()));
	}
	return api;
}