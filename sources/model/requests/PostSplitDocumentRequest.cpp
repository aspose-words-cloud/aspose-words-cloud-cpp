/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PostSplitDocumentRequest.cpp">
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
#include "PostSplitDocumentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
PostSplitDocumentRequest::PostSplitDocumentRequest(
        utility::string_t name,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<utility::string_t> format,
                boost::optional<int32_t> from,
                boost::optional<int32_t> to,
                boost::optional<bool> zipOutput,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_format(std::move(format)),
            m_from(std::move(from)),
            m_to(std::move(to)),
            m_zipOutput(std::move(zipOutput)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t PostSplitDocumentRequest::getName() const
        {
            return m_name;
        }
        void PostSplitDocumentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        boost::optional<utility::string_t> PostSplitDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void PostSplitDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PostSplitDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void PostSplitDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PostSplitDocumentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void PostSplitDocumentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> PostSplitDocumentRequest::getPassword() const
        {
            return m_password;
        }
        void PostSplitDocumentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> PostSplitDocumentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostSplitDocumentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<utility::string_t> PostSplitDocumentRequest::getFormat() const
        {
            return m_format;
        }
        void PostSplitDocumentRequest::setFormat(boost::optional<utility::string_t> format){
            m_format = std::move(format);
        }
        boost::optional<int32_t> PostSplitDocumentRequest::getFrom() const
        {
            return m_from;
        }
        void PostSplitDocumentRequest::setFrom(boost::optional<int32_t> from){
            m_from = std::move(from);
        }
        boost::optional<int32_t> PostSplitDocumentRequest::getTo() const
        {
            return m_to;
        }
        void PostSplitDocumentRequest::setTo(boost::optional<int32_t> to){
            m_to = std::move(to);
        }
        boost::optional<bool> PostSplitDocumentRequest::getZipOutput() const
        {
            return m_zipOutput;
        }
        void PostSplitDocumentRequest::setZipOutput(boost::optional<bool> zipOutput){
            m_zipOutput = std::move(zipOutput);
        }
        boost::optional<utility::string_t> PostSplitDocumentRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void PostSplitDocumentRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

