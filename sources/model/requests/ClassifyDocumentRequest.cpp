/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ClassifyDocumentRequest.cpp">
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

#include "ClassifyDocumentRequest.h"
namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {
ClassifyDocumentRequest::ClassifyDocumentRequest(
    utility::string_t documentName,
    boost::optional< utility::string_t > folder,
    boost::optional< utility::string_t > storage,
    boost::optional< utility::string_t > loadEncoding,
    boost::optional< utility::string_t > password,
    boost::optional< utility::string_t > bestClassesCount,
    boost::optional< utility::string_t > taxonomy
) : m_DocumentName(std::move(documentName)),
m_Folder(std::move(folder)),
m_Storage(std::move(storage)),
m_LoadEncoding(std::move(loadEncoding)),
m_Password(std::move(password)),
m_BestClassesCount(std::move(bestClassesCount)),
m_Taxonomy(std::move(taxonomy))
{
}

utility::string_t ClassifyDocumentRequest::getDocumentName() const
{
    return m_DocumentName;
}

void ClassifyDocumentRequest::setDocumentName(utility::string_t documentName)
{
    m_DocumentName = std::move(documentName);
}

boost::optional< utility::string_t > ClassifyDocumentRequest::getFolder() const
{
    return m_Folder;
}

void ClassifyDocumentRequest::setFolder(boost::optional< utility::string_t > folder)
{
    m_Folder = std::move(folder);
}

boost::optional< utility::string_t > ClassifyDocumentRequest::getStorage() const
{
    return m_Storage;
}

void ClassifyDocumentRequest::setStorage(boost::optional< utility::string_t > storage)
{
    m_Storage = std::move(storage);
}

boost::optional< utility::string_t > ClassifyDocumentRequest::getLoadEncoding() const
{
    return m_LoadEncoding;
}

void ClassifyDocumentRequest::setLoadEncoding(boost::optional< utility::string_t > loadEncoding)
{
    m_LoadEncoding = std::move(loadEncoding);
}

boost::optional< utility::string_t > ClassifyDocumentRequest::getPassword() const
{
    return m_Password;
}

void ClassifyDocumentRequest::setPassword(boost::optional< utility::string_t > password)
{
    m_Password = std::move(password);
}

boost::optional< utility::string_t > ClassifyDocumentRequest::getBestClassesCount() const
{
    return m_BestClassesCount;
}

void ClassifyDocumentRequest::setBestClassesCount(boost::optional< utility::string_t > bestClassesCount)
{
    m_BestClassesCount = std::move(bestClassesCount);
}

boost::optional< utility::string_t > ClassifyDocumentRequest::getTaxonomy() const
{
    return m_Taxonomy;
}

void ClassifyDocumentRequest::setTaxonomy(boost::optional< utility::string_t > taxonomy)
{
    m_Taxonomy = std::move(taxonomy);
}

}
}
}
}
}
