/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="http_request_data.cpp">
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

#include "aspose_words_cloud/http_request_data.h"
#include "aspose_words_cloud/api_client.h"
#include "aspose_words_cloud/api_exception.h"
#include "aspose_words_cloud/models/file_content.h"

// USE THIRD PARTY LIBS ONLY IN CPP FILES!!!
#include "../thirdparty/json.hpp"
#include "../thirdparty/utf8.h"
#pragma warning(push, 0) 
#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "../thirdparty/httplib.h"
#pragma warning(pop)

namespace aspose::words::cloud {
    void HttpRequestData::setPath(const std::wstring& path)
    {
        m_Path = path;
    }

    void HttpRequestData::setPathParam(const std::wstring& name, const std::wstring& value)
    {
        size_t start_pos;
        if ((start_pos = m_Path.find(name)) != std::wstring::npos) {
            m_Path.replace(start_pos, name.length(), value);
        }
    }

    void HttpRequestData::setPathParam(const std::wstring& name, int32_t value)
    {
        setPathParam(name, std::to_wstring(value));
    }

    void HttpRequestData::addQueryParam(const std::wstring& name, const std::wstring& value)
    {
        m_QueryParams.emplace(name, value);
    }

    void HttpRequestData::addQueryParam(const std::wstring& name, int32_t value)
    {
        m_QueryParams.emplace(name, std::to_wstring(value));
    }

    void HttpRequestData::addQueryParam(const std::wstring& name, bool value)
    {
        m_QueryParams.emplace(name, value ? L"true" : L"false");
    }

    void HttpRequestData::addQueryParam(const std::wstring& name, double value)
    {
        m_QueryParams.emplace(name, std::to_wstring(value));
    }

    void HttpRequestData::addHeader(const std::wstring& name, const std::wstring& value)
    {
        m_Headers.emplace(name, value);
    }

    void HttpRequestData::setMethod(HttpRequestMethod method)
    {
         m_Method = method;
    }

    std::string& HttpRequestData::getBodyMutable()
    {
        return m_Body;
    }

