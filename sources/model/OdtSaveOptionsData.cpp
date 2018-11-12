/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OdtSaveOptionsData.cpp">
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


#include "OdtSaveOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[utility::conversions::to_string_t("IsStrictSchema11")] = ModelBase::toJson(m_IsStrictSchema11);
    }
    if(m_MeasureUnitIsSet)
    {
        val[utility::conversions::to_string_t("MeasureUnit")] = ModelBase::toJson(m_MeasureUnit);
    }
    if(m_PrettyFormatIsSet)
    {
        val[utility::conversions::to_string_t("PrettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }

    return val;
}

void OdtSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("IsStrictSchema11")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("IsStrictSchema11")];
        if(!fieldValue.is_null())
        {
            setIsStrictSchema11(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("MeasureUnit")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("MeasureUnit")];
        if(!fieldValue.is_null())
        {
            setMeasureUnit(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PrettyFormat")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PrettyFormat")];
        if(!fieldValue.is_null())
        {
            setPrettyFormat(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void OdtSaveOptionsData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_ColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ColorMode"), m_ColorMode));
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SaveFormat"), m_SaveFormat));
        
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FileName"), m_FileName));
        
    }
    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DmlRenderingMode"), m_DmlRenderingMode));
        
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
        
    }
    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ZipOutput"), m_ZipOutput));
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }
    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateSdtContent"), m_UpdateSdtContent));
    }
    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateFields"), m_UpdateFields));
    }
    if(m_IsStrictSchema11IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("IsStrictSchema11"), m_IsStrictSchema11));
    }
    if(m_MeasureUnitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("MeasureUnit"), m_MeasureUnit));
        
    }
    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PrettyFormat"), m_PrettyFormat));
    }
}

void OdtSaveOptionsData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("ColorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ColorMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("SaveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SaveFormat"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FileName"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DmlRenderingMode")))
    {
        setDmlRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DmlRenderingMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DmlEffectsRenderingMode")))
    {
        setDmlEffectsRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DmlEffectsRenderingMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ZipOutput")))
    {
        setZipOutput(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ZipOutput"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateLastSavedTimeProperty")))
    {
        setUpdateLastSavedTimeProperty(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateLastSavedTimeProperty"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateSdtContent")))
    {
        setUpdateSdtContent(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateSdtContent"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateFields")))
    {
        setUpdateFields(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateFields"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("IsStrictSchema11")))
    {
        setIsStrictSchema11(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("IsStrictSchema11"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("MeasureUnit")))
    {
        setMeasureUnit(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("MeasureUnit"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PrettyFormat")))
    {
        setPrettyFormat(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PrettyFormat"))));
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

