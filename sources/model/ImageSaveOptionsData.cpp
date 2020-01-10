/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ImageSaveOptionsData.cpp">
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


#include "ImageSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

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
        val[_XPLATSTR("graphicsQualityOptions")] = ModelBase::toJson(m_GraphicsQualityOptions);
    }
    if(m_HorizontalResolutionIsSet)
    {
        val[_XPLATSTR("horizontalResolution")] = ModelBase::toJson(m_HorizontalResolution);
    }
    if(m_ImageBrightnessIsSet)
    {
        val[_XPLATSTR("imageBrightness")] = ModelBase::toJson(m_ImageBrightness);
    }
    if(m_ImageColorModeIsSet)
    {
        val[_XPLATSTR("imageColorMode")] = ModelBase::toJson(m_ImageColorMode);
    }
    if(m_ImageContrastIsSet)
    {
        val[_XPLATSTR("imageContrast")] = ModelBase::toJson(m_ImageContrast);
    }
    if(m_PaperColorIsSet)
    {
        val[_XPLATSTR("paperColor")] = ModelBase::toJson(m_PaperColor);
    }
    if(m_PixelFormatIsSet)
    {
        val[_XPLATSTR("pixelFormat")] = ModelBase::toJson(m_PixelFormat);
    }
    if(m_ResolutionIsSet)
    {
        val[_XPLATSTR("resolution")] = ModelBase::toJson(m_Resolution);
    }
    if(m_ScaleIsSet)
    {
        val[_XPLATSTR("scale")] = ModelBase::toJson(m_Scale);
    }
    if(m_UseAntiAliasingIsSet)
    {
        val[_XPLATSTR("useAntiAliasing")] = ModelBase::toJson(m_UseAntiAliasing);
    }
    if(m_UseGdiEmfRendererIsSet)
    {
        val[_XPLATSTR("useGdiEmfRenderer")] = ModelBase::toJson(m_UseGdiEmfRenderer);
    }
    if(m_UseHighQualityRenderingIsSet)
    {
        val[_XPLATSTR("useHighQualityRendering")] = ModelBase::toJson(m_UseHighQualityRendering);
    }
    if(m_VerticalResolutionIsSet)
    {
        val[_XPLATSTR("verticalResolution")] = ModelBase::toJson(m_VerticalResolution);
    }

    return val;
}

void ImageSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("graphicsQualityOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("graphicsQualityOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<GraphicsQualityOptionsData> newItem(new GraphicsQualityOptionsData());
            newItem->fromJson(fieldValue);
            setGraphicsQualityOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("horizontalResolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("horizontalResolution")];
        if(!fieldValue.is_null())
        {
            setHorizontalResolution(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imageBrightness")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imageBrightness")];
        if(!fieldValue.is_null())
        {
            setImageBrightness(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imageColorMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imageColorMode")];
        if(!fieldValue.is_null())
        {
            setImageColorMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imageContrast")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imageContrast")];
        if(!fieldValue.is_null())
        {
            setImageContrast(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("paperColor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("paperColor")];
        if(!fieldValue.is_null())
        {
            setPaperColor(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pixelFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pixelFormat")];
        if(!fieldValue.is_null())
        {
            setPixelFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resolution")];
        if(!fieldValue.is_null())
        {
            setResolution(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("scale")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("scale")];
        if(!fieldValue.is_null())
        {
            setScale(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("useAntiAliasing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("useAntiAliasing")];
        if(!fieldValue.is_null())
        {
            setUseAntiAliasing(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("useGdiEmfRenderer")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("useGdiEmfRenderer")];
        if(!fieldValue.is_null())
        {
            setUseGdiEmfRenderer(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("useHighQualityRendering")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("useHighQualityRendering")];
        if(!fieldValue.is_null())
        {
            setUseHighQualityRendering(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("verticalResolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("verticalResolution")];
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
    if(m_GraphicsQualityOptionsIsSet)
    {
        if (m_GraphicsQualityOptions.get())
        {
            m_GraphicsQualityOptions->toMultipart(multipart, _XPLATSTR("graphicsQualityOptions."));
        }
        
    }
    if(m_HorizontalResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("horizontalResolution"), m_HorizontalResolution));
    }
    if(m_ImageBrightnessIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imageBrightness"), m_ImageBrightness));
    }
    if(m_ImageColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imageColorMode"), m_ImageColorMode));
        
    }
    if(m_ImageContrastIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imageContrast"), m_ImageContrast));
    }
    if(m_PaperColorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("paperColor"), m_PaperColor));
        
    }
    if(m_PixelFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pixelFormat"), m_PixelFormat));
        
    }
    if(m_ResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resolution"), m_Resolution));
    }
    if(m_ScaleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("scale"), m_Scale));
    }
    if(m_UseAntiAliasingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("useAntiAliasing"), m_UseAntiAliasing));
    }
    if(m_UseGdiEmfRendererIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("useGdiEmfRenderer"), m_UseGdiEmfRenderer));
    }
    if(m_UseHighQualityRenderingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("useHighQualityRendering"), m_UseHighQualityRendering));
    }
    if(m_VerticalResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("verticalResolution"), m_VerticalResolution));
    }
}

void ImageSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("graphicsQualityOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("graphicsQualityOptions")))
        {
            std::shared_ptr<GraphicsQualityOptionsData> newItem(new GraphicsQualityOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("graphicsQualityOptions."));
            setGraphicsQualityOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("horizontalResolution")))
    {
        setHorizontalResolution(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("horizontalResolution"))));
    }
    if(multipart->hasContent(_XPLATSTR("imageBrightness")))
    {
        setImageBrightness(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("imageBrightness"))));
    }
    if(multipart->hasContent(_XPLATSTR("imageColorMode")))
    {
        setImageColorMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("imageColorMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("imageContrast")))
    {
        setImageContrast(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("imageContrast"))));
    }
    if(multipart->hasContent(_XPLATSTR("paperColor")))
    {
        setPaperColor(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("paperColor"))));
    }
    if(multipart->hasContent(_XPLATSTR("pixelFormat")))
    {
        setPixelFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("pixelFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("resolution")))
    {
        setResolution(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("resolution"))));
    }
    if(multipart->hasContent(_XPLATSTR("scale")))
    {
        setScale(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("scale"))));
    }
    if(multipart->hasContent(_XPLATSTR("useAntiAliasing")))
    {
        setUseAntiAliasing(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("useAntiAliasing"))));
    }
    if(multipart->hasContent(_XPLATSTR("useGdiEmfRenderer")))
    {
        setUseGdiEmfRenderer(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("useGdiEmfRenderer"))));
    }
    if(multipart->hasContent(_XPLATSTR("useHighQualityRendering")))
    {
        setUseHighQualityRendering(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("useHighQualityRendering"))));
    }
    if(multipart->hasContent(_XPLATSTR("verticalResolution")))
    {
        setVerticalResolution(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("verticalResolution"))));
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
}

