/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderPageOnlineRequest.cpp">
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

#include "RenderPageOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
RenderPageOnlineRequest::RenderPageOnlineRequest(
    std::shared_ptr<HttpContent> document,
    int32_t pageIndex,
    utility::string_t format,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > fontsLocation
) : m_Document(std::move(document)),
m_PageIndex(std::move(pageIndex)),
m_Format(std::move(format)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_FontsLocation(std::move(fontsLocation))
{
}

std::shared_ptr<HttpContent> RenderPageOnlineRequest::getDocument() const
{
    return m_Document;
}

void RenderPageOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

int32_t RenderPageOnlineRequest::getPageIndex() const
{
    return m_PageIndex;
}

void RenderPageOnlineRequest::setPageIndex(int32_t pageIndex)
{
    m_PageIndex = std::move(pageIndex);
}

utility::string_t RenderPageOnlineRequest::getFormat() const
{
    return m_Format;
}

void RenderPageOnlineRequest::setFormat(utility::string_t format)
{
    m_Format = std::move(format);
}

boost::optional< utility::string_t > RenderPageOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void RenderPageOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > RenderPageOnlineRequest::getPassword() const
{
    return m_Password;
}

void RenderPageOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > RenderPageOnlineRequest::getFontsLocation() const
{
    return m_FontsLocation;
}

void RenderPageOnlineRequest::setFontsLocation(boost::optional< utility::string_t > fontsLocation)
{
    m_FontsLocation = std::move(fontsLocation);
}

}
}
}
}
}
