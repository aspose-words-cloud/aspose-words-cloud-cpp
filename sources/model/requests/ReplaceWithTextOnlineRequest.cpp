/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceWithTextOnlineRequest.cpp">
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

#include "ReplaceWithTextOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ReplaceWithTextOnlineRequest::ReplaceWithTextOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t rangeStartIdentifier,
    std::shared_ptr<ReplaceRange> rangeText,
    boost::optional< utility::string_t > rangeEndIdentifier,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName
) : m_Document(std::move(document)),
m_RangeStartIdentifier(std::move(rangeStartIdentifier)),
m_RangeText(std::move(rangeText)),
m_RangeEndIdentifier(std::move(rangeEndIdentifier)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName))
{
}

std::shared_ptr<HttpContent> ReplaceWithTextOnlineRequest::getDocument() const
{
    return m_Document;
}

void ReplaceWithTextOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t ReplaceWithTextOnlineRequest::getRangeStartIdentifier() const
{
    return m_RangeStartIdentifier;
}

void ReplaceWithTextOnlineRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier)
{
    m_RangeStartIdentifier = std::move(rangeStartIdentifier);
}

std::shared_ptr<ReplaceRange> ReplaceWithTextOnlineRequest::getRangeText() const
{
    return m_RangeText;
}

void ReplaceWithTextOnlineRequest::setRangeText(std::shared_ptr<ReplaceRange> rangeText)
{
    m_RangeText = std::move(rangeText);
}

boost::optional< utility::string_t > ReplaceWithTextOnlineRequest::getRangeEndIdentifier() const
{
    return m_RangeEndIdentifier;
}

void ReplaceWithTextOnlineRequest::setRangeEndIdentifier(boost::optional< utility::string_t > rangeEndIdentifier)
{
    m_RangeEndIdentifier = std::move(rangeEndIdentifier);
}

boost::optional< utility::string_t > ReplaceWithTextOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void ReplaceWithTextOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > ReplaceWithTextOnlineRequest::getPassword() const
{
    return m_Password;
}

void ReplaceWithTextOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > ReplaceWithTextOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void ReplaceWithTextOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

}
}
}
}
}
