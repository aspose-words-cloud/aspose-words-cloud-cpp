/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="http_request_data.h">
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

#pragma once
#include <memory>
#include <string>
#include <optional>
#include <map>
#include "./models/model_base.h"

namespace aspose::words::cloud {
    enum class HttpRequestMethod {
        HttpGET, HttpPOST, HttpPUT, HttpDELETE
    };

    class HttpRequestData
    {
    public:
        virtual ~HttpRequestData() = default;

        void setPath(const std::wstring& path);
        void setPathParam(const std::wstring& name, const std::wstring& value);
        void addQueryParam(const std::wstring& name, const std::wstring& value);
        void addHeader(const std::wstring& name, const std::wstring& value);
        void setMethod(HttpRequestMethod method);
        void setBody(const aspose::words::cloud::api::models::ModelBase& model);
        void setBody(const std::istream& stream);
        void setBody(const std::wstring& value);
        void addFormDataParam(const std::wstring& name, const aspose::words::cloud::api::models::ModelBase& model);
        void addFormDataParam(const std::wstring& name, const std::istream& stream);
        void addFormDataParam(const std::wstring& name, const std::wstring& value);
        void setContentType(const std::string& value);

        std::wstring getFullPath() const;
        HttpRequestMethod getMethod() const;
        const std::map<std::wstring, std::wstring>& getHeaders() const;
        const std::string& getBody() const;
        const std::string& getContentType() const;

    private:
        std::wstring urlEncode(const std::wstring& source) const;

    protected:
        std::wstring m_Path;
        std::map<std::wstring, std::wstring> m_QueryParams;
        std::map<std::wstring, std::wstring> m_Headers;
        HttpRequestMethod m_Method = HttpRequestMethod::HttpGET;
        std::string m_Body;
        std::string m_ContentType;
    };
}