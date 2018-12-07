/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiClient.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

namespace io {
namespace swagger {
namespace client {
namespace api {

using namespace io::swagger::client::model;

ApiClient::ApiClient(std::shared_ptr<ApiConfiguration> configuration )
    : m_Configuration(configuration)
{
    defaultHeaders.push_back(std::make_pair(utility::conversions::to_string_t("x-aspose-client-version"),
		utility::conversions::to_string_t("1.0")));

	defaultHeaders.push_back(std::make_pair(utility::conversions::to_string_t("x-aspose-client"),
		utility::conversions::to_string_t("C++ SDK")));
}
ApiClient::~ApiClient()
{
}

pplx::task<void> ApiClient::requestToken()
{
    if (m_Configuration == nullptr)
            throw "Configuration must be set before calling an api methods";

    std::map<utility::string_t, utility::string_t> queryParams, formParams, headerParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<io::swagger::client::model::HttpContent>>> fileParams;

    formParams.insert(std::make_pair(utility::conversions::to_string_t("grant_type"), 
		utility::conversions::to_string_t("client_credentials")));
	formParams.insert(std::make_pair(utility::conversions::to_string_t("client_id"),
		m_Configuration->getAppSid()));
	formParams.insert(std::make_pair(utility::conversions::to_string_t("client_secret"),
		m_Configuration->getAppKey()));

    return callApi(getTokenUrl(), L"POST", queryParams,nullptr, headerParams, formParams, fileParams, 
		utility::conversions::to_string_t("application/x-www-form-urlencoded")).then([=](web::http::http_response response) {
		
		if (response.status_code() >= 400)
			throw ApiException(response.status_code()
				, utility::conversions::to_string_t("error requesting token: ") + response.reason_phrase()
				, std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));

		return response.extract_json();
    }).then([this](web::json::value val) {
        this->setAccessToken(val[L"access_token"].as_string());
    });
}

utility::string_t ApiClient::getTokenUrl() const {
	return m_Configuration->getBaseUrl() + utility::conversions::to_string_t("/oauth2/token");            
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
	std::stringstream valueAsStringStream;
	valueAsStringStream << value;
    return utility::conversions::to_string_t(valueAsStringStream.str());
}
utility::string_t ApiClient::parameterToString(int32_t value)
{
	std::stringstream valueAsStringStream;
	valueAsStringStream << value;
    return utility::conversions::to_string_t(valueAsStringStream.str());
}

utility::string_t ApiClient::parameterToString(float value)
{
    return utility::conversions::to_string_t(std::to_string(value));
}

utility::string_t ApiClient::parameterToString(double value)
{
    return utility::conversions::to_string_t(std::to_string(value));
}

utility::string_t ApiClient::parameterToString(const utility::datetime &value)
{
    return utility::conversions::to_string_t(value.to_string(utility::datetime::ISO_8601));
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
    if (postBody != nullptr && formParams.size() != 0)
    {
        throw ApiException(400, utility::conversions::to_string_t("Cannot have body and form params"));
    }

    if (postBody != nullptr && fileParams.size() != 0)
    {
        throw ApiException(400, utility::conversions::to_string_t("Cannot have body and file params"));
    }

    if (fileParams.size() > 0 && contentType != utility::conversions::to_string_t("multipart/form-data"))
    {
        throw ApiException(400, utility::conversions::to_string_t("Operations with file parameters must be called with multipart/form-data"));
    }

    web::http::client::http_client client(m_Configuration->getBaseUrl(), m_Configuration->getHttpConfig());

    web::http::http_request request;
    for ( auto& kvp : headerParams )
    {
        request.headers().add(kvp.first, kvp.second);
    }

    if (fileParams.size() > 0)
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
        std::stringstream data;
        uploadData.writeTo(data);
        auto bodyString = data.str();
        auto length = bodyString.size();
        if (fileParams.size() + formParams.size() > 1)
			request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length, 
				utility::conversions::to_string_t("multipart/form-data; boundary = ") + uploadData.getBoundary());
		else
        request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length, utility::conversions::to_string_t("multipart/form-data;"));
    }
    else
    {
        if (postBody != nullptr)
        {
            std::stringstream data;
            postBody->writeTo(data);
            auto bodyString = data.str();
            auto length = bodyString.size();
            request.set_body(concurrency::streams::bytestream::open_istream(std::move(bodyString)), length, contentType);
        }
        else
        {
            if (contentType == utility::conversions::to_string_t("application/json"))
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
                   if (contentType == utility::conversions::to_string_t("multipart/form-data"))
										formData.append_query(kvp.second);
									else
									formData.append_query(kvp.first, kvp.second);
                }
                if (!formParams.empty())
                {
                    request.set_body(formData.query(), contentType);
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

		request.headers().add(web::http::header_names::authorization, utility::conversions::to_string_t("Bearer ") + m_AccessToken);
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

				utility::string_t ApiClient::copyDataFromStream(Concurrency::streams::istream stream)
				{
					if (!stream.is_valid()) return utility::conversions::to_string_t("EMPTY");

					auto bodyStreamBuf = stream.streambuf();
					size_t streamSize = bodyStreamBuf.size(),
						bufferSize = bodyStreamBuf.buffer_size(1);
					uint8_t* data;
					if (streamSize)
					{
						data = new uint8_t[streamSize];
						bodyStreamBuf.scopy(data, streamSize);
					}
					else
					{
						streamSize = bodyStreamBuf.in_avail();
						data = new uint8_t[streamSize];
						bodyStreamBuf.acquire(data, streamSize);
					}
					std::vector<uint8_t> saveVector(data, data + streamSize);
					std::ostringstream oss;
					std::copy(saveVector.begin(), saveVector.end(),
						std::ostream_iterator<uint8_t>(oss, ""));

					std::string s = oss.str();
					utility::string_t resultString(s.begin(), s.end());
					return resultString;
				}


				void ApiClient::logRequest(web::http::http_request request) {
					if (!m_Configuration->isDebugMode()) return;

					utility::string_t header = request.method() + utility::conversions::to_string_t(": ") +
						request.request_uri().to_string(),
						body = copyDataFromStream(request.body());

					std::wcout << header << std::endl << body << std::endl;
					std::wcout.clear();
				}

				void ApiClient::logResponse(web::http::http_response response) {
					if (!m_Configuration->isDebugMode()) return;
					
					utility::string_t header = utility::conversions::to_string_t("Response ") + 
						utility::conversions::to_string_t(std::to_string(response.status_code())) +
						utility::conversions::to_string_t(": ") + response.reason_phrase(),
						body = copyDataFromStream(response.body());

					std::wcout << header << std::endl << body << std::endl;
					std::wcout.clear();
				}

}
}
}
}
