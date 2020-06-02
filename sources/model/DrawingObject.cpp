/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObject.cpp">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "DrawingObject.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

DrawingObject::DrawingObject()
{
    m_Height = 0.0;
    m_HeightIsSet = false;

    m_ImageDataLinkIsSet = false;
    m_Left = 0.0;
    m_LeftIsSet = false;

    m_OleDataLinkIsSet = false;

    m_RelativeHorizontalPositionIsSet = false;

    m_RelativeVerticalPositionIsSet = false;

    m_RenderLinksIsSet = false;
    m_Top = 0.0;
    m_TopIsSet = false;
    m_Width = 0.0;
    m_WidthIsSet = false;

    m_WrapTypeIsSet = false;

}

DrawingObject::~DrawingObject()
{
}

void DrawingObject::validate()
{
    // TODO: implement validation
}

web::json::value DrawingObject::toJson() const
{
    web::json::value val = this->DrawingObjectLink::toJson();
    if(m_HeightIsSet)
    {
        val[_XPLATSTR("Height")] = ModelBase::toJson(m_Height);
    }
    if(m_ImageDataLinkIsSet)
    {
        val[_XPLATSTR("ImageDataLink")] = ModelBase::toJson(m_ImageDataLink);
    }
    if(m_LeftIsSet)
    {
        val[_XPLATSTR("Left")] = ModelBase::toJson(m_Left);
    }
    if(m_OleDataLinkIsSet)
    {
        val[_XPLATSTR("OleDataLink")] = ModelBase::toJson(m_OleDataLink);
    }
    if(m_RelativeHorizontalPositionIsSet)
    {
        val[_XPLATSTR("RelativeHorizontalPosition")] = ModelBase::toJson(m_RelativeHorizontalPosition);
    }
    if(m_RelativeVerticalPositionIsSet)
    {
        val[_XPLATSTR("RelativeVerticalPosition")] = ModelBase::toJson(m_RelativeVerticalPosition);
    }
    if(m_RenderLinksIsSet)
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_RenderLinks.begin(), m_RenderLinks.end(), std::back_inserter(jsonArray),
            [&](std::shared_ptr<WordsApiLink> item) {
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("RenderLinks")] = web::json::value::array(jsonArray);
        }
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

