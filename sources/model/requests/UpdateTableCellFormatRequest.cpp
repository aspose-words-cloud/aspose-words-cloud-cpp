/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTableCellFormatRequest.cpp">
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

#include "UpdateTableCellFormatRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateTableCellFormatRequest::UpdateTableCellFormatRequest(
    utility::string_t name,
    std::shared_ptr<TableCellFormat> format,
    utility::string_t tableRowPath,
    int32_t index,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_Format(std::move(format)),
m_TableRowPath(std::move(tableRowPath)),
m_Index(std::move(index)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t UpdateTableCellFormatRequest::getName() const
{
    return m_Name;
}

void UpdateTableCellFormatRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<TableCellFormat> UpdateTableCellFormatRequest::getFormat() const
{
    return m_Format;
}

void UpdateTableCellFormatRequest::setFormat(std::shared_ptr<TableCellFormat> format)
{
    m_Format = std::move(format);
}

utility::string_t UpdateTableCellFormatRequest::getTableRowPath() const
{
    return m_TableRowPath;
}

void UpdateTableCellFormatRequest::setTableRowPath(utility::string_t tableRowPath)
{
    m_TableRowPath = std::move(tableRowPath);
}

int32_t UpdateTableCellFormatRequest::getIndex() const
{
    return m_Index;
}

void UpdateTableCellFormatRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > UpdateTableCellFormatRequest::getFolder() const
{
    return m_Folder;
}

void UpdateTableCellFormatRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateTableCellFormatRequest::getStorage() const
{
    return m_Storage;
}

void UpdateTableCellFormatRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateTableCellFormatRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateTableCellFormatRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateTableCellFormatRequest::getPassword() const
{
    return m_Password;
}

void UpdateTableCellFormatRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateTableCellFormatRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateTableCellFormatRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateTableCellFormatRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateTableCellFormatRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateTableCellFormatRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateTableCellFormatRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
