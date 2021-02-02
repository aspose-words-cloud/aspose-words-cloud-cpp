/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OptimizeDocumentRequest.cpp">
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

#include "OptimizeDocumentRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
OptimizeDocumentRequest::OptimizeDocumentRequest(
    utility::string_t name,
    std::shared_ptr<OptimizationOptions> options,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > destFileName,
    boost::optional< utility::string_t > revisionAuthor,
    boost::optional< utility::string_t > revisionDateTime
) : m_Name(std::move(name)),
m_Options(std::move(options)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_DestFileName(std::move(destFileName)),
m_RevisionAuthor(std::move(revisionAuthor)),
m_RevisionDateTime(std::move(revisionDateTime))
{
}

utility::string_t OptimizeDocumentRequest::getName() const
{
    return m_Name;
}

void OptimizeDocumentRequest::setName(utility::string_t name)
{
    m_Name = std::move(name);
}

std::shared_ptr<OptimizationOptions> OptimizeDocumentRequest::getOptions() const
{
    return m_Options;
}

void OptimizeDocumentRequest::setOptions(std::shared_ptr<OptimizationOptions> options)
{
    m_Options = std::move(options);
}

boost::optional< utility::string_t > OptimizeDocumentRequest::getFolder() const
{
    return m_Folder;
}

void OptimizeDocumentRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > OptimizeDocumentRequest::getStorage() const
{
    return m_Storage;
}

void OptimizeDocumentRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > OptimizeDocumentRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void OptimizeDocumentRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > OptimizeDocumentRequest::getPassword() const
{
    return m_Password;
}

void OptimizeDocumentRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > OptimizeDocumentRequest::getDestFileName() const
{
    return m_DestFileName;
}

void OptimizeDocumentRequest::setDestFileName(boost::optional< utility::string_t > destFileName)
{
    m_DestFileName = std::move(destFileName);
}

boost::optional< utility::string_t > OptimizeDocumentRequest::getRevisionAuthor() const
{
    return m_RevisionAuthor;
}

void OptimizeDocumentRequest::setRevisionAuthor(boost::optional< utility::string_t > revisionAuthor)
{
    m_RevisionAuthor = std::move(revisionAuthor);
}

boost::optional< utility::string_t > OptimizeDocumentRequest::getRevisionDateTime() const
{
    return m_RevisionDateTime;
}

void OptimizeDocumentRequest::setRevisionDateTime(boost::optional< utility::string_t > revisionDateTime)
{
    m_RevisionDateTime = std::move(revisionDateTime);
}

}
}
}
}
}
