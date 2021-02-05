/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SaveOptionsData.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#include "SaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SaveOptionsData::SaveOptionsData()
{
    m_Dml3DEffectsRenderingModeIsSet = false;
    m_DmlEffectsRenderingMode = utility::conversions::to_string_t("");
    m_DmlEffectsRenderingModeIsSet = false;
    m_DmlRenderingMode = utility::conversions::to_string_t("");
    m_DmlRenderingModeIsSet = false;
    m_FileName = utility::conversions::to_string_t("");
    m_FileNameIsSet = false;
    m_SaveFormat = utility::conversions::to_string_t("");
    m_SaveFormatIsSet = false;
    m_UpdateFields = false;
    m_UpdateFieldsIsSet = false;
    m_UpdateLastPrintedProperty = false;
    m_UpdateLastPrintedPropertyIsSet = false;
    m_UpdateLastSavedTimeProperty = false;
    m_UpdateLastSavedTimePropertyIsSet = false;
    m_UpdateSdtContent = false;
    m_UpdateSdtContentIsSet = false;
    m_ZipOutput = false;
    m_ZipOutputIsSet = false;

}

SaveOptionsData::~SaveOptionsData()
{
}

void SaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value SaveOptionsData::toJson() const
{
    web::json::value val = web::json::value::object();
    if(m_Dml3DEffectsRenderingModeIsSet)
    {
        val[_XPLATSTR("Dml3DEffectsRenderingMode")] = ModelBase::toJson(m_Dml3DEffectsRenderingMode);
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        val[_XPLATSTR("DmlEffectsRenderingMode")] = ModelBase::toJson(m_DmlEffectsRenderingMode);
    }
    if(m_DmlRenderingModeIsSet)
    {
        val[_XPLATSTR("DmlRenderingMode")] = ModelBase::toJson(m_DmlRenderingMode);
    }
    if(m_FileNameIsSet)
    {
        val[_XPLATSTR("FileName")] = ModelBase::toJson(m_FileName);
    }
    if(m_SaveFormatIsSet)
    {
        val[_XPLATSTR("SaveFormat")] = ModelBase::toJson(m_SaveFormat);
    }
    if(m_UpdateFieldsIsSet)
    {
        val[_XPLATSTR("UpdateFields")] = ModelBase::toJson(m_UpdateFields);
    }
    if(m_UpdateLastPrintedPropertyIsSet)
    {
        val[_XPLATSTR("UpdateLastPrintedProperty")] = ModelBase::toJson(m_UpdateLastPrintedProperty);
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        val[_XPLATSTR("UpdateLastSavedTimeProperty")] = ModelBase::toJson(m_UpdateLastSavedTimeProperty);
    }
    if(m_UpdateSdtContentIsSet)
    {
        val[_XPLATSTR("UpdateSdtContent")] = ModelBase::toJson(m_UpdateSdtContent);
    }
    if(m_ZipOutputIsSet)
    {
        val[_XPLATSTR("ZipOutput")] = ModelBase::toJson(m_ZipOutput);
    }

    return val;
}

