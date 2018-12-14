/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutExecuteMailMergeOnlineRequest.h">
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
#include "cpprest/details/basic_types.h"
#undef U
#include "HttpContent.h"
#include <boost/optional.hpp>

namespace io {
namespace swagger {
namespace client {
namespace model {

class PutExecuteMailMergeOnlineRequest{
    public: 
     PutExecuteMailMergeOnlineRequest(
        std::shared_ptr<HttpContent> _template,
                std::shared_ptr<HttpContent> data,
                boost::optional<bool> withRegions,
                boost::optional<utility::string_t> cleanup,
                boost::optional<utility::string_t> documentFileName
        );

        std::shared_ptr<HttpContent> getTemplate() const;
        void setTemplate(std::shared_ptr<HttpContent> _template);

        std::shared_ptr<HttpContent> getData() const;
        void setData(std::shared_ptr<HttpContent> data);

        boost::optional<bool> getWithRegions() const;
        void setWithRegions(boost::optional<bool> withRegions);

        boost::optional<utility::string_t> getCleanup() const;
        void setCleanup(boost::optional<utility::string_t> cleanup);

        boost::optional<utility::string_t> getDocumentFileName() const;
        void setDocumentFileName(boost::optional<utility::string_t> documentFileName);
    private:
        std::shared_ptr<HttpContent> m__template;
        std::shared_ptr<HttpContent> m_data;
        boost::optional<bool> m_withRegions;
        boost::optional<utility::string_t> m_cleanup;
        boost::optional<utility::string_t> m_documentFileName;
};

}
}
}
}
