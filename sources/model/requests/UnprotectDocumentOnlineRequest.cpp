/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UnprotectDocumentOnlineRequest.cpp">
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

#include "UnprotectDocumentOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UnprotectDocumentOnlineRequest::UnprotectDocumentOnlineRequest(
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<ProtectionRequest> protectionRequest,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName
) : m_Document(std::move(document)),
m_ProtectionRequest(std::move(protectionRequest)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName))
{
}

std::shared_ptr<HttpContent> UnprotectDocumentOnlineRequest::getDocument() const
{
    return m_Document;
}

void UnprotectDocumentOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<ProtectionRequest> UnprotectDocumentOnlineRequest::getProtectionRequest() const
{
    return m_ProtectionRequest;
}

void UnprotectDocumentOnlineRequest::setProtectionRequest(std::shared_ptr<ProtectionRequest> protectionRequest)
{
    m_ProtectionRequest = std::move(protectionRequest);
}

boost::optional< utility::string_t > UnprotectDocumentOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UnprotectDocumentOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UnprotectDocumentOnlineRequest::getPassword() const
{
    return m_Password;
}

void UnprotectDocumentOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UnprotectDocumentOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UnprotectDocumentOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

}
}
}
}
}
