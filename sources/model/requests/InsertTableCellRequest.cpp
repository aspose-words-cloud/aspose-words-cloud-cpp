/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableCellRequest.cpp">
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

#include "InsertTableCellRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertTableCellRequest::InsertTableCellRequest(
    utility::string_t name,
    std::shared_ptr<TableCellInsert> cell,
    utility::string_t tableRowPath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_Cell(std::move(cell)),
m_TableRowPath(std::move(tableRowPath)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t InsertTableCellRequest::getName() const
{
    return m_Name;
}

void InsertTableCellRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<TableCellInsert> InsertTableCellRequest::getCell() const
{
    return m_Cell;
}

void InsertTableCellRequest::setCell(std::shared_ptr<TableCellInsert> cell)
{
    m_Cell = std::move(cell);
}

utility::string_t InsertTableCellRequest::getTableRowPath() const
{
    return m_TableRowPath;
}

void InsertTableCellRequest::setTableRowPath(utility::string_t tableRowPath)
{
    m_TableRowPath = std::move(tableRowPath);
}

boost::optional< utility::string_t > InsertTableCellRequest::getFolder() const
{
    return m_Folder;
}

void InsertTableCellRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertTableCellRequest::getStorage() const
{
    return m_Storage;
}

void InsertTableCellRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertTableCellRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertTableCellRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertTableCellRequest::getPassword() const
{
    return m_Password;
}

void InsertTableCellRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertTableCellRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertTableCellRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertTableCellRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertTableCellRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertTableCellRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertTableCellRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
