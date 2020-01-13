/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ParagraphFormat.cpp">
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


#include "ParagraphFormat.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

ParagraphFormat::ParagraphFormat()
{
    m_AddSpaceBetweenFarEastAndAlpha = false;
    m_AddSpaceBetweenFarEastAndAlphaIsSet = false;
    m_AddSpaceBetweenFarEastAndDigit = false;
    m_AddSpaceBetweenFarEastAndDigitIsSet = false;
    m_Alignment = utility::conversions::to_string_t("");
    m_AlignmentIsSet = false;
    m_Bidi = false;
    m_BidiIsSet = false;
    m_DropCapPosition = utility::conversions::to_string_t("");
    m_DropCapPositionIsSet = false;
    m_FirstLineIndent = 0.0;
    m_FirstLineIndentIsSet = false;
    m_IsListItem = false;
    m_IsListItemIsSet = false;
    m_KeepTogether = false;
    m_KeepTogetherIsSet = false;
    m_KeepWithNext = false;
    m_KeepWithNextIsSet = false;
    m_LeftIndent = 0.0;
    m_LeftIndentIsSet = false;
    m_LineSpacing = 0.0;
    m_LineSpacingIsSet = false;
    m_LineSpacingRule = utility::conversions::to_string_t("");
    m_LineSpacingRuleIsSet = false;
    m_LinesToDrop = 0;
    m_LinesToDropIsSet = false;
    m_NoSpaceBetweenParagraphsOfSameStyle = false;
    m_NoSpaceBetweenParagraphsOfSameStyleIsSet = false;
    m_OutlineLevel = utility::conversions::to_string_t("");
    m_OutlineLevelIsSet = false;
    m_PageBreakBefore = false;
    m_PageBreakBeforeIsSet = false;
    m_RightIndent = 0.0;
    m_RightIndentIsSet = false;
    m_SpaceAfter = 0.0;
    m_SpaceAfterIsSet = false;
    m_SpaceAfterAuto = false;
    m_SpaceAfterAutoIsSet = false;
    m_SpaceBefore = 0.0;
    m_SpaceBeforeIsSet = false;
    m_SpaceBeforeAuto = false;
    m_SpaceBeforeAutoIsSet = false;
    m_StyleIdentifier = utility::conversions::to_string_t("");
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

ParagraphFormat::~ParagraphFormat()
{
}

void ParagraphFormat::validate()
{
    // TODO: implement validation
}

web::json::value ParagraphFormat::toJson() const
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
    if(m_IsListItemIsSet)
    {
        val[_XPLATSTR("IsListItem")] = ModelBase::toJson(m_IsListItem);
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

void ParagraphFormat::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("AddSpaceBetweenFarEastAndAlpha")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AddSpaceBetweenFarEastAndAlpha")];
        if(!fieldValue.is_null())
        {
            setAddSpaceBetweenFarEastAndAlpha(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("AddSpaceBetweenFarEastAndDigit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AddSpaceBetweenFarEastAndDigit")];
        if(!fieldValue.is_null())
        {
            setAddSpaceBetweenFarEastAndDigit(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Alignment")];
        if(!fieldValue.is_null())
        {
            setAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Bidi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Bidi")];
        if(!fieldValue.is_null())
        {
            setBidi(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("DropCapPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DropCapPosition")];
        if(!fieldValue.is_null())
        {
            setDropCapPosition(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FirstLineIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FirstLineIndent")];
        if(!fieldValue.is_null())
        {
            setFirstLineIndent(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("IsListItem")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("IsListItem")];
        if(!fieldValue.is_null())
        {
            setIsListItem(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("KeepTogether")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("KeepTogether")];
        if(!fieldValue.is_null())
        {
            setKeepTogether(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("KeepWithNext")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("KeepWithNext")];
        if(!fieldValue.is_null())
        {
            setKeepWithNext(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LeftIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LeftIndent")];
        if(!fieldValue.is_null())
        {
            setLeftIndent(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LineSpacing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineSpacing")];
        if(!fieldValue.is_null())
        {
            setLineSpacing(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LineSpacingRule")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineSpacingRule")];
        if(!fieldValue.is_null())
        {
            setLineSpacingRule(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("LinesToDrop")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LinesToDrop")];
        if(!fieldValue.is_null())
        {
            setLinesToDrop(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle")];
        if(!fieldValue.is_null())
        {
            setNoSpaceBetweenParagraphsOfSameStyle(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OutlineLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OutlineLevel")];
        if(!fieldValue.is_null())
        {
            setOutlineLevel(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PageBreakBefore")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageBreakBefore")];
        if(!fieldValue.is_null())
        {
            setPageBreakBefore(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("RightIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RightIndent")];
        if(!fieldValue.is_null())
        {
            setRightIndent(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SpaceAfter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceAfter")];
        if(!fieldValue.is_null())
        {
            setSpaceAfter(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SpaceAfterAuto")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceAfterAuto")];
        if(!fieldValue.is_null())
        {
            setSpaceAfterAuto(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SpaceBefore")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceBefore")];
        if(!fieldValue.is_null())
        {
            setSpaceBefore(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SpaceBeforeAuto")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SpaceBeforeAuto")];
        if(!fieldValue.is_null())
        {
            setSpaceBeforeAuto(ModelBase::boolFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("SuppressAutoHyphens")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SuppressAutoHyphens")];
        if(!fieldValue.is_null())
        {
            setSuppressAutoHyphens(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SuppressLineNumbers")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SuppressLineNumbers")];
        if(!fieldValue.is_null())
        {
            setSuppressLineNumbers(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("WidowControl")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("WidowControl")];
        if(!fieldValue.is_null())
        {
            setWidowControl(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void ParagraphFormat::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
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
    if(m_IsListItemIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("IsListItem"), m_IsListItem));
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

void ParagraphFormat::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("AddSpaceBetweenFarEastAndAlpha")))
    {
        setAddSpaceBetweenFarEastAndAlpha(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("AddSpaceBetweenFarEastAndAlpha"))));
    }
    if(multipart->hasContent(_XPLATSTR("AddSpaceBetweenFarEastAndDigit")))
    {
        setAddSpaceBetweenFarEastAndDigit(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("AddSpaceBetweenFarEastAndDigit"))));
    }
    if(multipart->hasContent(_XPLATSTR("Alignment")))
    {
        setAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Alignment"))));
    }
    if(multipart->hasContent(_XPLATSTR("Bidi")))
    {
        setBidi(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("Bidi"))));
    }
    if(multipart->hasContent(_XPLATSTR("DropCapPosition")))
    {
        setDropCapPosition(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DropCapPosition"))));
    }
    if(multipart->hasContent(_XPLATSTR("FirstLineIndent")))
    {
        setFirstLineIndent(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("FirstLineIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("IsListItem")))
    {
        setIsListItem(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("IsListItem"))));
    }
    if(multipart->hasContent(_XPLATSTR("KeepTogether")))
    {
        setKeepTogether(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("KeepTogether"))));
    }
    if(multipart->hasContent(_XPLATSTR("KeepWithNext")))
    {
        setKeepWithNext(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("KeepWithNext"))));
    }
    if(multipart->hasContent(_XPLATSTR("LeftIndent")))
    {
        setLeftIndent(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("LeftIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("LineSpacing")))
    {
        setLineSpacing(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("LineSpacing"))));
    }
    if(multipart->hasContent(_XPLATSTR("LineSpacingRule")))
    {
        setLineSpacingRule(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("LineSpacingRule"))));
    }
    if(multipart->hasContent(_XPLATSTR("LinesToDrop")))
    {
        setLinesToDrop(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("LinesToDrop"))));
    }
    if(multipart->hasContent(_XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle")))
    {
        setNoSpaceBetweenParagraphsOfSameStyle(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("NoSpaceBetweenParagraphsOfSameStyle"))));
    }
    if(multipart->hasContent(_XPLATSTR("OutlineLevel")))
    {
        setOutlineLevel(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("OutlineLevel"))));
    }
    if(multipart->hasContent(_XPLATSTR("PageBreakBefore")))
    {
        setPageBreakBefore(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("PageBreakBefore"))));
    }
    if(multipart->hasContent(_XPLATSTR("RightIndent")))
    {
        setRightIndent(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("RightIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("SpaceAfter")))
    {
        setSpaceAfter(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("SpaceAfter"))));
    }
    if(multipart->hasContent(_XPLATSTR("SpaceAfterAuto")))
    {
        setSpaceAfterAuto(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("SpaceAfterAuto"))));
    }
    if(multipart->hasContent(_XPLATSTR("SpaceBefore")))
    {
        setSpaceBefore(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("SpaceBefore"))));
    }
    if(multipart->hasContent(_XPLATSTR("SpaceBeforeAuto")))
    {
        setSpaceBeforeAuto(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("SpaceBeforeAuto"))));
    }
    if(multipart->hasContent(_XPLATSTR("StyleIdentifier")))
    {
        setStyleIdentifier(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StyleIdentifier"))));
    }
    if(multipart->hasContent(_XPLATSTR("StyleName")))
    {
        setStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StyleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("SuppressAutoHyphens")))
    {
        setSuppressAutoHyphens(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("SuppressAutoHyphens"))));
    }
    if(multipart->hasContent(_XPLATSTR("SuppressLineNumbers")))
    {
        setSuppressLineNumbers(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("SuppressLineNumbers"))));
    }
    if(multipart->hasContent(_XPLATSTR("WidowControl")))
    {
        setWidowControl(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("WidowControl"))));
    }
}

