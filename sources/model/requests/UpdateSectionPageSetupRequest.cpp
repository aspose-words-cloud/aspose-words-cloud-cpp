/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateSectionPageSetupRequest.cpp">
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
#include "UpdateSectionPageSetupRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
UpdateSectionPageSetupRequest::UpdateSectionPageSetupRequest(
        utility::string_t name,
                int32_t sectionIndex,
                std::shared_ptr<PageSetup> pageSetup,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(name),
            m_sectionIndex(sectionIndex),
            m_pageSetup(pageSetup),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_destFileName(destFileName),
            m_revisionAuthor(revisionAuthor),
            m_revisionDateTime(revisionDateTime)
        {
            
        }

        utility::string_t UpdateSectionPageSetupRequest::getName() const
        {
            return m_name;
        }
        void UpdateSectionPageSetupRequest::setName(utility::string_t name){
            m_name = name;
        }
        int32_t UpdateSectionPageSetupRequest::getSectionIndex() const
        {
            return m_sectionIndex;
        }
        void UpdateSectionPageSetupRequest::setSectionIndex(int32_t sectionIndex){
            m_sectionIndex = sectionIndex;
        }
        std::shared_ptr<PageSetup> UpdateSectionPageSetupRequest::getPageSetup() const
        {
            return m_pageSetup;
        }
        void UpdateSectionPageSetupRequest::setPageSetup(std::shared_ptr<PageSetup> pageSetup){
            m_pageSetup = pageSetup;
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateSectionPageSetupRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateSectionPageSetupRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateSectionPageSetupRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateSectionPageSetupRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateSectionPageSetupRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateSectionPageSetupRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = revisionAuthor;
        }
        boost::optional<utility::string_t> UpdateSectionPageSetupRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateSectionPageSetupRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = revisionDateTime;
        }

}
}
}
}

