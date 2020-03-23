/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestBase.cpp">
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

#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

utility::string_t get_file_text_as_string(const fs::path& file)
{
#ifdef _UTF16_STRINGS
	using ifstream_t = fs::wifstream;
#else
	using ifstream_t = fs::ifstream;
#endif

	ifstream_t fileStream{ file };

	if (!fileStream.is_open())
	{
		return nullptr;
	}

	utility::stringstream_t buffer;
	buffer << fileStream.rdbuf();
	return buffer.str();
}


std::shared_ptr<ApiConfiguration> get_config()
{
	utility::string_t credentials;
	credentials = get_file_text_as_string({ fs::path{ TEST_ROOT }.parent_path() / "servercreds.json" });
	web::json::value fileJson = web::json::value::parse(credentials);

	web::http::client::http_client_config conf;
	conf.set_timeout(std::chrono::seconds(60));

	auto newConfig = std::make_shared<ApiConfiguration>();
	newConfig->setAppKey(fileJson[_XPLATSTR("AppKey")].as_string());
	newConfig->setBaseUrl(fileJson[_XPLATSTR("BaseUrl")].as_string());
	newConfig->setAppSid(fileJson[_XPLATSTR("AppSid")].as_string());
	newConfig->setUserAgent(_XPLATSTR("CppAsposeClient"));
	newConfig->setHttpConfig(conf);

	return newConfig;
}

fs::path InfrastructureTest::get_sdk_root()
{
    return fs::path{TEST_ROOT}.normalize();
}

utility::string_t InfrastructureTest::get_data_folder()
{
    return {};
}

utility::string_t InfrastructureTest::path_combine(const fs::path& base, const utility::string_t& stringToAdd)
{
    return utility::conversions::to_string_t((base / stringToAdd).generic_string());
}

utility::string_t InfrastructureTest::path_combine_url(const utility::string_t& base, const utility::string_t& stringToAdd)
{
	return base + _XPLATSTR("/") + stringToAdd;
}

utility::string_t InfrastructureTest::cutFileExtension(const boost::filesystem::path& filename)
{
    return utility::conversions::to_string_t(filename.stem().generic_string());
}

fs::path InfrastructureTest::get_data_dir(const fs::path& subfolder) const
{
    return LocalTestDataFolder / fs::path{subfolder};
}

std::shared_ptr<HttpContent> InfrastructureTest::generate_http_content_from_file(const fs::path& filePath,
	const utility::string_t& filename, const utility::string_t& contentType)
{
    if (!fs::exists(filePath))
    {
        ucerr << _XPLATSTR("Cannot open file ") << filePath << _XPLATSTR(" to upload\n");
    }

    auto content = std::make_shared<HttpContent>();
	auto stream = std::make_shared<fs::ifstream>(filePath, std::ifstream::binary);
	content->setData(stream);
	content->setContentDisposition(_XPLATSTR("form-data"));

	content->setContentType(contentType);

	if (!filename.empty())
		content->setFileName(filename);

	return content;
}

utility::string_t InfrastructureTest::get_file_text(const fs::path& file)
{
	return get_file_text_as_string(file);
}

std::vector<fs::path> InfrastructureTest::get_directory_files(const boost::filesystem::path& dir)
{
    const auto dirIterator = fs::directory_iterator{dir};
    std::vector<fs::path> result;

    std::transform(begin(dirIterator), end(dirIterator), std::back_inserter(result),
        [](const fs::directory_entry& entry)
    {
        return entry.path();
    });

    return result;
}

void InfrastructureTest::UploadFileToStorage(const utility::string_t& remoteName, const fs::path& filePath)
{
	std::shared_ptr<UploadFileRequest> request = std::make_shared<UploadFileRequest>(generate_http_content_from_file(filePath), remoteName, boost::none);

	auto newConfig = get_config();
	newConfig->setDebugMode(true);
	std::shared_ptr<WordsApi> api = std::make_shared<WordsApi>(newConfig);

	auto result = api->uploadFile(request).get();
}


bool InfrastructureTest::DoesFileExist(const utility::string_t& remoteName)
{
	try
	{
		std::shared_ptr<DownloadFileRequest> request = std::make_shared<DownloadFileRequest>(remoteName, boost::none, boost::none);
		get_api()->downloadFile(request).get();
		return true;
	}
	catch (ApiException& exception)
	{
		if (exception.error_code().value() == 404)
			return false;
		throw;
	}
}

std::shared_ptr<ApiConfiguration> InfrastructureTest::get_configuration() const
{
	return m_Config;
}

std::shared_ptr<ApiClient> InfrastructureTest::get_client()
{
	if (!client) {
		client = std::make_shared<ApiClient>();
		client->setConfiguration(get_configuration());
	}
	return client;
}

std::shared_ptr<WordsApi> InfrastructureTest::get_api()
{
	if (!api)
	{
		api = std::make_shared<WordsApi>(get_configuration());
	}
	return api;
}