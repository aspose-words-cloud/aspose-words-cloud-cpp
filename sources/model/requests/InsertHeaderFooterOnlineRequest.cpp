/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertHeaderFooterOnlineRequest.cpp">
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

#include "InsertHeaderFooterOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertHeaderFooterOnlineRequest::InsertHeaderFooterOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t sectionPath,
    utility::string_t headerFooterType,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_SectionPath(std::move(sectionPath)),
m_HeaderFooterType(std::move(headerFooterType)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> InsertHeaderFooterOnlineRequest::getDocument() const
{
    return m_Document;
}

void InsertHeaderFooterOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t InsertHeaderFooterOnlineRequest::getSectionPath() const
{
    return m_SectionPath;
}

void InsertHeaderFooterOnlineRequest::setSectionPath(utility::string_t sectionPath)
{
    m_SectionPath = std::move(sectionPath);
}

utility::string_t InsertHeaderFooterOnlineRequest::getHeaderFooterType() const
{
    return m_HeaderFooterType;
}

void InsertHeaderFooterOnlineRequest::setHeaderFooterType(utility::string_t headerFooterType)
{
    m_HeaderFooterType = std::move(headerFooterType);
}

boost::optional< utility::string_t > InsertHeaderFooterOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertHeaderFooterOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertHeaderFooterOnlineRequest::getPassword() const
{
    return m_Password;
}

void InsertHeaderFooterOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertHeaderFooterOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertHeaderFooterOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertHeaderFooterOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertHeaderFooterOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertHeaderFooterOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertHeaderFooterOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
