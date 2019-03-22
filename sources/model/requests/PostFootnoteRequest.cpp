/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostFootnoteRequest.cpp">
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
#include "PostFootnoteRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
PostFootnoteRequest::PostFootnoteRequest(
        utility::string_t name,
                std::shared_ptr<Footnote> footnoteDto,
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
            m_footnoteDto(std::move(footnoteDto)),
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

        utility::string_t PostFootnoteRequest::getName() const
        {
            return m_name;
        }
        void PostFootnoteRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<Footnote> PostFootnoteRequest::getFootnoteDto() const
        {
            return m_footnoteDto;
        }
        void PostFootnoteRequest::setFootnoteDto(std::shared_ptr<Footnote> footnoteDto){
            m_footnoteDto = std::move(footnoteDto);
        }
        int32_t PostFootnoteRequest::getIndex() const
        {
            return m_index;
        }
        void PostFootnoteRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getFolder() const
        {
            return m_folder;
        }
        void PostFootnoteRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getStorage() const
        {
            return m_storage;
        }
        void PostFootnoteRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostFootnoteRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getPassword() const
        {
            return m_password;
        }
        void PostFootnoteRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostFootnoteRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PostFootnoteRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PostFootnoteRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }
        boost::optional<utility::string_t> PostFootnoteRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void PostFootnoteRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = std::move(nodePath);
        }

}
}
}
}
}

