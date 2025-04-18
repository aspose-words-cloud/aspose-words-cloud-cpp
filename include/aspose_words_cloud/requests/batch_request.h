﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="batch_request.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
#include <string>
#include <memory>
#include <iostream>
#include "aspose_words_cloud/common.h"
#include "aspose_words_cloud/requests/request_model_base.h"

namespace aspose::words::cloud {
    class ApiClient;
}

namespace aspose::words::cloud::requests {
    class BatchRequest
    {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT BatchRequest(std::shared_ptr<RequestModelBase> request);
        ASPOSE_WORDS_CLOUD_EXPORT virtual ~BatchRequest() = default;
        ASPOSE_WORDS_CLOUD_EXPORT void dependsOn(const BatchRequest& other);
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr<std::istream> asResult() const;
        ASPOSE_WORDS_CLOUD_EXPORT void serialize(ApiClient* apiClient, std::string& body) const;
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr<RequestModelBase> get() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::string& getRequestId() const;

    private:
        std::shared_ptr<RequestModelBase> m_Request;
        std::string m_RequestId;
        std::string m_DependsOn;
    };
}