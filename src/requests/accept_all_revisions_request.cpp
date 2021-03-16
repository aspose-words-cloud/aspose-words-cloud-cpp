/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="accept_all_revisions_request.cpp">
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

#include "aspose_words_cloud/requests/accept_all_revisions_request.h"

namespace aspose::words::cloud::api::models::requests {
    AcceptAllRevisionsRequest::AcceptAllRevisionsRequest(
        const std::wstring&& name,
        const std::optional<std::wstring>&& folder,
        const std::optional<std::wstring>&& storage,
        const std::optional<std::wstring>&& loadEncoding,
        const std::optional<std::wstring>&& password,
        const std::optional<std::wstring>&& destFileName
    ) : 
        m_Name(std::move(name)),
        m_Folder(std::move(folder)),
        m_Storage(std::move(storage)),
        m_LoadEncoding(std::move(loadEncoding)),
        m_Password(std::move(password)),
        m_DestFileName(std::move(destFileName))
    {
    }

    const std::wstring& AcceptAllRevisionsRequest::getName() const
    {
        return m_Name;
    }

    const std::optional<std::wstring>& AcceptAllRevisionsRequest::getFolder() const
    {
        return m_Folder;
    }

    const std::optional<std::wstring>& AcceptAllRevisionsRequest::getStorage() const
    {
        return m_Storage;
    }

    const std::optional<std::wstring>& AcceptAllRevisionsRequest::getLoadEncoding() const
    {
        return m_LoadEncoding;
    }

    const std::optional<std::wstring>& AcceptAllRevisionsRequest::getPassword() const
    {
        return m_Password;
    }

    const std::optional<std::wstring>& AcceptAllRevisionsRequest::getDestFileName() const
    {
        return m_DestFileName;
    }

    std::shared_ptr<HttpRequestData> AcceptAllRevisionsRequest::createHttpRequest() const
    {
        auto result = std::make_shared<HttpRequestData>();
        result->setMethod("put");
        result->setPath("/words/{name}/revisions/acceptAll");
        result->setPathParam("{name}", m_Name);
        if (m_Folder) result->addQueryParam("folder", *m_Folder);
        if (m_Storage) result->addQueryParam("storage", *m_Storage);
        if (m_LoadEncoding) result->addQueryParam("loadEncoding", *m_LoadEncoding);
        if (m_Password) result->addQueryParam("password", *m_Password);
        if (m_DestFileName) result->addQueryParam("destFileName", *m_DestFileName);
        return result;
    }
}
