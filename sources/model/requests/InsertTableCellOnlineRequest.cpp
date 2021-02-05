/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableCellOnlineRequest.cpp">
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

#include "InsertTableCellOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertTableCellOnlineRequest::InsertTableCellOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t tableRowPath,
    std::shared_ptr<TableCellInsert> cell,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_TableRowPath(std::move(tableRowPath)),
m_Cell(std::move(cell)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> InsertTableCellOnlineRequest::getDocument() const
{
    return m_Document;
}

void InsertTableCellOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t InsertTableCellOnlineRequest::getTableRowPath() const
{
    return m_TableRowPath;
}

void InsertTableCellOnlineRequest::setTableRowPath(utility::string_t tableRowPath)
{
    m_TableRowPath = std::move(tableRowPath);
}

std::shared_ptr<TableCellInsert> InsertTableCellOnlineRequest::getCell() const
{
    return m_Cell;
}

void InsertTableCellOnlineRequest::setCell(std::shared_ptr<TableCellInsert> cell)
{
    m_Cell = std::move(cell);
}

boost::optional< utility::string_t > InsertTableCellOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertTableCellOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertTableCellOnlineRequest::getPassword() const
{
    return m_Password;
}

void InsertTableCellOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertTableCellOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertTableCellOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertTableCellOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertTableCellOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertTableCellOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertTableCellOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
