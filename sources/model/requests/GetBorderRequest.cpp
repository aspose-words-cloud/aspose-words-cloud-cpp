/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetBorderRequest.cpp">
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
#include "GetBorderRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetBorderRequest::GetBorderRequest(
        utility::string_t name,
                utility::string_t nodePath,
                utility::string_t borderType,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        ) : 
            m_name(std::move(name)),
            m_nodePath(std::move(nodePath)),
            m_borderType(std::move(borderType)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password))
        {
            
        }

        utility::string_t GetBorderRequest::getName() const
        {
            return m_name;
        }
        void GetBorderRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t GetBorderRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void GetBorderRequest::setNodePath(utility::string_t nodePath){
            m_nodePath = std::move(nodePath);
        }
        utility::string_t GetBorderRequest::getBorderType() const
        {
            return m_borderType;
        }
        void GetBorderRequest::setBorderType(utility::string_t borderType){
            m_borderType = std::move(borderType);
        }
        boost::optional<utility::string_t> GetBorderRequest::getFolder() const
        {
            return m_folder;
        }
        void GetBorderRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> GetBorderRequest::getStorage() const
        {
            return m_storage;
        }
        void GetBorderRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> GetBorderRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void GetBorderRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> GetBorderRequest::getPassword() const
        {
            return m_password;
        }
        void GetBorderRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }

}
}
}
}
}