    void HttpRequestData::addFormDataParam(const std::wstring& name, const aspose::words::cloud::models::ModelBase& model)
    {
        if (m_PartsCount == 0)
        {
            ::nlohmann::json json;
            model.toJson(&json);
            if (json.empty()) {
                m_Body = "{}";
            }
            else {
                m_Body = std::move(json.dump());
            }

            setContentType("application/json; charset=utf-8");
            m_LastName = name;
        }
        else if (m_PartsCount == 1)
        {
            m_Boundary = ApiClient::createRandomGuid();
            std::string prepart;
            prepart.append("--" + m_Boundary + "\r\n");
            prepart.append("Content-Type: " + getContentType() + "\r\n");
            prepart.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(m_LastName.begin(), m_LastName.end(), back_inserter(prepart));
            prepart.append("\"\r\n\r\n");
            m_Body.insert(0, prepart);
            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("\r\n");

            m_Body.append("Content-Type: application/json; charset=utf-8\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            ::nlohmann::json json;
            model.toJson(&json);
            if (json.empty()) {
                m_Body.append("{}");
            }
            else {
                m_Body.append(std::move(json.dump()));
            }

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }
        else
        {
            m_Body[m_Body.size() - 2] = '\r';
            m_Body[m_Body.size() - 1] = '\n';

            m_Body.append("Content-Type: application/json; charset=utf-8\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            ::nlohmann::json json;
            model.toJson(&json);
            if (json.empty()) {
                m_Body.append("{}");
            }
            else {
                m_Body.append(std::move(json.dump()));
            }

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }

        m_PartsCount++;
    }

    void HttpRequestData::addFormDataParam(const std::wstring& name, std::istream& stream)
    {
        if (!stream.good()) {
            throw ApiException(400, L"Invalid input stream in operation request.");
        }

        if (m_PartsCount == 0)
        {
            constexpr size_t BUFFER_SIZE = 1024 * 4;
            char buffer[BUFFER_SIZE];
            while (stream.read(buffer, BUFFER_SIZE)) {
                m_Body.append(buffer, BUFFER_SIZE);
            }
            m_Body.append(buffer, stream.gcount());
            setContentType("application/octet-stream");
            m_LastName = name;
        }
        else if (m_PartsCount == 1)
        {
            m_Boundary = ApiClient::createRandomGuid();
            std::string prepart;
            prepart.append("--" + m_Boundary + "\r\n");
            prepart.append("Content-Type: " + getContentType() + "\r\n");
            prepart.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(m_LastName.begin(), m_LastName.end(), back_inserter(prepart));
            prepart.append("\"\r\n\r\n");
            m_Body.insert(0, prepart);
            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("\r\n");

            m_Body.append("Content-Type: application/octet-stream\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            constexpr size_t BUFFER_SIZE = 1024 * 4;
            char buffer[BUFFER_SIZE];
            while (stream.read(buffer, BUFFER_SIZE)) {
                m_Body.append(buffer, BUFFER_SIZE);
            }
            m_Body.append(buffer, stream.gcount());

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }
        else
        {
            m_Body[m_Body.size() - 2] = '\r';
            m_Body[m_Body.size() - 1] = '\n';

            m_Body.append("Content-Type: application/octet-stream\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            constexpr size_t BUFFER_SIZE = 1024 * 4;
            char buffer[BUFFER_SIZE];
            while (stream.read(buffer, BUFFER_SIZE)) {
                m_Body.append(buffer, BUFFER_SIZE);
            }
            m_Body.append(buffer, stream.gcount());

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }

        m_PartsCount++;
    }

    void HttpRequestData::addFormDataParam(const models::FileContent* fileContent)
    {
        if (!fileContent->getContent()->good()) {
            throw ApiException(400, L"Invalid input stream in operation request.");
        }

        if (m_PartsCount == 0)
        {
            throw ApiException(400, L"File content allowed only in mutipart request.");
        }
        else if (m_PartsCount == 1)
        {
            m_Boundary = ApiClient::createRandomGuid();
            std::string prepart;
            prepart.append("--" + m_Boundary + "\r\n");
            prepart.append("Content-Type: " + getContentType() + "\r\n");
            prepart.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(m_LastName.begin(), m_LastName.end(), back_inserter(prepart));
            prepart.append("\"\r\n\r\n");
            m_Body.insert(0, prepart);
            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("\r\n");

            m_Body.append("Content-Type: application/octet-stream\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(fileContent->getId()->begin(), fileContent->getId()->end(), back_inserter(m_Body));
            m_Body.append("\"; filename=\"");
            ::utf8::utf16to8(fileContent->getFilename()->begin(), fileContent->getFilename()->end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            constexpr size_t BUFFER_SIZE = 1024 * 4;
            char buffer[BUFFER_SIZE];
            while (fileContent->getContent()->read(buffer, BUFFER_SIZE)) {
                m_Body.append(buffer, BUFFER_SIZE);
            }
            m_Body.append(buffer, fileContent->getContent()->gcount());

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }
        else
        {
            m_Body[m_Body.size() - 2] = '\r';
            m_Body[m_Body.size() - 1] = '\n';

            m_Body.append("Content-Type: application/octet-stream\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(fileContent->getId()->begin(), fileContent->getId()->end(), back_inserter(m_Body));
            m_Body.append("\"; filename=\"");
            ::utf8::utf16to8(fileContent->getFilename()->begin(), fileContent->getFilename()->end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            constexpr size_t BUFFER_SIZE = 1024 * 4;
            char buffer[BUFFER_SIZE];
            while (fileContent->getContent()->read(buffer, BUFFER_SIZE)) {
                m_Body.append(buffer, BUFFER_SIZE);
            }
            m_Body.append(buffer, fileContent->getContent()->gcount());

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }

        m_PartsCount++;
    }

    void HttpRequestData::addFormDataParam(const std::wstring& name, const std::wstring& value)
    {
        if (m_PartsCount == 0)
        {
            ::utf8::utf16to8(value.begin(), value.end(), back_inserter(m_Body));
            setContentType("text/plain; charset=utf-8");
            m_LastName = name;
        }
        else if (m_PartsCount == 1)
        {
            m_Boundary = ApiClient::createRandomGuid();
            std::string prepart;
            prepart.append("--" + m_Boundary + "\r\n");
            prepart.append("Content-Type: " + getContentType() + "\r\n");
            prepart.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(m_LastName.begin(), m_LastName.end(), back_inserter(prepart));
            prepart.append("\"\r\n\r\n");
            m_Body.insert(0, prepart);
            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("\r\n");

            m_Body.append("Content-Type: text/plain; charset=utf-8\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            ::utf8::utf16to8(value.begin(), value.end(), back_inserter(m_Body));

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }
        else
        {
            m_Body[m_Body.size() - 2] = '\r';
            m_Body[m_Body.size() - 1] = '\n';

            m_Body.append("Content-Type: text/plain; charset=utf-8\r\n");
            m_Body.append("Content-Disposition: form-data; name=\"");
            ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
            m_Body.append("\"\r\n\r\n");

            ::utf8::utf16to8(value.begin(), value.end(), back_inserter(m_Body));

            m_Body.append("\r\n");
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("--");

            setContentType("multipart/form-data; boundary=" + m_Boundary);
        }

        m_PartsCount++;
    }

    void HttpRequestData::setContentType(const std::string& value)
    {
        m_ContentType = value;
    }

    void HttpRequestData::encryptSecureData(aspose::words::cloud::ApiClient* apiClient)
    {
        auto passwordField = m_QueryParams.find(L"password");
        if (passwordField != m_QueryParams.end())
        {
            m_QueryParams.insert(std::pair<std::wstring, std::wstring>(L"encryptedPassword", apiClient->encryptString(passwordField->second)));
            m_QueryParams.erase(passwordField);
        }
    }

    std::string HttpRequestData::getFullPath() const
    {
        std::string result;
        ::utf8::utf16to8(m_Path.begin(), m_Path.end(), back_inserter(result));

        size_t start_pos;
        while ((start_pos = result.find("//")) != std::string::npos) {
            result.replace(start_pos, 2, "/");
            start_pos = 0;
        }

        result = ::httplib::detail::encode_url(result);

        int c = 0;
        for (auto& pair : m_QueryParams)
        {
            std::string queryKeyUtf8, queryParamUtf8;
            ::utf8::utf16to8(pair.first.begin(), pair.first.end(), back_inserter(queryKeyUtf8));
            ::utf8::utf16to8(pair.second.begin(), pair.second.end(), back_inserter(queryParamUtf8));

            result += (c == 0 ? "?" : "&");
            result += queryKeyUtf8;
            result += "=";
            result += ::httplib::detail::encode_query_param(queryParamUtf8);
            c++;
        }

        return result;
    }

    HttpRequestMethod HttpRequestData::getMethod() const
    {
        return m_Method;
    }

    const std::map<std::wstring, std::wstring>& HttpRequestData::getHeaders() const
    {
        return m_Headers;
    }

    const std::string& HttpRequestData::getBody() const
    {
        return m_Body;
    }

    const std::string& HttpRequestData::getContentType() const
    {
        return m_ContentType;
    }
}