/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateCommentRequest.cpp">
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

#include "UpdateCommentRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateCommentRequest::UpdateCommentRequest(
    utility::string_t name,
    int32_t commentIndex,
    std::shared_ptr<CommentUpdate> comment,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_CommentIndex(std::move(commentIndex)),
m_Comment(std::move(comment)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t UpdateCommentRequest::getName() const
{
    return m_Name;
}

void UpdateCommentRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

int32_t UpdateCommentRequest::getCommentIndex() const
{
    return m_CommentIndex;
}

void UpdateCommentRequest::setCommentIndex(int32_t commentIndex)
{
    m_CommentIndex = std::move(commentIndex);
}

std::shared_ptr<CommentUpdate> UpdateCommentRequest::getComment() const
{
    return m_Comment;
}

void UpdateCommentRequest::setComment(std::shared_ptr<CommentUpdate> comment)
{
    m_Comment = std::move(comment);
}

boost::optional< utility::string_t > UpdateCommentRequest::getFolder() const
{
    return m_Folder;
}

void UpdateCommentRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateCommentRequest::getStorage() const
{
    return m_Storage;
}

void UpdateCommentRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateCommentRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateCommentRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateCommentRequest::getPassword() const
{
    return m_Password;
}

void UpdateCommentRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateCommentRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateCommentRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateCommentRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateCommentRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateCommentRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateCommentRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
