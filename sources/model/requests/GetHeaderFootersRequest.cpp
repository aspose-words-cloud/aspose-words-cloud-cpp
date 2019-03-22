/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetHeaderFootersRequest.cpp">
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
#include "GetHeaderFootersRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetHeaderFootersRequest::GetHeaderFootersRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> sectionPath,
                boost::optional<utility::string_t> filterByType
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_sectionPath(std::move(sectionPath)),
            m_filterByType(std::move(filterByType))
        {
            
        }

        utility::string_t GetHeaderFootersRequest::getName() const
        {
            return m_name;
        }
        void GetHeaderFootersRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> GetHeaderFootersRequest::getFolder() const
        {
            return m_folder;
        }
        void GetHeaderFootersRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetHeaderFootersRequest::getStorage() const
        {
            return m_storage;
        }
        void GetHeaderFootersRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetHeaderFootersRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetHeaderFootersRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetHeaderFootersRequest::getPassword() const
        {
            return m_password;
        }
        void GetHeaderFootersRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> GetHeaderFootersRequest::getSectionPath() const
        {
            return m_sectionPath;
        }
        void GetHeaderFootersRequest::setSectionPath(boost::optional<utility::string_t> sectionPath){
            m_sectionPath = std::move(sectionPath);
        }
        boost::optional<utility::string_t> GetHeaderFootersRequest::getFilterByType() const
        {
            return m_filterByType;
        }
        void GetHeaderFootersRequest::setFilterByType(boost::optional<utility::string_t> filterByType){
            m_filterByType = std::move(filterByType);
        }

}
}
}
}
}

