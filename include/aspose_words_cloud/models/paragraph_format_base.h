/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="paragraph_format_base.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include "./model_base.h"
#include "link_element.h"
#include "shading.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Paragraph format element base class.
    /// </summary>
    class ParagraphFormatBase : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets text alignment for the paragraph.
        /// </summary>
        enum class Alignment
        { 
            LEFT,
            CENTER,
            RIGHT,
            JUSTIFY,
            DISTRIBUTED,
            ARABIC_MEDIUM_KASHIDA,
            ARABIC_HIGH_KASHIDA,
            ARABIC_LOW_KASHIDA,
            THAI_DISTRIBUTED,
            MATH_ELEMENT_CENTER_AS_GROUP
        };

        /// <summary>
        /// Gets or sets the position for a drop cap text.
        /// </summary>
        enum class DropCapPosition
        { 
            NONE,
            NORMAL,
            MARGIN
        };

        /// <summary>
        /// Gets or sets the line spacing for the paragraph.
        /// </summary>
        enum class LineSpacingRule
        { 
            AT_LEAST,
            EXACTLY,
            MULTIPLE
        };

        /// <summary>
        /// Gets or sets the outline level of the paragraph in the document.
        /// </summary>
        enum class OutlineLevel
        { 
            LEVEL1,
            LEVEL2,
            LEVEL3,
            LEVEL4,
            LEVEL5,
            LEVEL6,
            LEVEL7,
            LEVEL8,
            LEVEL9,
            BODY_TEXT
        };

        /// <summary>
        /// Gets or sets the locale independent style identifier of the paragraph style applied to this formatting.
        /// </summary>
        enum class StyleIdentifier
        { 
            NORMAL,
            HEADING1,
            HEADING2,
            HEADING3,
            HEADING4,
            HEADING5,
            HEADING6,
            HEADING7,
            HEADING8,
            HEADING9,
            INDEX1,
            INDEX2,
            INDEX3,
            INDEX4,
            INDEX5,
            INDEX6,
            INDEX7,
            INDEX8,
            INDEX9,
            TOC1,
            TOC2,
            TOC3,
            TOC4,
            TOC5,
            TOC6,
            TOC7,
            TOC8,
            TOC9,
            NORMAL_INDENT,
            FOOTNOTE_TEXT,
            COMMENT_TEXT,
            HEADER,
            FOOTER,
            INDEX_HEADING,
            CAPTION,
            TABLE_OF_FIGURES,
            ENVELOPE_ADDRESS,
            ENVELOPE_RETURN,
            FOOTNOTE_REFERENCE,
            COMMENT_REFERENCE,
            LINE_NUMBER,
            PAGE_NUMBER,
            ENDNOTE_REFERENCE,
            ENDNOTE_TEXT,
            TABLE_OF_AUTHORITIES,
            MACRO,
            TOA_HEADING,
            LIST,
            LIST_BULLET,
            LIST_NUMBER,
            LIST2,
            LIST3,
            LIST4,
            LIST5,
            LIST_BULLET2,
            LIST_BULLET3,
            LIST_BULLET4,
            LIST_BULLET5,
            LIST_NUMBER2,
            LIST_NUMBER3,
            LIST_NUMBER4,
            LIST_NUMBER5,
            TITLE,
            CLOSING,
            SIGNATURE,
            DEFAULT_PARAGRAPH_FONT,
            BODY_TEXT,
            BODY_TEXT_IND,
            LIST_CONTINUE,
            LIST_CONTINUE2,
            LIST_CONTINUE3,
            LIST_CONTINUE4,
            LIST_CONTINUE5,
            MESSAGE_HEADER,
            SUBTITLE,
            SALUTATION,
            DATE,
            BODY_TEXT1_I,
            BODY_TEXT1_I2,
            NOTE_HEADING,
            BODY_TEXT2,
            BODY_TEXT3,
            BODY_TEXT_IND2,
            BODY_TEXT_IND3,
            BLOCK_TEXT,
            HYPERLINK,
            FOLLOWED_HYPERLINK,
            STRONG,
            EMPHASIS,
            DOCUMENT_MAP,
            PLAIN_TEXT,
            EMAIL_SIGNATURE,
            HTML_TOP_OF_FORM,
            HTML_BOTTOM_OF_FORM,
            NORMAL_WEB,
            HTML_ACRONYM,
            HTML_ADDRESS,
            HTML_CITE,
            HTML_CODE,
            HTML_DEFINITION,
            HTML_KEYBOARD,
            HTML_PREFORMATTED,
            HTML_SAMPLE,
            HTML_TYPEWRITER,
            HTML_VARIABLE,
            TABLE_NORMAL,
            COMMENT_SUBJECT,
            NO_LIST,
            OUTLINE_LIST1,
            OUTLINE_LIST2,
            OUTLINE_LIST3,
            TABLE_SIMPLE1,
            TABLE_SIMPLE2,
            TABLE_SIMPLE3,
            TABLE_CLASSIC1,
            TABLE_CLASSIC2,
            TABLE_CLASSIC3,
            TABLE_CLASSIC4,
            TABLE_COLORFUL1,
            TABLE_COLORFUL2,
            TABLE_COLORFUL3,
            TABLE_COLUMNS1,
            TABLE_COLUMNS2,
            TABLE_COLUMNS3,
            TABLE_COLUMNS4,
            TABLE_COLUMNS5,
            TABLE_GRID1,
            TABLE_GRID2,
            TABLE_GRID3,
            TABLE_GRID4,
            TABLE_GRID5,
            TABLE_GRID6,
            TABLE_GRID7,
            TABLE_GRID8,
            TABLE_LIST1,
            TABLE_LIST2,
            TABLE_LIST3,
            TABLE_LIST4,
            TABLE_LIST5,
            TABLE_LIST6,
            TABLE_LIST7,
            TABLE_LIST8,
            TABLE3_D_EFFECTS1,
            TABLE3_D_EFFECTS2,
            TABLE3_D_EFFECTS3,
            TABLE_CONTEMPORARY,
            TABLE_ELEGANT,
            TABLE_PROFESSIONAL,
            TABLE_SUBTLE1,
            TABLE_SUBTLE2,
            TABLE_WEB1,
            TABLE_WEB2,
            TABLE_WEB3,
            BALLOON_TEXT,
            TABLE_GRID,
            TABLE_THEME,
            PLACEHOLDER_TEXT,
            NO_SPACING,
            LIGHT_SHADING,
            LIGHT_LIST,
            LIGHT_GRID,
            MEDIUM_SHADING1,
            MEDIUM_SHADING2,
            MEDIUM_LIST1,
            MEDIUM_LIST2,
            MEDIUM_GRID1,
            MEDIUM_GRID2,
            MEDIUM_GRID3,
            DARK_LIST,
            COLORFUL_SHADING,
            COLORFUL_LIST,
            COLORFUL_GRID,
            LIGHT_SHADING_ACCENT1,
            LIGHT_LIST_ACCENT1,
            LIGHT_GRID_ACCENT1,
            MEDIUM_SHADING1_ACCENT1,
            MEDIUM_SHADING2_ACCENT1,
            MEDIUM_LIST1_ACCENT1,
            REVISION,
            LIST_PARAGRAPH,
            QUOTE,
            INTENSE_QUOTE,
            MEDIUM_LIST2_ACCENT1,
            MEDIUM_GRID1_ACCENT1,
            MEDIUM_GRID2_ACCENT1,
            MEDIUM_GRID3_ACCENT1,
            DARK_LIST_ACCENT1,
            COLORFUL_SHADING_ACCENT1,
            COLORFUL_LIST_ACCENT1,
            COLORFUL_GRID_ACCENT1,
            LIGHT_SHADING_ACCENT2,
            LIGHT_LIST_ACCENT2,
            LIGHT_GRID_ACCENT2,
            MEDIUM_SHADING1_ACCENT2,
            MEDIUM_SHADING2_ACCENT2,
            MEDIUM_LIST1_ACCENT2,
            MEDIUM_LIST2_ACCENT2,
            MEDIUM_GRID1_ACCENT2,
            MEDIUM_GRID2_ACCENT2,
            MEDIUM_GRID3_ACCENT2,
            DARK_LIST_ACCENT2,
            COLORFUL_SHADING_ACCENT2,
            COLORFUL_LIST_ACCENT2,
            COLORFUL_GRID_ACCENT2,
            LIGHT_SHADING_ACCENT3,
            LIGHT_LIST_ACCENT3,
            LIGHT_GRID_ACCENT3,
            MEDIUM_SHADING1_ACCENT3,
            MEDIUM_SHADING2_ACCENT3,
            MEDIUM_LIST1_ACCENT3,
            MEDIUM_LIST2_ACCENT3,
            MEDIUM_GRID1_ACCENT3,
            MEDIUM_GRID2_ACCENT3,
            MEDIUM_GRID3_ACCENT3,
            DARK_LIST_ACCENT3,
            COLORFUL_SHADING_ACCENT3,
            COLORFUL_LIST_ACCENT3,
            COLORFUL_GRID_ACCENT3,
            LIGHT_SHADING_ACCENT4,
            LIGHT_LIST_ACCENT4,
            LIGHT_GRID_ACCENT4,
            MEDIUM_SHADING1_ACCENT4,
            MEDIUM_SHADING2_ACCENT4,
            MEDIUM_LIST1_ACCENT4,
            MEDIUM_LIST2_ACCENT4,
            MEDIUM_GRID1_ACCENT4,
            MEDIUM_GRID2_ACCENT4,
            MEDIUM_GRID3_ACCENT4,
            DARK_LIST_ACCENT4,
            COLORFUL_SHADING_ACCENT4,
            COLORFUL_LIST_ACCENT4,
            COLORFUL_GRID_ACCENT4,
            LIGHT_SHADING_ACCENT5,
            LIGHT_LIST_ACCENT5,
            LIGHT_GRID_ACCENT5,
            MEDIUM_SHADING1_ACCENT5,
            MEDIUM_SHADING2_ACCENT5,
            MEDIUM_LIST1_ACCENT5,
            MEDIUM_LIST2_ACCENT5,
            MEDIUM_GRID1_ACCENT5,
            MEDIUM_GRID2_ACCENT5,
            MEDIUM_GRID3_ACCENT5,
            DARK_LIST_ACCENT5,
            COLORFUL_SHADING_ACCENT5,
            COLORFUL_LIST_ACCENT5,
            COLORFUL_GRID_ACCENT5,
            LIGHT_SHADING_ACCENT6,
            LIGHT_LIST_ACCENT6,
            LIGHT_GRID_ACCENT6,
            MEDIUM_SHADING1_ACCENT6,
            MEDIUM_SHADING2_ACCENT6,
            MEDIUM_LIST1_ACCENT6,
            MEDIUM_LIST2_ACCENT6,
            MEDIUM_GRID1_ACCENT6,
            MEDIUM_GRID2_ACCENT6,
            MEDIUM_GRID3_ACCENT6,
            DARK_LIST_ACCENT6,
            COLORFUL_SHADING_ACCENT6,
            COLORFUL_LIST_ACCENT6,
            COLORFUL_GRID_ACCENT6,
            SUBTLE_EMPHASIS,
            INTENSE_EMPHASIS,
            SUBTLE_REFERENCE,
            INTENSE_REFERENCE,
            BOOK_TITLE,
            BIBLIOGRAPHY,
            TOC_HEADING,
            PLAIN_TABLE1,
            PLAIN_TABLE2,
            PLAIN_TABLE3,
            PLAIN_TABLE4,
            PLAIN_TABLE5,
            TABLE_GRID_LIGHT,
            GRID_TABLE1_LIGHT,
            GRID_TABLE2,
            GRID_TABLE3,
            GRID_TABLE4,
            GRID_TABLE5_DARK,
            GRID_TABLE6_COLORFUL,
            GRID_TABLE7_COLORFUL,
            GRID_TABLE1_LIGHT_ACCENT1,
            GRID_TABLE2_ACCENT1,
            GRID_TABLE3_ACCENT1,
            GRID_TABLE4_ACCENT1,
            GRID_TABLE5_DARK_ACCENT1,
            GRID_TABLE6_COLORFUL_ACCENT1,
            GRID_TABLE7_COLORFUL_ACCENT1,
            GRID_TABLE1_LIGHT_ACCENT2,
            GRID_TABLE2_ACCENT2,
            GRID_TABLE3_ACCENT2,
            GRID_TABLE4_ACCENT2,
            GRID_TABLE5_DARK_ACCENT2,
            GRID_TABLE6_COLORFUL_ACCENT2,
            GRID_TABLE7_COLORFUL_ACCENT2,
            GRID_TABLE1_LIGHT_ACCENT3,
            GRID_TABLE2_ACCENT3,
            GRID_TABLE3_ACCENT3,
            GRID_TABLE4_ACCENT3,
            GRID_TABLE5_DARK_ACCENT3,
            GRID_TABLE6_COLORFUL_ACCENT3,
            GRID_TABLE7_COLORFUL_ACCENT3,
            GRID_TABLE1_LIGHT_ACCENT4,
            GRID_TABLE2_ACCENT4,
            GRID_TABLE3_ACCENT4,
            GRID_TABLE4_ACCENT4,
            GRID_TABLE5_DARK_ACCENT4,
            GRID_TABLE6_COLORFUL_ACCENT4,
            GRID_TABLE7_COLORFUL_ACCENT4,
            GRID_TABLE1_LIGHT_ACCENT5,
            GRID_TABLE2_ACCENT5,
            GRID_TABLE3_ACCENT5,
            GRID_TABLE4_ACCENT5,
            GRID_TABLE5_DARK_ACCENT5,
            GRID_TABLE6_COLORFUL_ACCENT5,
            GRID_TABLE7_COLORFUL_ACCENT5,
            GRID_TABLE1_LIGHT_ACCENT6,
            GRID_TABLE2_ACCENT6,
            GRID_TABLE3_ACCENT6,
            GRID_TABLE4_ACCENT6,
            GRID_TABLE5_DARK_ACCENT6,
            GRID_TABLE6_COLORFUL_ACCENT6,
            GRID_TABLE7_COLORFUL_ACCENT6,
            LIST_TABLE1_LIGHT,
            LIST_TABLE2,
            LIST_TABLE3,
            LIST_TABLE4,
            LIST_TABLE5_DARK,
            LIST_TABLE6_COLORFUL,
            LIST_TABLE7_COLORFUL,
            LIST_TABLE1_LIGHT_ACCENT1,
            LIST_TABLE2_ACCENT1,
            LIST_TABLE3_ACCENT1,
            LIST_TABLE4_ACCENT1,
            LIST_TABLE5_DARK_ACCENT1,
            LIST_TABLE6_COLORFUL_ACCENT1,
            LIST_TABLE7_COLORFUL_ACCENT1,
            LIST_TABLE1_LIGHT_ACCENT2,
            LIST_TABLE2_ACCENT2,
            LIST_TABLE3_ACCENT2,
            LIST_TABLE4_ACCENT2,
            LIST_TABLE5_DARK_ACCENT2,
            LIST_TABLE6_COLORFUL_ACCENT2,
            LIST_TABLE7_COLORFUL_ACCENT2,
            LIST_TABLE1_LIGHT_ACCENT3,
            LIST_TABLE2_ACCENT3,
            LIST_TABLE3_ACCENT3,
            LIST_TABLE4_ACCENT3,
            LIST_TABLE5_DARK_ACCENT3,
            LIST_TABLE6_COLORFUL_ACCENT3,
            LIST_TABLE7_COLORFUL_ACCENT3,
            LIST_TABLE1_LIGHT_ACCENT4,
            LIST_TABLE2_ACCENT4,
            LIST_TABLE3_ACCENT4,
            LIST_TABLE4_ACCENT4,
            LIST_TABLE5_DARK_ACCENT4,
            LIST_TABLE6_COLORFUL_ACCENT4,
            LIST_TABLE7_COLORFUL_ACCENT4,
            LIST_TABLE1_LIGHT_ACCENT5,
            LIST_TABLE2_ACCENT5,
            LIST_TABLE3_ACCENT5,
            LIST_TABLE4_ACCENT5,
            LIST_TABLE5_DARK_ACCENT5,
            LIST_TABLE6_COLORFUL_ACCENT5,
            LIST_TABLE7_COLORFUL_ACCENT5,
            LIST_TABLE1_LIGHT_ACCENT6,
            LIST_TABLE2_ACCENT6,
            LIST_TABLE3_ACCENT6,
            LIST_TABLE4_ACCENT6,
            LIST_TABLE5_DARK_ACCENT6,
            LIST_TABLE6_COLORFUL_ACCENT6,
            LIST_TABLE7_COLORFUL_ACCENT6,
            SMART_LINK,
            MENTION,
            SMART_HYPERLINK,
            HASHTAG,
            UNRESOLVED_MENTION,
            USER,
            NIL
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ParagraphFormatBase() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets a value indicating whether inter-character spacing is automatically adjusted between regions of Latin text and regions of East Asian text in the current paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAddSpaceBetweenFarEastAndAlpha() const;

        /// <summary>
        /// Gets or sets a value indicating whether inter-character spacing is automatically adjusted between regions of Latin text and regions of East Asian text in the current paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAddSpaceBetweenFarEastAndAlpha(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether inter-character spacing is automatically adjusted between regions of numbers and regions of East Asian text in the current paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAddSpaceBetweenFarEastAndDigit() const;

        /// <summary>
        /// Gets or sets a value indicating whether inter-character spacing is automatically adjusted between regions of numbers and regions of East Asian text in the current paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAddSpaceBetweenFarEastAndDigit(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets text alignment for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::Alignment > getAlignment() const;

        /// <summary>
        /// Gets or sets text alignment for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlignment(std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::Alignment > value);


        /// <summary>
        /// Gets or sets a value indicating whether this is a right-to-left paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBidi() const;

        /// <summary>
        /// Gets or sets a value indicating whether this is a right-to-left paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBidi(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the position for a drop cap text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::DropCapPosition > getDropCapPosition() const;

        /// <summary>
        /// Gets or sets the position for a drop cap text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDropCapPosition(std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::DropCapPosition > value);


        /// <summary>
        /// Gets or sets the value (in points) for a first line or hanging indent.
        /// Use a positive value to set a first-line indent, and use a negative value to set a hanging indent.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getFirstLineIndent() const;

        /// <summary>
        /// Gets or sets the value (in points) for a first line or hanging indent.
        /// Use a positive value to set a first-line indent, and use a negative value to set a hanging indent.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFirstLineIndent(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether all lines in the paragraph are to remain on the same page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getKeepTogether() const;

        /// <summary>
        /// Gets or sets a value indicating whether all lines in the paragraph are to remain on the same page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setKeepTogether(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the paragraph is to remains on the same page as the paragraph that follows it.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getKeepWithNext() const;

        /// <summary>
        /// Gets or sets a value indicating whether the paragraph is to remains on the same page as the paragraph that follows it.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setKeepWithNext(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the value (in points), that represents the left indent for paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLeftIndent() const;

        /// <summary>
        /// Gets or sets the value (in points), that represents the left indent for paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLeftIndent(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the line spacing (in points) for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLineSpacing() const;

        /// <summary>
        /// Gets or sets the line spacing (in points) for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineSpacing(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the line spacing for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::LineSpacingRule > getLineSpacingRule() const;

        /// <summary>
        /// Gets or sets the line spacing for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineSpacingRule(std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::LineSpacingRule > value);


        /// <summary>
        /// Gets or sets the number of lines of the paragraph text used to calculate the drop cap height.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getLinesToDrop() const;

        /// <summary>
        /// Gets or sets the number of lines of the paragraph text used to calculate the drop cap height.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLinesToDrop(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets a value indicating whether SpaceBefore and SpaceAfter will be ignored between the paragraphs of the same style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getNoSpaceBetweenParagraphsOfSameStyle() const;

        /// <summary>
        /// Gets or sets a value indicating whether SpaceBefore and SpaceAfter will be ignored between the paragraphs of the same style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNoSpaceBetweenParagraphsOfSameStyle(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the outline level of the paragraph in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::OutlineLevel > getOutlineLevel() const;

        /// <summary>
        /// Gets or sets the outline level of the paragraph in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOutlineLevel(std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::OutlineLevel > value);


        /// <summary>
        /// Gets or sets a value indicating whether a page break is forced before the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getPageBreakBefore() const;

        /// <summary>
        /// Gets or sets a value indicating whether a page break is forced before the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageBreakBefore(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the value (in points) that represents the right indent for paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getRightIndent() const;

        /// <summary>
        /// Gets or sets the value (in points) that represents the right indent for paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRightIndent(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the Shading object, that refers to the shading formatting for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Shading > getShading() const;

        /// <summary>
        /// Gets or sets the Shading object, that refers to the shading formatting for the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setShading(std::shared_ptr< aspose::words::cloud::models::Shading > value);


        /// <summary>
        /// Gets or sets the amount of spacing (in points) after the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getSpaceAfter() const;

        /// <summary>
        /// Gets or sets the amount of spacing (in points) after the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSpaceAfter(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether the amount of spacing after the paragraph is set automatically.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSpaceAfterAuto() const;

        /// <summary>
        /// Gets or sets a value indicating whether the amount of spacing after the paragraph is set automatically.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSpaceAfterAuto(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the amount of spacing (in points) before the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getSpaceBefore() const;

        /// <summary>
        /// Gets or sets the amount of spacing (in points) before the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSpaceBefore(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether the amount of spacing before the paragraph is set automatically.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSpaceBeforeAuto() const;

        /// <summary>
        /// Gets or sets a value indicating whether the amount of spacing before the paragraph is set automatically.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSpaceBeforeAuto(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the locale independent style identifier of the paragraph style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::StyleIdentifier > getStyleIdentifier() const;

        /// <summary>
        /// Gets or sets the locale independent style identifier of the paragraph style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleIdentifier(std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::StyleIdentifier > value);


        /// <summary>
        /// Gets or sets the name of the paragraph style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getStyleName() const;

        /// <summary>
        /// Gets or sets the name of the paragraph style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether the current paragraph should be exempted from any hyphenation which is applied in the document settings.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSuppressAutoHyphens() const;

        /// <summary>
        /// Gets or sets a value indicating whether the current paragraph should be exempted from any hyphenation which is applied in the document settings.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSuppressAutoHyphens(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the current paragraph's lines should be exempted from line numbering which is applied in the parent section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSuppressLineNumbers() const;

        /// <summary>
        /// Gets or sets a value indicating whether the current paragraph's lines should be exempted from line numbering which is applied in the parent section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSuppressLineNumbers(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the first and last lines in the paragraph are to remain on the same page as the rest of the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getWidowControl() const;

        /// <summary>
        /// Gets or sets a value indicating whether the first and last lines in the paragraph are to remain on the same page as the rest of the paragraph.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setWidowControl(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< bool > m_AddSpaceBetweenFarEastAndAlpha;
        std::shared_ptr< bool > m_AddSpaceBetweenFarEastAndDigit;
        std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::Alignment > m_Alignment;
        std::shared_ptr< bool > m_Bidi;
        std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::DropCapPosition > m_DropCapPosition;
        std::shared_ptr< double > m_FirstLineIndent;
        std::shared_ptr< bool > m_KeepTogether;
        std::shared_ptr< bool > m_KeepWithNext;
        std::shared_ptr< double > m_LeftIndent;
        std::shared_ptr< double > m_LineSpacing;
        std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::LineSpacingRule > m_LineSpacingRule;
        std::shared_ptr< int32_t > m_LinesToDrop;
        std::shared_ptr< bool > m_NoSpaceBetweenParagraphsOfSameStyle;
        std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::OutlineLevel > m_OutlineLevel;
        std::shared_ptr< bool > m_PageBreakBefore;
        std::shared_ptr< double > m_RightIndent;
        std::shared_ptr< aspose::words::cloud::models::Shading > m_Shading;
        std::shared_ptr< double > m_SpaceAfter;
        std::shared_ptr< bool > m_SpaceAfterAuto;
        std::shared_ptr< double > m_SpaceBefore;
        std::shared_ptr< bool > m_SpaceBeforeAuto;
        std::shared_ptr< aspose::words::cloud::models::ParagraphFormatBase::StyleIdentifier > m_StyleIdentifier;
        std::shared_ptr< std::wstring > m_StyleName;
        std::shared_ptr< bool > m_SuppressAutoHyphens;
        std::shared_ptr< bool > m_SuppressLineNumbers;
        std::shared_ptr< bool > m_WidowControl;
    };
}

