﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="save_as_range_request.h">
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
#include "./request_model_base.h"
#include "aspose_words_cloud/models/range_document.h"

namespace aspose::words::cloud::requests {
    class SaveAsRangeRequest : public RequestModelBase {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT SaveAsRangeRequest(
            const std::shared_ptr< std::wstring > name,
            const std::shared_ptr< std::wstring > rangeStartIdentifier,
            const std::shared_ptr< aspose::words::cloud::models::RangeDocument > documentParameters,
            const std::shared_ptr< std::wstring > rangeEndIdentifier = nullptr,
            const std::shared_ptr< std::wstring > folder = nullptr,
            const std::shared_ptr< std::wstring > storage = nullptr,
            const std::shared_ptr< std::wstring > loadEncoding = nullptr,
            const std::shared_ptr< std::wstring > password = nullptr
        );

        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getName() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getRangeStartIdentifier() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< aspose::words::cloud::models::RangeDocument > getDocumentParameters() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getRangeEndIdentifier() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getFolder() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getStorage() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getLoadEncoding() const;
        ASPOSE_WORDS_CLOUD_EXPORT const std::shared_ptr< std::wstring > getPassword() const;

        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::HttpRequestData > createHttpRequest() const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::responses::ResponseModelBase > createResponse() const override;

    private:
        const std::shared_ptr< std::wstring > m_Name;
        const std::shared_ptr< std::wstring > m_RangeStartIdentifier;
        const std::shared_ptr< aspose::words::cloud::models::RangeDocument > m_DocumentParameters;
        const std::shared_ptr< std::wstring > m_RangeEndIdentifier;
        const std::shared_ptr< std::wstring > m_Folder;
        const std::shared_ptr< std::wstring > m_Storage;
        const std::shared_ptr< std::wstring > m_LoadEncoding;
        const std::shared_ptr< std::wstring > m_Password;
    };
}