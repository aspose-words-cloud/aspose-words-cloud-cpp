/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiClient.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_ApiClient_H_
#define ASPOSE_WORDS_CLOUD_API_ApiClient_H_


#include "ApiConfiguration.h"
#include "ApiException.h"
#include "IHttpBody.h"
#include "HttpContent.h"
#include "JsonBody.h"

#include <memory>
#include <vector>
#include <array>

#include <cpprest/details/basic_types.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {

using namespace aspose::words::cloud::api::models;

class  ApiClient
{
public:
    explicit ApiClient( std::shared_ptr<ApiConfiguration> configuration = nullptr );

    std::shared_ptr<ApiConfiguration> getConfiguration() const;
    void setConfiguration(std::shared_ptr<ApiConfiguration> configuration);

    static utility::string_t parameterToString(utility::string_t value);
    static utility::string_t parameterToString(int32_t value);
    static utility::string_t parameterToString(int64_t value);
    static utility::string_t parameterToString(float value);
    static utility::string_t parameterToString(double value);
    static utility::string_t parameterToString(const utility::datetime &value);

    template<class T>
    static utility::string_t parameterToString(const std::vector<T>& value)
    {
        utility::string_t result;
        for (auto & item : value)
        {
            result.append(ApiClient::parameterToString(item));
            result.append(_XPLATSTR(", "));
        }

        if (!value.empty())
        {
            result.resize(result.size() - 2);
        }

        return result;
    }


    pplx::task<web::http::http_response> callApi(
        const utility::string_t& path,
        const utility::string_t& method,
        const std::map<utility::string_t, utility::string_t>& queryParams,
        const std::shared_ptr<IHttpBody> postBody,
        const std::map<utility::string_t, utility::string_t>& headerParams,
        const std::map<utility::string_t, utility::string_t>& formParams,
        const std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>>& fileParams,
        const utility::string_t& contentType
    );

    pplx::task<void> requestToken();

protected:
    void setAccessToken(utility::string_t token);
    std::shared_ptr<ApiConfiguration> m_Configuration;

private:
    utility::string_t m_AccessToken;
    std::array<std::pair<utility::string_t, utility::string_t>, 2> defaultHeaders =
    {
        std::make_pair<utility::string_t, utility::string_t>(_XPLATSTR("x-aspose-client-version"), _XPLATSTR("1.0")),
        std::make_pair<utility::string_t, utility::string_t>(_XPLATSTR("x-aspose-client"), _XPLATSTR("C++ SDK"))
    };

private:
    utility::string_t getTokenUrl() const;
    void logRequest(web::http::http_request request) const;
	void logResponse(web::http::http_response response) const;
	utility::string_t copyDataFromStream(const Concurrency::streams::istream& stream) const;
};

}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_ApiClient_H_ */
