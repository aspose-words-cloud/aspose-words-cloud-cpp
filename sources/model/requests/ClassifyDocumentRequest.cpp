/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ClassifyDocumentRequest.cpp">
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
#include "ClassifyDocumentRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
ClassifyDocumentRequest::ClassifyDocumentRequest(
        utility::string_t documentName,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> bestClassesCount,
                boost::optional<utility::string_t> taxonomy
        ) : 
            m_documentName(std::move(documentName)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_bestClassesCount(std::move(bestClassesCount)),
            m_taxonomy(std::move(taxonomy))
        {
            
        }

        utility::string_t ClassifyDocumentRequest::getDocumentName() const
        {
            return m_documentName;
        }
        void ClassifyDocumentRequest::setDocumentName(utility::string_t documentName){
            m_documentName = std::move(documentName);
        }
        boost::optional<utility::string_t> ClassifyDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void ClassifyDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> ClassifyDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void ClassifyDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> ClassifyDocumentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void ClassifyDocumentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> ClassifyDocumentRequest::getPassword() const
        {
            return m_password;
        }
        void ClassifyDocumentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> ClassifyDocumentRequest::getBestClassesCount() const
        {
            return m_bestClassesCount;
        }
        void ClassifyDocumentRequest::setBestClassesCount(boost::optional<utility::string_t> bestClassesCount){
            m_bestClassesCount = std::move(bestClassesCount);
        }
        boost::optional<utility::string_t> ClassifyDocumentRequest::getTaxonomy() const
        {
            return m_taxonomy;
        }
        void ClassifyDocumentRequest::setTaxonomy(boost::optional<utility::string_t> taxonomy){
            m_taxonomy = std::move(taxonomy);
        }

}
}
}
}

