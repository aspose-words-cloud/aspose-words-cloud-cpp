/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateStyleRequest.cpp">
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
#include "UpdateStyleRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateStyleRequest::UpdateStyleRequest(
        utility::string_t name,
                std::shared_ptr<StyleUpdate> styleUpdate,
                utility::string_t styleName,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_styleUpdate(std::move(styleUpdate)),
            m_styleName(std::move(styleName)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateStyleRequest::getName() const
        {
            return m_name;
        }
        void UpdateStyleRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<StyleUpdate> UpdateStyleRequest::getStyleUpdate() const
        {
            return m_styleUpdate;
        }
        void UpdateStyleRequest::setStyleUpdate(std::shared_ptr<StyleUpdate> styleUpdate){
            m_styleUpdate = std::move(styleUpdate);
        }
        utility::string_t UpdateStyleRequest::getStyleName() const
        {
            return m_styleName;
        }
        void UpdateStyleRequest::setStyleName(utility::string_t styleName){
            m_styleName = std::move(styleName);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateStyleRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateStyleRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateStyleRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateStyleRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateStyleRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateStyleRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateStyleRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateStyleRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

