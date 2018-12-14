/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetSectionRequest.cpp">
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
#include "GetSectionRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
GetSectionRequest::GetSectionRequest(
        utility::string_t name,
                int32_t sectionIndex,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(name),
            m_sectionIndex(sectionIndex),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password)
        {
            
        }

        utility::string_t GetSectionRequest::getName() const
        {
            return m_name;
        }
        void GetSectionRequest::setName(utility::string_t name){
            m_name = name;
        }
        int32_t GetSectionRequest::getSectionIndex() const
        {
            return m_sectionIndex;
        }
        void GetSectionRequest::setSectionIndex(int32_t sectionIndex){
            m_sectionIndex = sectionIndex;
        }
        boost::optional<utility::string_t> GetSectionRequest::getFolder() const
        {
            return m_folder;
        }
        void GetSectionRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> GetSectionRequest::getStorage() const
        {
            return m_storage;
        }
        void GetSectionRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> GetSectionRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetSectionRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> GetSectionRequest::getPassword() const
        {
            return m_password;
        }
        void GetSectionRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }

}
}
}
}

