
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ParagraphFormat.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_ParagraphFormat_H_
#define IO_SWAGGER_CLIENT_MODEL_ParagraphFormat_H_


#include <cpprest/details/basic_types.h>
#include "LinkElement.h"
#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// Paragraph format element             
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
    bool isAddSpaceBetweenFarEastAndAlpha() const;
    bool addSpaceBetweenFarEastAndAlphaIsSet() const;
    void unsetAddSpaceBetweenFarEastAndAlpha();
    void setAddSpaceBetweenFarEastAndAlpha(bool value);
    /// <summary>
    /// Gets or sets a flag indicating whether inter-character spacing is automatically adjusted between regions of numbers and regions of East Asian text in the current paragraph.             
    /// </summary>
    bool isAddSpaceBetweenFarEastAndDigit() const;
    bool addSpaceBetweenFarEastAndDigitIsSet() const;
    void unsetAddSpaceBetweenFarEastAndDigit();
    void setAddSpaceBetweenFarEastAndDigit(bool value);
    /// <summary>
    /// Gets or sets text alignment for the paragraph.             
    /// </summary>
    utility::string_t getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(utility::string_t value);
    /// <summary>
    /// Gets or sets whether this is a right-to-left paragraph.             
    /// </summary>
    bool isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(bool value);
    /// <summary>
    /// Gets or sets the position for a drop cap text.             
    /// </summary>
    utility::string_t getDropCapPosition() const;
    bool dropCapPositionIsSet() const;
    void unsetDropCapPosition();
    void setDropCapPosition(utility::string_t value);
    /// <summary>
    /// Gets or sets the value (in points) for a first line or hanging indent. Use a positive value to set a first-line indent, and use a negative value to set a hanging indent.             
    /// </summary>
    double getFirstLineIndent() const;
    bool firstLineIndentIsSet() const;
    void unsetFirstLineIndent();
    void setFirstLineIndent(double value);
    /// <summary>
    /// True if all lines in the paragraph are to remain on the same page.             
    /// </summary>
    bool isKeepTogether() const;
    bool keepTogetherIsSet() const;
    void unsetKeepTogether();
    void setKeepTogether(bool value);
    /// <summary>
    /// True if the paragraph is to remains on the same page as the paragraph that follows it.             
    /// </summary>
    bool isKeepWithNext() const;
    bool keepWithNextIsSet() const;
    void unsetKeepWithNext();
    void setKeepWithNext(bool value);
    /// <summary>
    /// Gets or sets the value (in points) that represents the left indent for paragraph.             
    /// </summary>
    double getLeftIndent() const;
    bool leftIndentIsSet() const;
    void unsetLeftIndent();
    void setLeftIndent(double value);
    /// <summary>
    /// Gets or sets the line spacing (in points) for the paragraph.             
    /// </summary>
    double getLineSpacing() const;
    bool lineSpacingIsSet() const;
    void unsetLineSpacing();
    void setLineSpacing(double value);
    /// <summary>
    /// Gets or sets the line spacing for the paragraph.             
    /// </summary>
    utility::string_t getLineSpacingRule() const;
    bool lineSpacingRuleIsSet() const;
    void unsetLineSpacingRule();
    void setLineSpacingRule(utility::string_t value);
    /// <summary>
    /// Gets or sets the number of lines of the paragraph text used to calculate the drop cap height.             
    /// </summary>
    int32_t getLinesToDrop() const;
    bool linesToDropIsSet() const;
    void unsetLinesToDrop();
    void setLinesToDrop(int32_t value);
    /// <summary>
    /// When true,  and  will be ignored between the paragraphs of the same style.             
    /// </summary>
    bool isNoSpaceBetweenParagraphsOfSameStyle() const;
    bool noSpaceBetweenParagraphsOfSameStyleIsSet() const;
    void unsetNoSpaceBetweenParagraphsOfSameStyle();
    void setNoSpaceBetweenParagraphsOfSameStyle(bool value);
    /// <summary>
    /// Specifies the outline level of the paragraph in the document.             
    /// </summary>
    utility::string_t getOutlineLevel() const;
    bool outlineLevelIsSet() const;
    void unsetOutlineLevel();
    void setOutlineLevel(utility::string_t value);
    /// <summary>
    /// True if a page break is forced before the paragraph.             
    /// </summary>
    bool isPageBreakBefore() const;
    bool pageBreakBeforeIsSet() const;
    void unsetPageBreakBefore();
    void setPageBreakBefore(bool value);
    /// <summary>
    /// Gets or sets the value (in points) that represents the right indent for paragraph.             
    /// </summary>
    double getRightIndent() const;
    bool rightIndentIsSet() const;
    void unsetRightIndent();
    void setRightIndent(double value);
    /// <summary>
    /// Gets or sets the amount of spacing (in points) after the paragraph.             
    /// </summary>
    double getSpaceAfter() const;
    bool spaceAfterIsSet() const;
    void unsetSpaceAfter();
    void setSpaceAfter(double value);
    /// <summary>
    /// True if the amount of spacing after the paragraph is set automatically.             
    /// </summary>
    bool isSpaceAfterAuto() const;
    bool spaceAfterAutoIsSet() const;
    void unsetSpaceAfterAuto();
    void setSpaceAfterAuto(bool value);
    /// <summary>
    /// Gets or sets the amount of spacing (in points) before the paragraph.             
    /// </summary>
    double getSpaceBefore() const;
    bool spaceBeforeIsSet() const;
    void unsetSpaceBefore();
    void setSpaceBefore(double value);
    /// <summary>
    /// True if the amount of spacing before the paragraph is set automatically.             
    /// </summary>
    bool isSpaceBeforeAuto() const;
    bool spaceBeforeAutoIsSet() const;
    void unsetSpaceBeforeAuto();
    void setSpaceBeforeAuto(bool value);
    /// <summary>
    /// Gets or sets the locale independent style identifier of the paragraph style applied to this formatting.             
    /// </summary>
    utility::string_t getStyleIdentifier() const;
    bool styleIdentifierIsSet() const;
    void unsetStyleIdentifier();
    void setStyleIdentifier(utility::string_t value);
    /// <summary>
    /// Gets or sets the name of the paragraph style applied to this formatting.             
    /// </summary>
    utility::string_t getStyleName() const;
    bool styleNameIsSet() const;
    void unsetStyleName();
    void setStyleName(utility::string_t value);
    /// <summary>
    /// Specifies whether the current paragraph should be exempted from any hyphenation which is applied in the document settings.             
    /// </summary>
    bool isSuppressAutoHyphens() const;
    bool suppressAutoHyphensIsSet() const;
    void unsetSuppressAutoHyphens();
    void setSuppressAutoHyphens(bool value);
    /// <summary>
    /// Specifies whether the current paragraph&#39;s lines should be exempted from line numbering which is applied in the parent section.             
    /// </summary>
    bool isSuppressLineNumbers() const;
    bool suppressLineNumbersIsSet() const;
    void unsetSuppressLineNumbers();
    void setSuppressLineNumbers(bool value);
    /// <summary>
    /// True if the first and last lines in the paragraph are to remain on the same page as the rest of the paragraph.             
    /// </summary>
    bool isWidowControl() const;
    bool widowControlIsSet() const;
    void unsetWidowControl();
    void setWidowControl(bool value);

