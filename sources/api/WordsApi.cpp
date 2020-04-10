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

pplx::task<AsposeResponse<RevisionsModificationResponse>> WordsApi::acceptAllRevisions(std::shared_ptr<AcceptAllRevisionsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/revisions/acceptAll"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->acceptAllRevisions does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->acceptAllRevisions does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling acceptAllRevisions: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::appendDocument(std::shared_ptr<AppendDocumentRequest> request)
{

    // verify the required parameter 'documentList' is set
    if (request->getDocumentList() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'documentList' when calling WordsApi->appendDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/appendDocument"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->appendDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getDocumentList())->toMultipart(multipart, _XPLATSTR("documentList"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->appendDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling appendDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::buildReport(std::shared_ptr<BuildReportRequest> request)
{

    // verify the required parameter 'reportEngineSettings' is set
    if (request->getReportEngineSettings() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'reportEngineSettings' when calling WordsApi->buildReport"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/buildReport"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->buildReport does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Data"), ApiClient::parameterToString((request->getData()))));
    }
    if (request->getReportEngineSettings() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("ReportEngineSettings"), ApiClient::parameterToString((request->getReportEngineSettings()))));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->buildReport does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling buildReport: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::buildReportOnline(std::shared_ptr<BuildReportOnlineRequest> request)
{

    // verify the required parameter '_template' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '_template' when calling WordsApi->buildReportOnline"));
    }

    // verify the required parameter 'reportEngineSettings' is set
    if (request->getReportEngineSettings() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'reportEngineSettings' when calling WordsApi->buildReportOnline"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/buildReport"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getTemplate() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Template"), (request->getTemplate())));
    }
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Data"), ApiClient::parameterToString((request->getData()))));
    }
    if (request->getReportEngineSettings() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("ReportEngineSettings"), ApiClient::parameterToString((request->getReportEngineSettings()))));
    }
    if (request->getDocumentFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->buildReportOnline does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<ClassificationResponse>> WordsApi::classify(std::shared_ptr<ClassifyRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/classify"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->classify does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getBestClassesCount())
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
        multipart->add(ModelBase::toHttpContent(_XPLATSTR("text"), request->getText()));

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->classify does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling classify: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ClassificationResponse>> WordsApi::classifyDocument(std::shared_ptr<ClassifyDocumentRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{documentName}/classify"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("documentName"),
        ApiClient::parameterToString(request->getDocumentName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->classifyDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getBestClassesCount())
    {
        queryParams[_XPLATSTR("BestClassesCount")] = ApiClient::parameterToString(*(request->getBestClassesCount()));
    }
    if (request->getTaxonomy())
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
        throw ApiException(415, _XPLATSTR("WordsApi->classifyDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling classifyDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::compareDocument(std::shared_ptr<CompareDocumentRequest> request)
{

    // verify the required parameter 'compareData' is set
    if (request->getCompareData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'compareData' when calling WordsApi->compareDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/compareDocument"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->compareDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
            (request->getCompareData())->toMultipart(multipart, _XPLATSTR("compareData"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->compareDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling compareDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::convertDocument(std::shared_ptr<ConvertDocumentRequest> request)
{

    // verify the required parameter 'document' is set
    if (request->getDocument() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'document' when calling WordsApi->convertDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/convert"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getDocument() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Document"), (request->getDocument())));
    }
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getOutPath())
    {
        queryParams[_XPLATSTR("OutPath")] = ApiClient::parameterToString(*(request->getOutPath()));
    }
    if (request->getFileNameFieldValue())
    {
        queryParams[_XPLATSTR("FileNameFieldValue")] = ApiClient::parameterToString(*(request->getFileNameFieldValue()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->convertDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::copyFile(std::shared_ptr<CopyFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/copy/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->copyFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }
    if (request->getVersionId())
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
        throw ApiException(415, _XPLATSTR("WordsApi->copyFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::copyFolder(std::shared_ptr<CopyFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/copy/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->copyFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->copyFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::createDocument(std::shared_ptr<CreateDocumentRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/create"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->createDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getFileName())
    {
        queryParams[_XPLATSTR("FileName")] = ApiClient::parameterToString(*(request->getFileName()));
    }
    if (request->getFolder())
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
        throw ApiException(415, _XPLATSTR("WordsApi->createDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling createDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::createFolder(std::shared_ptr<CreateFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->createFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorageName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->createFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<DocumentPropertyResponse>> WordsApi::createOrUpdateDocumentProperty(std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request)
{

    // verify the required parameter 'property' is set
    if (request->getProperty() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'property' when calling WordsApi->createOrUpdateDocumentProperty"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties/{propertyName}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("propertyName"),
        ApiClient::parameterToString(request->getPropertyName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->createOrUpdateDocumentProperty does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getProperty())->toMultipart(multipart, _XPLATSTR("property"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->createOrUpdateDocumentProperty does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling createOrUpdateDocumentProperty: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BorderResponse>> WordsApi::deleteBorder(std::shared_ptr<DeleteBorderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders/{borderType}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("borderType"),
        ApiClient::parameterToString(request->getBorderType()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteBorder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteBorder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling deleteBorder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BordersResponse>> WordsApi::deleteBorders(std::shared_ptr<DeleteBordersRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteBorders does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteBorders does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling deleteBorders: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteComment(std::shared_ptr<DeleteCommentRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments/{commentIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("commentIndex"),
        ApiClient::parameterToString(request->getCommentIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteComment does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteDocumentProperty(std::shared_ptr<DeleteDocumentPropertyRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties/{propertyName}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("propertyName"),
        ApiClient::parameterToString(request->getPropertyName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteDocumentProperty does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteDocumentProperty does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteDrawingObject(std::shared_ptr<DeleteDrawingObjectRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteDrawingObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteDrawingObject does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteDrawingObjectWithoutNodePath(std::shared_ptr<DeleteDrawingObjectWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteDrawingObjectWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteDrawingObjectWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteField(std::shared_ptr<DeleteFieldRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFieldWithoutNodePath(std::shared_ptr<DeleteFieldWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFieldWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFieldWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFields(std::shared_ptr<DeleteFieldsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFields does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFieldsWithoutNodePath(std::shared_ptr<DeleteFieldsWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFieldsWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFieldsWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFile(std::shared_ptr<DeleteFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getVersionId())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFolder(std::shared_ptr<DeleteFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getRecursive())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFootnote(std::shared_ptr<DeleteFootnoteRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFootnote does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFootnoteWithoutNodePath(std::shared_ptr<DeleteFootnoteWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFootnoteWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFootnoteWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFormField(std::shared_ptr<DeleteFormFieldRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFormField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteFormFieldWithoutNodePath(std::shared_ptr<DeleteFormFieldWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFormFieldWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteFormFieldWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteHeaderFooter(std::shared_ptr<DeleteHeaderFooterRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"),
        ApiClient::parameterToString(request->getSectionPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteHeaderFooter does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteHeaderFooter does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteHeadersFooters(std::shared_ptr<DeleteHeadersFootersRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"),
        ApiClient::parameterToString(request->getSectionPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteHeadersFooters does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getHeadersFootersTypes())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteHeadersFooters does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteMacros(std::shared_ptr<DeleteMacrosRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/macros"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteMacros does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteMacros does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteOfficeMathObject(std::shared_ptr<DeleteOfficeMathObjectRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteOfficeMathObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteOfficeMathObject does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteOfficeMathObjectWithoutNodePath(std::shared_ptr<DeleteOfficeMathObjectWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteOfficeMathObjectWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteOfficeMathObjectWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteParagraph(std::shared_ptr<DeleteParagraphRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteParagraph does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteParagraph does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteParagraphWithoutNodePath(std::shared_ptr<DeleteParagraphWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteParagraphWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteParagraphWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteRun(std::shared_ptr<DeleteRunRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteRun does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteSection(std::shared_ptr<DeleteSectionRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteSection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteSection does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteTable(std::shared_ptr<DeleteTableRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteTable does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteTable does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteTableCell(std::shared_ptr<DeleteTableCellRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteTableCell does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteTableCell does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteTableRow(std::shared_ptr<DeleteTableRowRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"),
        ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteTableRow does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteTableRow does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::deleteTableWithoutNodePath(std::shared_ptr<DeleteTableWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteTableWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteTableWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::deleteWatermark(std::shared_ptr<DeleteWatermarkRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/watermarks/deleteLast"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteWatermark does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteWatermark does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling deleteWatermark: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::downloadFile(std::shared_ptr<DownloadFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getVersionId())
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
        throw ApiException(415, _XPLATSTR("WordsApi->downloadFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::executeMailMerge(std::shared_ptr<ExecuteMailMergeRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/MailMerge"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->executeMailMerge does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getData())
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Data"), ApiClient::parameterToString(*(request->getData()))));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getWithRegions())
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getMailMergeDataFile())
    {
        queryParams[_XPLATSTR("MailMergeDataFile")] = ApiClient::parameterToString(*(request->getMailMergeDataFile()));
    }
    if (request->getCleanup())
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getUseWholeParagraphAsRegion())
    {
        queryParams[_XPLATSTR("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(*(request->getUseWholeParagraphAsRegion()));
    }
    if (request->getDestFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->executeMailMerge does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling executeMailMerge: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::executeMailMergeOnline(std::shared_ptr<ExecuteMailMergeOnlineRequest> request)
{

    // verify the required parameter '_template' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '_template' when calling WordsApi->executeMailMergeOnline"));
    }

    // verify the required parameter 'data' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'data' when calling WordsApi->executeMailMergeOnline"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/MailMerge"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getTemplate() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Template"), (request->getTemplate())));
    }
    if (request->getData() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Data"), (request->getData())));
    }
    if (request->getWithRegions())
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getCleanup())
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getDocumentFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->executeMailMergeOnline does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<AvailableFontsResponse>> WordsApi::getAvailableFonts(std::shared_ptr<GetAvailableFontsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/fonts/available"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getAvailableFonts does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getAvailableFonts does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getAvailableFonts: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BookmarkResponse>> WordsApi::getBookmarkByName(std::shared_ptr<GetBookmarkByNameRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/bookmarks/{bookmarkName}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("bookmarkName"),
        ApiClient::parameterToString(request->getBookmarkName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getBookmarkByName does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getBookmarkByName does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getBookmarkByName: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BookmarksResponse>> WordsApi::getBookmarks(std::shared_ptr<GetBookmarksRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/bookmarks"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getBookmarks does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getBookmarks does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getBookmarks: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BorderResponse>> WordsApi::getBorder(std::shared_ptr<GetBorderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders/{borderType}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("borderType"),
        ApiClient::parameterToString(request->getBorderType()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getBorder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getBorder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getBorder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BordersResponse>> WordsApi::getBorders(std::shared_ptr<GetBordersRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getBorders does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getBorders does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getBorders: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentResponse>> WordsApi::getComment(std::shared_ptr<GetCommentRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments/{commentIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("commentIndex"),
        ApiClient::parameterToString(request->getCommentIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getComment does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getComment: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentsResponse>> WordsApi::getComments(std::shared_ptr<GetCommentsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getComments does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getComments does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getComments: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::getDocument(std::shared_ptr<GetDocumentRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{documentName}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("documentName"),
        ApiClient::parameterToString(request->getDocumentName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::getDocumentDrawingObjectByIndex(std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentDrawingObjectByIndex does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjectByIndex does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentDrawingObjectByIndex: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::getDocumentDrawingObjectByIndexWithoutNodePath(std::shared_ptr<GetDocumentDrawingObjectByIndexWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentDrawingObjectByIndexWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjectByIndexWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentDrawingObjectByIndexWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectImageData(std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}/imageData"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjectImageData does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectImageDataWithoutNodePath(std::shared_ptr<GetDocumentDrawingObjectImageDataWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}/imageData"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjectImageDataWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectOleData(std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}/oleData"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjectOleData does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectOleDataWithoutNodePath(std::shared_ptr<GetDocumentDrawingObjectOleDataWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}/oleData"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjectOleDataWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<DrawingObjectsResponse>> WordsApi::getDocumentDrawingObjects(std::shared_ptr<GetDocumentDrawingObjectsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentDrawingObjects does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjects does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentDrawingObjects: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectsResponse>> WordsApi::getDocumentDrawingObjectsWithoutNodePath(std::shared_ptr<GetDocumentDrawingObjectsWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentDrawingObjectsWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentDrawingObjectsWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentDrawingObjectsWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldNamesResponse>> WordsApi::getDocumentFieldNames(std::shared_ptr<GetDocumentFieldNamesRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/mailMerge/FieldNames"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentFieldNames does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getUseNonMergeFields())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentFieldNames does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentFieldNames: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldNamesResponse>> WordsApi::getDocumentFieldNamesOnline(std::shared_ptr<GetDocumentFieldNamesOnlineRequest> request)
{

    // verify the required parameter '_template' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter '_template' when calling WordsApi->getDocumentFieldNamesOnline"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/mailMerge/FieldNames"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentFieldNamesOnline does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getTemplate() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("Template"), (request->getTemplate())));
    }
    if (request->getUseNonMergeFields())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentFieldNamesOnline does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentFieldNamesOnline: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HyperlinkResponse>> WordsApi::getDocumentHyperlinkByIndex(std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/hyperlinks/{hyperlinkIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("hyperlinkIndex"),
        ApiClient::parameterToString(request->getHyperlinkIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentHyperlinkByIndex does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentHyperlinkByIndex does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentHyperlinkByIndex: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HyperlinksResponse>> WordsApi::getDocumentHyperlinks(std::shared_ptr<GetDocumentHyperlinksRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/hyperlinks"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentHyperlinks does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentHyperlinks does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentHyperlinks: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentPropertiesResponse>> WordsApi::getDocumentProperties(std::shared_ptr<GetDocumentPropertiesRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentProperties does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentProperties does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentProperties: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentPropertyResponse>> WordsApi::getDocumentProperty(std::shared_ptr<GetDocumentPropertyRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/documentProperties/{propertyName}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("propertyName"),
        ApiClient::parameterToString(request->getPropertyName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentProperty does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentProperty does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentProperty: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ProtectionDataResponse>> WordsApi::getDocumentProtection(std::shared_ptr<GetDocumentProtectionRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentProtection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentProtection does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentProtection: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<StatDataResponse>> WordsApi::getDocumentStatistics(std::shared_ptr<GetDocumentStatisticsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/statistics"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentStatistics does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getIncludeComments())
    {
        queryParams[_XPLATSTR("IncludeComments")] = ApiClient::parameterToString(*(request->getIncludeComments()));
    }
    if (request->getIncludeFootnotes())
    {
        queryParams[_XPLATSTR("IncludeFootnotes")] = ApiClient::parameterToString(*(request->getIncludeFootnotes()));
    }
    if (request->getIncludeTextInShapes())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentStatistics does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getDocumentStatistics: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::getDocumentWithFormat(std::shared_ptr<GetDocumentWithFormatRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getOutPath())
    {
        queryParams[_XPLATSTR("OutPath")] = ApiClient::parameterToString(*(request->getOutPath()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentWithFormat does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<FieldResponse>> WordsApi::getField(std::shared_ptr<GetFieldRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::getFieldWithoutNodePath(std::shared_ptr<GetFieldWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFieldWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFieldWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFieldWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldsResponse>> WordsApi::getFields(std::shared_ptr<GetFieldsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFields does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFields: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldsResponse>> WordsApi::getFieldsWithoutNodePath(std::shared_ptr<GetFieldsWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFieldsWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFieldsWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFieldsWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FilesList>> WordsApi::getFilesList(std::shared_ptr<GetFilesListRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFilesList does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorageName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFilesList does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFilesList: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::getFootnote(std::shared_ptr<GetFootnoteRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFootnote does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFootnote: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::getFootnoteWithoutNodePath(std::shared_ptr<GetFootnoteWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFootnoteWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFootnoteWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFootnoteWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnotesResponse>> WordsApi::getFootnotes(std::shared_ptr<GetFootnotesRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFootnotes does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFootnotes does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFootnotes: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnotesResponse>> WordsApi::getFootnotesWithoutNodePath(std::shared_ptr<GetFootnotesWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFootnotesWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFootnotesWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFootnotesWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::getFormField(std::shared_ptr<GetFormFieldRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFormField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFormField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::getFormFieldWithoutNodePath(std::shared_ptr<GetFormFieldWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFormFieldWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFormFieldWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFormFieldWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldsResponse>> WordsApi::getFormFields(std::shared_ptr<GetFormFieldsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFormFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFormFields does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFormFields: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldsResponse>> WordsApi::getFormFieldsWithoutNodePath(std::shared_ptr<GetFormFieldsWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFormFieldsWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getFormFieldsWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getFormFieldsWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFooterResponse>> WordsApi::getHeaderFooter(std::shared_ptr<GetHeaderFooterRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/headersfooters/{headerFooterIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("headerFooterIndex"),
        ApiClient::parameterToString(request->getHeaderFooterIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getHeaderFooter does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getHeaderFooter does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getHeaderFooter: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFooterResponse>> WordsApi::getHeaderFooterOfSection(std::shared_ptr<GetHeaderFooterOfSectionRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}/headersfooters/{headerFooterIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("headerFooterIndex"),
        ApiClient::parameterToString(request->getHeaderFooterIndex()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getHeaderFooterOfSection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getHeaderFooterOfSection does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getHeaderFooterOfSection: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFootersResponse>> WordsApi::getHeaderFooters(std::shared_ptr<GetHeaderFootersRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"),
        ApiClient::parameterToString(request->getSectionPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getHeaderFooters does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getHeaderFooters does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getHeaderFooters: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ListResponse>> WordsApi::getList(std::shared_ptr<GetListRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/lists/{listId}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("listId"),
        ApiClient::parameterToString(request->getListId()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getList does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getList does not consume any supported media type"));
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
		AsposeResponse<ListResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ListResponse>(new ListResponse())
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
                , _XPLATSTR("error calling getList: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ListsResponse>> WordsApi::getLists(std::shared_ptr<GetListsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/lists"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getLists does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getLists does not consume any supported media type"));
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
		AsposeResponse<ListsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ListsResponse>(new ListsResponse())
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
                , _XPLATSTR("error calling getLists: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectResponse>> WordsApi::getOfficeMathObject(std::shared_ptr<GetOfficeMathObjectRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getOfficeMathObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getOfficeMathObject does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getOfficeMathObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectResponse>> WordsApi::getOfficeMathObjectWithoutNodePath(std::shared_ptr<GetOfficeMathObjectWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getOfficeMathObjectWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getOfficeMathObjectWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getOfficeMathObjectWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectsResponse>> WordsApi::getOfficeMathObjects(std::shared_ptr<GetOfficeMathObjectsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getOfficeMathObjects does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getOfficeMathObjects does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getOfficeMathObjects: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<OfficeMathObjectsResponse>> WordsApi::getOfficeMathObjectsWithoutNodePath(std::shared_ptr<GetOfficeMathObjectsWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getOfficeMathObjectsWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getOfficeMathObjectsWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getOfficeMathObjectsWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphResponse>> WordsApi::getParagraph(std::shared_ptr<GetParagraphRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getParagraph does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getParagraph does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getParagraph: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphFormatResponse>> WordsApi::getParagraphFormat(std::shared_ptr<GetParagraphFormatRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}/format"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getParagraphFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getParagraphFormat does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getParagraphFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphFormatResponse>> WordsApi::getParagraphFormatWithoutNodePath(std::shared_ptr<GetParagraphFormatWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}/format"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getParagraphFormatWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getParagraphFormatWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getParagraphFormatWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphResponse>> WordsApi::getParagraphWithoutNodePath(std::shared_ptr<GetParagraphWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getParagraphWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getParagraphWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getParagraphWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphLinkCollectionResponse>> WordsApi::getParagraphs(std::shared_ptr<GetParagraphsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getParagraphs does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getParagraphs does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getParagraphs: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphLinkCollectionResponse>> WordsApi::getParagraphsWithoutNodePath(std::shared_ptr<GetParagraphsWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getParagraphsWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getParagraphsWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getParagraphsWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RangeTextResponse>> WordsApi::getRangeText(std::shared_ptr<GetRangeTextRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("rangeStartIdentifier"),
        ApiClient::parameterToString(request->getRangeStartIdentifier()));
    path = replacePathParameter(path, _XPLATSTR("rangeEndIdentifier"), 
        extractOptional(request->getRangeEndIdentifier()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getRangeText does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getRangeText does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getRangeText: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunResponse>> WordsApi::getRun(std::shared_ptr<GetRunRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getRun does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getRun: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FontResponse>> WordsApi::getRunFont(std::shared_ptr<GetRunFontRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}/font"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getRunFont does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getRunFont does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getRunFont: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunsResponse>> WordsApi::getRuns(std::shared_ptr<GetRunsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getRuns does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getRuns does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getRuns: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionResponse>> WordsApi::getSection(std::shared_ptr<GetSectionRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getSection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getSection does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getSection: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionPageSetupResponse>> WordsApi::getSectionPageSetup(std::shared_ptr<GetSectionPageSetupRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}/pageSetup"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getSectionPageSetup does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getSectionPageSetup does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getSectionPageSetup: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionLinkCollectionResponse>> WordsApi::getSections(std::shared_ptr<GetSectionsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getSections does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getSections does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getSections: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::getTable(std::shared_ptr<GetTableRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTable does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTable does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTable: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellResponse>> WordsApi::getTableCell(std::shared_ptr<GetTableCellRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableCell does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTableCell does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTableCell: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellFormatResponse>> WordsApi::getTableCellFormat(std::shared_ptr<GetTableCellFormatRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}/cellformat"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableCellFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTableCellFormat does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTableCellFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::getTableProperties(std::shared_ptr<GetTablePropertiesRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}/properties"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableProperties does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTableProperties does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTableProperties: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::getTablePropertiesWithoutNodePath(std::shared_ptr<GetTablePropertiesWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}/properties"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTablePropertiesWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTablePropertiesWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTablePropertiesWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowResponse>> WordsApi::getTableRow(std::shared_ptr<GetTableRowRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"),
        ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableRow does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTableRow does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTableRow: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowFormatResponse>> WordsApi::getTableRowFormat(std::shared_ptr<GetTableRowFormatRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}/rowformat"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"),
        ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableRowFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTableRowFormat does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTableRowFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::getTableWithoutNodePath(std::shared_ptr<GetTableWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTableWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTableWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableLinkCollectionResponse>> WordsApi::getTables(std::shared_ptr<GetTablesRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTables does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTables does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTables: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableLinkCollectionResponse>> WordsApi::getTablesWithoutNodePath(std::shared_ptr<GetTablesWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTablesWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->getTablesWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling getTablesWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentResponse>> WordsApi::insertComment(std::shared_ptr<InsertCommentRequest> request)
{

    // verify the required parameter 'comment' is set
    if (request->getComment() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'comment' when calling WordsApi->insertComment"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getComment())->toMultipart(multipart, _XPLATSTR("comment"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertComment does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertComment: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::insertDrawingObject(std::shared_ptr<InsertDrawingObjectRequest> request)
{

    // verify the required parameter 'imageFile' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'imageFile' when calling WordsApi->insertDrawingObject"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertDrawingObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("DrawingObject"), ApiClient::parameterToString((request->getDrawingObject()))));
    }
    if (request->getImageFile() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->insertDrawingObject does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertDrawingObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::insertDrawingObjectWithoutNodePath(std::shared_ptr<InsertDrawingObjectWithoutNodePathRequest> request)
{

    // verify the required parameter 'imageFile' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'imageFile' when calling WordsApi->insertDrawingObjectWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertDrawingObjectWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("DrawingObject"), ApiClient::parameterToString((request->getDrawingObject()))));
    }
    if (request->getImageFile() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->insertDrawingObjectWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertDrawingObjectWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::insertField(std::shared_ptr<InsertFieldRequest> request)
{

    // verify the required parameter 'field' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'field' when calling WordsApi->insertField"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode())
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
            (request->getField())->toMultipart(multipart, _XPLATSTR("field"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::insertFieldWithoutNodePath(std::shared_ptr<InsertFieldWithoutNodePathRequest> request)
{

    // verify the required parameter 'field' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'field' when calling WordsApi->insertFieldWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/fields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertFieldWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode())
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
            (request->getField())->toMultipart(multipart, _XPLATSTR("field"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertFieldWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertFieldWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::insertFootnote(std::shared_ptr<InsertFootnoteRequest> request)
{

    // verify the required parameter 'footnoteDto' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'footnoteDto' when calling WordsApi->insertFootnote"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertFootnote does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertFootnote: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::insertFootnoteWithoutNodePath(std::shared_ptr<InsertFootnoteWithoutNodePathRequest> request)
{

    // verify the required parameter 'footnoteDto' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'footnoteDto' when calling WordsApi->insertFootnoteWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertFootnoteWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertFootnoteWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertFootnoteWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::insertFormField(std::shared_ptr<InsertFormFieldRequest> request)
{

    // verify the required parameter 'formField' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'formField' when calling WordsApi->insertFormField"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode())
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
            (request->getFormField())->toMultipart(multipart, _XPLATSTR("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertFormField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertFormField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::insertFormFieldWithoutNodePath(std::shared_ptr<InsertFormFieldWithoutNodePathRequest> request)
{

    // verify the required parameter 'formField' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'formField' when calling WordsApi->insertFormFieldWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertFormFieldWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode())
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
            (request->getFormField())->toMultipart(multipart, _XPLATSTR("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertFormFieldWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertFormFieldWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<HeaderFooterResponse>> WordsApi::insertHeaderFooter(std::shared_ptr<InsertHeaderFooterRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{sectionPath}/headersfooters"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"),
        ApiClient::parameterToString(request->getSectionPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertHeaderFooter does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        multipart->add(ModelBase::toHttpContent(_XPLATSTR("headerFooterType"), request->getHeaderFooterType()));

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertHeaderFooter does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertHeaderFooter: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ListResponse>> WordsApi::insertList(std::shared_ptr<InsertListRequest> request)
{

    // verify the required parameter 'listInsert' is set
    if (request->getListInsert() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'listInsert' when calling WordsApi->insertList"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/lists"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertList does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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

        json = ModelBase::toJson(request->getListInsert());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getListInsert().get())
        {
            (request->getListInsert())->toMultipart(multipart, _XPLATSTR("listInsert"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertList does not consume any supported media type"));
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
		AsposeResponse<ListResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ListResponse>(new ListResponse())
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
                , _XPLATSTR("error calling insertList: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::insertPageNumbers(std::shared_ptr<InsertPageNumbersRequest> request)
{

    // verify the required parameter 'pageNumber' is set
    if (request->getPageNumber() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'pageNumber' when calling WordsApi->insertPageNumbers"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/PageNumbers"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertPageNumbers does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getPageNumber())->toMultipart(multipart, _XPLATSTR("pageNumber"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertPageNumbers does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertPageNumbers: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphResponse>> WordsApi::insertParagraph(std::shared_ptr<InsertParagraphRequest> request)
{

    // verify the required parameter 'paragraph' is set
    if (request->getParagraph() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'paragraph' when calling WordsApi->insertParagraph"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertParagraph does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode())
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
            (request->getParagraph())->toMultipart(multipart, _XPLATSTR("paragraph"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertParagraph does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertParagraph: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunResponse>> WordsApi::insertRun(std::shared_ptr<InsertRunRequest> request)
{

    // verify the required parameter 'run' is set
    if (request->getRun() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'run' when calling WordsApi->insertRun"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode())
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
            (request->getRun())->toMultipart(multipart, _XPLATSTR("run"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertRun does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertRun: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::insertTable(std::shared_ptr<InsertTableRequest> request)
{

    // verify the required parameter 'table' is set
    if (request->getTable() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'table' when calling WordsApi->insertTable"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertTable does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getTable())->toMultipart(multipart, _XPLATSTR("table"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertTable does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertTable: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellResponse>> WordsApi::insertTableCell(std::shared_ptr<InsertTableCellRequest> request)
{

    // verify the required parameter 'cell' is set
    if (request->getCell() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'cell' when calling WordsApi->insertTableCell"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertTableCell does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getCell())->toMultipart(multipart, _XPLATSTR("cell"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertTableCell does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertTableCell: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowResponse>> WordsApi::insertTableRow(std::shared_ptr<InsertTableRowRequest> request)
{

    // verify the required parameter 'row' is set
    if (request->getRow() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'row' when calling WordsApi->insertTableRow"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"),
        ApiClient::parameterToString(request->getTablePath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertTableRow does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getRow())->toMultipart(multipart, _XPLATSTR("row"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertTableRow does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertTableRow: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableResponse>> WordsApi::insertTableWithoutNodePath(std::shared_ptr<InsertTableWithoutNodePathRequest> request)
{

    // verify the required parameter 'table' is set
    if (request->getTable() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'table' when calling WordsApi->insertTableWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertTableWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getTable())->toMultipart(multipart, _XPLATSTR("table"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertTableWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertTableWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::insertWatermarkImage(std::shared_ptr<InsertWatermarkImageRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/watermarks/images"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertWatermarkImage does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getImageFile() && *(request->getImageFile()) != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("ImageFile"), *(request->getImageFile())));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getRotationAngle())
    {
        queryParams[_XPLATSTR("RotationAngle")] = ApiClient::parameterToString(*(request->getRotationAngle()));
    }
    if (request->getImage())
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
        throw ApiException(415, _XPLATSTR("WordsApi->insertWatermarkImage does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertWatermarkImage: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::insertWatermarkText(std::shared_ptr<InsertWatermarkTextRequest> request)
{

    // verify the required parameter 'watermarkText' is set
    if (request->getWatermarkText() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'watermarkText' when calling WordsApi->insertWatermarkText"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/watermarks/texts"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertWatermarkText does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getWatermarkText())->toMultipart(multipart, _XPLATSTR("watermarkText"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertWatermarkText does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling insertWatermarkText: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SaveResponse>> WordsApi::loadWebDocument(std::shared_ptr<LoadWebDocumentRequest> request)
{

    // verify the required parameter 'data' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'data' when calling WordsApi->loadWebDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/loadWebDocument"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->loadWebDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorage())
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
            (request->getData())->toMultipart(multipart, _XPLATSTR("data"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->loadWebDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling loadWebDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::moveFile(std::shared_ptr<MoveFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/move/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->moveFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }
    if (request->getVersionId())
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
        throw ApiException(415, _XPLATSTR("WordsApi->moveFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::moveFolder(std::shared_ptr<MoveFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/folder/move/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->moveFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->moveFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<ProtectionDataResponse>> WordsApi::protectDocument(std::shared_ptr<ProtectDocumentRequest> request)
{

    // verify the required parameter 'protectionRequest' is set
    if (request->getProtectionRequest() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'protectionRequest' when calling WordsApi->protectDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->protectDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
            (request->getProtectionRequest())->toMultipart(multipart, _XPLATSTR("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->protectDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling protectDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RevisionsModificationResponse>> WordsApi::rejectAllRevisions(std::shared_ptr<RejectAllRevisionsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/revisions/rejectAll"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->rejectAllRevisions does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->rejectAllRevisions does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling rejectAllRevisions: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::removeRange(std::shared_ptr<RemoveRangeRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("rangeStartIdentifier"),
        ApiClient::parameterToString(request->getRangeStartIdentifier()));
    path = replacePathParameter(path, _XPLATSTR("rangeEndIdentifier"), 
        extractOptional(request->getRangeEndIdentifier()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->removeRange does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->removeRange does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling removeRange: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> WordsApi::renderDrawingObject(std::shared_ptr<RenderDrawingObjectRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderDrawingObject does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderDrawingObjectWithoutNodePath(std::shared_ptr<RenderDrawingObjectWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderDrawingObjectWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderMathObject(std::shared_ptr<RenderMathObjectRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/OfficeMathObjects/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderMathObject does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderMathObjectWithoutNodePath(std::shared_ptr<RenderMathObjectWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/OfficeMathObjects/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderMathObjectWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderPage(std::shared_ptr<RenderPageRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/pages/{pageIndex}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("pageIndex"),
        ApiClient::parameterToString(request->getPageIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderPage does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderParagraph(std::shared_ptr<RenderParagraphRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderParagraph does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderParagraphWithoutNodePath(std::shared_ptr<RenderParagraphWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/paragraphs/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderParagraphWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderTable(std::shared_ptr<RenderTableRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderTable does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<HttpContent> WordsApi::renderTableWithoutNodePath(std::shared_ptr<RenderTableWithoutNodePathRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}/render"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->renderTableWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<ReplaceTextResponse>> WordsApi::replaceText(std::shared_ptr<ReplaceTextRequest> request)
{

    // verify the required parameter 'replaceText' is set
    if (request->getReplaceText() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'replaceText' when calling WordsApi->replaceText"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/replaceText"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->replaceText does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getReplaceText())->toMultipart(multipart, _XPLATSTR("replaceText"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->replaceText does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling replaceText: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::replaceWithText(std::shared_ptr<ReplaceWithTextRequest> request)
{

    // verify the required parameter 'rangeText' is set
    if (request->getRangeText() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'rangeText' when calling WordsApi->replaceWithText"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("rangeStartIdentifier"),
        ApiClient::parameterToString(request->getRangeStartIdentifier()));
    path = replacePathParameter(path, _XPLATSTR("rangeEndIdentifier"), 
        extractOptional(request->getRangeEndIdentifier()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->replaceWithText does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
            (request->getRangeText())->toMultipart(multipart, _XPLATSTR("rangeText"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->replaceWithText does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling replaceWithText: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> WordsApi::resetCache(std::shared_ptr<ResetCacheRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/fonts/cache"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->resetCache does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));


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
        throw ApiException(415, _XPLATSTR("WordsApi->resetCache does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
pplx::task<AsposeResponse<SaveResponse>> WordsApi::saveAs(std::shared_ptr<SaveAsRequest> request)
{

    // verify the required parameter 'saveOptionsData' is set
    if (request->getSaveOptionsData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'saveOptionsData' when calling WordsApi->saveAs"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/saveAs"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->saveAs does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation())
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
            (request->getSaveOptionsData())->toMultipart(multipart, _XPLATSTR("saveOptionsData"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->saveAs does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling saveAs: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::saveAsRange(std::shared_ptr<SaveAsRangeRequest> request)
{

    // verify the required parameter 'documentParameters' is set
    if (request->getDocumentParameters() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'documentParameters' when calling WordsApi->saveAsRange"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/range/{rangeStartIdentifier}/{rangeEndIdentifier}/SaveAs"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("rangeStartIdentifier"),
        ApiClient::parameterToString(request->getRangeStartIdentifier()));
    path = replacePathParameter(path, _XPLATSTR("rangeEndIdentifier"), 
        extractOptional(request->getRangeEndIdentifier()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->saveAsRange does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
            (request->getDocumentParameters())->toMultipart(multipart, _XPLATSTR("documentParameters"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->saveAsRange does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling saveAsRange: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SaveResponse>> WordsApi::saveAsTiff(std::shared_ptr<SaveAsTiffRequest> request)
{

    // verify the required parameter 'saveOptions' is set
    if (request->getSaveOptions() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'saveOptions' when calling WordsApi->saveAsTiff"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/saveAs/tiff"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->saveAsTiff does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getUseAntiAliasing())
    {
        queryParams[_XPLATSTR("UseAntiAliasing")] = ApiClient::parameterToString(*(request->getUseAntiAliasing()));
    }
    if (request->getUseHighQualityRendering())
    {
        queryParams[_XPLATSTR("UseHighQualityRendering")] = ApiClient::parameterToString(*(request->getUseHighQualityRendering()));
    }
    if (request->getImageBrightness())
    {
        queryParams[_XPLATSTR("ImageBrightness")] = ApiClient::parameterToString(*(request->getImageBrightness()));
    }
    if (request->getImageColorMode())
    {
        queryParams[_XPLATSTR("ImageColorMode")] = ApiClient::parameterToString(*(request->getImageColorMode()));
    }
    if (request->getImageContrast())
    {
        queryParams[_XPLATSTR("ImageContrast")] = ApiClient::parameterToString(*(request->getImageContrast()));
    }
    if (request->getNumeralFormat())
    {
        queryParams[_XPLATSTR("NumeralFormat")] = ApiClient::parameterToString(*(request->getNumeralFormat()));
    }
    if (request->getPageCount())
    {
        queryParams[_XPLATSTR("PageCount")] = ApiClient::parameterToString(*(request->getPageCount()));
    }
    if (request->getPageIndex())
    {
        queryParams[_XPLATSTR("PageIndex")] = ApiClient::parameterToString(*(request->getPageIndex()));
    }
    if (request->getPaperColor())
    {
        queryParams[_XPLATSTR("PaperColor")] = ApiClient::parameterToString(*(request->getPaperColor()));
    }
    if (request->getPixelFormat())
    {
        queryParams[_XPLATSTR("PixelFormat")] = ApiClient::parameterToString(*(request->getPixelFormat()));
    }
    if (request->getResolution())
    {
        queryParams[_XPLATSTR("Resolution")] = ApiClient::parameterToString(*(request->getResolution()));
    }
    if (request->getScale())
    {
        queryParams[_XPLATSTR("Scale")] = ApiClient::parameterToString(*(request->getScale()));
    }
    if (request->getTiffCompression())
    {
        queryParams[_XPLATSTR("TiffCompression")] = ApiClient::parameterToString(*(request->getTiffCompression()));
    }
    if (request->getDmlRenderingMode())
    {
        queryParams[_XPLATSTR("DmlRenderingMode")] = ApiClient::parameterToString(*(request->getDmlRenderingMode()));
    }
    if (request->getDmlEffectsRenderingMode())
    {
        queryParams[_XPLATSTR("DmlEffectsRenderingMode")] = ApiClient::parameterToString(*(request->getDmlEffectsRenderingMode()));
    }
    if (request->getTiffBinarizationMethod())
    {
        queryParams[_XPLATSTR("TiffBinarizationMethod")] = ApiClient::parameterToString(*(request->getTiffBinarizationMethod()));
    }
    if (request->getZipOutput())
    {
        queryParams[_XPLATSTR("ZipOutput")] = ApiClient::parameterToString(*(request->getZipOutput()));
    }
    if (request->getFontsLocation())
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
            (request->getSaveOptions())->toMultipart(multipart, _XPLATSTR("saveOptions"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->saveAsTiff does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling saveAsTiff: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SearchResponse>> WordsApi::search(std::shared_ptr<SearchRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/search"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->search does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Pattern")] = ApiClient::parameterToString((request->getPattern()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
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
        throw ApiException(415, _XPLATSTR("WordsApi->search does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling search: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SplitDocumentResponse>> WordsApi::splitDocument(std::shared_ptr<SplitDocumentRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/split"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->splitDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getFrom())
    {
        queryParams[_XPLATSTR("From")] = ApiClient::parameterToString(*(request->getFrom()));
    }
    if (request->getTo())
    {
        queryParams[_XPLATSTR("To")] = ApiClient::parameterToString(*(request->getTo()));
    }
    if (request->getZipOutput())
    {
        queryParams[_XPLATSTR("ZipOutput")] = ApiClient::parameterToString(*(request->getZipOutput()));
    }
    if (request->getFontsLocation())
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
        throw ApiException(415, _XPLATSTR("WordsApi->splitDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling splitDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ProtectionDataResponse>> WordsApi::unprotectDocument(std::shared_ptr<UnprotectDocumentRequest> request)
{

    // verify the required parameter 'protectionRequest' is set
    if (request->getProtectionRequest() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'protectionRequest' when calling WordsApi->unprotectDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->unprotectDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
            (request->getProtectionRequest())->toMultipart(multipart, _XPLATSTR("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->unprotectDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling unprotectDocument: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BookmarkResponse>> WordsApi::updateBookmark(std::shared_ptr<UpdateBookmarkRequest> request)
{

    // verify the required parameter 'bookmarkData' is set
    if (request->getBookmarkData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'bookmarkData' when calling WordsApi->updateBookmark"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/bookmarks/{bookmarkName}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("bookmarkName"),
        ApiClient::parameterToString(request->getBookmarkName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateBookmark does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getBookmarkData())->toMultipart(multipart, _XPLATSTR("bookmarkData"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateBookmark does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateBookmark: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<BorderResponse>> WordsApi::updateBorder(std::shared_ptr<UpdateBorderRequest> request)
{

    // verify the required parameter 'borderProperties' is set
    if (request->getBorderProperties() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'borderProperties' when calling WordsApi->updateBorder"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders/{borderType}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("borderType"),
        ApiClient::parameterToString(request->getBorderType()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateBorder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getBorderProperties())->toMultipart(multipart, _XPLATSTR("borderProperties"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateBorder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateBorder: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<CommentResponse>> WordsApi::updateComment(std::shared_ptr<UpdateCommentRequest> request)
{

    // verify the required parameter 'comment' is set
    if (request->getComment() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'comment' when calling WordsApi->updateComment"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments/{commentIndex}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("commentIndex"),
        ApiClient::parameterToString(request->getCommentIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getComment())->toMultipart(multipart, _XPLATSTR("comment"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateComment does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateComment: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::updateDrawingObject(std::shared_ptr<UpdateDrawingObjectRequest> request)
{

    // verify the required parameter 'imageFile' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'imageFile' when calling WordsApi->updateDrawingObject"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/drawingObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateDrawingObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("DrawingObject"), ApiClient::parameterToString((request->getDrawingObject()))));
    }
    if (request->getImageFile() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->updateDrawingObject does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateDrawingObject: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DrawingObjectResponse>> WordsApi::updateDrawingObjectWithoutNodePath(std::shared_ptr<UpdateDrawingObjectWithoutNodePathRequest> request)
{

    // verify the required parameter 'imageFile' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'imageFile' when calling WordsApi->updateDrawingObjectWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/drawingObjects/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateDrawingObjectWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("DrawingObject"), ApiClient::parameterToString((request->getDrawingObject()))));
    }
    if (request->getImageFile() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
        throw ApiException(415, _XPLATSTR("WordsApi->updateDrawingObjectWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateDrawingObjectWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FieldResponse>> WordsApi::updateField(std::shared_ptr<UpdateFieldRequest> request)
{

    // verify the required parameter 'field' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'field' when calling WordsApi->updateField"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/fields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getField())->toMultipart(multipart, _XPLATSTR("field"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<DocumentResponse>> WordsApi::updateFields(std::shared_ptr<UpdateFieldsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/updateFields"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->updateFields does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateFields: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::updateFootnote(std::shared_ptr<UpdateFootnoteRequest> request)
{

    // verify the required parameter 'footnoteDto' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'footnoteDto' when calling WordsApi->updateFootnote"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/footnotes/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateFootnote does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateFootnote: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FootnoteResponse>> WordsApi::updateFootnoteWithoutNodePath(std::shared_ptr<UpdateFootnoteWithoutNodePathRequest> request)
{

    // verify the required parameter 'footnoteDto' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'footnoteDto' when calling WordsApi->updateFootnoteWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/footnotes/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateFootnoteWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateFootnoteWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateFootnoteWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::updateFormField(std::shared_ptr<UpdateFormFieldRequest> request)
{

    // verify the required parameter 'formField' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'formField' when calling WordsApi->updateFormField"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/formfields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFormField())->toMultipart(multipart, _XPLATSTR("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateFormField does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateFormField: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FormFieldResponse>> WordsApi::updateFormFieldWithoutNodePath(std::shared_ptr<UpdateFormFieldWithoutNodePathRequest> request)
{

    // verify the required parameter 'formField' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'formField' when calling WordsApi->updateFormFieldWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/formfields/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateFormFieldWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFormField())->toMultipart(multipart, _XPLATSTR("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateFormFieldWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateFormFieldWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ListResponse>> WordsApi::updateList(std::shared_ptr<UpdateListRequest> request)
{

    // verify the required parameter 'listUpdate' is set
    if (request->getListUpdate() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'listUpdate' when calling WordsApi->updateList"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/lists/{listId}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("listId"),
        ApiClient::parameterToString(request->getListId()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateList does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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

        json = ModelBase::toJson(request->getListUpdate());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getListUpdate().get())
        {
            (request->getListUpdate())->toMultipart(multipart, _XPLATSTR("listUpdate"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateList does not consume any supported media type"));
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
		AsposeResponse<ListResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ListResponse>(new ListResponse())
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
                , _XPLATSTR("error calling updateList: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ListResponse>> WordsApi::updateListLevel(std::shared_ptr<UpdateListLevelRequest> request)
{

    // verify the required parameter 'listUpdate' is set
    if (request->getListUpdate() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'listUpdate' when calling WordsApi->updateListLevel"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/lists/{listId}/{listLevel}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("listId"),
        ApiClient::parameterToString(request->getListId()));
    path = replacePathParameter(path, _XPLATSTR("listLevel"),
        ApiClient::parameterToString(request->getListLevel()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateListLevel does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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

        json = ModelBase::toJson(request->getListUpdate());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getListUpdate().get())
        {
            (request->getListUpdate())->toMultipart(multipart, _XPLATSTR("listUpdate"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateListLevel does not consume any supported media type"));
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
		AsposeResponse<ListResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<ListResponse>(new ListResponse())
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
                , _XPLATSTR("error calling updateListLevel: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<ParagraphFormatResponse>> WordsApi::updateParagraphFormat(std::shared_ptr<UpdateParagraphFormatRequest> request)
{

    // verify the required parameter 'dto' is set
    if (request->getDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'dto' when calling WordsApi->updateParagraphFormat"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/paragraphs/{index}/format"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateParagraphFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getDto())->toMultipart(multipart, _XPLATSTR("dto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateParagraphFormat does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateParagraphFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<RunResponse>> WordsApi::updateRun(std::shared_ptr<UpdateRunRequest> request)
{

    // verify the required parameter 'run' is set
    if (request->getRun() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'run' when calling WordsApi->updateRun"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getRun())->toMultipart(multipart, _XPLATSTR("run"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateRun does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateRun: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FontResponse>> WordsApi::updateRunFont(std::shared_ptr<UpdateRunFontRequest> request)
{

    // verify the required parameter 'fontDto' is set
    if (request->getFontDto() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'fontDto' when calling WordsApi->updateRunFont"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{paragraphPath}/runs/{index}/font"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateRunFont does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFontDto())->toMultipart(multipart, _XPLATSTR("fontDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateRunFont does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateRunFont: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<SectionPageSetupResponse>> WordsApi::updateSectionPageSetup(std::shared_ptr<UpdateSectionPageSetupRequest> request)
{

    // verify the required parameter 'pageSetup' is set
    if (request->getPageSetup() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'pageSetup' when calling WordsApi->updateSectionPageSetup"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections/{sectionIndex}/pageSetup"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateSectionPageSetup does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getPageSetup())->toMultipart(multipart, _XPLATSTR("pageSetup"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateSectionPageSetup does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateSectionPageSetup: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableCellFormatResponse>> WordsApi::updateTableCellFormat(std::shared_ptr<UpdateTableCellFormatRequest> request)
{

    // verify the required parameter 'format' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'format' when calling WordsApi->updateTableCellFormat"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tableRowPath}/cells/{index}/cellformat"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateTableCellFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFormat())->toMultipart(multipart, _XPLATSTR("format"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateTableCellFormat does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateTableCellFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::updateTableProperties(std::shared_ptr<UpdateTablePropertiesRequest> request)
{

    // verify the required parameter 'properties' is set
    if (request->getProperties() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'properties' when calling WordsApi->updateTableProperties"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/tables/{index}/properties"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"),
        ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateTableProperties does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getProperties())->toMultipart(multipart, _XPLATSTR("properties"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateTableProperties does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateTableProperties: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TablePropertiesResponse>> WordsApi::updateTablePropertiesWithoutNodePath(std::shared_ptr<UpdateTablePropertiesWithoutNodePathRequest> request)
{

    // verify the required parameter 'properties' is set
    if (request->getProperties() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'properties' when calling WordsApi->updateTablePropertiesWithoutNodePath"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/tables/{index}/properties"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateTablePropertiesWithoutNodePath does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getProperties())->toMultipart(multipart, _XPLATSTR("properties"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateTablePropertiesWithoutNodePath does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateTablePropertiesWithoutNodePath: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<TableRowFormatResponse>> WordsApi::updateTableRowFormat(std::shared_ptr<UpdateTableRowFormatRequest> request)
{

    // verify the required parameter 'format' is set
    if (request->getFormat() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'format' when calling WordsApi->updateTableRowFormat"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{tablePath}/rows/{index}/rowformat"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"),
        ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"),
        ApiClient::parameterToString(request->getIndex()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateTableRowFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage())
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding())
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword())
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor())
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime())
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
            (request->getFormat())->toMultipart(multipart, _XPLATSTR("format"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateTableRowFormat does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling updateTableRowFormat: unsupported response type"));
        }

        return result;
    });
}
pplx::task<AsposeResponse<FilesUploadResult>> WordsApi::uploadFile(std::shared_ptr<UploadFileRequest> request)
{

    // verify the required parameter 'fileContent' is set
    if (request->getFileContent() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'fileContent' when calling WordsApi->uploadFile"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/storage/file/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::vector<ApiClient::FormParamContainer> formParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));

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
        throw ApiException(400, _XPLATSTR("WordsApi->uploadFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getFileContent() != nullptr)
    {
        formParams.push_back(ApiClient::FormParamContainer(_XPLATSTR("FileContent"), (request->getFileContent())));
    }
    if (request->getStorageName())
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
        throw ApiException(415, _XPLATSTR("WordsApi->uploadFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
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
                , _XPLATSTR("error calling uploadFile: unsupported response type"));
        }

        return result;
    });
}

}
}
}
}


