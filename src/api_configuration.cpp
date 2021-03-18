/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_configuration.cpp">
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

#include "aspose_words_cloud/api_configuration.h"
#include "aspose_words_cloud/api_exception.h"

namespace aspose::words::cloud {
    ApiConfiguration::ApiConfiguration(const std::wstring& clientId, const std::wstring& clientSecret)
    {
        setClientId(clientId);
        setClientSecret(clientSecret);
    }

    const std::wstring& ApiConfiguration::getBaseUrl() const
    {
        return m_BaseUrl;
    }

    void ApiConfiguration::setBaseUrl( const std::wstring& value )
    {
        m_BaseUrl = value;
    }

    const std::wstring& ApiConfiguration::getClientId() const{
        return m_clientId;
    }

    void ApiConfiguration::setClientId(const std::wstring& clientId){
        if (clientId.empty()) {
            throw ApiException(400, L"ClientId could not be an empty string.");
        }

        m_clientId = clientId;
    }

    const std::wstring& ApiConfiguration::getClientSecret() const {
        return m_clientSecret;
    }

    void ApiConfiguration::setClientSecret(const std::wstring& clientSecret){
        if (clientSecret.empty()) {
            throw ApiException(400, L"ClientSecret could not be an empty string.");
        }

        m_clientSecret = clientSecret;
    }

    bool ApiConfiguration::isDebugMode() const {
        return m_DebugMode;
    }

    void ApiConfiguration::setDebugMode(bool debug) {
        m_DebugMode = debug;
    }

    const std::wstring& ApiConfiguration::getApiVersion() const
    {
        return m_Version;
    }
}
