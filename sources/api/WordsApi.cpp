/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="WordsApi.cpp">
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

#include "WordsApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>
#include <utility>

namespace aspose::words::cloud::api {
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

    std::wstring replacePathParameter(std::wstring path, const std::wstring& paramName, std::wstring value)
    {
        if (!value.empty())
        {
            size_t pos = 0;
            const std::wstring search(_XPLATSTR(" "));
            const std::wstring replace(_XPLATSTR("%20"));
            while ((pos = value.find(search, pos)) != std::wstring::npos) {
                value.replace(pos, search.length(), replace);
                pos += replace.length();
            }

            std::replace_all(path, _XPLATSTR("{") + paramName + _XPLATSTR("}"),
                ApiClient::parameterToString(value));
        }
        else
        {
            std::replace_all(path, _XPLATSTR("/{") + paramName + _XPLATSTR("}"),
                value);
        }
        return path;
    }

    template <class T> 
    std::wstring extractOptional(const std::optional<T>& parameter)
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

    pplx::task<HttpContent> WordsApi::acceptAllRevisions(std::shared_ptr<AcceptAllRevisionsRequest> request)
    {
        std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
        std::wstring bPath = apiConfiguration->getApiVersion() + _XPLATSTR("/words/{name}/revisions/acceptAll"),
        path = bPath;
        path = replacePathParameter(path, _XPLATSTR("name"),
            ApiClient::parameterToString(request->getName()));


        std::map<std::wstring, std::wstring> queryParams;
        std::map<std::wstring, std::wstring> headerParams(apiConfiguration->getDefaultHeaders());
        std::vector<ApiClient::FormParamContainer> formParams;

        headerParams[_XPLATSTR("Accept")] = _XPLATSTR("application/json");

        std::unordered_set<std::wstring> consumeHttpContentTypes;
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
        std::wstring requestHttpContentType;

        // use JSON if possible
        if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
        consumeHttpContentTypes.end())
        {
            requestHttpContentType = _XPLATSTR("application/json");
        }
        // multipart formdata
        else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
        {
            requestHttpContentType = _XPLATSTR("multipart/form-data");
        }
        else
        {
            throw ApiException(415, _XPLATSTR("WordsApi->acceptAllRevisions does not consume any supported media type."));
        }

        return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams,
        requestHttpContentType)
        .then([=](web::http::http_response response)
        {
            // 1xx - informational : OK
            // 2xx - successful    : OK
            // 3xx - redirection   : OK
            // 4xx - client error  : not OK
            // 5xx - client error  : not OK
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

}
