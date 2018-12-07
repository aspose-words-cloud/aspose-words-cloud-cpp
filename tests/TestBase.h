#ifndef TEST_BASE
#define TEST_BASE
#include <gtest/gtest.h>
#include "WordsApi.h"

#if defined (__WIN32__) || defined(_WIN32)
#include <Windows.h>
#endif

#if defined (__unix__)
#include <dirent.h>
#endif

#define STCONVERT(s) utility::conversions::to_string_t(s)

using namespace io::swagger::client::api;
using namespace std;
std::shared_ptr<ApiConfiguration> get_config();

const std::shared_ptr<ApiConfiguration> config = get_config();

vector<utility::string_t> split(utility::string_t stringToSplit);

utility::string_t join(vector<utility::string_t> parts, utility::string_t delim = STCONVERT("\\"));

utility::string_t cutFileExtension(utility::string_t filename);

class InfrastructureTest : public ::testing::Test
{
protected:
	utility::string_t LocalTestDataFolder = path_combine(get_sdk_root(), STCONVERT("tests\\TestData"));

	utility::string_t get_sdk_root();
	utility::string_t virtual get_data_folder();

	void SetUp()
	{
		m_Config = config;
	};
	utility::string_t path_combine(utility::string_t base, utility::string_t stringToAdd);
	utility::string_t path_combine_url(utility::string_t base, utility::string_t stringToAdd);
	utility::string_t get_data_dir(utility::string_t subfolder);

	std::shared_ptr<HttpContent> generate_http_content_from_file(utility::string_t filePath,
		utility::string_t filename = STCONVERT(""), utility::string_t contentType = STCONVERT(" "));

	utility::string_t get_file_text(utility::string_t file);

	utility::string_t get_executable_path() {
#if defined (__WIN32__) || defined (_WIN32)
		char buffer[MAX_PATH];
		size_t pathLength = GetModuleFileName(nullptr, buffer, MAX_PATH);
		utility::string_t result = STCONVERT(buffer);
		auto resultParts = split(result);
		resultParts.pop_back();
		return join(resultParts);
#elif defined (__unix__)
		string fullFileName = "";

		// Code taken from: http://www.gamedev.net/community/forums/topic.asp?topic_id=459511
		std::string path = "";
		pid_t pid = getpid();
		char buf[20] = { 0 };
		sprintf(buf, "%d", pid);
		std::string _link = "/proc/";
		_link.append(buf);
		_link.append("/exe");
		char proc[512];
		int ch = readlink(_link.c_str(), proc, 512);
		if (ch != -1) {
			proc[ch] = 0;
			path = proc;
			std::string::size_type t = path.find_last_of("/");
			path = path.substr(0, t);
		}

		fullFileName = path + string("/");
		return STCONVERT(fullFileName);
#endif
	}
	std::vector<utility::string_t> get_directory_files(utility::string_t dir){
		std::vector<utility::string_t> files;
#ifdef _WIN32
		WIN32_FIND_DATA fd;
		std::string s(dir.begin(), dir.end());
		s += "/*.*";
		utility::string_t testsCode;

		HANDLE hFind = ::FindFirstFile(s.c_str(), &fd);
		if (hFind != INVALID_HANDLE_VALUE) {
			do {
				// read all (real) files in current folder
				// , delete '!' read other 2 default folder . and ..
				if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					files.push_back(dir + STCONVERT("\\") + STCONVERT(fd.cFileName));
				}
			} while (::FindNextFile(hFind, &fd));
			::FindClose(hFind);
		}

#elif defined(__unix__)
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir("c:\\src\\")) != NULL) {
			/* print all the files and directories within directory */
			while ((ent = readdir(dir)) != NULL) {
				files.push_back(dir + STCONVERT("\\") + STCONVERT(ent->d_name));
			}
			closedir(dir);
		}
		else {
			/* could not open directory */
			perror("");
			return EXIT_FAILURE;
		}
#endif
		return files;
	}
public:
	void UploadFileToStorage(utility::string_t path, utility::string_t filePath);
	bool GetIsExists(utility::string_t path);

public:
	std::shared_ptr<ApiConfiguration> get_configuration();
	std::shared_ptr<ApiClient> get_client();
	std::shared_ptr<WordsApi> get_api();

protected:
	const utility::string_t baseTestOutPath = STCONVERT("TestOut"),
		remoteBaseTestDataFolder = STCONVERT("Temp\\SdkTests\\TestData"),
		commonFolder = STCONVERT("Common");

	const utility::string_t buildAbsPath;

private:
	std::shared_ptr<ApiClient> client;
	std::shared_ptr<WordsApi> api;
	std::shared_ptr<ApiConfiguration> m_Config;
};
#endif
