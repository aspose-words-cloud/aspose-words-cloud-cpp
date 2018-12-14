/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutFormFieldRequest.cpp">
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
#include "PutFormFieldRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PutFormFieldRequest::PutFormFieldRequest(
        utility::string_t name,
                std::shared_ptr<FormField> formField,
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
            m_name(name),
            m_formField(formField),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_destFileName(destFileName),
            m_revisionAuthor(revisionAuthor),
            m_revisionDateTime(revisionDateTime),
            m_nodePath(nodePath),
            m_insertBeforeNode(insertBeforeNode)
        {
            
        }

        utility::string_t PutFormFieldRequest::getName() const
        {
            return m_name;
        }
        void PutFormFieldRequest::setName(utility::string_t name){
            m_name = name;
        }
        std::shared_ptr<FormField> PutFormFieldRequest::getFormField() const
        {
            return m_formField;
        }
        void PutFormFieldRequest::setFormField(std::shared_ptr<FormField> formField){
            m_formField = formField;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getFolder() const
        {
            return m_folder;
        }
        void PutFormFieldRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getStorage() const
        {
            return m_storage;
        }
        void PutFormFieldRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PutFormFieldRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getPassword() const
        {
            return m_password;
        }
        void PutFormFieldRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PutFormFieldRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PutFormFieldRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = revisionAuthor;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PutFormFieldRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = revisionDateTime;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void PutFormFieldRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = nodePath;
        }
        boost::optional<utility::string_t> PutFormFieldRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void PutFormFieldRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = insertBeforeNode;
        }

}
}
}
}

