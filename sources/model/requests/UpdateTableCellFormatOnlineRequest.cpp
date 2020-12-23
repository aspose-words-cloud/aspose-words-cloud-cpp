/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTableCellFormatOnlineRequest.cpp">
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

#include "UpdateTableCellFormatOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateTableCellFormatOnlineRequest::UpdateTableCellFormatOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t tableRowPath,
    std::shared_ptr<TableCellFormat> format,
    int32_t index,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_TableRowPath(std::move(tableRowPath)),
m_Format(std::move(format)),
m_Index(std::move(index)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateTableCellFormatOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateTableCellFormatOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t UpdateTableCellFormatOnlineRequest::getTableRowPath() const
{
    return m_TableRowPath;
}

void UpdateTableCellFormatOnlineRequest::setTableRowPath(utility::string_t tableRowPath)
{
    m_TableRowPath = std::move(tableRowPath);
}

std::shared_ptr<TableCellFormat> UpdateTableCellFormatOnlineRequest::getFormat() const
{
    return m_Format;
}

void UpdateTableCellFormatOnlineRequest::setFormat(std::shared_ptr<TableCellFormat> format)
{
    m_Format = std::move(format);
}

int32_t UpdateTableCellFormatOnlineRequest::getIndex() const
{
    return m_Index;
}

void UpdateTableCellFormatOnlineRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > UpdateTableCellFormatOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateTableCellFormatOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateTableCellFormatOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateTableCellFormatOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateTableCellFormatOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateTableCellFormatOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateTableCellFormatOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateTableCellFormatOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateTableCellFormatOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateTableCellFormatOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
