/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="BuildReportRequest.cpp">
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
#include "BuildReportRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
BuildReportRequest::BuildReportRequest(
        utility::string_t name,
                utility::string_t data,
                std::shared_ptr<ReportEngineSettings> reportEngineSettings,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> storage,
                boost::optional<utility::string_t> loadEncoding,
                boost::optional<utility::string_t> password,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_data(std::move(data)),
            m_reportEngineSettings(std::move(reportEngineSettings)),
            m_folder(std::move(folder)),
            m_storage(std::move(storage)),
            m_loadEncoding(std::move(loadEncoding)),
            m_password(std::move(password)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t BuildReportRequest::getName() const
        {
            return m_name;
        }
        void BuildReportRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        utility::string_t BuildReportRequest::getData() const
        {
            return m_data;
        }
        void BuildReportRequest::setData(utility::string_t data){
            m_data = std::move(data);
        }
        std::shared_ptr<ReportEngineSettings> BuildReportRequest::getReportEngineSettings() const
        {
            return m_reportEngineSettings;
        }
        void BuildReportRequest::setReportEngineSettings(std::shared_ptr<ReportEngineSettings> reportEngineSettings){
            m_reportEngineSettings = std::move(reportEngineSettings);
        }
        boost::optional<utility::string_t> BuildReportRequest::getFolder() const
        {
            return m_folder;
        }
        void BuildReportRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> BuildReportRequest::getStorage() const
        {
            return m_storage;
        }
        void BuildReportRequest::setStorage(boost::optional<utility::string_t> storage){
            m_storage = std::move(storage);
        }
        boost::optional<utility::string_t> BuildReportRequest::getLoadEncoding() const
        {
            return m_loadEncoding;
        }
        void BuildReportRequest::setLoadEncoding(boost::optional<utility::string_t> loadEncoding){
            m_loadEncoding = std::move(loadEncoding);
        }
        boost::optional<utility::string_t> BuildReportRequest::getPassword() const
        {
            return m_password;
        }
        void BuildReportRequest::setPassword(boost::optional<utility::string_t> password){
            m_password = std::move(password);
        }
        boost::optional<utility::string_t> BuildReportRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void BuildReportRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}
