/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DeleteBorderRequest.cpp">
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
#include "DeleteBorderRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
DeleteBorderRequest::DeleteBorderRequest(
        utility::string_t name,
                utility::string_t nodePath,
                utility::string_t borderType,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_nodePath(std::move(nodePath)),
            m_borderType(std::move(borderType)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t DeleteBorderRequest::getName() const
        {
            return m_name;
        }
        void DeleteBorderRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t DeleteBorderRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void DeleteBorderRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        utility::string_t DeleteBorderRequest::getBorderType() const
        {
            return m_borderType;
        }
        void DeleteBorderRequest::setBorderType(utility::string_t borderType){
            m_borderType = std::move(borderType);
        }
        boost::optional<utility::string_t> DeleteBorderRequest::getFolder() const
        {
            return m_folder;
        }
        void DeleteBorderRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> DeleteBorderRequest::getStorage() const
        {
            return m_storage;
        }
        void DeleteBorderRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> DeleteBorderRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void DeleteBorderRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> DeleteBorderRequest::getPassword() const
        {
            return m_password;
        }
        void DeleteBorderRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> DeleteBorderRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void DeleteBorderRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> DeleteBorderRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void DeleteBorderRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> DeleteBorderRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void DeleteBorderRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

