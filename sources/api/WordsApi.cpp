/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApi.cpp">
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

#include "WordsApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

#include <boost/algorithm/string/replace.hpp>
#include <utility>

namespace io
{
namespace swagger
{
namespace client
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
        std::shared_ptr<FormFieldCollection> fields(new FormFieldCollection);

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

using namespace io::swagger::client::model;

WordsApi::WordsApi(std::shared_ptr<ApiClient> apiClient)
    : m_ApiClient(std::move(apiClient))
{
}

pplx::task<std::shared_ptr<RevisionsModificationResponse>> WordsApi::acceptAllRevisions(
    std::shared_ptr<AcceptAllRevisionsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/revisions/acceptAll"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->acceptAllRevisions does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling acceptAllRevisions: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<RevisionsModificationResponse> result(new RevisionsModificationResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<ClassificationResponse>> WordsApi::classify(std::shared_ptr<ClassifyRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/classify"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("text"), ApiClient::parameterToString(request->getText()));
    path = replacePathParameter(path, _XPLATSTR("bestClassesCount"), extractOptional(request->getBestClassesCount()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->classify does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getBestClassesCount() && bPath.find(_XPLATSTR("bestClassesCount")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        multipart->add(ModelBase::toHttpContent(_XPLATSTR("text"), request->getText()));

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->classify does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling classify: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ClassificationResponse> result(new ClassificationResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<ClassificationResponse>> WordsApi::classifyDocument(
    std::shared_ptr<ClassifyDocumentRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{documentName}/classify"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("documentName"),
        ApiClient::parameterToString(request->getDocumentName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("bestClassesCount"), extractOptional(request->getBestClassesCount()));
    path = replacePathParameter(path, _XPLATSTR("taxonomy"), extractOptional(request->getTaxonomy()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->classifyDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getBestClassesCount() && bPath.find(_XPLATSTR("bestClassesCount")) == std::string::npos)
    {
        queryParams[_XPLATSTR("BestClassesCount")] = ApiClient::parameterToString(*(request->getBestClassesCount()));
    }
    if (request->getTaxonomy() && bPath.find(_XPLATSTR("taxonomy")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling classifyDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ClassificationResponse> result(new ClassificationResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<DocumentPropertyResponse>> WordsApi::createOrUpdateDocumentProperty(
    std::shared_ptr<CreateOrUpdateDocumentPropertyRequest> request)
{
    // verify the required parameter 'property' is set
    if (request->getProperty() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'property' when calling WordsApi->createOrUpdateDocumentProperty"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/documentProperties/{propertyName}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("propertyName"),
        ApiClient::parameterToString(request->getPropertyName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->createOrUpdateDocumentProperty does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getProperty().get())
        {
            (request->getProperty())->toMultipart(multipart, _XPLATSTR("property"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->createOrUpdateDocumentProperty does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling createOrUpdateDocumentProperty: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentPropertyResponse> result(new DocumentPropertyResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                      _XPLATSTR(
"error calling createOrUpdateDocumentProperty: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<BorderResponse>> WordsApi::deleteBorder(std::shared_ptr<DeleteBorderRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteBorder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteBorder: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BorderResponse> result(new BorderResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<BordersResponse>> WordsApi::deleteBorders(std::shared_ptr<DeleteBordersRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/{nodePath}/borders"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteBorders does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteBorders: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BordersResponse> result(new BordersResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteComment(std::shared_ptr<DeleteCommentRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments/{commentIndex}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("commentIndex"),
        ApiClient::parameterToString(request->getCommentIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteComment: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteComment: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteDocumentMacros(
    std::shared_ptr<DeleteDocumentMacrosRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/macros"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteDocumentMacros does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->deleteDocumentMacros does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteDocumentMacros: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteDocumentMacros: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteDocumentProperty(
    std::shared_ptr<DeleteDocumentPropertyRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/documentProperties/{propertyName}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("propertyName"),
        ApiClient::parameterToString(request->getPropertyName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->deleteDocumentProperty does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->deleteDocumentProperty does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteDocumentProperty: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteDocumentProperty: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::deleteDocumentWatermark(
    std::shared_ptr<DeleteDocumentWatermarkRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/watermark"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->deleteDocumentWatermark does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->deleteDocumentWatermark does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteDocumentWatermark: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteDocumentWatermark: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteDrawingObject(
    std::shared_ptr<DeleteDrawingObjectRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteDrawingObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteDrawingObject: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteDrawingObject: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteField(std::shared_ptr<DeleteFieldRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/fields/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteField: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteFields(std::shared_ptr<DeleteFieldsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/fields"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteFields: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteFields: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteFootnote(std::shared_ptr<DeleteFootnoteRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/footnotes/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteFootnote: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteFootnote: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteFormField(std::shared_ptr<DeleteFormFieldRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/formfields/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteFormField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteFormField: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteHeaderFooter(
    std::shared_ptr<DeleteHeaderFooterRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{sectionPath}/headersfooters/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"), extractOptional(request->getSectionPath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteHeaderFooter does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getSectionPath() && bPath.find(_XPLATSTR("sectionPath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("SectionPath")] = ApiClient::parameterToString(*(request->getSectionPath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteHeaderFooter: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteHeaderFooter: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteHeadersFooters(
    std::shared_ptr<DeleteHeadersFootersRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{sectionPath}/headersfooters"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"), extractOptional(request->getSectionPath()));
    path = replacePathParameter(path, _XPLATSTR("headersFootersTypes"),
        extractOptional(request->getHeadersFootersTypes()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteHeadersFooters does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getSectionPath() && bPath.find(_XPLATSTR("sectionPath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("SectionPath")] = ApiClient::parameterToString(*(request->getSectionPath()));
    }
    if (request->getHeadersFootersTypes() && bPath.find(_XPLATSTR("headersFootersTypes")) == std::string::npos)
    {
        queryParams[_XPLATSTR("HeadersFootersTypes")] = ApiClient::parameterToString(
            *(request->getHeadersFootersTypes()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteHeadersFooters: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteHeadersFooters: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteOfficeMathObject(
    std::shared_ptr<DeleteOfficeMathObjectRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/OfficeMathObjects/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->deleteOfficeMathObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->deleteOfficeMathObject does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteOfficeMathObject: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteOfficeMathObject: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteParagraph(std::shared_ptr<DeleteParagraphRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/paragraphs/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteParagraph does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteParagraph: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteParagraph: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteRun(std::shared_ptr<DeleteRunRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{paragraphPath}/runs/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteRun: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteRun: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteTable(std::shared_ptr<DeleteTableRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/tables/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteTable does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteTable: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteTable: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteTableCell(std::shared_ptr<DeleteTableCellRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tableRowPath}/cells/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteTableCell does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteTableCell: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteTableCell: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::deleteTableRow(std::shared_ptr<DeleteTableRowRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tablePath}/rows/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"), ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->deleteTableRow does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteTableRow: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteTableRow: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::deleteUnprotectDocument(
    std::shared_ptr<DeleteUnprotectDocumentRequest> request)
{
    // verify the required parameter 'protectionRequest' is set
    if (request->getProtectionRequest() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'protectionRequest' when calling WordsApi->deleteUnprotectDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection")
                      ,
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->deleteUnprotectDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getProtectionRequest().get())
        {
            (request->getProtectionRequest())->toMultipart(multipart, _XPLATSTR("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->deleteUnprotectDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling deleteUnprotectDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling deleteUnprotectDocument: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<AvailableFontsResponse>> WordsApi::getAvailableFonts(
    std::shared_ptr<GetAvailableFontsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/fonts/available"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getAvailableFonts does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getAvailableFonts: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AvailableFontsResponse> result(new AvailableFontsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<BorderResponse>> WordsApi::getBorder(std::shared_ptr<GetBorderRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/borders/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getBorder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getBorder: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BorderResponse> result(new BorderResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<BordersResponse>> WordsApi::getBorders(std::shared_ptr<GetBordersRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/borders"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getBorders does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getBorders: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BordersResponse> result(new BordersResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<CommentResponse>> WordsApi::getComment(std::shared_ptr<GetCommentRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/comments/{commentIndex}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("commentIndex"),
        ApiClient::parameterToString(request->getCommentIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getComment: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<CommentResponse> result(new CommentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<CommentsResponse>> WordsApi::getComments(std::shared_ptr<GetCommentsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getComments does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getComments: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<CommentsResponse> result(new CommentsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::getDocument(std::shared_ptr<GetDocumentRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{documentName}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("documentName"),
        ApiClient::parameterToString(request->getDocumentName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<BookmarkResponse>> WordsApi::getDocumentBookmarkByName(
    std::shared_ptr<GetDocumentBookmarkByNameRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/bookmarks/{bookmarkName}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("bookmarkName"),
        ApiClient::parameterToString(request->getBookmarkName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentBookmarkByName does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentBookmarkByName does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentBookmarkByName: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BookmarkResponse> result(new BookmarkResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentBookmarkByName: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<BookmarksResponse>> WordsApi::getDocumentBookmarks(
    std::shared_ptr<GetDocumentBookmarksRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/bookmarks"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentBookmarks does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentBookmarks does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentBookmarks: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BookmarksResponse> result(new BookmarksResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentBookmarks: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DrawingObjectResponse>> WordsApi::getDocumentDrawingObjectByIndex(
    std::shared_ptr<GetDocumentDrawingObjectByIndexRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentDrawingObjectByIndex does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentDrawingObjectByIndex does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentDrawingObjectByIndex: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DrawingObjectResponse> result(new DrawingObjectResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                      _XPLATSTR(
"error calling getDocumentDrawingObjectByIndex: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectImageData(
    std::shared_ptr<GetDocumentDrawingObjectImageDataRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects/{index}/imageData"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentDrawingObjectImageData does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentDrawingObjectImageData: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::getDocumentDrawingObjectOleData(
    std::shared_ptr<GetDocumentDrawingObjectOleDataRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects/{index}/oleData"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentDrawingObjectOleData does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentDrawingObjectOleData: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<std::shared_ptr<DrawingObjectsResponse>> WordsApi::getDocumentDrawingObjects(
    std::shared_ptr<GetDocumentDrawingObjectsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentDrawingObjects does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentDrawingObjects does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentDrawingObjects: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DrawingObjectsResponse> result(new DrawingObjectsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<FieldNamesResponse>> WordsApi::getDocumentFieldNames(
    std::shared_ptr<GetDocumentFieldNamesRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/mailMergeFieldNames"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("useNonMergeFields"), extractOptional(request->getUseNonMergeFields()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentFieldNames does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getUseNonMergeFields() && bPath.find(_XPLATSTR("useNonMergeFields")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentFieldNames: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FieldNamesResponse> result(new FieldNamesResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<HyperlinkResponse>> WordsApi::getDocumentHyperlinkByIndex(
    std::shared_ptr<GetDocumentHyperlinkByIndexRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/hyperlinks/{hyperlinkIndex}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("hyperlinkIndex"),
        ApiClient::parameterToString(request->getHyperlinkIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentHyperlinkByIndex does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentHyperlinkByIndex does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentHyperlinkByIndex: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<HyperlinkResponse> result(new HyperlinkResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                  _XPLATSTR(
"error calling getDocumentHyperlinkByIndex: unsupported response type"
));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<HyperlinksResponse>> WordsApi::getDocumentHyperlinks(
    std::shared_ptr<GetDocumentHyperlinksRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/hyperlinks")
                      ,
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentHyperlinks does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentHyperlinks: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<HyperlinksResponse> result(new HyperlinksResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<ParagraphResponse>> WordsApi::getDocumentParagraph(
    std::shared_ptr<GetDocumentParagraphRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/paragraphs/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentParagraph does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentParagraph does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentParagraph: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ParagraphResponse> result(new ParagraphResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentParagraph: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ParagraphFormatResponse>> WordsApi::getDocumentParagraphFormat(
    std::shared_ptr<GetDocumentParagraphFormatRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/paragraphs/{index}/format"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentParagraphFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentParagraphFormat does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentParagraphFormat: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ParagraphFormatResponse> result(new ParagraphFormatResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentParagraphFormat: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<RunResponse>> WordsApi::getDocumentParagraphRun(
    std::shared_ptr<GetDocumentParagraphRunRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{paragraphPath}/runs/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentParagraphRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentParagraphRun does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentParagraphRun: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<RunResponse> result(new RunResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentParagraphRun: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FontResponse>> WordsApi::getDocumentParagraphRunFont(
    std::shared_ptr<GetDocumentParagraphRunFontRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{paragraphPath}/runs/{index}/font"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentParagraphRunFont does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentParagraphRunFont does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentParagraphRunFont: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FontResponse> result(new FontResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                  _XPLATSTR(
"error calling getDocumentParagraphRunFont: unsupported response type"
));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<RunsResponse>> WordsApi::getDocumentParagraphRuns(
    std::shared_ptr<GetDocumentParagraphRunsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{paragraphPath}/runs"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getDocumentParagraphRuns does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->getDocumentParagraphRuns does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentParagraphRuns: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<RunsResponse> result(new RunsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentParagraphRuns: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ParagraphLinkCollectionResponse>> WordsApi::getDocumentParagraphs(
    std::shared_ptr<GetDocumentParagraphsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/paragraphs"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentParagraphs does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentParagraphs does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentParagraphs: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ParagraphLinkCollectionResponse> result(
                              new ParagraphLinkCollectionResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentParagraphs: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentPropertiesResponse>> WordsApi::getDocumentProperties(
    std::shared_ptr<GetDocumentPropertiesRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/documentProperties"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentProperties does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentProperties: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentPropertiesResponse> result(new DocumentPropertiesResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<DocumentPropertyResponse>> WordsApi::getDocumentProperty(
    std::shared_ptr<GetDocumentPropertyRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/documentProperties/{propertyName}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("propertyName"),
        ApiClient::parameterToString(request->getPropertyName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentProperty does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentProperty: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentPropertyResponse> result(new DocumentPropertyResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::getDocumentProtection(
    std::shared_ptr<GetDocumentProtectionRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection")
                      ,
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentProtection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentProtection: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<StatDataResponse>> WordsApi::getDocumentStatistics(
    std::shared_ptr<GetDocumentStatisticsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/statistics")
                      ,
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("includeComments"), extractOptional(request->getIncludeComments()));
    path = replacePathParameter(path, _XPLATSTR("includeFootnotes"), extractOptional(request->getIncludeFootnotes()));
    path = replacePathParameter(path, _XPLATSTR("includeTextInShapes"),
        extractOptional(request->getIncludeTextInShapes()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentStatistics does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getIncludeComments() && bPath.find(_XPLATSTR("includeComments")) == std::string::npos)
    {
        queryParams[_XPLATSTR("IncludeComments")] = ApiClient::parameterToString(*(request->getIncludeComments()));
    }
    if (request->getIncludeFootnotes() && bPath.find(_XPLATSTR("includeFootnotes")) == std::string::npos)
    {
        queryParams[_XPLATSTR("IncludeFootnotes")] = ApiClient::parameterToString(*(request->getIncludeFootnotes()));
    }
    if (request->getIncludeTextInShapes() && bPath.find(_XPLATSTR("includeTextInShapes")) == std::string::npos)
    {
        queryParams[_XPLATSTR("IncludeTextInShapes")] = ApiClient::parameterToString(
            *(request->getIncludeTextInShapes()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentStatistics: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<StatDataResponse> result(new StatDataResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TextItemsResponse>> WordsApi::getDocumentTextItems(
    std::shared_ptr<GetDocumentTextItemsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/textItems"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getDocumentTextItems does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->getDocumentTextItems does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentTextItems: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TextItemsResponse> result(new TextItemsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling getDocumentTextItems: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::getDocumentWithFormat(std::shared_ptr<GetDocumentWithFormatRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("format"), ApiClient::parameterToString(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("outPath"), extractOptional(request->getOutPath()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getOutPath() && bPath.find(_XPLATSTR("outPath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("OutPath")] = ApiClient::parameterToString(*(request->getOutPath()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getDocumentWithFormat: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<std::shared_ptr<FieldResponse>> WordsApi::getField(std::shared_ptr<GetFieldRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/fields/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FieldResponse> result(new FieldResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<FieldsResponse>> WordsApi::getFields(std::shared_ptr<GetFieldsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/fields"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getFields: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FieldsResponse> result(new FieldsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<FootnoteResponse>> WordsApi::getFootnote(std::shared_ptr<GetFootnoteRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/footnotes/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getFootnote: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FootnoteResponse> result(new FootnoteResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<FootnotesResponse>> WordsApi::getFootnotes(std::shared_ptr<GetFootnotesRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/footnotes"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFootnotes does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getFootnotes: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FootnotesResponse> result(new FootnotesResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<FormFieldResponse>> WordsApi::getFormField(std::shared_ptr<GetFormFieldRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/formfields/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getFormField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FormFieldResponse> result(new FormFieldResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<FormFieldsResponse>> WordsApi::getFormFields(std::shared_ptr<GetFormFieldsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/formfields"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getFormFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getFormFields: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FormFieldsResponse> result(new FormFieldsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<HeaderFooterResponse>> WordsApi::getHeaderFooter(
    std::shared_ptr<GetHeaderFooterRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/headersfooters/{headerFooterIndex}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("headerFooterIndex"),
        ApiClient::parameterToString(request->getHeaderFooterIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("filterByType"), extractOptional(request->getFilterByType()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getHeaderFooter does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType() && bPath.find(_XPLATSTR("filterByType")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getHeaderFooter: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<HeaderFooterResponse> result(new HeaderFooterResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<HeaderFooterResponse>> WordsApi::getHeaderFooterOfSection(
    std::shared_ptr<GetHeaderFooterOfSectionRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/sections/{sectionIndex}/headersfooters/{headerFooterIndex}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("headerFooterIndex"),
        ApiClient::parameterToString(request->getHeaderFooterIndex()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("filterByType"), extractOptional(request->getFilterByType()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->getHeaderFooterOfSection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFilterByType() && bPath.find(_XPLATSTR("filterByType")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->getHeaderFooterOfSection does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getHeaderFooterOfSection: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<HeaderFooterResponse> result(new HeaderFooterResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<HeaderFootersResponse>> WordsApi::getHeaderFooters(
    std::shared_ptr<GetHeaderFootersRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{sectionPath}/headersfooters"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"), extractOptional(request->getSectionPath()));
    path = replacePathParameter(path, _XPLATSTR("filterByType"), extractOptional(request->getFilterByType()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getHeaderFooters does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getSectionPath() && bPath.find(_XPLATSTR("sectionPath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("SectionPath")] = ApiClient::parameterToString(*(request->getSectionPath()));
    }
    if (request->getFilterByType() && bPath.find(_XPLATSTR("filterByType")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getHeaderFooters: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<HeaderFootersResponse> result(new HeaderFootersResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<OfficeMathObjectResponse>> WordsApi::getOfficeMathObject(
    std::shared_ptr<GetOfficeMathObjectRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/OfficeMathObjects/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getOfficeMathObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getOfficeMathObject: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<OfficeMathObjectResponse> result(new OfficeMathObjectResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<OfficeMathObjectsResponse>> WordsApi::getOfficeMathObjects(
    std::shared_ptr<GetOfficeMathObjectsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/OfficeMathObjects"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getOfficeMathObjects does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getOfficeMathObjects: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<OfficeMathObjectsResponse> result(new OfficeMathObjectsResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<SectionResponse>> WordsApi::getSection(std::shared_ptr<GetSectionRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/sections/{sectionIndex}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getSection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getSection: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SectionResponse> result(new SectionResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<SectionPageSetupResponse>> WordsApi::getSectionPageSetup(
    std::shared_ptr<GetSectionPageSetupRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/sections/{sectionIndex}/pageSetup"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getSectionPageSetup does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getSectionPageSetup: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SectionPageSetupResponse> result(new SectionPageSetupResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<SectionLinkCollectionResponse>> WordsApi::getSections(
    std::shared_ptr<GetSectionsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/sections"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getSections does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getSections: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SectionLinkCollectionResponse> result(new SectionLinkCollectionResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableResponse>> WordsApi::getTable(std::shared_ptr<GetTableRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/tables/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTable does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getTable: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableResponse> result(new TableResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableCellResponse>> WordsApi::getTableCell(std::shared_ptr<GetTableCellRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tableRowPath}/cells/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableCell does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getTableCell: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableCellResponse> result(new TableCellResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableCellFormatResponse>> WordsApi::getTableCellFormat(
    std::shared_ptr<GetTableCellFormatRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tableRowPath}/cells/{index}/cellformat"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableCellFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getTableCellFormat: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableCellFormatResponse> result(new TableCellFormatResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TablePropertiesResponse>> WordsApi::getTableProperties(
    std::shared_ptr<GetTablePropertiesRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/tables/{index}/properties"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableProperties does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getTableProperties: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TablePropertiesResponse> result(new TablePropertiesResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableRowResponse>> WordsApi::getTableRow(std::shared_ptr<GetTableRowRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tablePath}/rows/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"), ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableRow does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getTableRow: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableRowResponse> result(new TableRowResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableRowFormatResponse>> WordsApi::getTableRowFormat(
    std::shared_ptr<GetTableRowFormatRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tablePath}/rows/{index}/rowformat"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"), ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTableRowFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getTableRowFormat: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableRowFormatResponse> result(new TableRowFormatResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableLinkCollectionResponse>> WordsApi::getTables(std::shared_ptr<GetTablesRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/tables"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->getTables does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling getTables: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableLinkCollectionResponse> result(new TableLinkCollectionResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableResponse>> WordsApi::insertTable(std::shared_ptr<InsertTableRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/tables"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertTable does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        if (request->getTable())
            json = ModelBase::toJson(*(request->getTable()));

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getTable() && (*(request->getTable())).get())
        {
            (*(request->getTable()))->toMultipart(multipart, _XPLATSTR("table"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertTable does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling insertTable: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableResponse> result(new TableResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableCellResponse>> WordsApi::insertTableCell(
    std::shared_ptr<InsertTableCellRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tableRowPath}/cells"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertTableCell does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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

        if (request->getCell())
            json = ModelBase::toJson(*(request->getCell()));

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getCell() && (*(request->getCell())).get())
        {
            (*(request->getCell()))->toMultipart(multipart, _XPLATSTR("cell"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertTableCell does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling insertTableCell: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableCellResponse> result(new TableCellResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableRowResponse>> WordsApi::insertTableRow(std::shared_ptr<InsertTableRowRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tablePath}/rows"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"), ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->insertTableRow does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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

        if (request->getRow())
            json = ModelBase::toJson(*(request->getRow()));

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getRow() && (*(request->getRow())).get())
        {
            (*(request->getRow()))->toMultipart(multipart, _XPLATSTR("row"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->insertTableRow does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling insertTableRow: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableRowResponse> result(new TableRowResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postAppendDocument(
    std::shared_ptr<PostAppendDocumentRequest> request)
{
    // verify the required parameter 'documentList' is set
    if (request->getDocumentList() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'documentList' when calling WordsApi->postAppendDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/appendDocument"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postAppendDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getDocumentList().get())
        {
            (request->getDocumentList())->toMultipart(multipart, _XPLATSTR("documentList"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postAppendDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postAppendDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postAppendDocument: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::postChangeDocumentProtection(
    std::shared_ptr<PostChangeDocumentProtectionRequest> request)
{
    // verify the required parameter 'protectionRequest' is set
    if (request->getProtectionRequest() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR(
"Missing required parameter 'protectionRequest' when calling WordsApi->postChangeDocumentProtection"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection")
                      ,
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postChangeDocumentProtection does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getProtectionRequest().get())
        {
            (request->getProtectionRequest())->toMultipart(multipart, _XPLATSTR("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->postChangeDocumentProtection does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postChangeDocumentProtection: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                  _XPLATSTR(
"error calling postChangeDocumentProtection: unsupported response type"
));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<CommentResponse>> WordsApi::postComment(std::shared_ptr<PostCommentRequest> request)
{
    // verify the required parameter 'comment' is set
    if (request->getComment() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'comment' when calling WordsApi->postComment"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/comments/{commentIndex}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("commentIndex"),
        ApiClient::parameterToString(request->getCommentIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getComment().get())
        {
            (request->getComment())->toMultipart(multipart, _XPLATSTR("comment"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postComment does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postComment: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<CommentResponse> result(new CommentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postComment: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postCompareDocument(
    std::shared_ptr<PostCompareDocumentRequest> request)
{
    // verify the required parameter 'compareData' is set
    if (request->getCompareData() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'compareData' when calling WordsApi->postCompareDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/compareDocument"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postCompareDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getCompareData().get())
        {
            (request->getCompareData())->toMultipart(multipart, _XPLATSTR("compareData"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postCompareDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postCompareDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postCompareDocument: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postDocumentExecuteMailMerge(
    std::shared_ptr<PostDocumentExecuteMailMergeRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/executeMailMerge"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("data"), extractOptional(request->getData()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("withRegions"), extractOptional(request->getWithRegions()));
    path = replacePathParameter(path, _XPLATSTR("mailMergeDataFile"), extractOptional(request->getMailMergeDataFile()));
    path = replacePathParameter(path, _XPLATSTR("cleanup"), extractOptional(request->getCleanup()));
    path = replacePathParameter(path, _XPLATSTR("useWholeParagraphAsRegion"),
        extractOptional(request->getUseWholeParagraphAsRegion()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postDocumentExecuteMailMerge does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getData() && bPath.find(_XPLATSTR("data")) == std::string::npos)
    {
        formParams[_XPLATSTR("Data")] = ApiClient::parameterToString(*(request->getData()));
    }
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getWithRegions() && bPath.find(_XPLATSTR("withRegions")) == std::string::npos)
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getMailMergeDataFile() && bPath.find(_XPLATSTR("mailMergeDataFile")) == std::string::npos)
    {
        queryParams[_XPLATSTR("MailMergeDataFile")] = ApiClient::parameterToString(*(request->getMailMergeDataFile()));
    }
    if (request->getCleanup() && bPath.find(_XPLATSTR("cleanup")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getUseWholeParagraphAsRegion() && bPath.find(_XPLATSTR("useWholeParagraphAsRegion")) == std::string::
        npos)
    {
        queryParams[_XPLATSTR("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(
            *(request->getUseWholeParagraphAsRegion()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->postDocumentExecuteMailMerge does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postDocumentExecuteMailMerge: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                  _XPLATSTR(
"error calling postDocumentExecuteMailMerge: unsupported response type"
));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ParagraphFormatResponse>> WordsApi::postDocumentParagraphFormat(
    std::shared_ptr<PostDocumentParagraphFormatRequest> request)
{
    // verify the required parameter 'dto' is set
    if (request->getDto() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'dto' when calling WordsApi->postDocumentParagraphFormat"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/paragraphs/{index}/format"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postDocumentParagraphFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getDto().get())
        {
            (request->getDto())->toMultipart(multipart, _XPLATSTR("dto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->postDocumentParagraphFormat does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postDocumentParagraphFormat: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ParagraphFormatResponse> result(new ParagraphFormatResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                  _XPLATSTR(
"error calling postDocumentParagraphFormat: unsupported response type"
));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FontResponse>> WordsApi::postDocumentParagraphRunFont(
    std::shared_ptr<PostDocumentParagraphRunFontRequest> request)
{
    // verify the required parameter 'fontDto' is set
    if (request->getFontDto() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'fontDto' when calling WordsApi->postDocumentParagraphRunFont"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{paragraphPath}/runs/{index}/font"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postDocumentParagraphRunFont does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getFontDto().get())
        {
            (request->getFontDto())->toMultipart(multipart, _XPLATSTR("fontDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->postDocumentParagraphRunFont does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postDocumentParagraphRunFont: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FontResponse> result(new FontResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                  _XPLATSTR(
"error calling postDocumentParagraphRunFont: unsupported response type"
));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<SaveResponse>> WordsApi::postDocumentSaveAs(
    std::shared_ptr<PostDocumentSaveAsRequest> request)
{
    // verify the required parameter 'saveOptionsData' is set
    if (request->getSaveOptionsData() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'saveOptionsData' when calling WordsApi->postDocumentSaveAs"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/saveAs"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postDocumentSaveAs does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getSaveOptionsData().get())
        {
            (request->getSaveOptionsData())->toMultipart(multipart, _XPLATSTR("saveOptionsData"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postDocumentSaveAs does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postDocumentSaveAs: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SaveResponse> result(new SaveResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postDocumentSaveAs: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DrawingObjectResponse>> WordsApi::postDrawingObject(
    std::shared_ptr<PostDrawingObjectRequest> request)
{
    // verify the required parameter 'imageFile' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'imageFile' when calling WordsApi->postDrawingObject"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("drawingObject"),
        ApiClient::parameterToString(request->getDrawingObject()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postDrawingObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams[_XPLATSTR("DrawingObject")] = ApiClient::parameterToString((request->getDrawingObject()));
    }
    if (request->getImageFile() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postDrawingObject does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postDrawingObject: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DrawingObjectResponse> result(new DrawingObjectResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postDrawingObject: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postExecuteTemplate(
    std::shared_ptr<PostExecuteTemplateRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/executeTemplate"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("data"), ApiClient::parameterToString(request->getData()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("cleanup"), extractOptional(request->getCleanup()));
    path = replacePathParameter(path, _XPLATSTR("useWholeParagraphAsRegion"),
        extractOptional(request->getUseWholeParagraphAsRegion()));
    path = replacePathParameter(path, _XPLATSTR("withRegions"), extractOptional(request->getWithRegions()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postExecuteTemplate does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams[_XPLATSTR("Data")] = ApiClient::parameterToString((request->getData()));
    }
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getCleanup() && bPath.find(_XPLATSTR("cleanup")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getUseWholeParagraphAsRegion() && bPath.find(_XPLATSTR("useWholeParagraphAsRegion")) == std::string::
        npos)
    {
        queryParams[_XPLATSTR("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(
            *(request->getUseWholeParagraphAsRegion()));
    }
    if (request->getWithRegions() && bPath.find(_XPLATSTR("withRegions")) == std::string::npos)
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->postExecuteTemplate does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postExecuteTemplate: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postExecuteTemplate: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FieldResponse>> WordsApi::postField(std::shared_ptr<PostFieldRequest> request)
{
    // verify the required parameter 'field' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'field' when calling WordsApi->postField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/fields/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getField().get())
        {
            (request->getField())->toMultipart(multipart, _XPLATSTR("field"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postField does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FieldResponse> result(new FieldResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postField: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FootnoteResponse>> WordsApi::postFootnote(std::shared_ptr<PostFootnoteRequest> request)
{
    // verify the required parameter 'footnoteDto' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'footnoteDto' when calling WordsApi->postFootnote"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/footnotes/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getFootnoteDto().get())
        {
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postFootnote does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postFootnote: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FootnoteResponse> result(new FootnoteResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postFootnote: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FormFieldResponse>> WordsApi::postFormField(std::shared_ptr<PostFormFieldRequest> request)
{
    // verify the required parameter 'formField' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'formField' when calling WordsApi->postFormField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/formfields/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getFormField().get())
        {
            (request->getFormField())->toMultipart(multipart, _XPLATSTR("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postFormField does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postFormField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FormFieldResponse> result(new FormFieldResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postFormField: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postInsertDocumentWatermarkImage(
    std::shared_ptr<PostInsertDocumentWatermarkImageRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/watermark/insertImage"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("rotationAngle"), extractOptional(request->getRotationAngle()));
    path = replacePathParameter(path, _XPLATSTR("image"), extractOptional(request->getImage()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postInsertDocumentWatermarkImage does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getImageFile() && *(request->getImageFile()) != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), *(request->getImageFile())));
    }
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getRotationAngle() && bPath.find(_XPLATSTR("rotationAngle")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RotationAngle")] = ApiClient::parameterToString(*(request->getRotationAngle()));
    }
    if (request->getImage() && bPath.find(_XPLATSTR("image")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->postInsertDocumentWatermarkImage does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postInsertDocumentWatermarkImage: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                      _XPLATSTR(
"error calling postInsertDocumentWatermarkImage: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postInsertDocumentWatermarkText(
    std::shared_ptr<PostInsertDocumentWatermarkTextRequest> request)
{
    // verify the required parameter 'watermarkText' is set
    if (request->getWatermarkText() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR(
"Missing required parameter 'watermarkText' when calling WordsApi->postInsertDocumentWatermarkText"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/watermark/insertText"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postInsertDocumentWatermarkText does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getWatermarkText().get())
        {
            (request->getWatermarkText())->toMultipart(multipart, _XPLATSTR("watermarkText"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->postInsertDocumentWatermarkText does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postInsertDocumentWatermarkText: ") + response.
                                  reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  ,                                      _XPLATSTR(
"error calling postInsertDocumentWatermarkText: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postInsertPageNumbers(
    std::shared_ptr<PostInsertPageNumbersRequest> request)
{
    // verify the required parameter 'pageNumber' is set
    if (request->getPageNumber() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'pageNumber' when calling WordsApi->postInsertPageNumbers"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/insertPageNumbers"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postInsertPageNumbers does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getPageNumber().get())
        {
            (request->getPageNumber())->toMultipart(multipart, _XPLATSTR("pageNumber"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postInsertPageNumbers does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postInsertPageNumbers: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postInsertPageNumbers: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<SaveResponse>> WordsApi::postLoadWebDocument(
    std::shared_ptr<PostLoadWebDocumentRequest> request)
{
    // verify the required parameter 'data' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'data' when calling WordsApi->postLoadWebDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/loadWebDocument"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postLoadWebDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getData().get())
        {
            (request->getData())->toMultipart(multipart, _XPLATSTR("data"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postLoadWebDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postLoadWebDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SaveResponse> result(new SaveResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postLoadWebDocument: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ReplaceTextResponse>> WordsApi::postReplaceText(
    std::shared_ptr<PostReplaceTextRequest> request)
{
    // verify the required parameter 'replaceText' is set
    if (request->getReplaceText() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'replaceText' when calling WordsApi->postReplaceText"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() +                      _XPLATSTR(
"/words/{name}/replaceText"
),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postReplaceText does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getReplaceText().get())
        {
            (request->getReplaceText())->toMultipart(multipart, _XPLATSTR("replaceText"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postReplaceText does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postReplaceText: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ReplaceTextResponse> result(new ReplaceTextResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postReplaceText: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<RunResponse>> WordsApi::postRun(std::shared_ptr<PostRunRequest> request)
{
    // verify the required parameter 'run' is set
    if (request->getRun() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'run' when calling WordsApi->postRun"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{paragraphPath}/runs/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getRun().get())
        {
            (request->getRun())->toMultipart(multipart, _XPLATSTR("run"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->postRun does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postRun: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<RunResponse> result(new RunResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postRun: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<SplitDocumentResponse>> WordsApi::postSplitDocument(
    std::shared_ptr<PostSplitDocumentRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/split"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("format"), extractOptional(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("from"), extractOptional(request->getFrom()));
    path = replacePathParameter(path, _XPLATSTR("to"), extractOptional(request->getTo()));
    path = replacePathParameter(path, _XPLATSTR("zipOutput"), extractOptional(request->getZipOutput()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->postSplitDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getFormat() && bPath.find(_XPLATSTR("format")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString(*(request->getFormat()));
    }
    if (request->getFrom() && bPath.find(_XPLATSTR("from")) == std::string::npos)
    {
        queryParams[_XPLATSTR("From")] = ApiClient::parameterToString(*(request->getFrom()));
    }
    if (request->getTo() && bPath.find(_XPLATSTR("to")) == std::string::npos)
    {
        queryParams[_XPLATSTR("To")] = ApiClient::parameterToString(*(request->getTo()));
    }
    if (request->getZipOutput() && bPath.find(_XPLATSTR("zipOutput")) == std::string::npos)
    {
        queryParams[_XPLATSTR("ZipOutput")] = ApiClient::parameterToString(*(request->getZipOutput()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->postSplitDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postSplitDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SplitDocumentResponse> result(new SplitDocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postSplitDocument: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<BookmarkResponse>> WordsApi::postUpdateDocumentBookmark(
    std::shared_ptr<PostUpdateDocumentBookmarkRequest> request)
{
    // verify the required parameter 'bookmarkData' is set
    if (request->getBookmarkData() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'bookmarkData' when calling WordsApi->postUpdateDocumentBookmark"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/bookmarks/{bookmarkName}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("bookmarkName"),
        ApiClient::parameterToString(request->getBookmarkName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postUpdateDocumentBookmark does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getBookmarkData().get())
        {
            (request->getBookmarkData())->toMultipart(multipart, _XPLATSTR("bookmarkData"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->postUpdateDocumentBookmark does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postUpdateDocumentBookmark: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BookmarkResponse> result(new BookmarkResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postUpdateDocumentBookmark: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::postUpdateDocumentFields(
    std::shared_ptr<PostUpdateDocumentFieldsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/updateFields"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->postUpdateDocumentFields does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->postUpdateDocumentFields does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling postUpdateDocumentFields: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling postUpdateDocumentFields: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<CommentResponse>> WordsApi::putComment(std::shared_ptr<PutCommentRequest> request)
{
    // verify the required parameter 'comment' is set
    if (request->getComment() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'comment' when calling WordsApi->putComment"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/comments"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putComment does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getComment().get())
        {
            (request->getComment())->toMultipart(multipart, _XPLATSTR("comment"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putComment does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putComment: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<CommentResponse> result(new CommentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putComment: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::putConvertDocument(std::shared_ptr<PutConvertDocumentRequest> request)
{
    // verify the required parameter 'document' is set
    if (request->getDocument() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'document' when calling WordsApi->putConvertDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/convert"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("format"), ApiClient::parameterToString(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("outPath"), extractOptional(request->getOutPath()));
    path = replacePathParameter(path, _XPLATSTR("documentFileName"), extractOptional(request->getDocumentFileName()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getDocument() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Document"), (request->getDocument())));
    }
    {
        queryParams[_XPLATSTR("Format")] = ApiClient::parameterToString((request->getFormat()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getOutPath() && bPath.find(_XPLATSTR("outPath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("OutPath")] = ApiClient::parameterToString(*(request->getOutPath()));
    }
    if (request->getDocumentFileName() && bPath.find(_XPLATSTR("documentFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DocumentFileName")] = ApiClient::parameterToString(*(request->getDocumentFileName()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->putConvertDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putConvertDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<std::shared_ptr<DocumentResponse>> WordsApi::putCreateDocument(
    std::shared_ptr<PutCreateDocumentRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/create"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("fileName"), extractOptional(request->getFileName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putCreateDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getFileName() && bPath.find(_XPLATSTR("fileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("FileName")] = ApiClient::parameterToString(*(request->getFileName()));
    }
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->putCreateDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putCreateDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DocumentResponse> result(new DocumentResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putCreateDocument: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FieldNamesResponse>> WordsApi::putDocumentFieldNames(
    std::shared_ptr<PutDocumentFieldNamesRequest> request)
{
    // verify the required parameter '_template' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter '_template' when calling WordsApi->putDocumentFieldNames"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/mailMergeFieldNames"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("useNonMergeFields"), extractOptional(request->getUseNonMergeFields()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putDocumentFieldNames does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getTemplate() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Template"), (request->getTemplate())));
    }
    if (request->getUseNonMergeFields() && bPath.find(_XPLATSTR("useNonMergeFields")) == std::string::npos)
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
        throw ApiException(415, _XPLATSTR("WordsApi->putDocumentFieldNames does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putDocumentFieldNames: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FieldNamesResponse> result(new FieldNamesResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putDocumentFieldNames: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<SaveResponse>> WordsApi::putDocumentSaveAsTiff(
    std::shared_ptr<PutDocumentSaveAsTiffRequest> request)
{
    // verify the required parameter 'saveOptions' is set
    if (request->getSaveOptions() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'saveOptions' when calling WordsApi->putDocumentSaveAsTiff"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() +                      _XPLATSTR(
"/words/{name}/saveAs/tiff"
),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("resultFile"), extractOptional(request->getResultFile()));
    path = replacePathParameter(path, _XPLATSTR("useAntiAliasing"), extractOptional(request->getUseAntiAliasing()));
    path = replacePathParameter(path, _XPLATSTR("useHighQualityRendering"),
        extractOptional(request->getUseHighQualityRendering()));
    path = replacePathParameter(path, _XPLATSTR("imageBrightness"), extractOptional(request->getImageBrightness()));
    path = replacePathParameter(path, _XPLATSTR("imageColorMode"), extractOptional(request->getImageColorMode()));
    path = replacePathParameter(path, _XPLATSTR("imageContrast"), extractOptional(request->getImageContrast()));
    path = replacePathParameter(path, _XPLATSTR("numeralFormat"), extractOptional(request->getNumeralFormat()));
    path = replacePathParameter(path, _XPLATSTR("pageCount"), extractOptional(request->getPageCount()));
    path = replacePathParameter(path, _XPLATSTR("pageIndex"), extractOptional(request->getPageIndex()));
    path = replacePathParameter(path, _XPLATSTR("paperColor"), extractOptional(request->getPaperColor()));
    path = replacePathParameter(path, _XPLATSTR("pixelFormat"), extractOptional(request->getPixelFormat()));
    path = replacePathParameter(path, _XPLATSTR("resolution"), extractOptional(request->getResolution()));
    path = replacePathParameter(path, _XPLATSTR("scale"), extractOptional(request->getScale()));
    path = replacePathParameter(path, _XPLATSTR("tiffCompression"), extractOptional(request->getTiffCompression()));
    path = replacePathParameter(path, _XPLATSTR("dmlRenderingMode"), extractOptional(request->getDmlRenderingMode()));
    path = replacePathParameter(path, _XPLATSTR("dmlEffectsRenderingMode"),
        extractOptional(request->getDmlEffectsRenderingMode()));
    path = replacePathParameter(path, _XPLATSTR("tiffBinarizationMethod"),
        extractOptional(request->getTiffBinarizationMethod()));
    path = replacePathParameter(path, _XPLATSTR("zipOutput"), extractOptional(request->getZipOutput()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putDocumentSaveAsTiff does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getResultFile() && bPath.find(_XPLATSTR("resultFile")) == std::string::npos)
    {
        queryParams[_XPLATSTR("ResultFile")] = ApiClient::parameterToString(*(request->getResultFile()));
    }
    if (request->getUseAntiAliasing() && bPath.find(_XPLATSTR("useAntiAliasing")) == std::string::npos)
    {
        queryParams[_XPLATSTR("UseAntiAliasing")] = ApiClient::parameterToString(*(request->getUseAntiAliasing()));
    }
    if (request->getUseHighQualityRendering() && bPath.find(_XPLATSTR("useHighQualityRendering")) == std::string::npos)
    {
        queryParams[_XPLATSTR("UseHighQualityRendering")] = ApiClient::parameterToString(
            *(request->getUseHighQualityRendering()));
    }
    if (request->getImageBrightness() && bPath.find(_XPLATSTR("imageBrightness")) == std::string::npos)
    {
        queryParams[_XPLATSTR("ImageBrightness")] = ApiClient::parameterToString(*(request->getImageBrightness()));
    }
    if (request->getImageColorMode() && bPath.find(_XPLATSTR("imageColorMode")) == std::string::npos)
    {
        queryParams[_XPLATSTR("ImageColorMode")] = ApiClient::parameterToString(*(request->getImageColorMode()));
    }
    if (request->getImageContrast() && bPath.find(_XPLATSTR("imageContrast")) == std::string::npos)
    {
        queryParams[_XPLATSTR("ImageContrast")] = ApiClient::parameterToString(*(request->getImageContrast()));
    }
    if (request->getNumeralFormat() && bPath.find(_XPLATSTR("numeralFormat")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NumeralFormat")] = ApiClient::parameterToString(*(request->getNumeralFormat()));
    }
    if (request->getPageCount() && bPath.find(_XPLATSTR("pageCount")) == std::string::npos)
    {
        queryParams[_XPLATSTR("PageCount")] = ApiClient::parameterToString(*(request->getPageCount()));
    }
    if (request->getPageIndex() && bPath.find(_XPLATSTR("pageIndex")) == std::string::npos)
    {
        queryParams[_XPLATSTR("PageIndex")] = ApiClient::parameterToString(*(request->getPageIndex()));
    }
    if (request->getPaperColor() && bPath.find(_XPLATSTR("paperColor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("PaperColor")] = ApiClient::parameterToString(*(request->getPaperColor()));
    }
    if (request->getPixelFormat() && bPath.find(_XPLATSTR("pixelFormat")) == std::string::npos)
    {
        queryParams[_XPLATSTR("PixelFormat")] = ApiClient::parameterToString(*(request->getPixelFormat()));
    }
    if (request->getResolution() && bPath.find(_XPLATSTR("resolution")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Resolution")] = ApiClient::parameterToString(*(request->getResolution()));
    }
    if (request->getScale() && bPath.find(_XPLATSTR("scale")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Scale")] = ApiClient::parameterToString(*(request->getScale()));
    }
    if (request->getTiffCompression() && bPath.find(_XPLATSTR("tiffCompression")) == std::string::npos)
    {
        queryParams[_XPLATSTR("TiffCompression")] = ApiClient::parameterToString(*(request->getTiffCompression()));
    }
    if (request->getDmlRenderingMode() && bPath.find(_XPLATSTR("dmlRenderingMode")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DmlRenderingMode")] = ApiClient::parameterToString(*(request->getDmlRenderingMode()));
    }
    if (request->getDmlEffectsRenderingMode() && bPath.find(_XPLATSTR("dmlEffectsRenderingMode")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DmlEffectsRenderingMode")] = ApiClient::parameterToString(
            *(request->getDmlEffectsRenderingMode()));
    }
    if (request->getTiffBinarizationMethod() && bPath.find(_XPLATSTR("tiffBinarizationMethod")) == std::string::npos)
    {
        queryParams[_XPLATSTR("TiffBinarizationMethod")] = ApiClient::parameterToString(
            *(request->getTiffBinarizationMethod()));
    }
    if (request->getZipOutput() && bPath.find(_XPLATSTR("zipOutput")) == std::string::npos)
    {
        queryParams[_XPLATSTR("ZipOutput")] = ApiClient::parameterToString(*(request->getZipOutput()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getSaveOptions().get())
        {
            (request->getSaveOptions())->toMultipart(multipart, _XPLATSTR("saveOptions"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putDocumentSaveAsTiff does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putDocumentSaveAsTiff: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SaveResponse> result(new SaveResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putDocumentSaveAsTiff: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<DrawingObjectResponse>> WordsApi::putDrawingObject(
    std::shared_ptr<PutDrawingObjectRequest> request)
{
    // verify the required parameter 'imageFile' is set
    if (request->getImageFile() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'imageFile' when calling WordsApi->putDrawingObject"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("drawingObject"),
        ApiClient::parameterToString(request->getDrawingObject()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putDrawingObject does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    {
        formParams[_XPLATSTR("DrawingObject")] = ApiClient::parameterToString((request->getDrawingObject()));
    }
    if (request->getImageFile() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("ImageFile"), (request->getImageFile())));
    }
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putDrawingObject does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putDrawingObject: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<DrawingObjectResponse> result(new DrawingObjectResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putDrawingObject: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::putExecuteMailMergeOnline(std::shared_ptr<PutExecuteMailMergeOnlineRequest> request)
{
    // verify the required parameter '_template' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter '_template' when calling WordsApi->putExecuteMailMergeOnline"));
    }

    // verify the required parameter 'data' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'data' when calling WordsApi->putExecuteMailMergeOnline"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/executeMailMerge"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("withRegions"), extractOptional(request->getWithRegions()));
    path = replacePathParameter(path, _XPLATSTR("cleanup"), extractOptional(request->getCleanup()));
    path = replacePathParameter(path, _XPLATSTR("documentFileName"), extractOptional(request->getDocumentFileName()));

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
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getTemplate() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Template"), (request->getTemplate())));
    }
    if (request->getData() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Data"), (request->getData())));
    }
    if (request->getWithRegions() && bPath.find(_XPLATSTR("withRegions")) == std::string::npos)
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getCleanup() && bPath.find(_XPLATSTR("cleanup")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getDocumentFileName() && bPath.find(_XPLATSTR("documentFileName")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->putExecuteMailMergeOnline does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putExecuteMailMergeOnline: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::putExecuteTemplateOnline(std::shared_ptr<PutExecuteTemplateOnlineRequest> request)
{
    // verify the required parameter '_template' is set
    if (request->getTemplate() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter '_template' when calling WordsApi->putExecuteTemplateOnline"));
    }

    // verify the required parameter 'data' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'data' when calling WordsApi->putExecuteTemplateOnline"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/executeTemplate"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("cleanup"), extractOptional(request->getCleanup()));
    path = replacePathParameter(path, _XPLATSTR("useWholeParagraphAsRegion"),
        extractOptional(request->getUseWholeParagraphAsRegion()));
    path = replacePathParameter(path, _XPLATSTR("withRegions"), extractOptional(request->getWithRegions()));
    path = replacePathParameter(path, _XPLATSTR("documentFileName"), extractOptional(request->getDocumentFileName()));

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
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getTemplate() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Template"), (request->getTemplate())));
    }
    if (request->getData() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Data"), (request->getData())));
    }
    if (request->getCleanup() && bPath.find(_XPLATSTR("cleanup")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Cleanup")] = ApiClient::parameterToString(*(request->getCleanup()));
    }
    if (request->getUseWholeParagraphAsRegion() && bPath.find(_XPLATSTR("useWholeParagraphAsRegion")) == std::string::
        npos)
    {
        queryParams[_XPLATSTR("UseWholeParagraphAsRegion")] = ApiClient::parameterToString(
            *(request->getUseWholeParagraphAsRegion()));
    }
    if (request->getWithRegions() && bPath.find(_XPLATSTR("withRegions")) == std::string::npos)
    {
        queryParams[_XPLATSTR("WithRegions")] = ApiClient::parameterToString(*(request->getWithRegions()));
    }
    if (request->getDocumentFileName() && bPath.find(_XPLATSTR("documentFileName")) == std::string::npos)
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
        throw ApiException(415,
            _XPLATSTR("WordsApi->putExecuteTemplateOnline does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putExecuteTemplateOnline: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<std::shared_ptr<FieldResponse>> WordsApi::putField(std::shared_ptr<PutFieldRequest> request)
{
    // verify the required parameter 'field' is set
    if (request->getField() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'field' when calling WordsApi->putField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/fields"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("insertBeforeNode"), extractOptional(request->getInsertBeforeNode()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }
    if (request->getInsertBeforeNode() && bPath.find(_XPLATSTR("insertBeforeNode")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getField().get())
        {
            (request->getField())->toMultipart(multipart, _XPLATSTR("field"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putField does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FieldResponse> result(new FieldResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putField: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FootnoteResponse>> WordsApi::putFootnote(std::shared_ptr<PutFootnoteRequest> request)
{
    // verify the required parameter 'footnoteDto' is set
    if (request->getFootnoteDto() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'footnoteDto' when calling WordsApi->putFootnote"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/footnotes"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putFootnote does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getFootnoteDto().get())
        {
            (request->getFootnoteDto())->toMultipart(multipart, _XPLATSTR("footnoteDto"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putFootnote does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putFootnote: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FootnoteResponse> result(new FootnoteResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putFootnote: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<FormFieldResponse>> WordsApi::putFormField(std::shared_ptr<PutFormFieldRequest> request)
{
    // verify the required parameter 'formField' is set
    if (request->getFormField() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'formField' when calling WordsApi->putFormField"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/formfields"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("insertBeforeNode"), extractOptional(request->getInsertBeforeNode()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putFormField does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }
    if (request->getInsertBeforeNode() && bPath.find(_XPLATSTR("insertBeforeNode")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getFormField().get())
        {
            (request->getFormField())->toMultipart(multipart, _XPLATSTR("formField"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putFormField does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putFormField: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<FormFieldResponse> result(new FormFieldResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putFormField: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<HeaderFooterResponse>> WordsApi::putHeaderFooter(
    std::shared_ptr<PutHeaderFooterRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{sectionPath}/headersfooters"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("headerFooterType"),
        ApiClient::parameterToString(request->getHeaderFooterType()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("sectionPath"), extractOptional(request->getSectionPath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putHeaderFooter does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getSectionPath() && bPath.find(_XPLATSTR("sectionPath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("SectionPath")] = ApiClient::parameterToString(*(request->getSectionPath()));
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);
        multipart->add(ModelBase::toHttpContent(_XPLATSTR("headerFooterType"), request->getHeaderFooterType()));

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putHeaderFooter does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putHeaderFooter: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<HeaderFooterResponse> result(new HeaderFooterResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putHeaderFooter: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ParagraphResponse>> WordsApi::putParagraph(std::shared_ptr<PutParagraphRequest> request)
{
    // verify the required parameter 'paragraph' is set
    if (request->getParagraph() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'paragraph' when calling WordsApi->putParagraph"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/paragraphs"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("insertBeforeNode"), extractOptional(request->getInsertBeforeNode()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putParagraph does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }
    if (request->getInsertBeforeNode() && bPath.find(_XPLATSTR("insertBeforeNode")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getParagraph().get())
        {
            (request->getParagraph())->toMultipart(multipart, _XPLATSTR("paragraph"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putParagraph does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putParagraph: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ParagraphResponse> result(new ParagraphResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putParagraph: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<ProtectionDataResponse>> WordsApi::putProtectDocument(
    std::shared_ptr<PutProtectDocumentRequest> request)
{
    // verify the required parameter 'protectionRequest' is set
    if (request->getProtectionRequest() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'protectionRequest' when calling WordsApi->putProtectDocument"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/protection")
                      ,
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putProtectDocument does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getProtectionRequest().get())
        {
            (request->getProtectionRequest())->toMultipart(multipart, _XPLATSTR("protectionRequest"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putProtectDocument does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putProtectDocument: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<ProtectionDataResponse> result(new ProtectionDataResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putProtectDocument: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<RunResponse>> WordsApi::putRun(std::shared_ptr<PutRunRequest> request)
{
    // verify the required parameter 'run' is set
    if (request->getRun() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'run' when calling WordsApi->putRun"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{paragraphPath}/runs"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("paragraphPath"),
        ApiClient::parameterToString(request->getParagraphPath()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("insertBeforeNode"), extractOptional(request->getInsertBeforeNode()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->putRun does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getInsertBeforeNode() && bPath.find(_XPLATSTR("insertBeforeNode")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getRun().get())
        {
            (request->getRun())->toMultipart(multipart, _XPLATSTR("run"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->putRun does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling putRun: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<RunResponse> result(new RunResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling putRun: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<RevisionsModificationResponse>> WordsApi::rejectAllRevisions(
    std::shared_ptr<RejectAllRevisionsRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/revisions/rejectAll"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->rejectAllRevisions does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling rejectAllRevisions: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<RevisionsModificationResponse> result(new RevisionsModificationResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<HttpContent> WordsApi::renderDrawingObject(std::shared_ptr<RenderDrawingObjectRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/drawingObjects/{index}/render"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("format"), ApiClient::parameterToString(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling renderDrawingObject: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::renderMathObject(std::shared_ptr<RenderMathObjectRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/OfficeMathObjects/{index}/render"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("format"), ApiClient::parameterToString(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling renderMathObject: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::renderPage(std::shared_ptr<RenderPageRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/pages/{pageIndex}/render"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("pageIndex"), ApiClient::parameterToString(request->getPageIndex()));
    path = replacePathParameter(path, _XPLATSTR("format"), ApiClient::parameterToString(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling renderPage: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::renderParagraph(std::shared_ptr<RenderParagraphRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/paragraphs/{index}/render"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("format"), ApiClient::parameterToString(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling renderParagraph: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<HttpContent> WordsApi::renderTable(std::shared_ptr<RenderTableRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/tables/{index}/render"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("format"), ApiClient::parameterToString(request->getFormat()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("fontsLocation"), extractOptional(request->getFontsLocation()));

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
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }
    if (request->getFontsLocation() && bPath.find(_XPLATSTR("fontsLocation")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling renderTable: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_vector();
                      })
                      .then([=](std::vector<unsigned char> response)
                      {
                          HttpContent result;
                          std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(
                              std::string(response.begin(), response.end()));
                          result.setData(stream);
                          return result;
                      });
}

pplx::task<std::shared_ptr<AsposeResponse>> WordsApi::resetCache(std::shared_ptr<ResetCacheRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/fonts/cache"),
                      path = bPath;

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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling resetCache: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<AsposeResponse> result(new AsposeResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
                              // {
                              // TODO multipart response parsing
                              // }
                          else
                          {
                              throw ApiException(500
                                  , _XPLATSTR("error calling resetCache: unsupported response type"));
                          }

                          return result;
                      });
}

pplx::task<std::shared_ptr<SearchResponse>> WordsApi::search(std::shared_ptr<SearchRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/search"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("pattern"), ApiClient::parameterToString(request->getPattern()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->search does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    {
        queryParams[_XPLATSTR("Pattern")] = ApiClient::parameterToString((request->getPattern()));
    }
    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling search: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SearchResponse> result(new SearchResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<BorderResponse>> WordsApi::updateBorder(std::shared_ptr<UpdateBorderRequest> request)
{
    // verify the required parameter 'borderProperties' is set
    if (request->getBorderProperties() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'borderProperties' when calling WordsApi->updateBorder"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/borders/{index}"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), ApiClient::parameterToString(request->getNodePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateBorder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling updateBorder: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<BorderResponse> result(new BorderResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<SectionPageSetupResponse>> WordsApi::updateSectionPageSetup(
    std::shared_ptr<UpdateSectionPageSetupRequest> request)
{
    // verify the required parameter 'pageSetup' is set
    if (request->getPageSetup() == nullptr)
    {
        throw ApiException(400,
            _XPLATSTR("Missing required parameter 'pageSetup' when calling WordsApi->updateSectionPageSetup"));
    }


    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/sections/{sectionIndex}/pageSetup"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("sectionIndex"),
        ApiClient::parameterToString(request->getSectionIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400,
            _XPLATSTR("WordsApi->updateSectionPageSetup does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getPageSetup().get())
        {
            (request->getPageSetup())->toMultipart(multipart, _XPLATSTR("pageSetup"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415,
            _XPLATSTR("WordsApi->updateSectionPageSetup does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling updateSectionPageSetup: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<SectionPageSetupResponse> result(new SectionPageSetupResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableCellFormatResponse>> WordsApi::updateTableCellFormat(
    std::shared_ptr<UpdateTableCellFormatRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tableRowPath}/cells/{index}/cellformat"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tableRowPath"),
        ApiClient::parameterToString(request->getTableRowPath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateTableCellFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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

        if (request->getFormat())
            json = ModelBase::toJson(*(request->getFormat()));

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getFormat() && (*(request->getFormat())).get())
        {
            (*(request->getFormat()))->toMultipart(multipart, _XPLATSTR("format"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateTableCellFormat does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling updateTableCellFormat: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableCellFormatResponse> result(new TableCellFormatResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TablePropertiesResponse>> WordsApi::updateTableProperties(
    std::shared_ptr<UpdateTablePropertiesRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{nodePath}/tables/{index}/properties"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));
    path = replacePathParameter(path, _XPLATSTR("nodePath"), extractOptional(request->getNodePath()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateTableProperties does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionDateTime")] = ApiClient::parameterToString(*(request->getRevisionDateTime()));
    }
    if (request->getNodePath() && bPath.find(_XPLATSTR("nodePath")) == std::string::npos)
    {
        queryParams[_XPLATSTR("NodePath")] = ApiClient::parameterToString(*(request->getNodePath()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) !=
        consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        if (request->getProperties())
            json = ModelBase::toJson(*(request->getProperties()));

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getProperties() && (*(request->getProperties())).get())
        {
            (*(request->getProperties()))->toMultipart(multipart, _XPLATSTR("properties"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateTableProperties does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling updateTableProperties: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TablePropertiesResponse> result(new TablePropertiesResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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

pplx::task<std::shared_ptr<TableRowFormatResponse>> WordsApi::updateTableRowFormat(
    std::shared_ptr<UpdateTableRowFormatRequest> request)
{
    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR(
"/words/{name}/{tablePath}/rows/{index}/rowformat"),
                      path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"), ApiClient::parameterToString(request->getName()));
    path = replacePathParameter(path, _XPLATSTR("tablePath"), ApiClient::parameterToString(request->getTablePath()));
    path = replacePathParameter(path, _XPLATSTR("index"), ApiClient::parameterToString(request->getIndex()));
    path = replacePathParameter(path, _XPLATSTR("folder"), extractOptional(request->getFolder()));
    path = replacePathParameter(path, _XPLATSTR("storage"), extractOptional(request->getStorage()));
    path = replacePathParameter(path, _XPLATSTR("loadEncoding"), extractOptional(request->getLoadEncoding()));
    path = replacePathParameter(path, _XPLATSTR("password"), extractOptional(request->getPassword()));
    path = replacePathParameter(path, _XPLATSTR("destFileName"), extractOptional(request->getDestFileName()));
    path = replacePathParameter(path, _XPLATSTR("revisionAuthor"), extractOptional(request->getRevisionAuthor()));
    path = replacePathParameter(path, _XPLATSTR("revisionDateTime"), extractOptional(request->getRevisionDateTime()));

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
        throw ApiException(400, _XPLATSTR("WordsApi->updateTableRowFormat does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));

    if (request->getFolder() && bPath.find(_XPLATSTR("folder")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getStorage() && bPath.find(_XPLATSTR("storage")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Storage")] = ApiClient::parameterToString(*(request->getStorage()));
    }
    if (request->getLoadEncoding() && bPath.find(_XPLATSTR("loadEncoding")) == std::string::npos)
    {
        queryParams[_XPLATSTR("LoadEncoding")] = ApiClient::parameterToString(*(request->getLoadEncoding()));
    }
    if (request->getPassword() && bPath.find(_XPLATSTR("password")) == std::string::npos)
    {
        queryParams[_XPLATSTR("Password")] = ApiClient::parameterToString(*(request->getPassword()));
    }
    if (request->getDestFileName() && bPath.find(_XPLATSTR("destFileName")) == std::string::npos)
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }
    if (request->getRevisionAuthor() && bPath.find(_XPLATSTR("revisionAuthor")) == std::string::npos)
    {
        queryParams[_XPLATSTR("RevisionAuthor")] = ApiClient::parameterToString(*(request->getRevisionAuthor()));
    }
    if (request->getRevisionDateTime() && bPath.find(_XPLATSTR("revisionDateTime")) == std::string::npos)
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

        if (request->getFormat())
            json = ModelBase::toJson(*(request->getFormat()));

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
        // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart(new MultipartFormData);

        if (request->getFormat() && (*(request->getFormat())).get())
        {
            (*(request->getFormat()))->toMultipart(multipart, _XPLATSTR("format"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("WordsApi->updateTableRowFormat does not consume any supported media type"));
    }


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
                              throw ApiException(response.status_code()
                                  , _XPLATSTR("error calling updateTableRowFormat: ") + response.reason_phrase()
                                  , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
                          }

                          return response.extract_string();
                      })
                      .then([=](utility::string_t response)
                      {
                          std::shared_ptr<TableRowFormatResponse> result(new TableRowFormatResponse());

                          if (responseHttpContentType == _XPLATSTR("application/json"))
                          {
                              web::json::value json = web::json::value::parse(response);


                              result->fromJson(json);
                              postInitializeResponse(json, result.get());
                          }
                              // else if(responseHttpContentType == _XPLATSTR("multipart/form-data"))
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
}
}
}
}
