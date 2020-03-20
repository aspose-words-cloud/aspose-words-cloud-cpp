/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApi.cpp">
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

#include "WordsApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

#include <boost/algorithm/string/replace.hpp>
#include <utility>

namespace aspose 
{
namespace words 
{
namespace cloud 
{
namespace api 
{

std::shared_ptr<FormField> deserializeFormField(web::json::value json)
{
					std::shared_ptr<FormField> field;
					if (json.has_field(_XPLATSTR("Checked")))
						field = std::make_shared<FormFieldCheckbox>();

					if (json.has_field(_XPLATSTR("TextInputFormat")) ||
						json.has_field(_XPLATSTR("TextInputDefault")))
						field = std::make_shared<FormFieldTextInput>();

					if (json.has_field(_XPLATSTR("DropDownItems")))
						field = std::make_shared<FormFieldDropDown>();

					if (!field) throw std::invalid_argument("Wrong json provided for FormFieldResponse");
					field->fromJson(json);
					return field;
				}

void postInitializeResponse(web::json::value json, void* response)
{
    if (json.has_field(_XPLATSTR("FormField")))
    {
        FormFieldResponse* fieldResponse = (FormFieldResponse*)response;
        web::json::value formField = json[_XPLATSTR("FormField")];
        fieldResponse->setFormField(deserializeFormField(formField));
    }

    if (json.has_field(_XPLATSTR("FormFields")))
    {
        FormFieldsResponse* fieldResponse = (FormFieldsResponse*)response;
        web::json::value formField = json[_XPLATSTR("FormFields")];
        std::shared_ptr<FormFieldCollection> fields = std::make_shared<FormFieldCollection>();

        std::vector<std::shared_ptr<FormField>> list;
        if (formField.has_field(_XPLATSTR("List"))
            && !formField[_XPLATSTR("List")].is_null())
        {
            for (auto& item : formField[_XPLATSTR("List")].as_array())
            {
                if (item.is_null())
                {
                    list.push_back(std::shared_ptr<FormField>(nullptr));
                }
                else
                {	
                    list.push_back(deserializeFormField(item));
                }
            }
        }

        fields->setList(list);
        fieldResponse->setFormFields(fields);
    }
}

utility::string_t replacePathParameter(utility::string_t path, const utility::string_t& paramName, const utility::string_t& value)
{
    if (!value.empty())
    {
        boost::replace_all(path, _XPLATSTR("{") + paramName + _XPLATSTR("}"),
            ApiClient::parameterToString(value));
    }
    else
    {
        boost::replace_all(path, _XPLATSTR("/{") + paramName + _XPLATSTR("}"),
            value);
    }
    return path;
}

template <class T> 
utility::string_t extractOptional(const boost::optional<T>& parameter)
{
	if (parameter.has_value())
		return ApiClient::parameterToString(parameter.value());

    return {};
}
using namespace aspose::words::cloud::api::models;

WordsApi::WordsApi(std::shared_ptr<ApiConfiguration> configuration)
    : m_ApiClient(std::make_shared<ApiClient>(configuration))
{
}

pplx::task<AsposeResponse<RevisionsModificationResponse>> WordsApi::(std::shared_ptr<AcceptAllRevisionsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/revisions/acceptAll"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<RevisionsModificationResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<RevisionsModificationResponse>(new RevisionsModificationResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<AppendDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getDocumentList() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/appendDocument"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getDocumentList());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getDocumentList().get())
        {
            (request->getDocumentList())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ClassificationResponse>> WordsApi::(std::shared_ptr<ClassifyRequest> request)
{

    // verify the required parameter '' is set
    if (request->getText() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/classify"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getBestClassesCount() && *(request->getBestClassesCount()) != nullptr)
    {
        queryParams[_XPLATSTR("BestClassesCount")] = ApiClient::parameterToString(*(request->getBestClassesCount()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getText());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getText().get())
        {
            (request->getText())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ClassificationResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ClassificationResponse>(new ClassificationResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ClassificationResponse>> WordsApi::(std::shared_ptr<ClassifyDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getDocumentName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{documentName}/classify"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getBestClassesCount() && *(request->getBestClassesCount()) != nullptr)
    {
        queryParams[_XPLATSTR("BestClassesCount")] = ApiClient::parameterToString(*(request->getBestClassesCount()));
    }
    if (request->getTaxonomy() && *(request->getTaxonomy()) != nullptr)
    {
        queryParams[_XPLATSTR("Taxonomy")] = ApiClient::parameterToString(*(request->getTaxonomy()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ClassificationResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ClassificationResponse>(new ClassificationResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<CompareDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getCompareData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/compareDocument"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getCompareData());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getCompareData().get())
        {
            (request->getCompareData())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<ConvertDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getDocument() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/convert"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDocument() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Document"), (request->getDocument())));
    }
    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getOutPath() && *(request->getOutPath()) != nullptr)
    {
        queryParams[_XPLATSTR("OutPath")] = ApiClient::parameterToString(*(request->getOutPath()));
    }
    if (request->getFileNameFieldValue() && *(request->getFileNameFieldValue()) != nullptr)
    {
        queryParams[_XPLATSTR("FileNameFieldValue")] = ApiClient::parameterToString(*(request->getFileNameFieldValue()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<CopyFileRequest> request)
{

    // verify the required parameter '' is set
    if (request->getDestPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSrcPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/copy/{srcPath}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDestPath() != nullptr)
    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName() && *(request->getSrcStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName() && *(request->getDestStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }
    if (request->getVersionId() && *(request->getVersionId()) != nullptr)
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<CopyFolderRequest> request)
{

    // verify the required parameter '' is set
    if (request->getDestPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSrcPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/copy/{srcPath}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDestPath() != nullptr)
    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName() && *(request->getSrcStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName() && *(request->getDestStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<CreateDocumentRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/create"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getFileName() && *(request->getFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("FileName")] = ApiClient::parameterToString(*(request->getFileName()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<CreateFolderRequest> request)
{

    // verify the required parameter '' is set
    if (request->getPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/{path}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getStorageName() && *(request->getStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<AsposeResponse<DocumentPropertyResponse>> WordsApi::(std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPropertyName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getProperty() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties/{propertyName}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getProperty());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getProperty().get())
        {
            (request->getProperty())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentPropertyResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentPropertyResponse>(new DocumentPropertyResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BorderResponse>> WordsApi::(std::shared_ptr<DeleteBorderRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getBorderType() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders/{borderType}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BorderResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BorderResponse>(new BorderResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BordersResponse>> WordsApi::(std::shared_ptr<DeleteBordersRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BordersResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BordersResponse>(new BordersResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteCommentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getCommentIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments/{commentIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteDocumentPropertyRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPropertyName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties/{propertyName}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteDrawingObjectRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteDrawingObjectWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFieldWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFieldsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFieldsWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFileRequest> request)
{

    // verify the required parameter '' is set
    if (request->getPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/{path}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getStorageName() && *(request->getStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getVersionId() && *(request->getVersionId()) != nullptr)
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFolderRequest> request)
{

    // verify the required parameter '' is set
    if (request->getPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/{path}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getStorageName() && *(request->getStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getRecursive() && *(request->getRecursive()) != nullptr)
    {
        queryParams[_XPLATSTR("Recursive")] = ApiClient::parameterToString(*(request->getRecursive()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFootnoteRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFootnoteWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFormFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteFormFieldWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteHeaderFooterRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteHeadersFootersRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getHeadersFootersTypes() && *(request->getHeadersFootersTypes()) != nullptr)
    {
        queryParams[_XPLATSTR("HeadersFootersTypes")] = ApiClient::parameterToString(*(request->getHeadersFootersTypes()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteMacrosRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/macros"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteOfficeMathObjectRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteOfficeMathObjectWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteParagraphRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteParagraphWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteRunRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraphPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteSectionRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteTableRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteTableCellRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTableRowPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteTableRowRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTablePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<DeleteTableWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<DeleteWatermarkRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/watermarks/deleteLast"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<DownloadFileRequest> request)
{

    // verify the required parameter '' is set
    if (request->getPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/{path}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getStorageName() && *(request->getStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getVersionId() && *(request->getVersionId()) != nullptr)
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<ExecuteMailMergeRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/MailMerge"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getData() && *(request->getData()) != nullptr)
    {
        formParams[_XPLATSTR("Data")] = ApiClient::parameterToString(*(request->getData()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getWithRegions() && *(request->getWithRegions()) != nullptr)
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getMailMergeDataFile() && *(request->getMailMergeDataFile()) != nullptr)
    {
        queryParams[_XPLATSTR("MailMergeDataFile")] = ApiClient::parameterToString(*(request->getMailMergeDataFile()));
    }
    if (request->getCleanup() && *(request->getCleanup()) != nullptr)
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getUseWholeParagraphAsRegion() && *(request->getUseWholeParagraphAsRegion()) != nullptr)
    {
        queryParams[_XPLATSTR("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(*(request->getUseWholeParagraphAsRegion()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<ExecuteMailMergeOnlineRequest> request)
{

    // verify the required parameter '' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/MailMerge"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getTemplate() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Template"), (request->getTemplate())));
    }
    if (request->getData() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Data"), (request->getData())));
    }
    if (request->getWithRegions() && *(request->getWithRegions()) != nullptr)
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getCleanup() && *(request->getCleanup()) != nullptr)
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getDocumentFileName() && *(request->getDocumentFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DocumentFileName")] = ApiClient::parameterToString(*(request->getDocumentFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<AsposeResponse<AvailableFontsResponse>> WordsApi::(std::shared_ptr<GetAvailableFontsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/fonts/available"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<AvailableFontsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<AvailableFontsResponse>(new AvailableFontsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BookmarkResponse>> WordsApi::(std::shared_ptr<GetBookmarkByNameRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getBookmarkName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/bookmarks/{bookmarkName}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BookmarkResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BookmarkResponse>(new BookmarkResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BookmarksResponse>> WordsApi::(std::shared_ptr<GetBookmarksRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/bookmarks"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BookmarksResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BookmarksResponse>(new BookmarksResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BorderResponse>> WordsApi::(std::shared_ptr<GetBorderRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getBorderType() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders/{borderType}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BorderResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BorderResponse>(new BorderResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BordersResponse>> WordsApi::(std::shared_ptr<GetBordersRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BordersResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BordersResponse>(new BordersResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentResponse>> WordsApi::(std::shared_ptr<GetCommentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getCommentIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments/{commentIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<CommentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<CommentResponse>(new CommentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentsResponse>> WordsApi::(std::shared_ptr<GetCommentsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<CommentsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<CommentsResponse>(new CommentsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<GetDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getDocumentName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{documentName}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectResponse>(new DrawingObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectByIndexWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectResponse>(new DrawingObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}/imageData"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectImageDataWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}/imageData"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}/oleData"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectOleDataWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}/oleData"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectsResponse>> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectsResponse>(new DrawingObjectsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectsResponse>> WordsApi::(std::shared_ptr<GetDocumentDrawingObjectsWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectsResponse>(new DrawingObjectsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldNamesResponse>> WordsApi::(std::shared_ptr<GetDocumentFieldNamesRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/mailMerge/FieldNames"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getUseNonMergeFields() && *(request->getUseNonMergeFields()) != nullptr)
    {
        queryParams[_XPLATSTR("UseNonMergeFields")] = ApiClient::parameterToString(*(request->getUseNonMergeFields()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldNamesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldNamesResponse>(new FieldNamesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldNamesResponse>> WordsApi::(std::shared_ptr<GetDocumentFieldNamesOnlineRequest> request)
{

    // verify the required parameter '' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/mailMerge/FieldNames"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getTemplate() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Template"), (request->getTemplate())));
    }
    if (request->getUseNonMergeFields() && *(request->getUseNonMergeFields()) != nullptr)
    {
        queryParams[_XPLATSTR("UseNonMergeFields")] = ApiClient::parameterToString(*(request->getUseNonMergeFields()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldNamesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldNamesResponse>(new FieldNamesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HyperlinkResponse>> WordsApi::(std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getHyperlinkIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/hyperlinks/{hyperlinkIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<HyperlinkResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<HyperlinkResponse>(new HyperlinkResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HyperlinksResponse>> WordsApi::(std::shared_ptr<GetDocumentHyperlinksRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/hyperlinks"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<HyperlinksResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<HyperlinksResponse>(new HyperlinksResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentPropertiesResponse>> WordsApi::(std::shared_ptr<GetDocumentPropertiesRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentPropertiesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentPropertiesResponse>(new DocumentPropertiesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentPropertyResponse>> WordsApi::(std::shared_ptr<GetDocumentPropertyRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPropertyName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties/{propertyName}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentPropertyResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentPropertyResponse>(new DocumentPropertyResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ProtectionDataResponse>> WordsApi::(std::shared_ptr<GetDocumentProtectionRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ProtectionDataResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ProtectionDataResponse>(new ProtectionDataResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<StatDataResponse>> WordsApi::(std::shared_ptr<GetDocumentStatisticsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/statistics"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getIncludeComments() && *(request->getIncludeComments()) != nullptr)
    {
        queryParams[_XPLATSTR("IncludeComments")] = ApiClient::parameterToString(*(request->getIncludeComments()));
    }
    if (request->getIncludeFootnotes() && *(request->getIncludeFootnotes()) != nullptr)
    {
        queryParams[_XPLATSTR("IncludeFootnotes")] = ApiClient::parameterToString(*(request->getIncludeFootnotes()));
    }
    if (request->getIncludeTextInShapes() && *(request->getIncludeTextInShapes()) != nullptr)
    {
        queryParams[_XPLATSTR("IncludeTextInShapes")] = ApiClient::parameterToString(*(request->getIncludeTextInShapes()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<StatDataResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<StatDataResponse>(new StatDataResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<GetDocumentWithFormatRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getOutPath() && *(request->getOutPath()) != nullptr)
    {
        queryParams[_XPLATSTR("OutPath")] = ApiClient::parameterToString(*(request->getOutPath()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::(std::shared_ptr<GetFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldResponse>(new FieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::(std::shared_ptr<GetFieldWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldResponse>(new FieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldsResponse>> WordsApi::(std::shared_ptr<GetFieldsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldsResponse>(new FieldsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldsResponse>> WordsApi::(std::shared_ptr<GetFieldsWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldsResponse>(new FieldsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FilesList>> WordsApi::(std::shared_ptr<GetFilesListRequest> request)
{

    // verify the required parameter '' is set
    if (request->getPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/{path}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getStorageName() && *(request->getStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FilesList> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FilesList>(new FilesList())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::(std::shared_ptr<GetFootnoteRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnoteResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnoteResponse>(new FootnoteResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::(std::shared_ptr<GetFootnoteWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnoteResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnoteResponse>(new FootnoteResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnotesResponse>> WordsApi::(std::shared_ptr<GetFootnotesRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnotesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnotesResponse>(new FootnotesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnotesResponse>> WordsApi::(std::shared_ptr<GetFootnotesWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnotesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnotesResponse>(new FootnotesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::(std::shared_ptr<GetFormFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldResponse>(new FormFieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::(std::shared_ptr<GetFormFieldWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldResponse>(new FormFieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldsResponse>> WordsApi::(std::shared_ptr<GetFormFieldsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldsResponse>(new FormFieldsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldsResponse>> WordsApi::(std::shared_ptr<GetFormFieldsWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldsResponse>(new FormFieldsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFooterResponse>> WordsApi::(std::shared_ptr<GetHeaderFooterRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getHeaderFooterIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/headersfooters/{headerFooterIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType() && *(request->getFilterByType()) != nullptr)
    {
        queryParams[_XPLATSTR("FilterByType")] = ApiClient::parameterToString(*(request->getFilterByType()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<HeaderFooterResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<HeaderFooterResponse>(new HeaderFooterResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFooterResponse>> WordsApi::(std::shared_ptr<GetHeaderFooterOfSectionRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getHeaderFooterIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}/headersfooters/{headerFooterIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType() && *(request->getFilterByType()) != nullptr)
    {
        queryParams[_XPLATSTR("FilterByType")] = ApiClient::parameterToString(*(request->getFilterByType()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<HeaderFooterResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<HeaderFooterResponse>(new HeaderFooterResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFootersResponse>> WordsApi::(std::shared_ptr<GetHeaderFootersRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType() && *(request->getFilterByType()) != nullptr)
    {
        queryParams[_XPLATSTR("FilterByType")] = ApiClient::parameterToString(*(request->getFilterByType()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<HeaderFootersResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<HeaderFootersResponse>(new HeaderFootersResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectResponse>> WordsApi::(std::shared_ptr<GetOfficeMathObjectRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<OfficeMathObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<OfficeMathObjectResponse>(new OfficeMathObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectResponse>> WordsApi::(std::shared_ptr<GetOfficeMathObjectWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<OfficeMathObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<OfficeMathObjectResponse>(new OfficeMathObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectsResponse>> WordsApi::(std::shared_ptr<GetOfficeMathObjectsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<OfficeMathObjectsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<OfficeMathObjectsResponse>(new OfficeMathObjectsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectsResponse>> WordsApi::(std::shared_ptr<GetOfficeMathObjectsWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<OfficeMathObjectsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<OfficeMathObjectsResponse>(new OfficeMathObjectsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphResponse>> WordsApi::(std::shared_ptr<GetParagraphRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphResponse>(new ParagraphResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphFormatResponse>> WordsApi::(std::shared_ptr<GetParagraphFormatRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}/format"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphFormatResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphFormatResponse>(new ParagraphFormatResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphFormatResponse>> WordsApi::(std::shared_ptr<GetParagraphFormatWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}/format"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphFormatResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphFormatResponse>(new ParagraphFormatResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphResponse>> WordsApi::(std::shared_ptr<GetParagraphWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphResponse>(new ParagraphResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphLinkCollectionResponse>> WordsApi::(std::shared_ptr<GetParagraphsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphLinkCollectionResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphLinkCollectionResponse>(new ParagraphLinkCollectionResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphLinkCollectionResponse>> WordsApi::(std::shared_ptr<GetParagraphsWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphLinkCollectionResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphLinkCollectionResponse>(new ParagraphLinkCollectionResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RangeTextResponse>> WordsApi::(std::shared_ptr<GetRangeTextRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRangeStartIdentifier() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<RangeTextResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<RangeTextResponse>(new RangeTextResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunResponse>> WordsApi::(std::shared_ptr<GetRunRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraphPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<RunResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<RunResponse>(new RunResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FontResponse>> WordsApi::(std::shared_ptr<GetRunFontRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraphPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}/font"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FontResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FontResponse>(new FontResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunsResponse>> WordsApi::(std::shared_ptr<GetRunsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraphPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<RunsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<RunsResponse>(new RunsResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionResponse>> WordsApi::(std::shared_ptr<GetSectionRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SectionResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SectionResponse>(new SectionResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionPageSetupResponse>> WordsApi::(std::shared_ptr<GetSectionPageSetupRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}/pageSetup"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SectionPageSetupResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SectionPageSetupResponse>(new SectionPageSetupResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionLinkCollectionResponse>> WordsApi::(std::shared_ptr<GetSectionsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SectionLinkCollectionResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SectionLinkCollectionResponse>(new SectionLinkCollectionResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::(std::shared_ptr<GetTableRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableResponse>(new TableResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellResponse>> WordsApi::(std::shared_ptr<GetTableCellRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTableRowPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableCellResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableCellResponse>(new TableCellResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellFormatResponse>> WordsApi::(std::shared_ptr<GetTableCellFormatRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTableRowPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}/cellformat"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableCellFormatResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableCellFormatResponse>(new TableCellFormatResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::(std::shared_ptr<GetTablePropertiesRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}/properties"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TablePropertiesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TablePropertiesResponse>(new TablePropertiesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::(std::shared_ptr<GetTablePropertiesWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}/properties"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TablePropertiesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TablePropertiesResponse>(new TablePropertiesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowResponse>> WordsApi::(std::shared_ptr<GetTableRowRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTablePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableRowResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableRowResponse>(new TableRowResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowFormatResponse>> WordsApi::(std::shared_ptr<GetTableRowFormatRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTablePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}/rowformat"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableRowFormatResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableRowFormatResponse>(new TableRowFormatResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::(std::shared_ptr<GetTableWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableResponse>(new TableResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableLinkCollectionResponse>> WordsApi::(std::shared_ptr<GetTablesRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableLinkCollectionResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableLinkCollectionResponse>(new TableLinkCollectionResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableLinkCollectionResponse>> WordsApi::(std::shared_ptr<GetTablesWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableLinkCollectionResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableLinkCollectionResponse>(new TableLinkCollectionResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentResponse>> WordsApi::(std::shared_ptr<InsertCommentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getComment() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getComment());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getComment().get())
        {
            (request->getComment())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<CommentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<CommentResponse>(new CommentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::(std::shared_ptr<InsertDrawingObjectRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getDrawingObject() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDrawingObject() != nullptr)
    {
        formParams[_XPLATSTR("DrawingObject")] = ApiClient::parameterToString((request->getDrawingObject()));
    }
    if (request->getImageFile() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectResponse>(new DrawingObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::(std::shared_ptr<InsertDrawingObjectWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getDrawingObject() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDrawingObject() != nullptr)
    {
        formParams[_XPLATSTR("DrawingObject")] = ApiClient::parameterToString((request->getDrawingObject()));
    }
    if (request->getImageFile() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectResponse>(new DrawingObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::(std::shared_ptr<InsertFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode() && *(request->getInsertBeforeNode()) != nullptr)
    {
        queryParams[_XPLATSTR("InsertBeforeNode")] = ApiClient::parameterToString(*(request->getInsertBeforeNode()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getField());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getField().get())
        {
            (request->getField())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldResponse>(new FieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::(std::shared_ptr<InsertFieldWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode() && *(request->getInsertBeforeNode()) != nullptr)
    {
        queryParams[_XPLATSTR("InsertBeforeNode")] = ApiClient::parameterToString(*(request->getInsertBeforeNode()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getField());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getField().get())
        {
            (request->getField())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldResponse>(new FieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::(std::shared_ptr<InsertFootnoteRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFootnoteDto());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFootnoteDto().get())
        {
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnoteResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnoteResponse>(new FootnoteResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::(std::shared_ptr<InsertFootnoteWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFootnoteDto());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFootnoteDto().get())
        {
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnoteResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnoteResponse>(new FootnoteResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::(std::shared_ptr<InsertFormFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode() && *(request->getInsertBeforeNode()) != nullptr)
    {
        queryParams[_XPLATSTR("InsertBeforeNode")] = ApiClient::parameterToString(*(request->getInsertBeforeNode()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFormField());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFormField().get())
        {
            (request->getFormField())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldResponse>(new FormFieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::(std::shared_ptr<InsertFormFieldWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode() && *(request->getInsertBeforeNode()) != nullptr)
    {
        queryParams[_XPLATSTR("InsertBeforeNode")] = ApiClient::parameterToString(*(request->getInsertBeforeNode()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFormField());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFormField().get())
        {
            (request->getFormField())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldResponse>(new FormFieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFooterResponse>> WordsApi::(std::shared_ptr<InsertHeaderFooterRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getHeaderFooterType() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getHeaderFooterType());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getHeaderFooterType().get())
        {
            (request->getHeaderFooterType())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<HeaderFooterResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<HeaderFooterResponse>(new HeaderFooterResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<InsertPageNumbersRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPageNumber() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/PageNumbers"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getPageNumber());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getPageNumber().get())
        {
            (request->getPageNumber())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphResponse>> WordsApi::(std::shared_ptr<InsertParagraphRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraph() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode() && *(request->getInsertBeforeNode()) != nullptr)
    {
        queryParams[_XPLATSTR("InsertBeforeNode")] = ApiClient::parameterToString(*(request->getInsertBeforeNode()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getParagraph());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getParagraph().get())
        {
            (request->getParagraph())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphResponse>(new ParagraphResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunResponse>> WordsApi::(std::shared_ptr<InsertRunRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraphPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRun() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode() && *(request->getInsertBeforeNode()) != nullptr)
    {
        queryParams[_XPLATSTR("InsertBeforeNode")] = ApiClient::parameterToString(*(request->getInsertBeforeNode()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getRun());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getRun().get())
        {
            (request->getRun())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<RunResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<RunResponse>(new RunResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::(std::shared_ptr<InsertTableRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTable() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getTable());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getTable().get())
        {
            (request->getTable())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableResponse>(new TableResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellResponse>> WordsApi::(std::shared_ptr<InsertTableCellRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getCell() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTableRowPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getCell());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getCell().get())
        {
            (request->getCell())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableCellResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableCellResponse>(new TableCellResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowResponse>> WordsApi::(std::shared_ptr<InsertTableRowRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRow() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTablePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getRow());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getRow().get())
        {
            (request->getRow())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableRowResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableRowResponse>(new TableRowResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::(std::shared_ptr<InsertTableWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTable() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getTable());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getTable().get())
        {
            (request->getTable())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableResponse>(new TableResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<InsertWatermarkImageRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/watermarks/images"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getImageFile() && *(request->getImageFile()) != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), *(request->getImageFile())));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getRotationAngle() && *(request->getRotationAngle()) != nullptr)
    {
        queryParams[_XPLATSTR("RotationAngle")] = ApiClient::parameterToString(*(request->getRotationAngle()));
    }
    if (request->getImage() && *(request->getImage()) != nullptr)
    {
        queryParams[_XPLATSTR("Image")] = ApiClient::parameterToString(*(request->getImage()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<InsertWatermarkTextRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getWatermarkText() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/watermarks/texts"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getWatermarkText());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getWatermarkText().get())
        {
            (request->getWatermarkText())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SaveResponse>> WordsApi::(std::shared_ptr<LoadWebDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/loadWebDocument"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getData());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getData().get())
        {
            (request->getData())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SaveResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SaveResponse>(new SaveResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<MoveFileRequest> request)
{

    // verify the required parameter '' is set
    if (request->getDestPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSrcPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/move/{srcPath}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDestPath() != nullptr)
    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName() && *(request->getSrcStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName() && *(request->getDestStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }
    if (request->getVersionId() && *(request->getVersionId()) != nullptr)
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<MoveFolderRequest> request)
{

    // verify the required parameter '' is set
    if (request->getDestPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSrcPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/move/{srcPath}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDestPath() != nullptr)
    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName() && *(request->getSrcStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName() && *(request->getDestStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<AsposeResponse<ProtectionDataResponse>> WordsApi::(std::shared_ptr<ProtectDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getProtectionRequest() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getProtectionRequest());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getProtectionRequest().get())
        {
            (request->getProtectionRequest())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ProtectionDataResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ProtectionDataResponse>(new ProtectionDataResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RevisionsModificationResponse>> WordsApi::(std::shared_ptr<RejectAllRevisionsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/revisions/rejectAll"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<RevisionsModificationResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<RevisionsModificationResponse>(new RevisionsModificationResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<RemoveRangeRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRangeStartIdentifier() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderDrawingObjectRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderDrawingObjectWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderMathObjectRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderMathObjectWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderPageRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPageIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/pages/{pageIndex}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderParagraphRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderParagraphWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderTableRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<HttpContent> WordsApi::(std::shared_ptr<RenderTableWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}/render"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFormat() != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<AsposeResponse<ReplaceTextResponse>> WordsApi::(std::shared_ptr<ReplaceTextRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getReplaceText() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/replaceText"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getReplaceText());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getReplaceText().get())
        {
            (request->getReplaceText())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ReplaceTextResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ReplaceTextResponse>(new ReplaceTextResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<ReplaceWithTextRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRangeStartIdentifier() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRangeText() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getRangeText());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getRangeText().get())
        {
            (request->getRangeText())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::(std::shared_ptr<ResetCacheRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/fonts/cache"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;


    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<AsposeResponse<SaveResponse>> WordsApi::(std::shared_ptr<SaveAsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSaveOptionsData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/saveAs"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getSaveOptionsData());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getSaveOptionsData().get())
        {
            (request->getSaveOptionsData())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SaveResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SaveResponse>(new SaveResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<SaveAsRangeRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRangeStartIdentifier() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getDocumentParameters() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}/SaveAs"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getDocumentParameters());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getDocumentParameters().get())
        {
            (request->getDocumentParameters())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SaveResponse>> WordsApi::(std::shared_ptr<SaveAsTiffRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSaveOptions() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/saveAs/tiff"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getUseAntiAliasing() && *(request->getUseAntiAliasing()) != nullptr)
    {
        queryParams[_XPLATSTR("UseAntiAliasing")] = ApiClient::parameterToString(*(request->getUseAntiAliasing()));
    }
    if (request->getUseHighQualityRendering() && *(request->getUseHighQualityRendering()) != nullptr)
    {
        queryParams[_XPLATSTR("UseHighQualityRendering")] = ApiClient::parameterToString(*(request->getUseHighQualityRendering()));
    }
    if (request->getImageBrightness() && *(request->getImageBrightness()) != nullptr)
    {
        queryParams[_XPLATSTR("ImageBrightness")] = ApiClient::parameterToString(*(request->getImageBrightness()));
    }
    if (request->getImageColorMode() && *(request->getImageColorMode()) != nullptr)
    {
        queryParams[_XPLATSTR("ImageColorMode")] = ApiClient::parameterToString(*(request->getImageColorMode()));
    }
    if (request->getImageContrast() && *(request->getImageContrast()) != nullptr)
    {
        queryParams[_XPLATSTR("ImageContrast")] = ApiClient::parameterToString(*(request->getImageContrast()));
    }
    if (request->getNumeralFormat() && *(request->getNumeralFormat()) != nullptr)
    {
        queryParams[_XPLATSTR("NumeralFormat")] = ApiClient::parameterToString(*(request->getNumeralFormat()));
    }
    if (request->getPageCount() && *(request->getPageCount()) != nullptr)
    {
        queryParams[_XPLATSTR("PageCount")] = ApiClient::parameterToString(*(request->getPageCount()));
    }
    if (request->getPageIndex() && *(request->getPageIndex()) != nullptr)
    {
        queryParams[_XPLATSTR("PageIndex")] = ApiClient::parameterToString(*(request->getPageIndex()));
    }
    if (request->getPaperColor() && *(request->getPaperColor()) != nullptr)
    {
        queryParams[_XPLATSTR("PaperColor")] = ApiClient::parameterToString(*(request->getPaperColor()));
    }
    if (request->getPixelFormat() && *(request->getPixelFormat()) != nullptr)
    {
        queryParams[_XPLATSTR("PixelFormat")] = ApiClient::parameterToString(*(request->getPixelFormat()));
    }
    if (request->getResolution() && *(request->getResolution()) != nullptr)
    {
        queryParams[_XPLATSTR("Resolution")] = ApiClient::parameterToString(*(request->getResolution()));
    }
    if (request->getScale() && *(request->getScale()) != nullptr)
    {
        queryParams[_XPLATSTR("Scale")] = ApiClient::parameterToString(*(request->getScale()));
    }
    if (request->getTiffCompression() && *(request->getTiffCompression()) != nullptr)
    {
        queryParams[_XPLATSTR("TiffCompression")] = ApiClient::parameterToString(*(request->getTiffCompression()));
    }
    if (request->getDmlRenderingMode() && *(request->getDmlRenderingMode()) != nullptr)
    {
        queryParams[_XPLATSTR("DmlRenderingMode")] = ApiClient::parameterToString(*(request->getDmlRenderingMode()));
    }
    if (request->getDmlEffectsRenderingMode() && *(request->getDmlEffectsRenderingMode()) != nullptr)
    {
        queryParams[_XPLATSTR("DmlEffectsRenderingMode")] = ApiClient::parameterToString(*(request->getDmlEffectsRenderingMode()));
    }
    if (request->getTiffBinarizationMethod() && *(request->getTiffBinarizationMethod()) != nullptr)
    {
        queryParams[_XPLATSTR("TiffBinarizationMethod")] = ApiClient::parameterToString(*(request->getTiffBinarizationMethod()));
    }
    if (request->getZipOutput() && *(request->getZipOutput()) != nullptr)
    {
        queryParams[_XPLATSTR("ZipOutput")] = ApiClient::parameterToString(*(request->getZipOutput()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getSaveOptions());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getSaveOptions().get())
        {
            (request->getSaveOptions())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SaveResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SaveResponse>(new SaveResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SearchResponse>> WordsApi::(std::shared_ptr<SearchRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPattern() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/search"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getPattern() != nullptr)
    {
        queryParams[_XPLATSTR("Pattern")] = ApiClient::parameterToString((request->getPattern()));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SearchResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SearchResponse>(new SearchResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SplitDocumentResponse>> WordsApi::(std::shared_ptr<SplitDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/split"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getFormat() && *(request->getFormat()) != nullptr)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString(*(request->getFormat()));
    }
    if (request->getFrom() && *(request->getFrom()) != nullptr)
    {
        queryParams[_XPLATSTR("From")] = ApiClient::parameterToString(*(request->getFrom()));
    }
    if (request->getTo() && *(request->getTo()) != nullptr)
    {
        queryParams[_XPLATSTR("To")] = ApiClient::parameterToString(*(request->getTo()));
    }
    if (request->getZipOutput() && *(request->getZipOutput()) != nullptr)
    {
        queryParams[_XPLATSTR("ZipOutput")] = ApiClient::parameterToString(*(request->getZipOutput()));
    }
    if (request->getFontsLocation() && *(request->getFontsLocation()) != nullptr)
    {
        queryParams[_XPLATSTR("FontsLocation")] = ApiClient::parameterToString(*(request->getFontsLocation()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SplitDocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SplitDocumentResponse>(new SplitDocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ProtectionDataResponse>> WordsApi::(std::shared_ptr<UnprotectDocumentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getProtectionRequest() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getProtectionRequest());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getProtectionRequest().get())
        {
            (request->getProtectionRequest())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ProtectionDataResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ProtectionDataResponse>(new ProtectionDataResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BookmarkResponse>> WordsApi::(std::shared_ptr<UpdateBookmarkRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getBookmarkData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getBookmarkName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/bookmarks/{bookmarkName}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getBookmarkData());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getBookmarkData().get())
        {
            (request->getBookmarkData())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BookmarkResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BookmarkResponse>(new BookmarkResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BorderResponse>> WordsApi::(std::shared_ptr<UpdateBorderRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getBorderProperties() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getBorderType() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders/{borderType}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getBorderProperties());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getBorderProperties().get())
        {
            (request->getBorderProperties())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<BorderResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<BorderResponse>(new BorderResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentResponse>> WordsApi::(std::shared_ptr<UpdateCommentRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getCommentIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getComment() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments/{commentIndex}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getComment());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getComment().get())
        {
            (request->getComment())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<CommentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<CommentResponse>(new CommentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::(std::shared_ptr<UpdateDrawingObjectRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getDrawingObject() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDrawingObject() != nullptr)
    {
        formParams[_XPLATSTR("DrawingObject")] = ApiClient::parameterToString((request->getDrawingObject()));
    }
    if (request->getImageFile() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectResponse>(new DrawingObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::(std::shared_ptr<UpdateDrawingObjectWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getDrawingObject() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getDrawingObject() != nullptr)
    {
        formParams[_XPLATSTR("DrawingObject")] = ApiClient::parameterToString((request->getDrawingObject()));
    }
    if (request->getImageFile() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DrawingObjectResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DrawingObjectResponse>(new DrawingObjectResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::(std::shared_ptr<UpdateFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getField());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getField().get())
        {
            (request->getField())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FieldResponse>(new FieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::(std::shared_ptr<UpdateFieldsRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/updateFields"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<DocumentResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<DocumentResponse>(new DocumentResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::(std::shared_ptr<UpdateFootnoteRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFootnoteDto());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFootnoteDto().get())
        {
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnoteResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnoteResponse>(new FootnoteResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::(std::shared_ptr<UpdateFootnoteWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFootnoteDto());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFootnoteDto().get())
        {
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FootnoteResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FootnoteResponse>(new FootnoteResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::(std::shared_ptr<UpdateFormFieldRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFormField());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFormField().get())
        {
            (request->getFormField())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldResponse>(new FormFieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::(std::shared_ptr<UpdateFormFieldWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFormField());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFormField().get())
        {
            (request->getFormField())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FormFieldResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormFieldResponse>(new FormFieldResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphFormatResponse>> WordsApi::(std::shared_ptr<UpdateParagraphFormatRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}/format"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getDto());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getDto().get())
        {
            (request->getDto())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<ParagraphFormatResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ParagraphFormatResponse>(new ParagraphFormatResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunResponse>> WordsApi::(std::shared_ptr<UpdateRunRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getRun() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraphPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getRun());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getRun().get())
        {
            (request->getRun())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<RunResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<RunResponse>(new RunResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FontResponse>> WordsApi::(std::shared_ptr<UpdateRunFontRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFontDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getParagraphPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}/font"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFontDto());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFontDto().get())
        {
            (request->getFontDto())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FontResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FontResponse>(new FontResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionPageSetupResponse>> WordsApi::(std::shared_ptr<UpdateSectionPageSetupRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getSectionIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPageSetup() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}/pageSetup"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getPageSetup());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getPageSetup().get())
        {
            (request->getPageSetup())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<SectionPageSetupResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<SectionPageSetupResponse>(new SectionPageSetupResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellFormatResponse>> WordsApi::(std::shared_ptr<UpdateTableCellFormatRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTableRowPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}/cellformat"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFormat());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFormat().get())
        {
            (request->getFormat())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableCellFormatResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableCellFormatResponse>(new TableCellFormatResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::(std::shared_ptr<UpdateTablePropertiesRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getProperties() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getNodePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}/properties"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getProperties());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getProperties().get())
        {
            (request->getProperties())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TablePropertiesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TablePropertiesResponse>(new TablePropertiesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::(std::shared_ptr<UpdateTablePropertiesWithoutNodePathRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getProperties() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}/properties"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getProperties());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getProperties().get())
        {
            (request->getProperties())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TablePropertiesResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TablePropertiesResponse>(new TablePropertiesResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowFormatResponse>> WordsApi::(std::shared_ptr<UpdateTableRowFormatRequest> request)
{

    // verify the required parameter '' is set
    if (request->getName() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getTablePath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getIndex() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}/rowformat"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFolder() && *(request->getFolder()) != nullptr)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && *(request->getStorage()) != nullptr)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && *(request->getLoadEncoding()) != nullptr)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && *(request->getPassword()) != nullptr)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && *(request->getDestFileName()) != nullptr)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && *(request->getRevisionAuthor()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && *(request->getRevisionDateTime()) != nullptr)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getFormat());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getFormat().get())
        {
            (request->getFormat())->toMultipart(multipart, _XPLATSTR(""));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<TableRowFormatResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<TableRowFormatResponse>(new TableRowFormatResponse())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FilesUploadResult>> WordsApi::(std::shared_ptr<UploadFileRequest> request)
{

    // verify the required parameter '' is set
    if (request->getFileContent() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    // verify the required parameter '' is set
    if (request->getPath() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '' when calling WordsApi->"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/{path}"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("WordsApi-> does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;

    if (request->getFileContent() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("FileContent"), (request->getFileContent())));
    }
    if (request->getStorageName() && *(request->getStorageName()) != nullptr)
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi-> does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			std::shared_ptr<WordsApiErrorResponse> errorResponse = std::shared_ptr<WordsApiErrorResponse>(new WordsApiErrorResponse());
			web::json::value error_json = response.extract_json().get();
			errorResponse->fromJson(error_json);

			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase()
				, errorResponse);
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		AsposeResponse<FilesUploadResult> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FilesUploadResult>(new FilesUploadResult())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling : unsupported response type"));
        }

        return result;
    });
}

}
}
}
}