protected:
    bool m_AddSpaceBetweenFarEastAndAlpha;
    bool m_AddSpaceBetweenFarEastAndAlphaIsSet;
    bool m_AddSpaceBetweenFarEastAndDigit;
    bool m_AddSpaceBetweenFarEastAndDigitIsSet;
    utility::string_t m_Alignment;
    bool m_AlignmentIsSet;
    bool m_Bidi;
    bool m_BidiIsSet;
    utility::string_t m_DropCapPosition;
    bool m_DropCapPositionIsSet;
    double m_FirstLineIndent;
    bool m_FirstLineIndentIsSet;
    bool m_KeepTogether;
    bool m_KeepTogetherIsSet;
    bool m_KeepWithNext;
    bool m_KeepWithNextIsSet;
    double m_LeftIndent;
    bool m_LeftIndentIsSet;
    double m_LineSpacing;
    bool m_LineSpacingIsSet;
    utility::string_t m_LineSpacingRule;
    bool m_LineSpacingRuleIsSet;
    int32_t m_LinesToDrop;
    bool m_LinesToDropIsSet;
    bool m_NoSpaceBetweenParagraphsOfSameStyle;
    bool m_NoSpaceBetweenParagraphsOfSameStyleIsSet;
    utility::string_t m_OutlineLevel;
    bool m_OutlineLevelIsSet;
    bool m_PageBreakBefore;
    bool m_PageBreakBeforeIsSet;
    double m_RightIndent;
    bool m_RightIndentIsSet;
    double m_SpaceAfter;
    bool m_SpaceAfterIsSet;
    bool m_SpaceAfterAuto;
    bool m_SpaceAfterAutoIsSet;
    double m_SpaceBefore;
    bool m_SpaceBeforeIsSet;
    bool m_SpaceBeforeAuto;
    bool m_SpaceBeforeAutoIsSet;
    utility::string_t m_StyleIdentifier;
    bool m_StyleIdentifierIsSet;
    utility::string_t m_StyleName;
    bool m_StyleNameIsSet;
    bool m_SuppressAutoHyphens;
    bool m_SuppressAutoHyphensIsSet;
    bool m_SuppressLineNumbers;
    bool m_SuppressLineNumbersIsSet;
    bool m_WidowControl;
    bool m_WidowControlIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_ParagraphFormat_H_ */
