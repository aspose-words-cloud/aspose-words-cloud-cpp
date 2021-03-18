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

#include "aspose_words_cloud/http_request_data.h"

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

    void HttpRequestData::addQueryParam(const std::wstring& name, const std::wstring& value)
    {
        m_QueryParams.emplace(name, value);
    }

    void HttpRequestData::addHeader(const std::wstring& name, const std::wstring& value)
    {
        m_Headers.emplace(name, value);
    }

    void HttpRequestData::setMethod(HttpRequestMethod method)
    {
         m_Method = method;
    }

    void HttpRequestData::setContentType(const std::string& value)
    {
        m_ContentType = value;
    }

    std::wstring HttpRequestData::getFullPath() const
    {
        int c = 0;
        std::wstring result(m_Path);
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