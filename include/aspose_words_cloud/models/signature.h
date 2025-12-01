/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="signature.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
    /// The REST response with a document signature collection.
    /// This response is returned by the Service when handling any "https://api.aspose.cloud/v4.0/words/Test.doc/signatures" REST API requests.
    /// </summary>
    class Signature : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~Signature() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the signing purpose comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getComments() const;

        /// <summary>
        /// Gets or sets the signing purpose comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setComments(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the subject distinguished name of the certificate issuer.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getIssuerName() const;

        /// <summary>
        /// Gets or sets the subject distinguished name of the certificate issuer.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIssuerName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether this digital signature is valid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsValid() const;

        /// <summary>
        /// Gets or sets a value indicating whether this digital signature is valid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsValid(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the type of the digital signature.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSignatureType() const;

        /// <summary>
        /// Gets or sets the type of the digital signature.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSignatureType(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets an array of bytes representing a signature value as base64 string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSignatureValue() const;

        /// <summary>
        /// Gets or sets an array of bytes representing a signature value as base64 string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSignatureValue(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the time the document was signed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSignTime() const;

        /// <summary>
        /// Gets or sets the time the document was signed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSignTime(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the subject distinguished name of the certificate that was used to sign the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSubjectName() const;

        /// <summary>
        /// Gets or sets the subject distinguished name of the certificate that was used to sign the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSubjectName(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_Comments;
        std::shared_ptr< std::wstring > m_IssuerName;
        std::shared_ptr< bool > m_IsValid;
        std::shared_ptr< std::wstring > m_SignatureType;
        std::shared_ptr< std::wstring > m_SignatureValue;
        std::shared_ptr< std::wstring > m_SignTime;
        std::shared_ptr< std::wstring > m_SubjectName;
    };
}

