/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertParagraphOnlineRequest.cpp">
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

#include "InsertParagraphOnlineRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertParagraphOnlineRequest::InsertParagraphOnlineRequest(
    utility::string_t nodePath,
    std::shared_ptr<HttpContent> document,
    std::shared_ptr<ParagraphInsert> paragraph,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime,
    boost::optional< utility::string_t > insertBeforeNode
) : m_NodePath(std::move(nodePath)),
m_Document(std::move(document)),
m_Paragraph(std::move(paragraph)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime)),
m_InsertBeforeNode(std::move(insertBeforeNode))
{
}

utility::string_t InsertParagraphOnlineRequest::getNodePath() const
{
    return m_NodePath;
}

void InsertParagraphOnlineRequest::setNodePath(utility::string_t nodePath)
{
    m_NodePath = std::move(nodePath);
}

std::shared_ptr<HttpContent> InsertParagraphOnlineRequest::getDocument() const
{
    return m_Document;
}

void InsertParagraphOnlineRequest::setDocument(std::shared_ptr<HttpContent> document)
{
    m_Document = std::move(document);
}

std::shared_ptr<ParagraphInsert> InsertParagraphOnlineRequest::getParagraph() const
{
    return m_Paragraph;
}

void InsertParagraphOnlineRequest::setParagraph(std::shared_ptr<ParagraphInsert> paragraph)
{
    m_Paragraph = std::move(paragraph);
}

boost::optional< utility::string_t > InsertParagraphOnlineRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertParagraphOnlineRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertParagraphOnlineRequest::getPassword() const
{
    return m_Password;
}

void InsertParagraphOnlineRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertParagraphOnlineRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertParagraphOnlineRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertParagraphOnlineRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertParagraphOnlineRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertParagraphOnlineRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertParagraphOnlineRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

boost::optional< utility::string_t > InsertParagraphOnlineRequest::getInsertBeforeNode() const
{
    return m_InsertBeforeNode;
}

void InsertParagraphOnlineRequest::setInsertBeforeNode(boost::optional< utility::string_t > insertBeforeNode)
{
    m_InsertBeforeNode = std::move(insertBeforeNode);
}

}
}
}
}
}
