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
        val[_XPLATSTR("addSpaceBetweenFarEastAndAlpha")] = ModelBase::toJson(m_AddSpaceBetweenFarEastAndAlpha);
    }
    if(m_AddSpaceBetweenFarEastAndDigitIsSet)
    {
        val[_XPLATSTR("addSpaceBetweenFarEastAndDigit")] = ModelBase::toJson(m_AddSpaceBetweenFarEastAndDigit);
    }
    if(m_AlignmentIsSet)
    {
        val[_XPLATSTR("alignment")] = ModelBase::toJson(m_Alignment);
    }
    if(m_BidiIsSet)
    {
        val[_XPLATSTR("bidi")] = ModelBase::toJson(m_Bidi);
    }
    if(m_DropCapPositionIsSet)
    {
        val[_XPLATSTR("dropCapPosition")] = ModelBase::toJson(m_DropCapPosition);
    }
    if(m_FirstLineIndentIsSet)
    {
        val[_XPLATSTR("firstLineIndent")] = ModelBase::toJson(m_FirstLineIndent);
    }
    if(m_IsListItemIsSet)
    {
        val[_XPLATSTR("isListItem")] = ModelBase::toJson(m_IsListItem);
    }
    if(m_KeepTogetherIsSet)
    {
        val[_XPLATSTR("keepTogether")] = ModelBase::toJson(m_KeepTogether);
    }
    if(m_KeepWithNextIsSet)
    {
        val[_XPLATSTR("keepWithNext")] = ModelBase::toJson(m_KeepWithNext);
    }
    if(m_LeftIndentIsSet)
    {
        val[_XPLATSTR("leftIndent")] = ModelBase::toJson(m_LeftIndent);
    }
    if(m_LineSpacingIsSet)
    {
        val[_XPLATSTR("lineSpacing")] = ModelBase::toJson(m_LineSpacing);
    }
    if(m_LineSpacingRuleIsSet)
    {
        val[_XPLATSTR("lineSpacingRule")] = ModelBase::toJson(m_LineSpacingRule);
    }
    if(m_LinesToDropIsSet)
    {
        val[_XPLATSTR("linesToDrop")] = ModelBase::toJson(m_LinesToDrop);
    }
    if(m_NoSpaceBetweenParagraphsOfSameStyleIsSet)
    {
        val[_XPLATSTR("noSpaceBetweenParagraphsOfSameStyle")] = ModelBase::toJson(m_NoSpaceBetweenParagraphsOfSameStyle);
    }
    if(m_OutlineLevelIsSet)
    {
        val[_XPLATSTR("outlineLevel")] = ModelBase::toJson(m_OutlineLevel);
    }
    if(m_PageBreakBeforeIsSet)
    {
        val[_XPLATSTR("pageBreakBefore")] = ModelBase::toJson(m_PageBreakBefore);
    }
    if(m_RightIndentIsSet)
    {
        val[_XPLATSTR("rightIndent")] = ModelBase::toJson(m_RightIndent);
    }
    if(m_SpaceAfterIsSet)
    {
        val[_XPLATSTR("spaceAfter")] = ModelBase::toJson(m_SpaceAfter);
    }
    if(m_SpaceAfterAutoIsSet)
    {
        val[_XPLATSTR("spaceAfterAuto")] = ModelBase::toJson(m_SpaceAfterAuto);
    }
    if(m_SpaceBeforeIsSet)
    {
        val[_XPLATSTR("spaceBefore")] = ModelBase::toJson(m_SpaceBefore);
    }
    if(m_SpaceBeforeAutoIsSet)
    {
        val[_XPLATSTR("spaceBeforeAuto")] = ModelBase::toJson(m_SpaceBeforeAuto);
    }
    if(m_StyleIdentifierIsSet)
    {
        val[_XPLATSTR("styleIdentifier")] = ModelBase::toJson(m_StyleIdentifier);
    }
    if(m_StyleNameIsSet)
    {
        val[_XPLATSTR("styleName")] = ModelBase::toJson(m_StyleName);
    }
    if(m_SuppressAutoHyphensIsSet)
    {
        val[_XPLATSTR("suppressAutoHyphens")] = ModelBase::toJson(m_SuppressAutoHyphens);
    }
    if(m_SuppressLineNumbersIsSet)
    {
        val[_XPLATSTR("suppressLineNumbers")] = ModelBase::toJson(m_SuppressLineNumbers);
    }
    if(m_WidowControlIsSet)
    {
        val[_XPLATSTR("widowControl")] = ModelBase::toJson(m_WidowControl);
    }

    return val;
}

