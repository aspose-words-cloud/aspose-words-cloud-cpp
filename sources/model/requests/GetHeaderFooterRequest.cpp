/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetHeaderFooterRequest.cpp">
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
#include "GetHeaderFooterRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
GetHeaderFooterRequest::GetHeaderFooterRequest(
        utility::string_t name,
                int32_t headerFooterIndex,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> filterByType
        ) : 
            m_name(std::move(name)),
            m_headerFooterIndex(std::move(headerFooterIndex)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_filterByType(std::move(filterByType))
        {
            
        }

        utility::string_t GetHeaderFooterRequest::getName() const
        {
            return m_name;
        }
        void GetHeaderFooterRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t GetHeaderFooterRequest::getHeaderFooterIndex() const
        {
            return m_headerFooterIndex;
        }
        void GetHeaderFooterRequest::setHeaderFooterIndex(int32_t headerFooterIndex){
            m_headerFooterIndex = std::move(headerFooterIndex);
        }
        boost::optional<utility::string_t> GetHeaderFooterRequest::getFolder() const
        {
            return m_folder;
        }
        void GetHeaderFooterRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetHeaderFooterRequest::getStorage() const
        {
            return m_storage;
        }
        void GetHeaderFooterRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetHeaderFooterRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetHeaderFooterRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetHeaderFooterRequest::getPassword() const
        {
            return m_password;
        }
        void GetHeaderFooterRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> GetHeaderFooterRequest::getFilterByType() const
        {
            return m_filterByType;
        }
        void GetHeaderFooterRequest::setFilterByType(boost::optional<utility::string_t> filterByType){
            m_filterByType = std::move(filterByType);
        }

}
}
}
}

