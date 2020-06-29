/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetHeaderFootersRequest.cpp">
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

#include "GetHeaderFootersRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetHeaderFootersRequest::GetHeaderFootersRequest(
    utility::string_t name,
    utility::string_t sectionPath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > filterByType
) : m_Name(std::move(name)),
m_SectionPath(std::move(sectionPath)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_FilterByType(std::move(filterByType))
{
}

utility::string_t GetHeaderFootersRequest::getName() const
{
    return m_Name;
}

void GetHeaderFootersRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t GetHeaderFootersRequest::getSectionPath() const
{
    return m_SectionPath;
}

void GetHeaderFootersRequest::setSectionPath(utility::string_t sectionPath)
{
    m_SectionPath = std::move(sectionPath);
}

boost::optional< utility::string_t > GetHeaderFootersRequest::getFolder() const
{
    return m_Folder;
}

void GetHeaderFootersRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > GetHeaderFootersRequest::getStorage() const
{
    return m_Storage;
}

void GetHeaderFootersRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > GetHeaderFootersRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetHeaderFootersRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetHeaderFootersRequest::getPassword() const
{
    return m_Password;
}

void GetHeaderFootersRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > GetHeaderFootersRequest::getFilterByType() const
{
    return m_FilterByType;
}

void GetHeaderFootersRequest::setFilterByType(boost::optional< utility::string_t > filterByType)
{
    m_FilterByType = std::move(filterByType);
}

}
}
}
}
}
