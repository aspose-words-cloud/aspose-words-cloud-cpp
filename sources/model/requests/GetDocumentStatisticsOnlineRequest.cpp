/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetDocumentStatisticsOnlineRequest.cpp">
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

#include "GetDocumentStatisticsOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetDocumentStatisticsOnlineRequest::GetDocumentStatisticsOnlineRequest(
    std::shared_ptr<HttpContent> document,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< bool > includeComments,
    boost::optional< bool > includeFootnotes,
    boost::optional< bool > includeTextInShapes
) : m_Document(std::move(document)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_IncludeComments(std::move(includeComments)),
m_IncludeFootnotes(std::move(includeFootnotes)),
m_IncludeTextInShapes(std::move(includeTextInShapes))
{
}

std::shared_ptr<HttpContent> GetDocumentStatisticsOnlineRequest::getDocument() const
{
    return m_Document;
}

void GetDocumentStatisticsOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

boost::optional< utility::string_t > GetDocumentStatisticsOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetDocumentStatisticsOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetDocumentStatisticsOnlineRequest::getPassword() const
{
    return m_Password;
}

void GetDocumentStatisticsOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< bool > GetDocumentStatisticsOnlineRequest::getIncludeComments() const
{
    return m_IncludeComments;
}

void GetDocumentStatisticsOnlineRequest::setIncludeComments(boost::optional< bool > includeComments)
{
    m_IncludeComments = std::move(includeComments);
}

boost::optional< bool > GetDocumentStatisticsOnlineRequest::getIncludeFootnotes() const
{
    return m_IncludeFootnotes;
}

void GetDocumentStatisticsOnlineRequest::setIncludeFootnotes(boost::optional< bool > includeFootnotes)
{
    m_IncludeFootnotes = std::move(includeFootnotes);
}

boost::optional< bool > GetDocumentStatisticsOnlineRequest::getIncludeTextInShapes() const
{
    return m_IncludeTextInShapes;
}

void GetDocumentStatisticsOnlineRequest::setIncludeTextInShapes(boost::optional< bool > includeTextInShapes)
{
    m_IncludeTextInShapes = std::move(includeTextInShapes);
}

}
}
}
}
}
