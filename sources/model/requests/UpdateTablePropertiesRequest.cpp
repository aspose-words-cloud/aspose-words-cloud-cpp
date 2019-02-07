/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTablePropertiesRequest.cpp">
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
#include "UpdateTablePropertiesRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
UpdateTablePropertiesRequest::UpdateTablePropertiesRequest(
        utility::string_t name,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<std::shared_ptr<TableProperties>> properties,
                boost::optional<utility::string_t> nodePath
        ) : 
            m_name(std::move(name)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_properties(std::move(properties)),
            m_nodePath(std::move(nodePath))
        {
            
        }

        utility::string_t UpdateTablePropertiesRequest::getName() const
        {
            return m_name;
        }
        void UpdateTablePropertiesRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t UpdateTablePropertiesRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateTablePropertiesRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateTablePropertiesRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateTablePropertiesRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateTablePropertiesRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateTablePropertiesRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateTablePropertiesRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateTablePropertiesRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateTablePropertiesRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<std::shared_ptr<TableProperties>> UpdateTablePropertiesRequest::getProperties() const
        {
            return m_properties;
        }
        void UpdateTablePropertiesRequest::setProperties(boost::optional<std::shared_ptr<TableProperties>> properties){
            m_properties = std::move(properties);
        }
        boost::optional<utility::string_t> UpdateTablePropertiesRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void UpdateTablePropertiesRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = std::move(nodePath);
        }

}
}
}
}

