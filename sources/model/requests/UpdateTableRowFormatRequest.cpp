/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateTableRowFormatRequest.cpp">
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
#include "UpdateTableRowFormatRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
UpdateTableRowFormatRequest::UpdateTableRowFormatRequest(
        utility::string_t name,
                std::shared_ptr<TableRowFormat> format,
                utility::string_t tablePath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_tablePath(std::move(tablePath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t UpdateTableRowFormatRequest::getName() const
        {
            return m_name;
        }
        void UpdateTableRowFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableRowFormat> UpdateTableRowFormatRequest::getFormat() const
        {
            return m_format;
        }
        void UpdateTableRowFormatRequest::setFormat(std::shared_ptr<TableRowFormat> format){
            m_format = std::move(format);
        }
        utility::string_t UpdateTableRowFormatRequest::getTablePath() const
        {
            return m_tablePath;
        }
        void UpdateTableRowFormatRequest::setTablePath(utility::string_t tablePath){
            m_tablePath = std::move(tablePath);
        }
        int32_t UpdateTableRowFormatRequest::getIndex() const
        {
            return m_index;
        }
        void UpdateTableRowFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void UpdateTableRowFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void UpdateTableRowFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void UpdateTableRowFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getPassword() const
        {
            return m_password;
        }
        void UpdateTableRowFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void UpdateTableRowFormatRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void UpdateTableRowFormatRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> UpdateTableRowFormatRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void UpdateTableRowFormatRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

