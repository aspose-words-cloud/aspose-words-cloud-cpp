/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReadmeTest.cpp">
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

#include "TestBase.h"
#include <list>
#include <fstream>
#include <regex>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

/// <summary>
/// README.md code test
/// </summary>
class ReadmeTest : public InfrastructureTest {
protected:
	const std::wstring dataFolder = path_combine_url(remoteBaseTestDataFolder, STCONVERT("Readme"));
	void WriteCodeToReadme();
};

/// <summary>
/// Test for getting range text
/// </summary>
TEST_F(ReadmeTest, TestReadmeCode) {
	auto remoteName = STCONVERT("ReadmeCode.docx");
	auto remotePath = path_combine_url(dataFolder, remoteName);
	auto localPath = path_combine(get_data_dir(commonFolder), STCONVERT("test_multi_pages.docx"));

	// get config settings
	auto tesConfig = get_config();
	auto yourClientId = tesConfig->getClientId();
	auto yourClientSecret = tesConfig->getClientSecret();
	auto baseUrl = tesConfig->getBaseUrl();

	// Start README example

	//  create client configuration
	auto config = std::make_shared<ApiConfiguration>(yourClientId, yourClientSecret);
	// optional step, default value is https://api.aspose.cloud
	config->setBaseUrl(baseUrl);

	// create API
	auto api = std::make_shared<WordsApi>(config);

	// read file content
	auto content = std::make_shared<HttpContent>();
	auto stream = std::make_shared<fs::ifstream>(localPath, std::ifstream::binary);
	content->setData(stream);
	content->setContentDisposition(_XPLATSTR("form-data"));

	// upload file
	std::shared_ptr<UploadFileRequest> uploadRequest = std::make_shared<UploadFileRequest>(content, remotePath, std::none);
	api->uploadFile(uploadRequest).get();

	// call one of API methods
	auto request = std::make_shared<GetSectionsRequest>(remoteName, dataFolder, std::none, std::none, std::none);
	auto response = api->getSections(request).get();
	auto sections = response.body->getSections();

	// End README example

	WriteCodeToReadme();
}

void ReadmeTest::WriteCodeToReadme() {
	// set regex patterns
	auto startPatern = R"(^\s*// Start README example\s*$)";
	auto endPattern = R"(^\s*// End README example\s*$)";

	// set paths
	fs::path readmePath = { fs::path{ TEST_ROOT }.parent_path() / "README.md" };
	fs::path sourcePath = { fs::path{ TEST_ROOT } / "readmeTest.cpp" };

	// read test code
	std::list<std::string> codeLines;
	std::ifstream testFile(sourcePath.string());
	std::string s;
	while (std::getline(testFile, s)) codeLines.push_back(s);
	testFile.close();

	// extract readme code
	std::list<std::string> readmeCode;
	bool skipMode = true;
	for (const auto& line : codeLines)
	{
		if (skipMode)
		{
			skipMode = !std::regex_match(line, std::regex(startPatern));
		}

		if (!skipMode)
		{
			readmeCode.push_back(line);
			skipMode = std::regex_match(line, std::regex(endPattern));
		}
	}

	// read readme.md
	std::list<std::string> readmeLines;
	std::ifstream readmeFile(readmePath.string());
	while (std::getline(readmeFile, s)) readmeLines.push_back(s);
	readmeFile.close();

	// replace code in readme.md
	std::list<std::string> newReadmeLines;
	bool codeMode = false;
	for (const auto& line : readmeLines)
	{
		if (!codeMode)
		{
			codeMode = std::regex_match(line, std::regex(startPatern));

			if (codeMode)
			{
				for (const auto& codeLine : readmeCode) newReadmeLines.push_back(codeLine);
			}
		}

		if (codeMode)
		{
			codeMode = !std::regex_match(line, std::regex(endPattern));
			continue;
		}

		if(!codeMode)
		{
			newReadmeLines.push_back(line);
		}
	}

	// write to readme.md
	std::ofstream readmeOutputFile(readmePath.string());
	for (const auto& line : newReadmeLines) readmeOutputFile << line << "\n";
	readmeOutputFile.close();
}
