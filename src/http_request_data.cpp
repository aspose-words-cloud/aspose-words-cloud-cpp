/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="http_request_data.cpp">
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

#include <random>
#include "aspose_words_cloud/http_request_data.h"
#include "../thirdparty/json.hpp"
#include "../thirdparty/utf8.h"

namespace aspose::words::cloud {
    inline std::wstring urlEncode(const std::wstring& source)
    {
        std::wstring result;
        wchar_t bufHex[10];
        for (int i = 0; i < source.length(); i++) {
            wchar_t c = source[i];
            int ic = c;
            if (c==L' ') result += L'+';
            else if (isalnum(c) || c == L'-' || c == L'_' || c == L'.' || c == L'~') result += c;
            else {
                swprintf(bufHex, 10, L"%X", c);
                if (ic < 16)
                    result += L"%0";
                else
                    result += L"%";
                result += bufHex;
            }
        }

        return result;
    }

    inline std::string createRandomGuid()
    {
        static std::random_device dev;
        static std::mt19937 rng(dev());

        std::uniform_int_distribution<int> dist(0, 15);

        const char* v = "0123456789abcdef";
        const bool dash[] = { 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 };

        std::string res;
        for (int i = 0; i < 16; i++) {
            if (dash[i]) res += '-';
            res += v[dist(rng)];
            res += v[dist(rng)];
        }
        return res;
    }

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

    void HttpRequestData::setBody(const aspose::words::cloud::models::ModelBase& model)
    {
        ::nlohmann::json json;
        model.toJson(&json);
        m_Body = std::move(json.dump());
    }

    void HttpRequestData::setBody(std::istream& stream)
    {
        constexpr size_t BUFFER_SIZE = 1024 * 4;
        char buffer[BUFFER_SIZE];
        while (stream.read(buffer, BUFFER_SIZE)) {
            m_Body.append(buffer, BUFFER_SIZE);
        }
        m_Body.append(buffer, stream.gcount());
    }

    void HttpRequestData::setBody(const std::wstring& value)
    {
        ::utf8::utf16to8(value.begin(), value.end(), back_inserter(m_Body));
    }

    void HttpRequestData::addFormDataParam(const std::wstring& name, const aspose::words::cloud::models::ModelBase& model)
    {
        if (m_Boundary.empty()) {
            m_Boundary = createRandomGuid();
        }

        if (m_Body.empty())
        {
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("\r\n");
        }
        else {
            m_Body[m_Body.size() - 2] = '\r';
            m_Body[m_Body.size() - 1] = '\n';
        }

        m_Body.append("Content-Disposition: form-data; name=\"");
        ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
        m_Body.append("\";\r\n\r\n");

        ::nlohmann::json json;
        model.toJson(&json);
        m_Body.append(std::move(json.dump()));

        m_Body.append("\r\n");
        m_Body.append("--");
        m_Body.append(m_Boundary);
        m_Body.append("--");
    }

    void HttpRequestData::addFormDataParam(const std::wstring& name, std::istream& stream)
    {
        if (m_Boundary.empty()) {
            m_Boundary = createRandomGuid();
        }

        if (m_Body.empty())
        {
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("\r\n");
        }
        else {
            m_Body[m_Body.size() - 2] = '\r';
            m_Body[m_Body.size() - 1] = '\n';
        }

        m_Body.append("Content-Disposition: form-data; name=\"");
        ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
        m_Body.append("\";\r\n\r\n");

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
    }

    void HttpRequestData::addFormDataParam(const std::wstring& name, const std::wstring& value)
    {
        if (m_Boundary.empty()) {
            m_Boundary = createRandomGuid();
        }

        if (m_Body.empty())
        {
            m_Body.append("--");
            m_Body.append(m_Boundary);
            m_Body.append("\r\n");
        }
        else {
            m_Body[m_Body.size() - 2] = '\r';
            m_Body[m_Body.size() - 1] = '\n';
        }

        m_Body.append("Content-Disposition: form-data; name=\"");
        ::utf8::utf16to8(name.begin(), name.end(), back_inserter(m_Body));
        m_Body.append("\";\r\n\r\n");

        ::utf8::utf16to8(value.begin(), value.end(), back_inserter(m_Body));

        m_Body.append("\r\n");
        m_Body.append("--");
        m_Body.append(m_Boundary);
        m_Body.append("--");
    }

    void HttpRequestData::setContentType(const std::string& value)
    {
        m_ContentType = value;
    }

    std::wstring HttpRequestData::getFullPath() const
    {
        int c = 0;
        std::wstring result(L"/v4.0" + m_Path);
        for (auto& pair : m_QueryParams)
        {
            result += (c == 0 ? L"?" : L"&");
            result += urlEncode(pair.first);
            result += L"=";
            result += urlEncode(pair.second);
            c++;
        }

        size_t start_pos;
        while ((start_pos = result.find(L"//")) != std::wstring::npos) {
            result.replace(start_pos, 2, L"/");
            start_pos = 0;
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