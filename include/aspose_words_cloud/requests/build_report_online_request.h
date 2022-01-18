/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="build_report_online_request.h">
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
#include "./request_model_base.h"
#include "aspose_words_cloud/models/report_engine_settings.h"

namespace aspose::words::cloud::requests {
    class BuildReportOnlineRequest : public RequestModelBase {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT BuildReportOnlineRequest(
            const std::shared_ptr< std::istream > _template,
            const std::shared_ptr< std::wstring > data,
            const std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings > reportEngineSettings,
            const std::shared_ptr< std::wstring > documentFileName = nullptr
        );

        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::istream > getTemplate() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getData() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings > getReportEngineSettings() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getDocumentFileName() const;

        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::HttpRequestData > createHttpRequest() const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > createResponse() const override;

    private:
        const std::shared_ptr< std::istream > m_Template;
        const std::shared_ptr< std::wstring > m_Data;
        const std::shared_ptr< aspose::words::cloud::models::ReportEngineSettings > m_ReportEngineSettings;
        const std::shared_ptr< std::wstring > m_DocumentFileName;
    };
}
