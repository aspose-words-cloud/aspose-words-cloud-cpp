/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="sign_options.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for digital signature options.
    /// </summary>
    class SignOptions : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~SignOptions() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets comments on the digital signature. Default value is empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getComments() const;

        /// <summary>
        /// Gets or sets comments on the digital signature. Default value is empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setComments(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the password to decrypt source document. Default value is empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDecryptionPassword() const;

        /// <summary>
        /// Gets or sets the password to decrypt source document. Default value is empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDecryptionPassword(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the class Guid of the signature cryptography provider. Default value is Empty (all zeroes) Guid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getProviderId() const;

        /// <summary>
        /// Gets or sets the class Guid of the signature cryptography provider. Default value is Empty (all zeroes) Guid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setProviderId(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets user defined signature line Guid. Default value is Empty (all zeroes) Guid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSignatureLineId() const;

        /// <summary>
        /// Gets or sets user defined signature line Guid. Default value is Empty (all zeroes) Guid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSignatureLineId(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the image that will be shown in associated SignatureLine. Default value is empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSignatureLineImageFilename() const;

        /// <summary>
        /// Gets or sets the image that will be shown in associated SignatureLine. Default value is empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSignatureLineImageFilename(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the date of signing. Default value is current time (Now).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSignTime() const;

        /// <summary>
        /// Gets or sets the date of signing. Default value is current time (Now).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSignTime(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_Comments;
        std::shared_ptr< std::wstring > m_DecryptionPassword;
        std::shared_ptr< std::wstring > m_ProviderId;
        std::shared_ptr< std::wstring > m_SignatureLineId;
        std::shared_ptr< std::wstring > m_SignatureLineImageFilename;
        std::shared_ptr< std::wstring > m_SignTime;
    };
}

