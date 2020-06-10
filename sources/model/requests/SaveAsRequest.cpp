/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsRequest.cpp">
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

#include "SaveAsRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
SaveAsRequest::SaveAsRequest(
    utility::string_t name,
    std::shared_ptr<SaveOptionsData> saveOptionsData,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > fontsLocation
) : m_Name(std::move(name)),
m_SaveOptionsData(std::move(saveOptionsData)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_FontsLocation(std::move(fontsLocation))
{
}

utility::string_t SaveAsRequest::getName() const
{
    return m_Name;
}

void SaveAsRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<SaveOptionsData> SaveAsRequest::getSaveOptionsData() const
{
    return m_SaveOptionsData;
}

void SaveAsRequest::setSaveOptionsData(std::shared_ptr<SaveOptionsData> saveOptionsData)
{
    m_SaveOptionsData = std::move(saveOptionsData);
}

boost::optional< utility::string_t > SaveAsRequest::getFolder() const
{
    return m_Folder;
}

void SaveAsRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > SaveAsRequest::getStorage() const
{
    return m_Storage;
}

void SaveAsRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > SaveAsRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void SaveAsRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > SaveAsRequest::getPassword() const
{
    return m_Password;
}

void SaveAsRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > SaveAsRequest::getFontsLocation() const
{
    return m_FontsLocation;
}

void SaveAsRequest::setFontsLocation(boost::optional< utility::string_t > fontsLocation)
{
    m_FontsLocation = std::move(fontsLocation);
}

}
}
}
}
}
