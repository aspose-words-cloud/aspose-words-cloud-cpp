/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetHeaderFootersOnlineRequest.cpp">
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

#include "GetHeaderFootersOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetHeaderFootersOnlineRequest::GetHeaderFootersOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t sectionPath,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > filterByType
) : m_Document(std::move(document)),
m_SectionPath(std::move(sectionPath)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_FilterByType(std::move(filterByType))
{
}

std::shared_ptr<HttpContent> GetHeaderFootersOnlineRequest::getDocument() const
{
    return m_Document;
}

void GetHeaderFootersOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t GetHeaderFootersOnlineRequest::getSectionPath() const
{
    return m_SectionPath;
}

void GetHeaderFootersOnlineRequest::setSectionPath(utility::string_t sectionPath)
{
    m_SectionPath = std::move(sectionPath);
}

boost::optional< utility::string_t > GetHeaderFootersOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetHeaderFootersOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetHeaderFootersOnlineRequest::getPassword() const
{
    return m_Password;
}

void GetHeaderFootersOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > GetHeaderFootersOnlineRequest::getFilterByType() const
{
    return m_FilterByType;
}

void GetHeaderFootersOnlineRequest::setFilterByType(boost::optional< utility::string_t > filterByType)
{
    m_FilterByType = std::move(filterByType);
}

}
}
}
}
}
