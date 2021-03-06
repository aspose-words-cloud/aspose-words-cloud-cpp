/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertOrUpdateParagraphTabStopOnlineRequest.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "InsertOrUpdateParagraphTabStopOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertOrUpdateParagraphTabStopOnlineRequest::InsertOrUpdateParagraphTabStopOnlineRequest(
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<TabStopInsert> tabStopInsertDto,
    int32_t index,
    boost::optional< utility::string_t > nodePath,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName
) : m_Document(std::move(document)),
m_TabStopInsertDto(std::move(tabStopInsertDto)),
m_Index(std::move(index)),
m_NodePath(std::move(nodePath)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName))
{
}

std::shared_ptr<HttpContent> InsertOrUpdateParagraphTabStopOnlineRequest::getDocument() const
{
    return m_Document;
}

void InsertOrUpdateParagraphTabStopOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<TabStopInsert> InsertOrUpdateParagraphTabStopOnlineRequest::getTabStopInsertDto() const
{
    return m_TabStopInsertDto;
}

void InsertOrUpdateParagraphTabStopOnlineRequest::setTabStopInsertDto(std::shared_ptr<TabStopInsert> tabStopInsertDto)
{
    m_TabStopInsertDto = std::move(tabStopInsertDto);
}

int32_t InsertOrUpdateParagraphTabStopOnlineRequest::getIndex() const
{
    return m_Index;
}

void InsertOrUpdateParagraphTabStopOnlineRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > InsertOrUpdateParagraphTabStopOnlineRequest::getNodePath() const
{
    return m_NodePath;
}

void InsertOrUpdateParagraphTabStopOnlineRequest::setNodePath(boost::optional< utility::string_t > nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > InsertOrUpdateParagraphTabStopOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertOrUpdateParagraphTabStopOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertOrUpdateParagraphTabStopOnlineRequest::getPassword() const
{
    return m_Password;
}

void InsertOrUpdateParagraphTabStopOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertOrUpdateParagraphTabStopOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertOrUpdateParagraphTabStopOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

}
}
}
}
}
