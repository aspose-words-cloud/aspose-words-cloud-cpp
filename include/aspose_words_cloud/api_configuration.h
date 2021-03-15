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
#include <string>

namespace aspose::words::cloud::api {
    class  ApiConfiguration
    {
    public:
        ApiConfiguration(const std::wstring& clientId, const std::wstring& clientSecret);
        virtual ~ApiConfiguration() = default;

        const std::wstring& getBaseUrl() const;
        void setBaseUrl( const std::wstring& value );

        const std::wstring& getClientId() const;
        void setClientId( const std::wstring& apiSid );

        const std::wstring& getClientSecret() const;
        void setClientSecret( const std::wstring& clientSecret );

        bool isDebugMode() const;
        void setDebugMode(bool debug);

        const std::wstring& getApiVersion() const;

    protected:
        bool m_DebugMode = false;
        const std::wstring m_Version = L"v4.0";
        std::wstring m_BaseUrl = L"https://api.aspose.cloud";
        std::wstring m_clientSecret;
        std::wstring m_clientId;
    };
}