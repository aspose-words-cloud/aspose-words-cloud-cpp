/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetCommentRequest.cpp">
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

#include "GetCommentRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetCommentRequest::GetCommentRequest(
    utility::string_t name,
    int32_t commentIndex,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password
) : m_Name(std::move(name)),
m_CommentIndex(std::move(commentIndex)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password))
{
}

utility::string_t GetCommentRequest::getName() const
{
    return m_Name;
}

void GetCommentRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

int32_t GetCommentRequest::getCommentIndex() const
{
    return m_CommentIndex;
}

void GetCommentRequest::setCommentIndex(int32_t commentIndex)
{
    m_CommentIndex = std::move(commentIndex);
}

boost::optional< utility::string_t > GetCommentRequest::getFolder() const
{
    return m_Folder;
}

void GetCommentRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > GetCommentRequest::getStorage() const
{
    return m_Storage;
}

void GetCommentRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > GetCommentRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetCommentRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetCommentRequest::getPassword() const
{
    return m_Password;
}

void GetCommentRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

}
}
}
}
}
