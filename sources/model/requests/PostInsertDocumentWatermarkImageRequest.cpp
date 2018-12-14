/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostInsertDocumentWatermarkImageRequest.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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
namespace io{
namespace swagger{
namespace client{
namespace model{
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
            m_name(name),
            m_imageFile(imageFile),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_destFileName(destFileName),
            m_revisionAuthor(revisionAuthor),
            m_revisionDateTime(revisionDateTime),
            m_rotationAngle(rotationAngle),
            m_image(image)
        {
            
        }

        utility::string_t PostInsertDocumentWatermarkImageRequest::getName() const
        {
            return m_name;
        }
        void PostInsertDocumentWatermarkImageRequest::setName(utility::string_t name){
            m_name = name;
        }
        boost::optional<std::shared_ptr<HttpContent>> PostInsertDocumentWatermarkImageRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void PostInsertDocumentWatermarkImageRequest::setImageFile(boost::optional<std::shared_ptr<HttpContent>> imageFile){
            m_imageFile = imageFile;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getFolder() const
        {
            return m_folder;
        }
        void PostInsertDocumentWatermarkImageRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getStorage() const
        {
            return m_storage;
        }
        void PostInsertDocumentWatermarkImageRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostInsertDocumentWatermarkImageRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getPassword() const
        {
            return m_password;
        }
        void PostInsertDocumentWatermarkImageRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostInsertDocumentWatermarkImageRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PostInsertDocumentWatermarkImageRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = revisionAuthor;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PostInsertDocumentWatermarkImageRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = revisionDateTime;
        }
        boost::optional<double> PostInsertDocumentWatermarkImageRequest::getRotationAngle() const
        {
            return m_rotationAngle;
        }
        void PostInsertDocumentWatermarkImageRequest::setRotationAngle(boost::optional<double> rotationAngle){
            m_rotationAngle = rotationAngle;
        }
        boost::optional<utility::string_t> PostInsertDocumentWatermarkImageRequest::getImage() const
        {
            return m_image;
        }
        void PostInsertDocumentWatermarkImageRequest::setImage(boost::optional<utility::string_t> image){
            m_image = image;
        }

}
}
}
}

