/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PdfEncryptionDetailsData.cpp">
*   Copyright (c) 2018 Aspose.Words for Cloud
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


#include "PdfEncryptionDetailsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

PdfEncryptionDetailsData::PdfEncryptionDetailsData()
{
    m_EncryptionAlgorithm = _XPLATSTR("");
    m_EncryptionAlgorithmIsSet = false;
    m_OwnerPassword = _XPLATSTR("");
    m_OwnerPasswordIsSet = false;
    m_Permissions = _XPLATSTR("");
    m_PermissionsIsSet = false;
    m_UserPassword = _XPLATSTR("");
    m_UserPasswordIsSet = false;
}

PdfEncryptionDetailsData::~PdfEncryptionDetailsData()
{
}

void PdfEncryptionDetailsData::validate()
{
    // TODO: implement validation
}

web::json::value PdfEncryptionDetailsData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_EncryptionAlgorithmIsSet)
    {
        val[_XPLATSTR("EncryptionAlgorithm")] = ModelBase::toJson(m_EncryptionAlgorithm);
    }
    if(m_OwnerPasswordIsSet)
    {
        val[_XPLATSTR("OwnerPassword")] = ModelBase::toJson(m_OwnerPassword);
    }
    if(m_PermissionsIsSet)
    {
        val[_XPLATSTR("Permissions")] = ModelBase::toJson(m_Permissions);
    }
    if(m_UserPasswordIsSet)
    {
        val[_XPLATSTR("UserPassword")] = ModelBase::toJson(m_UserPassword);
    }

    return val;
}

void PdfEncryptionDetailsData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("EncryptionAlgorithm")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EncryptionAlgorithm")];
        if(!fieldValue.is_null())
        {
            setEncryptionAlgorithm(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OwnerPassword")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OwnerPassword")];
        if(!fieldValue.is_null())
        {
            setOwnerPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Permissions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Permissions")];
        if(!fieldValue.is_null())
        {
            setPermissions(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UserPassword")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UserPassword")];
        if(!fieldValue.is_null())
        {
            setUserPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void PdfEncryptionDetailsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_EncryptionAlgorithmIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EncryptionAlgorithm"), m_EncryptionAlgorithm));
        
    }
    if(m_OwnerPasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OwnerPassword"), m_OwnerPassword));
        
    }
    if(m_PermissionsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Permissions"), m_Permissions));
        
    }
    if(m_UserPasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UserPassword"), m_UserPassword));
        
    }
}

void PdfEncryptionDetailsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(multipart->hasContent(_XPLATSTR("EncryptionAlgorithm")))
    {
        setEncryptionAlgorithm(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("EncryptionAlgorithm"))));
    }
    if(multipart->hasContent(_XPLATSTR("OwnerPassword")))
    {
        setOwnerPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("OwnerPassword"))));
    }
    if(multipart->hasContent(_XPLATSTR("Permissions")))
    {
        setPermissions(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Permissions"))));
    }
    if(multipart->hasContent(_XPLATSTR("UserPassword")))
    {
        setUserPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("UserPassword"))));
    }
}

utility::string_t PdfEncryptionDetailsData::getEncryptionAlgorithm() const
{
    return m_EncryptionAlgorithm;
}


void PdfEncryptionDetailsData::setEncryptionAlgorithm(utility::string_t value)
{
    m_EncryptionAlgorithm = value;
    m_EncryptionAlgorithmIsSet = true;
}
bool PdfEncryptionDetailsData::encryptionAlgorithmIsSet() const
{
    return m_EncryptionAlgorithmIsSet;
}

void PdfEncryptionDetailsData::unsetEncryptionAlgorithm()
{
    m_EncryptionAlgorithmIsSet = false;
}

utility::string_t PdfEncryptionDetailsData::getOwnerPassword() const
{
    return m_OwnerPassword;
}


void PdfEncryptionDetailsData::setOwnerPassword(utility::string_t value)
{
    m_OwnerPassword = value;
    m_OwnerPasswordIsSet = true;
}
bool PdfEncryptionDetailsData::ownerPasswordIsSet() const
{
    return m_OwnerPasswordIsSet;
}

void PdfEncryptionDetailsData::unsetOwnerPassword()
{
    m_OwnerPasswordIsSet = false;
}

utility::string_t PdfEncryptionDetailsData::getPermissions() const
{
    return m_Permissions;
}


void PdfEncryptionDetailsData::setPermissions(utility::string_t value)
{
    m_Permissions = value;
    m_PermissionsIsSet = true;
}
bool PdfEncryptionDetailsData::permissionsIsSet() const
{
    return m_PermissionsIsSet;
}

void PdfEncryptionDetailsData::unsetPermissions()
{
    m_PermissionsIsSet = false;
}

utility::string_t PdfEncryptionDetailsData::getUserPassword() const
{
    return m_UserPassword;
}


void PdfEncryptionDetailsData::setUserPassword(utility::string_t value)
{
    m_UserPassword = value;
    m_UserPasswordIsSet = true;
}
bool PdfEncryptionDetailsData::userPasswordIsSet() const
{
    return m_UserPasswordIsSet;
}

void PdfEncryptionDetailsData::unsetUserPassword()
{
    m_UserPasswordIsSet = false;
}

}
}
}
}

