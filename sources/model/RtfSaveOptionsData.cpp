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
        val[_XPLATSTR("exportCompactSize")] = ModelBase::toJson(m_ExportCompactSize);
    }
    if(m_ExportImagesForOldReadersIsSet)
    {
        val[_XPLATSTR("exportImagesForOldReaders")] = ModelBase::toJson(m_ExportImagesForOldReaders);
    }
    if(m_PrettyFormatIsSet)
    {
        val[_XPLATSTR("prettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }

    return val;
}

void RtfSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("exportCompactSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportCompactSize")];
        if(!fieldValue.is_null())
        {
            setExportCompactSize(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportImagesForOldReaders")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportImagesForOldReaders")];
        if(!fieldValue.is_null())
        {
            setExportImagesForOldReaders(ModelBase::boolFromJson(fieldValue));
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

void RtfSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_ExportCompactSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportCompactSize"), m_ExportCompactSize));
    }
    if(m_ExportImagesForOldReadersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportImagesForOldReaders"), m_ExportImagesForOldReaders));
    }
    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("prettyFormat"), m_PrettyFormat));
    }
}

void RtfSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("exportCompactSize")))
    {
        setExportCompactSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportCompactSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportImagesForOldReaders")))
    {
        setExportImagesForOldReaders(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportImagesForOldReaders"))));
    }
    if(multipart->hasContent(_XPLATSTR("prettyFormat")))
    {
        setPrettyFormat(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("prettyFormat"))));
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

