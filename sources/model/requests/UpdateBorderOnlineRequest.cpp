/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateBorderOnlineRequest.cpp">
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

#include "UpdateBorderOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateBorderOnlineRequest::UpdateBorderOnlineRequest(
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<Border> borderProperties,
    utility::string_t borderType,
    boost::optional< utility::string_t > nodePath,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_BorderProperties(std::move(borderProperties)),
m_BorderType(std::move(borderType)),
m_NodePath(std::move(nodePath)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateBorderOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateBorderOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<Border> UpdateBorderOnlineRequest::getBorderProperties() const
{
    return m_BorderProperties;
}

void UpdateBorderOnlineRequest::setBorderProperties(std::shared_ptr<Border> borderProperties)
{
    m_BorderProperties = std::move(borderProperties);
}

utility::string_t UpdateBorderOnlineRequest::getBorderType() const
{
    return m_BorderType;
}

void UpdateBorderOnlineRequest::setBorderType(utility::string_t borderType)
{
    m_BorderType = std::move(borderType);
}

boost::optional< utility::string_t > UpdateBorderOnlineRequest::getNodePath() const
{
    return m_NodePath;
}

void UpdateBorderOnlineRequest::setNodePath(boost::optional< utility::string_t > nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > UpdateBorderOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateBorderOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateBorderOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateBorderOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateBorderOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateBorderOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateBorderOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateBorderOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateBorderOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateBorderOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
