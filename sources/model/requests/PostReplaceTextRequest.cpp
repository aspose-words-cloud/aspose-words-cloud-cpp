/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostReplaceTextRequest.cpp">
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
#include "PostReplaceTextRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
PostReplaceTextRequest::PostReplaceTextRequest(
        utility::string_t name,
                std::shared_ptr<ReplaceTextRequest> replaceText,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_replaceText(std::move(replaceText)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t PostReplaceTextRequest::getName() const
        {
            return m_name;
        }
        void PostReplaceTextRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ReplaceTextRequest> PostReplaceTextRequest::getReplaceText() const
        {
            return m_replaceText;
        }
        void PostReplaceTextRequest::setReplaceText(std::shared_ptr<ReplaceTextRequest> replaceText){
            m_replaceText = std::move(replaceText);
        }
        boost::optional<utility::string_t> PostReplaceTextRequest::getFolder() const
        {
            return m_folder;
        }
        void PostReplaceTextRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PostReplaceTextRequest::getStorage() const
        {
            return m_storage;
        }
        void PostReplaceTextRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PostReplaceTextRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostReplaceTextRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PostReplaceTextRequest::getPassword() const
        {
            return m_password;
        }
        void PostReplaceTextRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PostReplaceTextRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostReplaceTextRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PostReplaceTextRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void PostReplaceTextRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> PostReplaceTextRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void PostReplaceTextRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

