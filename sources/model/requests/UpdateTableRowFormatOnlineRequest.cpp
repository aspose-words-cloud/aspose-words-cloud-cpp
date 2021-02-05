/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTableRowFormatOnlineRequest.cpp">
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

#include "UpdateTableRowFormatOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateTableRowFormatOnlineRequest::UpdateTableRowFormatOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t tablePath,
    std::shared_ptr<TableRowFormat> format,
    int32_t index,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_TablePath(std::move(tablePath)),
m_Format(std::move(format)),
m_Index(std::move(index)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateTableRowFormatOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateTableRowFormatOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t UpdateTableRowFormatOnlineRequest::getTablePath() const
{
    return m_TablePath;
}

void UpdateTableRowFormatOnlineRequest::setTablePath(utility::string_t tablePath)
{
    m_TablePath = std::move(tablePath);
}

std::shared_ptr<TableRowFormat> UpdateTableRowFormatOnlineRequest::getFormat() const
{
    return m_Format;
}

void UpdateTableRowFormatOnlineRequest::setFormat(std::shared_ptr<TableRowFormat> format)
{
    m_Format = std::move(format);
}

int32_t UpdateTableRowFormatOnlineRequest::getIndex() const
{
    return m_Index;
}

void UpdateTableRowFormatOnlineRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > UpdateTableRowFormatOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateTableRowFormatOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateTableRowFormatOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateTableRowFormatOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateTableRowFormatOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateTableRowFormatOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateTableRowFormatOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateTableRowFormatOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateTableRowFormatOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateTableRowFormatOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
