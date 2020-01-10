/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Border.cpp">
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


#include "Border.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Border::Border()
{
    m_BorderType = utility::conversions::to_string_t("");
    m_BorderTypeIsSet = false;
    m_ColorIsSet = false;
    m_DistanceFromText = 0.0;
    m_DistanceFromTextIsSet = false;
    m_LineStyle = utility::conversions::to_string_t("");
    m_LineStyleIsSet = false;
    m_LineWidth = 0.0;
    m_LineWidthIsSet = false;
    m_Shadow = false;
    m_ShadowIsSet = false;
}

Border::~Border()
{
}

void Border::validate()
{
    // TODO: implement validation
}

web::json::value Border::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_BorderTypeIsSet)
    {
        val[_XPLATSTR("borderType")] = ModelBase::toJson(m_BorderType);
    }
    if(m_ColorIsSet)
    {
        val[_XPLATSTR("color")] = ModelBase::toJson(m_Color);
    }
    if(m_DistanceFromTextIsSet)
    {
        val[_XPLATSTR("distanceFromText")] = ModelBase::toJson(m_DistanceFromText);
    }
    if(m_LineStyleIsSet)
    {
        val[_XPLATSTR("lineStyle")] = ModelBase::toJson(m_LineStyle);
    }
    if(m_LineWidthIsSet)
    {
        val[_XPLATSTR("lineWidth")] = ModelBase::toJson(m_LineWidth);
    }
    if(m_ShadowIsSet)
    {
        val[_XPLATSTR("shadow")] = ModelBase::toJson(m_Shadow);
    }

    return val;
}

void Border::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("borderType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("borderType")];
        if(!fieldValue.is_null())
        {
            setBorderType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("color")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("color")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromJson(fieldValue);
            setColor( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("distanceFromText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("distanceFromText")];
        if(!fieldValue.is_null())
        {
            setDistanceFromText(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineStyle")];
        if(!fieldValue.is_null())
        {
            setLineStyle(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineWidth")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineWidth")];
        if(!fieldValue.is_null())
        {
            setLineWidth(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("shadow")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("shadow")];
        if(!fieldValue.is_null())
        {
            setShadow(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void Border::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_BorderTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("borderType"), m_BorderType));
        
    }
    if(m_ColorIsSet)
    {
        if (m_Color.get())
        {
            m_Color->toMultipart(multipart, _XPLATSTR("color."));
        }
        
    }
    if(m_DistanceFromTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("distanceFromText"), m_DistanceFromText));
    }
    if(m_LineStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineStyle"), m_LineStyle));
        
    }
    if(m_LineWidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineWidth"), m_LineWidth));
    }
    if(m_ShadowIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("shadow"), m_Shadow));
    }
}

void Border::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("borderType")))
    {
        setBorderType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("borderType"))));
    }
    if(multipart->hasContent(_XPLATSTR("color")))
    {
        if(multipart->hasContent(_XPLATSTR("color")))
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromMultiPart(multipart, _XPLATSTR("color."));
            setColor( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("distanceFromText")))
    {
        setDistanceFromText(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("distanceFromText"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineStyle")))
    {
        setLineStyle(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("lineStyle"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineWidth")))
    {
        setLineWidth(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("lineWidth"))));
    }
    if(multipart->hasContent(_XPLATSTR("shadow")))
    {
        setShadow(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("shadow"))));
    }
}

utility::string_t Border::getBorderType() const
{
    return m_BorderType;
}


void Border::setBorderType(utility::string_t value)
{
    m_BorderType = value;
    m_BorderTypeIsSet = true;
}
bool Border::borderTypeIsSet() const
{
    return m_BorderTypeIsSet;
}

void Border::unsetBorderType()
{
    m_BorderTypeIsSet = false;
}

std::shared_ptr<XmlColor> Border::getColor() const
{
    return m_Color;
}


void Border::setColor(std::shared_ptr<XmlColor> value)
{
    m_Color = value;
    m_ColorIsSet = true;
}
bool Border::colorIsSet() const
{
    return m_ColorIsSet;
}

void Border::unsetColor()
{
    m_ColorIsSet = false;
}

double Border::getDistanceFromText() const
{
    return m_DistanceFromText;
}


void Border::setDistanceFromText(double value)
{
    m_DistanceFromText = value;
    m_DistanceFromTextIsSet = true;
}
bool Border::distanceFromTextIsSet() const
{
    return m_DistanceFromTextIsSet;
}

void Border::unsetDistanceFromText()
{
    m_DistanceFromTextIsSet = false;
}

utility::string_t Border::getLineStyle() const
{
    return m_LineStyle;
}


void Border::setLineStyle(utility::string_t value)
{
    m_LineStyle = value;
    m_LineStyleIsSet = true;
}
bool Border::lineStyleIsSet() const
{
    return m_LineStyleIsSet;
}

void Border::unsetLineStyle()
{
    m_LineStyleIsSet = false;
}

double Border::getLineWidth() const
{
    return m_LineWidth;
}


void Border::setLineWidth(double value)
{
    m_LineWidth = value;
    m_LineWidthIsSet = true;
}
bool Border::lineWidthIsSet() const
{
    return m_LineWidthIsSet;
}

void Border::unsetLineWidth()
{
    m_LineWidthIsSet = false;
}

bool Border::isShadow() const
{
    return m_Shadow;
}


void Border::setShadow(bool value)
{
    m_Shadow = value;
    m_ShadowIsSet = true;
}
bool Border::shadowIsSet() const
{
    return m_ShadowIsSet;
}

void Border::unsetShadow()
{
    m_ShadowIsSet = false;
}

}
}
}
}
}

