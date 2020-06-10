/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateRunFontRequest.cpp">
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

#include "UpdateRunFontRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateRunFontRequest::UpdateRunFontRequest(
    utility::string_t name,
    std::shared_ptr<Font> fontDto,
    utility::string_t paragraphPath,
    int32_t index,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_FontDto(std::move(fontDto)),
m_ParagraphPath(std::move(paragraphPath)),
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

utility::string_t UpdateRunFontRequest::getName() const
{
    return m_Name;
}

void UpdateRunFontRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<Font> UpdateRunFontRequest::getFontDto() const
{
    return m_FontDto;
}

void UpdateRunFontRequest::setFontDto(std::shared_ptr<Font> fontDto)
{
    m_FontDto = std::move(fontDto);
}

utility::string_t UpdateRunFontRequest::getParagraphPath() const
{
    return m_ParagraphPath;
}

void UpdateRunFontRequest::setParagraphPath(utility::string_t paragraphPath)
{
    m_ParagraphPath = std::move(paragraphPath);
}

int32_t UpdateRunFontRequest::getIndex() const
{
    return m_Index;
}

void UpdateRunFontRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > UpdateRunFontRequest::getFolder() const
{
    return m_Folder;
}

void UpdateRunFontRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateRunFontRequest::getStorage() const
{
    return m_Storage;
}

void UpdateRunFontRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateRunFontRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateRunFontRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateRunFontRequest::getPassword() const
{
    return m_Password;
}

void UpdateRunFontRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateRunFontRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateRunFontRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateRunFontRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateRunFontRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateRunFontRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateRunFontRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
