/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertParagraphWithoutNodePathRequest.cpp">
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

#include "InsertParagraphWithoutNodePathRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertParagraphWithoutNodePathRequest::InsertParagraphWithoutNodePathRequest(
    utility::string_t name,
    std::shared_ptr<ParagraphInsert> paragraph,
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

utility::string_t InsertParagraphWithoutNodePathRequest::getName() const
{
    return m_Name;
}

void InsertParagraphWithoutNodePathRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<ParagraphInsert> InsertParagraphWithoutNodePathRequest::getParagraph() const
{
    return m_Paragraph;
}

void InsertParagraphWithoutNodePathRequest::setParagraph(std::shared_ptr<ParagraphInsert> paragraph)
{
    m_Paragraph = std::move(paragraph);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getFolder() const
{
    return m_Folder;
}

void InsertParagraphWithoutNodePathRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getStorage() const
{
    return m_Storage;
}

void InsertParagraphWithoutNodePathRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertParagraphWithoutNodePathRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getPassword() const
{
    return m_Password;
}

void InsertParagraphWithoutNodePathRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertParagraphWithoutNodePathRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertParagraphWithoutNodePathRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertParagraphWithoutNodePathRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

boost::optional< utility::string_t > InsertParagraphWithoutNodePathRequest::getInsertBeforeNode() const
{
    return m_InsertBeforeNode;
}

void InsertParagraphWithoutNodePathRequest::setInsertBeforeNode(boost::optional< utility::string_t > insertBeforeNode)
{
    m_InsertBeforeNode = std::move(insertBeforeNode);
}

}
}
}
}
}
