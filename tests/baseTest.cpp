/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="baseTest.cpp">
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

#include <gmock/gmock.h>
#include <boost/filesystem.hpp>

using ::testing::AllOf;
using ::testing::HasSubstr;

#include <string>
#include <iostream>
#include <regex>

namespace fs = boost::filesystem;

class ConfigurationTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = STCONVERT("BaseApiTest");
};

///Checks that debug message is writing when debug mode is turned on
TEST_F(ConfigurationTest, TestDebugMode) {
    fs::path filePath = get_data_dir(commonFolder) / "test_multi_pages.docx";
    auto remoteName = STCONVERT("TestDebugMode.docx");
    utility::string_t fullName = path_combine(dataFolder, remoteName);

	auto client = get_client();
	auto newConfig = get_config();
	newConfig->setDebugMode(true);
    std::shared_ptr<WordsApi> api= std::make_shared<WordsApi>(client);
    std::shared_ptr<DeleteFieldsRequest> request= std::make_shared<DeleteFieldsRequest>(remoteName, dataFolder, boost::none, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);

	UploadFileToStorage(fullName, filePath);

	utility::stringstream_t ss;
    auto outbuf = ucout.rdbuf(ss.rdbuf());
    client->setConfiguration(newConfig);

	std::shared_ptr<AsposeResponse> response;
	response = api->deleteFields(request).get();

	utility::string_t res = ss.str(),
		fwSlash = _XPLATSTR("/"),
		expectedUri = _XPLATSTR("DELETE: ") +
						fwSlash + newConfig->getApiVersion() + fwSlash + _XPLATSTR("words") +
						fwSlash + remoteName + fwSlash + _XPLATSTR("fields"),
		expectedResponseHeader = _XPLATSTR("Response 200: OK");

    ucout.rdbuf(outbuf);

	EXPECT_THAT(res, AllOf(HasSubstr(expectedUri), HasSubstr(expectedResponseHeader)));
	EXPECT_EQ(200, response->getCode());
}

///Checks that API version is properly applied to path building
TEST_F(ConfigurationTest, TestVersionIsUsing) {
    utility::string_t localName = _XPLATSTR("test_multi_pages.docx");
    utility::string_t remoteName = _XPLATSTR("TestVersionIsUsing.docx");
    utility::string_t fullName = path_combine(dataFolder, remoteName);
    utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);


    auto client = get_client();
	auto newConfig = get_config();
	newConfig->setDebugMode(true);
	newConfig->setApiVersion(_XPLATSTR("v2"));

    std::shared_ptr<WordsApi> api= std::make_shared<WordsApi>(client);

    std::shared_ptr<DeleteFieldsRequest> request= std::make_shared<DeleteFieldsRequest>(remoteName, dataFolder, boost::none, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none);
	ucout << "Uploading";
	UploadFileToStorage(fullName, filePath);

	utility::stringstream_t ss;
	streambuf_t* outbuf = ucout.rdbuf(ss.rdbuf());
    client->setConfiguration(newConfig);
	
	std::shared_ptr<AsposeResponse> response;
	response = api->deleteFields(request).get();

	utility::string_t res = ss.str(),
		fwSlash = _XPLATSTR("/"),
		expectedUri = _XPLATSTR("DELETE: ") +
		fwSlash + newConfig->getApiVersion() + fwSlash + _XPLATSTR("words") +
		fwSlash + remoteName + fwSlash + _XPLATSTR("fields"),
		expectedResponseHeader = _XPLATSTR("Response 200: OK");
    ucout.rdbuf(outbuf);

    EXPECT_THAT(res, AllOf(HasSubstr(expectedUri), HasSubstr(expectedResponseHeader)));
	EXPECT_EQ(200, response->getCode());
}

class BaseApiTest : public InfrastructureTest {

};
/// <summary>
/// If file does not exist, 400 response should be returned with message "Error while loading file ".
/// </summary>
TEST_F(BaseApiTest, TestHandleErrors) {
	utility::string_t name = _XPLATSTR("noFileWithThisName.docx");

	try {
		auto request= std::make_shared<GetSectionsRequest>(name, boost::none, boost::none, boost::none, boost::none);
		auto response = get_api()->getSections(request).wait();
		FAIL() << "Expected exception has not been thrown";
	}
	catch (ApiException& exception) {
		ASSERT_EQ(400, exception.error_code().value()) << "Exception code is not equals to 400";
		std::string message((std::istreambuf_iterator<char>(*(exception.getContent()))), std::istreambuf_iterator<char>());
		web::json::value actual = web::json::value::parse(STCONVERT(message));
		ASSERT_TRUE(actual.has_field(_XPLATSTR("Message")));
		EXPECT_THAT(actual[_XPLATSTR("Message")].as_string(), HasSubstr(_XPLATSTR("Error while loading file 'noFileWithThisName.docx' from storage:")));
	}
}

/// <summary>
/// Check if all API methods have covered by tests
/// This test requires structure of folders so it is skiiped if WordsApi.h isn't found
/// </summary>
TEST_F(BaseApiTest, TestApiCoverage) {
	fs::path sdkRoot = get_sdk_root();
	auto testsPath = sdkRoot.parent_path() / "tests";
	auto apiPath = sdkRoot.parent_path() / "sources" / "api" / "WordsApi.h";

	if (fs::exists(apiPath))
	{
		auto apiCode = get_file_text(apiPath);
		std::string apiCode_str(apiCode.begin(), apiCode.end());
		std::vector<std::string> apiMethods;
		std::smatch match;
		std::regex regEx(">> (.*)\\(");
		while (std::regex_search(apiCode_str, match, regEx)) {
			apiMethods.push_back(match[1].str());
			apiCode_str = match.suffix().str();
		}

		auto files = get_directory_files(testsPath);
		utility::string_t testsCode;
		for (auto file : files)
		{
			if (file.extension() == ".cpp")
			{
				testsCode += get_file_text(file);
			}
		}

		for (const auto& method : apiMethods) {
			EXPECT_THAT(testsCode, HasSubstr(STCONVERT("->") + STCONVERT(method) + _XPLATSTR('('))) << " Uncovered method";
		}
	}
}

TEST_F(InfrastructureTest, OAuthTest)
{
	std::shared_ptr<ApiClient> client = get_client();
	client->requestToken().wait();	 	// ApiException will be thrown if something goes wrong
}

#pragma region Upload To Storage Tests
class StorageApiTest : public InfrastructureTest {
protected:
	utility::string_t get_data_folder() override {
        return _XPLATSTR("Temp\\SdkTests\\TestData\\DocumentElements\\Bookmarks");
	}
};

TEST_F(StorageApiTest, UploadToStorageTestPNG) {
	utility::string_t localName = STCONVERT("Aspose Logo.png"),
		remoteName = STCONVERT("AsposeLogo.png"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);
}

TEST_F(StorageApiTest, UploadToStorageTestDOCX) {
	utility::string_t localName = STCONVERT("test_doc.docx"),
		remoteName = STCONVERT("TestDoc.docx"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);
}

TEST_F(StorageApiTest, TestIsExists) {
	utility::string_t localName = STCONVERT("test_doc.docx"),
		remoteName = STCONVERT("TestDoc.docx"),
		fullName = path_combine(get_data_folder(), remoteName);
	utility::string_t filePath = path_combine(get_data_dir(commonFolder), localName);

	UploadFileToStorage(fullName, filePath);

	ASSERT_TRUE(GetIsExists(fullName));
}

TEST_F(StorageApiTest, TestIsNotExists) {
	ASSERT_FALSE(GetIsExists(STCONVERT("NoSuchFile.ext")));
}
#pragma endregion
