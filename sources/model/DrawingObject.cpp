/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObject.cpp">
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


#include "DrawingObject.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

DrawingObject::DrawingObject()
{
    m_Height = 0.0;
    m_HeightIsSet = false;
    m_ImageDataLinkIsSet = false;
    m_Left = 0.0;
    m_LeftIsSet = false;
    m_OleDataLinkIsSet = false;
    m_RelativeHorizontalPosition = utility::conversions::to_string_t("");
    m_RelativeHorizontalPositionIsSet = false;
    m_RelativeVerticalPosition = utility::conversions::to_string_t("");
    m_RelativeVerticalPositionIsSet = false;
    m_RenderLinksIsSet = false;
    m_Top = 0.0;
    m_TopIsSet = false;
    m_Width = 0.0;
    m_WidthIsSet = false;
    m_WrapType = utility::conversions::to_string_t("");
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
        val[utility::conversions::to_string_t("Height")] = ModelBase::toJson(m_Height);
    }
    if(m_ImageDataLinkIsSet)
    {
        val[utility::conversions::to_string_t("ImageDataLink")] = ModelBase::toJson(m_ImageDataLink);
    }
    if(m_LeftIsSet)
    {
        val[utility::conversions::to_string_t("Left")] = ModelBase::toJson(m_Left);
    }
    if(m_OleDataLinkIsSet)
    {
        val[utility::conversions::to_string_t("OleDataLink")] = ModelBase::toJson(m_OleDataLink);
    }
    if(m_RelativeHorizontalPositionIsSet)
    {
        val[utility::conversions::to_string_t("RelativeHorizontalPosition")] = ModelBase::toJson(m_RelativeHorizontalPosition);
    }
    if(m_RelativeVerticalPositionIsSet)
    {
        val[utility::conversions::to_string_t("RelativeVerticalPosition")] = ModelBase::toJson(m_RelativeVerticalPosition);
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_RenderLinks.begin(), m_RenderLinks.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<WordsApiLink> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[utility::conversions::to_string_t("RenderLinks")] = web::json::value::array(jsonArray);
        }
    }
    if(m_TopIsSet)
    {
        val[utility::conversions::to_string_t("Top")] = ModelBase::toJson(m_Top);
    }
    if(m_WidthIsSet)
    {
        val[utility::conversions::to_string_t("Width")] = ModelBase::toJson(m_Width);
    }
    if(m_WrapTypeIsSet)
    {
        val[utility::conversions::to_string_t("WrapType")] = ModelBase::toJson(m_WrapType);
    }

    return val;
}

void DrawingObject::fromJson(web::json::value& val)
{
    this->DrawingObjectLink::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("Height")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Height")];
        if(!fieldValue.is_null())
        {
            setHeight(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ImageDataLink")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ImageDataLink")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromJson(fieldValue);
            setImageDataLink( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Left")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Left")];
        if(!fieldValue.is_null())
        {
            setLeft(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("OleDataLink")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("OleDataLink")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromJson(fieldValue);
            setOleDataLink( newItem );
        }
    }
    if(val.has_field(utility::conversions::to_string_t("RelativeHorizontalPosition")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("RelativeHorizontalPosition")];
        if(!fieldValue.is_null())
        {
            setRelativeHorizontalPosition(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("RelativeVerticalPosition")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("RelativeVerticalPosition")];
        if(!fieldValue.is_null())
        {
            setRelativeVerticalPosition(ModelBase::stringFromJson(fieldValue));
        }
    }
    {
        m_RenderLinks.clear();
        if(val.has_field(utility::conversions::to_string_t("RenderLinks")) 
                            && !val[utility::conversions::to_string_t("RenderLinks")].is_null())
        {
        auto arr = val[utility::conversions::to_string_t("RenderLinks")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_RenderLinks), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<WordsApiLink>(nullptr);
            }
            else
            {
                std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
    if(val.has_field(utility::conversions::to_string_t("Top")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Top")];
        if(!fieldValue.is_null())
        {
            setTop(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Width")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Width")];
        if(!fieldValue.is_null())
        {
            setWidth(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("WrapType")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("WrapType")];
        if(!fieldValue.is_null())
        {
            setWrapType(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void DrawingObject::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, utility::conversions::to_string_t("link."));
        }
        
    }
    if(m_NodeIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("NodeId"), m_NodeId));
        
    }
    if(m_HeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Height"), m_Height));
    }
    if(m_ImageDataLinkIsSet)
    {
        if (m_ImageDataLink.get())
        {
            m_ImageDataLink->toMultipart(multipart, utility::conversions::to_string_t("ImageDataLink."));
        }
        
    }
    if(m_LeftIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Left"), m_Left));
    }
    if(m_OleDataLinkIsSet)
    {
        if (m_OleDataLink.get())
        {
            m_OleDataLink->toMultipart(multipart, utility::conversions::to_string_t("OleDataLink."));
        }
        
    }
    if(m_RelativeHorizontalPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RelativeHorizontalPosition"), m_RelativeHorizontalPosition));
        
    }
    if(m_RelativeVerticalPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RelativeVerticalPosition"), m_RelativeVerticalPosition));
        
    }
    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_RenderLinks.begin(), m_RenderLinks.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<WordsApiLink> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RenderLinks"), web::json::value::array(jsonArray), utility::conversions::to_string_t("application/json")));
        }
    }
    if(m_TopIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Top"), m_Top));
    }
    if(m_WidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Width"), m_Width));
    }
    if(m_WrapTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("WrapType"), m_WrapType));
        
    }
}

void DrawingObject::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("link")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("NodeId")))
    {
        setNodeId(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("NodeId"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Height")))
    {
        setHeight(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Height"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ImageDataLink")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("ImageDataLink")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("ImageDataLink."));
            setImageDataLink( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Left")))
    {
        setLeft(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Left"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("OleDataLink")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("OleDataLink")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("OleDataLink."));
            setOleDataLink( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("RelativeHorizontalPosition")))
    {
        setRelativeHorizontalPosition(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RelativeHorizontalPosition"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("RelativeVerticalPosition")))
    {
        setRelativeVerticalPosition(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RelativeVerticalPosition"))));
    }
    {
        m_RenderLinks.clear();
        if(multipart->hasContent(utility::conversions::to_string_t("RenderLinks")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RenderLinks")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_RenderLinks), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<WordsApiLink>(nullptr) ;
            }
            else
            {
                std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Top")))
    {
        setTop(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Top"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Width")))
    {
        setWidth(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Width"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("WrapType")))
    {
        setWrapType(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("WrapType"))));
    }
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

