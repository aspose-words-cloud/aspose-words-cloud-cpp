/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetTableCellFormatRequest.cpp">
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
#include "GetTableCellFormatRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
GetTableCellFormatRequest::GetTableCellFormatRequest(
        utility::string_t name,
                utility::string_t tableRowPath,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_tableRowPath(std::move(tableRowPath)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetTableCellFormatRequest::getName() const
        {
            return m_name;
        }
        void GetTableCellFormatRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetTableCellFormatRequest::getTableRowPath() const
        {
            return m_tableRowPath;
        }
        void GetTableCellFormatRequest::setTableRowPath(utility::string_t tableRowPath){
            m_tableRowPath = std::move(tableRowPath);
        }
        int32_t GetTableCellFormatRequest::getIndex() const
        {
            return m_index;
        }
        void GetTableCellFormatRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getFolder() const
        {
            return m_folder;
        }
        void GetTableCellFormatRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getStorage() const
        {
            return m_storage;
        }
        void GetTableCellFormatRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetTableCellFormatRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetTableCellFormatRequest::getPassword() const
        {
            return m_password;
        }
        void GetTableCellFormatRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}

