/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableProperties.cpp">
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


#include "TableProperties.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TableProperties::TableProperties()
{
    m_Alignment = utility::conversions::to_string_t("");
    m_AlignmentIsSet = false;
    m_AllowAutoFit = false;
    m_AllowAutoFitIsSet = false;
    m_Bidi = false;
    m_BidiIsSet = false;
    m_BottomPadding = 0.0;
    m_BottomPaddingIsSet = false;
    m_CellSpacing = 0.0;
    m_CellSpacingIsSet = false;
    m_LeftIndent = 0.0;
    m_LeftIndentIsSet = false;
    m_LeftPadding = 0.0;
    m_LeftPaddingIsSet = false;
    m_PreferredWidthIsSet = false;
    m_RightPadding = 0.0;
    m_RightPaddingIsSet = false;
    m_StyleIdentifier = utility::conversions::to_string_t("");
    m_StyleIdentifierIsSet = false;
    m_StyleName = utility::conversions::to_string_t("");
    m_StyleNameIsSet = false;
    m_StyleOptions = utility::conversions::to_string_t("");
    m_StyleOptionsIsSet = false;
    m_TextWrapping = utility::conversions::to_string_t("");
    m_TextWrappingIsSet = false;
    m_TopPadding = 0.0;
    m_TopPaddingIsSet = false;
}

TableProperties::~TableProperties()
{
}

void TableProperties::validate()
{
    // TODO: implement validation
}

web::json::value TableProperties::toJson() const
{
    web::json::value val = this->LinkElement::toJson();

    if(m_AlignmentIsSet)
    {
        val[_XPLATSTR("Alignment")] = ModelBase::toJson(m_Alignment);
    }
    if(m_AllowAutoFitIsSet)
    {
        val[_XPLATSTR("AllowAutoFit")] = ModelBase::toJson(m_AllowAutoFit);
    }
    if(m_BidiIsSet)
    {
        val[_XPLATSTR("Bidi")] = ModelBase::toJson(m_Bidi);
    }
    if(m_BottomPaddingIsSet)
    {
        val[_XPLATSTR("BottomPadding")] = ModelBase::toJson(m_BottomPadding);
    }
    if(m_CellSpacingIsSet)
    {
        val[_XPLATSTR("CellSpacing")] = ModelBase::toJson(m_CellSpacing);
    }
    if(m_LeftIndentIsSet)
    {
        val[_XPLATSTR("LeftIndent")] = ModelBase::toJson(m_LeftIndent);
    }
    if(m_LeftPaddingIsSet)
    {
        val[_XPLATSTR("LeftPadding")] = ModelBase::toJson(m_LeftPadding);
    }
    if(m_PreferredWidthIsSet)
    {
        val[_XPLATSTR("PreferredWidth")] = ModelBase::toJson(m_PreferredWidth);
    }
    if(m_RightPaddingIsSet)
    {
        val[_XPLATSTR("RightPadding")] = ModelBase::toJson(m_RightPadding);
    }
    if(m_StyleIdentifierIsSet)
    {
        val[_XPLATSTR("StyleIdentifier")] = ModelBase::toJson(m_StyleIdentifier);
    }
    if(m_StyleNameIsSet)
    {
        val[_XPLATSTR("StyleName")] = ModelBase::toJson(m_StyleName);
    }
    if(m_StyleOptionsIsSet)
    {
        val[_XPLATSTR("StyleOptions")] = ModelBase::toJson(m_StyleOptions);
    }
    if(m_TextWrappingIsSet)
    {
        val[_XPLATSTR("TextWrapping")] = ModelBase::toJson(m_TextWrapping);
    }
    if(m_TopPaddingIsSet)
    {
        val[_XPLATSTR("TopPadding")] = ModelBase::toJson(m_TopPadding);
    }

    return val;
}

