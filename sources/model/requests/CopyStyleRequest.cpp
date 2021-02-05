/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CopyStyleRequest.cpp">
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

#include "CopyStyleRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
CopyStyleRequest::CopyStyleRequest(
    utility::string_t name,
    std::shared_ptr<StyleCopy> styleCopy,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_StyleCopy(std::move(styleCopy)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t CopyStyleRequest::getName() const
{
    return m_Name;
}

void CopyStyleRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<StyleCopy> CopyStyleRequest::getStyleCopy() const
{
    return m_StyleCopy;
}

void CopyStyleRequest::setStyleCopy(std::shared_ptr<StyleCopy> styleCopy)
{
    m_StyleCopy = std::move(styleCopy);
}

boost::optional< utility::string_t > CopyStyleRequest::getFolder() const
{
    return m_Folder;
}

void CopyStyleRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > CopyStyleRequest::getStorage() const
{
    return m_Storage;
}

void CopyStyleRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > CopyStyleRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void CopyStyleRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > CopyStyleRequest::getPassword() const
{
    return m_Password;
}

void CopyStyleRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > CopyStyleRequest::getDestFileName() const
{
    return m_DestFileName;
}

void CopyStyleRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > CopyStyleRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void CopyStyleRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > CopyStyleRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void CopyStyleRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
