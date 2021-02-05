/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="CreateDocumentRequest.cpp">
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

#include "CreateDocumentRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
CreateDocumentRequest::CreateDocumentRequest(
    boost::optional< utility::string_t > fileName,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage
) : m_FileName(std::move(fileName)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage))
{
}

boost::optional< utility::string_t > CreateDocumentRequest::getFileName() const
{
    return m_FileName;
}

void CreateDocumentRequest::setFileName(boost::optional< utility::string_t > fileName)
{
    m_FileName = std::move(fileName);
}

boost::optional< utility::string_t > CreateDocumentRequest::getFolder() const
{
    return m_Folder;
}

void CreateDocumentRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > CreateDocumentRequest::getStorage() const
{
    return m_Storage;
}

void CreateDocumentRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

}
}
}
}
}
