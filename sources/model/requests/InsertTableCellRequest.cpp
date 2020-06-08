/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableCellRequest.cpp">
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
#include "InsertTableCellRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
InsertTableCellRequest::InsertTableCellRequest(
        utility::string_t name,
        std::shared_ptr<TableCellInsert> cell,
        utility::string_t tableRowPath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime
        ) : 
            m_name(std::move(name)),
            m_cell(std::move(cell)),
            m_tableRowPath(std::move(tableRowPath)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_revisionAuthor(std::move(revisionAuthor)),
            m_revisionDateTime(std::move(revisionDateTime))
        {
            
        }

        utility::string_t InsertTableCellRequest::getName() const
        {
            return m_name;
        }
        void InsertTableCellRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<TableCellInsert> InsertTableCellRequest::getCell() const
        {
            return m_cell;
        }
        void InsertTableCellRequest::setCell(std::shared_ptr<TableCellInsert> cell){
            m_cell = std::move(cell);
        }
        utility::string_t InsertTableCellRequest::getTableRowPath() const
        {
            return m_tableRowPath;
        }
        void InsertTableCellRequest::setTableRowPath(utility::string_t tableRowPath){
            m_tableRowPath = std::move(tableRowPath);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertTableCellRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertTableCellRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertTableCellRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getPassword() const
        {
            return m_password;
        }
        void InsertTableCellRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertTableCellRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertTableCellRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = std::move(revisionAuthor);
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertTableCellRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = std::move(revisionDateTime);
        }

}
}
}
}
}