void SaveOptionsData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Dml3DEffectsRenderingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Dml3DEffectsRenderingMode")];
        if(!fieldValue.is_null())
        {
           setDml3DEffectsRenderingMode(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("DmlEffectsRenderingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DmlEffectsRenderingMode")];
        if(!fieldValue.is_null())
        {
           setDmlEffectsRenderingMode(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("DmlRenderingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DmlRenderingMode")];
        if(!fieldValue.is_null())
        {
           setDmlRenderingMode(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("FileName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FileName")];
        if(!fieldValue.is_null())
        {
           setFileName(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SaveFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SaveFormat")];
        if(!fieldValue.is_null())
        {
           setSaveFormat(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("UpdateFields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UpdateFields")];
        if(!fieldValue.is_null())
        {
           setUpdateFields(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("UpdateLastPrintedProperty")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UpdateLastPrintedProperty")];
        if(!fieldValue.is_null())
        {
           setUpdateLastPrintedProperty(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("UpdateLastSavedTimeProperty")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UpdateLastSavedTimeProperty")];
        if(!fieldValue.is_null())
        {
           setUpdateLastSavedTimeProperty(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("UpdateSdtContent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UpdateSdtContent")];
        if(!fieldValue.is_null())
        {
           setUpdateSdtContent(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ZipOutput")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ZipOutput")];
        if(!fieldValue.is_null())
        {
           setZipOutput(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void SaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_Dml3DEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Dml3DEffectsRenderingMode"), m_Dml3DEffectsRenderingMode));
    }


    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
    }


    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DmlRenderingMode"), m_DmlRenderingMode));
    }


    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FileName"), m_FileName));
    }


    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SaveFormat"), m_SaveFormat));
    }


    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateFields"), m_UpdateFields));
    }


    if(m_UpdateLastPrintedPropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateLastPrintedProperty"), m_UpdateLastPrintedProperty));
    }


    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }


    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateSdtContent"), m_UpdateSdtContent));
    }


    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ZipOutput"), m_ZipOutput));
    }

}

void SaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t SaveOptionsData::getDml3DEffectsRenderingMode() const
{
    return m_Dml3DEffectsRenderingMode;
}


void SaveOptionsData::setDml3DEffectsRenderingMode(utility::string_t value)
{
    m_Dml3DEffectsRenderingMode = value;
    m_Dml3DEffectsRenderingModeIsSet = true;
}

bool SaveOptionsData::dml3DEffectsRenderingModeIsSet() const
{
    return m_Dml3DEffectsRenderingModeIsSet;
}

void SaveOptionsData::unsetDml3DEffectsRenderingMode()
{
    m_Dml3DEffectsRenderingModeIsSet = false;
}

utility::string_t SaveOptionsData::getDmlEffectsRenderingMode() const
{
    return m_DmlEffectsRenderingMode;
}


void SaveOptionsData::setDmlEffectsRenderingMode(utility::string_t value)
{
    m_DmlEffectsRenderingMode = value;
    m_DmlEffectsRenderingModeIsSet = true;
}

bool SaveOptionsData::dmlEffectsRenderingModeIsSet() const
{
    return m_DmlEffectsRenderingModeIsSet;
}

void SaveOptionsData::unsetDmlEffectsRenderingMode()
{
    m_DmlEffectsRenderingModeIsSet = false;
}

utility::string_t SaveOptionsData::getDmlRenderingMode() const
{
    return m_DmlRenderingMode;
}


void SaveOptionsData::setDmlRenderingMode(utility::string_t value)
{
    m_DmlRenderingMode = value;
    m_DmlRenderingModeIsSet = true;
}

bool SaveOptionsData::dmlRenderingModeIsSet() const
{
    return m_DmlRenderingModeIsSet;
}

void SaveOptionsData::unsetDmlRenderingMode()
{
    m_DmlRenderingModeIsSet = false;
}

utility::string_t SaveOptionsData::getFileName() const
{
    return m_FileName;
}


void SaveOptionsData::setFileName(utility::string_t value)
{
    m_FileName = value;
    m_FileNameIsSet = true;
}

bool SaveOptionsData::fileNameIsSet() const
{
    return m_FileNameIsSet;
}

void SaveOptionsData::unsetFileName()
{
    m_FileNameIsSet = false;
}

utility::string_t SaveOptionsData::getSaveFormat() const
{
    return m_SaveFormat;
}


void SaveOptionsData::setSaveFormat(utility::string_t value)
{
    m_SaveFormat = value;
    m_SaveFormatIsSet = true;
}

bool SaveOptionsData::saveFormatIsSet() const
{
    return m_SaveFormatIsSet;
}

void SaveOptionsData::unsetSaveFormat()
{
    m_SaveFormatIsSet = false;
}

bool SaveOptionsData::isUpdateFields() const
{
    return m_UpdateFields;
}


void SaveOptionsData::setUpdateFields(bool value)
{
    m_UpdateFields = value;
    m_UpdateFieldsIsSet = true;
}

bool SaveOptionsData::updateFieldsIsSet() const
{
    return m_UpdateFieldsIsSet;
}

void SaveOptionsData::unsetUpdateFields()
{
    m_UpdateFieldsIsSet = false;
}

bool SaveOptionsData::isUpdateLastPrintedProperty() const
{
    return m_UpdateLastPrintedProperty;
}


void SaveOptionsData::setUpdateLastPrintedProperty(bool value)
{
    m_UpdateLastPrintedProperty = value;
    m_UpdateLastPrintedPropertyIsSet = true;
}

bool SaveOptionsData::updateLastPrintedPropertyIsSet() const
{
    return m_UpdateLastPrintedPropertyIsSet;
}

void SaveOptionsData::unsetUpdateLastPrintedProperty()
{
    m_UpdateLastPrintedPropertyIsSet = false;
}

bool SaveOptionsData::isUpdateLastSavedTimeProperty() const
{
    return m_UpdateLastSavedTimeProperty;
}


void SaveOptionsData::setUpdateLastSavedTimeProperty(bool value)
{
    m_UpdateLastSavedTimeProperty = value;
    m_UpdateLastSavedTimePropertyIsSet = true;
}

bool SaveOptionsData::updateLastSavedTimePropertyIsSet() const
{
    return m_UpdateLastSavedTimePropertyIsSet;
}

void SaveOptionsData::unsetUpdateLastSavedTimeProperty()
{
    m_UpdateLastSavedTimePropertyIsSet = false;
}

bool SaveOptionsData::isUpdateSdtContent() const
{
    return m_UpdateSdtContent;
}


void SaveOptionsData::setUpdateSdtContent(bool value)
{
    m_UpdateSdtContent = value;
    m_UpdateSdtContentIsSet = true;
}

bool SaveOptionsData::updateSdtContentIsSet() const
{
    return m_UpdateSdtContentIsSet;
}

void SaveOptionsData::unsetUpdateSdtContent()
{
    m_UpdateSdtContentIsSet = false;
}

bool SaveOptionsData::isZipOutput() const
{
    return m_ZipOutput;
}


void SaveOptionsData::setZipOutput(bool value)
{
    m_ZipOutput = value;
    m_ZipOutputIsSet = true;
}

bool SaveOptionsData::zipOutputIsSet() const
{
    return m_ZipOutputIsSet;
}

void SaveOptionsData::unsetZipOutput()
{
    m_ZipOutputIsSet = false;
}

}
}
}
}
}
