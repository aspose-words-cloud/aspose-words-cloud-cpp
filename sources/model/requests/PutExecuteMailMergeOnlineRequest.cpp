/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PutExecuteMailMergeOnlineRequest.cpp">
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
#include "PutExecuteMailMergeOnlineRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
PutExecuteMailMergeOnlineRequest::PutExecuteMailMergeOnlineRequest(
        std::shared_ptr<HttpContent> _template,
                std::shared_ptr<HttpContent> data,
                boost::optional<bool> withRegions,
                boost::optional<utility::string_t> cleanup,
                boost::optional<utility::string_t> documentFileName
        ) : 
            m__template(std::move(_template)),
            m_data(std::move(data)),
            m_withRegions(std::move(withRegions)),
            m_cleanup(std::move(cleanup)),
            m_documentFileName(std::move(documentFileName))
        {
            
        }

        std::shared_ptr<HttpContent> PutExecuteMailMergeOnlineRequest::getTemplate() const
        {
            return m__template;
        }
        void PutExecuteMailMergeOnlineRequest::setTemplate(std::shared_ptr<HttpContent> _template){
            m__template = std::move(_template);
        }
        std::shared_ptr<HttpContent> PutExecuteMailMergeOnlineRequest::getData() const
        {
            return m_data;
        }
        void PutExecuteMailMergeOnlineRequest::setData(std::shared_ptr<HttpContent> data){
            m_data = std::move(data);
        }
        boost::optional<bool> PutExecuteMailMergeOnlineRequest::getWithRegions() const
        {
            return m_withRegions;
        }
        void PutExecuteMailMergeOnlineRequest::setWithRegions(boost::optional<bool> withRegions){
            m_withRegions = std::move(withRegions);
        }
        boost::optional<utility::string_t> PutExecuteMailMergeOnlineRequest::getCleanup() const
        {
            return m_cleanup;
        }
        void PutExecuteMailMergeOnlineRequest::setCleanup(boost::optional<utility::string_t> cleanup){
            m_cleanup = std::move(cleanup);
        }
        boost::optional<utility::string_t> PutExecuteMailMergeOnlineRequest::getDocumentFileName() const
        {
            return m_documentFileName;
        }
        void PutExecuteMailMergeOnlineRequest::setDocumentFileName(boost::optional<utility::string_t> documentFileName){
            m_documentFileName = std::move(documentFileName);
        }

}
}
}
}
}

