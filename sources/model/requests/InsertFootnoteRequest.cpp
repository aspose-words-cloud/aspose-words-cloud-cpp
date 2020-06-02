/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFootnoteRequest.cpp">
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

#include "InsertFootnoteRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertFootnoteRequest::InsertFootnoteRequest(
    utility::string_t name,
    std::shared_ptr<FootnoteInsert> footnoteDto,
    utility::string_t nodePath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_FootnoteDto(std::move(footnoteDto)),
m_NodePath(std::move(nodePath)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t InsertFootnoteRequest::getName() const
{
    return m_Name;
}

void InsertFootnoteRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<FootnoteInsert> InsertFootnoteRequest::getFootnoteDto() const
{
    return m_FootnoteDto;
}

void InsertFootnoteRequest::setFootnoteDto(std::shared_ptr<FootnoteInsert> footnoteDto)
{
    m_FootnoteDto = std::move(footnoteDto);
}

utility::string_t InsertFootnoteRequest::getNodePath() const
{
    return m_NodePath;
}

void InsertFootnoteRequest::setNodePath(utility::string_t nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > InsertFootnoteRequest::getFolder() const
{
    return m_Folder;
}

void InsertFootnoteRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertFootnoteRequest::getStorage() const
{
    return m_Storage;
}

void InsertFootnoteRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertFootnoteRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertFootnoteRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertFootnoteRequest::getPassword() const
{
    return m_Password;
}

void InsertFootnoteRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertFootnoteRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertFootnoteRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertFootnoteRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertFootnoteRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertFootnoteRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertFootnoteRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
