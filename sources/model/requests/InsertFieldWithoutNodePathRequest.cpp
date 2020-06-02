/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="InsertFieldWithoutNodePathRequest.cpp">
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

#include "InsertFieldWithoutNodePathRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
InsertFieldWithoutNodePathRequest::InsertFieldWithoutNodePathRequest(
    utility::string_t name,
    std::shared_ptr<FieldInsert> field,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime,
    boost::optional< utility::string_t > insertBeforeNode
) : m_Name(std::move(name)),
m_Field(std::move(field)),
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

utility::string_t InsertFieldWithoutNodePathRequest::getName() const
{
    return m_Name;
}

void InsertFieldWithoutNodePathRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<FieldInsert> InsertFieldWithoutNodePathRequest::getField() const
{
    return m_Field;
}

void InsertFieldWithoutNodePathRequest::setField(std::shared_ptr<FieldInsert> field)
{
    m_Field = std::move(field);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getFolder() const
{
    return m_Folder;
}

void InsertFieldWithoutNodePathRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getStorage() const
{
    return m_Storage;
}

void InsertFieldWithoutNodePathRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void InsertFieldWithoutNodePathRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getPassword() const
{
    return m_Password;
}

void InsertFieldWithoutNodePathRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getDestFileName() const
{
    return m_DestFileName;
}

void InsertFieldWithoutNodePathRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void InsertFieldWithoutNodePathRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void InsertFieldWithoutNodePathRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

boost::optional< utility::string_t > InsertFieldWithoutNodePathRequest::getInsertBeforeNode() const
{
    return m_InsertBeforeNode;
}

void InsertFieldWithoutNodePathRequest::setInsertBeforeNode(boost::optional< utility::string_t > insertBeforeNode)
{
    m_InsertBeforeNode = std::move(insertBeforeNode);
}

}
}
}
}
}
