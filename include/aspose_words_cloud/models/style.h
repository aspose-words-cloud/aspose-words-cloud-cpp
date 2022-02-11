/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="style.h">
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
#include "font.h"
#include "link_element.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a single document style.
    /// </summary>
    class Style : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the locale independent style identifier for a built-in style.
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

        /// <summary>
        /// Gets or sets the style type (paragraph or character).
        /// </summary>
        enum class Type
        { 
            PARAGRAPH,
            CHARACTER,
            TABLE,
            LIST
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~Style() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets all aliases of this style. If style has no aliases then empty array of string is returned.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > getAliases() const;

        /// <summary>
        /// Gets or sets all aliases of this style. If style has no aliases then empty array of string is returned.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAliases(std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > value);


        /// <summary>
        /// Gets or sets the name of the style this style is based on.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getBaseStyleName() const;

        /// <summary>
        /// Gets or sets the name of the style this style is based on.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBaseStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether this style is one of the built-in styles in MS Word.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBuiltIn() const;

        /// <summary>
        /// Gets or sets a value indicating whether this style is one of the built-in styles in MS Word.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBuiltIn(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the character formatting of the style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Font > getFont() const;

        /// <summary>
        /// Gets or sets the character formatting of the style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFont(std::shared_ptr< aspose::words::cloud::models::Font > value);


        /// <summary>
        /// Gets or sets a value indicating whether the style is one of the built-in Heading styles.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsHeading() const;

        /// <summary>
        /// Gets or sets a value indicating whether the style is one of the built-in Heading styles.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsHeading(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether this style is shown in the Quick Style gallery inside MS Word UI.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsQuickStyle() const;

        /// <summary>
        /// Gets or sets a value indicating whether this style is shown in the Quick Style gallery inside MS Word UI.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsQuickStyle(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the name of the Style linked to this one. Returns Empty string if no styles are linked.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getLinkedStyleName() const;

        /// <summary>
        /// Gets or sets the name of the Style linked to this one. Returns Empty string if no styles are linked.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLinkedStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getName() const;

        /// <summary>
        /// Gets or sets the name of the style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the style to be applied automatically to a new paragraph inserted after a paragraph formatted with the specified style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNextParagraphStyleName() const;

        /// <summary>
        /// Gets or sets the name of the style to be applied automatically to a new paragraph inserted after a paragraph formatted with the specified style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNextParagraphStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the locale independent style identifier for a built-in style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Style::StyleIdentifier > getStyleIdentifier() const;

        /// <summary>
        /// Gets or sets the locale independent style identifier for a built-in style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleIdentifier(std::shared_ptr< aspose::words::cloud::models::Style::StyleIdentifier > value);


        /// <summary>
        /// Gets or sets the style type (paragraph or character).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Style::Type > getType() const;

        /// <summary>
        /// Gets or sets the style type (paragraph or character).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setType(std::shared_ptr< aspose::words::cloud::models::Style::Type > value);


    protected:
        std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > m_Aliases;
        std::shared_ptr< std::wstring > m_BaseStyleName;
        std::shared_ptr< bool > m_BuiltIn;
        std::shared_ptr< aspose::words::cloud::models::Font > m_Font;
        std::shared_ptr< bool > m_IsHeading;
        std::shared_ptr< bool > m_IsQuickStyle;
        std::shared_ptr< std::wstring > m_LinkedStyleName;
        std::shared_ptr< std::wstring > m_Name;
        std::shared_ptr< std::wstring > m_NextParagraphStyleName;
        std::shared_ptr< aspose::words::cloud::models::Style::StyleIdentifier > m_StyleIdentifier;
        std::shared_ptr< aspose::words::cloud::models::Style::Type > m_Type;
    };
}

