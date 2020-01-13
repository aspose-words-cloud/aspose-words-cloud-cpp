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
        val[_XPLATSTR("ThresholdForFloydSteinbergDithering")] = ModelBase::toJson(m_ThresholdForFloydSteinbergDithering);
    }
    if(m_TiffBinarizationMethodIsSet)
    {
        val[_XPLATSTR("TiffBinarizationMethod")] = ModelBase::toJson(m_TiffBinarizationMethod);
    }
    if(m_TiffCompressionIsSet)
    {
        val[_XPLATSTR("TiffCompression")] = ModelBase::toJson(m_TiffCompression);
    }

    return val;
}

void TiffSaveOptionsData::fromJson(web::json::value& val)
{
    this->ImageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("ThresholdForFloydSteinbergDithering")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ThresholdForFloydSteinbergDithering")];
        if(!fieldValue.is_null())
        {
            setThresholdForFloydSteinbergDithering(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TiffBinarizationMethod")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TiffBinarizationMethod")];
        if(!fieldValue.is_null())
        {
            setTiffBinarizationMethod(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TiffCompression")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TiffCompression")];
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
    if(m_ThresholdForFloydSteinbergDitheringIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ThresholdForFloydSteinbergDithering"), m_ThresholdForFloydSteinbergDithering));
    }
    if(m_TiffBinarizationMethodIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TiffBinarizationMethod"), m_TiffBinarizationMethod));
        
    }
    if(m_TiffCompressionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TiffCompression"), m_TiffCompression));
        
    }
}

void TiffSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("ThresholdForFloydSteinbergDithering")))
    {
        setThresholdForFloydSteinbergDithering(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("ThresholdForFloydSteinbergDithering"))));
    }
    if(multipart->hasContent(_XPLATSTR("TiffBinarizationMethod")))
    {
        setTiffBinarizationMethod(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TiffBinarizationMethod"))));
    }
    if(multipart->hasContent(_XPLATSTR("TiffCompression")))
    {
        setTiffCompression(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TiffCompression"))));
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

