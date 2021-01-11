/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTablePropertiesOnlineRequest.cpp">
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

#include "UpdateTablePropertiesOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateTablePropertiesOnlineRequest::UpdateTablePropertiesOnlineRequest(
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<TableProperties> properties,
    int32_t index,
    boost::optional< utility::string_t > nodePath,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Document(std::move(document)),
m_Properties(std::move(properties)),
m_Index(std::move(index)),
m_NodePath(std::move(nodePath)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

std::shared_ptr<HttpContent> UpdateTablePropertiesOnlineRequest::getDocument() const
{
    return m_Document;
}

void UpdateTablePropertiesOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<TableProperties> UpdateTablePropertiesOnlineRequest::getProperties() const
{
    return m_Properties;
}

void UpdateTablePropertiesOnlineRequest::setProperties(std::shared_ptr<TableProperties> properties)
{
    m_Properties = std::move(properties);
}

int32_t UpdateTablePropertiesOnlineRequest::getIndex() const
{
    return m_Index;
}

void UpdateTablePropertiesOnlineRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > UpdateTablePropertiesOnlineRequest::getNodePath() const
{
    return m_NodePath;
}

void UpdateTablePropertiesOnlineRequest::setNodePath(boost::optional< utility::string_t > nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > UpdateTablePropertiesOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateTablePropertiesOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateTablePropertiesOnlineRequest::getPassword() const
{
    return m_Password;
}

void UpdateTablePropertiesOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateTablePropertiesOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateTablePropertiesOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateTablePropertiesOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateTablePropertiesOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateTablePropertiesOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateTablePropertiesOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
