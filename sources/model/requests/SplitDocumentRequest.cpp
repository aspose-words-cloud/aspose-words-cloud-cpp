/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentRequest.cpp">
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

#include "SplitDocumentRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
SplitDocumentRequest::SplitDocumentRequest(
    utility::string_t name,
    utility::string_t format,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< int32_t > from,
    boost::optional< int32_t > to,
    boost::optional< bool > zipOutput,
    boost::optional< utility::string_t > fontsLocation
) : m_Name(std::move(name)),
m_Format(std::move(format)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_From(std::move(from)),
m_To(std::move(to)),
m_ZipOutput(std::move(zipOutput)),
m_FontsLocation(std::move(fontsLocation))
{
}

utility::string_t SplitDocumentRequest::getName() const
{
    return m_Name;
}

void SplitDocumentRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t SplitDocumentRequest::getFormat() const
{
    return m_Format;
}

void SplitDocumentRequest::setFormat(utility::string_t format)
{
    m_Format = std::move(format);
}

boost::optional< utility::string_t > SplitDocumentRequest::getFolder() const
{
    return m_Folder;
}

void SplitDocumentRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > SplitDocumentRequest::getStorage() const
{
    return m_Storage;
}

void SplitDocumentRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > SplitDocumentRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void SplitDocumentRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > SplitDocumentRequest::getPassword() const
{
    return m_Password;
}

void SplitDocumentRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > SplitDocumentRequest::getDestFileName() const
{
    return m_DestFileName;
}

void SplitDocumentRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< int32_t > SplitDocumentRequest::getFrom() const
{
    return m_From;
}

void SplitDocumentRequest::setFrom(boost::optional< int32_t > from)
{
    m_From = std::move(from);
}

boost::optional< int32_t > SplitDocumentRequest::getTo() const
{
    return m_To;
}

void SplitDocumentRequest::setTo(boost::optional< int32_t > to)
{
    m_To = std::move(to);
}

boost::optional< bool > SplitDocumentRequest::getZipOutput() const
{
    return m_ZipOutput;
}

void SplitDocumentRequest::setZipOutput(boost::optional< bool > zipOutput)
{
    m_ZipOutput = std::move(zipOutput);
}

boost::optional< utility::string_t > SplitDocumentRequest::getFontsLocation() const
{
    return m_FontsLocation;
}

void SplitDocumentRequest::setFontsLocation(boost::optional< utility::string_t > fontsLocation)
{
    m_FontsLocation = std::move(fontsLocation);
}

}
}
}
}
}
