/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AcceptAllRevisionsRequest.cpp">
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

#include "AcceptAllRevisionsRequest.h"

namespace aspose::words::cloud::api::models {
    AcceptAllRevisionsRequest::AcceptAllRevisionsRequest(
        std::wstring name,
        std::optional< std::wstring > folder,
        std::optional< std::wstring > storage,
        std::optional< std::wstring > loadEncoding,
        std::optional< std::wstring > password,
        std::optional< std::wstring > destFileName
    ) : 
        m_Name(std::move(name)),
        m_Folder(std::move(folder)),
        m_Storage(std::move(storage)),
        m_LoadEncoding(std::move(loadEncoding)),
        m_Password(std::move(password)),
        m_DestFileName(std::move(destFileName))
    {
    }

    std::wstring AcceptAllRevisionsRequest::getName() const
    {
        return m_Name;
    }

    void AcceptAllRevisionsRequest::setName(std::wstring name)
    {
        m_Name = std::move(name);
    }

    std::optional< std::wstring > AcceptAllRevisionsRequest::getFolder() const
    {
        return m_Folder;
    }

    void AcceptAllRevisionsRequest::setFolder(std::optional< std::wstring > folder)
    {
        m_Folder = std::move(folder);
    }

    std::optional< std::wstring > AcceptAllRevisionsRequest::getStorage() const
    {
        return m_Storage;
    }

    void AcceptAllRevisionsRequest::setStorage(std::optional< std::wstring > storage)
    {
        m_Storage = std::move(storage);
    }

    std::optional< std::wstring > AcceptAllRevisionsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    void AcceptAllRevisionsRequest::setLoadEncoding(std::optional< std::wstring > loadEncoding)
    {
        m_LoadEncoding = std::move(loadEncoding);
    }

    std::optional< std::wstring > AcceptAllRevisionsRequest::getPassword() const
    {
        return m_Password;
    }

    void AcceptAllRevisionsRequest::setPassword(std::optional< std::wstring > password)
    {
        m_Password = std::move(password);
    }

    std::optional< std::wstring > AcceptAllRevisionsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    void AcceptAllRevisionsRequest::setDestFileName(std::optional< std::wstring > destFileName)
    {
        m_DestFileName = std::move(destFileName);
    }
}
