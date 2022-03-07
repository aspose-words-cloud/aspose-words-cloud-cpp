/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="pdf_encryption_details_data.h">
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
#include "./model_base.h"
#include "pdf_permissions.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for details of encryption.
    /// </summary>
    class PdfEncryptionDetailsData : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~PdfEncryptionDetailsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the owner password for the encrypted PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getOwnerPassword() const;

        /// <summary>
        /// Gets or sets the owner password for the encrypted PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOwnerPassword(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the operations that are allowed to a user on the encrypted PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::PdfPermissions>> > getPermissions() const;

        /// <summary>
        /// Gets or sets the operations that are allowed to a user on the encrypted PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPermissions(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::PdfPermissions>> > value);


        /// <summary>
        /// Gets or sets the user password required for opening the encrypted PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getUserPassword() const;

        /// <summary>
        /// Gets or sets the user password required for opening the encrypted PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUserPassword(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_OwnerPassword;
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::PdfPermissions>> > m_Permissions;
        std::shared_ptr< std::wstring > m_UserPassword;
    };
}

