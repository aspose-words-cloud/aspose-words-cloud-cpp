/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ClassifyDocumentOnlineRequest.cpp">
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

#include "ClassifyDocumentOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ClassifyDocumentOnlineRequest::ClassifyDocumentOnlineRequest(
    std::shared_ptr<HttpContent> document,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > bestClassesCount,
    boost::optional< utility::string_t > taxonomy
) : m_Document(std::move(document)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_BestClassesCount(std::move(bestClassesCount)),
m_Taxonomy(std::move(taxonomy))
{
}

std::shared_ptr<HttpContent> ClassifyDocumentOnlineRequest::getDocument() const
{
    return m_Document;
}

void ClassifyDocumentOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

boost::optional< utility::string_t > ClassifyDocumentOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void ClassifyDocumentOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > ClassifyDocumentOnlineRequest::getPassword() const
{
    return m_Password;
}

void ClassifyDocumentOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > ClassifyDocumentOnlineRequest::getBestClassesCount() const
{
    return m_BestClassesCount;
}

void ClassifyDocumentOnlineRequest::setBestClassesCount(boost::optional< utility::string_t > bestClassesCount)
{
    m_BestClassesCount = std::move(bestClassesCount);
}

boost::optional< utility::string_t > ClassifyDocumentOnlineRequest::getTaxonomy() const
{
    return m_Taxonomy;
}

void ClassifyDocumentOnlineRequest::setTaxonomy(boost::optional< utility::string_t > taxonomy)
{
    m_Taxonomy = std::move(taxonomy);
}

}
}
}
}
}
