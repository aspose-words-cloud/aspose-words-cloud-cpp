/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="execute_mail_merge_request.h">
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
#include "aspose_words_cloud/models/field_options.h"

namespace aspose::words::cloud::requests {
    class ExecuteMailMergeRequest : public RequestModelBase {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT ExecuteMailMergeRequest(
            const std::shared_ptr< std::wstring > name,
            const std::shared_ptr< std::wstring > data = nullptr,
            const std::shared_ptr< aspose::words::cloud::models::FieldOptions > options = nullptr,
            const std::shared_ptr< std::wstring > folder = nullptr,
            const std::shared_ptr< std::wstring > storage = nullptr,
            const std::shared_ptr< std::wstring > loadEncoding = nullptr,
            const std::shared_ptr< std::wstring > password = nullptr,
            const std::shared_ptr< std::wstring > encryptedPassword = nullptr,
            const std::shared_ptr< bool > withRegions = nullptr,
            const std::shared_ptr< std::wstring > mailMergeDataFile = nullptr,
            const std::shared_ptr< std::wstring > cleanup = nullptr,
            const std::shared_ptr< bool > useWholeParagraphAsRegion = nullptr,
            const std::shared_ptr< std::wstring > destFileName = nullptr
        );

        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getName() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getData() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< aspose::words::cloud::models::FieldOptions > getOptions() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getFolder() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getStorage() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getLoadEncoding() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getPassword() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getEncryptedPassword() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< bool > getWithRegions() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getMailMergeDataFile() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getCleanup() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< bool > getUseWholeParagraphAsRegion() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getDestFileName() const;

        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::HttpRequestData > createHttpRequest() const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > createResponse() const override;

    private:
        const std::shared_ptr< std::wstring > m_Name;
        const std::shared_ptr< std::wstring > m_Data;
        const std::shared_ptr< aspose::words::cloud::models::FieldOptions > m_Options;
        const std::shared_ptr< std::wstring > m_Folder;
        const std::shared_ptr< std::wstring > m_Storage;
        const std::shared_ptr< std::wstring > m_LoadEncoding;
        const std::shared_ptr< std::wstring > m_Password;
        const std::shared_ptr< std::wstring > m_EncryptedPassword;
        const std::shared_ptr< bool > m_WithRegions;
        const std::shared_ptr< std::wstring > m_MailMergeDataFile;
        const std::shared_ptr< std::wstring > m_Cleanup;
        const std::shared_ptr< bool > m_UseWholeParagraphAsRegion;
        const std::shared_ptr< std::wstring > m_DestFileName;
    };
}
