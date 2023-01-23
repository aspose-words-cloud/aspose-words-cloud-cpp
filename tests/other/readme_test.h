/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="readme_test.h">
*   Copyright (c) 2023 Aspose.Words for Cloud
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
#include <list>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <filesystem>

/// <summary>
/// README.md code test
/// </summary>
class ReadmeTest : public InfrastructureTest {
protected:
    const std::wstring dataFolder = remoteBaseTestDataFolder + L"/Readme";
    void writeCodeToReadme();
};

/// <summary>
/// Test for getting range text
/// </summary>
TEST_F(ReadmeTest, TestReadmeCode) {
    auto remoteName = std::make_shared<std::wstring>(L"ReadmeCode.docx");
    auto remoteDir = std::make_shared<std::wstring>(dataFolder);
    auto remotePath = std::make_shared<std::wstring>(*remoteDir + L"/" + *remoteName);
    auto localPath = getDataDir(commonFolder) + L"/test_multi_pages.docx";

    // get config settings
    auto tesConfig = getConfig();
    auto yourClientId = tesConfig->getClientId();
    auto yourClientSecret = tesConfig->getClientSecret();
    auto baseUrl = tesConfig->getBaseUrl();

    // Start README example
    using namespace aspose::words::cloud;

    // Create client configuration
    auto config = std::make_shared<ApiConfiguration>(yourClientId, yourClientSecret, /*optional*/baseUrl);

    // Create API
    auto api = std::make_shared<api::WordsApi>(config);

    // Read file content
    auto stream = std::shared_ptr<std::istream>(new std::ifstream(std::filesystem::path(localPath), std::ifstream::binary));

    // upload file
    auto uploadRequest = std::shared_ptr<requests::UploadFileRequest>(
        new requests::UploadFileRequest(stream, remotePath)
    );
    auto uploadResult = api->uploadFile(uploadRequest);

    // call one of API methods
    auto request = std::shared_ptr<requests::GetSectionsRequest>(
        new requests::GetSectionsRequest(remoteName, remoteDir)
    );
    auto response = api->getSections(request);
    auto sections = response->getSections();

    // End README example

    writeCodeToReadme();
}

void ReadmeTest::writeCodeToReadme() {
    // set regex patterns
    auto startPatern = R"(^\s*// Start README example\s*$)";
    auto endPattern = R"(^\s*// End README example\s*$)";

    // set paths
    std::filesystem::path readmePath(getSdkRoot() + L"/README.md");
    std::filesystem::path sourcePath(getSdkRoot() + L"/tests/other/readmeTest.cpp");

    // read test code
    std::list<std::string> codeLines;
    std::ifstream testFile(sourcePath);
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
    std::ifstream readmeFile(readmePath);
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
