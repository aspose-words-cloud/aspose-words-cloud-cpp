/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiClient.cpp">
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
#include "ApiClient.h"
#include "MultipartFormData.h"
#include "ModelBase.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {

using namespace aspose::words::cloud::api::models;

ApiClient::ApiClient(std::shared_ptr<ApiConfiguration> configuration )
    : m_Configuration(configuration)
{
}

pplx::task<void> ApiClient::requestToken()
{
    if (m_Configuration == nullptr)
            throw "Configuration must be set before calling an api methods";

	if(m_Configuration->getAppSid().empty())
		throw "Configuration parameter AppSid must be set before calling an api methods";

	if (m_Configuration->getAppKey().empty())
		throw "Configuration parameter AppKey must be set before calling an api methods";

	if (m_Configuration->getBaseUrl().empty())
		throw "Configuration parameter BaseUrl must be set before calling an api methods";

    std::map<utility::string_t, utility::string_t> queryParams, headerParams;

    std::map<utility::string_t, utility::string_t> formParams = {
        {_XPLATSTR("grant_type"), _XPLATSTR("client_credentials")},
        {_XPLATSTR("client_id"), m_Configuration->getAppSid()},
        {_XPLATSTR("client_secret"), m_Configuration->getAppKey()}
    };

    return callApi(getTokenUrl(), _XPLATSTR("POST"), queryParams, nullptr, headerParams, formParams, {}, 
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
    });
}

utility::string_t ApiClient::getTokenUrl() const {
	return m_Configuration->getBaseUrl() + _XPLATSTR("/connect/token");            
}

void ApiClient::setAccessToken(utility::string_t token){
    m_AccessToken = token;
}

std::shared_ptr<ApiConfiguration> ApiClient::getConfiguration() const
{
    return m_Configuration;
}
void ApiClient::setConfiguration(std::shared_ptr<ApiConfiguration> configuration)
{
    m_Configuration = configuration;
}


utility::string_t ApiClient::parameterToString(utility::string_t value)
{
    return value;
}
utility::string_t ApiClient::parameterToString(int64_t value)
{
    return utility::conversions::details::to_string_t(value);
}
utility::string_t ApiClient::parameterToString(int32_t value)
{
    return utility::conversions::details::to_string_t(value);
}

utility::string_t ApiClient::parameterToString(float value)
{
    return utility::conversions::details::to_string_t(value);
}

utility::string_t ApiClient::parameterToString(double value)
{
    return utility::conversions::details::to_string_t(value);
}

utility::string_t ApiClient::parameterToString(const utility::datetime &value)
{
    return value.to_string(utility::datetime::ISO_8601);
}

