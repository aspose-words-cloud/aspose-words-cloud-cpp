/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostDrawingObjectRequest.cpp">
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
#include "PostDrawingObjectRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
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
            m_name(name),
            m_drawingObject(drawingObject),
            m_imageFile(imageFile),
            m_index(index),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_destFileName(destFileName),
            m_revisionAuthor(revisionAuthor),
            m_revisionDateTime(revisionDateTime),
            m_nodePath(nodePath)
        {
            
        }

        utility::string_t PostDrawingObjectRequest::getName() const
        {
            return m_name;
        }
        void PostDrawingObjectRequest::setName(utility::string_t name){
            m_name = name;
        }
        utility::string_t PostDrawingObjectRequest::getDrawingObject() const
        {
            return m_drawingObject;
        }
        void PostDrawingObjectRequest::setDrawingObject(utility::string_t drawingObject){
            m_drawingObject = drawingObject;
        }
        std::shared_ptr<HttpContent> PostDrawingObjectRequest::getImageFile() const
        {
            return m_imageFile;
        }
        void PostDrawingObjectRequest::setImageFile(std::shared_ptr<HttpContent> imageFile){
            m_imageFile = imageFile;
        }
        int32_t PostDrawingObjectRequest::getIndex() const
        {
            return m_index;
        }
        void PostDrawingObjectRequest::setIndex(int32_t index){
            m_index = index;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void PostDrawingObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void PostDrawingObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostDrawingObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getPassword() const
        {
            return m_password;
        }
        void PostDrawingObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostDrawingObjectRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PostDrawingObjectRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = revisionAuthor;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PostDrawingObjectRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = revisionDateTime;
        }
        boost::optional<utility::string_t> PostDrawingObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void PostDrawingObjectRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = nodePath;
        }

}
}
}
}

