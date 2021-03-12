/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_configuration.h">
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

#include <unordered_map>
#include <map>

#include "../model/WordsApiErrorResponse.h"

namespace aspose::words::cloud::api {
    class  ApiConfiguration
    {
    public:
        ApiConfiguration();
        ApiConfiguration(std::wstring clientId, std::wstring clientSecret);
        virtual ~ApiConfiguration() = default;

        web::http::client::http_client_config& getHttpConfig();
        void setHttpConfig(const web::http::client::http_client_config& value );

        std::wstring getBaseUrl() const;
        void setBaseUrl( std::wstring value );

        std::wstring getUserAgent() const;
        void setUserAgent( std::wstring value );

        std::map<std::wstring, std::wstring>& getDefaultHeaders();

        std::wstring getClientId() const;
        void setClientId( std::wstring apiSid );

        std::wstring getClientSecret( const std::wstring& prefix) const;
        void setClientSecret( const std::wstring& prefix, const std::wstring& clientSecret );

        std::wstring getClientSecret() const;
        void setClientSecret( std::wstring clientSecret );

        std::wstring getApiVersion() const;

        bool isDebugMode() const;
        void setDebugMode(bool debug);

    protected:
        bool m_DebugMode = false;
        std::wstring m_BaseUrl = STCONVERT("https://api.aspose.cloud");
        std::map<std::wstring, std::wstring> m_DefaultHeaders;
        std::unordered_map<std::wstring, std::wstring> m_clientSecrets;

        std::wstring m_clientSecret;
        std::wstring m_clientId;

        web::http::client::http_client_config m_HttpConfig;
        std::wstring m_UserAgent = STCONVERT("CppAsposeClient");
    };
}