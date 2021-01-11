/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateListOnlineRequest.cpp">
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

#include "UpdateListOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateListOnlineRequest::UpdateListOnlineRequest(
    std::shared_ptr<HttpContent> document,
    int32_t listId,
    std::shared_ptr<ListUpdate> listUpdate,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_ListId(std::move(listId)),
m_ListUpdate(std::move(listUpdate)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateListOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateListOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

int32_t UpdateListOnlineRequest::getListId() const
{
    return m_ListId;
}

void UpdateListOnlineRequest::setListId(int32_t listId)
{
    m_ListId = std::move(listId);
}

std::shared_ptr<ListUpdate> UpdateListOnlineRequest::getListUpdate() const
{
    return m_ListUpdate;
}

void UpdateListOnlineRequest::setListUpdate(std::shared_ptr<ListUpdate> listUpdate)
{
    m_ListUpdate = std::move(listUpdate);
}

boost::optional< utility::string_t > UpdateListOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateListOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateListOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateListOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateListOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateListOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateListOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateListOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateListOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateListOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
