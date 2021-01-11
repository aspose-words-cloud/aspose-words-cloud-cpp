/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertRunOnlineRequest.cpp">
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

#include "InsertRunOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertRunOnlineRequest::InsertRunOnlineRequest(
    std::shared_ptr<HttpContent> document,
    utility::string_t paragraphPath,
    std::shared_ptr<RunInsert> run,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime,
    boost::optional< utility::string_t > insertBeforeNode
) : m_Document(std::move(document)),
m_ParagraphPath(std::move(paragraphPath)),
m_Run(std::move(run)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime)),
m_InsertBeforeNode(std::move(insertBeforeNode))
{
}

std::shared_ptr<HttpContent> InsertRunOnlineRequest::getDocument() const
{
    return m_Document;
}

void InsertRunOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

utility::string_t InsertRunOnlineRequest::getParagraphPath() const
{
    return m_ParagraphPath;
}

void InsertRunOnlineRequest::setParagraphPath(utility::string_t paragraphPath)
{
    m_ParagraphPath = std::move(paragraphPath);
}

std::shared_ptr<RunInsert> InsertRunOnlineRequest::getRun() const
{
    return m_Run;
}

void InsertRunOnlineRequest::setRun(std::shared_ptr<RunInsert> run)
{
    m_Run = std::move(run);
}

boost::optional< utility::string_t > InsertRunOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertRunOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertRunOnlineRequest::getPassword() const
{
    return m_Password;
}

void InsertRunOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertRunOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertRunOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertRunOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertRunOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertRunOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertRunOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

boost::optional< utility::string_t > InsertRunOnlineRequest::getInsertBeforeNode() const
{
    return m_InsertBeforeNode;
}

void InsertRunOnlineRequest::setInsertBeforeNode(boost::optional< utility::string_t > insertBeforeNode)
{
    m_InsertBeforeNode = std::move(insertBeforeNode);
}

}
}
}
}
}
