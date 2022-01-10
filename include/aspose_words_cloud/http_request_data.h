/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="http_request_data.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include <memory>
#include <string>
#include <map>
#include "./common.h"
#include "./models/model_base.h"

namespace aspose::words::cloud {
    enum class HttpRequestMethod {
        HttpGET, HttpPOST, HttpPUT, HttpDELETE
    };

    class ApiClient;
    class HttpRequestData
    {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT virtual ~HttpRequestData() = default;

        ASPOSE_WORDS_CLOUD_EXPORT void setPath(const std::wstring& path);
        ASPOSE_WORDS_CLOUD_EXPORT void setPathParam(const std::wstring& name, const std::wstring& value);
        ASPOSE_WORDS_CLOUD_EXPORT void setPathParam(const std::wstring& name, int32_t value);
        ASPOSE_WORDS_CLOUD_EXPORT void addQueryParam(const std::wstring& name, const std::wstring& value);
        ASPOSE_WORDS_CLOUD_EXPORT void addQueryParam(const std::wstring& name, int32_t value);
        ASPOSE_WORDS_CLOUD_EXPORT void addQueryParam(const std::wstring& name, bool value);
        ASPOSE_WORDS_CLOUD_EXPORT void addQueryParam(const std::wstring& name, double value);
        ASPOSE_WORDS_CLOUD_EXPORT void addHeader(const std::wstring& name, const std::wstring& value);
        ASPOSE_WORDS_CLOUD_EXPORT void setMethod(HttpRequestMethod method);
        ASPOSE_WORDS_CLOUD_EXPORT void setBody(const aspose::words::cloud::models::ModelBase& model);
        ASPOSE_WORDS_CLOUD_EXPORT void setBody(std::istream& stream);
        ASPOSE_WORDS_CLOUD_EXPORT std::string& getBodyMutable();
        ASPOSE_WORDS_CLOUD_EXPORT void setBodyJson(const std::wstring& value);
        ASPOSE_WORDS_CLOUD_EXPORT void setBodyText(const std::wstring& value);
        ASPOSE_WORDS_CLOUD_EXPORT void addFormDataParam(const std::wstring& name, const aspose::words::cloud::models::ModelBase& model);
        ASPOSE_WORDS_CLOUD_EXPORT void addFormDataParam(const std::wstring& name, std::istream& stream);
        ASPOSE_WORDS_CLOUD_EXPORT void addFormDataParam(const std::wstring& name, const std::wstring& value);
        ASPOSE_WORDS_CLOUD_EXPORT void setContentType(const std::string& value);
        ASPOSE_WORDS_CLOUD_EXPORT void encryptSecureData(aspose::words::cloud::ApiClient* apiClient);

        ASPOSE_WORDS_CLOUD_EXPORT std::string getFullPath() const;
        ASPOSE_WORDS_CLOUD_EXPORT HttpRequestMethod getMethod() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::map<std::wstring, std::wstring>& getHeaders() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::string& getBody() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::string& getContentType() const;

    protected:
        std::wstring m_Path;
        std::map<std::wstring, std::wstring> m_QueryParams;
        std::map<std::wstring, std::wstring> m_Headers;
        HttpRequestMethod m_Method = HttpRequestMethod::HttpGET;
        std::string m_Body;
        std::string m_ContentType;
        std::string m_Boundary;
    };
}