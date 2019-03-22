/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PclSaveOptionsData.cpp">
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


#include "PclSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

PclSaveOptionsData::PclSaveOptionsData()
{
    m_FalllbackFontName = utility::conversions::to_string_t("");
    m_FalllbackFontNameIsSet = false;
    m_RasterizeTransformedElements = false;
    m_RasterizeTransformedElementsIsSet = false;
}

PclSaveOptionsData::~PclSaveOptionsData()
{
}

void PclSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value PclSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();

    if(m_FalllbackFontNameIsSet)
    {
        val[_XPLATSTR("FalllbackFontName")] = ModelBase::toJson(m_FalllbackFontName);
    }
    if(m_RasterizeTransformedElementsIsSet)
    {
        val[_XPLATSTR("RasterizeTransformedElements")] = ModelBase::toJson(m_RasterizeTransformedElements);
    }

    return val;
}

void PclSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("FalllbackFontName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FalllbackFontName")];
        if(!fieldValue.is_null())
        {
            setFalllbackFontName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("RasterizeTransformedElements")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RasterizeTransformedElements")];
        if(!fieldValue.is_null())
        {
            setRasterizeTransformedElements(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void PclSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_FalllbackFontNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FalllbackFontName"), m_FalllbackFontName));
        
    }
    if(m_RasterizeTransformedElementsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RasterizeTransformedElements"), m_RasterizeTransformedElements));
    }
}

void PclSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("FalllbackFontName")))
    {
        setFalllbackFontName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FalllbackFontName"))));
    }
    if(multipart->hasContent(_XPLATSTR("RasterizeTransformedElements")))
    {
        setRasterizeTransformedElements(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("RasterizeTransformedElements"))));
    }
}

utility::string_t PclSaveOptionsData::getFalllbackFontName() const
{
    return m_FalllbackFontName;
}


void PclSaveOptionsData::setFalllbackFontName(utility::string_t value)
{
    m_FalllbackFontName = value;
    m_FalllbackFontNameIsSet = true;
}
bool PclSaveOptionsData::falllbackFontNameIsSet() const
{
    return m_FalllbackFontNameIsSet;
}

void PclSaveOptionsData::unsetFalllbackFontName()
{
    m_FalllbackFontNameIsSet = false;
}

bool PclSaveOptionsData::isRasterizeTransformedElements() const
{
    return m_RasterizeTransformedElements;
}


void PclSaveOptionsData::setRasterizeTransformedElements(bool value)
{
    m_RasterizeTransformedElements = value;
    m_RasterizeTransformedElementsIsSet = true;
}
bool PclSaveOptionsData::rasterizeTransformedElementsIsSet() const
{
    return m_RasterizeTransformedElementsIsSet;
}

void PclSaveOptionsData::unsetRasterizeTransformedElements()
{
    m_RasterizeTransformedElementsIsSet = false;
}

}
}
}
}
}

