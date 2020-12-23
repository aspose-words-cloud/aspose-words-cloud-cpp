/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateRunFontOnlineRequest.cpp">
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

#include "UpdateRunFontOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateRunFontOnlineRequest::UpdateRunFontOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t paragraphPath,
    std::shared_ptr<Font> fontDto,
    int32_t index,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_ParagraphPath(std::move(paragraphPath)),
m_FontDto(std::move(fontDto)),
m_Index(std::move(index)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateRunFontOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateRunFontOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t UpdateRunFontOnlineRequest::getParagraphPath() const
{
    return m_ParagraphPath;
}

void UpdateRunFontOnlineRequest::setParagraphPath(utility::string_t paragraphPath)
{
    m_ParagraphPath = std::move(paragraphPath);
}

std::shared_ptr<Font> UpdateRunFontOnlineRequest::getFontDto() const
{
    return m_FontDto;
}

void UpdateRunFontOnlineRequest::setFontDto(std::shared_ptr<Font> fontDto)
{
    m_FontDto = std::move(fontDto);
}

int32_t UpdateRunFontOnlineRequest::getIndex() const
{
    return m_Index;
}

void UpdateRunFontOnlineRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > UpdateRunFontOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateRunFontOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateRunFontOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateRunFontOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateRunFontOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateRunFontOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateRunFontOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateRunFontOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateRunFontOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateRunFontOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
