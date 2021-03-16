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

#include <codecvt>
#include "aspose_words_cloud/http_request_data.h"
#include "../thirdparty/httplib.h"
#include "../thirdparty/utf8.h"

namespace aspose::words::cloud {
    void HttpRequestData::setPath(const std::string&& path)
    {
        m_Path = std::move(path);
    }

    void HttpRequestData::setPathParam(const std::string& name, const std::wstring& value)
    {
        std::string valueUtf8;
        utf8::utf16to8(value.begin(), value.end(), back_inserter(valueUtf8));

        size_t start_pos;
        if ((start_pos = m_Path.find(name)) != std::string::npos) {
            m_Path.replace(start_pos, name.length(), valueUtf8);
        }

        if ((start_pos = m_Path.find("//")) != std::string::npos) {
            m_Path.replace(start_pos, 2, "/");
        }
    }

    void HttpRequestData::addQueryParam(const std::string& name, const std::wstring& value)
    {
        m_QueryParams.emplace(name, std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(value));
    }

    void HttpRequestData::addHeader(const std::string& name, const std::wstring& value)
    {
        m_Headers.emplace(name, std::wstring_convert<std::codecvt_utf8<wchar_t>>().to_bytes(value));
    }

    void HttpRequestData::setMethod(const std::string&& method)
    {
         m_Method = std::move(method);
    }
}