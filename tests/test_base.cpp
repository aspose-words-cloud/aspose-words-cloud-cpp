/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="test_base.cpp">
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

#include <filesystem>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include "./test_base.h"
#include "../thirdparty/json.hpp"

std::shared_ptr<ApiConfiguration> InfrastructureTest::getConfig()
{
    std::wstring credentials;
    InfrastructureTest::getFileText(getSdkRoot() + L"/settings/servercreds.json", credentials);

    auto fileJson = ::nlohmann::json::parse(credentials);
    return std::make_shared<ApiConfiguration>(
        fileJson["ClientId"].get<std::wstring>(),
        fileJson["ClientSecret"].get<std::wstring>(),
        fileJson["BaseUrl"].get<std::wstring>()
    );
}

void InfrastructureTest::SetUp()
{
    m_Config = getConfig();
}

std::wstring InfrastructureTest::getSdkRoot()
{
    return std::filesystem::current_path().wstring();
}

std::wstring InfrastructureTest::getDataDir(const std::wstring& subfolder) const
{
    return localTestDataFolder + L"/" + subfolder;
}

std::wstring InfrastructureTest::createRandomGuid() const
{
    static std::random_device dev;
    static std::mt19937 rng(dev());

    std::uniform_int_distribution<int> dist(0, 15);

    const wchar_t* v = L"0123456789abcdef";
    const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

    std::wstring res;
    for (int i = 0; i < 16; i++) {
        if (dash[i]) res += L"-";
        res += v[dist(rng)];
        res += v[dist(rng)];
    }
    return res;
}

void InfrastructureTest::getFileText(const std::wstring& file, std::wstring& result)
{
    std::wifstream fileStream(file);
    if (!fileStream.good())
    {
        throw L"Failed to open file: " + file;
    }

    std::wstringstream buffer;
    buffer << fileStream.rdbuf();
    result = buffer.str();
}

void InfrastructureTest::uploadFileToStorage(const std::wstring& localPath, const std::wstring& remotePath)
{
    //std::shared_ptr<UploadFileRequest> request = std::make_shared<UploadFileRequest>(generate_http_content_from_file(filePath), remoteName);
    //std::shared_ptr<WordsApi> api = get_api();
    //auto result = api->uploadFile(request).get();
}

std::shared_ptr<ApiConfiguration> InfrastructureTest::getConfiguration() const
{
    return m_Config;
}

std::shared_ptr<api::WordsApi> InfrastructureTest::getApi()
{
    if (!m_wordsApi)
    {
        m_wordsApi = std::make_shared<api::WordsApi>(getConfiguration());
    }
    return m_wordsApi;
}
