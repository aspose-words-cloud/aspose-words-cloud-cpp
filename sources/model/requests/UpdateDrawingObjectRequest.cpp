/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateDrawingObjectRequest.cpp">
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
#include "UpdateDrawingObjectRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateDrawingObjectRequest::UpdateDrawingObjectRequest(
        utility::string_t name,
                std::shared_ptr<DrawingObjectUpdate> drawingObject,
                std::shared_ptr<HttpContent> imageFile,
                utility::string_t nodePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_drawingObject(std::move(drawingObject)),
            m_imageFile(std::move(imageFile)),
            m_nodePath(std::move(nodePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateDrawingObjectRequest::getName() const
        {
            return m_name;
        }
        void UpdateDrawingObjectRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<DrawingObjectUpdate> UpdateDrawingObjectRequest::getDrawingObject() const
        {
            return m_drawingObject;
        }
        void UpdateDrawingObjectRequest::setDrawingObject(std::shared_ptr<DrawingObjectUpdate> drawingObject){
            m_drawingObject = std::move(drawingObject);
        }
        std::shared_ptr<HttpContent> UpdateDrawingObjectRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void UpdateDrawingObjectRequest::setImageFile(std::shared_ptr<HttpContent> imageFile){
            m_imageFile = std::move(imageFile);
        }
        utility::string_t UpdateDrawingObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateDrawingObjectRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        int32_t UpdateDrawingObjectRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateDrawingObjectRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateDrawingObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateDrawingObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateDrawingObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateDrawingObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateDrawingObjectRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateDrawingObjectRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateDrawingObjectRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateDrawingObjectRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

