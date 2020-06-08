/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellFormat.cpp">
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


#include "TableCellFormat.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableCellFormat::TableCellFormat()
{
    m_BottomPadding = 0.0;
    m_BottomPaddingIsSet = false;
    m_FitText = false;
    m_FitTextIsSet = false;
    m_HorizontalMerge = utility::conversions::to_string_t("");
    m_HorizontalMergeIsSet = false;
    m_LeftPadding = 0.0;
    m_LeftPaddingIsSet = false;
    m_Orientation = utility::conversions::to_string_t("");
    m_OrientationIsSet = false;
    m_PreferredWidthIsSet = false;
    m_RightPadding = 0.0;
    m_RightPaddingIsSet = false;
    m_TopPadding = 0.0;
    m_TopPaddingIsSet = false;
    m_VerticalAlignment = utility::conversions::to_string_t("");
    m_VerticalAlignmentIsSet = false;
    m_VerticalMerge = utility::conversions::to_string_t("");
    m_VerticalMergeIsSet = false;
    m_Width = 0.0;
    m_WidthIsSet = false;
    m_WrapText = false;
    m_WrapTextIsSet = false;
}

TableCellFormat::~TableCellFormat()
{
}

void TableCellFormat::validate()
{
    // TODO: implement validation
}

web::json::value TableCellFormat::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_BottomPaddingIsSet)
    {
        val[_XPLATSTR("BottomPadding")] = ModelBase::toJson(m_BottomPadding);
    }
    if(m_FitTextIsSet)
    {
        val[_XPLATSTR("FitText")] = ModelBase::toJson(m_FitText);
    }
    if(m_HorizontalMergeIsSet)
    {
        val[_XPLATSTR("HorizontalMerge")] = ModelBase::toJson(m_HorizontalMerge);
    }
    if(m_LeftPaddingIsSet)
    {
        val[_XPLATSTR("LeftPadding")] = ModelBase::toJson(m_LeftPadding);
    }
    if(m_OrientationIsSet)
    {
        val[_XPLATSTR("Orientation")] = ModelBase::toJson(m_Orientation);
    }
    if(m_PreferredWidthIsSet)
    {
        val[_XPLATSTR("PreferredWidth")] = ModelBase::toJson(m_PreferredWidth);
    }
    if(m_RightPaddingIsSet)
    {
        val[_XPLATSTR("RightPadding")] = ModelBase::toJson(m_RightPadding);
    }
    if(m_TopPaddingIsSet)
    {
        val[_XPLATSTR("TopPadding")] = ModelBase::toJson(m_TopPadding);
    }
    if(m_VerticalAlignmentIsSet)
    {
        val[_XPLATSTR("VerticalAlignment")] = ModelBase::toJson(m_VerticalAlignment);
    }
    if(m_VerticalMergeIsSet)
    {
        val[_XPLATSTR("VerticalMerge")] = ModelBase::toJson(m_VerticalMerge);
    }
    if(m_WidthIsSet)
    {
        val[_XPLATSTR("Width")] = ModelBase::toJson(m_Width);
    }
    if(m_WrapTextIsSet)
    {
        val[_XPLATSTR("WrapText")] = ModelBase::toJson(m_WrapText);
    }

    return val;
}

