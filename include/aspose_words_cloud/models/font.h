/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="font.h">
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
#include "border.h"
#include "link_element.h"
#include "xml_color.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a font element.
    /// </summary>
    class Font : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the locale independent style identifier of the character style applied to this formatting.
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
        /// Gets or sets the font animation effect.
        /// </summary>
        enum class TextEffect
        { 
            NONE,
            LAS_VEGAS_LIGHTS,
            BLINKING_BACKGROUND,
            SPARKLE_TEXT,
            MARCHING_BLACK_ANTS,
            MARCHING_RED_ANTS,
            SHIMMER
        };

        /// <summary>
        /// Gets or sets the type of underline applied to the font.
        /// </summary>
        enum class Underline
        { 
            NONE,
            SINGLE,
            WORDS,
            DOUBLE,
            DOTTED,
            THICK,
            DASH,
            DOT_DASH,
            DOT_DOT_DASH,
            WAVY,
            DOTTED_HEAVY,
            DASH_HEAVY,
            DOT_DASH_HEAVY,
            DOT_DOT_DASH_HEAVY,
            WAVY_HEAVY,
            DASH_LONG,
            WAVY_DOUBLE,
            DASH_LONG_HEAVY
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~Font() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as all capital letters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAllCaps() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as all capital letters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAllCaps(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the contents of this run shall have right-to-left characteristics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBidi() const;

        /// <summary>
        /// Gets or sets a value indicating whether the contents of this run shall have right-to-left characteristics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBidi(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as bold.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBold() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as bold.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBold(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the right-to-left text is formatted as bold.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBoldBi() const;

        /// <summary>
        /// Gets or sets a value indicating whether the right-to-left text is formatted as bold.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBoldBi(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the border object, that specifies border for the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Border > getBorder() const;

        /// <summary>
        /// Gets or sets the border object, that specifies border for the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBorder(std::shared_ptr< aspose::words::cloud::models::Border > value);


        /// <summary>
        /// Gets or sets the color of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getColor() const;

        /// <summary>
        /// Gets or sets the color of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


        /// <summary>
        /// Gets or sets a value indicating whether the contents of this run shall be treated as complex script text regardless of their Unicode character values when determining the formatting for this run.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getComplexScript() const;

        /// <summary>
        /// Gets or sets a value indicating whether the contents of this run shall be treated as complex script text regardless of their Unicode character values when determining the formatting for this run.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setComplexScript(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as double strikethrough text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getDoubleStrikeThrough() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as double strikethrough text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDoubleStrikeThrough(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as embossed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getEmboss() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as embossed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEmboss(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as engraved.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getEngrave() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as engraved.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEngrave(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as hidden text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getHidden() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as hidden text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHidden(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the highlight (marker) color.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getHighlightColor() const;

        /// <summary>
        /// Gets or sets the highlight (marker) color.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHighlightColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as italic.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getItalic() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as italic.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setItalic(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the right-to-left text is formatted as italic.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getItalicBi() const;

        /// <summary>
        /// Gets or sets a value indicating whether the right-to-left text is formatted as italic.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setItalicBi(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the font size at which kerning starts.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getKerning() const;

        /// <summary>
        /// Gets or sets the font size at which kerning starts.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setKerning(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the locale identifier (language) of the formatted characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getLocaleId() const;

        /// <summary>
        /// Gets or sets the locale identifier (language) of the formatted characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLocaleId(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the locale identifier (language) of the formatted right-to-left characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getLocaleIdBi() const;

        /// <summary>
        /// Gets or sets the locale identifier (language) of the formatted right-to-left characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLocaleIdBi(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the locale identifier (language) of the formatted Asian characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getLocaleIdFarEast() const;

        /// <summary>
        /// Gets or sets the locale identifier (language) of the formatted Asian characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLocaleIdFarEast(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the name of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getName() const;

        /// <summary>
        /// Gets or sets the name of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the font used for Latin text (characters with character codes from 0 (zero) through 127).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNameAscii() const;

        /// <summary>
        /// Gets or sets the font used for Latin text (characters with character codes from 0 (zero) through 127).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNameAscii(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the font in a right-to-left language document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNameBi() const;

        /// <summary>
        /// Gets or sets the name of the font in a right-to-left language document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNameBi(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the East Asian font name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNameFarEast() const;

        /// <summary>
        /// Gets or sets the East Asian font name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNameFarEast(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the font used for characters with character codes from 128 through 255.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNameOther() const;

        /// <summary>
        /// Gets or sets the font used for characters with character codes from 128 through 255.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNameOther(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether the formatted characters are not to be spell checked.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getNoProofing() const;

        /// <summary>
        /// Gets or sets a value indicating whether the formatted characters are not to be spell checked.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNoProofing(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as outline.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getOutline() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as outline.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOutline(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the position of text (in points) relative to the base line.
        /// A positive number raises the text, and a negative number lowers it.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getPosition() const;

        /// <summary>
        /// Gets or sets the position of text (in points) relative to the base line.
        /// A positive number raises the text, and a negative number lowers it.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPosition(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets character width scaling in percent.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getScaling() const;

        /// <summary>
        /// Gets or sets character width scaling in percent.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setScaling(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as shadowed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getShadow() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as shadowed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setShadow(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the font size in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getSize() const;

        /// <summary>
        /// Gets or sets the font size in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSize(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the font size in points used in a right-to-left document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getSizeBi() const;

        /// <summary>
        /// Gets or sets the font size in points used in a right-to-left document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSizeBi(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as small capital letters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSmallCaps() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as small capital letters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSmallCaps(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the spacing (in points) between characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getSpacing() const;

        /// <summary>
        /// Gets or sets the spacing (in points) between characters.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSpacing(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as strikethrough text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getStrikeThrough() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as strikethrough text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStrikeThrough(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the locale independent style identifier of the character style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Font::StyleIdentifier > getStyleIdentifier() const;

        /// <summary>
        /// Gets or sets the locale independent style identifier of the character style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleIdentifier(std::shared_ptr< aspose::words::cloud::models::Font::StyleIdentifier > value);


        /// <summary>
        /// Gets or sets the name of the character style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getStyleName() const;

        /// <summary>
        /// Gets or sets the name of the character style applied to this formatting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as subscript.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSubscript() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as subscript.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSubscript(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as superscript.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSuperscript() const;

        /// <summary>
        /// Gets or sets a value indicating whether the font is formatted as superscript.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSuperscript(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the font animation effect.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Font::TextEffect > getTextEffect() const;

        /// <summary>
        /// Gets or sets the font animation effect.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextEffect(std::shared_ptr< aspose::words::cloud::models::Font::TextEffect > value);


        /// <summary>
        /// Gets or sets the type of underline applied to the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Font::Underline > getUnderline() const;

        /// <summary>
        /// Gets or sets the type of underline applied to the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUnderline(std::shared_ptr< aspose::words::cloud::models::Font::Underline > value);


        /// <summary>
        /// Gets or sets the color of the underline applied to the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getUnderlineColor() const;

        /// <summary>
        /// Gets or sets the color of the underline applied to the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUnderlineColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


    protected:
        std::shared_ptr< bool > m_AllCaps;
        std::shared_ptr< bool > m_Bidi;
        std::shared_ptr< bool > m_Bold;
        std::shared_ptr< bool > m_BoldBi;
        std::shared_ptr< aspose::words::cloud::models::Border > m_Border;
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_Color;
        std::shared_ptr< bool > m_ComplexScript;
        std::shared_ptr< bool > m_DoubleStrikeThrough;
        std::shared_ptr< bool > m_Emboss;
        std::shared_ptr< bool > m_Engrave;
        std::shared_ptr< bool > m_Hidden;
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_HighlightColor;
        std::shared_ptr< bool > m_Italic;
        std::shared_ptr< bool > m_ItalicBi;
        std::shared_ptr< double > m_Kerning;
        std::shared_ptr< int32_t > m_LocaleId;
        std::shared_ptr< int32_t > m_LocaleIdBi;
        std::shared_ptr< int32_t > m_LocaleIdFarEast;
        std::shared_ptr< std::wstring > m_Name;
        std::shared_ptr< std::wstring > m_NameAscii;
        std::shared_ptr< std::wstring > m_NameBi;
        std::shared_ptr< std::wstring > m_NameFarEast;
        std::shared_ptr< std::wstring > m_NameOther;
        std::shared_ptr< bool > m_NoProofing;
        std::shared_ptr< bool > m_Outline;
        std::shared_ptr< double > m_Position;
        std::shared_ptr< int32_t > m_Scaling;
        std::shared_ptr< bool > m_Shadow;
        std::shared_ptr< double > m_Size;
        std::shared_ptr< double > m_SizeBi;
        std::shared_ptr< bool > m_SmallCaps;
        std::shared_ptr< double > m_Spacing;
        std::shared_ptr< bool > m_StrikeThrough;
        std::shared_ptr< aspose::words::cloud::models::Font::StyleIdentifier > m_StyleIdentifier;
        std::shared_ptr< std::wstring > m_StyleName;
        std::shared_ptr< bool > m_Subscript;
        std::shared_ptr< bool > m_Superscript;
        std::shared_ptr< aspose::words::cloud::models::Font::TextEffect > m_TextEffect;
        std::shared_ptr< aspose::words::cloud::models::Font::Underline > m_Underline;
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_UnderlineColor;
    };
}

