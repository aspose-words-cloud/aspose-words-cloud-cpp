/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsRangeOnlineRequest.cpp">
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

#include "SaveAsRangeOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
SaveAsRangeOnlineRequest::SaveAsRangeOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t rangeStartIdentifier,
    std::shared_ptr<RangeDocument> documentParameters,
    boost::optional< utility::string_t > rangeEndIdentifier,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password
) : m_Document(std::move(document)),
m_RangeStartIdentifier(std::move(rangeStartIdentifier)),
m_DocumentParameters(std::move(documentParameters)),
m_RangeEndIdentifier(std::move(rangeEndIdentifier)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password))
{
}

std::shared_ptr<HttpContent> SaveAsRangeOnlineRequest::getDocument() const
{
    return m_Document;
}

void SaveAsRangeOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t SaveAsRangeOnlineRequest::getRangeStartIdentifier() const
{
    return m_RangeStartIdentifier;
}

void SaveAsRangeOnlineRequest::setRangeStartIdentifier(utility::string_t rangeStartIdentifier)
{
    m_RangeStartIdentifier = std::move(rangeStartIdentifier);
}

std::shared_ptr<RangeDocument> SaveAsRangeOnlineRequest::getDocumentParameters() const
{
    return m_DocumentParameters;
}

void SaveAsRangeOnlineRequest::setDocumentParameters(std::shared_ptr<RangeDocument> documentParameters)
{
    m_DocumentParameters = std::move(documentParameters);
}

boost::optional< utility::string_t > SaveAsRangeOnlineRequest::getRangeEndIdentifier() const
{
    return m_RangeEndIdentifier;
}

void SaveAsRangeOnlineRequest::setRangeEndIdentifier(boost::optional< utility::string_t > rangeEndIdentifier)
{
    m_RangeEndIdentifier = std::move(rangeEndIdentifier);
}

boost::optional< utility::string_t > SaveAsRangeOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void SaveAsRangeOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > SaveAsRangeOnlineRequest::getPassword() const
{
    return m_Password;
}

void SaveAsRangeOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

}
}
}
}
}
