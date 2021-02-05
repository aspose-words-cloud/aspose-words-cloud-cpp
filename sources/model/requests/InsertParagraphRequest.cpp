/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertParagraphRequest.cpp">
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

#include "InsertParagraphRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertParagraphRequest::InsertParagraphRequest(
    utility::string_t name,
    std::shared_ptr<ParagraphInsert> paragraph,
    boost::optional< utility::string_t > nodePath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime,
    boost::optional< utility::string_t > insertBeforeNode
) : m_Name(std::move(name)),
m_Paragraph(std::move(paragraph)),
m_NodePath(std::move(nodePath)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime)),
m_InsertBeforeNode(std::move(insertBeforeNode))
{
}

utility::string_t InsertParagraphRequest::getName() const
{
    return m_Name;
}

void InsertParagraphRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<ParagraphInsert> InsertParagraphRequest::getParagraph() const
{
    return m_Paragraph;
}

void InsertParagraphRequest::setParagraph(std::shared_ptr<ParagraphInsert> paragraph)
{
    m_Paragraph = std::move(paragraph);
}

boost::optional< utility::string_t > InsertParagraphRequest::getNodePath() const
{
    return m_NodePath;
}

void InsertParagraphRequest::setNodePath(boost::optional< utility::string_t > nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > InsertParagraphRequest::getFolder() const
{
    return m_Folder;
}

void InsertParagraphRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertParagraphRequest::getStorage() const
{
    return m_Storage;
}

void InsertParagraphRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertParagraphRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertParagraphRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertParagraphRequest::getPassword() const
{
    return m_Password;
}

void InsertParagraphRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertParagraphRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertParagraphRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertParagraphRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertParagraphRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertParagraphRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertParagraphRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

boost::optional< utility::string_t > InsertParagraphRequest::getInsertBeforeNode() const
{
    return m_InsertBeforeNode;
}

void InsertParagraphRequest::setInsertBeforeNode(boost::optional< utility::string_t > insertBeforeNode)
{
    m_InsertBeforeNode = std::move(insertBeforeNode);
}

}
}
}
}
}