bool ParagraphFormat::isAddSpaceBetweenFarEastAndAlpha() const
{
    return m_AddSpaceBetweenFarEastAndAlpha;
}


void ParagraphFormat::setAddSpaceBetweenFarEastAndAlpha(bool value)
{
    m_AddSpaceBetweenFarEastAndAlpha = value;
    m_AddSpaceBetweenFarEastAndAlphaIsSet = true;
}
bool ParagraphFormat::addSpaceBetweenFarEastAndAlphaIsSet() const
{
    return m_AddSpaceBetweenFarEastAndAlphaIsSet;
}

void ParagraphFormat::unsetAddSpaceBetweenFarEastAndAlpha()
{
    m_AddSpaceBetweenFarEastAndAlphaIsSet = false;
}

bool ParagraphFormat::isAddSpaceBetweenFarEastAndDigit() const
{
    return m_AddSpaceBetweenFarEastAndDigit;
}


void ParagraphFormat::setAddSpaceBetweenFarEastAndDigit(bool value)
{
    m_AddSpaceBetweenFarEastAndDigit = value;
    m_AddSpaceBetweenFarEastAndDigitIsSet = true;
}
bool ParagraphFormat::addSpaceBetweenFarEastAndDigitIsSet() const
{
    return m_AddSpaceBetweenFarEastAndDigitIsSet;
}

