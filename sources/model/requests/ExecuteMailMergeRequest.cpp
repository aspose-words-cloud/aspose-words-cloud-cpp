/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ExecuteMailMergeRequest.cpp">
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

#include "ExecuteMailMergeRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ExecuteMailMergeRequest::ExecuteMailMergeRequest(
    utility::string_t name,
    boost::optional< utility::string_t > data,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< bool > withRegions,
    boost::optional< utility::string_t > mailMergeDataFile,
    boost::optional< utility::string_t > cleanup,
    boost::optional< bool > useWholeParagraphAsRegion,
    boost::optional< utility::string_t > destFileName
) : m_Name(std::move(name)),
m_Data(std::move(data)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_WithRegions(std::move(withRegions)),
m_MailMergeDataFile(std::move(mailMergeDataFile)),
m_Cleanup(std::move(cleanup)),
m_UseWholeParagraphAsRegion(std::move(useWholeParagraphAsRegion)),
m_DestFileName(std::move(destFileName))
{
}

utility::string_t ExecuteMailMergeRequest::getName() const
{
    return m_Name;
}

void ExecuteMailMergeRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getData() const
{
    return m_Data;
}

void ExecuteMailMergeRequest::setData(boost::optional< utility::string_t > data)
{
    m_Data = std::move(data);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getFolder() const
{
    return m_Folder;
}

void ExecuteMailMergeRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getStorage() const
{
    return m_Storage;
}

void ExecuteMailMergeRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void ExecuteMailMergeRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getPassword() const
{
    return m_Password;
}

void ExecuteMailMergeRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< bool > ExecuteMailMergeRequest::getWithRegions() const
{
    return m_WithRegions;
}

void ExecuteMailMergeRequest::setWithRegions(boost::optional< bool > withRegions)
{
    m_WithRegions = std::move(withRegions);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getMailMergeDataFile() const
{
    return m_MailMergeDataFile;
}

void ExecuteMailMergeRequest::setMailMergeDataFile(boost::optional< utility::string_t > mailMergeDataFile)
{
    m_MailMergeDataFile = std::move(mailMergeDataFile);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getCleanup() const
{
    return m_Cleanup;
}

void ExecuteMailMergeRequest::setCleanup(boost::optional< utility::string_t > cleanup)
{
    m_Cleanup = std::move(cleanup);
}

boost::optional< bool > ExecuteMailMergeRequest::getUseWholeParagraphAsRegion() const
{
    return m_UseWholeParagraphAsRegion;
}

void ExecuteMailMergeRequest::setUseWholeParagraphAsRegion(boost::optional< bool > useWholeParagraphAsRegion)
{
    m_UseWholeParagraphAsRegion = std::move(useWholeParagraphAsRegion);
}

boost::optional< utility::string_t > ExecuteMailMergeRequest::getDestFileName() const
{
    return m_DestFileName;
}

void ExecuteMailMergeRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

}
}
}
}
}
