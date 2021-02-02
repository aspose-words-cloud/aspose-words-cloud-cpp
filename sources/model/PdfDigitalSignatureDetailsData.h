/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PdfDigitalSignatureDetailsData.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_PdfDigitalSignatureDetailsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_PdfDigitalSignatureDetailsData_H_

#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for details of digital signature.
/// </summary>
class PdfDigitalSignatureDetailsData
    : public ModelBase
{
public:
    PdfDigitalSignatureDetailsData();
    virtual ~PdfDigitalSignatureDetailsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// PdfDigitalSignatureDetailsData members

    /// <summary>
    /// Gets or sets the certificate's filename using for signing.
    /// </summary>
    utility::string_t getCertificateFilename() const;
    bool certificateFilenameIsSet() const;
    void unsetCertificateFilename();
    void setCertificateFilename(utility::string_t value);

    /// <summary>
    /// Gets or sets the hash algorithm.
    /// </summary>
    utility::string_t getHashAlgorithm() const;
    bool hashAlgorithmIsSet() const;
    void unsetHashAlgorithm();
    void setHashAlgorithm(utility::string_t value);

    /// <summary>
    /// Gets or sets the location of the signing.
    /// </summary>
    utility::string_t getLocation() const;
    bool locationIsSet() const;
    void unsetLocation();
    void setLocation(utility::string_t value);

    /// <summary>
    /// Gets or sets the reason for the signing.
    /// </summary>
    utility::string_t getReason() const;
    bool reasonIsSet() const;
    void unsetReason();
    void setReason(utility::string_t value);

    /// <summary>
    /// Gets or sets the date of the signing.
    /// </summary>
    utility::datetime getSignatureDate() const;
    bool signatureDateIsSet() const;
    void unsetSignatureDate();
    void setSignatureDate(utility::datetime value);

protected:
    utility::string_t m_CertificateFilename;
    bool m_CertificateFilenameIsSet;

    utility::string_t m_HashAlgorithm;
    bool m_HashAlgorithmIsSet;

    utility::string_t m_Location;
    bool m_LocationIsSet;

    utility::string_t m_Reason;
    bool m_ReasonIsSet;

    utility::datetime m_SignatureDate;
    bool m_SignatureDateIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PdfDigitalSignatureDetailsData_H_ */
