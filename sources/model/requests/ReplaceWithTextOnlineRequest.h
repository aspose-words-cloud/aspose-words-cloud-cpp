/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceWithTextOnlineRequest.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceWithTextOnlineRequest_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceWithTextOnlineRequest_H_

#include "ReplaceRange.h"
#include "HttpContent.h"
#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class ReplaceWithTextOnlineRequest {
    public: 
 ReplaceWithTextOnlineRequest(
            std::shared_ptr<HttpContent> document,
            utility::string_t rangeStartIdentifier,
            std::shared_ptr<ReplaceRange> rangeText,
            boost::optional< utility::string_t > rangeEndIdentifier,
            boost::optional< utility::string_t > loadEncoding,
            boost::optional< utility::string_t > password,
            boost::optional< utility::string_t > destFileName
        );

        std::shared_ptr<HttpContent> getDocument() const;
        void setDocument(std::shared_ptr<HttpContent> document);

        utility::string_t getRangeStartIdentifier() const;
        void setRangeStartIdentifier(utility::string_t rangeStartIdentifier);

        std::shared_ptr<ReplaceRange> getRangeText() const;
        void setRangeText(std::shared_ptr<ReplaceRange> rangeText);

        boost::optional< utility::string_t > getRangeEndIdentifier() const;
        void setRangeEndIdentifier(boost::optional< utility::string_t > rangeEndIdentifier);

        boost::optional< utility::string_t > getLoadEncoding() const;
        void setLoadEncoding(boost::optional< utility::string_t > loadEncoding);

        boost::optional< utility::string_t > getPassword() const;
        void setPassword(boost::optional< utility::string_t > password);

        boost::optional< utility::string_t > getDestFileName() const;
        void setDestFileName(boost::optional< utility::string_t > destFileName);

    private:
        std::shared_ptr<HttpContent> m_Document;
        utility::string_t m_RangeStartIdentifier;
        std::shared_ptr<ReplaceRange> m_RangeText;
        boost::optional< utility::string_t > m_RangeEndIdentifier;
        boost::optional< utility::string_t > m_LoadEncoding;
        boost::optional< utility::string_t > m_Password;
        boost::optional< utility::string_t > m_DestFileName;
};

}
}
}
}
}

#endif  /* ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceWithTextOnlineRequest_H_ */
