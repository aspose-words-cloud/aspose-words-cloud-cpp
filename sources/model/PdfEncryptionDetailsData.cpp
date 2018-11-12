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
    m_EncryptionAlgorithm = utility::conversions::to_string_t("");
    m_EncryptionAlgorithmIsSet = false;
    m_OwnerPassword = utility::conversions::to_string_t("");
    m_OwnerPasswordIsSet = false;
    m_Permissions = utility::conversions::to_string_t("");
    m_PermissionsIsSet = false;
    m_UserPassword = utility::conversions::to_string_t("");
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
        val[utility::conversions::to_string_t("EncryptionAlgorithm")] = ModelBase::toJson(m_EncryptionAlgorithm);
    }
    if(m_OwnerPasswordIsSet)
    {
        val[utility::conversions::to_string_t("OwnerPassword")] = ModelBase::toJson(m_OwnerPassword);
    }
    if(m_PermissionsIsSet)
    {
        val[utility::conversions::to_string_t("Permissions")] = ModelBase::toJson(m_Permissions);
    }
    if(m_UserPasswordIsSet)
    {
        val[utility::conversions::to_string_t("UserPassword")] = ModelBase::toJson(m_UserPassword);
    }

    return val;
}

void PdfEncryptionDetailsData::fromJson(web::json::value& val)
{
    if(val.has_field(utility::conversions::to_string_t("EncryptionAlgorithm")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("EncryptionAlgorithm")];
        if(!fieldValue.is_null())
        {
            setEncryptionAlgorithm(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("OwnerPassword")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("OwnerPassword")];
        if(!fieldValue.is_null())
        {
            setOwnerPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Permissions")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Permissions")];
        if(!fieldValue.is_null())
        {
            setPermissions(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("UserPassword")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("UserPassword")];
        if(!fieldValue.is_null())
        {
            setUserPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void PdfEncryptionDetailsData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_EncryptionAlgorithmIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("EncryptionAlgorithm"), m_EncryptionAlgorithm));
        
    }
    if(m_OwnerPasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("OwnerPassword"), m_OwnerPassword));
        
    }
    if(m_PermissionsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Permissions"), m_Permissions));
        
    }
    if(m_UserPasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UserPassword"), m_UserPassword));
        
    }
}

void PdfEncryptionDetailsData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("EncryptionAlgorithm")))
    {
        setEncryptionAlgorithm(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("EncryptionAlgorithm"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("OwnerPassword")))
    {
        setOwnerPassword(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("OwnerPassword"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Permissions")))
    {
        setPermissions(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Permissions"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UserPassword")))
    {
        setUserPassword(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UserPassword"))));
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

