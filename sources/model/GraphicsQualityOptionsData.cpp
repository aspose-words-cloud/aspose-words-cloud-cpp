/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GraphicsQualityOptionsData.cpp">
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


#include "GraphicsQualityOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

GraphicsQualityOptionsData::GraphicsQualityOptionsData()
{
    m_CompositingMode = utility::conversions::to_string_t("");
    m_CompositingModeIsSet = false;
    m_CompositingQuality = utility::conversions::to_string_t("");
    m_CompositingQualityIsSet = false;
    m_InterpolationMode = utility::conversions::to_string_t("");
    m_InterpolationModeIsSet = false;
    m_SmoothingMode = utility::conversions::to_string_t("");
    m_SmoothingModeIsSet = false;
    m_StringFormatIsSet = false;
    m_TextRenderingHint = utility::conversions::to_string_t("");
    m_TextRenderingHintIsSet = false;
}

GraphicsQualityOptionsData::~GraphicsQualityOptionsData()
{
}

void GraphicsQualityOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value GraphicsQualityOptionsData::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_CompositingModeIsSet)
    {
        val[_XPLATSTR("CompositingMode")] = ModelBase::toJson(m_CompositingMode);
    }
    if(m_CompositingQualityIsSet)
    {
        val[_XPLATSTR("CompositingQuality")] = ModelBase::toJson(m_CompositingQuality);
    }
    if(m_InterpolationModeIsSet)
    {
        val[_XPLATSTR("InterpolationMode")] = ModelBase::toJson(m_InterpolationMode);
    }
    if(m_SmoothingModeIsSet)
    {
        val[_XPLATSTR("SmoothingMode")] = ModelBase::toJson(m_SmoothingMode);
    }
    if(m_StringFormatIsSet)
    {
        val[_XPLATSTR("StringFormat")] = ModelBase::toJson(m_StringFormat);
    }
    if(m_TextRenderingHintIsSet)
    {
        val[_XPLATSTR("TextRenderingHint")] = ModelBase::toJson(m_TextRenderingHint);
    }

    return val;
}

void GraphicsQualityOptionsData::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("CompositingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CompositingMode")];
        if(!fieldValue.is_null())
        {
            setCompositingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CompositingQuality")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CompositingQuality")];
        if(!fieldValue.is_null())
        {
            setCompositingQuality(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("InterpolationMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("InterpolationMode")];
        if(!fieldValue.is_null())
        {
            setInterpolationMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SmoothingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SmoothingMode")];
        if(!fieldValue.is_null())
        {
            setSmoothingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("StringFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StringFormat")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<StringFormatData> newItem(new StringFormatData());
            newItem->fromJson(fieldValue);
            setStringFormat( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("TextRenderingHint")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextRenderingHint")];
        if(!fieldValue.is_null())
        {
            setTextRenderingHint(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void GraphicsQualityOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_CompositingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CompositingMode"), m_CompositingMode));
        
    }
    if(m_CompositingQualityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CompositingQuality"), m_CompositingQuality));
        
    }
    if(m_InterpolationModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("InterpolationMode"), m_InterpolationMode));
        
    }
    if(m_SmoothingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SmoothingMode"), m_SmoothingMode));
        
    }
    if(m_StringFormatIsSet)
    {
        if (m_StringFormat.get())
        {
            m_StringFormat->toMultipart(multipart, _XPLATSTR("StringFormat."));
        }
        
    }
    if(m_TextRenderingHintIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextRenderingHint"), m_TextRenderingHint));
        
    }
}

void GraphicsQualityOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("CompositingMode")))
    {
        setCompositingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CompositingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("CompositingQuality")))
    {
        setCompositingQuality(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CompositingQuality"))));
    }
    if(multipart->hasContent(_XPLATSTR("InterpolationMode")))
    {
        setInterpolationMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("InterpolationMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("SmoothingMode")))
    {
        setSmoothingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("SmoothingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("StringFormat")))
    {
        if(multipart->hasContent(_XPLATSTR("StringFormat")))
        {
            std::shared_ptr<StringFormatData> newItem(new StringFormatData());
            newItem->fromMultiPart(multipart, _XPLATSTR("StringFormat."));
            setStringFormat( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("TextRenderingHint")))
    {
        setTextRenderingHint(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextRenderingHint"))));
    }
}

utility::string_t GraphicsQualityOptionsData::getCompositingMode() const
{
    return m_CompositingMode;
}


void GraphicsQualityOptionsData::setCompositingMode(utility::string_t value)
{
    m_CompositingMode = value;
    m_CompositingModeIsSet = true;
}
bool GraphicsQualityOptionsData::compositingModeIsSet() const
{
    return m_CompositingModeIsSet;
}

void GraphicsQualityOptionsData::unsetCompositingMode()
{
    m_CompositingModeIsSet = false;
}

utility::string_t GraphicsQualityOptionsData::getCompositingQuality() const
{
    return m_CompositingQuality;
}


void GraphicsQualityOptionsData::setCompositingQuality(utility::string_t value)
{
    m_CompositingQuality = value;
    m_CompositingQualityIsSet = true;
}
bool GraphicsQualityOptionsData::compositingQualityIsSet() const
{
    return m_CompositingQualityIsSet;
}

void GraphicsQualityOptionsData::unsetCompositingQuality()
{
    m_CompositingQualityIsSet = false;
}

utility::string_t GraphicsQualityOptionsData::getInterpolationMode() const
{
    return m_InterpolationMode;
}


void GraphicsQualityOptionsData::setInterpolationMode(utility::string_t value)
{
    m_InterpolationMode = value;
    m_InterpolationModeIsSet = true;
}
bool GraphicsQualityOptionsData::interpolationModeIsSet() const
{
    return m_InterpolationModeIsSet;
}

void GraphicsQualityOptionsData::unsetInterpolationMode()
{
    m_InterpolationModeIsSet = false;
}

utility::string_t GraphicsQualityOptionsData::getSmoothingMode() const
{
    return m_SmoothingMode;
}


void GraphicsQualityOptionsData::setSmoothingMode(utility::string_t value)
{
    m_SmoothingMode = value;
    m_SmoothingModeIsSet = true;
}
bool GraphicsQualityOptionsData::smoothingModeIsSet() const
{
    return m_SmoothingModeIsSet;
}

void GraphicsQualityOptionsData::unsetSmoothingMode()
{
    m_SmoothingModeIsSet = false;
}

std::shared_ptr<StringFormatData> GraphicsQualityOptionsData::getStringFormat() const
{
    return m_StringFormat;
}


void GraphicsQualityOptionsData::setStringFormat(std::shared_ptr<StringFormatData> value)
{
    m_StringFormat = value;
    m_StringFormatIsSet = true;
}
bool GraphicsQualityOptionsData::stringFormatIsSet() const
{
    return m_StringFormatIsSet;
}

void GraphicsQualityOptionsData::unsetStringFormat()
{
    m_StringFormatIsSet = false;
}

utility::string_t GraphicsQualityOptionsData::getTextRenderingHint() const
{
    return m_TextRenderingHint;
}


void GraphicsQualityOptionsData::setTextRenderingHint(utility::string_t value)
{
    m_TextRenderingHint = value;
    m_TextRenderingHintIsSet = true;
}
bool GraphicsQualityOptionsData::textRenderingHintIsSet() const
{
    return m_TextRenderingHintIsSet;
}

void GraphicsQualityOptionsData::unsetTextRenderingHint()
{
    m_TextRenderingHintIsSet = false;
}

}
}
}
}

