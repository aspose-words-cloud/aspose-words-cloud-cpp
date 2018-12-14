/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DeleteDocumentWatermarkRequest.cpp">
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
#include "DeleteDocumentWatermarkRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
DeleteDocumentWatermarkRequest::DeleteDocumentWatermarkRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(name),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_destFileName(destFileName),
            m_revisionAuthor(revisionAuthor),
            m_revisionDateTime(revisionDateTime)
        {
            
        }

        utility::string_t DeleteDocumentWatermarkRequest::getName() const
        {
            return m_name;
        }
        void DeleteDocumentWatermarkRequest::setName(utility::string_t name){
            m_name = name;
        }
        boost::optional<utility::string_t> DeleteDocumentWatermarkRequest::getFolder() const
        {
            return m_folder;
        }
        void DeleteDocumentWatermarkRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> DeleteDocumentWatermarkRequest::getStorage() const
        {
            return m_storage;
        }
        void DeleteDocumentWatermarkRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> DeleteDocumentWatermarkRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void DeleteDocumentWatermarkRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> DeleteDocumentWatermarkRequest::getPassword() const
        {
            return m_password;
        }
        void DeleteDocumentWatermarkRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> DeleteDocumentWatermarkRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void DeleteDocumentWatermarkRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> DeleteDocumentWatermarkRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void DeleteDocumentWatermarkRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = revisionAuthor;
        }
        boost::optional<utility::string_t> DeleteDocumentWatermarkRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void DeleteDocumentWatermarkRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = revisionDateTime;
        }

}
}
}
}

