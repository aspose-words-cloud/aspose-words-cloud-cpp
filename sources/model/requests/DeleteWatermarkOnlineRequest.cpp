/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DeleteWatermarkOnlineRequest.cpp">
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

#include "DeleteWatermarkOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
DeleteWatermarkOnlineRequest::DeleteWatermarkOnlineRequest(
    std::shared_ptr<HttpContent> document,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> DeleteWatermarkOnlineRequest::getDocument() const
{
    return m_Document;
}

void DeleteWatermarkOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

boost::optional< utility::string_t > DeleteWatermarkOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void DeleteWatermarkOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > DeleteWatermarkOnlineRequest::getPassword() const
{
    return m_Password;
}

void DeleteWatermarkOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > DeleteWatermarkOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void DeleteWatermarkOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > DeleteWatermarkOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void DeleteWatermarkOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > DeleteWatermarkOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void DeleteWatermarkOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
