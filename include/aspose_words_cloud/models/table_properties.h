/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="table_properties.h">
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
#include "preferred_width.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with table properties.
    /// </summary>
    class TableProperties : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls how an inline table is aligned in the document.
        /// </summary>
        enum class Alignment
        { 
            LEFT,
            CENTER,
            RIGHT
        };

        /// <summary>
        /// Gets or sets the locale independent style identifier of the table style applied to this table.
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
        /// Gets or sets the bit flags, that specify how a table style is applied to this table.
        /// </summary>
        enum class StyleOptions
        { 
            NONE,
            FIRST_ROW,
            LAST_ROW,
            FIRST_COLUMN,
            LAST_COLUMN,
            ROW_BANDS,
            DEFAULT,
            COLUMN_BANDS,
            DEFAULT2003
        };

        /// <summary>
        /// Gets or sets the option that controls text wrapping for the table.
        /// </summary>
        enum class TextWrapping
        { 
            DEFAULT,
            NONE,
            AROUND
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TableProperties() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the option that controls how an inline table is aligned in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableProperties::Alignment > getAlignment() const;

        /// <summary>
        /// Gets or sets the option that controls how an inline table is aligned in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlignment(std::shared_ptr< aspose::words::cloud::models::TableProperties::Alignment > value);


        /// <summary>
        /// Gets or sets a value indicating whether to automatically resize cells in a table to fit their contents.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAllowAutoFit() const;

        /// <summary>
        /// Gets or sets a value indicating whether to automatically resize cells in a table to fit their contents.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAllowAutoFit(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether this is a right-to-left table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBidi() const;

        /// <summary>
        /// Gets or sets a value indicating whether this is a right-to-left table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBidi(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) to add below the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getBottomPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add below the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBottomPadding(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) between the cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getCellSpacing() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) between the cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCellSpacing(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the value, that represents the left indent of the table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLeftIndent() const;

        /// <summary>
        /// Gets or sets the value, that represents the left indent of the table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLeftIndent(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the left of the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLeftPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the left of the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLeftPadding(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the table preferred width.
        /// Preferred width can be specified as a percentage, number of points or a special "auto" value.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PreferredWidth > getPreferredWidth() const;

        /// <summary>
        /// Gets or sets the table preferred width.
        /// Preferred width can be specified as a percentage, number of points or a special "auto" value.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPreferredWidth(std::shared_ptr< aspose::words::cloud::models::PreferredWidth > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the right of the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getRightPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the right of the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRightPadding(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the locale independent style identifier of the table style applied to this table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableProperties::StyleIdentifier > getStyleIdentifier() const;

        /// <summary>
        /// Gets or sets the locale independent style identifier of the table style applied to this table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleIdentifier(std::shared_ptr< aspose::words::cloud::models::TableProperties::StyleIdentifier > value);


        /// <summary>
        /// Gets or sets the name of the table style applied to this table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getStyleName() const;

        /// <summary>
        /// Gets or sets the name of the table style applied to this table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the bit flags, that specify how a table style is applied to this table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableProperties::StyleOptions > getStyleOptions() const;

        /// <summary>
        /// Gets or sets the bit flags, that specify how a table style is applied to this table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleOptions(std::shared_ptr< aspose::words::cloud::models::TableProperties::StyleOptions > value);


        /// <summary>
        /// Gets or sets the option that controls text wrapping for the table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableProperties::TextWrapping > getTextWrapping() const;

        /// <summary>
        /// Gets or sets the option that controls text wrapping for the table.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextWrapping(std::shared_ptr< aspose::words::cloud::models::TableProperties::TextWrapping > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) to add above the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTopPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add above the contents of cells.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTopPadding(std::shared_ptr< double > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::TableProperties::Alignment > m_Alignment;
        std::shared_ptr< bool > m_AllowAutoFit;
        std::shared_ptr< bool > m_Bidi;
        std::shared_ptr< double > m_BottomPadding;
        std::shared_ptr< double > m_CellSpacing;
        std::shared_ptr< double > m_LeftIndent;
        std::shared_ptr< double > m_LeftPadding;
        std::shared_ptr< aspose::words::cloud::models::PreferredWidth > m_PreferredWidth;
        std::shared_ptr< double > m_RightPadding;
        std::shared_ptr< aspose::words::cloud::models::TableProperties::StyleIdentifier > m_StyleIdentifier;
        std::shared_ptr< std::wstring > m_StyleName;
        std::shared_ptr< aspose::words::cloud::models::TableProperties::StyleOptions > m_StyleOptions;
        std::shared_ptr< aspose::words::cloud::models::TableProperties::TextWrapping > m_TextWrapping;
        std::shared_ptr< double > m_TopPadding;
    };
}

