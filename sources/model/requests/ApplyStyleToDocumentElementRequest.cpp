/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApplyStyleToDocumentElementRequest.cpp">
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

#include "ApplyStyleToDocumentElementRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ApplyStyleToDocumentElementRequest::ApplyStyleToDocumentElementRequest(
    utility::string_t name,
    utility::string_t styledNodePath,
    std::shared_ptr<StyleApply> styleApply,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_StyledNodePath(std::move(styledNodePath)),
m_StyleApply(std::move(styleApply)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t ApplyStyleToDocumentElementRequest::getName() const
{
    return m_Name;
}

void ApplyStyleToDocumentElementRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t ApplyStyleToDocumentElementRequest::getStyledNodePath() const
{
    return m_StyledNodePath;
}

void ApplyStyleToDocumentElementRequest::setStyledNodePath(utility::string_t styledNodePath)
{
    m_StyledNodePath = std::move(styledNodePath);
}

std::shared_ptr<StyleApply> ApplyStyleToDocumentElementRequest::getStyleApply() const
{
    return m_StyleApply;
}

void ApplyStyleToDocumentElementRequest::setStyleApply(std::shared_ptr<StyleApply> styleApply)
{
    m_StyleApply = std::move(styleApply);
}

boost::optional< utility::string_t > ApplyStyleToDocumentElementRequest::getFolder() const
{
    return m_Folder;
}

void ApplyStyleToDocumentElementRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > ApplyStyleToDocumentElementRequest::getStorage() const
{
    return m_Storage;
}

void ApplyStyleToDocumentElementRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > ApplyStyleToDocumentElementRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void ApplyStyleToDocumentElementRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > ApplyStyleToDocumentElementRequest::getPassword() const
{
    return m_Password;
}

void ApplyStyleToDocumentElementRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > ApplyStyleToDocumentElementRequest::getDestFileName() const
{
    return m_DestFileName;
}

void ApplyStyleToDocumentElementRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > ApplyStyleToDocumentElementRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void ApplyStyleToDocumentElementRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > ApplyStyleToDocumentElementRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void ApplyStyleToDocumentElementRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
