/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApplyStyleToDocmentElementRequest.cpp">
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
#include "ApplyStyleToDocmentElementRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
ApplyStyleToDocmentElementRequest::ApplyStyleToDocmentElementRequest(
        utility::string_t name,
                std::shared_ptr<StyleApply> styleApply,
                utility::string_t styledNodePath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_styleApply(std::move(styleApply)),
            m_styledNodePath(std::move(styledNodePath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t ApplyStyleToDocmentElementRequest::getName() const
        {
            return m_name;
        }
        void ApplyStyleToDocmentElementRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<StyleApply> ApplyStyleToDocmentElementRequest::getStyleApply() const
        {
            return m_styleApply;
        }
        void ApplyStyleToDocmentElementRequest::setStyleApply(std::shared_ptr<StyleApply> styleApply){
            m_styleApply = std::move(styleApply);
        }
        utility::string_t ApplyStyleToDocmentElementRequest::getStyledNodePath() const
        {
            return m_styledNodePath;
        }
        void ApplyStyleToDocmentElementRequest::setStyledNodePath(utility::string_t styledNodePath){
            m_styledNodePath = std::move(styledNodePath);
        }
        boost::optional<utility::string_t> ApplyStyleToDocmentElementRequest::getFolder() const
        {
            return m_folder;
        }
        void ApplyStyleToDocmentElementRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> ApplyStyleToDocmentElementRequest::getStorage() const
        {
            return m_storage;
        }
        void ApplyStyleToDocmentElementRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> ApplyStyleToDocmentElementRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void ApplyStyleToDocmentElementRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> ApplyStyleToDocmentElementRequest::getPassword() const
        {
            return m_password;
        }
        void ApplyStyleToDocmentElementRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> ApplyStyleToDocmentElementRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void ApplyStyleToDocmentElementRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> ApplyStyleToDocmentElementRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void ApplyStyleToDocmentElementRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> ApplyStyleToDocmentElementRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void ApplyStyleToDocmentElementRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

