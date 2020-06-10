/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetStyleRequest.cpp">
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

#include "GetStyleRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetStyleRequest::GetStyleRequest(
    utility::string_t name,
    utility::string_t styleName,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password
) : m_Name(std::move(name)),
m_StyleName(std::move(styleName)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password))
{
}

utility::string_t GetStyleRequest::getName() const
{
    return m_Name;
}

void GetStyleRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t GetStyleRequest::getStyleName() const
{
    return m_StyleName;
}

void GetStyleRequest::setStyleName(utility::string_t styleName)
{
    m_StyleName = std::move(styleName);
}

boost::optional< utility::string_t > GetStyleRequest::getFolder() const
{
    return m_Folder;
}

void GetStyleRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > GetStyleRequest::getStorage() const
{
    return m_Storage;
}

void GetStyleRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > GetStyleRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetStyleRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetStyleRequest::getPassword() const
{
    return m_Password;
}

void GetStyleRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

}
}
}
}
}
