/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObjectUpdate.cpp">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
    m_Height = 0.0;
    m_HeightIsSet = false;
    m_Left = 0.0;
    m_LeftIsSet = false;

    m_RelativeHorizontalPositionIsSet = false;

    m_RelativeVerticalPositionIsSet = false;
    m_Top = 0.0;
    m_TopIsSet = false;
    m_Width = 0.0;
    m_WidthIsSet = false;

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
    if(m_HeightIsSet)
    {
        val[_XPLATSTR("Height")] = ModelBase::toJson(m_Height);
    }
    if(m_LeftIsSet)
    {
        val[_XPLATSTR("Left")] = ModelBase::toJson(m_Left);
    }
    if(m_RelativeHorizontalPositionIsSet)
    {
        val[_XPLATSTR("RelativeHorizontalPosition")] = ModelBase::toJson(m_RelativeHorizontalPosition);
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
    if(m_WrapTypeIsSet)
    {
        val[_XPLATSTR("WrapType")] = ModelBase::toJson(m_WrapType);
    }

    return val;
}

void DrawingObjectUpdate::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("Height")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Height")];
        if(!fieldValue.is_null())
        {
           setHeight(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Left")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Left")];
        if(!fieldValue.is_null())
        {
           setLeft(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RelativeHorizontalPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RelativeHorizontalPosition")];
        if(!fieldValue.is_null())
        {
           setRelativeHorizontalPosition(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RelativeVerticalPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RelativeVerticalPosition")];
        if(!fieldValue.is_null())
        {
           setRelativeVerticalPosition(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Top")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Top")];
        if(!fieldValue.is_null())
        {
           setTop(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Width")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Width")];
        if(!fieldValue.is_null())
        {
           setWidth(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("WrapType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WrapType")];
        if(!fieldValue.is_null())
        {
           setWrapType(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void DrawingObjectUpdate::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_HeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Height"), m_Height));
    }


    if(m_LeftIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Left"), m_Left));
    }


    if(m_RelativeHorizontalPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RelativeHorizontalPosition"), m_RelativeHorizontalPosition));
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


    if(m_WrapTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("WrapType"), m_WrapType));
    }

}

void DrawingObjectUpdate::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

double DrawingObjectUpdate::getHeight() const
{
    return m_Height;
}


void DrawingObjectUpdate::setHeight(double value)
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

double DrawingObjectUpdate::getLeft() const
{
    return m_Left;
}


void DrawingObjectUpdate::setLeft(double value)
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

utility::string_t DrawingObjectUpdate::getRelativeHorizontalPosition() const
{
    return m_RelativeHorizontalPosition;
}


void DrawingObjectUpdate::setRelativeHorizontalPosition(utility::string_t value)
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

utility::string_t DrawingObjectUpdate::getRelativeVerticalPosition() const
{
    return m_RelativeVerticalPosition;
}


void DrawingObjectUpdate::setRelativeVerticalPosition(utility::string_t value)
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

double DrawingObjectUpdate::getTop() const
{
    return m_Top;
}


void DrawingObjectUpdate::setTop(double value)
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

double DrawingObjectUpdate::getWidth() const
{
    return m_Width;
}


void DrawingObjectUpdate::setWidth(double value)
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

utility::string_t DrawingObjectUpdate::getWrapType() const
{
    return m_WrapType;
}


void DrawingObjectUpdate::setWrapType(utility::string_t value)
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
