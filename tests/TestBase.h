/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestBase.h">
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

#ifndef TEST_BASE
#define TEST_BASE

#include <gtest/gtest.h>
#include "WordsApi.h"

#define STCONVERT(s) utility::conversions::to_string_t(s)

using streambuf_t = std::basic_streambuf<utility::char_t>;

using namespace aspose::words::cloud::api;

std::shared_ptr<ApiConfiguration> get_config();

template<typename T>
bool IsNotNull(std::vector<T> vector) { return true; }

template<typename T>
bool IsNotNull(std::shared_ptr<T> ptr) { return bool(ptr); }

class InfrastructureTest : public ::testing::Test
{
protected:
    static std::filesystem::path get_sdk_root();

    std::filesystem::path LocalTestDataFolder{get_sdk_root()/"TestData"};

    virtual std::wstring get_data_folder();

	void SetUp() override
    {
		m_Config = get_config();
	};
    static std::wstring path_combine(const std::filesystem::path& base, const std::wstring& stringToAdd);
    static std::wstring path_combine_url(const std::wstring& base, const std::wstring& stringToAdd);
    static std::wstring cutFileExtension(const std::filesystem::path& filename);
    std::filesystem::path get_data_dir(const std::filesystem::path& subfolder) const;

    std::wstring create_random_guid() const;

    static std::shared_ptr<HttpContent> generate_http_content_from_file(const std::filesystem::path& filePath,
        const std::wstring& filename = {}, const std::wstring& contentType = {});

    static std::wstring get_file_text(const std::filesystem::path& file);

    static std::vector<std::filesystem::path> get_directory_files(const std::filesystem::path& dir);

public:
	void UploadFileToStorage(const std::wstring& path, const std::filesystem::path& filePath);
	bool DoesFileExist(const std::wstring& path);

public:
	std::shared_ptr<ApiConfiguration> get_configuration() const;
	std::shared_ptr<WordsApi> get_api();

protected:
    const std::wstring baseTestOutPath{_XPLATSTR("TestOut/Cpp")};
    const std::wstring remoteBaseTestDataFolder{_XPLATSTR("Temp/SdkTests/Cpp/TestData")};
    const std::filesystem::path commonFolder{"Common"};

private:
	std::shared_ptr<ApiClient> client;
	std::shared_ptr<WordsApi> api;
	std::shared_ptr<ApiConfiguration> m_Config;
};
#endif
