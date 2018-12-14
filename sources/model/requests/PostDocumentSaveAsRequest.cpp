/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostDocumentSaveAsRequest.cpp">
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
#include "PostDocumentSaveAsRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PostDocumentSaveAsRequest::PostDocumentSaveAsRequest(
        utility::string_t name,
                std::shared_ptr<SaveOptionsData> saveOptionsData,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(name),
            m_saveOptionsData(saveOptionsData),
            m_folder(folder),
            m_storage(storage),
            m_loadEncoding(loadEncoding),
            m_password(password),
            m_destFileName(destFileName),
            m_fontsLocation(fontsLocation)
        {
            
        }

        utility::string_t PostDocumentSaveAsRequest::getName() const
        {
            return m_name;
        }
        void PostDocumentSaveAsRequest::setName(utility::string_t name){
            m_name = name;
        }
        std::shared_ptr<SaveOptionsData> PostDocumentSaveAsRequest::getSaveOptionsData() const
        {
            return m_saveOptionsData;
        }
        void PostDocumentSaveAsRequest::setSaveOptionsData(std::shared_ptr<SaveOptionsData> saveOptionsData){
            m_saveOptionsData = saveOptionsData;
        }
        boost::optional<utility::string_t> PostDocumentSaveAsRequest::getFolder() const
        {
            return m_folder;
        }
        void PostDocumentSaveAsRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = folder;
        }
        boost::optional<utility::string_t> PostDocumentSaveAsRequest::getStorage() const
        {
            return m_storage;
        }
        void PostDocumentSaveAsRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> PostDocumentSaveAsRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostDocumentSaveAsRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = loadEncoding;
        }
        boost::optional<utility::string_t> PostDocumentSaveAsRequest::getPassword() const
        {
            return m_password;
        }
        void PostDocumentSaveAsRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = password;
        }
        boost::optional<utility::string_t> PostDocumentSaveAsRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostDocumentSaveAsRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = destFileName;
        }
        boost::optional<utility::string_t> PostDocumentSaveAsRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void PostDocumentSaveAsRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = fontsLocation;
        }

}
}
}
}

