/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="accept_all_revisions_request.h">
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

#pragma once
#include "request_model_base.h"

namespace aspose::words::cloud::api::models::requests {
    class AcceptAllRevisionsRequest : public RequestModelBase {
    public:
        AcceptAllRevisionsRequest(
            const std::wstring&& name,
            const std::optional<std::wstring>&& folder = std::nullopt,
            const std::optional<std::wstring>&& storage = std::nullopt,
            const std::optional<std::wstring>&& loadEncoding = std::nullopt,
            const std::optional<std::wstring>&& password = std::nullopt,
            const std::optional<std::wstring>&& destFileName = std::nullopt
        );

        const std::wstring& getName() const;
        const std::optional<std::wstring>& getFolder() const;
        const std::optional<std::wstring>& getStorage() const;
        const std::optional<std::wstring>& getLoadEncoding() const;
        const std::optional<std::wstring>& getPassword() const;
        const std::optional<std::wstring>& getDestFileName() const;

        virtual std::shared_ptr<HttpRequestData> createHttpRequest() const override;

    private:
        const std::wstring m_Name;
        const std::optional<std::wstring> m_Folder;
        const std::optional<std::wstring> m_Storage;
        const std::optional<std::wstring> m_LoadEncoding;
        const std::optional<std::wstring> m_Password;
        const std::optional<std::wstring> m_DestFileName;
    };
}
