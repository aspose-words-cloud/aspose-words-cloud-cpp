/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutParagraphRequest.cpp">
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
#include "PutParagraphRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
PutParagraphRequest::PutParagraphRequest(
        utility::string_t name,
                std::shared_ptr<ParagraphInsert> paragraph,
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
            m_paragraph(std::move(paragraph)),
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

        utility::string_t PutParagraphRequest::getName() const
        {
            return m_name;
        }
        void PutParagraphRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ParagraphInsert> PutParagraphRequest::getParagraph() const
        {
            return m_paragraph;
        }
        void PutParagraphRequest::setParagraph(std::shared_ptr<ParagraphInsert> paragraph){
            m_paragraph = std::move(paragraph);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getFolder() const
        {
            return m_folder;
        }
        void PutParagraphRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getStorage() const
        {
            return m_storage;
        }
        void PutParagraphRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PutParagraphRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getPassword() const
        {
            return m_password;
        }
        void PutParagraphRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PutParagraphRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PutParagraphRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PutParagraphRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void PutParagraphRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = std::move(nodePath);
        }
        boost::optional<utility::string_t> PutParagraphRequest::getInsertBeforeNode() const
        {
            return m_insertBeforeNode;
        }
        void PutParagraphRequest::setInsertBeforeNode(boost::optional<utility::string_t> insertBeforeNode){
            m_insertBeforeNode = std::move(insertBeforeNode);
        }

}
}
}
}
}

