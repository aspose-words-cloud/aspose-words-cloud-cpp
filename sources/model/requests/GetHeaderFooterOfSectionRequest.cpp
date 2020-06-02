/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetHeaderFooterOfSectionRequest.cpp">
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

#include "GetHeaderFooterOfSectionRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetHeaderFooterOfSectionRequest::GetHeaderFooterOfSectionRequest(
    utility::string_t name,
    int32_t headerFooterIndex,
    int32_t sectionIndex,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > filterByType
) : m_Name(std::move(name)),
m_HeaderFooterIndex(std::move(headerFooterIndex)),
m_SectionIndex(std::move(sectionIndex)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_FilterByType(std::move(filterByType))
{
}

utility::string_t GetHeaderFooterOfSectionRequest::getName() const
{
    return m_Name;
}

void GetHeaderFooterOfSectionRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

int32_t GetHeaderFooterOfSectionRequest::getHeaderFooterIndex() const
{
    return m_HeaderFooterIndex;
}

void GetHeaderFooterOfSectionRequest::setHeaderFooterIndex(int32_t headerFooterIndex)
{
    m_HeaderFooterIndex = std::move(headerFooterIndex);
}

int32_t GetHeaderFooterOfSectionRequest::getSectionIndex() const
{
    return m_SectionIndex;
}

void GetHeaderFooterOfSectionRequest::setSectionIndex(int32_t sectionIndex)
{
    m_SectionIndex = std::move(sectionIndex);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionRequest::getFolder() const
{
    return m_Folder;
}

void GetHeaderFooterOfSectionRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionRequest::getStorage() const
{
    return m_Storage;
}

void GetHeaderFooterOfSectionRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetHeaderFooterOfSectionRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionRequest::getPassword() const
{
    return m_Password;
}

void GetHeaderFooterOfSectionRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionRequest::getFilterByType() const
{
    return m_FilterByType;
}

void GetHeaderFooterOfSectionRequest::setFilterByType(boost::optional< utility::string_t > filterByType)
{
    m_FilterByType = std::move(filterByType);
}

}
}
}
}
}
