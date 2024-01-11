/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="protection_request_v2.h">
*   Copyright (c) 2024 Aspose.Words for Cloud
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
#include "model_base.h"
#include "protection_request_base.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Request on changing of protection.
    /// </summary>
    class ProtectionRequestV2 : public ProtectionRequestBase
    {
    public:
        /// <summary>
        /// Gets or sets the new type of the document protection.
        /// </summary>
        enum class ProtectionType
        { 
            ALLOW_ONLY_REVISIONS,
            ALLOW_ONLY_COMMENTS,
            ALLOW_ONLY_FORM_FIELDS,
            READ_ONLY,
            NO_PROTECTION
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ProtectionRequestV2() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractProtectionRequestBase() override {}

        /// <summary>
        /// Gets or sets the new password for the document protection.
        /// This property is required, but empty value is allowed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getProtectionPassword() const;

        /// <summary>
        /// Gets or sets the new password for the document protection.
        /// This property is required, but empty value is allowed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setProtectionPassword(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the new type of the document protection.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ProtectionRequestV2::ProtectionType > getProtectionType() const;

        /// <summary>
        /// Gets or sets the new type of the document protection.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setProtectionType(std::shared_ptr< aspose::words::cloud::models::ProtectionRequestV2::ProtectionType > value);


    protected:
        std::shared_ptr< std::wstring > m_ProtectionPassword;
        std::shared_ptr< aspose::words::cloud::models::ProtectionRequestV2::ProtectionType > m_ProtectionType;
    };
}