void TableCellFormat::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("BottomPadding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BottomPadding")];
        if(!fieldValue.is_null())
        {
            setBottomPadding(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FitText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FitText")];
        if(!fieldValue.is_null())
        {
            setFitText(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("HorizontalMerge")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HorizontalMerge")];
        if(!fieldValue.is_null())
        {
            setHorizontalMerge(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LeftPadding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LeftPadding")];
        if(!fieldValue.is_null())
        {
            setLeftPadding(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Orientation")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Orientation")];
        if(!fieldValue.is_null())
        {
            setOrientation(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PreferredWidth")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PreferredWidth")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> newItem(new PreferredWidth());
            newItem->fromJson(fieldValue);
            setPreferredWidth( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("RightPadding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RightPadding")];
        if(!fieldValue.is_null())
        {
            setRightPadding(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TopPadding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TopPadding")];
        if(!fieldValue.is_null())
        {
            setTopPadding(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("VerticalAlignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("VerticalAlignment")];
        if(!fieldValue.is_null())
        {
            setVerticalAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("VerticalMerge")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("VerticalMerge")];
        if(!fieldValue.is_null())
        {
            setVerticalMerge(ModelBase::stringFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("WrapText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WrapText")];
        if(!fieldValue.is_null())
        {
            setWrapText(ModelBase::bool?FromJson(fieldValue));
        }
    }
}

void TableCellFormat::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_BottomPaddingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BottomPadding"), m_BottomPadding));
        
    }
    if(m_FitTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FitText"), m_FitText));
        
    }
    if(m_HorizontalMergeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HorizontalMerge"), m_HorizontalMerge));
        
    }
    if(m_LeftPaddingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LeftPadding"), m_LeftPadding));
        
    }
    if(m_OrientationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Orientation"), m_Orientation));
        
    }
    if(m_PreferredWidthIsSet)
    {
        if (m_PreferredWidth.get())
        {
            m_PreferredWidth->toMultipart(multipart, _XPLATSTR("PreferredWidth."));
        }
        
    }
    if(m_RightPaddingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RightPadding"), m_RightPadding));
        
    }
    if(m_TopPaddingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TopPadding"), m_TopPadding));
        
    }
    if(m_VerticalAlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("VerticalAlignment"), m_VerticalAlignment));
        
    }
    if(m_VerticalMergeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("VerticalMerge"), m_VerticalMerge));
        
    }
    if(m_WidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Width"), m_Width));
        
    }
    if(m_WrapTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("WrapText"), m_WrapText));
        
    }
}

void TableCellFormat::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    LinkElement::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("BottomPadding")))
    {
        setBottomPadding(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("BottomPadding"))));
    }
    if(multipart->hasContent(_XPLATSTR("FitText")))
    {
        setFitText(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("FitText"))));
    }
    if(multipart->hasContent(_XPLATSTR("HorizontalMerge")))
    {
        setHorizontalMerge(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("HorizontalMerge"))));
    }
    if(multipart->hasContent(_XPLATSTR("LeftPadding")))
    {
        setLeftPadding(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("LeftPadding"))));
    }
    if(multipart->hasContent(_XPLATSTR("Orientation")))
    {
        setOrientation(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Orientation"))));
    }
    if(multipart->hasContent(_XPLATSTR("PreferredWidth")))
    {
        if(multipart->hasContent(_XPLATSTR("PreferredWidth")))
        {
            <DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> newItem(new PreferredWidth());
            newItem->fromMultiPart(multipart, _XPLATSTR("PreferredWidth."));
            setPreferredWidth( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("RightPadding")))
    {
        setRightPadding(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("RightPadding"))));
    }
    if(multipart->hasContent(_XPLATSTR("TopPadding")))
    {
        setTopPadding(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("TopPadding"))));
    }
    if(multipart->hasContent(_XPLATSTR("VerticalAlignment")))
    {
        setVerticalAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("VerticalAlignment"))));
    }
    if(multipart->hasContent(_XPLATSTR("VerticalMerge")))
    {
        setVerticalMerge(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("VerticalMerge"))));
    }
    if(multipart->hasContent(_XPLATSTR("Width")))
    {
        setWidth(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("Width"))));
    }
    if(multipart->hasContent(_XPLATSTR("WrapText")))
    {
        setWrapText(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("WrapText"))));
    }
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableCellFormat::getBottomPadding() const
{
    return m_BottomPadding;
}


void TableCellFormat::setBottomPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_BottomPadding = value;
    m_BottomPaddingIsSet = true;
}
bool TableCellFormat::bottomPaddingIsSet() const
{
    return m_BottomPaddingIsSet;
}

