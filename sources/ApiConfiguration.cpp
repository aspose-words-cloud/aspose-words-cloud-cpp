/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiConfiguration.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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
#include "ApiConfiguration.h"

namespace io {
namespace swagger {
namespace client {
namespace api {

void ApiConfiguration::setAppKey( utility::string_t appKey){
    m_AppKey = std::move(appKey);
}

utility::string_t ApiConfiguration::getAppKey() const {
    return m_AppKey;
}

void ApiConfiguration::setAppSid( utility::string_t appSid){
    m_AppSid = std::move(appSid);
}

utility::string_t ApiConfiguration::getAppSid() const{
    return m_AppSid;
}

utility::string_t ApiConfiguration::getApiVersion() const
{
	return m_ApiVersion;
}

void ApiConfiguration::setApiVersion( utility::string_t  apiVersion)
{
	m_ApiVersion = std::move(apiVersion);
}

bool ApiConfiguration::isDebugMode() const {
    return m_DebugMode;
}

void ApiConfiguration::setDebugMode(bool debug) {
    m_DebugMode = debug;
}

web::http::client::http_client_config& ApiConfiguration::getHttpConfig()
{
    return m_HttpConfig;
}

void ApiConfiguration::setHttpConfig(const web::http::client::http_client_config& value )
{
    m_HttpConfig = value;
}

utility::string_t ApiConfiguration::getBaseUrl() const
{
    return m_BaseUrl;
}

void ApiConfiguration::setBaseUrl( utility::string_t value )
{
    m_BaseUrl = std::move(value);
}

utility::string_t ApiConfiguration::getUserAgent() const
{
    return m_UserAgent;
}

void ApiConfiguration::setUserAgent( utility::string_t value )
{
    m_UserAgent = std::move(value);
}

std::map<utility::string_t, utility::string_t>& ApiConfiguration::getDefaultHeaders()
{
    return m_DefaultHeaders;
}

utility::string_t ApiConfiguration::getApiKey( const utility::string_t& prefix) const
{
    const auto result = m_ApiKeys.find(prefix);
    if( result != m_ApiKeys.end() )
    {
        return result->second;
    }
    return {};
}

void ApiConfiguration::setApiKey( const utility::string_t& prefix, const utility::string_t& apiKey )
{
    m_ApiKeys[prefix] = apiKey;
}

}
}
}
}
