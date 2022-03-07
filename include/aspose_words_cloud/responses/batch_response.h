/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="batch_response.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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
#include <vector>
#include <memory>
#include <unordered_map>
#include <string_view>
#include "aspose_words_cloud/common.h"
#include "aspose_words_cloud/requests/batch_request.h"
#include "aspose_words_cloud/requests/request_model_base.h"
#include "aspose_words_cloud/responses/response_model_base.h"

namespace aspose::words::cloud::responses {
    class BatchResponse : public ResponseModelBase {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT virtual ~BatchResponse() = default;

        ASPOSE_WORDS_CLOUD_EXPORT void initialize(const std::vector<aspose::words::cloud::requests::BatchRequest>& requests);
        ASPOSE_WORDS_CLOUD_EXPORT virtual void deserialize(const std::string& contentType, const std::string_view& response) override;

        const std::shared_ptr< ResponseModelBase > getResult(size_t index) const {
            if (!m_Result || m_Result->size() <= index) return nullptr;
            return m_Result->at(index);
        }

        template<class ResultType>
        const ResultType* getResult(size_t index) const {
            return dynamic_cast<ResultType*>(getResult(index).get());
        }

        ASPOSE_WORDS_CLOUD_EXPORT size_t getCount() const;

    private:
        std::shared_ptr< std::unordered_map< std::string, std::shared_ptr<aspose::words::cloud::requests::RequestModelBase> > > m_Order;
        std::shared_ptr< std::vector< std::shared_ptr< ResponseModelBase > > > m_Result;
    };
}