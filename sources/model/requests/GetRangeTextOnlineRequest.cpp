/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetRangeTextOnlineRequest.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "GetRangeTextOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetRangeTextOnlineRequest::GetRangeTextOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t rangeStartIdentifier,
    boost::optional< utility::string_t > rangeEndIdentifier,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password
) : m_Document(std::move(document)),
m_RangeStartIdentifier(std::move(rangeStartIdentifier)),
m_RangeEndIdentifier(std::move(rangeEndIdentifier)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password))
{
}

std::shared_ptr<HttpContent> GetRangeTextOnlineRequest::getDocument() const
{
    return m_Document;
}

void GetRangeTextOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t GetRangeTextOnlineRequest::getRangeStartIdentifier() const
{
    return m_RangeStartIdentifier;
}

void GetRangeTextOnlineRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier)
{
    m_RangeStartIdentifier = std::move(rangeStartIdentifier);
}

boost::optional< utility::string_t > GetRangeTextOnlineRequest::getRangeEndIdentifier() const
{
    return m_RangeEndIdentifier;
}

void GetRangeTextOnlineRequest::setRangeEndIdentifier(boost::optional< utility::string_t > rangeEndIdentifier)
{
    m_RangeEndIdentifier = std::move(rangeEndIdentifier);
}

boost::optional< utility::string_t > GetRangeTextOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetRangeTextOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetRangeTextOnlineRequest::getPassword() const
{
    return m_Password;
}

void GetRangeTextOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

}
}
}
}
}
