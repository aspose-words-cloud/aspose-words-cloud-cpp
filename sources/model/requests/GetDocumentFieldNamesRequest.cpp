/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetDocumentFieldNamesRequest.cpp">
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
#include "GetDocumentFieldNamesRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetDocumentFieldNamesRequest::GetDocumentFieldNamesRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<bool> useNonMergeFields
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_useNonMergeFields(std::move(useNonMergeFields))
        {
            
        }

        utility::string_t GetDocumentFieldNamesRequest::getName() const
        {
            return m_name;
        }
        void GetDocumentFieldNamesRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> GetDocumentFieldNamesRequest::getFolder() const
        {
            return m_folder;
        }
        void GetDocumentFieldNamesRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetDocumentFieldNamesRequest::getStorage() const
        {
            return m_storage;
        }
        void GetDocumentFieldNamesRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetDocumentFieldNamesRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetDocumentFieldNamesRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetDocumentFieldNamesRequest::getPassword() const
        {
            return m_password;
        }
        void GetDocumentFieldNamesRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<bool> GetDocumentFieldNamesRequest::getUseNonMergeFields() const
        {
            return m_useNonMergeFields;
        }
        void GetDocumentFieldNamesRequest::setUseNonMergeFields(boost::optional<bool> useNonMergeFields){
            m_useNonMergeFields = std::move(useNonMergeFields);
        }

}
}
}
}
}

