/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertTableCellRequest.cpp">
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
#include "InsertTableCellRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
InsertTableCellRequest::InsertTableCellRequest(
        utility::string_t name,
                utility::string_t tableRowPath,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> revisionAuthor,
                boost::optional<utility::string_t> revisionDateTime,
                boost::optional<std::shared_ptr<TableCellInsert>> cell
        ) : 
            m_name(name),
            m_tableRowPath(tableRowPath),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_destFileName(destFileName),
            m_revisionAuthor(revisionAuthor),
            m_revisionDateTime(revisionDateTime),
            m_cell(cell)
        {
            
        }

        utility::string_t InsertTableCellRequest::getName() const
        {
            return m_name;
        }
        void InsertTableCellRequest::setName(utility::string_t name){
            m_name = name;
        }
        utility::string_t InsertTableCellRequest::getTableRowPath() const
        {
            return m_tableRowPath;
        }
        void InsertTableCellRequest::setTableRowPath(utility::string_t tableRowPath){
            m_tableRowPath = tableRowPath;
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getFolder() const
        {
            return m_folder;
        }
        void InsertTableCellRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getStorage() const
        {
            return m_storage;
        }
        void InsertTableCellRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void InsertTableCellRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getPassword() const
        {
            return m_password;
        }
        void InsertTableCellRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void InsertTableCellRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getRevisionAuthor() const
        {
            return m_revisionAuthor;
        }
        void InsertTableCellRequest::setRevisionAuthor(boost::optional<utility::string_t> revisionAuthor){
            m_revisionAuthor = revisionAuthor;
        }
        boost::optional<utility::string_t> InsertTableCellRequest::getRevisionDateTime() const
        {
            return m_revisionDateTime;
        }
        void InsertTableCellRequest::setRevisionDateTime(boost::optional<utility::string_t> revisionDateTime){
            m_revisionDateTime = revisionDateTime;
        }
        boost::optional<std::shared_ptr<TableCellInsert>> InsertTableCellRequest::getCell() const
        {
            return m_cell;
        }
        void InsertTableCellRequest::setCell(boost::optional<std::shared_ptr<TableCellInsert>> cell){
            m_cell = cell;
        }

}
}
}
}

