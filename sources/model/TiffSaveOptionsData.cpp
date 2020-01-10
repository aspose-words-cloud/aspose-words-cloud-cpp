/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TiffSaveOptionsData.cpp">
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


#include "TiffSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TiffSaveOptionsData::TiffSaveOptionsData()
{
    m_ThresholdForFloydSteinbergDithering = 0;
    m_ThresholdForFloydSteinbergDitheringIsSet = false;
    m_TiffBinarizationMethod = utility::conversions::to_string_t("");
    m_TiffBinarizationMethodIsSet = false;
    m_TiffCompression = utility::conversions::to_string_t("");
    m_TiffCompressionIsSet = false;
}

TiffSaveOptionsData::~TiffSaveOptionsData()
{
}

void TiffSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value TiffSaveOptionsData::toJson() const
{
    web::json::value val = this->ImageSaveOptionsData::toJson();

    if(m_ThresholdForFloydSteinbergDitheringIsSet)
    {
        val[_XPLATSTR("thresholdForFloydSteinbergDithering")] = ModelBase::toJson(m_ThresholdForFloydSteinbergDithering);
    }
    if(m_TiffBinarizationMethodIsSet)
    {
        val[_XPLATSTR("tiffBinarizationMethod")] = ModelBase::toJson(m_TiffBinarizationMethod);
    }
    if(m_TiffCompressionIsSet)
    {
        val[_XPLATSTR("tiffCompression")] = ModelBase::toJson(m_TiffCompression);
    }

    return val;
}

void TiffSaveOptionsData::fromJson(web::json::value& val)
{
    this->ImageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("thresholdForFloydSteinbergDithering")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("thresholdForFloydSteinbergDithering")];
        if(!fieldValue.is_null())
        {
            setThresholdForFloydSteinbergDithering(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("tiffBinarizationMethod")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("tiffBinarizationMethod")];
        if(!fieldValue.is_null())
        {
            setTiffBinarizationMethod(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("tiffCompression")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("tiffCompression")];
        if(!fieldValue.is_null())
        {
            setTiffCompression(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void TiffSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_ThresholdForFloydSteinbergDitheringIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("thresholdForFloydSteinbergDithering"), m_ThresholdForFloydSteinbergDithering));
    }
    if(m_TiffBinarizationMethodIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("tiffBinarizationMethod"), m_TiffBinarizationMethod));
        
    }
    if(m_TiffCompressionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("tiffCompression"), m_TiffCompression));
        
    }
}

void TiffSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("thresholdForFloydSteinbergDithering")))
    {
        setThresholdForFloydSteinbergDithering(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("thresholdForFloydSteinbergDithering"))));
    }
    if(multipart->hasContent(_XPLATSTR("tiffBinarizationMethod")))
    {
        setTiffBinarizationMethod(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("tiffBinarizationMethod"))));
    }
    if(multipart->hasContent(_XPLATSTR("tiffCompression")))
    {
        setTiffCompression(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("tiffCompression"))));
    }
}

int32_t TiffSaveOptionsData::getThresholdForFloydSteinbergDithering() const
{
    return m_ThresholdForFloydSteinbergDithering;
}


void TiffSaveOptionsData::setThresholdForFloydSteinbergDithering(int32_t value)
{
    m_ThresholdForFloydSteinbergDithering = value;
    m_ThresholdForFloydSteinbergDitheringIsSet = true;
}
bool TiffSaveOptionsData::thresholdForFloydSteinbergDitheringIsSet() const
{
    return m_ThresholdForFloydSteinbergDitheringIsSet;
}

void TiffSaveOptionsData::unsetThresholdForFloydSteinbergDithering()
{
    m_ThresholdForFloydSteinbergDitheringIsSet = false;
}

utility::string_t TiffSaveOptionsData::getTiffBinarizationMethod() const
{
    return m_TiffBinarizationMethod;
}


void TiffSaveOptionsData::setTiffBinarizationMethod(utility::string_t value)
{
    m_TiffBinarizationMethod = value;
    m_TiffBinarizationMethodIsSet = true;
}
bool TiffSaveOptionsData::tiffBinarizationMethodIsSet() const
{
    return m_TiffBinarizationMethodIsSet;
}

void TiffSaveOptionsData::unsetTiffBinarizationMethod()
{
    m_TiffBinarizationMethodIsSet = false;
}

utility::string_t TiffSaveOptionsData::getTiffCompression() const
{
    return m_TiffCompression;
}


void TiffSaveOptionsData::setTiffCompression(utility::string_t value)
{
    m_TiffCompression = value;
    m_TiffCompressionIsSet = true;
}
bool TiffSaveOptionsData::tiffCompressionIsSet() const
{
    return m_TiffCompressionIsSet;
}

void TiffSaveOptionsData::unsetTiffCompression()
{
    m_TiffCompressionIsSet = false;
}

}
}
}
}
}

