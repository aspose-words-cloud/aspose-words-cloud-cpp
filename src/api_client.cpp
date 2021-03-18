/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_client.cpp">
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

#include "aspose_words_cloud/api_client.h"
#include "../thirdparty/utf8.h"
#pragma warning(push, 0) 
#include "../thirdparty/httplib.h"
#pragma warning(pop)

namespace aspose::words::cloud {
    std::array<std::pair<std::string, std::string>, 2> m_DefaultHeaders =
    {
        std::make_pair<std::string, std::string>("x-aspose-client-version", "21.3"),
        std::make_pair<std::string, std::string>("x-aspose-client", "C++ SDK")
    };

    inline ::httplib::Result callInternal(
        std::shared_ptr<::httplib::Client> client,
        HttpRequestMethod method,
        const char* path,
        const ::httplib::Headers& headers,
        const std::string& body,
        const std::string& contentType)
    {
        if (method == HttpRequestMethod::HttpGET)
        {
            return client->Get(path, headers);
        }
        else if (method == HttpRequestMethod::HttpPOST)
        {
            return client->Post(path, headers, body, contentType.c_str());
        }
        else if (method == HttpRequestMethod::HttpPUT)
        {
            return client->Put(path, headers, body, contentType.c_str());
        }
        else if (method == HttpRequestMethod::HttpDELETE)
        {
            return client->Delete(path, headers, body, contentType.c_str());
        }

        throw ApiException(400, L"Invalid http method type.");
    }

    ApiClient::ApiClient(std::shared_ptr<ApiConfiguration> configuration )
        : m_Configuration(configuration)
    {
        std::string baseUrlUtf8;
        utf8::utf16to8(configuration->getBaseUrl().begin(), configuration->getBaseUrl().end(), back_inserter(baseUrlUtf8));
        m_HttpClient = std::make_shared<::httplib::Client>(baseUrlUtf8.c_str());
    }

    void ApiClient::call(
        std::shared_ptr<HttpRequestData> httpRequest,
        aspose::words::cloud::responses::ResponseModelBase& response)
    {
        std::wstring path(httpRequest->getFullPath());
        std::string pathUtf8;
        ::utf8::utf16to8(path.begin(), path.end(), back_inserter(pathUtf8));

        ::httplib::Headers headers;
        for (auto& pair : httpRequest->getHeaders())
        {
            std::string keyUtf8, valueUtf8;
            ::utf8::utf16to8(pair.first.begin(), pair.first.end(), back_inserter(keyUtf8));
            ::utf8::utf16to8(pair.second.begin(), pair.second.end(), back_inserter(valueUtf8));
            headers.emplace(keyUtf8, valueUtf8);
        }
        for (auto& pair : m_DefaultHeaders)
            headers.emplace(pair.first, pair.second);

        ::httplib::Result httpResponse = callInternal(
            m_HttpClient, 
            httpRequest->getMethod(), 
            pathUtf8.c_str(), headers, 
            httpRequest->getBody(), 
            httpRequest->getContentType());
    }

    void ApiClient::requestToken()
    {
        if (m_Configuration == nullptr)
            throw ApiException(400, L"Configuration must be set before calling an api methods");

        if(m_Configuration->getClientId().empty())
            throw ApiException(400, L"Configuration parameter ClientId must be set before calling an api methods");

        if (m_Configuration->getClientSecret().empty())
            throw ApiException(400, L"Configuration parameter ClientSecret must be set before calling an api methods");

        if (m_Configuration->getBaseUrl().empty())
            throw ApiException(400, L"Configuration parameter BaseUrl must be set before calling an api methods");

        std::map<std::wstring, std::wstring> queryParams, headerParams;

        /*std::vector<FormParamContainer> formParams = {
            FormParamContainer(_XPLATSTR("grant_type"), _XPLATSTR("client_credentials")),
            FormParamContainer(_XPLATSTR("client_id"), m_Configuration->getClientId()),
            FormParamContainer(_XPLATSTR("client_secret"), m_Configuration->getClientSecret())
        };

        return callApi(getTokenUrl(), _XPLATSTR("POST"), queryParams, nullptr, headerParams, formParams, 
            _XPLATSTR("application/x-www-form-urlencoded")).then([=](web::http::http_response response) {

            if (response.status_code() >= 400)
            {
                auto code = response.status_code();
                auto reason = response.reason_phrase();
                auto message = response.extract_string().get();

                throw ApiException(code, _XPLATSTR("error requesting token: ") + reason + _XPLATSTR("\n") + message);
            }

            return response.extract_json();
        }).then([this](web::json::value val) {
            this->setAccessToken(val[_XPLATSTR("access_token")].as_string());
        });*/
    }
}