void DrawingObject::fromJson(web::json::value& val)
{
    this->DrawingObjectLink::fromJson(val);

    if(val.has_field(_XPLATSTR("Height")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Height")];
        if(!fieldValue.is_null())
        {
           setHeight(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ImageDataLink")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImageDataLink")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromJson(fieldValue);
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


    if(val.has_field(_XPLATSTR("OleDataLink")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OleDataLink")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromJson(fieldValue);
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


    {
        m_RenderLinks.clear();
        if(val.has_field(_XPLATSTR("RenderLinks")) 
                            && !val[_XPLATSTR("RenderLinks")].is_null())
        {
            auto arr = val[_XPLATSTR("RenderLinks")].as_array();
            std::transform(arr.begin(), arr.end(), std::back_inserter(m_RenderLinks), [&](web::json::value& item){
                if(!item.is_null())
                {
                    std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
                    newItem->fromJson(item);
                    return newItem;
                }

                return (std::shared_ptr<WordsApiLink>)nullptr;
            });
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

void DrawingObject::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    DrawingObjectLink::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_HeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Height"), m_Height));
    }


    if(m_ImageDataLinkIsSet)
    {
        if (m_ImageDataLink.get())
        {
            m_ImageDataLink->toMultipart(multipart, _XPLATSTR("ImageDataLink."));
        }
    }


    if(m_LeftIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Left"), m_Left));
    }


    if(m_OleDataLinkIsSet)
    {
        if (m_OleDataLink.get())
        {
            m_OleDataLink->toMultipart(multipart, _XPLATSTR("OleDataLink."));
        }
    }


    if(m_RelativeHorizontalPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RelativeHorizontalPosition"), m_RelativeHorizontalPosition));
    }


    if(m_RelativeVerticalPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RelativeVerticalPosition"), m_RelativeVerticalPosition));
    }


    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_RenderLinks.begin(), m_RenderLinks.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<WordsApiLink> item){
            return ModelBase::toJson(item);
        });

        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RenderLinks"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
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

void DrawingObject::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

double DrawingObject::getHeight() const
{
    return m_Height;
}


void DrawingObject::setHeight(double value)
{
    m_Height = value;
    m_HeightIsSet = true;
}

bool DrawingObject::heightIsSet() const
{
    return m_HeightIsSet;
}

void DrawingObject::unsetHeight()
{
    m_HeightIsSet = false;
}

std::shared_ptr<WordsApiLink> DrawingObject::getImageDataLink() const
{
    return m_ImageDataLink;
}


void DrawingObject::setImageDataLink(std::shared_ptr<WordsApiLink> value)
{
    m_ImageDataLink = value;
    m_ImageDataLinkIsSet = true;
}

bool DrawingObject::imageDataLinkIsSet() const
{
    return m_ImageDataLinkIsSet;
}

void DrawingObject::unsetImageDataLink()
{
    m_ImageDataLinkIsSet = false;
}

double DrawingObject::getLeft() const
{
    return m_Left;
}


void DrawingObject::setLeft(double value)
{
    m_Left = value;
    m_LeftIsSet = true;
}

bool DrawingObject::leftIsSet() const
{
    return m_LeftIsSet;
}

void DrawingObject::unsetLeft()
{
    m_LeftIsSet = false;
}

std::shared_ptr<WordsApiLink> DrawingObject::getOleDataLink() const
{
    return m_OleDataLink;
}


void DrawingObject::setOleDataLink(std::shared_ptr<WordsApiLink> value)
{
    m_OleDataLink = value;
    m_OleDataLinkIsSet = true;
}

bool DrawingObject::oleDataLinkIsSet() const
{
    return m_OleDataLinkIsSet;
}

void DrawingObject::unsetOleDataLink()
{
    m_OleDataLinkIsSet = false;
}

utility::string_t DrawingObject::getRelativeHorizontalPosition() const
{
    return m_RelativeHorizontalPosition;
}


void DrawingObject::setRelativeHorizontalPosition(utility::string_t value)
{
    m_RelativeHorizontalPosition = value;
    m_RelativeHorizontalPositionIsSet = true;
}

bool DrawingObject::relativeHorizontalPositionIsSet() const
{
    return m_RelativeHorizontalPositionIsSet;
}

void DrawingObject::unsetRelativeHorizontalPosition()
{
    m_RelativeHorizontalPositionIsSet = false;
}

utility::string_t DrawingObject::getRelativeVerticalPosition() const
{
    return m_RelativeVerticalPosition;
}


void DrawingObject::setRelativeVerticalPosition(utility::string_t value)
{
    m_RelativeVerticalPosition = value;
    m_RelativeVerticalPositionIsSet = true;
}

bool DrawingObject::relativeVerticalPositionIsSet() const
{
    return m_RelativeVerticalPositionIsSet;
}

void DrawingObject::unsetRelativeVerticalPosition()
{
    m_RelativeVerticalPositionIsSet = false;
}

std::vector<std::shared_ptr<WordsApiLink>>& DrawingObject::getRenderLinks()
{
    return m_RenderLinks;
}


void DrawingObject::setRenderLinks(std::vector<std::shared_ptr<WordsApiLink>> const& value)
{
    m_RenderLinks = value;
    m_RenderLinksIsSet = true;
}

bool DrawingObject::renderLinksIsSet() const
{
    return m_RenderLinksIsSet;
}

void DrawingObject::unsetRenderLinks()
{
    m_RenderLinksIsSet = false;
}

double DrawingObject::getTop() const
{
    return m_Top;
}


void DrawingObject::setTop(double value)
{
    m_Top = value;
    m_TopIsSet = true;
}

bool DrawingObject::topIsSet() const
{
    return m_TopIsSet;
}

void DrawingObject::unsetTop()
{
    m_TopIsSet = false;
}

double DrawingObject::getWidth() const
{
    return m_Width;
}


void DrawingObject::setWidth(double value)
{
    m_Width = value;
    m_WidthIsSet = true;
}

bool DrawingObject::widthIsSet() const
{
    return m_WidthIsSet;
}

void DrawingObject::unsetWidth()
{
    m_WidthIsSet = false;
}

utility::string_t DrawingObject::getWrapType() const
{
    return m_WrapType;
}


void DrawingObject::setWrapType(utility::string_t value)
{
    m_WrapType = value;
    m_WrapTypeIsSet = true;
}

bool DrawingObject::wrapTypeIsSet() const
{
    return m_WrapTypeIsSet;
}

void DrawingObject::unsetWrapType()
{
    m_WrapTypeIsSet = false;
}

}
}
}
}
}
