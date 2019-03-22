/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiConfiguration.h">
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
#ifndef ASPOSE_WORDS_CLOUD_API_ApiConfiguration_H_
#define ASPOSE_WORDS_CLOUD_API_ApiConfiguration_H_



#include <unordered_map>
#include <map>

#include <cpprest/details/basic_types.h>
#include <cpprest/http_client.h>
namespace aspose {
namespace words {
namespace cloud {
namespace api {

class  ApiConfiguration
{
public:
    virtual ~ApiConfiguration() = default;

    web::http::client::http_client_config& getHttpConfig();
    void setHttpConfig(const web::http::client::http_client_config& value );

    utility::string_t getBaseUrl() const;
    void setBaseUrl( utility::string_t value );

    utility::string_t getUserAgent() const;
    void setUserAgent( utility::string_t value );

    std::map<utility::string_t, utility::string_t>& getDefaultHeaders();

    utility::string_t getApiKey( const utility::string_t& prefix) const;
    void setApiKey( const utility::string_t& prefix, const utility::string_t& apiKey );

    utility::string_t getAppKey() const;
    void setAppKey( utility::string_t apiKey );

    utility::string_t getAppSid() const;
    void setAppSid( utility::string_t apiSid );

    utility::string_t getApiVersion() const;
	void setApiVersion( utility::string_t apiVersion);

    bool isDebugMode() const;
    void setDebugMode(bool debug);

protected:
    bool m_DebugMode = false;
    utility::string_t m_BaseUrl;
    std::map<utility::string_t, utility::string_t> m_DefaultHeaders;
    std::unordered_map<utility::string_t, utility::string_t> m_ApiKeys;

    utility::string_t m_AppKey;
    utility::string_t m_AppSid;
	utility::string_t m_ApiVersion;

    web::http::client::http_client_config m_HttpConfig;
    utility::string_t m_UserAgent;
};

}
}
}
}
#endif /* ASPOSE_WORDS_CLOUD_API_ApiConfiguration_H_ */