pplx::task<web::http::http_response> ApiClient::callApi(
    const utility::string_t& path,
    const utility::string_t& method,
    const std::map<utility::string_t, utility::string_t>& queryParams,
    const std::shared_ptr<IHttpBody> postBody,
    const std::map<utility::string_t, utility::string_t>& headerParams,
    const std::map<utility::string_t, utility::string_t>& formParams,
    const std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>>& fileParams,
    const utility::string_t& contentType
)
{
    if (postBody && !formParams.empty())
    {
        throw ApiException(400, _XPLATSTR("Cannot have body and form params"));
    }

    if (postBody && !fileParams.empty())
    {
        throw ApiException(400, _XPLATSTR("Cannot have body and file params"));
    }

    if (!fileParams.empty() && contentType != _XPLATSTR("multipart/form-data"))
    {
        throw ApiException(400, _XPLATSTR("Operations with file parameters must be called with multipart/form-data"));
    }

    web::http::client::http_client client(m_Configuration->getBaseUrl(), m_Configuration->getHttpConfig());

    web::http::http_request request;

    auto & request_header = request.headers();
    for ( auto& kvp : headerParams )
    {
        request_header.add(kvp.first, kvp.second);
    }

    if (!fileParams.empty())
    {
        MultipartFormData uploadData;
        for (auto& kvp : formParams)
        {
            uploadData.add(ModelBase::toHttpContent(kvp.first, kvp.second));
        }
        for (auto& kvp : fileParams)
        {
            uploadData.add(ModelBase::toHttpContent(kvp.first, kvp.second));
        }
        std::ostringstream data;
        uploadData.writeTo(data);
        auto bodyString = data.str();
        auto length = bodyString.size();

        if (fileParams.size() + formParams.size() > 1)
        {
			request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length, 
				_XPLATSTR("multipart/form-data; boundary = ") + uploadData.getBoundary());
        }
		else
        {
            request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length);
        }
    }
    else
    {
        if (postBody)
        {
            std::ostringstream data;
            postBody->writeTo(data);
            auto bodyString = data.str();
            auto length = bodyString.size();
            request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length, contentType);
        }
        else
        {
            if (contentType == _XPLATSTR("application/json"))
            {
                web::json::value body_data = web::json::value::object();
                for (auto& kvp : formParams)
                {
                    body_data[kvp.first] = ModelBase::toJson(kvp.second);
                }
                if (!formParams.empty())
                {
                    request.set_body(body_data);
		}
            }
            else
            {
                web::http::uri_builder formData;
                for (auto& kvp : formParams)
                {
                    if (contentType == _XPLATSTR("multipart/form-data"))
                    {
                        formData.append_query(kvp.second);
                    }
                    else
                    {
                        formData.append_query(kvp.first, kvp.second);
                    }
                }

                if (!formParams.empty())
                {
                    request.set_body(formData.query(), contentType == _XPLATSTR("multipart/form-data") ? _XPLATSTR("application/x-www-form-urlencoded") : contentType);
                }
            }
        }
    }

    web::http::uri_builder builder(path);
    for (auto& kvp : queryParams)
    {
        builder.append_query(kvp.first, kvp.second);
    }
    request.set_request_uri(builder.to_uri());
    request.set_method(method);
    if ( !request.headers().has( web::http::header_names::user_agent ) )
    {
        request.headers().add( web::http::header_names::user_agent, m_Configuration->getUserAgent() );
    }
	if (!request.headers().has(web::http::header_names::authorization)) {
		if (this->m_AccessToken.empty() && path != getTokenUrl()) {
			requestToken().wait();
		}

		request.headers().add(web::http::header_names::authorization, _XPLATSTR("Bearer ") + m_AccessToken);
	}
    for (auto header : defaultHeaders) {
		request.headers().add(header.first, header.second);
	}
    
    logRequest(request);
    return client.request(request).then([=](web::http::http_response response){
        logResponse(response);
        return response;
    });
}

void ApiClient::logDataFromStream(const Concurrency::streams::istream& stream) const
{
	if (!m_Configuration->isDebugMode()) return;

	if (!stream.is_valid())
	{
		ucout << _XPLATSTR("EMPTY");
		return;
	}

    auto bodyStreamBuf = stream.streambuf();
    const size_t streamSize = bodyStreamBuf.size();

    std::string buffer;

    if (streamSize)
    {
        buffer.resize(streamSize);
        bodyStreamBuf.scopy(const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(buffer.data())) , buffer.size());
    }
    else
    {
        buffer.resize(bodyStreamBuf.in_avail());
        uint8_t* ptr = const_cast<uint8_t*>(reinterpret_cast<const uint8_t*>(buffer.data()));
        auto size = buffer.size();
        bodyStreamBuf.acquire(ptr, size);
    }

	for (int i = 0; i < buffer.size(); i++)
		ucout << buffer[i];
}


void ApiClient::logRequest(web::http::http_request request) const
{
    if (!m_Configuration->isDebugMode()) return;

    // header
    ucout << request.method() << _XPLATSTR(": ") << request.request_uri().to_string() << _XPLATSTR('\n');

    // body
	logDataFromStream(request.body());
    ucout << _XPLATSTR('\n');
}

void ApiClient::logResponse(web::http::http_response response) const
{
    if (!m_Configuration->isDebugMode()) return;

    // header
    ucout << _XPLATSTR("Response ") << response.status_code() << _XPLATSTR(": ") << response.reason_phrase() << _XPLATSTR('\n');

    // body
	logDataFromStream(response.body());
    ucout << _XPLATSTR('\n');
}

}
}
}
}
