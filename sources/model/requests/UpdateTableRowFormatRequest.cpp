/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTableRowFormatRequest.cpp">
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

#include "UpdateTableRowFormatRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateTableRowFormatRequest::UpdateTableRowFormatRequest(
    utility::string_t name,
    utility::string_t tablePath,
    int32_t index,
    std::shared_ptr<TableRowFormat> format,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_TablePath(std::move(tablePath)),
m_Index(std::move(index)),
m_Format(std::move(format)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t UpdateTableRowFormatRequest::getName() const
{
    return m_Name;
}

void UpdateTableRowFormatRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t UpdateTableRowFormatRequest::getTablePath() const
{
    return m_TablePath;
}

void UpdateTableRowFormatRequest::setTablePath(utility::string_t tablePath)
{
    m_TablePath = std::move(tablePath);
}

int32_t UpdateTableRowFormatRequest::getIndex() const
{
    return m_Index;
}

void UpdateTableRowFormatRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

std::shared_ptr<TableRowFormat> UpdateTableRowFormatRequest::getFormat() const
{
    return m_Format;
}

void UpdateTableRowFormatRequest::setFormat(std::shared_ptr<TableRowFormat> format)
{
    m_Format = std::move(format);
}

boost::optional< utility::string_t > UpdateTableRowFormatRequest::getFolder() const
{
    return m_Folder;
}

void UpdateTableRowFormatRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateTableRowFormatRequest::getStorage() const
{
    return m_Storage;
}

void UpdateTableRowFormatRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateTableRowFormatRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateTableRowFormatRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateTableRowFormatRequest::getPassword() const
{
    return m_Password;
}

void UpdateTableRowFormatRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateTableRowFormatRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateTableRowFormatRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateTableRowFormatRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateTableRowFormatRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateTableRowFormatRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateTableRowFormatRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
