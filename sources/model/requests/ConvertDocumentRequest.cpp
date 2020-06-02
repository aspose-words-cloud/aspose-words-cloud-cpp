/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ConvertDocumentRequest.cpp">
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

#include "ConvertDocumentRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ConvertDocumentRequest::ConvertDocumentRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t format,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > outPath,
    boost::optional< utility::string_t > fileNameFieldValue,
    boost::optional< utility::string_t > fontsLocation
) : m_Document(std::move(document)),
m_Format(std::move(format)),
m_Storage(std::move(storage)),
m_OutPath(std::move(outPath)),
m_FileNameFieldValue(std::move(fileNameFieldValue)),
m_FontsLocation(std::move(fontsLocation))
{
}

std::shared_ptr<HttpContent> ConvertDocumentRequest::getDocument() const
{
    return m_Document;
}

void ConvertDocumentRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t ConvertDocumentRequest::getFormat() const
{
    return m_Format;
}

void ConvertDocumentRequest::setFormat(utility::string_t format)
{
    m_Format = std::move(format);
}

boost::optional< utility::string_t > ConvertDocumentRequest::getStorage() const
{
    return m_Storage;
}

void ConvertDocumentRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > ConvertDocumentRequest::getOutPath() const
{
    return m_OutPath;
}

void ConvertDocumentRequest::setOutPath(boost::optional< utility::string_t > outPath)
{
    m_OutPath = std::move(outPath);
}

boost::optional< utility::string_t > ConvertDocumentRequest::getFileNameFieldValue() const
{
    return m_FileNameFieldValue;
}

void ConvertDocumentRequest::setFileNameFieldValue(boost::optional< utility::string_t > fileNameFieldValue)
{
    m_FileNameFieldValue = std::move(fileNameFieldValue);
}

boost::optional< utility::string_t > ConvertDocumentRequest::getFontsLocation() const
{
    return m_FontsLocation;
}

void ConvertDocumentRequest::setFontsLocation(boost::optional< utility::string_t > fontsLocation)
{
    m_FontsLocation = std::move(fontsLocation);
}

}
}
}
}
}
