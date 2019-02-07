/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutCreateDocumentRequest.cpp">
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
#include "PutCreateDocumentRequest.h"
namespace io{
namespace swagger{
namespace client{
namespace model{
PutCreateDocumentRequest::PutCreateDocumentRequest(
        boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> fileName,
                boost::optional<utility::string_t> folder
        ) : 
            m_storage(std::move(storage)),
            m_fileName(std::move(fileName)),
            m_folder(std::move(folder))
        {
            
        }

        boost::optional<utility::string_t> PutCreateDocumentRequest::getStorage() const
        {
            return m_storage;
        }
        void PutCreateDocumentRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> PutCreateDocumentRequest::getFileName() const
        {
            return m_fileName;
        }
        void PutCreateDocumentRequest::setFileName(boost::optional<utility::string_t> fileName){
            m_fileName = std::move(fileName);
        }
        boost::optional<utility::string_t> PutCreateDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void PutCreateDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }

}
}
}
}

