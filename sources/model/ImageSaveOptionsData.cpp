/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ImageSaveOptionsData.cpp">
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


#include "ImageSaveOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

ImageSaveOptionsData::ImageSaveOptionsData()
{
    m_GraphicsQualityOptionsIsSet = false;
    m_HorizontalResolution = 0.0;
    m_HorizontalResolutionIsSet = false;
    m_ImageBrightness = 0.0;
    m_ImageBrightnessIsSet = false;
    m_ImageColorMode = utility::conversions::to_string_t("");
    m_ImageColorModeIsSet = false;
    m_ImageContrast = 0.0;
    m_ImageContrastIsSet = false;
    m_PaperColor = utility::conversions::to_string_t("");
    m_PaperColorIsSet = false;
    m_PixelFormat = utility::conversions::to_string_t("");
    m_PixelFormatIsSet = false;
    m_Resolution = 0.0;
    m_ResolutionIsSet = false;
    m_Scale = 0.0;
    m_ScaleIsSet = false;
    m_UseAntiAliasing = false;
    m_UseAntiAliasingIsSet = false;
    m_UseGdiEmfRenderer = false;
    m_UseGdiEmfRendererIsSet = false;
    m_UseHighQualityRendering = false;
    m_UseHighQualityRenderingIsSet = false;
    m_VerticalResolution = 0.0;
    m_VerticalResolutionIsSet = false;
}

ImageSaveOptionsData::~ImageSaveOptionsData()
{
}

void ImageSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value ImageSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();

    if(m_GraphicsQualityOptionsIsSet)
    {
        val[_XPLATSTR("GraphicsQualityOptions")] = ModelBase::toJson(m_GraphicsQualityOptions);
    }
    if(m_HorizontalResolutionIsSet)
    {
        val[_XPLATSTR("HorizontalResolution")] = ModelBase::toJson(m_HorizontalResolution);
    }
    if(m_ImageBrightnessIsSet)
    {
        val[_XPLATSTR("ImageBrightness")] = ModelBase::toJson(m_ImageBrightness);
    }
    if(m_ImageColorModeIsSet)
    {
        val[_XPLATSTR("ImageColorMode")] = ModelBase::toJson(m_ImageColorMode);
    }
    if(m_ImageContrastIsSet)
    {
        val[_XPLATSTR("ImageContrast")] = ModelBase::toJson(m_ImageContrast);
    }
    if(m_PaperColorIsSet)
    {
        val[_XPLATSTR("PaperColor")] = ModelBase::toJson(m_PaperColor);
    }
    if(m_PixelFormatIsSet)
    {
        val[_XPLATSTR("PixelFormat")] = ModelBase::toJson(m_PixelFormat);
    }
    if(m_ResolutionIsSet)
    {
        val[_XPLATSTR("Resolution")] = ModelBase::toJson(m_Resolution);
    }
    if(m_ScaleIsSet)
    {
        val[_XPLATSTR("Scale")] = ModelBase::toJson(m_Scale);
    }
    if(m_UseAntiAliasingIsSet)
    {
        val[_XPLATSTR("UseAntiAliasing")] = ModelBase::toJson(m_UseAntiAliasing);
    }
    if(m_UseGdiEmfRendererIsSet)
    {
        val[_XPLATSTR("UseGdiEmfRenderer")] = ModelBase::toJson(m_UseGdiEmfRenderer);
    }
    if(m_UseHighQualityRenderingIsSet)
    {
        val[_XPLATSTR("UseHighQualityRendering")] = ModelBase::toJson(m_UseHighQualityRendering);
    }
    if(m_VerticalResolutionIsSet)
    {
        val[_XPLATSTR("VerticalResolution")] = ModelBase::toJson(m_VerticalResolution);
    }

    return val;
}

void ImageSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("GraphicsQualityOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("GraphicsQualityOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<GraphicsQualityOptionsData> newItem(new GraphicsQualityOptionsData());
            newItem->fromJson(fieldValue);
            setGraphicsQualityOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("HorizontalResolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HorizontalResolution")];
        if(!fieldValue.is_null())
        {
            setHorizontalResolution(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImageBrightness")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImageBrightness")];
        if(!fieldValue.is_null())
        {
            setImageBrightness(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImageColorMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImageColorMode")];
        if(!fieldValue.is_null())
        {
            setImageColorMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImageContrast")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImageContrast")];
        if(!fieldValue.is_null())
        {
            setImageContrast(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PaperColor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PaperColor")];
        if(!fieldValue.is_null())
        {
            setPaperColor(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PixelFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PixelFormat")];
        if(!fieldValue.is_null())
        {
            setPixelFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Resolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Resolution")];
        if(!fieldValue.is_null())
        {
            setResolution(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Scale")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Scale")];
        if(!fieldValue.is_null())
        {
            setScale(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UseAntiAliasing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseAntiAliasing")];
        if(!fieldValue.is_null())
        {
            setUseAntiAliasing(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UseGdiEmfRenderer")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseGdiEmfRenderer")];
        if(!fieldValue.is_null())
        {
            setUseGdiEmfRenderer(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UseHighQualityRendering")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseHighQualityRendering")];
        if(!fieldValue.is_null())
        {
            setUseHighQualityRendering(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("VerticalResolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("VerticalResolution")];
        if(!fieldValue.is_null())
        {
            setVerticalResolution(ModelBase::doubleFromJson(fieldValue));
        }
    }
}

void ImageSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_GraphicsQualityOptionsIsSet)
    {
        if (m_GraphicsQualityOptions.get())
        {
            m_GraphicsQualityOptions->toMultipart(multipart, _XPLATSTR("GraphicsQualityOptions."));
        }
        
    }
    if(m_HorizontalResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HorizontalResolution"), m_HorizontalResolution));
    }
    if(m_ImageBrightnessIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImageBrightness"), m_ImageBrightness));
    }
    if(m_ImageColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImageColorMode"), m_ImageColorMode));
        
    }
    if(m_ImageContrastIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImageContrast"), m_ImageContrast));
    }
    if(m_PaperColorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PaperColor"), m_PaperColor));
        
    }
    if(m_PixelFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PixelFormat"), m_PixelFormat));
        
    }
    if(m_ResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Resolution"), m_Resolution));
    }
    if(m_ScaleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Scale"), m_Scale));
    }
    if(m_UseAntiAliasingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseAntiAliasing"), m_UseAntiAliasing));
    }
    if(m_UseGdiEmfRendererIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseGdiEmfRenderer"), m_UseGdiEmfRenderer));
    }
    if(m_UseHighQualityRenderingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseHighQualityRendering"), m_UseHighQualityRendering));
    }
    if(m_VerticalResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("VerticalResolution"), m_VerticalResolution));
    }
}

void ImageSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("GraphicsQualityOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("GraphicsQualityOptions")))
        {
            std::shared_ptr<GraphicsQualityOptionsData> newItem(new GraphicsQualityOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("GraphicsQualityOptions."));
            setGraphicsQualityOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("HorizontalResolution")))
    {
        setHorizontalResolution(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("HorizontalResolution"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImageBrightness")))
    {
        setImageBrightness(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("ImageBrightness"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImageColorMode")))
    {
        setImageColorMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ImageColorMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImageContrast")))
    {
        setImageContrast(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("ImageContrast"))));
    }
    if(multipart->hasContent(_XPLATSTR("PaperColor")))
    {
        setPaperColor(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("PaperColor"))));
    }
    if(multipart->hasContent(_XPLATSTR("PixelFormat")))
    {
        setPixelFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("PixelFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("Resolution")))
    {
        setResolution(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("Resolution"))));
    }
    if(multipart->hasContent(_XPLATSTR("Scale")))
    {
        setScale(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("Scale"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseAntiAliasing")))
    {
        setUseAntiAliasing(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UseAntiAliasing"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseGdiEmfRenderer")))
    {
        setUseGdiEmfRenderer(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UseGdiEmfRenderer"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseHighQualityRendering")))
    {
        setUseHighQualityRendering(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UseHighQualityRendering"))));
    }
    if(multipart->hasContent(_XPLATSTR("VerticalResolution")))
    {
        setVerticalResolution(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("VerticalResolution"))));
    }
}

std::shared_ptr<GraphicsQualityOptionsData> ImageSaveOptionsData::getGraphicsQualityOptions() const
{
    return m_GraphicsQualityOptions;
}


void ImageSaveOptionsData::setGraphicsQualityOptions(std::shared_ptr<GraphicsQualityOptionsData> value)
{
    m_GraphicsQualityOptions = value;
    m_GraphicsQualityOptionsIsSet = true;
}
bool ImageSaveOptionsData::graphicsQualityOptionsIsSet() const
{
    return m_GraphicsQualityOptionsIsSet;
}

void ImageSaveOptionsData::unsetGraphicsQualityOptions()
{
    m_GraphicsQualityOptionsIsSet = false;
}

double ImageSaveOptionsData::getHorizontalResolution() const
{
    return m_HorizontalResolution;
}


void ImageSaveOptionsData::setHorizontalResolution(double value)
{
    m_HorizontalResolution = value;
    m_HorizontalResolutionIsSet = true;
}
bool ImageSaveOptionsData::horizontalResolutionIsSet() const
{
    return m_HorizontalResolutionIsSet;
}

void ImageSaveOptionsData::unsetHorizontalResolution()
{
    m_HorizontalResolutionIsSet = false;
}

double ImageSaveOptionsData::getImageBrightness() const
{
    return m_ImageBrightness;
}


void ImageSaveOptionsData::setImageBrightness(double value)
{
    m_ImageBrightness = value;
    m_ImageBrightnessIsSet = true;
}
bool ImageSaveOptionsData::imageBrightnessIsSet() const
{
    return m_ImageBrightnessIsSet;
}

void ImageSaveOptionsData::unsetImageBrightness()
{
    m_ImageBrightnessIsSet = false;
}

utility::string_t ImageSaveOptionsData::getImageColorMode() const
{
    return m_ImageColorMode;
}


void ImageSaveOptionsData::setImageColorMode(utility::string_t value)
{
    m_ImageColorMode = value;
    m_ImageColorModeIsSet = true;
}
bool ImageSaveOptionsData::imageColorModeIsSet() const
{
    return m_ImageColorModeIsSet;
}

void ImageSaveOptionsData::unsetImageColorMode()
{
    m_ImageColorModeIsSet = false;
}

double ImageSaveOptionsData::getImageContrast() const
{
    return m_ImageContrast;
}


void ImageSaveOptionsData::setImageContrast(double value)
{
    m_ImageContrast = value;
    m_ImageContrastIsSet = true;
}
bool ImageSaveOptionsData::imageContrastIsSet() const
{
    return m_ImageContrastIsSet;
}

void ImageSaveOptionsData::unsetImageContrast()
{
    m_ImageContrastIsSet = false;
}

utility::string_t ImageSaveOptionsData::getPaperColor() const
{
    return m_PaperColor;
}


void ImageSaveOptionsData::setPaperColor(utility::string_t value)
{
    m_PaperColor = value;
    m_PaperColorIsSet = true;
}
bool ImageSaveOptionsData::paperColorIsSet() const
{
    return m_PaperColorIsSet;
}

void ImageSaveOptionsData::unsetPaperColor()
{
    m_PaperColorIsSet = false;
}

utility::string_t ImageSaveOptionsData::getPixelFormat() const
{
    return m_PixelFormat;
}


void ImageSaveOptionsData::setPixelFormat(utility::string_t value)
{
    m_PixelFormat = value;
    m_PixelFormatIsSet = true;
}
bool ImageSaveOptionsData::pixelFormatIsSet() const
{
    return m_PixelFormatIsSet;
}

void ImageSaveOptionsData::unsetPixelFormat()
{
    m_PixelFormatIsSet = false;
}

double ImageSaveOptionsData::getResolution() const
{
    return m_Resolution;
}


void ImageSaveOptionsData::setResolution(double value)
{
    m_Resolution = value;
    m_ResolutionIsSet = true;
}
bool ImageSaveOptionsData::resolutionIsSet() const
{
    return m_ResolutionIsSet;
}

void ImageSaveOptionsData::unsetResolution()
{
    m_ResolutionIsSet = false;
}

double ImageSaveOptionsData::getScale() const
{
    return m_Scale;
}


void ImageSaveOptionsData::setScale(double value)
{
    m_Scale = value;
    m_ScaleIsSet = true;
}
bool ImageSaveOptionsData::scaleIsSet() const
{
    return m_ScaleIsSet;
}

void ImageSaveOptionsData::unsetScale()
{
    m_ScaleIsSet = false;
}

bool ImageSaveOptionsData::isUseAntiAliasing() const
{
    return m_UseAntiAliasing;
}


void ImageSaveOptionsData::setUseAntiAliasing(bool value)
{
    m_UseAntiAliasing = value;
    m_UseAntiAliasingIsSet = true;
}
bool ImageSaveOptionsData::useAntiAliasingIsSet() const
{
    return m_UseAntiAliasingIsSet;
}

void ImageSaveOptionsData::unsetUseAntiAliasing()
{
    m_UseAntiAliasingIsSet = false;
}

bool ImageSaveOptionsData::isUseGdiEmfRenderer() const
{
    return m_UseGdiEmfRenderer;
}


void ImageSaveOptionsData::setUseGdiEmfRenderer(bool value)
{
    m_UseGdiEmfRenderer = value;
    m_UseGdiEmfRendererIsSet = true;
}
bool ImageSaveOptionsData::useGdiEmfRendererIsSet() const
{
    return m_UseGdiEmfRendererIsSet;
}

void ImageSaveOptionsData::unsetUseGdiEmfRenderer()
{
    m_UseGdiEmfRendererIsSet = false;
}

bool ImageSaveOptionsData::isUseHighQualityRendering() const
{
    return m_UseHighQualityRendering;
}


void ImageSaveOptionsData::setUseHighQualityRendering(bool value)
{
    m_UseHighQualityRendering = value;
    m_UseHighQualityRenderingIsSet = true;
}
bool ImageSaveOptionsData::useHighQualityRenderingIsSet() const
{
    return m_UseHighQualityRenderingIsSet;
}

void ImageSaveOptionsData::unsetUseHighQualityRendering()
{
    m_UseHighQualityRenderingIsSet = false;
}

double ImageSaveOptionsData::getVerticalResolution() const
{
    return m_VerticalResolution;
}


void ImageSaveOptionsData::setVerticalResolution(double value)
{
    m_VerticalResolution = value;
    m_VerticalResolutionIsSet = true;
}
bool ImageSaveOptionsData::verticalResolutionIsSet() const
{
    return m_VerticalResolutionIsSet;
}

void ImageSaveOptionsData::unsetVerticalResolution()
{
    m_VerticalResolutionIsSet = false;
}

}
}
}
}

