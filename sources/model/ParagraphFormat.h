/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ParagraphFormat.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ParagraphFormat_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ParagraphFormat_H_


#include "LinkElement.h"
#include "Shading.h"
#include "WordsApiLink.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Paragraph format element.             
/// </summary>
class  ParagraphFormat
    : public LinkElement
{
public:
    ParagraphFormat();
    virtual ~ParagraphFormat();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ParagraphFormat members

    /// <summary>
    /// Gets or sets a flag indicating whether inter-character spacing is automatically adjusted between regions of Latin text and regions of East Asian text in the current paragraph.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isAddSpaceBetweenFarEastAndAlpha() const;
    bool addSpaceBetweenFarEastAndAlphaIsSet() const;
    void unsetAddSpaceBetweenFarEastAndAlpha();
    void setAddSpaceBetweenFarEastAndAlpha(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a flag indicating whether inter-character spacing is automatically adjusted between regions of numbers and regions of East Asian text in the current paragraph.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isAddSpaceBetweenFarEastAndDigit() const;
    bool addSpaceBetweenFarEastAndDigitIsSet() const;
    void unsetAddSpaceBetweenFarEastAndDigit();
    void setAddSpaceBetweenFarEastAndDigit(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets text alignment for the paragraph.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets whether this is a right-to-left paragraph.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the position for a drop cap text.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getDropCapPosition() const;
    bool dropCapPositionIsSet() const;
    void unsetDropCapPosition();
    void setDropCapPosition(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the value (in points) for a first line or hanging indent. Use a positive value to set a first-line indent, and use a negative value to set a hanging indent.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getFirstLineIndent() const;
    bool firstLineIndentIsSet() const;
    void unsetFirstLineIndent();
    void setFirstLineIndent(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets True when the paragraph is an item in a bulleted or numbered list.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isIsListItem() const;
    bool isListItemIsSet() const;
    void unsetIsListItem();
    void setIsListItem(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if all lines in the paragraph are to remain on the same page.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isKeepTogether() const;
    bool keepTogetherIsSet() const;
    void unsetKeepTogether();
    void setKeepTogether(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the paragraph is to remains on the same page as the paragraph that follows it.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isKeepWithNext() const;
    bool keepWithNextIsSet() const;
    void unsetKeepWithNext();
    void setKeepWithNext(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the value (in points) that represents the left indent for paragraph.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLeftIndent() const;
    bool leftIndentIsSet() const;
    void unsetLeftIndent();
    void setLeftIndent(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the line spacing (in points) for the paragraph.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLineSpacing() const;
    bool lineSpacingIsSet() const;
    void unsetLineSpacing();
    void setLineSpacing(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the line spacing for the paragraph.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getLineSpacingRule() const;
    bool lineSpacingRuleIsSet() const;
    void unsetLineSpacingRule();
    void setLineSpacingRule(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the number of lines of the paragraph text used to calculate the drop cap height.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getLinesToDrop() const;
    bool linesToDropIsSet() const;
    void unsetLinesToDrop();
    void setLinesToDrop(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets when true, SpaceBefore and SpaceAfter will be ignored between the paragraphs of the same style.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isNoSpaceBetweenParagraphsOfSameStyle() const;
    bool noSpaceBetweenParagraphsOfSameStyleIsSet() const;
    void unsetNoSpaceBetweenParagraphsOfSameStyle();
    void setNoSpaceBetweenParagraphsOfSameStyle(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the outline level of the paragraph in the document.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getOutlineLevel() const;
    bool outlineLevelIsSet() const;
    void unsetOutlineLevel();
    void setOutlineLevel(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if a page break is forced before the paragraph.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isPageBreakBefore() const;
    bool pageBreakBeforeIsSet() const;
    void unsetPageBreakBefore();
    void setPageBreakBefore(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the value (in points) that represents the right indent for paragraph.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getRightIndent() const;
    bool rightIndentIsSet() const;
    void unsetRightIndent();
    void setRightIndent(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets Shading.
    /// </summary>
    <DATA_TYPE_START>Shading<DATA_TYPE_END> getShading() const;
    bool shadingIsSet() const;
    void unsetShading();
    void setShading(<DATA_TYPE_START>Shading<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of spacing (in points) after the paragraph.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getSpaceAfter() const;
    bool spaceAfterIsSet() const;
    void unsetSpaceAfter();
    void setSpaceAfter(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the amount of spacing after the paragraph is set automatically.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSpaceAfterAuto() const;
    bool spaceAfterAutoIsSet() const;
    void unsetSpaceAfterAuto();
    void setSpaceAfterAuto(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of spacing (in points) before the paragraph.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getSpaceBefore() const;
    bool spaceBeforeIsSet() const;
    void unsetSpaceBefore();
    void setSpaceBefore(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the amount of spacing before the paragraph is set automatically.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSpaceBeforeAuto() const;
    bool spaceBeforeAutoIsSet() const;
    void unsetSpaceBeforeAuto();
    void setSpaceBeforeAuto(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the locale independent style identifier of the paragraph style applied to this formatting.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleIdentifier() const;
    bool styleIdentifierIsSet() const;
    void unsetStyleIdentifier();
    void setStyleIdentifier(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the name of the paragraph style applied to this formatting.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleName() const;
    bool styleNameIsSet() const;
    void unsetStyleName();
    void setStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether the current paragraph should be exempted from any hyphenation which is applied in the document settings.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSuppressAutoHyphens() const;
    bool suppressAutoHyphensIsSet() const;
    void unsetSuppressAutoHyphens();
    void setSuppressAutoHyphens(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether the current paragraph&#x27;s lines should be exempted from line numbering which is applied in the parent section.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSuppressLineNumbers() const;
    bool suppressLineNumbersIsSet() const;
    void unsetSuppressLineNumbers();
    void setSuppressLineNumbers(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if the first and last lines in the paragraph are to remain on the same page as the rest of the paragraph.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isWidowControl() const;
    bool widowControlIsSet() const;
    void unsetWidowControl();
    void setWidowControl(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_AddSpaceBetweenFarEastAndAlpha;
    bool m_AddSpaceBetweenFarEastAndAlphaIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_AddSpaceBetweenFarEastAndDigit;
    bool m_AddSpaceBetweenFarEastAndDigitIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Alignment;
    bool m_AlignmentIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Bidi;
    bool m_BidiIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_DropCapPosition;
    bool m_DropCapPositionIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_FirstLineIndent;
    bool m_FirstLineIndentIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_IsListItem;
    bool m_IsListItemIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_KeepTogether;
    bool m_KeepTogetherIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_KeepWithNext;
    bool m_KeepWithNextIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LeftIndent;
    bool m_LeftIndentIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LineSpacing;
    bool m_LineSpacingIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_LineSpacingRule;
    bool m_LineSpacingRuleIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_LinesToDrop;
    bool m_LinesToDropIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_NoSpaceBetweenParagraphsOfSameStyle;
    bool m_NoSpaceBetweenParagraphsOfSameStyleIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_OutlineLevel;
    bool m_OutlineLevelIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_PageBreakBefore;
    bool m_PageBreakBeforeIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_RightIndent;
    bool m_RightIndentIsSet;
    <DATA_TYPE_START>Shading<DATA_TYPE_END> m_Shading;
    bool m_ShadingIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_SpaceAfter;
    bool m_SpaceAfterIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_SpaceAfterAuto;
    bool m_SpaceAfterAutoIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_SpaceBefore;
    bool m_SpaceBeforeIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_SpaceBeforeAuto;
    bool m_SpaceBeforeAutoIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleIdentifier;
    bool m_StyleIdentifierIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleName;
    bool m_StyleNameIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_SuppressAutoHyphens;
    bool m_SuppressAutoHyphensIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_SuppressLineNumbers;
    bool m_SuppressLineNumbersIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_WidowControl;
    bool m_WidowControlIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ParagraphFormat_H_ */
