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
        val[_XPLATSTR("falllbackFontName")] = ModelBase::toJson(m_FalllbackFontName);
    }
    if(m_RasterizeTransformedElementsIsSet)
    {
        val[_XPLATSTR("rasterizeTransformedElements")] = ModelBase::toJson(m_RasterizeTransformedElements);
    }

    return val;
}

void PclSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("falllbackFontName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("falllbackFontName")];
        if(!fieldValue.is_null())
        {
            setFalllbackFontName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("rasterizeTransformedElements")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rasterizeTransformedElements")];
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
    if(m_FalllbackFontNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("falllbackFontName"), m_FalllbackFontName));
        
    }
    if(m_RasterizeTransformedElementsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("rasterizeTransformedElements"), m_RasterizeTransformedElements));
    }
}

void PclSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("falllbackFontName")))
    {
        setFalllbackFontName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("falllbackFontName"))));
    }
    if(multipart->hasContent(_XPLATSTR("rasterizeTransformedElements")))
    {
        setRasterizeTransformedElements(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("rasterizeTransformedElements"))));
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

