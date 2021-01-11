/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateRunRequest.cpp">
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

#include "UpdateRunRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateRunRequest::UpdateRunRequest(
    utility::string_t name,
    utility::string_t paragraphPath,
    int32_t index,
    std::shared_ptr<RunUpdate> run,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_ParagraphPath(std::move(paragraphPath)),
m_Index(std::move(index)),
m_Run(std::move(run)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t UpdateRunRequest::getName() const
{
    return m_Name;
}

void UpdateRunRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t UpdateRunRequest::getParagraphPath() const
{
    return m_ParagraphPath;
}

void UpdateRunRequest::setParagraphPath(utility::string_t paragraphPath)
{
    m_ParagraphPath = std::move(paragraphPath);
}

int32_t UpdateRunRequest::getIndex() const
{
    return m_Index;
}

void UpdateRunRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

std::shared_ptr<RunUpdate> UpdateRunRequest::getRun() const
{
    return m_Run;
}

void UpdateRunRequest::setRun(std::shared_ptr<RunUpdate> run)
{
    m_Run = std::move(run);
}

boost::optional< utility::string_t > UpdateRunRequest::getFolder() const
{
    return m_Folder;
}

void UpdateRunRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateRunRequest::getStorage() const
{
    return m_Storage;
}

void UpdateRunRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateRunRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateRunRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateRunRequest::getPassword() const
{
    return m_Password;
}

void UpdateRunRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateRunRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateRunRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateRunRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateRunRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateRunRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateRunRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
