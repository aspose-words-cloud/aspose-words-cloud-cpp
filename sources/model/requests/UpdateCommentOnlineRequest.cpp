/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateCommentOnlineRequest.cpp">
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

#include "UpdateCommentOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateCommentOnlineRequest::UpdateCommentOnlineRequest(
    std::shared_ptr<HttpContent> document,
    int32_t commentIndex,
    std::shared_ptr<CommentUpdate> comment,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_CommentIndex(std::move(commentIndex)),
m_Comment(std::move(comment)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateCommentOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateCommentOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

int32_t UpdateCommentOnlineRequest::getCommentIndex() const
{
    return m_CommentIndex;
}

void UpdateCommentOnlineRequest::setCommentIndex(int32_t commentIndex)
{
    m_CommentIndex = std::move(commentIndex);
}

std::shared_ptr<CommentUpdate> UpdateCommentOnlineRequest::getComment() const
{
    return m_Comment;
}

void UpdateCommentOnlineRequest::setComment(std::shared_ptr<CommentUpdate> comment)
{
    m_Comment = std::move(comment);
}

boost::optional< utility::string_t > UpdateCommentOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateCommentOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateCommentOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateCommentOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateCommentOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateCommentOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateCommentOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateCommentOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateCommentOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateCommentOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
