/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderPageRequest.cpp">
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

#include "RenderPageRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
RenderPageRequest::RenderPageRequest(
    utility::string_t name,
    int32_t pageIndex,
    utility::string_t format,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > fontsLocation
) : m_Name(std::move(name)),
m_PageIndex(std::move(pageIndex)),
m_Format(std::move(format)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_FontsLocation(std::move(fontsLocation))
{
}

utility::string_t RenderPageRequest::getName() const
{
    return m_Name;
}

void RenderPageRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

int32_t RenderPageRequest::getPageIndex() const
{
    return m_PageIndex;
}

void RenderPageRequest::setPageIndex(int32_t pageIndex)
{
    m_PageIndex = std::move(pageIndex);
}

utility::string_t RenderPageRequest::getFormat() const
{
    return m_Format;
}

void RenderPageRequest::setFormat(utility::string_t format)
{
    m_Format = std::move(format);
}

boost::optional< utility::string_t > RenderPageRequest::getFolder() const
{
    return m_Folder;
}

void RenderPageRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > RenderPageRequest::getStorage() const
{
    return m_Storage;
}

void RenderPageRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > RenderPageRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void RenderPageRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > RenderPageRequest::getPassword() const
{
    return m_Password;
}

void RenderPageRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > RenderPageRequest::getFontsLocation() const
{
    return m_FontsLocation;
}

void RenderPageRequest::setFontsLocation(boost::optional< utility::string_t > fontsLocation)
{
    m_FontsLocation = std::move(fontsLocation);
}

}
}
}
}
}
