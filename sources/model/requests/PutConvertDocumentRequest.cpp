/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutConvertDocumentRequest.cpp">
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
#include "PutConvertDocumentRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PutConvertDocumentRequest::PutConvertDocumentRequest(
        std::shared_ptr<HttpContent> document,
                utility::string_t format,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> outPath,
                boost::optional<utility::string_t> documentFileName,
                boost::optional<utility::string_t> fontsLocation
        ) : 
            m_document(document),
            m_format(format),
            m_storage(storage),
            m_outPath(outPath),
            m_documentFileName(documentFileName),
            m_fontsLocation(fontsLocation)
        {
            
        }

        std::shared_ptr<HttpContent> PutConvertDocumentRequest::getDocument() const
        {
            return m_document;
        }
        void PutConvertDocumentRequest::setDocument(std::shared_ptr<HttpContent> document){
            m_document = document;
        }
        utility::string_t PutConvertDocumentRequest::getFormat() const
        {
            return m_format;
        }
        void PutConvertDocumentRequest::setFormat(utility::string_t format){
            m_format = format;
        }
        boost::optional<utility::string_t> PutConvertDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void PutConvertDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = storage;
        }
        boost::optional<utility::string_t> PutConvertDocumentRequest::getOutPath() const
        {
            return m_outPath;
        }
        void PutConvertDocumentRequest::setOutPath(boost::optional<utility::string_t> outPath){
            m_outPath = outPath;
        }
        boost::optional<utility::string_t> PutConvertDocumentRequest::getDocumentFileName() const
        {
            return m_documentFileName;
        }
        void PutConvertDocumentRequest::setDocumentFileName(boost::optional<utility::string_t> documentFileName){
            m_documentFileName = documentFileName;
        }
        boost::optional<utility::string_t> PutConvertDocumentRequest::getFontsLocation() const
        {
            return m_fontsLocation;
        }
        void PutConvertDocumentRequest::setFontsLocation(boost::optional<utility::string_t> fontsLocation){
            m_fontsLocation = fontsLocation;
        }

}
}
}
}

