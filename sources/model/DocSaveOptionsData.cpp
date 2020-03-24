/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocSaveOptionsData.cpp">
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


#include "DocSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DocSaveOptionsData::DocSaveOptionsData()
{
    m_AlwaysCompressMetafiles = false;
    m_AlwaysCompressMetafilesIsSet = false;
    m_Password = utility::conversions::to_string_t("");
    m_PasswordIsSet = false;
    m_SavePictureBullet = false;
    m_SavePictureBulletIsSet = false;
    m_SaveRoutingSlip = false;
    m_SaveRoutingSlipIsSet = false;
}

DocSaveOptionsData::~DocSaveOptionsData()
{
}

void DocSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value DocSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_AlwaysCompressMetafilesIsSet)
    {
        val[_XPLATSTR("AlwaysCompressMetafiles")] = ModelBase::toJson(m_AlwaysCompressMetafiles);
    }
    if(m_PasswordIsSet)
    {
        val[_XPLATSTR("Password")] = ModelBase::toJson(m_Password);
    }
    if(m_SavePictureBulletIsSet)
    {
        val[_XPLATSTR("SavePictureBullet")] = ModelBase::toJson(m_SavePictureBullet);
    }
    if(m_SaveRoutingSlipIsSet)
    {
        val[_XPLATSTR("SaveRoutingSlip")] = ModelBase::toJson(m_SaveRoutingSlip);
    }

    return val;
}

void DocSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("AlwaysCompressMetafiles")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AlwaysCompressMetafiles")];
        if(!fieldValue.is_null())
        {
            setAlwaysCompressMetafiles(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Password")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Password")];
        if(!fieldValue.is_null())
        {
            setPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SavePictureBullet")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SavePictureBullet")];
        if(!fieldValue.is_null())
        {
            setSavePictureBullet(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SaveRoutingSlip")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SaveRoutingSlip")];
        if(!fieldValue.is_null())
        {
            setSaveRoutingSlip(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void DocSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    SaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_AlwaysCompressMetafilesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AlwaysCompressMetafiles"), m_AlwaysCompressMetafiles));
        
    }
    if(m_PasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Password"), m_Password));
        
    }
    if(m_SavePictureBulletIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SavePictureBullet"), m_SavePictureBullet));
        
    }
    if(m_SaveRoutingSlipIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SaveRoutingSlip"), m_SaveRoutingSlip));
        
    }
}

void DocSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    SaveOptionsData::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("AlwaysCompressMetafiles")))
    {
        setAlwaysCompressMetafiles(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("AlwaysCompressMetafiles"))));
    }
    if(multipart->hasContent(_XPLATSTR("Password")))
    {
        setPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Password"))));
    }
    if(multipart->hasContent(_XPLATSTR("SavePictureBullet")))
    {
        setSavePictureBullet(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("SavePictureBullet"))));
    }
    if(multipart->hasContent(_XPLATSTR("SaveRoutingSlip")))
    {
        setSaveRoutingSlip(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("SaveRoutingSlip"))));
    }
}

bool DocSaveOptionsData::isAlwaysCompressMetafiles() const
{
    return m_AlwaysCompressMetafiles;
}


void DocSaveOptionsData::setAlwaysCompressMetafiles(bool value)
{
    m_AlwaysCompressMetafiles = value;
    m_AlwaysCompressMetafilesIsSet = true;
}
bool DocSaveOptionsData::alwaysCompressMetafilesIsSet() const
{
    return m_AlwaysCompressMetafilesIsSet;
}

void DocSaveOptionsData::unsetAlwaysCompressMetafiles()
{
    m_AlwaysCompressMetafilesIsSet = false;
}

utility::string_t DocSaveOptionsData::getPassword() const
{
    return m_Password;
}


void DocSaveOptionsData::setPassword(utility::string_t value)
{
    m_Password = value;
    m_PasswordIsSet = true;
}
bool DocSaveOptionsData::passwordIsSet() const
{
    return m_PasswordIsSet;
}

void DocSaveOptionsData::unsetPassword()
{
    m_PasswordIsSet = false;
}

bool DocSaveOptionsData::isSavePictureBullet() const
{
    return m_SavePictureBullet;
}


void DocSaveOptionsData::setSavePictureBullet(bool value)
{
    m_SavePictureBullet = value;
    m_SavePictureBulletIsSet = true;
}
bool DocSaveOptionsData::savePictureBulletIsSet() const
{
    return m_SavePictureBulletIsSet;
}

void DocSaveOptionsData::unsetSavePictureBullet()
{
    m_SavePictureBulletIsSet = false;
}

bool DocSaveOptionsData::isSaveRoutingSlip() const
{
    return m_SaveRoutingSlip;
}


void DocSaveOptionsData::setSaveRoutingSlip(bool value)
{
    m_SaveRoutingSlip = value;
    m_SaveRoutingSlipIsSet = true;
}
bool DocSaveOptionsData::saveRoutingSlipIsSet() const
{
    return m_SaveRoutingSlipIsSet;
}

void DocSaveOptionsData::unsetSaveRoutingSlip()
{
    m_SaveRoutingSlipIsSet = false;
}

}
}
}
}
}

