/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="apply_style_to_document_element_online_request.h">
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
#include "aspose_words_cloud/models/style_apply.h"

namespace aspose::words::cloud::requests {
    class ApplyStyleToDocumentElementOnlineRequest : public RequestModelBase {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT ApplyStyleToDocumentElementOnlineRequest(
            const std::shared_ptr< std::istream > document,
            const std::shared_ptr< std::wstring > styledNodePath,
            const std::shared_ptr< aspose::words::cloud::models::StyleApply > styleApply,
            const std::shared_ptr< std::wstring > loadEncoding = nullptr,
            const std::shared_ptr< std::wstring > password = nullptr,
            const std::shared_ptr< std::wstring > encryptedPassword = nullptr,
            const std::shared_ptr< std::wstring > destFileName = nullptr,
            const std::shared_ptr< std::wstring > revisionAuthor = nullptr,
            const std::shared_ptr< std::wstring > revisionDateTime = nullptr
        );

        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::istream > getDocument() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getStyledNodePath() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< aspose::words::cloud::models::StyleApply > getStyleApply() const;
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
        const std::shared_ptr< std::wstring > m_StyledNodePath;
        const std::shared_ptr< aspose::words::cloud::models::StyleApply > m_StyleApply;
        const std::shared_ptr< std::wstring > m_LoadEncoding;
        const std::shared_ptr< std::wstring > m_Password;
        const std::shared_ptr< std::wstring > m_EncryptedPassword;
        const std::shared_ptr< std::wstring > m_DestFileName;
        const std::shared_ptr< std::wstring > m_RevisionAuthor;
        const std::shared_ptr< std::wstring > m_RevisionDateTime;
    };
}
