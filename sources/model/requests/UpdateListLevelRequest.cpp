/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="UpdateListLevelRequest.cpp">
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

#include "UpdateListLevelRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
UpdateListLevelRequest::UpdateListLevelRequest(
    utility::string_t name,
    int32_t listId,
    int32_t listLevel,
    std::shared_ptr<ListLevelUpdate> listUpdate,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_ListId(std::move(listId)),
m_ListLevel(std::move(listLevel)),
m_ListUpdate(std::move(listUpdate)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t UpdateListLevelRequest::getName() const
{
    return m_Name;
}

void UpdateListLevelRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

int32_t UpdateListLevelRequest::getListId() const
{
    return m_ListId;
}

void UpdateListLevelRequest::setListId(int32_t listId)
{
    m_ListId = std::move(listId);
}

int32_t UpdateListLevelRequest::getListLevel() const
{
    return m_ListLevel;
}

void UpdateListLevelRequest::setListLevel(int32_t listLevel)
{
    m_ListLevel = std::move(listLevel);
}

std::shared_ptr<ListLevelUpdate> UpdateListLevelRequest::getListUpdate() const
{
    return m_ListUpdate;
}

void UpdateListLevelRequest::setListUpdate(std::shared_ptr<ListLevelUpdate> listUpdate)
{
    m_ListUpdate = std::move(listUpdate);
}

boost::optional< utility::string_t > UpdateListLevelRequest::getFolder() const
{
    return m_Folder;
}

void UpdateListLevelRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > UpdateListLevelRequest::getStorage() const
{
    return m_Storage;
}

void UpdateListLevelRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > UpdateListLevelRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void UpdateListLevelRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > UpdateListLevelRequest::getPassword() const
{
    return m_Password;
}

void UpdateListLevelRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > UpdateListLevelRequest::getDestFileName() const
{
    return m_DestFileName;
}

void UpdateListLevelRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > UpdateListLevelRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void UpdateListLevelRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > UpdateListLevelRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void UpdateListLevelRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
