/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_client.h">
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

#include "ApiConfiguration.h"
#include "ApiException.h"
#include "IHttpBody.h"
#include "HttpContent.h"
#include "JsonBody.h"

#include <memory>
#include <vector>
#include <array>

namespace aspose::words::cloud::api {
    class  ApiClient
    {
    public:
        class FormParamContainer
        {
        private:
            const std::wstring m_name;
            const std::wstring m_text;
            const std::shared_ptr<HttpContent> m_file;
            const bool m_isFile;

        public:
            FormParamContainer(const std::wstring& name, const std::wstring& text)
                : m_name(name), m_text(text), m_isFile(false) { }

            FormParamContainer(const std::wstring& name, const std::shared_ptr<HttpContent> file)
                : m_name(name), m_file(file), m_isFile(true) { }

            bool isFile() const { return m_isFile; }
            const std::wstring& getName() const { return m_name; }
            const std::wstring& getText() const { return m_text; }
            const std::shared_ptr<HttpContent> getFile() const { return m_file; }
        };

        explicit ApiClient( std::shared_ptr<ApiConfiguration> configuration = nullptr );

        std::shared_ptr<ApiConfiguration> getConfiguration() const;
        void setConfiguration(std::shared_ptr<ApiConfiguration> configuration);

        static std::wstring parameterToString(std::wstring value);
        static std::wstring parameterToString(bool value);
        static std::wstring parameterToString(int32_t value);
        static std::wstring parameterToString(int64_t value);
        static std::wstring parameterToString(float value);
        static std::wstring parameterToString(double value);
        static std::wstring parameterToString(const utility::datetime &value);

        template<class T>
        static std::wstring parameterToString(const std::vector<T>& value)
        {
            std::wstring result;
            for (auto & item : value)
            {
                result.append(ApiClient::parameterToString(item));
                result.append(_XPLATSTR(", "));
            }

            if (!value.empty())
            {
                result.resize(result.size() - 2);
            }

            return result;
        }

        template<class T>
        static std::wstring parameterToString(std::shared_ptr<T> value)
        {
            ModelBase* modelPtr = static_cast<ModelBase*>(value.get());
            return modelPtr->toJson().serialize();
        }


        pplx::task<web::http::http_response> callApi(
            const std::wstring& path,
            const std::wstring& method,
            const std::map<std::wstring, std::wstring>& queryParams,
            const std::shared_ptr<IHttpBody> postBody,
            const std::map<std::wstring, std::wstring>& headerParams,
            const std::vector<FormParamContainer>& formParams,
            const std::wstring& contentType
        );

        pplx::task<void> requestToken();

    protected:
        void setAccessToken(std::wstring token);
        std::shared_ptr<ApiConfiguration> m_Configuration;

    private:
        std::wstring m_AccessToken;
        std::array<std::pair<std::wstring, std::wstring>, 2> defaultHeaders =
        {
            std::make_pair<std::wstring, std::wstring>(_XPLATSTR("x-aspose-client-version"), _XPLATSTR("21.3")),
            std::make_pair<std::wstring, std::wstring>(_XPLATSTR("x-aspose-client"), _XPLATSTR("C++ SDK"))
        };

    private:
        std::wstring getTokenUrl() const;
        void logRequest(web::http::http_request request) const;
        void logResponse(web::http::http_response response) const;
        void logDataFromStream(const Concurrency::streams::istream& stream) const;
    };
}
