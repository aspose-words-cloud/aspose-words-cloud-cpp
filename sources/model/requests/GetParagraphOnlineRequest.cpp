/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GetParagraphOnlineRequest.cpp">
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

#include "GetParagraphOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
GetParagraphOnlineRequest::GetParagraphOnlineRequest(
    utility::string_t nodePath,
    std::shared_ptr<HttpContent> document,
    int32_t index,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password
) : m_NodePath(std::move(nodePath)),
m_Document(std::move(document)),
m_Index(std::move(index)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password))
{
}

utility::string_t GetParagraphOnlineRequest::getNodePath() const
{
    return m_NodePath;
}

void GetParagraphOnlineRequest::setNodePath(utility::string_t nodePath)
{
    m_NodePath = std::move(nodePath);
}

std::shared_ptr<HttpContent> GetParagraphOnlineRequest::getDocument() const
{
    return m_Document;
}

void GetParagraphOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

int32_t GetParagraphOnlineRequest::getIndex() const
{
    return m_Index;
}

void GetParagraphOnlineRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > GetParagraphOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void GetParagraphOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > GetParagraphOnlineRequest::getPassword() const
{
    return m_Password;
}

void GetParagraphOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

}
}
}
}
}
