/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFootnoteWithoutNodePathRequest.cpp">
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

#include "InsertFootnoteWithoutNodePathRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertFootnoteWithoutNodePathRequest::InsertFootnoteWithoutNodePathRequest(
    utility::string_t name,
    std::shared_ptr<FootnoteInsert> footnoteDto,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_FootnoteDto(std::move(footnoteDto)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t InsertFootnoteWithoutNodePathRequest::getName() const
{
    return m_Name;
}

void InsertFootnoteWithoutNodePathRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<FootnoteInsert> InsertFootnoteWithoutNodePathRequest::getFootnoteDto() const
{
    return m_FootnoteDto;
}

void InsertFootnoteWithoutNodePathRequest::setFootnoteDto(std::shared_ptr<FootnoteInsert> footnoteDto)
{
    m_FootnoteDto = std::move(footnoteDto);
}

boost::optional< utility::string_t > InsertFootnoteWithoutNodePathRequest::getFolder() const
{
    return m_Folder;
}

void InsertFootnoteWithoutNodePathRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertFootnoteWithoutNodePathRequest::getStorage() const
{
    return m_Storage;
}

void InsertFootnoteWithoutNodePathRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertFootnoteWithoutNodePathRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertFootnoteWithoutNodePathRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertFootnoteWithoutNodePathRequest::getPassword() const
{
    return m_Password;
}

void InsertFootnoteWithoutNodePathRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertFootnoteWithoutNodePathRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertFootnoteWithoutNodePathRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertFootnoteWithoutNodePathRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertFootnoteWithoutNodePathRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertFootnoteWithoutNodePathRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertFootnoteWithoutNodePathRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
