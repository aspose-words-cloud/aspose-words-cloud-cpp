/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetHeaderFooterOfSectionRequest.cpp">
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
#include "GetHeaderFooterOfSectionRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
GetHeaderFooterOfSectionRequest::GetHeaderFooterOfSectionRequest(
        utility::string_t name,
                int32_t headerFooterIndex,
                int32_t sectionIndex,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> filterByType
        ) : 
            m_name(name),
            m_headerFooterIndex(headerFooterIndex),
            m_sectionIndex(sectionIndex),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_filterByType(filterByType)
        {
            
        }

        utility::string_t GetHeaderFooterOfSectionRequest::getName() const
        {
            return m_name;
        }
        void GetHeaderFooterOfSectionRequest::setName(utility::string_t name){
            m_name = name;
        }
        int32_t GetHeaderFooterOfSectionRequest::getHeaderFooterIndex() const
        {
            return m_headerFooterIndex;
        }
        void GetHeaderFooterOfSectionRequest::setHeaderFooterIndex(int32_t headerFooterIndex){
            m_headerFooterIndex = headerFooterIndex;
        }
        int32_t GetHeaderFooterOfSectionRequest::getSectionIndex() const
        {
            return m_sectionIndex;
        }
        void GetHeaderFooterOfSectionRequest::setSectionIndex(int32_t sectionIndex){
            m_sectionIndex = sectionIndex;
        }
        boost::optional<utility::string_t> GetHeaderFooterOfSectionRequest::getFolder() const
        {
            return m_folder;
        }
        void GetHeaderFooterOfSectionRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> GetHeaderFooterOfSectionRequest::getStorage() const
        {
            return m_storage;
        }
        void GetHeaderFooterOfSectionRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> GetHeaderFooterOfSectionRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetHeaderFooterOfSectionRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> GetHeaderFooterOfSectionRequest::getPassword() const
        {
            return m_password;
        }
        void GetHeaderFooterOfSectionRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> GetHeaderFooterOfSectionRequest::getFilterByType() const
        {
            return m_filterByType;
        }
        void GetHeaderFooterOfSectionRequest::setFilterByType(boost::optional<utility::string_t> filterByType){
            m_filterByType = filterByType;
        }

}
}
}
}

