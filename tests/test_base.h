/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="test_base.h">
*   Copyright (c) 2026 Aspose.Words for Cloud
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
#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "aspose_words_cloud.h"

using namespace aspose::words::cloud;

class InfrastructureTest : public ::testing::Test
{
protected:
    static std::wstring getSdkRoot();

    std::wstring localTestDataFolder = getSdkRoot() + L"/test_data";

    std::shared_ptr<ApiConfiguration> getConfig();

    std::wstring getDataDir(const std::wstring& subfolder) const;
    std::wstring createRandomGuid() const;
    std::string getFileText(const std::wstring& file);
    std::wstring getFileTextUtf16(const std::wstring& file);
    void uploadFileToStorage(const std::wstring& localPath, const std::wstring& remotePath);

public:
    std::shared_ptr<api::WordsApi> getApi();

protected:
    const std::wstring baseTestOutPath = L"TestOut/Cpp";
    const std::wstring commonFolder = L"Common";

#ifdef _WIN32
    const std::wstring remoteBaseTestDataFolder = L"Temp/SdkTests/Cpp/Windows/TestData";
#else
    const std::wstring remoteBaseTestDataFolder = L"Temp/SdkTests/Cpp/Linux/TestData";
#endif
};
