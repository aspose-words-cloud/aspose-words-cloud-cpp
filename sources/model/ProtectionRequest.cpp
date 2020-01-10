/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ProtectionRequest.cpp">
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


#include "ProtectionRequest.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("password")] = ModelBase::toJson(m_Password);
    }
    if(m_NewPasswordIsSet)
    {
        val[_XPLATSTR("newPassword")] = ModelBase::toJson(m_NewPassword);
    }
    if(m_ProtectionTypeIsSet)
    {
        val[_XPLATSTR("protectionType")] = ModelBase::toJson(m_ProtectionType);
    }

    return val;
}

void ProtectionRequest::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("password")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("password")];
        if(!fieldValue.is_null())
        {
            setPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("newPassword")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("newPassword")];
        if(!fieldValue.is_null())
        {
            setNewPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("protectionType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("protectionType")];
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("password"), m_Password));
        
    }
    if(m_NewPasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("newPassword"), m_NewPassword));
        
    }
    if(m_ProtectionTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("protectionType"), m_ProtectionType));
        
    }
}

void ProtectionRequest::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("password")))
    {
        setPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("password"))));
    }
    if(multipart->hasContent(_XPLATSTR("newPassword")))
    {
        setNewPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("newPassword"))));
    }
    if(multipart->hasContent(_XPLATSTR("protectionType")))
    {
        setProtectionType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("protectionType"))));
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
}

