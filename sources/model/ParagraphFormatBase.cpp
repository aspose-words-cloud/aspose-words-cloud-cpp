/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ParagraphFormatBase.cpp">
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

#include "ParagraphFormatBase.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ParagraphFormatBase::ParagraphFormatBase()
{
    m_AddSpaceBetweenFarEastAndAlpha = false;
    m_AddSpaceBetweenFarEastAndAlphaIsSet = false;
    m_AddSpaceBetweenFarEastAndDigit = false;
    m_AddSpaceBetweenFarEastAndDigitIsSet = false;

    m_AlignmentIsSet = false;
    m_Bidi = false;
    m_BidiIsSet = false;

    m_DropCapPositionIsSet = false;
    m_FirstLineIndent = 0.0;
    m_FirstLineIndentIsSet = false;
    m_KeepTogether = false;
    m_KeepTogetherIsSet = false;
    m_KeepWithNext = false;
    m_KeepWithNextIsSet = false;
    m_LeftIndent = 0.0;
    m_LeftIndentIsSet = false;
    m_LineSpacing = 0.0;
    m_LineSpacingIsSet = false;

    m_LineSpacingRuleIsSet = false;
    m_LinesToDrop = 0;
    m_LinesToDropIsSet = false;
    m_NoSpaceBetweenParagraphsOfSameStyle = false;
    m_NoSpaceBetweenParagraphsOfSameStyleIsSet = false;

    m_OutlineLevelIsSet = false;
    m_PageBreakBefore = false;
    m_PageBreakBeforeIsSet = false;
    m_RightIndent = 0.0;
    m_RightIndentIsSet = false;

    m_ShadingIsSet = false;
    m_SpaceAfter = 0.0;
    m_SpaceAfterIsSet = false;
    m_SpaceAfterAuto = false;
    m_SpaceAfterAutoIsSet = false;
    m_SpaceBefore = 0.0;
    m_SpaceBeforeIsSet = false;
    m_SpaceBeforeAuto = false;
    m_SpaceBeforeAutoIsSet = false;

    m_StyleIdentifierIsSet = false;
    m_StyleName = utility::conversions::to_string_t("");
    m_StyleNameIsSet = false;
    m_SuppressAutoHyphens = false;
    m_SuppressAutoHyphensIsSet = false;
    m_SuppressLineNumbers = false;
    m_SuppressLineNumbersIsSet = false;
    m_WidowControl = false;
    m_WidowControlIsSet = false;

}

ParagraphFormatBase::~ParagraphFormatBase()
{
}

void ParagraphFormatBase::validate()
{
    // TODO: implement validation
}

