/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="XpsSaveOptionsData.cpp">
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


#include "XpsSaveOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[utility::conversions::to_string_t("BookmarksOutlineLevel")] = ModelBase::toJson(m_BookmarksOutlineLevel);
    }
    if(m_HeadingsOutlineLevelsIsSet)
    {
        val[utility::conversions::to_string_t("HeadingsOutlineLevels")] = ModelBase::toJson(m_HeadingsOutlineLevels);
    }
    if(m_OutlineOptionsIsSet)
    {
        val[utility::conversions::to_string_t("OutlineOptions")] = ModelBase::toJson(m_OutlineOptions);
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        val[utility::conversions::to_string_t("UseBookFoldPrintingSettings")] = ModelBase::toJson(m_UseBookFoldPrintingSettings);
    }

    return val;
}

void XpsSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("BookmarksOutlineLevel")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("BookmarksOutlineLevel")];
        if(!fieldValue.is_null())
        {
            setBookmarksOutlineLevel(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("HeadingsOutlineLevels")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("HeadingsOutlineLevels")];
        if(!fieldValue.is_null())
        {
            setHeadingsOutlineLevels(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("OutlineOptions")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("OutlineOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromJson(fieldValue);
            setOutlineOptions( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("UseBookFoldPrintingSettings")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("UseBookFoldPrintingSettings")];
        if(!fieldValue.is_null())
        {
            setUseBookFoldPrintingSettings(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void XpsSaveOptionsData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
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
    if(m_JpegQualityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("JpegQuality"), m_JpegQuality));
    }
    if(m_MetafileRenderingOptionsIsSet)
    {
        if (m_MetafileRenderingOptions.get())
        {
            m_MetafileRenderingOptions->toMultipart(multipart, utility::conversions::to_string_t("MetafileRenderingOptions."));
        }
        
    }
    if(m_NumeralFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("NumeralFormat"), m_NumeralFormat));
        
    }
    if(m_OptimizeOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("OptimizeOutput"), m_OptimizeOutput));
    }
    if(m_PageCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageCount"), m_PageCount));
    }
    if(m_PageIndexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageIndex"), m_PageIndex));
    }
    if(m_BookmarksOutlineLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("BookmarksOutlineLevel"), m_BookmarksOutlineLevel));
    }
    if(m_HeadingsOutlineLevelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("HeadingsOutlineLevels"), m_HeadingsOutlineLevels));
    }
    if(m_OutlineOptionsIsSet)
    {
        if (m_OutlineOptions.get())
        {
            m_OutlineOptions->toMultipart(multipart, utility::conversions::to_string_t("OutlineOptions."));
        }
        
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UseBookFoldPrintingSettings"), m_UseBookFoldPrintingSettings));
    }
}

void XpsSaveOptionsData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(utility::conversions::to_string_t("JpegQuality")))
    {
        setJpegQuality(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("JpegQuality"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("MetafileRenderingOptions")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("MetafileRenderingOptions")))
        {
            std::shared_ptr<MetafileRenderingOptionsData> newItem(new MetafileRenderingOptionsData());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("MetafileRenderingOptions."));
            setMetafileRenderingOptions( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("NumeralFormat")))
    {
        setNumeralFormat(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("NumeralFormat"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("OptimizeOutput")))
    {
        setOptimizeOutput(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("OptimizeOutput"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PageCount")))
    {
        setPageCount(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageCount"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PageIndex")))
    {
        setPageIndex(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageIndex"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("BookmarksOutlineLevel")))
    {
        setBookmarksOutlineLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("BookmarksOutlineLevel"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("HeadingsOutlineLevels")))
    {
        setHeadingsOutlineLevels(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("HeadingsOutlineLevels"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("OutlineOptions")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("OutlineOptions")))
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("OutlineOptions."));
            setOutlineOptions( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UseBookFoldPrintingSettings")))
    {
        setUseBookFoldPrintingSettings(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UseBookFoldPrintingSettings"))));
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

