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
        val[_XPLATSTR("exportEmbeddedImages")] = ModelBase::toJson(m_ExportEmbeddedImages);
    }
    if(m_FitToViewPortIsSet)
    {
        val[_XPLATSTR("fitToViewPort")] = ModelBase::toJson(m_FitToViewPort);
    }
    if(m_ResourcesFolderIsSet)
    {
        val[_XPLATSTR("resourcesFolder")] = ModelBase::toJson(m_ResourcesFolder);
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        val[_XPLATSTR("resourcesFolderAlias")] = ModelBase::toJson(m_ResourcesFolderAlias);
    }
    if(m_ShowPageBorderIsSet)
    {
        val[_XPLATSTR("showPageBorder")] = ModelBase::toJson(m_ShowPageBorder);
    }
    if(m_TextOutputModeIsSet)
    {
        val[_XPLATSTR("textOutputMode")] = ModelBase::toJson(m_TextOutputMode);
    }

    return val;
}

void SvgSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("exportEmbeddedImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportEmbeddedImages")];
        if(!fieldValue.is_null())
        {
            setExportEmbeddedImages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("fitToViewPort")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fitToViewPort")];
        if(!fieldValue.is_null())
        {
            setFitToViewPort(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resourcesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resourcesFolder")];
        if(!fieldValue.is_null())
        {
            setResourcesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resourcesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resourcesFolderAlias")];
        if(!fieldValue.is_null())
        {
            setResourcesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("showPageBorder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("showPageBorder")];
        if(!fieldValue.is_null())
        {
            setShowPageBorder(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("textOutputMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("textOutputMode")];
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
    if(m_JpegQualityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("jpegQuality"), m_JpegQuality));
    }
    if(m_MetafileRenderingOptionsIsSet)
    {
        if (m_MetafileRenderingOptions.get())
        {
            m_MetafileRenderingOptions->toMultipart(multipart, _XPLATSTR("metafileRenderingOptions."));
        }
        
    }
    if(m_NumeralFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("numeralFormat"), m_NumeralFormat));
        
    }
    if(m_OptimizeOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("optimizeOutput"), m_OptimizeOutput));
    }
    if(m_PageCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageCount"), m_PageCount));
    }
    if(m_PageIndexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageIndex"), m_PageIndex));
    }
    if(m_ExportEmbeddedImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportEmbeddedImages"), m_ExportEmbeddedImages));
    }
    if(m_FitToViewPortIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fitToViewPort"), m_FitToViewPort));
    }
    if(m_ResourcesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resourcesFolder"), m_ResourcesFolder));
        
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resourcesFolderAlias"), m_ResourcesFolderAlias));
        
    }
    if(m_ShowPageBorderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("showPageBorder"), m_ShowPageBorder));
    }
    if(m_TextOutputModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("textOutputMode"), m_TextOutputMode));
        
    }
}

void SvgSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("jpegQuality")))
    {
        setJpegQuality(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("jpegQuality"))));
    }
    if(multipart->hasContent(_XPLATSTR("metafileRenderingOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("metafileRenderingOptions")))
        {
            std::shared_ptr<MetafileRenderingOptionsData> newItem(new MetafileRenderingOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("metafileRenderingOptions."));
            setMetafileRenderingOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("numeralFormat")))
    {
        setNumeralFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("numeralFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("optimizeOutput")))
    {
        setOptimizeOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("optimizeOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageCount")))
    {
        setPageCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("pageCount"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageIndex")))
    {
        setPageIndex(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("pageIndex"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportEmbeddedImages")))
    {
        setExportEmbeddedImages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportEmbeddedImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("fitToViewPort")))
    {
        setFitToViewPort(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("fitToViewPort"))));
    }
    if(multipart->hasContent(_XPLATSTR("resourcesFolder")))
    {
        setResourcesFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("resourcesFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("resourcesFolderAlias")))
    {
        setResourcesFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("resourcesFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("showPageBorder")))
    {
        setShowPageBorder(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("showPageBorder"))));
    }
    if(multipart->hasContent(_XPLATSTR("textOutputMode")))
    {
        setTextOutputMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("textOutputMode"))));
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

