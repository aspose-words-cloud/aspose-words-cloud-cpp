/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RejectAllRevisionsOnlineResponse.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_RejectAllRevisionsOnlineResponse_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_RejectAllRevisionsOnlineResponse_H_

#include "RevisionsModificationResponse.h"
#include "HttpContent.h"
#include "cpprest/details/basic_types.h"
#include <boost/optional.hpp>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

class RejectAllRevisionsOnlineResponse {
    public: 
        RejectAllRevisionsOnlineResponse(
            std::shared_ptr<RevisionsModificationResponse> model,
            std::shared_ptr<HttpContent> document
        );

        std::shared_ptr<RevisionsModificationResponse> getModel() const;

        std::shared_ptr<HttpContent> getDocument() const;

    private:
        std::shared_ptr<RevisionsModificationResponse> m_Model;
        std::shared_ptr<HttpContent> m_Document;
};

}
}
}
}
}

#endif  /* ASPOSE_WORDS_CLOUD_API_MODELS_RejectAllRevisionsOnlineResponse_H_ */
