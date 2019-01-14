#include "TestBase.h"
#include "../model/FormFieldTextInput.h"
#include <string>
#include <iostream>
#include <regex>

class ConfigurationTest : public InfrastructureTest {
protected:
	utility::string_t dataFolder = STCONVERT("BaseApiTest");
};

///Checks that debug message is writing when debug mode is turned on
TEST_F(ConfigurationTest, TestDebugMode) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestDebugMode.docx"),
		fullName = path_combine(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	auto client = get_client();
	auto newConfig = get_config();
	newConfig->setDebugMode(true);
	client->setConfiguration(newConfig);
	shared_ptr<WordsApi> api(new WordsApi(client));
	
	shared_ptr<DeleteFieldsRequest> request(new DeleteFieldsRequest(remoteName, dataFolder, boost::none, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	UploadFileToStorage(fullName, filePath);

	utility::stringstream_t ss;
	std::wstreambuf *outbuf = ucout.rdbuf(ss.rdbuf());

	api->deleteFields(request).get();

	ucout.rdbuf(outbuf);
	utility::string_t res = ss.str(),
		fwSlash = STCONVERT("/"),
		expectedUri = STCONVERT("DELETE: ") +
						fwSlash + newConfig->getApiVersion() + fwSlash + STCONVERT("words") +
						fwSlash + remoteName + fwSlash + STCONVERT("fields"),
		expectedResponseHeader = STCONVERT("Response 200: OK"),
		expectedResponseBody = STCONVERT("{\"Code\":200,\"Status\":\"OK\"}");

	ASSERT_TRUE(res.find(expectedUri) != std::string::npos);

	ASSERT_TRUE(res.find(expectedResponseHeader) != std::string::npos);

	ASSERT_TRUE(res.find(expectedResponseBody) != std::string::npos);

}

///Checks that API version is properly applied to path building
TEST_F(ConfigurationTest, TestVersionIsUsing) {
	utility::string_t localName = STCONVERT("test_multi_pages.docx"),
		remoteName = STCONVERT("TestVersionIsUsing.docx"),
		fullName = path_combine(dataFolder, remoteName),
		filePath = path_combine(get_data_dir(commonFolder), localName);

	auto client = get_client();
	auto newConfig = get_config();
	newConfig->setDebugMode(true);
	newConfig->setApiVersion(STCONVERT("v2"));

	client->setConfiguration(newConfig);
	shared_ptr<WordsApi> api(new WordsApi(client));

	shared_ptr<DeleteFieldsRequest> request(new DeleteFieldsRequest(remoteName, dataFolder, boost::none, boost::none,
		boost::none, boost::none, boost::none, boost::none, boost::none));

	UploadFileToStorage(fullName, filePath);

	std::wstringstream ss;
	std::wstreambuf *outbuf = ucout.rdbuf(ss.rdbuf());

	api->deleteFields(request).get();

	ucout.rdbuf(outbuf);
	utility::string_t res = ss.str(),
		fwSlash = STCONVERT("/"),
		expectedUri = STCONVERT("DELETE: ") +
		fwSlash + newConfig->getApiVersion() + fwSlash + STCONVERT("words") +
		fwSlash + remoteName + fwSlash + STCONVERT("fields"),
		expectedResponseHeader = STCONVERT("Response 200: OK"),
		expectedResponseBody = STCONVERT("{\"Code\":200,\"Status\":\"OK\"}");

	ASSERT_TRUE(res.find(expectedUri) != std::string::npos);

	ASSERT_TRUE(res.find(expectedResponseHeader) != std::string::npos);

	ASSERT_TRUE(res.find(expectedResponseBody) != std::string::npos);

}

class BaseApiTest : public InfrastructureTest {

};
/// <summary>
/// If file does not exist, 400 response should be returned with message "Error while loading file ".
/// </summary>
TEST_F(BaseApiTest, TestHandleErrors) {
	utility::string_t name = STCONVERT("noFileWithThisName.docx");

	try {
		std::shared_ptr<GetSectionsRequest> request(new GetSectionsRequest(name, boost::none, boost::none, boost::none, boost::none));
		auto response = get_api()->getSections(request).wait();

		ASSERT_FALSE(true) << STCONVERT("Expected exception has not been thrown");
	}
	catch (ApiException& exception) {
		ASSERT_EQ(400, exception.error_code().value()) << "Exception code is not equals to 400";
		std::string message((std::istreambuf_iterator<char>(*(exception.getContent()))), std::istreambuf_iterator<char>());
		web::json::value actual = web::json::value::parse(STCONVERT(message));
		ucout << STCONVERT(message) << "====" << std::endl;
		ASSERT_TRUE(actual.has_field(STCONVERT("Message")));
		ASSERT_EQ(STCONVERT("Error while loading file 'noFileWithThisName.docx' from storage:"),
			actual[STCONVERT("Message")].as_string().substr(0, 64)) << "Wrong message: " << message;
	}
}
/// <summary>
/// Check if all API methods have covered by tests
/// </summary>
TEST_F(BaseApiTest, TestApiCoverage) {
	utility::string_t sdkRoot = get_executable_path();
	auto rootParts = split(sdkRoot);
	rootParts.pop_back();
	rootParts.pop_back();
	rootParts.pop_back();
	utility::string_t testsPath = join(rootParts) + STCONVERT("\\tests");
	utility::string_t apiPath = join(rootParts) + STCONVERT("\\sources\\api\\WordsApi.h");

	utility::string_t apiCode = get_file_text(apiPath);
	std::string apiCode_str(apiCode.begin(), apiCode.end());
	std::vector<utility::string_t> apiMethods;
	std::smatch match;
	std::regex regEx(">> (.*)\\(");
	while (std::regex_search(apiCode_str, match, regEx)) {
		apiMethods.push_back(STCONVERT(match[1].str()));
		apiCode_str = match.suffix().str();
	}

	std::vector<utility::string_t> files = get_directory_files(testsPath);
	utility::string_t testsCode;
	for (auto file : files)
		testsCode += get_file_text(file);

	vector<utility::string_t> uncoveredMethods;
	for (auto method : apiMethods) {
		size_t pos = testsCode.find(STCONVERT("->") + method + STCONVERT("("), 0);
		if (pos == wstring::npos) {
			uncoveredMethods.push_back(method);
		}
	}
	ASSERT_EQ(0, uncoveredMethods.size()) << "Found uncovered methods: " << std::endl << join(uncoveredMethods, STCONVERT("\n"));

}

TEST_F(InfrastructureTest, OAuthTest)
{
	std::shared_ptr<ApiClient> client = get_client();
	client->requestToken().wait();
	ASSERT_TRUE(true);
}

#pragma region Upload To Storage Tests
class StorageApiTest : public InfrastructureTest {
protected:
	utility::string_t get_data_folder() override {
		return path_combine_url(STCONVERT("Temp\\SdkTests\\TestData"), STCONVERT("DocumentElements\\Bookmarks"));
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

	ASSERT_TRUE(GetIsExists(remoteName));
}

TEST_F(StorageApiTest, TestIsNotExists) {
	ASSERT_FALSE(GetIsExists(STCONVERT("NoSuchFile.ext")));
}
#pragma endregion
