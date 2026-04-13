/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="job_handler.h">
*   Copyright (c) 2026 Aspose.Words for Cloud
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
#include <any>
#include <chrono>
#include <memory>
#include <thread>
#include "aspose_words_cloud/api_client.h"
#include "aspose_words_cloud/api_exception.h"
#include "aspose_words_cloud/models/job_info.h"
#include "aspose_words_cloud/requests/request_model_base.h"

namespace aspose::words::cloud {
    template <typename T>
    class JobHandler
    {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT JobHandler(
            std::shared_ptr<ApiClient> apiClient,
            std::shared_ptr< aspose::words::cloud::requests::RequestModelBase > request,
            std::shared_ptr< aspose::words::cloud::models::JobInfo > info)
            : m_ApiClient(apiClient),
            m_Request(request),
            m_Info(info) {
        }

        ASPOSE_WORDS_CLOUD_EXPORT std::wstring getMessage() const
        {
            if (m_Info == nullptr || m_Info->getMessage() == nullptr) {
                return L"";
            }

            return *m_Info->getMessage();
        }

        ASPOSE_WORDS_CLOUD_EXPORT aspose::words::cloud::models::JobInfo::Status getStatus() const
        {
            if (m_Info == nullptr || m_Info->getStatus() == nullptr) {
                return aspose::words::cloud::models::JobInfo::Status::UNKNOWN;
            }

            return *m_Info->getStatus();
        }

        ASPOSE_WORDS_CLOUD_EXPORT T getResult() const
        {
            return m_Result;
        }

        ASPOSE_WORDS_CLOUD_EXPORT void update()
        {
            if (m_Info == nullptr || m_Info->getJobId() == nullptr || m_Info->getJobId()->empty()) {
                throw ApiException(400, L"Invalid job id.");
            }

            auto parts = m_ApiClient->callJobResult(*m_Info->getJobId());
            if (parts.size() >= 1) {
                m_Info = m_ApiClient->deserializeJobInfoPart(parts[0]);

                if (parts.size() >= 2 && getStatus() == aspose::words::cloud::models::JobInfo::Status::SUCCEDED) {
                    auto response = m_ApiClient->deserializeHttpResponsePart(m_Request, parts[1]);
                    m_Result = std::any_cast<T>(m_Request->getResponseResult(response));
                }
            }
        }

        ASPOSE_WORDS_CLOUD_EXPORT T waitResult(std::chrono::milliseconds updateInterval)
        {
            while (getStatus() == aspose::words::cloud::models::JobInfo::Status::QUEUED ||
                   getStatus() == aspose::words::cloud::models::JobInfo::Status::PROCESSING) {
                std::this_thread::sleep_for(updateInterval);
                update();
            }

            if (m_Result == nullptr && getStatus() == aspose::words::cloud::models::JobInfo::Status::SUCCEDED) {
                update();
            }

            if (getStatus() != aspose::words::cloud::models::JobInfo::Status::SUCCEDED) {
                throw ApiException(400, L"Job failed with status \"" + statusToString(getStatus()) + L"\" - \"" + getMessage() + L"\".");
            }

            return m_Result;
        }

    private:
        static std::wstring statusToString(aspose::words::cloud::models::JobInfo::Status status)
        {
            switch (status) {
            case aspose::words::cloud::models::JobInfo::Status::UNKNOWN:
                return L"Unknown";
            case aspose::words::cloud::models::JobInfo::Status::QUEUED:
                return L"Queued";
            case aspose::words::cloud::models::JobInfo::Status::PROCESSING:
                return L"Processing";
            case aspose::words::cloud::models::JobInfo::Status::SUCCEDED:
                return L"Succeded";
            case aspose::words::cloud::models::JobInfo::Status::FAILED:
                return L"Failed";
            default:
                return L"Unknown";
            }
        }

        std::shared_ptr<ApiClient> m_ApiClient;
        std::shared_ptr< aspose::words::cloud::requests::RequestModelBase > m_Request;
        std::shared_ptr< aspose::words::cloud::models::JobInfo > m_Info;
        T m_Result = nullptr;
    };
}