/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="SvgSaveOptionsData.cpp">
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


#include "SvgSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

SvgSaveOptionsData::SvgSaveOptionsData()
{
    m_ExportEmbeddedImages = false;
    m_ExportEmbeddedImagesIsSet = false;
    m_FitToViewPort = false;
    m_FitToViewPortIsSet = false;
    m_ResourcesFolder = utility::conversions::to_string_t("");
    m_ResourcesFolderIsSet = false;
    m_ResourcesFolderAlias = utility::conversions::to_string_t("");
    m_ResourcesFolderAliasIsSet = false;
    m_ShowPageBorder = false;
    m_ShowPageBorderIsSet = false;
    m_TextOutputMode = utility::conversions::to_string_t("");
    m_TextOutputModeIsSet = false;
}

SvgSaveOptionsData::~SvgSaveOptionsData()
{
}

void SvgSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value SvgSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();

    if(m_ExportEmbeddedImagesIsSet)
    {
        val[_XPLATSTR("ExportEmbeddedImages")] = ModelBase::toJson(m_ExportEmbeddedImages);
    }
    if(m_FitToViewPortIsSet)
    {
        val[_XPLATSTR("FitToViewPort")] = ModelBase::toJson(m_FitToViewPort);
    }
    if(m_ResourcesFolderIsSet)
    {
        val[_XPLATSTR("ResourcesFolder")] = ModelBase::toJson(m_ResourcesFolder);
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        val[_XPLATSTR("ResourcesFolderAlias")] = ModelBase::toJson(m_ResourcesFolderAlias);
    }
    if(m_ShowPageBorderIsSet)
    {
        val[_XPLATSTR("ShowPageBorder")] = ModelBase::toJson(m_ShowPageBorder);
    }
    if(m_TextOutputModeIsSet)
    {
        val[_XPLATSTR("TextOutputMode")] = ModelBase::toJson(m_TextOutputMode);
    }

    return val;
}

void SvgSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("ExportEmbeddedImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportEmbeddedImages")];
        if(!fieldValue.is_null())
        {
            setExportEmbeddedImages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FitToViewPort")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FitToViewPort")];
        if(!fieldValue.is_null())
        {
            setFitToViewPort(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ResourcesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourcesFolder")];
        if(!fieldValue.is_null())
        {
            setResourcesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ResourcesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourcesFolderAlias")];
        if(!fieldValue.is_null())
        {
            setResourcesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ShowPageBorder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ShowPageBorder")];
        if(!fieldValue.is_null())
        {
            setShowPageBorder(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TextOutputMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextOutputMode")];
        if(!fieldValue.is_null())
        {
            setTextOutputMode(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void SvgSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_ExportEmbeddedImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportEmbeddedImages"), m_ExportEmbeddedImages));
    }
    if(m_FitToViewPortIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FitToViewPort"), m_FitToViewPort));
    }
    if(m_ResourcesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolder"), m_ResourcesFolder));
        
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolderAlias"), m_ResourcesFolderAlias));
        
    }
    if(m_ShowPageBorderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ShowPageBorder"), m_ShowPageBorder));
    }
    if(m_TextOutputModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextOutputMode"), m_TextOutputMode));
        
    }
}

void SvgSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("ExportEmbeddedImages")))
    {
        setExportEmbeddedImages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportEmbeddedImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("FitToViewPort")))
    {
        setFitToViewPort(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("FitToViewPort"))));
    }
    if(multipart->hasContent(_XPLATSTR("ResourcesFolder")))
    {
        setResourcesFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ResourcesFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("ResourcesFolderAlias")))
    {
        setResourcesFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ResourcesFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("ShowPageBorder")))
    {
        setShowPageBorder(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ShowPageBorder"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextOutputMode")))
    {
        setTextOutputMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextOutputMode"))));
    }
}

bool SvgSaveOptionsData::isExportEmbeddedImages() const
{
    return m_ExportEmbeddedImages;
}


void SvgSaveOptionsData::setExportEmbeddedImages(bool value)
{
    m_ExportEmbeddedImages = value;
    m_ExportEmbeddedImagesIsSet = true;
}
bool SvgSaveOptionsData::exportEmbeddedImagesIsSet() const
{
    return m_ExportEmbeddedImagesIsSet;
}

void SvgSaveOptionsData::unsetExportEmbeddedImages()
{
    m_ExportEmbeddedImagesIsSet = false;
}

bool SvgSaveOptionsData::isFitToViewPort() const
{
    return m_FitToViewPort;
}


void SvgSaveOptionsData::setFitToViewPort(bool value)
{
    m_FitToViewPort = value;
    m_FitToViewPortIsSet = true;
}
bool SvgSaveOptionsData::fitToViewPortIsSet() const
{
    return m_FitToViewPortIsSet;
}

void SvgSaveOptionsData::unsetFitToViewPort()
{
    m_FitToViewPortIsSet = false;
}

utility::string_t SvgSaveOptionsData::getResourcesFolder() const
{
    return m_ResourcesFolder;
}


void SvgSaveOptionsData::setResourcesFolder(utility::string_t value)
{
    m_ResourcesFolder = value;
    m_ResourcesFolderIsSet = true;
}
bool SvgSaveOptionsData::resourcesFolderIsSet() const
{
    return m_ResourcesFolderIsSet;
}

void SvgSaveOptionsData::unsetResourcesFolder()
{
    m_ResourcesFolderIsSet = false;
}

utility::string_t SvgSaveOptionsData::getResourcesFolderAlias() const
{
    return m_ResourcesFolderAlias;
}


void SvgSaveOptionsData::setResourcesFolderAlias(utility::string_t value)
{
    m_ResourcesFolderAlias = value;
    m_ResourcesFolderAliasIsSet = true;
}
bool SvgSaveOptionsData::resourcesFolderAliasIsSet() const
{
    return m_ResourcesFolderAliasIsSet;
}

void SvgSaveOptionsData::unsetResourcesFolderAlias()
{
    m_ResourcesFolderAliasIsSet = false;
}

bool SvgSaveOptionsData::isShowPageBorder() const
{
    return m_ShowPageBorder;
}


void SvgSaveOptionsData::setShowPageBorder(bool value)
{
    m_ShowPageBorder = value;
    m_ShowPageBorderIsSet = true;
}
bool SvgSaveOptionsData::showPageBorderIsSet() const
{
    return m_ShowPageBorderIsSet;
}

void SvgSaveOptionsData::unsetShowPageBorder()
{
    m_ShowPageBorderIsSet = false;
}

utility::string_t SvgSaveOptionsData::getTextOutputMode() const
{
    return m_TextOutputMode;
}


void SvgSaveOptionsData::setTextOutputMode(utility::string_t value)
{
    m_TextOutputMode = value;
    m_TextOutputModeIsSet = true;
}
bool SvgSaveOptionsData::textOutputModeIsSet() const
{
    return m_TextOutputModeIsSet;
}

void SvgSaveOptionsData::unsetTextOutputMode()
{
    m_TextOutputModeIsSet = false;
}

}
}
}
}
}

