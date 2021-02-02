/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiConfiguration.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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
#include "../model/WordsApiErrorResponse.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {

#define STCONVERT(s) utility::conversions::to_string_t(s)

class  ApiConfiguration
{
public:
    ApiConfiguration();
    ApiConfiguration(utility::string_t clientId, utility::string_t clientSecret);
    virtual ~ApiConfiguration() = default;

    web::http::client::http_client_config& getHttpConfig();
    void setHttpConfig(const web::http::client::http_client_config& value );

    utility::string_t getBaseUrl() const;
    void setBaseUrl( utility::string_t value );

    utility::string_t getUserAgent() const;
    void setUserAgent( utility::string_t value );

    std::map<utility::string_t, utility::string_t>& getDefaultHeaders();

    utility::string_t getClientId() const;
    void setClientId( utility::string_t apiSid );

    utility::string_t getClientSecret( const utility::string_t& prefix) const;
    void setClientSecret( const utility::string_t& prefix, const utility::string_t& clientSecret );

    utility::string_t getClientSecret() const;
    void setClientSecret( utility::string_t clientSecret );

    utility::string_t getApiVersion() const;

    bool isDebugMode() const;
    void setDebugMode(bool debug);

protected:
    bool m_DebugMode = false;
    utility::string_t m_BaseUrl = STCONVERT("https://api.aspose.cloud");
    std::map<utility::string_t, utility::string_t> m_DefaultHeaders;
    std::unordered_map<utility::string_t, utility::string_t> m_clientSecrets;

    utility::string_t m_clientSecret;
    utility::string_t m_clientId;

    web::http::client::http_client_config m_HttpConfig;
    utility::string_t m_UserAgent = STCONVERT("CppAsposeClient");
};

}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_ApiConfiguration_H_ */