void ParagraphFormat::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("addSpaceBetweenFarEastAndAlpha")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("addSpaceBetweenFarEastAndAlpha")];
        if(!fieldValue.is_null())
        {
            setAddSpaceBetweenFarEastAndAlpha(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("addSpaceBetweenFarEastAndDigit")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("addSpaceBetweenFarEastAndDigit")];
        if(!fieldValue.is_null())
        {
            setAddSpaceBetweenFarEastAndDigit(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("alignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("alignment")];
        if(!fieldValue.is_null())
        {
            setAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("bidi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("bidi")];
        if(!fieldValue.is_null())
        {
            setBidi(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("dropCapPosition")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("dropCapPosition")];
        if(!fieldValue.is_null())
        {
            setDropCapPosition(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("firstLineIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("firstLineIndent")];
        if(!fieldValue.is_null())
        {
            setFirstLineIndent(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("isListItem")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("isListItem")];
        if(!fieldValue.is_null())
        {
            setIsListItem(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("keepTogether")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("keepTogether")];
        if(!fieldValue.is_null())
        {
            setKeepTogether(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("keepWithNext")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("keepWithNext")];
        if(!fieldValue.is_null())
        {
            setKeepWithNext(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("leftIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("leftIndent")];
        if(!fieldValue.is_null())
        {
            setLeftIndent(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineSpacing")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineSpacing")];
        if(!fieldValue.is_null())
        {
            setLineSpacing(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineSpacingRule")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineSpacingRule")];
        if(!fieldValue.is_null())
        {
            setLineSpacingRule(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("linesToDrop")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("linesToDrop")];
        if(!fieldValue.is_null())
        {
            setLinesToDrop(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("noSpaceBetweenParagraphsOfSameStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("noSpaceBetweenParagraphsOfSameStyle")];
        if(!fieldValue.is_null())
        {
            setNoSpaceBetweenParagraphsOfSameStyle(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("outlineLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("outlineLevel")];
        if(!fieldValue.is_null())
        {
            setOutlineLevel(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageBreakBefore")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageBreakBefore")];
        if(!fieldValue.is_null())
        {
            setPageBreakBefore(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("rightIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rightIndent")];
        if(!fieldValue.is_null())
        {
            setRightIndent(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("spaceAfter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("spaceAfter")];
        if(!fieldValue.is_null())
        {
            setSpaceAfter(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("spaceAfterAuto")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("spaceAfterAuto")];
        if(!fieldValue.is_null())
        {
            setSpaceAfterAuto(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("spaceBefore")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("spaceBefore")];
        if(!fieldValue.is_null())
        {
            setSpaceBefore(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("spaceBeforeAuto")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("spaceBeforeAuto")];
        if(!fieldValue.is_null())
        {
            setSpaceBeforeAuto(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("styleIdentifier")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("styleIdentifier")];
        if(!fieldValue.is_null())
        {
            setStyleIdentifier(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("styleName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("styleName")];
        if(!fieldValue.is_null())
        {
            setStyleName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("suppressAutoHyphens")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("suppressAutoHyphens")];
        if(!fieldValue.is_null())
        {
            setSuppressAutoHyphens(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("suppressLineNumbers")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("suppressLineNumbers")];
        if(!fieldValue.is_null())
        {
            setSuppressLineNumbers(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("widowControl")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("widowControl")];
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("addSpaceBetweenFarEastAndAlpha"), m_AddSpaceBetweenFarEastAndAlpha));
    }
    if(m_AddSpaceBetweenFarEastAndDigitIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("addSpaceBetweenFarEastAndDigit"), m_AddSpaceBetweenFarEastAndDigit));
    }
    if(m_AlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("alignment"), m_Alignment));
        
    }
    if(m_BidiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bidi"), m_Bidi));
    }
    if(m_DropCapPositionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dropCapPosition"), m_DropCapPosition));
        
    }
    if(m_FirstLineIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("firstLineIndent"), m_FirstLineIndent));
    }
    if(m_IsListItemIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("isListItem"), m_IsListItem));
    }
    if(m_KeepTogetherIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("keepTogether"), m_KeepTogether));
    }
    if(m_KeepWithNextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("keepWithNext"), m_KeepWithNext));
    }
    if(m_LeftIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("leftIndent"), m_LeftIndent));
    }
    if(m_LineSpacingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineSpacing"), m_LineSpacing));
    }
    if(m_LineSpacingRuleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineSpacingRule"), m_LineSpacingRule));
        
    }
    if(m_LinesToDropIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("linesToDrop"), m_LinesToDrop));
    }
    if(m_NoSpaceBetweenParagraphsOfSameStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("noSpaceBetweenParagraphsOfSameStyle"), m_NoSpaceBetweenParagraphsOfSameStyle));
    }
    if(m_OutlineLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("outlineLevel"), m_OutlineLevel));
        
    }
    if(m_PageBreakBeforeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageBreakBefore"), m_PageBreakBefore));
    }
    if(m_RightIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("rightIndent"), m_RightIndent));
    }
    if(m_SpaceAfterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("spaceAfter"), m_SpaceAfter));
    }
    if(m_SpaceAfterAutoIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("spaceAfterAuto"), m_SpaceAfterAuto));
    }
    if(m_SpaceBeforeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("spaceBefore"), m_SpaceBefore));
    }
    if(m_SpaceBeforeAutoIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("spaceBeforeAuto"), m_SpaceBeforeAuto));
    }
    if(m_StyleIdentifierIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("styleIdentifier"), m_StyleIdentifier));
        
    }
    if(m_StyleNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("styleName"), m_StyleName));
        
    }
    if(m_SuppressAutoHyphensIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("suppressAutoHyphens"), m_SuppressAutoHyphens));
    }
    if(m_SuppressLineNumbersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("suppressLineNumbers"), m_SuppressLineNumbers));
    }
    if(m_WidowControlIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("widowControl"), m_WidowControl));
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
    if(multipart->hasContent(_XPLATSTR("addSpaceBetweenFarEastAndAlpha")))
    {
        setAddSpaceBetweenFarEastAndAlpha(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("addSpaceBetweenFarEastAndAlpha"))));
    }
    if(multipart->hasContent(_XPLATSTR("addSpaceBetweenFarEastAndDigit")))
    {
        setAddSpaceBetweenFarEastAndDigit(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("addSpaceBetweenFarEastAndDigit"))));
    }
    if(multipart->hasContent(_XPLATSTR("alignment")))
    {
        setAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("alignment"))));
    }
    if(multipart->hasContent(_XPLATSTR("bidi")))
    {
        setBidi(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("bidi"))));
    }
    if(multipart->hasContent(_XPLATSTR("dropCapPosition")))
    {
        setDropCapPosition(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("dropCapPosition"))));
    }
    if(multipart->hasContent(_XPLATSTR("firstLineIndent")))
    {
        setFirstLineIndent(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("firstLineIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("isListItem")))
    {
        setIsListItem(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("isListItem"))));
    }
    if(multipart->hasContent(_XPLATSTR("keepTogether")))
    {
        setKeepTogether(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("keepTogether"))));
    }
    if(multipart->hasContent(_XPLATSTR("keepWithNext")))
    {
        setKeepWithNext(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("keepWithNext"))));
    }
    if(multipart->hasContent(_XPLATSTR("leftIndent")))
    {
        setLeftIndent(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("leftIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineSpacing")))
    {
        setLineSpacing(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("lineSpacing"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineSpacingRule")))
    {
        setLineSpacingRule(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("lineSpacingRule"))));
    }
    if(multipart->hasContent(_XPLATSTR("linesToDrop")))
    {
        setLinesToDrop(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("linesToDrop"))));
    }
    if(multipart->hasContent(_XPLATSTR("noSpaceBetweenParagraphsOfSameStyle")))
    {
        setNoSpaceBetweenParagraphsOfSameStyle(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("noSpaceBetweenParagraphsOfSameStyle"))));
    }
    if(multipart->hasContent(_XPLATSTR("outlineLevel")))
    {
        setOutlineLevel(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("outlineLevel"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageBreakBefore")))
    {
        setPageBreakBefore(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("pageBreakBefore"))));
    }
    if(multipart->hasContent(_XPLATSTR("rightIndent")))
    {
        setRightIndent(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("rightIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("spaceAfter")))
    {
        setSpaceAfter(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("spaceAfter"))));
    }
    if(multipart->hasContent(_XPLATSTR("spaceAfterAuto")))
    {
        setSpaceAfterAuto(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("spaceAfterAuto"))));
    }
    if(multipart->hasContent(_XPLATSTR("spaceBefore")))
    {
        setSpaceBefore(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("spaceBefore"))));
    }
    if(multipart->hasContent(_XPLATSTR("spaceBeforeAuto")))
    {
        setSpaceBeforeAuto(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("spaceBeforeAuto"))));
    }
    if(multipart->hasContent(_XPLATSTR("styleIdentifier")))
    {
        setStyleIdentifier(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("styleIdentifier"))));
    }
    if(multipart->hasContent(_XPLATSTR("styleName")))
    {
        setStyleName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("styleName"))));
    }
    if(multipart->hasContent(_XPLATSTR("suppressAutoHyphens")))
    {
        setSuppressAutoHyphens(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("suppressAutoHyphens"))));
    }
    if(multipart->hasContent(_XPLATSTR("suppressLineNumbers")))
    {
        setSuppressLineNumbers(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("suppressLineNumbers"))));
    }
    if(multipart->hasContent(_XPLATSTR("widowControl")))
    {
        setWidowControl(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("widowControl"))));
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

