/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SplitDocumentRequest.cpp">
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
#include "SplitDocumentRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
SplitDocumentRequest::SplitDocumentRequest(
        utility::string_t name,
                utility::string_t format,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName,
                boost::optional<int32_t> from,
                boost::optional<int32_t> to,
                boost::optional<bool> zipOutput,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_name(std::move(name)),
            m_format(std::move(format)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName)),
            m_from(std::move(from)),
            m_to(std::move(to)),
            m_zipOutput(std::move(zipOutput)),
            m_fontsLocation(std::move(fontsLocation))
        {
            
        }

        utility::string_t SplitDocumentRequest::getName() const
        {
            return m_name;
        }
        void SplitDocumentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t SplitDocumentRequest::getFormat() const
        {
            return m_format;
        }
        void SplitDocumentRequest::setFormat(utility::string_t format){
            m_format = std::move(format);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void SplitDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void SplitDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void SplitDocumentRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getPassword() const
        {
            return m_password;
        }
        void SplitDocumentRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void SplitDocumentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }
        boost::optional<int32_t> SplitDocumentRequest::getFrom() const
        {
            return m_from;
        }
        void SplitDocumentRequest::setFrom(boost::optional<int32_t> from){
            m_from = std::move(from);
        }
        boost::optional<int32_t> SplitDocumentRequest::getTo() const
        {
            return m_to;
        }
        void SplitDocumentRequest::setTo(boost::optional<int32_t> to){
            m_to = std::move(to);
        }
        boost::optional<bool> SplitDocumentRequest::getZipOutput() const
        {
            return m_zipOutput;
        }
        void SplitDocumentRequest::setZipOutput(boost::optional<bool> zipOutput){
            m_zipOutput = std::move(zipOutput);
        }
        boost::optional<utility::string_t> SplitDocumentRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void SplitDocumentRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = std::move(fontsLocation);
        }

}
}
}
}
}