void TableProperties::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("Alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Alignment")];
        if(!fieldValue.is_null())
        {
            setAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("AllowAutoFit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AllowAutoFit")];
        if(!fieldValue.is_null())
        {
            setAllowAutoFit(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Bidi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Bidi")];
        if(!fieldValue.is_null())
        {
            setBidi(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("BottomPadding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BottomPadding")];
        if(!fieldValue.is_null())
        {
            setBottomPadding(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CellSpacing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CellSpacing")];
        if(!fieldValue.is_null())
        {
            setCellSpacing(ModelBase::double?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LeftIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LeftIndent")];
        if(!fieldValue.is_null())
        {
            setLeftIndent(ModelBase::double?FromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("StyleIdentifier")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleIdentifier")];
        if(!fieldValue.is_null())
        {
            setStyleIdentifier(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("StyleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleName")];
        if(!fieldValue.is_null())
        {
            setStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("StyleOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleOptions")];
        if(!fieldValue.is_null())
        {
            setStyleOptions(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TextWrapping")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextWrapping")];
        if(!fieldValue.is_null())
        {
            setTextWrapping(ModelBase::stringFromJson(fieldValue));
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
}

void TableProperties::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_AlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Alignment"), m_Alignment));
        
    }
    if(m_AllowAutoFitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AllowAutoFit"), m_AllowAutoFit));
        
    }
    if(m_BidiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Bidi"), m_Bidi));
        
    }
    if(m_BottomPaddingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BottomPadding"), m_BottomPadding));
        
    }
    if(m_CellSpacingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CellSpacing"), m_CellSpacing));
        
    }
    if(m_LeftIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LeftIndent"), m_LeftIndent));
        
    }
    if(m_LeftPaddingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LeftPadding"), m_LeftPadding));
        
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
    if(m_StyleIdentifierIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleIdentifier"), m_StyleIdentifier));
        
    }
    if(m_StyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleName"), m_StyleName));
        
    }
    if(m_StyleOptionsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleOptions"), m_StyleOptions));
        
    }
    if(m_TextWrappingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextWrapping"), m_TextWrapping));
        
    }
    if(m_TopPaddingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TopPadding"), m_TopPadding));
        
    }
}

void TableProperties::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    LinkElement::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("Alignment")))
    {
        setAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Alignment"))));
    }
    if(multipart->hasContent(_XPLATSTR("AllowAutoFit")))
    {
        setAllowAutoFit(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("AllowAutoFit"))));
    }
    if(multipart->hasContent(_XPLATSTR("Bidi")))
    {
        setBidi(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("Bidi"))));
    }
    if(multipart->hasContent(_XPLATSTR("BottomPadding")))
    {
        setBottomPadding(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("BottomPadding"))));
    }
    if(multipart->hasContent(_XPLATSTR("CellSpacing")))
    {
        setCellSpacing(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("CellSpacing"))));
    }
    if(multipart->hasContent(_XPLATSTR("LeftIndent")))
    {
        setLeftIndent(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("LeftIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("LeftPadding")))
    {
        setLeftPadding(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("LeftPadding"))));
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
    if(multipart->hasContent(_XPLATSTR("StyleIdentifier")))
    {
        setStyleIdentifier(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StyleIdentifier"))));
    }
    if(multipart->hasContent(_XPLATSTR("StyleName")))
    {
        setStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StyleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("StyleOptions")))
    {
        setStyleOptions(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StyleOptions"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextWrapping")))
    {
        setTextWrapping(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextWrapping"))));
    }
    if(multipart->hasContent(_XPLATSTR("TopPadding")))
    {
        setTopPadding(ModelBase::double?FromHttpContent(multipart->getContent(_XPLATSTR("TopPadding"))));
    }
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableProperties::getAlignment() const
{
    return m_Alignment;
}


void TableProperties::setAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Alignment = value;
    m_AlignmentIsSet = true;
}
bool TableProperties::alignmentIsSet() const
{
    return m_AlignmentIsSet;
}

void TableProperties::unsetAlignment()
{
    m_AlignmentIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TableProperties::isAllowAutoFit() const
{
    return m_AllowAutoFit;
}


void TableProperties::setAllowAutoFit(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_AllowAutoFit = value;
    m_AllowAutoFitIsSet = true;
}
bool TableProperties::allowAutoFitIsSet() const
{
    return m_AllowAutoFitIsSet;
}

void TableProperties::unsetAllowAutoFit()
{
    m_AllowAutoFitIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TableProperties::isBidi() const
{
    return m_Bidi;
}


void TableProperties::setBidi(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_Bidi = value;
    m_BidiIsSet = true;
}
bool TableProperties::bidiIsSet() const
{
    return m_BidiIsSet;
}

void TableProperties::unsetBidi()
{
    m_BidiIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableProperties::getBottomPadding() const
{
    return m_BottomPadding;
}


void TableProperties::setBottomPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_BottomPadding = value;
    m_BottomPaddingIsSet = true;
}
bool TableProperties::bottomPaddingIsSet() const
{
    return m_BottomPaddingIsSet;
}

void TableProperties::unsetBottomPadding()
{
    m_BottomPaddingIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableProperties::getCellSpacing() const
{
    return m_CellSpacing;
}


void TableProperties::setCellSpacing(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_CellSpacing = value;
    m_CellSpacingIsSet = true;
}
bool TableProperties::cellSpacingIsSet() const
{
    return m_CellSpacingIsSet;
}

void TableProperties::unsetCellSpacing()
{
    m_CellSpacingIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableProperties::getLeftIndent() const
{
    return m_LeftIndent;
}


void TableProperties::setLeftIndent(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_LeftIndent = value;
    m_LeftIndentIsSet = true;
}
bool TableProperties::leftIndentIsSet() const
{
    return m_LeftIndentIsSet;
}

void TableProperties::unsetLeftIndent()
{
    m_LeftIndentIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableProperties::getLeftPadding() const
{
    return m_LeftPadding;
}


void TableProperties::setLeftPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_LeftPadding = value;
    m_LeftPaddingIsSet = true;
}
bool TableProperties::leftPaddingIsSet() const
{
    return m_LeftPaddingIsSet;
}

void TableProperties::unsetLeftPadding()
{
    m_LeftPaddingIsSet = false;
}

<DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> TableProperties::getPreferredWidth() const
{
    return m_PreferredWidth;
}


void TableProperties::setPreferredWidth(<DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> value)
{
    m_PreferredWidth = value;
    m_PreferredWidthIsSet = true;
}
bool TableProperties::preferredWidthIsSet() const
{
    return m_PreferredWidthIsSet;
}

void TableProperties::unsetPreferredWidth()
{
    m_PreferredWidthIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableProperties::getRightPadding() const
{
    return m_RightPadding;
}


void TableProperties::setRightPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_RightPadding = value;
    m_RightPaddingIsSet = true;
}
bool TableProperties::rightPaddingIsSet() const
{
    return m_RightPaddingIsSet;
}

void TableProperties::unsetRightPadding()
{
    m_RightPaddingIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableProperties::getStyleIdentifier() const
{
    return m_StyleIdentifier;
}


void TableProperties::setStyleIdentifier(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_StyleIdentifier = value;
    m_StyleIdentifierIsSet = true;
}
bool TableProperties::styleIdentifierIsSet() const
{
    return m_StyleIdentifierIsSet;
}

void TableProperties::unsetStyleIdentifier()
{
    m_StyleIdentifierIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableProperties::getStyleName() const
{
    return m_StyleName;
}


void TableProperties::setStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_StyleName = value;
    m_StyleNameIsSet = true;
}
bool TableProperties::styleNameIsSet() const
{
    return m_StyleNameIsSet;
}

void TableProperties::unsetStyleName()
{
    m_StyleNameIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableProperties::getStyleOptions() const
{
    return m_StyleOptions;
}


void TableProperties::setStyleOptions(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_StyleOptions = value;
    m_StyleOptionsIsSet = true;
}
bool TableProperties::styleOptionsIsSet() const
{
    return m_StyleOptionsIsSet;
}

void TableProperties::unsetStyleOptions()
{
    m_StyleOptionsIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TableProperties::getTextWrapping() const
{
    return m_TextWrapping;
}


void TableProperties::setTextWrapping(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_TextWrapping = value;
    m_TextWrappingIsSet = true;
}
bool TableProperties::textWrappingIsSet() const
{
    return m_TextWrappingIsSet;
}

void TableProperties::unsetTextWrapping()
{
    m_TextWrappingIsSet = false;
}

<DATA_TYPE_START>double?<DATA_TYPE_END> TableProperties::getTopPadding() const
{
    return m_TopPadding;
}


void TableProperties::setTopPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value)
{
    m_TopPadding = value;
    m_TopPaddingIsSet = true;
}
bool TableProperties::topPaddingIsSet() const
{
    return m_TopPaddingIsSet;
}

void TableProperties::unsetTopPadding()
{
    m_TopPaddingIsSet = false;
}

}
}
}
}
}

