/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DeleteParagraphTabStopRequest.cpp">
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

#include "DeleteParagraphTabStopRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
DeleteParagraphTabStopRequest::DeleteParagraphTabStopRequest(
    utility::string_t name,
    double position,
    int32_t index,
    boost::optional< utility::string_t > nodePath,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName
) : m_Name(std::move(name)),
m_Position(std::move(position)),
m_Index(std::move(index)),
m_NodePath(std::move(nodePath)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName))
{
}

utility::string_t DeleteParagraphTabStopRequest::getName() const
{
    return m_Name;
}

void DeleteParagraphTabStopRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

double DeleteParagraphTabStopRequest::getPosition() const
{
    return m_Position;
}

void DeleteParagraphTabStopRequest::setPosition(double position)
{
    m_Position = std::move(position);
}

int32_t DeleteParagraphTabStopRequest::getIndex() const
{
    return m_Index;
}

void DeleteParagraphTabStopRequest::setIndex(int32_t index)
{
    m_Index = std::move(index);
}

boost::optional< utility::string_t > DeleteParagraphTabStopRequest::getNodePath() const
{
    return m_NodePath;
}

void DeleteParagraphTabStopRequest::setNodePath(boost::optional< utility::string_t > nodePath)
{
    m_NodePath = std::move(nodePath);
}

boost::optional< utility::string_t > DeleteParagraphTabStopRequest::getFolder() const
{
    return m_Folder;
}

void DeleteParagraphTabStopRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > DeleteParagraphTabStopRequest::getStorage() const
{
    return m_Storage;
}

void DeleteParagraphTabStopRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > DeleteParagraphTabStopRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void DeleteParagraphTabStopRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > DeleteParagraphTabStopRequest::getPassword() const
{
    return m_Password;
}

void DeleteParagraphTabStopRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > DeleteParagraphTabStopRequest::getDestFileName() const
{
    return m_DestFileName;
}

void DeleteParagraphTabStopRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

}
}
}
}
}