web::json::value ParagraphFormatBase::toJson() const
{
    web::json::value val = this->LinkElement::toJson();
    if(m_AddSpaceBetweenFarEastAndAlphaIsSet)
    {
        val[_XPLATSTR("AddSpaceBetweenFarEastAndAlpha")] = ModelBase::toJson(m_AddSpaceBetweenFarEastAndAlpha);
    }
    if(m_AddSpaceBetweenFarEastAndDigitIsSet)
    {
        val[_XPLATSTR("AddSpaceBetweenFarEastAndDigit")] = ModelBase::toJson(m_AddSpaceBetweenFarEastAndDigit);
    }
    if(m_AlignmentIsSet)
    {
        val[_XPLATSTR("Alignment")] = ModelBase::toJson(m_Alignment);
    }
    if(m_BidiIsSet)
    {
        val[_XPLATSTR("Bidi")] = ModelBase::toJson(m_Bidi);
    }
    if(m_DropCapPositionIsSet)
    {
        val[_XPLATSTR("DropCapPosition")] = ModelBase::toJson(m_DropCapPosition);
    }
    if(m_FirstLineIndentIsSet)
    {
        val[_XPLATSTR("FirstLineIndent")] = ModelBase::toJson(m_FirstLineIndent);
    }
    if(m_KeepTogetherIsSet)
    {
        val[_XPLATSTR("KeepTogether")] = ModelBase::toJson(m_KeepTogether);
    }
    if(m_KeepWithNextIsSet)
    {
        val[_XPLATSTR("KeepWithNext")] = ModelBase::toJson(m_KeepWithNext);
    }
    if(m_LeftIndentIsSet)
    {
        val[_XPLATSTR("LeftIndent")] = ModelBase::toJson(m_LeftIndent);
    }
    if(m_LineSpacingIsSet)
    {
        val[_XPLATSTR("LineSpacing")] = ModelBase::toJson(m_LineSpacing);
    }
    if(m_LineSpacingRuleIsSet)
    {
        val[_XPLATSTR("LineSpacingRule")] = ModelBase::toJson(m_LineSpacingRule);
    }
    if(m_LinesToDropIsSet)
    {
        val[_XPLATSTR("LinesToDrop")] = ModelBase::toJson(m_LinesToDrop);
    }
    if(m_NoSpaceBetweenParagraphsOfSameStyleIsSet)
    {
        val[_XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle")] = ModelBase::toJson(m_NoSpaceBetweenParagraphsOfSameStyle);
    }
    if(m_OutlineLevelIsSet)
    {
        val[_XPLATSTR("OutlineLevel")] = ModelBase::toJson(m_OutlineLevel);
    }
    if(m_PageBreakBeforeIsSet)
    {
        val[_XPLATSTR("PageBreakBefore")] = ModelBase::toJson(m_PageBreakBefore);
    }
    if(m_RightIndentIsSet)
    {
        val[_XPLATSTR("RightIndent")] = ModelBase::toJson(m_RightIndent);
    }
    if(m_ShadingIsSet)
    {
        val[_XPLATSTR("Shading")] = ModelBase::toJson(m_Shading);
    }
    if(m_SpaceAfterIsSet)
    {
        val[_XPLATSTR("SpaceAfter")] = ModelBase::toJson(m_SpaceAfter);
    }
    if(m_SpaceAfterAutoIsSet)
    {
        val[_XPLATSTR("SpaceAfterAuto")] = ModelBase::toJson(m_SpaceAfterAuto);
    }
    if(m_SpaceBeforeIsSet)
    {
        val[_XPLATSTR("SpaceBefore")] = ModelBase::toJson(m_SpaceBefore);
    }
    if(m_SpaceBeforeAutoIsSet)
    {
        val[_XPLATSTR("SpaceBeforeAuto")] = ModelBase::toJson(m_SpaceBeforeAuto);
    }
    if(m_StyleIdentifierIsSet)
    {
        val[_XPLATSTR("StyleIdentifier")] = ModelBase::toJson(m_StyleIdentifier);
    }
    if(m_StyleNameIsSet)
    {
        val[_XPLATSTR("StyleName")] = ModelBase::toJson(m_StyleName);
    }
    if(m_SuppressAutoHyphensIsSet)
    {
        val[_XPLATSTR("SuppressAutoHyphens")] = ModelBase::toJson(m_SuppressAutoHyphens);
    }
    if(m_SuppressLineNumbersIsSet)
    {
        val[_XPLATSTR("SuppressLineNumbers")] = ModelBase::toJson(m_SuppressLineNumbers);
    }
    if(m_WidowControlIsSet)
    {
        val[_XPLATSTR("WidowControl")] = ModelBase::toJson(m_WidowControl);
    }

    return val;
}

void ParagraphFormatBase::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("AddSpaceBetweenFarEastAndAlpha")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AddSpaceBetweenFarEastAndAlpha")];
        if(!fieldValue.is_null())
        {
           setAddSpaceBetweenFarEastAndAlpha(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("AddSpaceBetweenFarEastAndDigit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AddSpaceBetweenFarEastAndDigit")];
        if(!fieldValue.is_null())
        {
           setAddSpaceBetweenFarEastAndDigit(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Alignment")];
        if(!fieldValue.is_null())
        {
           setAlignment(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Bidi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Bidi")];
        if(!fieldValue.is_null())
        {
           setBidi(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("DropCapPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DropCapPosition")];
        if(!fieldValue.is_null())
        {
           setDropCapPosition(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("FirstLineIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FirstLineIndent")];
        if(!fieldValue.is_null())
        {
           setFirstLineIndent(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("KeepTogether")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("KeepTogether")];
        if(!fieldValue.is_null())
        {
           setKeepTogether(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("KeepWithNext")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("KeepWithNext")];
        if(!fieldValue.is_null())
        {
           setKeepWithNext(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LeftIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LeftIndent")];
        if(!fieldValue.is_null())
        {
           setLeftIndent(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LineSpacing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineSpacing")];
        if(!fieldValue.is_null())
        {
           setLineSpacing(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LineSpacingRule")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineSpacingRule")];
        if(!fieldValue.is_null())
        {
           setLineSpacingRule(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LinesToDrop")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LinesToDrop")];
        if(!fieldValue.is_null())
        {
           setLinesToDrop(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle")];
        if(!fieldValue.is_null())
        {
           setNoSpaceBetweenParagraphsOfSameStyle(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("OutlineLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OutlineLevel")];
        if(!fieldValue.is_null())
        {
           setOutlineLevel(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PageBreakBefore")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageBreakBefore")];
        if(!fieldValue.is_null())
        {
           setPageBreakBefore(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RightIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RightIndent")];
        if(!fieldValue.is_null())
        {
           setRightIndent(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Shading")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Shading")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<Shading> newItem(new Shading());
            newItem->fromJson(fieldValue);
            setShading( newItem );
        }
    }


    if(val.has_field(_XPLATSTR("SpaceAfter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceAfter")];
        if(!fieldValue.is_null())
        {
           setSpaceAfter(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SpaceAfterAuto")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceAfterAuto")];
        if(!fieldValue.is_null())
        {
           setSpaceAfterAuto(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SpaceBefore")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceBefore")];
        if(!fieldValue.is_null())
        {
           setSpaceBefore(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SpaceBeforeAuto")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceBeforeAuto")];
        if(!fieldValue.is_null())
        {
           setSpaceBeforeAuto(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("StyleIdentifier")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StyleIdentifier")];
        if(!fieldValue.is_null())
        {
           setStyleIdentifier(ModelBase::enumFromJson(fieldValue));
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


    if(val.has_field(_XPLATSTR("SuppressAutoHyphens")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SuppressAutoHyphens")];
        if(!fieldValue.is_null())
        {
           setSuppressAutoHyphens(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SuppressLineNumbers")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SuppressLineNumbers")];
        if(!fieldValue.is_null())
        {
           setSuppressLineNumbers(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("WidowControl")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WidowControl")];
        if(!fieldValue.is_null())
        {
           setWidowControl(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void ParagraphFormatBase::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_AddSpaceBetweenFarEastAndAlphaIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AddSpaceBetweenFarEastAndAlpha"), m_AddSpaceBetweenFarEastAndAlpha));
    }


    if(m_AddSpaceBetweenFarEastAndDigitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AddSpaceBetweenFarEastAndDigit"), m_AddSpaceBetweenFarEastAndDigit));
    }


    if(m_AlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Alignment"), m_Alignment));
    }


    if(m_BidiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Bidi"), m_Bidi));
    }


    if(m_DropCapPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DropCapPosition"), m_DropCapPosition));
    }


    if(m_FirstLineIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FirstLineIndent"), m_FirstLineIndent));
    }


    if(m_KeepTogetherIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("KeepTogether"), m_KeepTogether));
    }


    if(m_KeepWithNextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("KeepWithNext"), m_KeepWithNext));
    }


    if(m_LeftIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LeftIndent"), m_LeftIndent));
    }


    if(m_LineSpacingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineSpacing"), m_LineSpacing));
    }


    if(m_LineSpacingRuleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineSpacingRule"), m_LineSpacingRule));
    }


    if(m_LinesToDropIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LinesToDrop"), m_LinesToDrop));
    }


    if(m_NoSpaceBetweenParagraphsOfSameStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle"), m_NoSpaceBetweenParagraphsOfSameStyle));
    }


    if(m_OutlineLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OutlineLevel"), m_OutlineLevel));
    }


    if(m_PageBreakBeforeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageBreakBefore"), m_PageBreakBefore));
    }


    if(m_RightIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RightIndent"), m_RightIndent));
    }


    if(m_ShadingIsSet)
    {
        if (m_Shading.get())
        {
            m_Shading->toMultipart(multipart, _XPLATSTR("Shading."));
        }
    }


    if(m_SpaceAfterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SpaceAfter"), m_SpaceAfter));
    }


    if(m_SpaceAfterAutoIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SpaceAfterAuto"), m_SpaceAfterAuto));
    }


    if(m_SpaceBeforeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SpaceBefore"), m_SpaceBefore));
    }


    if(m_SpaceBeforeAutoIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SpaceBeforeAuto"), m_SpaceBeforeAuto));
    }


    if(m_StyleIdentifierIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleIdentifier"), m_StyleIdentifier));
    }


    if(m_StyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StyleName"), m_StyleName));
    }


    if(m_SuppressAutoHyphensIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SuppressAutoHyphens"), m_SuppressAutoHyphens));
    }


    if(m_SuppressLineNumbersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SuppressLineNumbers"), m_SuppressLineNumbers));
    }


    if(m_WidowControlIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("WidowControl"), m_WidowControl));
    }

}

void ParagraphFormatBase::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool ParagraphFormatBase::isAddSpaceBetweenFarEastAndAlpha() const
{
    return m_AddSpaceBetweenFarEastAndAlpha;
}


void ParagraphFormatBase::setAddSpaceBetweenFarEastAndAlpha(bool value)
{
    m_AddSpaceBetweenFarEastAndAlpha = value;
    m_AddSpaceBetweenFarEastAndAlphaIsSet = true;
}

bool ParagraphFormatBase::addSpaceBetweenFarEastAndAlphaIsSet() const
{
    return m_AddSpaceBetweenFarEastAndAlphaIsSet;
}

void ParagraphFormatBase::unsetAddSpaceBetweenFarEastAndAlpha()
{
    m_AddSpaceBetweenFarEastAndAlphaIsSet = false;
}

bool ParagraphFormatBase::isAddSpaceBetweenFarEastAndDigit() const
{
    return m_AddSpaceBetweenFarEastAndDigit;
}


void ParagraphFormatBase::setAddSpaceBetweenFarEastAndDigit(bool value)
{
    m_AddSpaceBetweenFarEastAndDigit = value;
    m_AddSpaceBetweenFarEastAndDigitIsSet = true;
}

bool ParagraphFormatBase::addSpaceBetweenFarEastAndDigitIsSet() const
{
    return m_AddSpaceBetweenFarEastAndDigitIsSet;
}

void ParagraphFormatBase::unsetAddSpaceBetweenFarEastAndDigit()
{
    m_AddSpaceBetweenFarEastAndDigitIsSet = false;
}

utility::string_t ParagraphFormatBase::getAlignment() const
{
    return m_Alignment;
}


void ParagraphFormatBase::setAlignment(utility::string_t value)
{
    m_Alignment = value;
    m_AlignmentIsSet = true;
}

bool ParagraphFormatBase::alignmentIsSet() const
{
    return m_AlignmentIsSet;
}

void ParagraphFormatBase::unsetAlignment()
{
    m_AlignmentIsSet = false;
}

bool ParagraphFormatBase::isBidi() const
{
    return m_Bidi;
}


void ParagraphFormatBase::setBidi(bool value)
{
    m_Bidi = value;
    m_BidiIsSet = true;
}

bool ParagraphFormatBase::bidiIsSet() const
{
    return m_BidiIsSet;
}

void ParagraphFormatBase::unsetBidi()
{
    m_BidiIsSet = false;
}

utility::string_t ParagraphFormatBase::getDropCapPosition() const
{
    return m_DropCapPosition;
}


void ParagraphFormatBase::setDropCapPosition(utility::string_t value)
{
    m_DropCapPosition = value;
    m_DropCapPositionIsSet = true;
}

bool ParagraphFormatBase::dropCapPositionIsSet() const
{
    return m_DropCapPositionIsSet;
}

void ParagraphFormatBase::unsetDropCapPosition()
{
    m_DropCapPositionIsSet = false;
}

double ParagraphFormatBase::getFirstLineIndent() const
{
    return m_FirstLineIndent;
}


void ParagraphFormatBase::setFirstLineIndent(double value)
{
    m_FirstLineIndent = value;
    m_FirstLineIndentIsSet = true;
}

bool ParagraphFormatBase::firstLineIndentIsSet() const
{
    return m_FirstLineIndentIsSet;
}

void ParagraphFormatBase::unsetFirstLineIndent()
{
    m_FirstLineIndentIsSet = false;
}

bool ParagraphFormatBase::isKeepTogether() const
{
    return m_KeepTogether;
}


void ParagraphFormatBase::setKeepTogether(bool value)
{
    m_KeepTogether = value;
    m_KeepTogetherIsSet = true;
}

bool ParagraphFormatBase::keepTogetherIsSet() const
{
    return m_KeepTogetherIsSet;
}

void ParagraphFormatBase::unsetKeepTogether()
{
    m_KeepTogetherIsSet = false;
}

bool ParagraphFormatBase::isKeepWithNext() const
{
    return m_KeepWithNext;
}


void ParagraphFormatBase::setKeepWithNext(bool value)
{
    m_KeepWithNext = value;
    m_KeepWithNextIsSet = true;
}

bool ParagraphFormatBase::keepWithNextIsSet() const
{
    return m_KeepWithNextIsSet;
}

void ParagraphFormatBase::unsetKeepWithNext()
{
    m_KeepWithNextIsSet = false;
}

double ParagraphFormatBase::getLeftIndent() const
{
    return m_LeftIndent;
}


void ParagraphFormatBase::setLeftIndent(double value)
{
    m_LeftIndent = value;
    m_LeftIndentIsSet = true;
}

bool ParagraphFormatBase::leftIndentIsSet() const
{
    return m_LeftIndentIsSet;
}

void ParagraphFormatBase::unsetLeftIndent()
{
    m_LeftIndentIsSet = false;
}

double ParagraphFormatBase::getLineSpacing() const
{
    return m_LineSpacing;
}


void ParagraphFormatBase::setLineSpacing(double value)
{
    m_LineSpacing = value;
    m_LineSpacingIsSet = true;
}

bool ParagraphFormatBase::lineSpacingIsSet() const
{
    return m_LineSpacingIsSet;
}

void ParagraphFormatBase::unsetLineSpacing()
{
    m_LineSpacingIsSet = false;
}

utility::string_t ParagraphFormatBase::getLineSpacingRule() const
{
    return m_LineSpacingRule;
}


void ParagraphFormatBase::setLineSpacingRule(utility::string_t value)
{
    m_LineSpacingRule = value;
    m_LineSpacingRuleIsSet = true;
}

bool ParagraphFormatBase::lineSpacingRuleIsSet() const
{
    return m_LineSpacingRuleIsSet;
}

void ParagraphFormatBase::unsetLineSpacingRule()
{
    m_LineSpacingRuleIsSet = false;
}

int32_t ParagraphFormatBase::getLinesToDrop() const
{
    return m_LinesToDrop;
}


void ParagraphFormatBase::setLinesToDrop(int32_t value)
{
    m_LinesToDrop = value;
    m_LinesToDropIsSet = true;
}

bool ParagraphFormatBase::linesToDropIsSet() const
{
    return m_LinesToDropIsSet;
}

void ParagraphFormatBase::unsetLinesToDrop()
{
    m_LinesToDropIsSet = false;
}

bool ParagraphFormatBase::isNoSpaceBetweenParagraphsOfSameStyle() const
{
    return m_NoSpaceBetweenParagraphsOfSameStyle;
}


void ParagraphFormatBase::setNoSpaceBetweenParagraphsOfSameStyle(bool value)
{
    m_NoSpaceBetweenParagraphsOfSameStyle = value;
    m_NoSpaceBetweenParagraphsOfSameStyleIsSet = true;
}

bool ParagraphFormatBase::noSpaceBetweenParagraphsOfSameStyleIsSet() const
{
    return m_NoSpaceBetweenParagraphsOfSameStyleIsSet;
}

void ParagraphFormatBase::unsetNoSpaceBetweenParagraphsOfSameStyle()
{
    m_NoSpaceBetweenParagraphsOfSameStyleIsSet = false;
}

utility::string_t ParagraphFormatBase::getOutlineLevel() const
{
    return m_OutlineLevel;
}


void ParagraphFormatBase::setOutlineLevel(utility::string_t value)
{
    m_OutlineLevel = value;
    m_OutlineLevelIsSet = true;
}

bool ParagraphFormatBase::outlineLevelIsSet() const
{
    return m_OutlineLevelIsSet;
}

void ParagraphFormatBase::unsetOutlineLevel()
{
    m_OutlineLevelIsSet = false;
}

bool ParagraphFormatBase::isPageBreakBefore() const
{
    return m_PageBreakBefore;
}


void ParagraphFormatBase::setPageBreakBefore(bool value)
{
    m_PageBreakBefore = value;
    m_PageBreakBeforeIsSet = true;
}

bool ParagraphFormatBase::pageBreakBeforeIsSet() const
{
    return m_PageBreakBeforeIsSet;
}

void ParagraphFormatBase::unsetPageBreakBefore()
{
    m_PageBreakBeforeIsSet = false;
}

double ParagraphFormatBase::getRightIndent() const
{
    return m_RightIndent;
}


void ParagraphFormatBase::setRightIndent(double value)
{
    m_RightIndent = value;
    m_RightIndentIsSet = true;
}

bool ParagraphFormatBase::rightIndentIsSet() const
{
    return m_RightIndentIsSet;
}

void ParagraphFormatBase::unsetRightIndent()
{
    m_RightIndentIsSet = false;
}

std::shared_ptr<Shading> ParagraphFormatBase::getShading() const
{
    return m_Shading;
}


void ParagraphFormatBase::setShading(std::shared_ptr<Shading> value)
{
    m_Shading = value;
    m_ShadingIsSet = true;
}

bool ParagraphFormatBase::shadingIsSet() const
{
    return m_ShadingIsSet;
}

void ParagraphFormatBase::unsetShading()
{
    m_ShadingIsSet = false;
}

double ParagraphFormatBase::getSpaceAfter() const
{
    return m_SpaceAfter;
}


void ParagraphFormatBase::setSpaceAfter(double value)
{
    m_SpaceAfter = value;
    m_SpaceAfterIsSet = true;
}

bool ParagraphFormatBase::spaceAfterIsSet() const
{
    return m_SpaceAfterIsSet;
}

void ParagraphFormatBase::unsetSpaceAfter()
{
    m_SpaceAfterIsSet = false;
}

bool ParagraphFormatBase::isSpaceAfterAuto() const
{
    return m_SpaceAfterAuto;
}


void ParagraphFormatBase::setSpaceAfterAuto(bool value)
{
    m_SpaceAfterAuto = value;
    m_SpaceAfterAutoIsSet = true;
}

bool ParagraphFormatBase::spaceAfterAutoIsSet() const
{
    return m_SpaceAfterAutoIsSet;
}

void ParagraphFormatBase::unsetSpaceAfterAuto()
{
    m_SpaceAfterAutoIsSet = false;
}

double ParagraphFormatBase::getSpaceBefore() const
{
    return m_SpaceBefore;
}


void ParagraphFormatBase::setSpaceBefore(double value)
{
    m_SpaceBefore = value;
    m_SpaceBeforeIsSet = true;
}

bool ParagraphFormatBase::spaceBeforeIsSet() const
{
    return m_SpaceBeforeIsSet;
}

void ParagraphFormatBase::unsetSpaceBefore()
{
    m_SpaceBeforeIsSet = false;
}

bool ParagraphFormatBase::isSpaceBeforeAuto() const
{
    return m_SpaceBeforeAuto;
}


void ParagraphFormatBase::setSpaceBeforeAuto(bool value)
{
    m_SpaceBeforeAuto = value;
    m_SpaceBeforeAutoIsSet = true;
}

bool ParagraphFormatBase::spaceBeforeAutoIsSet() const
{
    return m_SpaceBeforeAutoIsSet;
}

void ParagraphFormatBase::unsetSpaceBeforeAuto()
{
    m_SpaceBeforeAutoIsSet = false;
}

utility::string_t ParagraphFormatBase::getStyleIdentifier() const
{
    return m_StyleIdentifier;
}


void ParagraphFormatBase::setStyleIdentifier(utility::string_t value)
{
    m_StyleIdentifier = value;
    m_StyleIdentifierIsSet = true;
}

bool ParagraphFormatBase::styleIdentifierIsSet() const
{
    return m_StyleIdentifierIsSet;
}

void ParagraphFormatBase::unsetStyleIdentifier()
{
    m_StyleIdentifierIsSet = false;
}

utility::string_t ParagraphFormatBase::getStyleName() const
{
    return m_StyleName;
}


void ParagraphFormatBase::setStyleName(utility::string_t value)
{
    m_StyleName = value;
    m_StyleNameIsSet = true;
}

bool ParagraphFormatBase::styleNameIsSet() const
{
    return m_StyleNameIsSet;
}

void ParagraphFormatBase::unsetStyleName()
{
    m_StyleNameIsSet = false;
}

bool ParagraphFormatBase::isSuppressAutoHyphens() const
{
    return m_SuppressAutoHyphens;
}


void ParagraphFormatBase::setSuppressAutoHyphens(bool value)
{
    m_SuppressAutoHyphens = value;
    m_SuppressAutoHyphensIsSet = true;
}

bool ParagraphFormatBase::suppressAutoHyphensIsSet() const
{
    return m_SuppressAutoHyphensIsSet;
}

void ParagraphFormatBase::unsetSuppressAutoHyphens()
{
    m_SuppressAutoHyphensIsSet = false;
}

bool ParagraphFormatBase::isSuppressLineNumbers() const
{
    return m_SuppressLineNumbers;
}


void ParagraphFormatBase::setSuppressLineNumbers(bool value)
{
    m_SuppressLineNumbers = value;
    m_SuppressLineNumbersIsSet = true;
}

bool ParagraphFormatBase::suppressLineNumbersIsSet() const
{
    return m_SuppressLineNumbersIsSet;
}

void ParagraphFormatBase::unsetSuppressLineNumbers()
{
    m_SuppressLineNumbersIsSet = false;
}

bool ParagraphFormatBase::isWidowControl() const
{
    return m_WidowControl;
}


void ParagraphFormatBase::setWidowControl(bool value)
{
    m_WidowControl = value;
    m_WidowControlIsSet = true;
}

bool ParagraphFormatBase::widowControlIsSet() const
{
    return m_WidowControlIsSet;
}

void ParagraphFormatBase::unsetWidowControl()
{
    m_WidowControlIsSet = false;
}

}
}
}
}
}
