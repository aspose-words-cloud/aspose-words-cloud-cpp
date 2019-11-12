/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveAsRangeRequest.h">
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
#ifndef saveAsRange_H
#define saveAsRange_H 

#include "cpprest/details/basic_types.h"
#include "RangeDocument.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class SaveAsRangeRequest{
    public: 
     SaveAsRangeRequest(
        utility::string_t name,
                utility::string_t rangeStartIdentifier,
                std::shared_ptr<RangeDocument> documentParameters,
                utility::string_t rangeEndIdentifier,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password
        );

        utility::string_t getName() const;
        void setName(utility::string_t name);

        utility::string_t getRangeStartIdentifier() const;
        void setRangeStartIdentifier(utility::string_t rangeStartIdentifier);

        std::shared_ptr<RangeDocument> getDocumentParameters() const;
        void setDocumentParameters(std::shared_ptr<RangeDocument> documentParameters);

        utility::string_t getRangeEndIdentifier() const;
        void setRangeEndIdentifier(utility::string_t rangeEndIdentifier);

        boost::optional<utility::string_t> getFolder() const;
        void setFolder(boost::optional<utility::string_t> folder);

        boost::optional<utility::string_t> getStorage() const;
        void setStorage(boost::optional<utility::string_t> storage);

        boost::optional<utility::string_t> getLoadEncoding() const;
        void setLoadEncoding(boost::optional<utility::string_t> loadEncoding);

        boost::optional<utility::string_t> getPassword() const;
        void setPassword(boost::optional<utility::string_t> password);
    private:
        utility::string_t m_name;
        utility::string_t m_rangeStartIdentifier;
        std::shared_ptr<RangeDocument> m_documentParameters;
        utility::string_t m_rangeEndIdentifier;
        boost::optional<utility::string_t> m_folder;
        boost::optional<utility::string_t> m_storage;
        boost::optional<utility::string_t> m_loadEncoding;
        boost::optional<utility::string_t> m_password;
};

}
}
}
}
}

#endif
