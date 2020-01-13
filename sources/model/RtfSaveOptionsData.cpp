/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="RtfSaveOptionsData.cpp">
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


#include "RtfSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("ExportCompactSize")] = ModelBase::toJson(m_ExportCompactSize);
    }
    if(m_ExportImagesForOldReadersIsSet)
    {
        val[_XPLATSTR("ExportImagesForOldReaders")] = ModelBase::toJson(m_ExportImagesForOldReaders);
    }
    if(m_PrettyFormatIsSet)
    {
        val[_XPLATSTR("PrettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }

    return val;
}

void RtfSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("ExportCompactSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportCompactSize")];
        if(!fieldValue.is_null())
        {
            setExportCompactSize(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportImagesForOldReaders")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportImagesForOldReaders")];
        if(!fieldValue.is_null())
        {
            setExportImagesForOldReaders(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PrettyFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PrettyFormat")];
        if(!fieldValue.is_null())
        {
            setPrettyFormat(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void RtfSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ColorMode"), m_ColorMode));
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SaveFormat"), m_SaveFormat));
        
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FileName"), m_FileName));
        
    }
    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DmlRenderingMode"), m_DmlRenderingMode));
        
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
        
    }
    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ZipOutput"), m_ZipOutput));
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }
    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateSdtContent"), m_UpdateSdtContent));
    }
    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateFields"), m_UpdateFields));
    }
    if(m_ExportCompactSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportCompactSize"), m_ExportCompactSize));
    }
    if(m_ExportImagesForOldReadersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportImagesForOldReaders"), m_ExportImagesForOldReaders));
    }
    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PrettyFormat"), m_PrettyFormat));
    }
}

void RtfSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("ColorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ColorMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("SaveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("SaveFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("FileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FileName"))));
    }
    if(multipart->hasContent(_XPLATSTR("DmlRenderingMode")))
    {
        setDmlRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DmlRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("DmlEffectsRenderingMode")))
    {
        setDmlEffectsRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DmlEffectsRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("ZipOutput")))
    {
        setZipOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ZipOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("UpdateLastSavedTimeProperty")))
    {
        setUpdateLastSavedTimeProperty(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UpdateLastSavedTimeProperty"))));
    }
    if(multipart->hasContent(_XPLATSTR("UpdateSdtContent")))
    {
        setUpdateSdtContent(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UpdateSdtContent"))));
    }
    if(multipart->hasContent(_XPLATSTR("UpdateFields")))
    {
        setUpdateFields(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UpdateFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportCompactSize")))
    {
        setExportCompactSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportCompactSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportImagesForOldReaders")))
    {
        setExportImagesForOldReaders(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportImagesForOldReaders"))));
    }
    if(multipart->hasContent(_XPLATSTR("PrettyFormat")))
    {
        setPrettyFormat(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("PrettyFormat"))));
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
}

