/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateFootnoteRequest.cpp">
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

#include "UpdateFootnoteRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateFootnoteRequest::UpdateFootnoteRequest(
    utility::string_t name,
    std::shared_ptr<FootnoteUpdate> footnoteDto,
    int32_t index,
    boost::optional< utility::string_t > nodePath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_FootnoteDto(std::move(footnoteDto)),
m_Index(std::move(index)),
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

utility::string_t UpdateFootnoteRequest::getName() const
{
    return m_Name;
}

void UpdateFootnoteRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<FootnoteUpdate> UpdateFootnoteRequest::getFootnoteDto() const
{
    return m_FootnoteDto;
}

void UpdateFootnoteRequest::setFootnoteDto(std::shared_ptr<FootnoteUpdate> footnoteDto)
{
    m_FootnoteDto = std::move(footnoteDto);
}

int32_t UpdateFootnoteRequest::getIndex() const
{
    return m_Index;
}

void UpdateFootnoteRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getNodePath() const
{
    return m_NodePath;
}

void UpdateFootnoteRequest::setNodePath(boost::optional< utility::string_t > nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getFolder() const
{
    return m_Folder;
}

void UpdateFootnoteRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getStorage() const
{
    return m_Storage;
}

void UpdateFootnoteRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateFootnoteRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getPassword() const
{
    return m_Password;
}

void UpdateFootnoteRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateFootnoteRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateFootnoteRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateFootnoteRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateFootnoteRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
