/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutFootnoteRequest.cpp">
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
#include "PutFootnoteRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PutFootnoteRequest::PutFootnoteRequest(
        utility::string_t name,
                std::shared_ptr<Footnote> footnoteDto,
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
            m_footnoteDto(footnoteDto),
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

        utility::string_t PutFootnoteRequest::getName() const
        {
            return m_name;
        }
        void PutFootnoteRequest::setName(utility::string_t name){
            m_name = name;
        }
        std::shared_ptr<Footnote> PutFootnoteRequest::getFootnoteDto() const
        {
            return m_footnoteDto;
        }
        void PutFootnoteRequest::setFootnoteDto(std::shared_ptr<Footnote> footnoteDto){
            m_footnoteDto = footnoteDto;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getFolder() const
        {
            return m_folder;
        }
        void PutFootnoteRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getStorage() const
        {
            return m_storage;
        }
        void PutFootnoteRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PutFootnoteRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getPassword() const
        {
            return m_password;
        }
        void PutFootnoteRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PutFootnoteRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PutFootnoteRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = revisionAuthor;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PutFootnoteRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = revisionDateTime;
        }
        boost::optional<utility::string_t> PutFootnoteRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void PutFootnoteRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = nodePath;
        }

}
}
}
}

