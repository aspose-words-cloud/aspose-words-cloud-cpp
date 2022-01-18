/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="update_run_online_request.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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
#include "./request_model_base.h"
#include "aspose_words_cloud/models/run_update.h"

namespace aspose::words::cloud::requests {
    class UpdateRunOnlineRequest : public RequestModelBase {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT UpdateRunOnlineRequest(
            const std::shared_ptr< std::istream > document,
            const std::shared_ptr< std::wstring > paragraphPath,
            const std::shared_ptr< aspose::words::cloud::models::RunUpdate > run,
            const std::shared_ptr< int32_t > index,
            const std::shared_ptr< std::wstring > loadEncoding = nullptr,
            const std::shared_ptr< std::wstring > password = nullptr,
            const std::shared_ptr< std::wstring > encryptedPassword = nullptr,
            const std::shared_ptr< std::wstring > destFileName = nullptr,
            const std::shared_ptr< std::wstring > revisionAuthor = nullptr,
            const std::shared_ptr< std::wstring > revisionDateTime = nullptr
        );

        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::istream > getDocument() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getParagraphPath() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< aspose::words::cloud::models::RunUpdate > getRun() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< int32_t > getIndex() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getLoadEncoding() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getPassword() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getEncryptedPassword() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getDestFileName() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getRevisionAuthor() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getRevisionDateTime() const;

        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::HttpRequestData > createHttpRequest() const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > createResponse() const override;

    private:
        const std::shared_ptr< std::istream > m_Document;
        const std::shared_ptr< std::wstring > m_ParagraphPath;
        const std::shared_ptr< aspose::words::cloud::models::RunUpdate > m_Run;
        const std::shared_ptr< int32_t > m_Index;
        const std::shared_ptr< std::wstring > m_LoadEncoding;
        const std::shared_ptr< std::wstring > m_Password;
        const std::shared_ptr< std::wstring > m_EncryptedPassword;
        const std::shared_ptr< std::wstring > m_DestFileName;
        const std::shared_ptr< std::wstring > m_RevisionAuthor;
        const std::shared_ptr< std::wstring > m_RevisionDateTime;
    };
}
