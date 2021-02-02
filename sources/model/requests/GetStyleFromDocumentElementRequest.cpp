/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetStyleFromDocumentElementRequest.cpp">
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

#include "GetStyleFromDocumentElementRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetStyleFromDocumentElementRequest::GetStyleFromDocumentElementRequest(
    utility::string_t name,
    utility::string_t styledNodePath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password
) : m_Name(std::move(name)),
m_StyledNodePath(std::move(styledNodePath)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password))
{
}

utility::string_t GetStyleFromDocumentElementRequest::getName() const
{
    return m_Name;
}

void GetStyleFromDocumentElementRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t GetStyleFromDocumentElementRequest::getStyledNodePath() const
{
    return m_StyledNodePath;
}

void GetStyleFromDocumentElementRequest::setStyledNodePath(utility::string_t styledNodePath)
{
    m_StyledNodePath = std::move(styledNodePath);
}

boost::optional< utility::string_t > GetStyleFromDocumentElementRequest::getFolder() const
{
    return m_Folder;
}

void GetStyleFromDocumentElementRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > GetStyleFromDocumentElementRequest::getStorage() const
{
    return m_Storage;
}

void GetStyleFromDocumentElementRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > GetStyleFromDocumentElementRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetStyleFromDocumentElementRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetStyleFromDocumentElementRequest::getPassword() const
{
    return m_Password;
}

void GetStyleFromDocumentElementRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

}
}
}
}
}
