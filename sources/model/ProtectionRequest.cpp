/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ProtectionRequest.cpp">
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


#include "ProtectionRequest.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

ProtectionRequest::ProtectionRequest()
{
    m_Password = utility::conversions::to_string_t("");
    m_PasswordIsSet = false;
    m_NewPassword = utility::conversions::to_string_t("");
    m_NewPasswordIsSet = false;
    m_ProtectionType = utility::conversions::to_string_t("");
    m_ProtectionTypeIsSet = false;
}

ProtectionRequest::~ProtectionRequest()
{
}

void ProtectionRequest::validate()
{
    // TODO: implement validation
}

web::json::value ProtectionRequest::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_PasswordIsSet)
    {
        val[_XPLATSTR("Password")] = ModelBase::toJson(m_Password);
    }
    if(m_NewPasswordIsSet)
    {
        val[_XPLATSTR("NewPassword")] = ModelBase::toJson(m_NewPassword);
    }
    if(m_ProtectionTypeIsSet)
    {
        val[_XPLATSTR("ProtectionType")] = ModelBase::toJson(m_ProtectionType);
    }

    return val;
}

void ProtectionRequest::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Password")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Password")];
        if(!fieldValue.is_null())
        {
            setPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("NewPassword")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NewPassword")];
        if(!fieldValue.is_null())
        {
            setNewPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ProtectionType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ProtectionType")];
        if(!fieldValue.is_null())
        {
            setProtectionType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void ProtectionRequest::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_PasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Password"), m_Password));
        
    }
    if(m_NewPasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NewPassword"), m_NewPassword));
        
    }
    if(m_ProtectionTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ProtectionType"), m_ProtectionType));
        
    }
}

void ProtectionRequest::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("Password")))
    {
        setPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Password"))));
    }
    if(multipart->hasContent(_XPLATSTR("NewPassword")))
    {
        setNewPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NewPassword"))));
    }
    if(multipart->hasContent(_XPLATSTR("ProtectionType")))
    {
        setProtectionType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ProtectionType"))));
    }
}

utility::string_t ProtectionRequest::getPassword() const
{
    return m_Password;
}


void ProtectionRequest::setPassword(utility::string_t value)
{
    m_Password = value;
    m_PasswordIsSet = true;
}
bool ProtectionRequest::passwordIsSet() const
{
    return m_PasswordIsSet;
}

void ProtectionRequest::unsetPassword()
{
    m_PasswordIsSet = false;
}

utility::string_t ProtectionRequest::getNewPassword() const
{
    return m_NewPassword;
}


void ProtectionRequest::setNewPassword(utility::string_t value)
{
    m_NewPassword = value;
    m_NewPasswordIsSet = true;
}
bool ProtectionRequest::newPasswordIsSet() const
{
    return m_NewPasswordIsSet;
}

void ProtectionRequest::unsetNewPassword()
{
    m_NewPasswordIsSet = false;
}

utility::string_t ProtectionRequest::getProtectionType() const
{
    return m_ProtectionType;
}


void ProtectionRequest::setProtectionType(utility::string_t value)
{
    m_ProtectionType = value;
    m_ProtectionTypeIsSet = true;
}
bool ProtectionRequest::protectionTypeIsSet() const
{
    return m_ProtectionTypeIsSet;
}

void ProtectionRequest::unsetProtectionType()
{
    m_ProtectionTypeIsSet = false;
}

}
}
}
}

