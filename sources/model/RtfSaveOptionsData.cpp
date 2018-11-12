/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RtfSaveOptionsData.cpp">
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


#include "RtfSaveOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

RtfSaveOptionsData::RtfSaveOptionsData()
{
    m_ExportCompactSize = false;
    m_ExportCompactSizeIsSet = false;
    m_ExportImagesForOldReaders = false;
    m_ExportImagesForOldReadersIsSet = false;
    m_PrettyFormat = false;
    m_PrettyFormatIsSet = false;
}

RtfSaveOptionsData::~RtfSaveOptionsData()
{
}

void RtfSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value RtfSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_ExportCompactSizeIsSet)
    {
        val[utility::conversions::to_string_t("ExportCompactSize")] = ModelBase::toJson(m_ExportCompactSize);
    }
    if(m_ExportImagesForOldReadersIsSet)
    {
        val[utility::conversions::to_string_t("ExportImagesForOldReaders")] = ModelBase::toJson(m_ExportImagesForOldReaders);
    }
    if(m_PrettyFormatIsSet)
    {
        val[utility::conversions::to_string_t("PrettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }

    return val;
}

void RtfSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("ExportCompactSize")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ExportCompactSize")];
        if(!fieldValue.is_null())
        {
            setExportCompactSize(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ExportImagesForOldReaders")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ExportImagesForOldReaders")];
        if(!fieldValue.is_null())
        {
            setExportImagesForOldReaders(ModelBase::boolFromJson(fieldValue));
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

void RtfSaveOptionsData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_ExportCompactSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ExportCompactSize"), m_ExportCompactSize));
    }
    if(m_ExportImagesForOldReadersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ExportImagesForOldReaders"), m_ExportImagesForOldReaders));
    }
    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PrettyFormat"), m_PrettyFormat));
    }
}

void RtfSaveOptionsData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("ExportCompactSize")))
    {
        setExportCompactSize(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ExportCompactSize"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ExportImagesForOldReaders")))
    {
        setExportImagesForOldReaders(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ExportImagesForOldReaders"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PrettyFormat")))
    {
        setPrettyFormat(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PrettyFormat"))));
    }
}

bool RtfSaveOptionsData::isExportCompactSize() const
{
    return m_ExportCompactSize;
}


void RtfSaveOptionsData::setExportCompactSize(bool value)
{
    m_ExportCompactSize = value;
    m_ExportCompactSizeIsSet = true;
}
bool RtfSaveOptionsData::exportCompactSizeIsSet() const
{
    return m_ExportCompactSizeIsSet;
}

void RtfSaveOptionsData::unsetExportCompactSize()
{
    m_ExportCompactSizeIsSet = false;
}

bool RtfSaveOptionsData::isExportImagesForOldReaders() const
{
    return m_ExportImagesForOldReaders;
}


void RtfSaveOptionsData::setExportImagesForOldReaders(bool value)
{
    m_ExportImagesForOldReaders = value;
    m_ExportImagesForOldReadersIsSet = true;
}
bool RtfSaveOptionsData::exportImagesForOldReadersIsSet() const
{
    return m_ExportImagesForOldReadersIsSet;
}

void RtfSaveOptionsData::unsetExportImagesForOldReaders()
{
    m_ExportImagesForOldReadersIsSet = false;
}

bool RtfSaveOptionsData::isPrettyFormat() const
{
    return m_PrettyFormat;
}


void RtfSaveOptionsData::setPrettyFormat(bool value)
{
    m_PrettyFormat = value;
    m_PrettyFormatIsSet = true;
}
bool RtfSaveOptionsData::prettyFormatIsSet() const
{
    return m_PrettyFormatIsSet;
}

void RtfSaveOptionsData::unsetPrettyFormat()
{
    m_PrettyFormatIsSet = false;
}

}
}
}
}