void ParagraphFormat::unsetAddSpaceBetweenFarEastAndDigit()
{
    m_AddSpaceBetweenFarEastAndDigitIsSet = false;
}

utility::string_t ParagraphFormat::getAlignment() const
{
    return m_Alignment;
}


void ParagraphFormat::setAlignment(utility::string_t value)
{
    m_Alignment = value;
    m_AlignmentIsSet = true;
}
bool ParagraphFormat::alignmentIsSet() const
{
    return m_AlignmentIsSet;
}

void ParagraphFormat::unsetAlignment()
{
    m_AlignmentIsSet = false;
}

bool ParagraphFormat::isBidi() const
{
    return m_Bidi;
}


void ParagraphFormat::setBidi(bool value)
{
    m_Bidi = value;
    m_BidiIsSet = true;
}
bool ParagraphFormat::bidiIsSet() const
{
    return m_BidiIsSet;
}

void ParagraphFormat::unsetBidi()
{
    m_BidiIsSet = false;
}

utility::string_t ParagraphFormat::getDropCapPosition() const
{
    return m_DropCapPosition;
}


void ParagraphFormat::setDropCapPosition(utility::string_t value)
{
    m_DropCapPosition = value;
    m_DropCapPositionIsSet = true;
}
bool ParagraphFormat::dropCapPositionIsSet() const
{
    return m_DropCapPositionIsSet;
}

void ParagraphFormat::unsetDropCapPosition()
{
    m_DropCapPositionIsSet = false;
}

double ParagraphFormat::getFirstLineIndent() const
{
    return m_FirstLineIndent;
}


void ParagraphFormat::setFirstLineIndent(double value)
{
    m_FirstLineIndent = value;
    m_FirstLineIndentIsSet = true;
}
bool ParagraphFormat::firstLineIndentIsSet() const
{
    return m_FirstLineIndentIsSet;
}

void ParagraphFormat::unsetFirstLineIndent()
{
    m_FirstLineIndentIsSet = false;
}

bool ParagraphFormat::isIsListItem() const
{
    return m_IsListItem;
}


void ParagraphFormat::setIsListItem(bool value)
{
    m_IsListItem = value;
    m_IsListItemIsSet = true;
}
bool ParagraphFormat::isListItemIsSet() const
{
    return m_IsListItemIsSet;
}

void ParagraphFormat::unsetIsListItem()
{
    m_IsListItemIsSet = false;
}

bool ParagraphFormat::isKeepTogether() const
{
    return m_KeepTogether;
}


void ParagraphFormat::setKeepTogether(bool value)
{
    m_KeepTogether = value;
    m_KeepTogetherIsSet = true;
}
bool ParagraphFormat::keepTogetherIsSet() const
{
    return m_KeepTogetherIsSet;
}

void ParagraphFormat::unsetKeepTogether()
{
    m_KeepTogetherIsSet = false;
}

