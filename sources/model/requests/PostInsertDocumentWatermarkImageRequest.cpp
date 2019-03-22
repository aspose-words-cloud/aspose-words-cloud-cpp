/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostInsertDocumentWatermarkImageRequest.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
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
#include "PostInsertDocumentWatermarkImageRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
PostInsertDocumentWatermarkImageRequest::PostInsertDocumentWatermarkImageRequest(
        utility::string_t name,
                boost::optional<std::shared_ptr<HttpContent>> imageFile,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<double> rotationAngle,
                boost::optional<utility::string_t> image
        ) : 
            m_name(std::move(name)),
            m_imageFile(std::move(imageFile)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_rotationAngle(std::move(rotationAngle)),
            m_image(std::move(image))
        {
            
        }

        utility::string_t PostInsertDocumentWatermarkImageRequest::getName() const
        {
            return m_name;
        }
        void PostInsertDocumentWatermarkImageRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<std::shared_ptr<HttpContent>> PostInsertDocumentWatermarkImageRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void PostInsertDocumentWatermarkImageRequest::setImageFile(boost::optional<std::shared_ptr<HttpContent>> imageFile){
            m_imageFile = std::move(imageFile);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getFolder() const
        {
            return m_folder;
        }
        void PostInsertDocumentWatermarkImageRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getStorage() const
        {
            return m_storage;
        }
        void PostInsertDocumentWatermarkImageRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostInsertDocumentWatermarkImageRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getPassword() const
        {
            return m_password;
        }
        void PostInsertDocumentWatermarkImageRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostInsertDocumentWatermarkImageRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PostInsertDocumentWatermarkImageRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PostInsertDocumentWatermarkImageRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<double> PostInsertDocumentWatermarkImageRequest::getRotationAngle() const
        {
            return m_rotationAngle;
        }
        void PostInsertDocumentWatermarkImageRequest::setRotationAngle(boost::optional<double> rotationAngle){
            m_rotationAngle = std::move(rotationAngle);
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getImage() const
        {
            return m_image;
        }
        void PostInsertDocumentWatermarkImageRequest::setImage(boost::optional<utility::string_t> image){
            m_image = std::move(image);
        }

}
}
}
}
}

