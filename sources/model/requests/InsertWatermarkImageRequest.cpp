/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertWatermarkImageRequest.cpp">
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

#include "InsertWatermarkImageRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertWatermarkImageRequest::InsertWatermarkImageRequest(
    utility::string_t name,
    boost::optional< std::shared_ptr<HttpContent> > imageFile,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime,
    boost::optional< double > rotationAngle,
    boost::optional< utility::string_t > image
) : m_Name(std::move(name)),
m_ImageFile(std::move(imageFile)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime)),
m_RotationAngle(std::move(rotationAngle)),
m_Image(std::move(image))
{
}

utility::string_t InsertWatermarkImageRequest::getName() const
{
    return m_Name;
}

void InsertWatermarkImageRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

boost::optional< std::shared_ptr<HttpContent> > InsertWatermarkImageRequest::getImageFile() const
{
    return m_ImageFile;
}

void InsertWatermarkImageRequest::setImageFile(boost::optional< std::shared_ptr<HttpContent> > imageFile)
{
    m_ImageFile = std::move(imageFile);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getFolder() const
{
    return m_Folder;
}

void InsertWatermarkImageRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getStorage() const
{
    return m_Storage;
}

void InsertWatermarkImageRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertWatermarkImageRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getPassword() const
{
    return m_Password;
}

void InsertWatermarkImageRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertWatermarkImageRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertWatermarkImageRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertWatermarkImageRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

boost::optional< double > InsertWatermarkImageRequest::getRotationAngle() const
{
    return m_RotationAngle;
}

void InsertWatermarkImageRequest::setRotationAngle(boost::optional< double > rotationAngle)
{
    m_RotationAngle = std::move(rotationAngle);
}

boost::optional< utility::string_t > InsertWatermarkImageRequest::getImage() const
{
    return m_Image;
}

void InsertWatermarkImageRequest::setImage(boost::optional< utility::string_t > image)
{
    m_Image = std::move(image);
}

}
}
}
}
}