void TableCellFormat::unsetBottomPadding()
{
    m_BottomPaddingIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TableCellFormat::isFitText() const
{
    return m_FitText;
}


void TableCellFormat::setFitText(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_FitText = value;
    m_FitTextIsSet = true;
}
bool TableCellFormat::fitTextIsSet() const
{
    return m_FitTextIsSet;
}

void TableCellFormat::unsetFitText()
{
    m_FitTextIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableCellFormat::getHorizontalMerge() const
{
    return m_HorizontalMerge;
}


void TableCellFormat::setHorizontalMerge(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_HorizontalMerge = value;
    m_HorizontalMergeIsSet = true;
}
bool TableCellFormat::horizontalMergeIsSet() const
{
    return m_HorizontalMergeIsSet;
}

void TableCellFormat::unsetHorizontalMerge()
{
    m_HorizontalMergeIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableCellFormat::getLeftPadding() const
{
    return m_LeftPadding;
}


void TableCellFormat::setLeftPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_LeftPadding = value;
    m_LeftPaddingIsSet = true;
}
bool TableCellFormat::leftPaddingIsSet() const
{
    return m_LeftPaddingIsSet;
}

void TableCellFormat::unsetLeftPadding()
{
    m_LeftPaddingIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableCellFormat::getOrientation() const
{
    return m_Orientation;
}


void TableCellFormat::setOrientation(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Orientation = value;
    m_OrientationIsSet = true;
}
bool TableCellFormat::orientationIsSet() const
{
    return m_OrientationIsSet;
}

void TableCellFormat::unsetOrientation()
{
    m_OrientationIsSet = false;
}

<DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> TableCellFormat::getPreferredWidth() const
{
    return m_PreferredWidth;
}


void TableCellFormat::setPreferredWidth(<DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> value)
{
    m_PreferredWidth = value;
    m_PreferredWidthIsSet = true;
}
bool TableCellFormat::preferredWidthIsSet() const
{
    return m_PreferredWidthIsSet;
}

void TableCellFormat::unsetPreferredWidth()
{
    m_PreferredWidthIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableCellFormat::getRightPadding() const
{
    return m_RightPadding;
}


void TableCellFormat::setRightPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_RightPadding = value;
    m_RightPaddingIsSet = true;
}
bool TableCellFormat::rightPaddingIsSet() const
{
    return m_RightPaddingIsSet;
}

void TableCellFormat::unsetRightPadding()
{
    m_RightPaddingIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableCellFormat::getTopPadding() const
{
    return m_TopPadding;
}


void TableCellFormat::setTopPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_TopPadding = value;
    m_TopPaddingIsSet = true;
}
bool TableCellFormat::topPaddingIsSet() const
{
    return m_TopPaddingIsSet;
}

void TableCellFormat::unsetTopPadding()
{
    m_TopPaddingIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableCellFormat::getVerticalAlignment() const
{
    return m_VerticalAlignment;
}


void TableCellFormat::setVerticalAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_VerticalAlignment = value;
    m_VerticalAlignmentIsSet = true;
}
bool TableCellFormat::verticalAlignmentIsSet() const
{
    return m_VerticalAlignmentIsSet;
}

void TableCellFormat::unsetVerticalAlignment()
{
    m_VerticalAlignmentIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableCellFormat::getVerticalMerge() const
{
    return m_VerticalMerge;
}


void TableCellFormat::setVerticalMerge(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_VerticalMerge = value;
    m_VerticalMergeIsSet = true;
}
bool TableCellFormat::verticalMergeIsSet() const
{
    return m_VerticalMergeIsSet;
}

void TableCellFormat::unsetVerticalMerge()
{
    m_VerticalMergeIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableCellFormat::getWidth() const
{
    return m_Width;
}


void TableCellFormat::setWidth(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_Width = value;
    m_WidthIsSet = true;
}
bool TableCellFormat::widthIsSet() const
{
    return m_WidthIsSet;
}

void TableCellFormat::unsetWidth()
{
    m_WidthIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TableCellFormat::isWrapText() const
{
    return m_WrapText;
}


void TableCellFormat::setWrapText(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_WrapText = value;
    m_WrapTextIsSet = true;
}
bool TableCellFormat::wrapTextIsSet() const
{
    return m_WrapTextIsSet;
}

void TableCellFormat::unsetWrapText()
{
    m_WrapTextIsSet = false;
}

}
}
}
}
}

