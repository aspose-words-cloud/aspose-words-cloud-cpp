/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateBorderRequest.cpp">
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

#include "UpdateBorderRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateBorderRequest::UpdateBorderRequest(
    utility::string_t name,
    utility::string_t borderType,
    std::shared_ptr<Border> borderProperties,
    boost::optional< utility::string_t > nodePath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_BorderType(std::move(borderType)),
m_BorderProperties(std::move(borderProperties)),
m_NodePath(std::move(nodePath)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t UpdateBorderRequest::getName() const
{
    return m_Name;
}

void UpdateBorderRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

utility::string_t UpdateBorderRequest::getBorderType() const
{
    return m_BorderType;
}

void UpdateBorderRequest::setBorderType(utility::string_t borderType)
{
    m_BorderType = std::move(borderType);
}

std::shared_ptr<Border> UpdateBorderRequest::getBorderProperties() const
{
    return m_BorderProperties;
}

void UpdateBorderRequest::setBorderProperties(std::shared_ptr<Border> borderProperties)
{
    m_BorderProperties = std::move(borderProperties);
}

boost::optional< utility::string_t > UpdateBorderRequest::getNodePath() const
{
    return m_NodePath;
}

void UpdateBorderRequest::setNodePath(boost::optional< utility::string_t > nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > UpdateBorderRequest::getFolder() const
{
    return m_Folder;
}

void UpdateBorderRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateBorderRequest::getStorage() const
{
    return m_Storage;
}

void UpdateBorderRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateBorderRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateBorderRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateBorderRequest::getPassword() const
{
    return m_Password;
}

void UpdateBorderRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateBorderRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateBorderRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateBorderRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateBorderRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateBorderRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateBorderRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
