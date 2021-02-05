/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateSectionPageSetupRequest.cpp">
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

#include "UpdateSectionPageSetupRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateSectionPageSetupRequest::UpdateSectionPageSetupRequest(
    utility::string_t name,
    int32_t sectionIndex,
    std::shared_ptr<PageSetup> pageSetup,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_SectionIndex(std::move(sectionIndex)),
m_PageSetup(std::move(pageSetup)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t UpdateSectionPageSetupRequest::getName() const
{
    return m_Name;
}

void UpdateSectionPageSetupRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

int32_t UpdateSectionPageSetupRequest::getSectionIndex() const
{
    return m_SectionIndex;
}

void UpdateSectionPageSetupRequest::setSectionIndex(int32_t sectionIndex)
{
    m_SectionIndex = std::move(sectionIndex);
}

std::shared_ptr<PageSetup> UpdateSectionPageSetupRequest::getPageSetup() const
{
    return m_PageSetup;
}

void UpdateSectionPageSetupRequest::setPageSetup(std::shared_ptr<PageSetup> pageSetup)
{
    m_PageSetup = std::move(pageSetup);
}

boost::optional< utility::string_t > UpdateSectionPageSetupRequest::getFolder() const
{
    return m_Folder;
}

void UpdateSectionPageSetupRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateSectionPageSetupRequest::getStorage() const
{
    return m_Storage;
}

void UpdateSectionPageSetupRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateSectionPageSetupRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateSectionPageSetupRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateSectionPageSetupRequest::getPassword() const
{
    return m_Password;
}

void UpdateSectionPageSetupRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateSectionPageSetupRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateSectionPageSetupRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateSectionPageSetupRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateSectionPageSetupRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateSectionPageSetupRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateSectionPageSetupRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
