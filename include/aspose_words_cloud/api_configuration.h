/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_configuration.h">
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
#include <string>
#include "./common.h"

namespace aspose::words::cloud {
    class  ApiConfiguration
    {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT ApiConfiguration(const std::wstring& clientId, const std::wstring& clientSecret, const std::wstring& baseUrl = L"https://api.aspose.cloud");
        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ApiConfiguration() = default;

        ASPOSE_WORDS_CLOUD_EXPORT const std::wstring& getBaseUrl() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::wstring& getClientId() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::wstring& getClientSecret() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::wstring& getApiVersion() const;

        ASPOSE_WORDS_CLOUD_EXPORT bool isDebugMode() const;
        ASPOSE_WORDS_CLOUD_EXPORT void setDebugMode(bool debug);

        ASPOSE_WORDS_CLOUD_EXPORT size_t getTimeout() const;
        ASPOSE_WORDS_CLOUD_EXPORT void setTimeout(size_t seconds);

    protected:
        bool m_DebugMode = false;
        size_t m_Timeout = 300;
        const std::wstring m_Version = L"v4.0";
        std::wstring m_BaseUrl;
        std::wstring m_ClientSecret;
        std::wstring m_ClientId;
    };
}