/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetHeaderFooterOfSectionOnlineRequest.cpp">
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

#include "GetHeaderFooterOfSectionOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetHeaderFooterOfSectionOnlineRequest::GetHeaderFooterOfSectionOnlineRequest(
    std::shared_ptr<HttpContent> document,
    int32_t headerFooterIndex,
    int32_t sectionIndex,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > filterByType
) : m_Document(std::move(document)),
m_HeaderFooterIndex(std::move(headerFooterIndex)),
m_SectionIndex(std::move(sectionIndex)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_FilterByType(std::move(filterByType))
{
}

std::shared_ptr<HttpContent> GetHeaderFooterOfSectionOnlineRequest::getDocument() const
{
    return m_Document;
}

void GetHeaderFooterOfSectionOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

int32_t GetHeaderFooterOfSectionOnlineRequest::getHeaderFooterIndex() const
{
    return m_HeaderFooterIndex;
}

void GetHeaderFooterOfSectionOnlineRequest::setHeaderFooterIndex(int32_t headerFooterIndex)
{
    m_HeaderFooterIndex = std::move(headerFooterIndex);
}

int32_t GetHeaderFooterOfSectionOnlineRequest::getSectionIndex() const
{
    return m_SectionIndex;
}

void GetHeaderFooterOfSectionOnlineRequest::setSectionIndex(int32_t sectionIndex)
{
    m_SectionIndex = std::move(sectionIndex);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetHeaderFooterOfSectionOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionOnlineRequest::getPassword() const
{
    return m_Password;
}

void GetHeaderFooterOfSectionOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > GetHeaderFooterOfSectionOnlineRequest::getFilterByType() const
{
    return m_FilterByType;
}

void GetHeaderFooterOfSectionOnlineRequest::setFilterByType(boost::optional< utility::string_t > filterByType)
{
    m_FilterByType = std::move(filterByType);
}

}
}
}
}
}
