#include <gtest/gtest.h>
#include "ApiClient.h"
#include <cpprest/http_listener.h>
#include <fstream>

#include <boost/shared_ptr.hpp>


#define PRINT_T(m) EXPECT_TRUE(false) << m;
using namespace web::http::experimental::listener;
using namespace web::http;

using namespace io::swagger::client::api;

using namespace std;

shared_ptr<ApiConfiguration> config;
shared_ptr<ApiConfiguration> getConfig() {
	if (config) return config;

	ifstream fileStream("servcreds.json");

	if (!fileStream.is_open()) {
		cout << "File is not open" << endl;
		return nullptr;
	}
	string lines, line;
	while (getline(fileStream, line)) {
		lines += line;
	}
	web::json::value fileJson = web::json::value::parse(utility::conversions::to_string_t(lines));
	config.reset(new ApiConfiguration);

	config->setAppKey(fileJson[L"AppKey"].as_string());
	config->setBaseUrl(fileJson[L"BaseUrl"].as_string());
	config->setAppSid(fileJson[L"AppSid"].as_string());
	return config;
}

TEST(OAuth, ServerTest) {
	ApiClient client;

	client.setConfiguration(getConfig());
	client.requestToken().wait();
	ASSERT_TRUE(true);
}

//TEST(OAUTH, OAUTHCase) {
//	utility::string_t 
//		token = utility::conversions::to_string_t("TOKENVALUE"),
//		key = utility::conversions::to_string_t("APPKEY"),
//		sid = utility::conversions::to_string_t("SID"),
//		grant_type = utility::conversions::to_string_t("client_credentials"),
//		base_url = utility::conversions::to_string_t("http://localhost:3000");
//
//
//	web::http::experimental::listener::http_listener listener(base_url);
//	listener.open().wait();
//
//	listener.support([=](http_request req) {
//		web::json::value body = req.extract_json().get();
//		try {
//			utility::string_t reqSid = body[L"client_id"].as_string(),
//						reqKey = body[L"client_secret"].as_string(),
//					reqGrantType = body[L"grant_type"].as_string();
//
//			std::wcout << reqKey << std::endl <<
//				reqSid << std::endl <<
//				reqGrantType << std::endl;
//
//			ASSERT_EQ(key, reqKey);
//			ASSERT_EQ(sid, reqSid);
//			ASSERT_EQ(grant_type, reqGrantType);
//		}
//		catch (const std::runtime_error& re)
//		{
//			// speciffic handling for runtime_error
//			std::cerr << "Runtime error: " << re.what() << std::endl;
//		}
//		catch (const std::exception& ex)
//		{
//			// speciffic handling for all exceptions extending std::exception, except
//			// std::runtime_error which is handled explicitly
//			std::cerr << "Error occurred: " << ex.what() << std::endl;
//		}
//
//		req.reply(status_codes::OK, token);
//	});
//
//	ApiClient client;
//	std::shared_ptr<ApiConfiguration> config(new ApiConfiguration());
//	config->setAppKey(key + L"FAKE");
//	config->setAppSid(sid);
//	config->setBaseUrl(base_url);
//	client.setConfiguration(config);
//	client.requestToken().wait(); 
//
//	ASSERT_EQ(token, client.getAccessToken());
//}


