/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ConvertDocumentRequest.h">
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
#pragma once
#ifndef convertDocument_H
#define convertDocument_H 

#include "cpprest/details/basic_types.h"
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class ConvertDocumentRequest{
    public: 
     ConvertDocumentRequest(
        std::shared_ptr<HttpContent> document,
                utility::string_t format,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> outPath,
                boost::optional<utility::string_t> fileNameFieldValue,
                boost::optional<utility::string_t> fontsLocation
        );

        std::shared_ptr<HttpContent> getDocument() const;
        void setDocument(std::shared_ptr<HttpContent> document);

        utility::string_t getFormat() const;
        void setFormat(utility::string_t format);

        boost::optional<utility::string_t> getStorage() const;
        void setStorage(boost::optional<utility::string_t> storage);

        boost::optional<utility::string_t> getOutPath() const;
        void setOutPath(boost::optional<utility::string_t> outPath);

        boost::optional<utility::string_t> getFileNameFieldValue() const;
        void setFileNameFieldValue(boost::optional<utility::string_t> fileNameFieldValue);

        boost::optional<utility::string_t> getFontsLocation() const;
        void setFontsLocation(boost::optional<utility::string_t> fontsLocation);
    private:
        std::shared_ptr<HttpContent> m_document;
        utility::string_t m_format;
        boost::optional<utility::string_t> m_storage;
        boost::optional<utility::string_t> m_outPath;
        boost::optional<utility::string_t> m_fileNameFieldValue;
        boost::optional<utility::string_t> m_fontsLocation;
};

}
}
}
}
}

#endif
