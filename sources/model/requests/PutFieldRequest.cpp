/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutFieldRequest.cpp">
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
#include "PutFieldRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PutFieldRequest::PutFieldRequest(
        utility::string_t name,
                std::shared_ptr<Field> field,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<utility::string_t> nodePath,
                boost::optional<utility::string_t> insertBeforeNode
        ) : 
            m_name(std::move(name)),
            m_field(std::move(field)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime)),
            m_nodePath(std::move(nodePath)),
            m_insertBeforeNode(std::move(insertBeforeNode))
        {
            
        }

        utility::string_t PutFieldRequest::getName() const
        {
            return m_name;
        }
        void PutFieldRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<Field> PutFieldRequest::getField() const
        {
            return m_field;
        }
        void PutFieldRequest::setField(std::shared_ptr<Field> field){
            m_field = std::move(field);
        }
        boost::optional<utility::string_t> PutFieldRequest::getFolder() const
        {
            return m_folder;
        }
        void PutFieldRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PutFieldRequest::getStorage() const
        {
            return m_storage;
        }
        void PutFieldRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PutFieldRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PutFieldRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PutFieldRequest::getPassword() const
        {
            return m_password;
        }
        void PutFieldRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PutFieldRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PutFieldRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PutFieldRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PutFieldRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> PutFieldRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PutFieldRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> PutFieldRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void PutFieldRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> PutFieldRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void PutFieldRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}

