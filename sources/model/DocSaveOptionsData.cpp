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
        val[_XPLATSTR("alwaysCompressMetafiles")] = ModelBase::toJson(m_AlwaysCompressMetafiles);
    }
    if(m_PasswordIsSet)
    {
        val[_XPLATSTR("password")] = ModelBase::toJson(m_Password);
    }
    if(m_SavePictureBulletIsSet)
    {
        val[_XPLATSTR("savePictureBullet")] = ModelBase::toJson(m_SavePictureBullet);
    }
    if(m_SaveRoutingSlipIsSet)
    {
        val[_XPLATSTR("saveRoutingSlip")] = ModelBase::toJson(m_SaveRoutingSlip);
    }

    return val;
}

void DocSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("alwaysCompressMetafiles")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("alwaysCompressMetafiles")];
        if(!fieldValue.is_null())
        {
            setAlwaysCompressMetafiles(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("password")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("password")];
        if(!fieldValue.is_null())
        {
            setPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("savePictureBullet")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("savePictureBullet")];
        if(!fieldValue.is_null())
        {
            setSavePictureBullet(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("saveRoutingSlip")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("saveRoutingSlip")];
        if(!fieldValue.is_null())
        {
            setSaveRoutingSlip(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void DocSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("colorMode"), m_ColorMode));
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("saveFormat"), m_SaveFormat));
        
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fileName"), m_FileName));
        
    }
    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dmlRenderingMode"), m_DmlRenderingMode));
        
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
        
    }
    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("zipOutput"), m_ZipOutput));
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("updateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }
    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("updateSdtContent"), m_UpdateSdtContent));
    }
    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("updateFields"), m_UpdateFields));
    }
    if(m_AlwaysCompressMetafilesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("alwaysCompressMetafiles"), m_AlwaysCompressMetafiles));
    }
    if(m_PasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("password"), m_Password));
        
    }
    if(m_SavePictureBulletIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("savePictureBullet"), m_SavePictureBullet));
    }
    if(m_SaveRoutingSlipIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("saveRoutingSlip"), m_SaveRoutingSlip));
    }
}

void DocSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("colorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("colorMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("saveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("saveFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("fileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fileName"))));
    }
    if(multipart->hasContent(_XPLATSTR("dmlRenderingMode")))
    {
        setDmlRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("dmlRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("dmlEffectsRenderingMode")))
    {
        setDmlEffectsRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("dmlEffectsRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("zipOutput")))
    {
        setZipOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("zipOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("updateLastSavedTimeProperty")))
    {
        setUpdateLastSavedTimeProperty(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("updateLastSavedTimeProperty"))));
    }
    if(multipart->hasContent(_XPLATSTR("updateSdtContent")))
    {
        setUpdateSdtContent(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("updateSdtContent"))));
    }
    if(multipart->hasContent(_XPLATSTR("updateFields")))
    {
        setUpdateFields(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("updateFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("alwaysCompressMetafiles")))
    {
        setAlwaysCompressMetafiles(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("alwaysCompressMetafiles"))));
    }
    if(multipart->hasContent(_XPLATSTR("password")))
    {
        setPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("password"))));
    }
    if(multipart->hasContent(_XPLATSTR("savePictureBullet")))
    {
        setSavePictureBullet(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("savePictureBullet"))));
    }
    if(multipart->hasContent(_XPLATSTR("saveRoutingSlip")))
    {
        setSaveRoutingSlip(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("saveRoutingSlip"))));
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

