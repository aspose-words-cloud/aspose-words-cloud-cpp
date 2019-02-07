/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Border.cpp">
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


#include "Border.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[_XPLATSTR("BorderType")] = ModelBase::toJson(m_BorderType);
    }
    if(m_ColorIsSet)
    {
        val[_XPLATSTR("Color")] = ModelBase::toJson(m_Color);
    }
    if(m_DistanceFromTextIsSet)
    {
        val[_XPLATSTR("DistanceFromText")] = ModelBase::toJson(m_DistanceFromText);
    }
    if(m_LineStyleIsSet)
    {
        val[_XPLATSTR("LineStyle")] = ModelBase::toJson(m_LineStyle);
    }
    if(m_LineWidthIsSet)
    {
        val[_XPLATSTR("LineWidth")] = ModelBase::toJson(m_LineWidth);
    }
    if(m_ShadowIsSet)
    {
        val[_XPLATSTR("Shadow")] = ModelBase::toJson(m_Shadow);
    }

    return val;
}

void Border::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("BorderType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BorderType")];
        if(!fieldValue.is_null())
        {
            setBorderType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Color")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Color")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromJson(fieldValue);
            setColor( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("DistanceFromText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DistanceFromText")];
        if(!fieldValue.is_null())
        {
            setDistanceFromText(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LineStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineStyle")];
        if(!fieldValue.is_null())
        {
            setLineStyle(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LineWidth")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineWidth")];
        if(!fieldValue.is_null())
        {
            setLineWidth(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Shadow")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Shadow")];
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BorderType"), m_BorderType));
        
    }
    if(m_ColorIsSet)
    {
        if (m_Color.get())
        {
            m_Color->toMultipart(multipart, _XPLATSTR("Color."));
        }
        
    }
    if(m_DistanceFromTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DistanceFromText"), m_DistanceFromText));
    }
    if(m_LineStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineStyle"), m_LineStyle));
        
    }
    if(m_LineWidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineWidth"), m_LineWidth));
    }
    if(m_ShadowIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Shadow"), m_Shadow));
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
    if(multipart->hasContent(_XPLATSTR("BorderType")))
    {
        setBorderType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("BorderType"))));
    }
    if(multipart->hasContent(_XPLATSTR("Color")))
    {
        if(multipart->hasContent(_XPLATSTR("Color")))
        {
            std::shared_ptr<XmlColor> newItem(new XmlColor());
            newItem->fromMultiPart(multipart, _XPLATSTR("Color."));
            setColor( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("DistanceFromText")))
    {
        setDistanceFromText(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("DistanceFromText"))));
    }
    if(multipart->hasContent(_XPLATSTR("LineStyle")))
    {
        setLineStyle(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("LineStyle"))));
    }
    if(multipart->hasContent(_XPLATSTR("LineWidth")))
    {
        setLineWidth(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("LineWidth"))));
    }
    if(multipart->hasContent(_XPLATSTR("Shadow")))
    {
        setShadow(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("Shadow"))));
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

