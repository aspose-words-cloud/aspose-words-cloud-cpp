/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BuildReportOnlineRequest.cpp">
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
#include "BuildReportOnlineRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
BuildReportOnlineRequest::BuildReportOnlineRequest(
        std::shared_ptr<HttpContent> _template,
                utility::string_t data,
                std::shared_ptr<ReportEngineSettings> reportEngineSettings,
                boost::optional<utility::string_t> documentFileName
        ) : 
            m__template(std::move(_template)),
            m_data(std::move(data)),
            m_reportEngineSettings(std::move(reportEngineSettings)),
            m_documentFileName(std::move(documentFileName))
        {
            
        }

        std::shared_ptr<HttpContent> BuildReportOnlineRequest::getTemplate() const
        {
            return m__template;
        }
        void BuildReportOnlineRequest::setTemplate(std::shared_ptr<HttpContent> _template){
            m__template = std::move(_template);
        }
        utility::string_t BuildReportOnlineRequest::getData() const
        {
            return m_data;
        }
        void BuildReportOnlineRequest::setData(utility::string_t data){
            m_data = std::move(data);
        }
        std::shared_ptr<ReportEngineSettings> BuildReportOnlineRequest::getReportEngineSettings() const
        {
            return m_reportEngineSettings;
        }
        void BuildReportOnlineRequest::setReportEngineSettings(std::shared_ptr<ReportEngineSettings> reportEngineSettings){
            m_reportEngineSettings = std::move(reportEngineSettings);
        }
        boost::optional<utility::string_t> BuildReportOnlineRequest::getDocumentFileName() const
        {
            return m_documentFileName;
        }
        void BuildReportOnlineRequest::setDocumentFileName(boost::optional<utility::string_t> documentFileName){
            m_documentFileName = std::move(documentFileName);
        }

}
}
}
}
}

