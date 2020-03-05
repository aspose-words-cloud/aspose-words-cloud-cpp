/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertPageNumbersRequest.cpp">
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
#include "InsertPageNumbersRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertPageNumbersRequest::InsertPageNumbersRequest(
        utility::string_t name,
                std::shared_ptr<PageNumber> pageNumber,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_pageNumber(std::move(pageNumber)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertPageNumbersRequest::getName() const
        {
            return m_name;
        }
        void InsertPageNumbersRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<PageNumber> InsertPageNumbersRequest::getPageNumber() const
        {
            return m_pageNumber;
        }
        void InsertPageNumbersRequest::setPageNumber(std::shared_ptr<PageNumber> pageNumber){
            m_pageNumber = std::move(pageNumber);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertPageNumbersRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertPageNumbersRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertPageNumbersRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getPassword() const
        {
            return m_password;
        }
        void InsertPageNumbersRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertPageNumbersRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertPageNumbersRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertPageNumbersRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertPageNumbersRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

