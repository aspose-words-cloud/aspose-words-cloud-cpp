/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObjectUpdate.cpp">
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


#include "DrawingObjectUpdate.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DrawingObjectUpdate::DrawingObjectUpdate()
{
    m_RelativeHorizontalPosition = utility::conversions::to_string_t("");
    m_RelativeHorizontalPositionIsSet = false;
    m_Left = 0.0;
    m_LeftIsSet = false;
    m_RelativeVerticalPosition = utility::conversions::to_string_t("");
    m_RelativeVerticalPositionIsSet = false;
    m_Top = 0.0;
    m_TopIsSet = false;
    m_Width = 0.0;
    m_WidthIsSet = false;
    m_Height = 0.0;
    m_HeightIsSet = false;
    m_WrapType = utility::conversions::to_string_t("");
    m_WrapTypeIsSet = false;
}

DrawingObjectUpdate::~DrawingObjectUpdate()
{
}

void DrawingObjectUpdate::validate()
{
    // TODO: implement validation
}

web::json::value DrawingObjectUpdate::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_RelativeHorizontalPositionIsSet)
    {
        val[_XPLATSTR("RelativeHorizontalPosition")] = ModelBase::toJson(m_RelativeHorizontalPosition);
    }
    if(m_LeftIsSet)
    {
        val[_XPLATSTR("Left")] = ModelBase::toJson(m_Left);
    }
    if(m_RelativeVerticalPositionIsSet)
    {
        val[_XPLATSTR("RelativeVerticalPosition")] = ModelBase::toJson(m_RelativeVerticalPosition);
    }
    if(m_TopIsSet)
    {
        val[_XPLATSTR("Top")] = ModelBase::toJson(m_Top);
    }
    if(m_WidthIsSet)
    {
        val[_XPLATSTR("Width")] = ModelBase::toJson(m_Width);
    }
    if(m_HeightIsSet)
    {
        val[_XPLATSTR("Height")] = ModelBase::toJson(m_Height);
    }
    if(m_WrapTypeIsSet)
    {
        val[_XPLATSTR("WrapType")] = ModelBase::toJson(m_WrapType);
    }

    return val;
}

void DrawingObjectUpdate::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("RelativeHorizontalPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RelativeHorizontalPosition")];
        if(!fieldValue.is_null())
        {
            setRelativeHorizontalPosition(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Left")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Left")];
        if(!fieldValue.is_null())
        {
            setLeft(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("RelativeVerticalPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RelativeVerticalPosition")];
        if(!fieldValue.is_null())
        {
            setRelativeVerticalPosition(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Top")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Top")];
        if(!fieldValue.is_null())
        {
            setTop(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Width")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Width")];
        if(!fieldValue.is_null())
        {
            setWidth(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Height")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Height")];
        if(!fieldValue.is_null())
        {
            setHeight(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("WrapType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WrapType")];
        if(!fieldValue.is_null())
        {
            setWrapType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void DrawingObjectUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RelativeHorizontalPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RelativeHorizontalPosition"), m_RelativeHorizontalPosition));
        
    }
    if(m_LeftIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Left"), m_Left));
        
    }
    if(m_RelativeVerticalPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RelativeVerticalPosition"), m_RelativeVerticalPosition));
        
    }
    if(m_TopIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Top"), m_Top));
        
    }
    if(m_WidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Width"), m_Width));
        
    }
    if(m_HeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Height"), m_Height));
        
    }
    if(m_WrapTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("WrapType"), m_WrapType));
        
    }
}

void DrawingObjectUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    

    if(multipart->hasContent(_XPLATSTR("RelativeHorizontalPosition")))
    {
        setRelativeHorizontalPosition(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RelativeHorizontalPosition"))));
    }
    if(multipart->hasContent(_XPLATSTR("Left")))
    {
        setLeft(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("Left"))));
    }
    if(multipart->hasContent(_XPLATSTR("RelativeVerticalPosition")))
    {
        setRelativeVerticalPosition(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RelativeVerticalPosition"))));
    }
    if(multipart->hasContent(_XPLATSTR("Top")))
    {
        setTop(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("Top"))));
    }
    if(multipart->hasContent(_XPLATSTR("Width")))
    {
        setWidth(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("Width"))));
    }
    if(multipart->hasContent(_XPLATSTR("Height")))
    {
        setHeight(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("Height"))));
    }
    if(multipart->hasContent(_XPLATSTR("WrapType")))
    {
        setWrapType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("WrapType"))));
    }
}

<DATA_TYPE_START>string<DATA_TYPE_END> DrawingObjectUpdate::getRelativeHorizontalPosition() const
{
    return m_RelativeHorizontalPosition;
}


void DrawingObjectUpdate::setRelativeHorizontalPosition(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_RelativeHorizontalPosition = value;
    m_RelativeHorizontalPositionIsSet = true;
}
bool DrawingObjectUpdate::relativeHorizontalPositionIsSet() const
{
    return m_RelativeHorizontalPositionIsSet;
}

void DrawingObjectUpdate::unsetRelativeHorizontalPosition()
{
    m_RelativeHorizontalPositionIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> DrawingObjectUpdate::getLeft() const
{
    return m_Left;
}


void DrawingObjectUpdate::setLeft(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_Left = value;
    m_LeftIsSet = true;
}
bool DrawingObjectUpdate::leftIsSet() const
{
    return m_LeftIsSet;
}

void DrawingObjectUpdate::unsetLeft()
{
    m_LeftIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> DrawingObjectUpdate::getRelativeVerticalPosition() const
{
    return m_RelativeVerticalPosition;
}


void DrawingObjectUpdate::setRelativeVerticalPosition(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_RelativeVerticalPosition = value;
    m_RelativeVerticalPositionIsSet = true;
}
bool DrawingObjectUpdate::relativeVerticalPositionIsSet() const
{
    return m_RelativeVerticalPositionIsSet;
}

void DrawingObjectUpdate::unsetRelativeVerticalPosition()
{
    m_RelativeVerticalPositionIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> DrawingObjectUpdate::getTop() const
{
    return m_Top;
}


void DrawingObjectUpdate::setTop(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_Top = value;
    m_TopIsSet = true;
}
bool DrawingObjectUpdate::topIsSet() const
{
    return m_TopIsSet;
}

void DrawingObjectUpdate::unsetTop()
{
    m_TopIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> DrawingObjectUpdate::getWidth() const
{
    return m_Width;
}


void DrawingObjectUpdate::setWidth(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_Width = value;
    m_WidthIsSet = true;
}
bool DrawingObjectUpdate::widthIsSet() const
{
    return m_WidthIsSet;
}

void DrawingObjectUpdate::unsetWidth()
{
    m_WidthIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> DrawingObjectUpdate::getHeight() const
{
    return m_Height;
}


void DrawingObjectUpdate::setHeight(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_Height = value;
    m_HeightIsSet = true;
}
bool DrawingObjectUpdate::heightIsSet() const
{
    return m_HeightIsSet;
}

void DrawingObjectUpdate::unsetHeight()
{
    m_HeightIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> DrawingObjectUpdate::getWrapType() const
{
    return m_WrapType;
}


void DrawingObjectUpdate::setWrapType(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_WrapType = value;
    m_WrapTypeIsSet = true;
}
bool DrawingObjectUpdate::wrapTypeIsSet() const
{
    return m_WrapTypeIsSet;
}

void DrawingObjectUpdate::unsetWrapType()
{
    m_WrapTypeIsSet = false;
}

}
}
}
}
}

