/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertDrawingObjectRequest.cpp">
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

#include "InsertDrawingObjectRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertDrawingObjectRequest::InsertDrawingObjectRequest(
    utility::string_t name,
    std::shared_ptr<DrawingObjectInsert> drawingObject,
    std::shared_ptr<HttpContent> imageFile,
    utility::string_t nodePath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_DrawingObject(std::move(drawingObject)),
m_ImageFile(std::move(imageFile)),
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

utility::string_t InsertDrawingObjectRequest::getName() const
{
    return m_Name;
}

void InsertDrawingObjectRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<DrawingObjectInsert> InsertDrawingObjectRequest::getDrawingObject() const
{
    return m_DrawingObject;
}

void InsertDrawingObjectRequest::setDrawingObject(std::shared_ptr<DrawingObjectInsert> drawingObject)
{
    m_DrawingObject = std::move(drawingObject);
}

std::shared_ptr<HttpContent> InsertDrawingObjectRequest::getImageFile() const
{
    return m_ImageFile;
}

void InsertDrawingObjectRequest::setImageFile(std::shared_ptr<HttpContent> imageFile)
{
    m_ImageFile = std::move(imageFile);
}

utility::string_t InsertDrawingObjectRequest::getNodePath() const
{
    return m_NodePath;
}

void InsertDrawingObjectRequest::setNodePath(utility::string_t nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > InsertDrawingObjectRequest::getFolder() const
{
    return m_Folder;
}

void InsertDrawingObjectRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertDrawingObjectRequest::getStorage() const
{
    return m_Storage;
}

void InsertDrawingObjectRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertDrawingObjectRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertDrawingObjectRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertDrawingObjectRequest::getPassword() const
{
    return m_Password;
}

void InsertDrawingObjectRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertDrawingObjectRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertDrawingObjectRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertDrawingObjectRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertDrawingObjectRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertDrawingObjectRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertDrawingObjectRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
