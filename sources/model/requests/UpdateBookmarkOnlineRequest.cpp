/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateBookmarkOnlineRequest.cpp">
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

#include "UpdateBookmarkOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateBookmarkOnlineRequest::UpdateBookmarkOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t bookmarkName,
    std::shared_ptr<BookmarkData> bookmarkData,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_BookmarkName(std::move(bookmarkName)),
m_BookmarkData(std::move(bookmarkData)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateBookmarkOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateBookmarkOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t UpdateBookmarkOnlineRequest::getBookmarkName() const
{
    return m_BookmarkName;
}

void UpdateBookmarkOnlineRequest::setBookmarkName(utility::string_t bookmarkName)
{
    m_BookmarkName = std::move(bookmarkName);
}

std::shared_ptr<BookmarkData> UpdateBookmarkOnlineRequest::getBookmarkData() const
{
    return m_BookmarkData;
}

void UpdateBookmarkOnlineRequest::setBookmarkData(std::shared_ptr<BookmarkData> bookmarkData)
{
    m_BookmarkData = std::move(bookmarkData);
}

boost::optional< utility::string_t > UpdateBookmarkOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateBookmarkOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateBookmarkOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateBookmarkOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateBookmarkOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateBookmarkOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateBookmarkOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateBookmarkOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateBookmarkOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateBookmarkOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
