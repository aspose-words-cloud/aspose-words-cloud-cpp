/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XpsSaveOptionsData.cpp">
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


#include "XpsSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

XpsSaveOptionsData::XpsSaveOptionsData()
{
    m_BookmarksOutlineLevel = 0;
    m_BookmarksOutlineLevelIsSet = false;
    m_HeadingsOutlineLevels = 0;
    m_HeadingsOutlineLevelsIsSet = false;
    m_OutlineOptionsIsSet = false;
    m_UseBookFoldPrintingSettings = false;
    m_UseBookFoldPrintingSettingsIsSet = false;
}

XpsSaveOptionsData::~XpsSaveOptionsData()
{
}

void XpsSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value XpsSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();

    if(m_BookmarksOutlineLevelIsSet)
    {
        val[_XPLATSTR("BookmarksOutlineLevel")] = ModelBase::toJson(m_BookmarksOutlineLevel);
    }
    if(m_HeadingsOutlineLevelsIsSet)
    {
        val[_XPLATSTR("HeadingsOutlineLevels")] = ModelBase::toJson(m_HeadingsOutlineLevels);
    }
    if(m_OutlineOptionsIsSet)
    {
        val[_XPLATSTR("OutlineOptions")] = ModelBase::toJson(m_OutlineOptions);
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        val[_XPLATSTR("UseBookFoldPrintingSettings")] = ModelBase::toJson(m_UseBookFoldPrintingSettings);
    }

    return val;
}

void XpsSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("BookmarksOutlineLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BookmarksOutlineLevel")];
        if(!fieldValue.is_null())
        {
            setBookmarksOutlineLevel(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("HeadingsOutlineLevels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HeadingsOutlineLevels")];
        if(!fieldValue.is_null())
        {
            setHeadingsOutlineLevels(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OutlineOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OutlineOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromJson(fieldValue);
            setOutlineOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("UseBookFoldPrintingSettings")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseBookFoldPrintingSettings")];
        if(!fieldValue.is_null())
        {
            setUseBookFoldPrintingSettings(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void XpsSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

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
    if(m_ColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ColorMode"), m_ColorMode));
        
    }
    if(m_JpegQualityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("JpegQuality"), m_JpegQuality));
    }
    if(m_MetafileRenderingOptionsIsSet)
    {
        if (m_MetafileRenderingOptions.get())
        {
            m_MetafileRenderingOptions->toMultipart(multipart, _XPLATSTR("MetafileRenderingOptions."));
        }
        
    }
    if(m_NumeralFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NumeralFormat"), m_NumeralFormat));
        
    }
    if(m_OptimizeOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OptimizeOutput"), m_OptimizeOutput));
    }
    if(m_PageCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageCount"), m_PageCount));
    }
    if(m_PageIndexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageIndex"), m_PageIndex));
    }
    if(m_BookmarksOutlineLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BookmarksOutlineLevel"), m_BookmarksOutlineLevel));
    }
    if(m_HeadingsOutlineLevelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HeadingsOutlineLevels"), m_HeadingsOutlineLevels));
    }
    if(m_OutlineOptionsIsSet)
    {
        if (m_OutlineOptions.get())
        {
            m_OutlineOptions->toMultipart(multipart, _XPLATSTR("OutlineOptions."));
        }
        
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseBookFoldPrintingSettings"), m_UseBookFoldPrintingSettings));
    }
}

void XpsSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
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
    if(multipart->hasContent(_XPLATSTR("ColorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ColorMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("JpegQuality")))
    {
        setJpegQuality(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("JpegQuality"))));
    }
    if(multipart->hasContent(_XPLATSTR("MetafileRenderingOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("MetafileRenderingOptions")))
        {
            std::shared_ptr<MetafileRenderingOptionsData> newItem(new MetafileRenderingOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("MetafileRenderingOptions."));
            setMetafileRenderingOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("NumeralFormat")))
    {
        setNumeralFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NumeralFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("OptimizeOutput")))
    {
        setOptimizeOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("OptimizeOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("PageCount")))
    {
        setPageCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("PageCount"))));
    }
    if(multipart->hasContent(_XPLATSTR("PageIndex")))
    {
        setPageIndex(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("PageIndex"))));
    }
    if(multipart->hasContent(_XPLATSTR("BookmarksOutlineLevel")))
    {
        setBookmarksOutlineLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("BookmarksOutlineLevel"))));
    }
    if(multipart->hasContent(_XPLATSTR("HeadingsOutlineLevels")))
    {
        setHeadingsOutlineLevels(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("HeadingsOutlineLevels"))));
    }
    if(multipart->hasContent(_XPLATSTR("OutlineOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("OutlineOptions")))
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("OutlineOptions."));
            setOutlineOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("UseBookFoldPrintingSettings")))
    {
        setUseBookFoldPrintingSettings(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UseBookFoldPrintingSettings"))));
    }
}

int32_t XpsSaveOptionsData::getBookmarksOutlineLevel() const
{
    return m_BookmarksOutlineLevel;
}


void XpsSaveOptionsData::setBookmarksOutlineLevel(int32_t value)
{
    m_BookmarksOutlineLevel = value;
    m_BookmarksOutlineLevelIsSet = true;
}
bool XpsSaveOptionsData::bookmarksOutlineLevelIsSet() const
{
    return m_BookmarksOutlineLevelIsSet;
}

void XpsSaveOptionsData::unsetBookmarksOutlineLevel()
{
    m_BookmarksOutlineLevelIsSet = false;
}

int32_t XpsSaveOptionsData::getHeadingsOutlineLevels() const
{
    return m_HeadingsOutlineLevels;
}


void XpsSaveOptionsData::setHeadingsOutlineLevels(int32_t value)
{
    m_HeadingsOutlineLevels = value;
    m_HeadingsOutlineLevelsIsSet = true;
}
bool XpsSaveOptionsData::headingsOutlineLevelsIsSet() const
{
    return m_HeadingsOutlineLevelsIsSet;
}

void XpsSaveOptionsData::unsetHeadingsOutlineLevels()
{
    m_HeadingsOutlineLevelsIsSet = false;
}

std::shared_ptr<OutlineOptionsData> XpsSaveOptionsData::getOutlineOptions() const
{
    return m_OutlineOptions;
}


void XpsSaveOptionsData::setOutlineOptions(std::shared_ptr<OutlineOptionsData> value)
{
    m_OutlineOptions = value;
    m_OutlineOptionsIsSet = true;
}
bool XpsSaveOptionsData::outlineOptionsIsSet() const
{
    return m_OutlineOptionsIsSet;
}

void XpsSaveOptionsData::unsetOutlineOptions()
{
    m_OutlineOptionsIsSet = false;
}

bool XpsSaveOptionsData::isUseBookFoldPrintingSettings() const
{
    return m_UseBookFoldPrintingSettings;
}


void XpsSaveOptionsData::setUseBookFoldPrintingSettings(bool value)
{
    m_UseBookFoldPrintingSettings = value;
    m_UseBookFoldPrintingSettingsIsSet = true;
}
bool XpsSaveOptionsData::useBookFoldPrintingSettingsIsSet() const
{
    return m_UseBookFoldPrintingSettingsIsSet;
}

void XpsSaveOptionsData::unsetUseBookFoldPrintingSettings()
{
    m_UseBookFoldPrintingSettingsIsSet = false;
}

}
}
}
}
}

