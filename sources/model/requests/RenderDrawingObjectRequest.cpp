/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RenderDrawingObjectRequest.cpp">
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
#include "RenderDrawingObjectRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
RenderDrawingObjectRequest::RenderDrawingObjectRequest(
        utility::string_t name,
                utility::string_t format,
                int32_t index,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> nodePath,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(name),
            m_format(format),
            m_index(index),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_nodePath(nodePath),
            m_fontsLocation(fontsLocation)
        {
            
        }

        utility::string_t RenderDrawingObjectRequest::getName() const
        {
            return m_name;
        }
        void RenderDrawingObjectRequest::setName(utility::string_t name){
            m_name = name;
        }
        utility::string_t RenderDrawingObjectRequest::getFormat() const
        {
            return m_format;
        }
        void RenderDrawingObjectRequest::setFormat(utility::string_t format){
            m_format = format;
        }
        int32_t RenderDrawingObjectRequest::getIndex() const
        {
            return m_index;
        }
        void RenderDrawingObjectRequest::setIndex(int32_t index){
            m_index = index;
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getFolder() const
        {
            return m_folder;
        }
        void RenderDrawingObjectRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getStorage() const
        {
            return m_storage;
        }
        void RenderDrawingObjectRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void RenderDrawingObjectRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getPassword() const
        {
            return m_password;
        }
        void RenderDrawingObjectRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getNodePath() const
        {
            return m_nodePath;
        }
        void RenderDrawingObjectRequest::setNodePath(boost::optional<utility::string_t> nodePath){
            m_nodePath = nodePath;
        }
        boost::optional<utility::string_t> RenderDrawingObjectRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void RenderDrawingObjectRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = fontsLocation;
        }

}
}
}
}

