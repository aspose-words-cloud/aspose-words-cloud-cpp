/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ExecuteMailMergeOnlineRequest.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "ExecuteMailMergeOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ExecuteMailMergeOnlineRequest::ExecuteMailMergeOnlineRequest(
    std::shared_ptr<HttpContent> _template,
    std::shared_ptr<HttpContent> data,
    boost::optional< bool > withRegions,
    boost::optional< utility::string_t > cleanup,
    boost::optional< utility::string_t > documentFileName
) : m_Template(std::move(_template)),
m_Data(std::move(data)),
m_WithRegions(std::move(withRegions)),
m_Cleanup(std::move(cleanup)),
m_DocumentFileName(std::move(documentFileName))
{
}

std::shared_ptr<HttpContent> ExecuteMailMergeOnlineRequest::getTemplate() const
{
    return m_Template;
}

void ExecuteMailMergeOnlineRequest::setTemplate(std::shared_ptr<HttpContent> _template)
{
    m_Template = std::move(_template);
}

std::shared_ptr<HttpContent> ExecuteMailMergeOnlineRequest::getData() const
{
    return m_Data;
}

void ExecuteMailMergeOnlineRequest::setData(std::shared_ptr<HttpContent> data)
{
    m_Data = std::move(data);
}

boost::optional< bool > ExecuteMailMergeOnlineRequest::getWithRegions() const
{
    return m_WithRegions;
}

void ExecuteMailMergeOnlineRequest::setWithRegions(boost::optional< bool > withRegions)
{
    m_WithRegions = std::move(withRegions);
}

boost::optional< utility::string_t > ExecuteMailMergeOnlineRequest::getCleanup() const
{
    return m_Cleanup;
}

void ExecuteMailMergeOnlineRequest::setCleanup(boost::optional< utility::string_t > cleanup)
{
    m_Cleanup = std::move(cleanup);
}

boost::optional< utility::string_t > ExecuteMailMergeOnlineRequest::getDocumentFileName() const
{
    return m_DocumentFileName;
}

void ExecuteMailMergeOnlineRequest::setDocumentFileName(boost::optional< utility::string_t > documentFileName)
{
    m_DocumentFileName = std::move(documentFileName);
}

}
}
}
}
}
