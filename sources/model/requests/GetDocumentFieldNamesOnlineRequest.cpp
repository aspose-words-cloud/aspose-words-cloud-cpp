/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetDocumentFieldNamesOnlineRequest.cpp">
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
#include "GetDocumentFieldNamesOnlineRequest.h"
namespace aspose{
namespace words{
namespace cloud{
namespace api{
namespace models{
GetDocumentFieldNamesOnlineRequest::GetDocumentFieldNamesOnlineRequest(
        std::shared_ptr<HttpContent> _template,
                boost::optional<bool> useNonMergeFields
        ) : 
            m__template(std::move(_template)),
            m_useNonMergeFields(std::move(useNonMergeFields))
        {
            
        }

        std::shared_ptr<HttpContent> GetDocumentFieldNamesOnlineRequest::getTemplate() const
        {
            return m__template;
        }
        void GetDocumentFieldNamesOnlineRequest::setTemplate(std::shared_ptr<HttpContent> _template){
            m__template = std::move(_template);
        }
        boost::optional<bool> GetDocumentFieldNamesOnlineRequest::getUseNonMergeFields() const
        {
            return m_useNonMergeFields;
        }
        void GetDocumentFieldNamesOnlineRequest::setUseNonMergeFields(boost::optional<bool> useNonMergeFields){
            m_useNonMergeFields = std::move(useNonMergeFields);
        }

}
}
}
}
}

