/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Shading.cpp">
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


#include "Shading.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

Shading::Shading()
{
    m_BackgroundPatternColorIsSet = false;
    m_ForegroundPatternColorIsSet = false;
    m_Texture = utility::conversions::to_string_t("");
    m_TextureIsSet = false;
}

Shading::~Shading()
{
}

void Shading::validate()
{
    // TODO: implement validation
}

web::json::value Shading::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_BackgroundPatternColorIsSet)
    {
        val[_XPLATSTR("BackgroundPatternColor")] = ModelBase::toJson(m_BackgroundPatternColor);
    }
    if(m_ForegroundPatternColorIsSet)
    {
        val[_XPLATSTR("ForegroundPatternColor")] = ModelBase::toJson(m_ForegroundPatternColor);
    }
    if(m_TextureIsSet)
    {
        val[_XPLATSTR("Texture")] = ModelBase::toJson(m_Texture);
    }

    return val;
}

void Shading::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("BackgroundPatternColor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BackgroundPatternColor")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>XmlColor<DATA_TYPE_END> newItem(new XmlColor());
            newItem->fromJson(fieldValue);
            setBackgroundPatternColor( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("ForegroundPatternColor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ForegroundPatternColor")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>XmlColor<DATA_TYPE_END> newItem(new XmlColor());
            newItem->fromJson(fieldValue);
            setForegroundPatternColor( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("Texture")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Texture")];
        if(!fieldValue.is_null())
        {
            setTexture(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Shading::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_BackgroundPatternColorIsSet)
    {
        if (m_BackgroundPatternColor.get())
        {
            m_BackgroundPatternColor->toMultipart(multipart, _XPLATSTR("BackgroundPatternColor."));
        }
        
    }
    if(m_ForegroundPatternColorIsSet)
    {
        if (m_ForegroundPatternColor.get())
        {
            m_ForegroundPatternColor->toMultipart(multipart, _XPLATSTR("ForegroundPatternColor."));
        }
        
    }
    if(m_TextureIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Texture"), m_Texture));
        
    }
}

void Shading::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("BackgroundPatternColor")))
    {
        if(multipart->hasContent(_XPLATSTR("BackgroundPatternColor")))
        {
            <DATA_TYPE_START>XmlColor<DATA_TYPE_END> newItem(new XmlColor());
            newItem->fromMultiPart(multipart, _XPLATSTR("BackgroundPatternColor."));
            setBackgroundPatternColor( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("ForegroundPatternColor")))
    {
        if(multipart->hasContent(_XPLATSTR("ForegroundPatternColor")))
        {
            <DATA_TYPE_START>XmlColor<DATA_TYPE_END> newItem(new XmlColor());
            newItem->fromMultiPart(multipart, _XPLATSTR("ForegroundPatternColor."));
            setForegroundPatternColor( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("Texture")))
    {
        setTexture(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Texture"))));
    }
}

<DATA_TYPE_START>XmlColor<DATA_TYPE_END> Shading::getBackgroundPatternColor() const
{
    return m_BackgroundPatternColor;
}


void Shading::setBackgroundPatternColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value)
{
    m_BackgroundPatternColor = value;
    m_BackgroundPatternColorIsSet = true;
}
bool Shading::backgroundPatternColorIsSet() const
{
    return m_BackgroundPatternColorIsSet;
}

void Shading::unsetBackgroundPatternColor()
{
    m_BackgroundPatternColorIsSet = false;
}

<DATA_TYPE_START>XmlColor<DATA_TYPE_END> Shading::getForegroundPatternColor() const
{
    return m_ForegroundPatternColor;
}


void Shading::setForegroundPatternColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value)
{
    m_ForegroundPatternColor = value;
    m_ForegroundPatternColorIsSet = true;
}
bool Shading::foregroundPatternColorIsSet() const
{
    return m_ForegroundPatternColorIsSet;
}

void Shading::unsetForegroundPatternColor()
{
    m_ForegroundPatternColorIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> Shading::getTexture() const
{
    return m_Texture;
}


void Shading::setTexture(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Texture = value;
    m_TextureIsSet = true;
}
bool Shading::textureIsSet() const
{
    return m_TextureIsSet;
}

void Shading::unsetTexture()
{
    m_TextureIsSet = false;
}

}
}
}
}
}

