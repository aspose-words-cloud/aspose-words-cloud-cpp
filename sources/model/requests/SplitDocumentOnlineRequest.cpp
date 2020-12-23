/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentOnlineRequest.cpp">
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

#include "SplitDocumentOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
SplitDocumentOnlineRequest::SplitDocumentOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t format,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< int32_t > from,
    boost::optional< int32_t > to,
    boost::optional< bool > zipOutput,
    boost::optional< utility::string_t > fontsLocation
) : m_Document(std::move(document)),
m_Format(std::move(format)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_From(std::move(from)),
m_To(std::move(to)),
m_ZipOutput(std::move(zipOutput)),
m_FontsLocation(std::move(fontsLocation))
{
}

std::shared_ptr<HttpContent> SplitDocumentOnlineRequest::getDocument() const
{
    return m_Document;
}

void SplitDocumentOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t SplitDocumentOnlineRequest::getFormat() const
{
    return m_Format;
}

void SplitDocumentOnlineRequest::setFormat(utility::string_t format)
{
    m_Format = std::move(format);
}

boost::optional< utility::string_t > SplitDocumentOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void SplitDocumentOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > SplitDocumentOnlineRequest::getPassword() const
{
    return m_Password;
}

void SplitDocumentOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > SplitDocumentOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void SplitDocumentOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< int32_t > SplitDocumentOnlineRequest::getFrom() const
{
    return m_From;
}

void SplitDocumentOnlineRequest::setFrom(boost::optional< int32_t > from)
{
    m_From = std::move(from);
}

boost::optional< int32_t > SplitDocumentOnlineRequest::getTo() const
{
    return m_To;
}

void SplitDocumentOnlineRequest::setTo(boost::optional< int32_t > to)
{
    m_To = std::move(to);
}

boost::optional< bool > SplitDocumentOnlineRequest::getZipOutput() const
{
    return m_ZipOutput;
}

void SplitDocumentOnlineRequest::setZipOutput(boost::optional< bool > zipOutput)
{
    m_ZipOutput = std::move(zipOutput);
}

boost::optional< utility::string_t > SplitDocumentOnlineRequest::getFontsLocation() const
{
    return m_FontsLocation;
}

void SplitDocumentOnlineRequest::setFontsLocation(boost::optional< utility::string_t > fontsLocation)
{
    m_FontsLocation = std::move(fontsLocation);
}

}
}
}
}
}
