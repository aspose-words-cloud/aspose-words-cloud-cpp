/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertWatermarkImageOnlineRequest.cpp">
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

#include "InsertWatermarkImageOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertWatermarkImageOnlineRequest::InsertWatermarkImageOnlineRequest(
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<HttpContent> imageFile,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime,
    boost::optional< double > rotationAngle,
    boost::optional< utility::string_t > image
) : m_Document(std::move(document)),
m_ImageFile(std::move(imageFile)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime)),
m_RotationAngle(std::move(rotationAngle)),
m_Image(std::move(image))
{
}

std::shared_ptr<HttpContent> InsertWatermarkImageOnlineRequest::getDocument() const
{
    return m_Document;
}

void InsertWatermarkImageOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<HttpContent> InsertWatermarkImageOnlineRequest::getImageFile() const
{
    return m_ImageFile;
}

void InsertWatermarkImageOnlineRequest::setImageFile(std::shared_ptr<HttpContent> imageFile)
{
    m_ImageFile = std::move(imageFile);
}

boost::optional< utility::string_t > InsertWatermarkImageOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertWatermarkImageOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertWatermarkImageOnlineRequest::getPassword() const
{
    return m_Password;
}

void InsertWatermarkImageOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertWatermarkImageOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertWatermarkImageOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertWatermarkImageOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertWatermarkImageOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertWatermarkImageOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertWatermarkImageOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

boost::optional< double > InsertWatermarkImageOnlineRequest::getRotationAngle() const
{
    return m_RotationAngle;
}

void InsertWatermarkImageOnlineRequest::setRotationAngle(boost::optional< double > rotationAngle)
{
    m_RotationAngle = std::move(rotationAngle);
}

boost::optional< utility::string_t > InsertWatermarkImageOnlineRequest::getImage() const
{
    return m_Image;
}

void InsertWatermarkImageOnlineRequest::setImage(boost::optional< utility::string_t > image)
{
    m_Image = std::move(image);
}

}
}
}
}
}
