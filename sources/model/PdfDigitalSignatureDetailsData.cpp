/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PdfDigitalSignatureDetailsData.cpp">
*   Copyright (c) 2019 Aspose.Words for Cloud
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


#include "PdfDigitalSignatureDetailsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

PdfDigitalSignatureDetailsData::PdfDigitalSignatureDetailsData()
{
    m_CertificateFilename = utility::conversions::to_string_t("");
    m_CertificateFilenameIsSet = false;
    m_HashAlgorithm = utility::conversions::to_string_t("");
    m_HashAlgorithmIsSet = false;
    m_Location = utility::conversions::to_string_t("");
    m_LocationIsSet = false;
    m_Reason = utility::conversions::to_string_t("");
    m_ReasonIsSet = false;
    m_SignatureDate = utility::datetime();
    m_SignatureDateIsSet = false;
}

PdfDigitalSignatureDetailsData::~PdfDigitalSignatureDetailsData()
{
}

void PdfDigitalSignatureDetailsData::validate()
{
    // TODO: implement validation
}

web::json::value PdfDigitalSignatureDetailsData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_CertificateFilenameIsSet)
    {
        val[_XPLATSTR("certificateFilename")] = ModelBase::toJson(m_CertificateFilename);
    }
    if(m_HashAlgorithmIsSet)
    {
        val[_XPLATSTR("hashAlgorithm")] = ModelBase::toJson(m_HashAlgorithm);
    }
    if(m_LocationIsSet)
    {
        val[_XPLATSTR("location")] = ModelBase::toJson(m_Location);
    }
    if(m_ReasonIsSet)
    {
        val[_XPLATSTR("reason")] = ModelBase::toJson(m_Reason);
    }
    if(m_SignatureDateIsSet)
    {
        val[_XPLATSTR("signatureDate")] = ModelBase::toJson(m_SignatureDate);
    }

    return val;
}

void PdfDigitalSignatureDetailsData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("certificateFilename")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("certificateFilename")];
        if(!fieldValue.is_null())
        {
            setCertificateFilename(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("hashAlgorithm")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("hashAlgorithm")];
        if(!fieldValue.is_null())
        {
            setHashAlgorithm(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("location")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("location")];
        if(!fieldValue.is_null())
        {
            setLocation(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("reason")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("reason")];
        if(!fieldValue.is_null())
        {
            setReason(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("signatureDate")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("signatureDate")];
        if(!fieldValue.is_null())
        {
            setSignatureDate(ModelBase::dateFromJson(fieldValue));
        }
    }
}

void PdfDigitalSignatureDetailsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_CertificateFilenameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("certificateFilename"), m_CertificateFilename));
        
    }
    if(m_HashAlgorithmIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("hashAlgorithm"), m_HashAlgorithm));
        
    }
    if(m_LocationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("location"), m_Location));
        
    }
    if(m_ReasonIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("reason"), m_Reason));
        
    }
    if(m_SignatureDateIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("signatureDate"), m_SignatureDate));
        
    }
}

void PdfDigitalSignatureDetailsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("certificateFilename")))
    {
        setCertificateFilename(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("certificateFilename"))));
    }
    if(multipart->hasContent(_XPLATSTR("hashAlgorithm")))
    {
        setHashAlgorithm(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("hashAlgorithm"))));
    }
    if(multipart->hasContent(_XPLATSTR("location")))
    {
        setLocation(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("location"))));
    }
    if(multipart->hasContent(_XPLATSTR("reason")))
    {
        setReason(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("reason"))));
    }
    if(multipart->hasContent(_XPLATSTR("signatureDate")))
    {
        setSignatureDate(ModelBase::dateFromHttpContent(multipart->getContent(_XPLATSTR("signatureDate"))));
    }
}

utility::string_t PdfDigitalSignatureDetailsData::getCertificateFilename() const
{
    return m_CertificateFilename;
}


void PdfDigitalSignatureDetailsData::setCertificateFilename(utility::string_t value)
{
    m_CertificateFilename = value;
    m_CertificateFilenameIsSet = true;
}
bool PdfDigitalSignatureDetailsData::certificateFilenameIsSet() const
{
    return m_CertificateFilenameIsSet;
}

void PdfDigitalSignatureDetailsData::unsetCertificateFilename()
{
    m_CertificateFilenameIsSet = false;
}

utility::string_t PdfDigitalSignatureDetailsData::getHashAlgorithm() const
{
    return m_HashAlgorithm;
}


void PdfDigitalSignatureDetailsData::setHashAlgorithm(utility::string_t value)
{
    m_HashAlgorithm = value;
    m_HashAlgorithmIsSet = true;
}
bool PdfDigitalSignatureDetailsData::hashAlgorithmIsSet() const
{
    return m_HashAlgorithmIsSet;
}

void PdfDigitalSignatureDetailsData::unsetHashAlgorithm()
{
    m_HashAlgorithmIsSet = false;
}

utility::string_t PdfDigitalSignatureDetailsData::getLocation() const
{
    return m_Location;
}


void PdfDigitalSignatureDetailsData::setLocation(utility::string_t value)
{
    m_Location = value;
    m_LocationIsSet = true;
}
bool PdfDigitalSignatureDetailsData::locationIsSet() const
{
    return m_LocationIsSet;
}

void PdfDigitalSignatureDetailsData::unsetLocation()
{
    m_LocationIsSet = false;
}

utility::string_t PdfDigitalSignatureDetailsData::getReason() const
{
    return m_Reason;
}


void PdfDigitalSignatureDetailsData::setReason(utility::string_t value)
{
    m_Reason = value;
    m_ReasonIsSet = true;
}
bool PdfDigitalSignatureDetailsData::reasonIsSet() const
{
    return m_ReasonIsSet;
}

void PdfDigitalSignatureDetailsData::unsetReason()
{
    m_ReasonIsSet = false;
}

utility::datetime PdfDigitalSignatureDetailsData::getSignatureDate() const
{
    return m_SignatureDate;
}


void PdfDigitalSignatureDetailsData::setSignatureDate(utility::datetime value)
{
    m_SignatureDate = value;
    m_SignatureDateIsSet = true;
}
bool PdfDigitalSignatureDetailsData::signatureDateIsSet() const
{
    return m_SignatureDateIsSet;
}

void PdfDigitalSignatureDetailsData::unsetSignatureDate()
{
    m_SignatureDateIsSet = false;
}

}
}
}
}
}

