/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OptimizeDocumentOnlineRequest.cpp">
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

#include "OptimizeDocumentOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
OptimizeDocumentOnlineRequest::OptimizeDocumentOnlineRequest(
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<OptimizationOptions> options,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_Options(std::move(options)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> OptimizeDocumentOnlineRequest::getDocument() const
{
    return m_Document;
}

void OptimizeDocumentOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<OptimizationOptions> OptimizeDocumentOnlineRequest::getOptions() const
{
    return m_Options;
}

void OptimizeDocumentOnlineRequest::setOptions(std::shared_ptr<OptimizationOptions> options)
{
    m_Options = std::move(options);
}

boost::optional< utility::string_t > OptimizeDocumentOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void OptimizeDocumentOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > OptimizeDocumentOnlineRequest::getPassword() const
{
    return m_Password;
}

void OptimizeDocumentOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > OptimizeDocumentOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void OptimizeDocumentOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > OptimizeDocumentOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void OptimizeDocumentOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > OptimizeDocumentOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void OptimizeDocumentOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
