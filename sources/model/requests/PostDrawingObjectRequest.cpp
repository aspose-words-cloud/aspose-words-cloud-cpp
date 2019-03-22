/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostDrawingObjectRequest.cpp">
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
#include "PostDrawingObjectRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
PostDrawingObjectRequest::PostDrawingObjectRequest(
        utility::string_t name,
                utility::string_t drawingObject,
                std::shared_ptr<HttpContent> imageFile,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> nodePath
        ) : 
            m_name(std::move(name)),
            m_drawingObject(std::move(drawingObject)),
            m_imageFile(std::move(imageFile)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_nodePath(std::move(nodePath))
        {
            
        }

        utility::string_t PostDrawingObjectRequest::getName() const
        {
            return m_name;
        }
        void PostDrawingObjectRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t PostDrawingObjectRequest::getDrawingObject() const
        {
            return m_drawingObject;
        }
        void PostDrawingObjectRequest::setDrawingObject(utility::string_t drawingObject){
            m_drawingObject = std::move(drawingObject);
        }
        std::shared_ptr<HttpContent> PostDrawingObjectRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void PostDrawingObjectRequest::setImageFile(std::shared_ptr<HttpContent> imageFile){
            m_imageFile = std::move(imageFile);
        }
        int32_t PostDrawingObjectRequest::getIndex() const
        {
            return m_index;
        }
        void PostDrawingObjectRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void PostDrawingObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void PostDrawingObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostDrawingObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getPassword() const
        {
            return m_password;
        }
        void PostDrawingObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostDrawingObjectRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PostDrawingObjectRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PostDrawingObjectRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void PostDrawingObjectRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = std::move(nodePath);
        }

}
}
}
}
}

