/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetSectionPageSetupRequest.cpp">
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

#include "GetSectionPageSetupRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetSectionPageSetupRequest::GetSectionPageSetupRequest(
    utility::string_t name,
    int32_t sectionIndex,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password
) : m_Name(std::move(name)),
m_SectionIndex(std::move(sectionIndex)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password))
{
}

utility::string_t GetSectionPageSetupRequest::getName() const
{
    return m_Name;
}

void GetSectionPageSetupRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

int32_t GetSectionPageSetupRequest::getSectionIndex() const
{
    return m_SectionIndex;
}

void GetSectionPageSetupRequest::setSectionIndex(int32_t sectionIndex)
{
    m_SectionIndex = std::move(sectionIndex);
}

boost::optional< utility::string_t > GetSectionPageSetupRequest::getFolder() const
{
    return m_Folder;
}

void GetSectionPageSetupRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > GetSectionPageSetupRequest::getStorage() const
{
    return m_Storage;
}

void GetSectionPageSetupRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > GetSectionPageSetupRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetSectionPageSetupRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetSectionPageSetupRequest::getPassword() const
{
    return m_Password;
}

void GetSectionPageSetupRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

}
}
}
}
}