bool ParagraphFormat::isKeepWithNext() const
{
    return m_KeepWithNext;
}


void ParagraphFormat::setKeepWithNext(bool value)
{
    m_KeepWithNext = value;
    m_KeepWithNextIsSet = true;
}
bool ParagraphFormat::keepWithNextIsSet() const
{
    return m_KeepWithNextIsSet;
}

void ParagraphFormat::unsetKeepWithNext()
{
    m_KeepWithNextIsSet = false;
}

double ParagraphFormat::getLeftIndent() const
{
    return m_LeftIndent;
}


void ParagraphFormat::setLeftIndent(double value)
{
    m_LeftIndent = value;
    m_LeftIndentIsSet = true;
}
bool ParagraphFormat::leftIndentIsSet() const
{
    return m_LeftIndentIsSet;
}

void ParagraphFormat::unsetLeftIndent()
{
    m_LeftIndentIsSet = false;
}

double ParagraphFormat::getLineSpacing() const
{
    return m_LineSpacing;
}


void ParagraphFormat::setLineSpacing(double value)
{
    m_LineSpacing = value;
    m_LineSpacingIsSet = true;
}
bool ParagraphFormat::lineSpacingIsSet() const
{
    return m_LineSpacingIsSet;
}

void ParagraphFormat::unsetLineSpacing()
{
    m_LineSpacingIsSet = false;
}

utility::string_t ParagraphFormat::getLineSpacingRule() const
{
    return m_LineSpacingRule;
}


void ParagraphFormat::setLineSpacingRule(utility::string_t value)
{
    m_LineSpacingRule = value;
    m_LineSpacingRuleIsSet = true;
}
bool ParagraphFormat::lineSpacingRuleIsSet() const
{
    return m_LineSpacingRuleIsSet;
}

void ParagraphFormat::unsetLineSpacingRule()
{
    m_LineSpacingRuleIsSet = false;
}

int32_t ParagraphFormat::getLinesToDrop() const
{
    return m_LinesToDrop;
}


void ParagraphFormat::setLinesToDrop(int32_t value)
{
    m_LinesToDrop = value;
    m_LinesToDropIsSet = true;
}
bool ParagraphFormat::linesToDropIsSet() const
{
    return m_LinesToDropIsSet;
}

void ParagraphFormat::unsetLinesToDrop()
{
    m_LinesToDropIsSet = false;
}

bool ParagraphFormat::isNoSpaceBetweenParagraphsOfSameStyle() const
{
    return m_NoSpaceBetweenParagraphsOfSameStyle;
}


void ParagraphFormat::setNoSpaceBetweenParagraphsOfSameStyle(bool value)
{
    m_NoSpaceBetweenParagraphsOfSameStyle = value;
    m_NoSpaceBetweenParagraphsOfSameStyleIsSet = true;
}
bool ParagraphFormat::noSpaceBetweenParagraphsOfSameStyleIsSet() const
{
    return m_NoSpaceBetweenParagraphsOfSameStyleIsSet;
}

void ParagraphFormat::unsetNoSpaceBetweenParagraphsOfSameStyle()
{
    m_NoSpaceBetweenParagraphsOfSameStyleIsSet = false;
}

utility::string_t ParagraphFormat::getOutlineLevel() const
{
    return m_OutlineLevel;
}


void ParagraphFormat::setOutlineLevel(utility::string_t value)
{
    m_OutlineLevel = value;
    m_OutlineLevelIsSet = true;
}
bool ParagraphFormat::outlineLevelIsSet() const
{
    return m_OutlineLevelIsSet;
}

void ParagraphFormat::unsetOutlineLevel()
{
    m_OutlineLevelIsSet = false;
}

bool ParagraphFormat::isPageBreakBefore() const
{
    return m_PageBreakBefore;
}


void ParagraphFormat::setPageBreakBefore(bool value)
{
    m_PageBreakBefore = value;
    m_PageBreakBeforeIsSet = true;
}
bool ParagraphFormat::pageBreakBeforeIsSet() const
{
    return m_PageBreakBeforeIsSet;
}

void ParagraphFormat::unsetPageBreakBefore()
{
    m_PageBreakBeforeIsSet = false;
}

double ParagraphFormat::getRightIndent() const
{
    return m_RightIndent;
}


void ParagraphFormat::setRightIndent(double value)
{
    m_RightIndent = value;
    m_RightIndentIsSet = true;
}
bool ParagraphFormat::rightIndentIsSet() const
{
    return m_RightIndentIsSet;
}

void ParagraphFormat::unsetRightIndent()
{
    m_RightIndentIsSet = false;
}

