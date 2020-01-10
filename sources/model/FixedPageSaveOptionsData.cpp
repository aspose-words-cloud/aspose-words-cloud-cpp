/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FixedPageSaveOptionsData.cpp">
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


#include "FixedPageSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

FixedPageSaveOptionsData::FixedPageSaveOptionsData()
{
    m_JpegQuality = 0;
    m_JpegQualityIsSet = false;
    m_MetafileRenderingOptionsIsSet = false;
    m_NumeralFormat = utility::conversions::to_string_t("");
    m_NumeralFormatIsSet = false;
    m_OptimizeOutput = false;
    m_OptimizeOutputIsSet = false;
    m_PageCount = 0;
    m_PageCountIsSet = false;
    m_PageIndex = 0;
    m_PageIndexIsSet = false;
}

FixedPageSaveOptionsData::~FixedPageSaveOptionsData()
{
}

void FixedPageSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value FixedPageSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_JpegQualityIsSet)
    {
        val[_XPLATSTR("jpegQuality")] = ModelBase::toJson(m_JpegQuality);
    }
    if(m_MetafileRenderingOptionsIsSet)
    {
        val[_XPLATSTR("metafileRenderingOptions")] = ModelBase::toJson(m_MetafileRenderingOptions);
    }
    if(m_NumeralFormatIsSet)
    {
        val[_XPLATSTR("numeralFormat")] = ModelBase::toJson(m_NumeralFormat);
    }
    if(m_OptimizeOutputIsSet)
    {
        val[_XPLATSTR("optimizeOutput")] = ModelBase::toJson(m_OptimizeOutput);
    }
    if(m_PageCountIsSet)
    {
        val[_XPLATSTR("pageCount")] = ModelBase::toJson(m_PageCount);
    }
    if(m_PageIndexIsSet)
    {
        val[_XPLATSTR("pageIndex")] = ModelBase::toJson(m_PageIndex);
    }

    return val;
}

void FixedPageSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("jpegQuality")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("jpegQuality")];
        if(!fieldValue.is_null())
        {
            setJpegQuality(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("metafileRenderingOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("metafileRenderingOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<MetafileRenderingOptionsData> newItem(new MetafileRenderingOptionsData());
            newItem->fromJson(fieldValue);
            setMetafileRenderingOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("numeralFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("numeralFormat")];
        if(!fieldValue.is_null())
        {
            setNumeralFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("optimizeOutput")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("optimizeOutput")];
        if(!fieldValue.is_null())
        {
            setOptimizeOutput(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageCount")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageCount")];
        if(!fieldValue.is_null())
        {
            setPageCount(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageIndex")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageIndex")];
        if(!fieldValue.is_null())
        {
            setPageIndex(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void FixedPageSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
}

void FixedPageSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
}

int32_t FixedPageSaveOptionsData::getJpegQuality() const
{
    return m_JpegQuality;
}


void FixedPageSaveOptionsData::setJpegQuality(int32_t value)
{
    m_JpegQuality = value;
    m_JpegQualityIsSet = true;
}
bool FixedPageSaveOptionsData::jpegQualityIsSet() const
{
    return m_JpegQualityIsSet;
}

void FixedPageSaveOptionsData::unsetJpegQuality()
{
    m_JpegQualityIsSet = false;
}

std::shared_ptr<MetafileRenderingOptionsData> FixedPageSaveOptionsData::getMetafileRenderingOptions() const
{
    return m_MetafileRenderingOptions;
}


void FixedPageSaveOptionsData::setMetafileRenderingOptions(std::shared_ptr<MetafileRenderingOptionsData> value)
{
    m_MetafileRenderingOptions = value;
    m_MetafileRenderingOptionsIsSet = true;
}
bool FixedPageSaveOptionsData::metafileRenderingOptionsIsSet() const
{
    return m_MetafileRenderingOptionsIsSet;
}

void FixedPageSaveOptionsData::unsetMetafileRenderingOptions()
{
    m_MetafileRenderingOptionsIsSet = false;
}

utility::string_t FixedPageSaveOptionsData::getNumeralFormat() const
{
    return m_NumeralFormat;
}


void FixedPageSaveOptionsData::setNumeralFormat(utility::string_t value)
{
    m_NumeralFormat = value;
    m_NumeralFormatIsSet = true;
}
bool FixedPageSaveOptionsData::numeralFormatIsSet() const
{
    return m_NumeralFormatIsSet;
}

void FixedPageSaveOptionsData::unsetNumeralFormat()
{
    m_NumeralFormatIsSet = false;
}

bool FixedPageSaveOptionsData::isOptimizeOutput() const
{
    return m_OptimizeOutput;
}


void FixedPageSaveOptionsData::setOptimizeOutput(bool value)
{
    m_OptimizeOutput = value;
    m_OptimizeOutputIsSet = true;
}
bool FixedPageSaveOptionsData::optimizeOutputIsSet() const
{
    return m_OptimizeOutputIsSet;
}

void FixedPageSaveOptionsData::unsetOptimizeOutput()
{
    m_OptimizeOutputIsSet = false;
}

int32_t FixedPageSaveOptionsData::getPageCount() const
{
    return m_PageCount;
}


void FixedPageSaveOptionsData::setPageCount(int32_t value)
{
    m_PageCount = value;
    m_PageCountIsSet = true;
}
bool FixedPageSaveOptionsData::pageCountIsSet() const
{
    return m_PageCountIsSet;
}

void FixedPageSaveOptionsData::unsetPageCount()
{
    m_PageCountIsSet = false;
}

int32_t FixedPageSaveOptionsData::getPageIndex() const
{
    return m_PageIndex;
}


void FixedPageSaveOptionsData::setPageIndex(int32_t value)
{
    m_PageIndex = value;
    m_PageIndexIsSet = true;
}
bool FixedPageSaveOptionsData::pageIndexIsSet() const
{
    return m_PageIndexIsSet;
}

void FixedPageSaveOptionsData::unsetPageIndex()
{
    m_PageIndexIsSet = false;
}

}
}
}
}
}

