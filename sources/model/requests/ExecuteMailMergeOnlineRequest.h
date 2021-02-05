/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ExecuteMailMergeOnlineRequest.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ExecuteMailMergeOnlineRequest_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ExecuteMailMergeOnlineRequest_H_

#include "HttpContent.h"
#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class ExecuteMailMergeOnlineRequest {
    public: 
 ExecuteMailMergeOnlineRequest(
            std::shared_ptr<HttpContent> _template,
            std::shared_ptr<HttpContent> data,
            boost::optional< bool > withRegions,
            boost::optional< utility::string_t > cleanup,
            boost::optional< utility::string_t > documentFileName
        );

        std::shared_ptr<HttpContent> getTemplate() const;
        void setTemplate(std::shared_ptr<HttpContent> _template);

        std::shared_ptr<HttpContent> getData() const;
        void setData(std::shared_ptr<HttpContent> data);

        boost::optional< bool > getWithRegions() const;
        void setWithRegions(boost::optional< bool > withRegions);

        boost::optional< utility::string_t > getCleanup() const;
        void setCleanup(boost::optional< utility::string_t > cleanup);

        boost::optional< utility::string_t > getDocumentFileName() const;
        void setDocumentFileName(boost::optional< utility::string_t > documentFileName);

    private:
        std::shared_ptr<HttpContent> m_Template;
        std::shared_ptr<HttpContent> m_Data;
        boost::optional< bool > m_WithRegions;
        boost::optional< utility::string_t > m_Cleanup;
        boost::optional< utility::string_t > m_DocumentFileName;
};

}
}
}
}
}

#endif  /* ASPOSE_WORDS_CLOUD_API_MODELS_ExecuteMailMergeOnlineRequest_H_ */