double ParagraphFormat::getSpaceAfter() const
{
    return m_SpaceAfter;
}


void ParagraphFormat::setSpaceAfter(double value)
{
    m_SpaceAfter = value;
    m_SpaceAfterIsSet = true;
}
bool ParagraphFormat::spaceAfterIsSet() const
{
    return m_SpaceAfterIsSet;
}

void ParagraphFormat::unsetSpaceAfter()
{
    m_SpaceAfterIsSet = false;
}

bool ParagraphFormat::isSpaceAfterAuto() const
{
    return m_SpaceAfterAuto;
}


void ParagraphFormat::setSpaceAfterAuto(bool value)
{
    m_SpaceAfterAuto = value;
    m_SpaceAfterAutoIsSet = true;
}
bool ParagraphFormat::spaceAfterAutoIsSet() const
{
    return m_SpaceAfterAutoIsSet;
}

void ParagraphFormat::unsetSpaceAfterAuto()
{
    m_SpaceAfterAutoIsSet = false;
}

double ParagraphFormat::getSpaceBefore() const
{
    return m_SpaceBefore;
}


void ParagraphFormat::setSpaceBefore(double value)
{
    m_SpaceBefore = value;
    m_SpaceBeforeIsSet = true;
}
bool ParagraphFormat::spaceBeforeIsSet() const
{
    return m_SpaceBeforeIsSet;
}

void ParagraphFormat::unsetSpaceBefore()
{
    m_SpaceBeforeIsSet = false;
}

bool ParagraphFormat::isSpaceBeforeAuto() const
{
    return m_SpaceBeforeAuto;
}


void ParagraphFormat::setSpaceBeforeAuto(bool value)
{
    m_SpaceBeforeAuto = value;
    m_SpaceBeforeAutoIsSet = true;
}
bool ParagraphFormat::spaceBeforeAutoIsSet() const
{
    return m_SpaceBeforeAutoIsSet;
}

void ParagraphFormat::unsetSpaceBeforeAuto()
{
    m_SpaceBeforeAutoIsSet = false;
}

utility::string_t ParagraphFormat::getStyleIdentifier() const
{
    return m_StyleIdentifier;
}


void ParagraphFormat::setStyleIdentifier(utility::string_t value)
{
    m_StyleIdentifier = value;
    m_StyleIdentifierIsSet = true;
}
bool ParagraphFormat::styleIdentifierIsSet() const
{
    return m_StyleIdentifierIsSet;
}

void ParagraphFormat::unsetStyleIdentifier()
{
    m_StyleIdentifierIsSet = false;
}

utility::string_t ParagraphFormat::getStyleName() const
{
    return m_StyleName;
}


void ParagraphFormat::setStyleName(utility::string_t value)
{
    m_StyleName = value;
    m_StyleNameIsSet = true;
}
bool ParagraphFormat::styleNameIsSet() const
{
    return m_StyleNameIsSet;
}

void ParagraphFormat::unsetStyleName()
{
    m_StyleNameIsSet = false;
}

bool ParagraphFormat::isSuppressAutoHyphens() const
{
    return m_SuppressAutoHyphens;
}


void ParagraphFormat::setSuppressAutoHyphens(bool value)
{
    m_SuppressAutoHyphens = value;
    m_SuppressAutoHyphensIsSet = true;
}
bool ParagraphFormat::suppressAutoHyphensIsSet() const
{
    return m_SuppressAutoHyphensIsSet;
}

void ParagraphFormat::unsetSuppressAutoHyphens()
{
    m_SuppressAutoHyphensIsSet = false;
}

bool ParagraphFormat::isSuppressLineNumbers() const
{
    return m_SuppressLineNumbers;
}


void ParagraphFormat::setSuppressLineNumbers(bool value)
{
    m_SuppressLineNumbers = value;
    m_SuppressLineNumbersIsSet = true;
}
bool ParagraphFormat::suppressLineNumbersIsSet() const
{
    return m_SuppressLineNumbersIsSet;
}

void ParagraphFormat::unsetSuppressLineNumbers()
{
    m_SuppressLineNumbersIsSet = false;
}

bool ParagraphFormat::isWidowControl() const
{
    return m_WidowControl;
}


void ParagraphFormat::setWidowControl(bool value)
{
    m_WidowControl = value;
    m_WidowControlIsSet = true;
}
bool ParagraphFormat::widowControlIsSet() const
{
    return m_WidowControlIsSet;
}

void ParagraphFormat::unsetWidowControl()
{
    m_WidowControlIsSet = false;
}

}
}
}
}
}

