/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OdtSaveOptionsData.cpp">
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


#include "OdtSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

OdtSaveOptionsData::OdtSaveOptionsData()
{
    m_IsStrictSchema11 = false;
    m_IsStrictSchema11IsSet = false;
    m_MeasureUnit = utility::conversions::to_string_t("");
    m_MeasureUnitIsSet = false;
    m_PrettyFormat = false;
    m_PrettyFormatIsSet = false;
}

OdtSaveOptionsData::~OdtSaveOptionsData()
{
}

void OdtSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value OdtSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_IsStrictSchema11IsSet)
    {
        val[_XPLATSTR("isStrictSchema11")] = ModelBase::toJson(m_IsStrictSchema11);
    }
    if(m_MeasureUnitIsSet)
    {
        val[_XPLATSTR("measureUnit")] = ModelBase::toJson(m_MeasureUnit);
    }
    if(m_PrettyFormatIsSet)
    {
        val[_XPLATSTR("prettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }

    return val;
}

void OdtSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("isStrictSchema11")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("isStrictSchema11")];
        if(!fieldValue.is_null())
        {
            setIsStrictSchema11(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("measureUnit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("measureUnit")];
        if(!fieldValue.is_null())
        {
            setMeasureUnit(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("prettyFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("prettyFormat")];
        if(!fieldValue.is_null())
        {
            setPrettyFormat(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void OdtSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_IsStrictSchema11IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("isStrictSchema11"), m_IsStrictSchema11));
    }
    if(m_MeasureUnitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("measureUnit"), m_MeasureUnit));
        
    }
    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("prettyFormat"), m_PrettyFormat));
    }
}

void OdtSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("isStrictSchema11")))
    {
        setIsStrictSchema11(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("isStrictSchema11"))));
    }
    if(multipart->hasContent(_XPLATSTR("measureUnit")))
    {
        setMeasureUnit(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("measureUnit"))));
    }
    if(multipart->hasContent(_XPLATSTR("prettyFormat")))
    {
        setPrettyFormat(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("prettyFormat"))));
    }
}

bool OdtSaveOptionsData::isIsStrictSchema11() const
{
    return m_IsStrictSchema11;
}


void OdtSaveOptionsData::setIsStrictSchema11(bool value)
{
    m_IsStrictSchema11 = value;
    m_IsStrictSchema11IsSet = true;
}
bool OdtSaveOptionsData::isStrictSchema11IsSet() const
{
    return m_IsStrictSchema11IsSet;
}

void OdtSaveOptionsData::unsetIsStrictSchema11()
{
    m_IsStrictSchema11IsSet = false;
}

utility::string_t OdtSaveOptionsData::getMeasureUnit() const
{
    return m_MeasureUnit;
}


void OdtSaveOptionsData::setMeasureUnit(utility::string_t value)
{
    m_MeasureUnit = value;
    m_MeasureUnitIsSet = true;
}
bool OdtSaveOptionsData::measureUnitIsSet() const
{
    return m_MeasureUnitIsSet;
}

void OdtSaveOptionsData::unsetMeasureUnit()
{
    m_MeasureUnitIsSet = false;
}

bool OdtSaveOptionsData::isPrettyFormat() const
{
    return m_PrettyFormat;
}


void OdtSaveOptionsData::setPrettyFormat(bool value)
{
    m_PrettyFormat = value;
    m_PrettyFormatIsSet = true;
}
bool OdtSaveOptionsData::prettyFormatIsSet() const
{
    return m_PrettyFormatIsSet;
}

void OdtSaveOptionsData::unsetPrettyFormat()
{
    m_PrettyFormatIsSet = false;
}

}
}
}
}
}

