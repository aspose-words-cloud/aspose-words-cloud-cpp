/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetDocumentDrawingObjectByIndexRequest.cpp">
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
#include "GetDocumentDrawingObjectByIndexRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetDocumentDrawingObjectByIndexRequest::GetDocumentDrawingObjectByIndexRequest(
        utility::string_t name,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> nodePath
        ) : 
            m_name(std::move(name)),
            m_index(std::move(index)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_nodePath(std::move(nodePath))
        {
            
        }

        utility::string_t GetDocumentDrawingObjectByIndexRequest::getName() const
        {
            return m_name;
        }
        void GetDocumentDrawingObjectByIndexRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        int32_t GetDocumentDrawingObjectByIndexRequest::getIndex() const
        {
            return m_index;
        }
        void GetDocumentDrawingObjectByIndexRequest::setIndex(int32_t index){
            m_index = std::move(index);
        }
        boost::optional<utility::string_t> GetDocumentDrawingObjectByIndexRequest::getFolder() const
        {
            return m_folder;
        }
        void GetDocumentDrawingObjectByIndexRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetDocumentDrawingObjectByIndexRequest::getStorage() const
        {
            return m_storage;
        }
        void GetDocumentDrawingObjectByIndexRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetDocumentDrawingObjectByIndexRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetDocumentDrawingObjectByIndexRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetDocumentDrawingObjectByIndexRequest::getPassword() const
        {
            return m_password;
        }
        void GetDocumentDrawingObjectByIndexRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> GetDocumentDrawingObjectByIndexRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void GetDocumentDrawingObjectByIndexRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = std::move(nodePath);
        }

}
}
}
}
}

