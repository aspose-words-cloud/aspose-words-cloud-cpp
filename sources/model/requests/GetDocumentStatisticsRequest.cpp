/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetDocumentStatisticsRequest.cpp">
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
#include "GetDocumentStatisticsRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
GetDocumentStatisticsRequest::GetDocumentStatisticsRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<bool> includeComments,
                boost::optional<bool> includeFootnotes,
                boost::optional<bool> includeTextInShapes
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_includeComments(std::move(includeComments)),
            m_includeFootnotes(std::move(includeFootnotes)),
            m_includeTextInShapes(std::move(includeTextInShapes))
        {
            
        }

        utility::string_t GetDocumentStatisticsRequest::getName() const
        {
            return m_name;
        }
        void GetDocumentStatisticsRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> GetDocumentStatisticsRequest::getFolder() const
        {
            return m_folder;
        }
        void GetDocumentStatisticsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetDocumentStatisticsRequest::getStorage() const
        {
            return m_storage;
        }
        void GetDocumentStatisticsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetDocumentStatisticsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetDocumentStatisticsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetDocumentStatisticsRequest::getPassword() const
        {
            return m_password;
        }
        void GetDocumentStatisticsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<bool> GetDocumentStatisticsRequest::getIncludeComments() const
        {
            return m_includeComments;
        }
        void GetDocumentStatisticsRequest::setIncludeComments(boost::optional<bool> includeComments){
            m_includeComments = std::move(includeComments);
        }
        boost::optional<bool> GetDocumentStatisticsRequest::getIncludeFootnotes() const
        {
            return m_includeFootnotes;
        }
        void GetDocumentStatisticsRequest::setIncludeFootnotes(boost::optional<bool> includeFootnotes){
            m_includeFootnotes = std::move(includeFootnotes);
        }
        boost::optional<bool> GetDocumentStatisticsRequest::getIncludeTextInShapes() const
        {
            return m_includeTextInShapes;
        }
        void GetDocumentStatisticsRequest::setIncludeTextInShapes(boost::optional<bool> includeTextInShapes){
            m_includeTextInShapes = std::move(includeTextInShapes);
        }

}
}
}
}

