/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="page_setup.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents the page setup properties of a section.
    /// </summary>
    class PageSetup : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls which pages the page border is printed on.
        /// </summary>
        enum class BorderAppliesTo
        { 
            ALL_PAGES,
            FIRST_PAGE,
            OTHER_PAGES
        };

        /// <summary>
        /// Gets or sets the value, that indicates whether the specified page border is measured from the edge of the page or from the text it surrounds.
        /// </summary>
        enum class BorderDistanceFrom
        { 
            TEXT,
            PAGE_EDGE
        };

        /// <summary>
        /// Gets or sets the way line numbering runs  that is, whether it starts over at the beginning of a new page or section or runs continuously.
        /// </summary>
        enum class LineNumberRestartMode
        { 
            RESTART_PAGE,
            RESTART_SECTION,
            CONTINUOUS
        };

        /// <summary>
        /// Gets or sets the orientation of the page.
        /// </summary>
        enum class Orientation
        { 
            PORTRAIT,
            LANDSCAPE
        };

        /// <summary>
        /// Gets or sets the page number format.
        /// </summary>
        enum class PageNumberStyle
        { 
            ARABIC,
            UPPERCASE_ROMAN,
            LOWERCASE_ROMAN,
            UPPERCASE_LETTER,
            LOWERCASE_LETTER,
            ORDINAL,
            NUMBER,
            ORDINAL_TEXT,
            HEX,
            CHICAGO_MANUAL,
            KANJI,
            KANJI_DIGIT,
            AIUEO_HALF_WIDTH,
            IROHA_HALF_WIDTH,
            ARABIC_FULL_WIDTH,
            ARABIC_HALF_WIDTH,
            KANJI_TRADITIONAL,
            KANJI_TRADITIONAL2,
            NUMBER_IN_CIRCLE,
            DECIMAL_FULL_WIDTH,
            AIUEO,
            IROHA,
            LEADING_ZERO,
            BULLET,
            GANADA,
            CHOSUNG,
            G_B1,
            G_B2,
            G_B3,
            G_B4,
            ZODIAC1,
            ZODIAC2,
            ZODIAC3,
            TRAD_CHIN_NUM1,
            TRAD_CHIN_NUM2,
            TRAD_CHIN_NUM3,
            TRAD_CHIN_NUM4,
            SIMP_CHIN_NUM1,
            SIMP_CHIN_NUM2,
            SIMP_CHIN_NUM3,
            SIMP_CHIN_NUM4,
            HANJA_READ,
            HANJA_READ_DIGIT,
            HANGUL,
            HANJA,
            HEBREW1,
            ARABIC1,
            HEBREW2,
            ARABIC2,
            HINDI_LETTER1,
            HINDI_LETTER2,
            HINDI_ARABIC,
            HINDI_CARDINAL_TEXT,
            THAI_LETTER,
            THAI_ARABIC,
            THAI_CARDINAL_TEXT,
            VIET_CARDINAL_TEXT,
            NUMBER_IN_DASH,
            LOWERCASE_RUSSIAN,
            UPPERCASE_RUSSIAN,
            NONE,
            CUSTOM
        };

        /// <summary>
        /// Gets or sets the paper size.
        /// </summary>
        enum class PaperSize
        { 
            A3,
            A4,
            A5,
            B4,
            B5,
            EXECUTIVE,
            FOLIO,
            LEDGER,
            LEGAL,
            LETTER,
            ENVELOPE_DL,
            QUARTO,
            STATEMENT,
            TABLOID,
            PAPER10X14,
            PAPER11X17,
            NUMBER10_ENVELOPE,
            CUSTOM
        };

        /// <summary>
        /// Gets or sets the type of section break for the specified object.
        /// </summary>
        enum class SectionStart
        { 
            CONTINUOUS,
            NEW_COLUMN,
            NEW_PAGE,
            EVEN_PAGE,
            ODD_PAGE
        };

        /// <summary>
        /// Gets or sets the vertical alignment of text on each page in the document.or section.
        /// </summary>
        enum class VerticalAlignment
        { 
            TOP,
            CENTER,
            JUSTIFY,
            BOTTOM
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~PageSetup() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets a value indicating whether this section contains bidirectional (complex scripts) text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBidi() const;

        /// <summary>
        /// Gets or sets a value indicating whether this section contains bidirectional (complex scripts) text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBidi(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the page border is positioned relative to intersecting texts and objects.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getBorderAlwaysInFront() const;

        /// <summary>
        /// Gets or sets a value indicating whether the page border is positioned relative to intersecting texts and objects.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBorderAlwaysInFront(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls which pages the page border is printed on.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::BorderAppliesTo > getBorderAppliesTo() const;

        /// <summary>
        /// Gets or sets the option that controls which pages the page border is printed on.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBorderAppliesTo(std::shared_ptr< aspose::words::cloud::models::PageSetup::BorderAppliesTo > value);


        /// <summary>
        /// Gets or sets the value, that indicates whether the specified page border is measured from the edge of the page or from the text it surrounds.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::BorderDistanceFrom > getBorderDistanceFrom() const;

        /// <summary>
        /// Gets or sets the value, that indicates whether the specified page border is measured from the edge of the page or from the text it surrounds.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBorderDistanceFrom(std::shared_ptr< aspose::words::cloud::models::PageSetup::BorderDistanceFrom > value);


        /// <summary>
        /// Gets or sets the distance (in points) between the bottom edge of the page and the bottom boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getBottomMargin() const;

        /// <summary>
        /// Gets or sets the distance (in points) between the bottom edge of the page and the bottom boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBottomMargin(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether a different header or footer is used on the first page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getDifferentFirstPageHeaderFooter() const;

        /// <summary>
        /// Gets or sets a value indicating whether a different header or footer is used on the first page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDifferentFirstPageHeaderFooter(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the paper tray (bin) to use for the first page of a section.
        /// The value is implementation (printer) specific.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getFirstPageTray() const;

        /// <summary>
        /// Gets or sets the paper tray (bin) to use for the first page of a section.
        /// The value is implementation (printer) specific.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFirstPageTray(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the distance (in points) between the footer and the bottom of the page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getFooterDistance() const;

        /// <summary>
        /// Gets or sets the distance (in points) between the footer and the bottom of the page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFooterDistance(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the amount of extra space added to the margin for document binding.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getGutter() const;

        /// <summary>
        /// Gets or sets the amount of extra space added to the margin for document binding.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setGutter(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the distance (in points) between the header and the top of the page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getHeaderDistance() const;

        /// <summary>
        /// Gets or sets the distance (in points) between the header and the top of the page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeaderDistance(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the distance (in points) between the left edge of the page and the left boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLeftMargin() const;

        /// <summary>
        /// Gets or sets the distance (in points) between the left edge of the page and the left boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLeftMargin(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the numeric increment for line numbers.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getLineNumberCountBy() const;

        /// <summary>
        /// Gets or sets the numeric increment for line numbers.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineNumberCountBy(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the distance between the right edge of line numbers and the left edge of the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLineNumberDistanceFromText() const;

        /// <summary>
        /// Gets or sets the distance between the right edge of line numbers and the left edge of the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineNumberDistanceFromText(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the way line numbering runs  that is, whether it starts over at the beginning of a new page or section or runs continuously.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::LineNumberRestartMode > getLineNumberRestartMode() const;

        /// <summary>
        /// Gets or sets the way line numbering runs  that is, whether it starts over at the beginning of a new page or section or runs continuously.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineNumberRestartMode(std::shared_ptr< aspose::words::cloud::models::PageSetup::LineNumberRestartMode > value);


        /// <summary>
        /// Gets or sets the starting line number.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getLineStartingNumber() const;

        /// <summary>
        /// Gets or sets the starting line number.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineStartingNumber(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the orientation of the page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::Orientation > getOrientation() const;

        /// <summary>
        /// Gets or sets the orientation of the page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOrientation(std::shared_ptr< aspose::words::cloud::models::PageSetup::Orientation > value);


        /// <summary>
        /// Gets or sets the paper tray (bin) to be used for all but the first page of a section.
        /// The value is implementation (printer) specific.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getOtherPagesTray() const;

        /// <summary>
        /// Gets or sets the paper tray (bin) to be used for all but the first page of a section.
        /// The value is implementation (printer) specific.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOtherPagesTray(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the height of the page in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getPageHeight() const;

        /// <summary>
        /// Gets or sets the height of the page in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageHeight(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the page number format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::PageNumberStyle > getPageNumberStyle() const;

        /// <summary>
        /// Gets or sets the page number format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageNumberStyle(std::shared_ptr< aspose::words::cloud::models::PageSetup::PageNumberStyle > value);


        /// <summary>
        /// Gets or sets the starting page number of the section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getPageStartingNumber() const;

        /// <summary>
        /// Gets or sets the starting page number of the section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageStartingNumber(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the width of the page in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getPageWidth() const;

        /// <summary>
        /// Gets or sets the width of the page in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageWidth(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the paper size.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::PaperSize > getPaperSize() const;

        /// <summary>
        /// Gets or sets the paper size.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPaperSize(std::shared_ptr< aspose::words::cloud::models::PageSetup::PaperSize > value);


        /// <summary>
        /// Gets or sets a value indicating whether page numbering restarts at the beginning of the section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getRestartPageNumbering() const;

        /// <summary>
        /// Gets or sets a value indicating whether page numbering restarts at the beginning of the section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRestartPageNumbering(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the distance (in points) between the right edge of the page and the right boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getRightMargin() const;

        /// <summary>
        /// Gets or sets the distance (in points) between the right edge of the page and the right boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRightMargin(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether Microsoft Word uses gutters for the section based on a right-to-left language or a left-to-right language.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getRtlGutter() const;

        /// <summary>
        /// Gets or sets a value indicating whether Microsoft Word uses gutters for the section based on a right-to-left language or a left-to-right language.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRtlGutter(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the type of section break for the specified object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::SectionStart > getSectionStart() const;

        /// <summary>
        /// Gets or sets the type of section break for the specified object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSectionStart(std::shared_ptr< aspose::words::cloud::models::PageSetup::SectionStart > value);


        /// <summary>
        /// Gets or sets a value indicating whether endnotes are printed at the end of the next section that doesn't suppress endnotes. Suppressed endnotes are printed before the endnotes in that section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSuppressEndnotes() const;

        /// <summary>
        /// Gets or sets a value indicating whether endnotes are printed at the end of the next section that doesn't suppress endnotes. Suppressed endnotes are printed before the endnotes in that section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSuppressEndnotes(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the distance (in points) between the top edge of the page and the top boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTopMargin() const;

        /// <summary>
        /// Gets or sets the distance (in points) between the top edge of the page and the top boundary of the body text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTopMargin(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the vertical alignment of text on each page in the document.or section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PageSetup::VerticalAlignment > getVerticalAlignment() const;

        /// <summary>
        /// Gets or sets the vertical alignment of text on each page in the document.or section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setVerticalAlignment(std::shared_ptr< aspose::words::cloud::models::PageSetup::VerticalAlignment > value);


    protected:
        std::shared_ptr< bool > m_Bidi;
        std::shared_ptr< bool > m_BorderAlwaysInFront;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::BorderAppliesTo > m_BorderAppliesTo;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::BorderDistanceFrom > m_BorderDistanceFrom;
        std::shared_ptr< double > m_BottomMargin;
        std::shared_ptr< bool > m_DifferentFirstPageHeaderFooter;
        std::shared_ptr< int32_t > m_FirstPageTray;
        std::shared_ptr< double > m_FooterDistance;
        std::shared_ptr< double > m_Gutter;
        std::shared_ptr< double > m_HeaderDistance;
        std::shared_ptr< double > m_LeftMargin;
        std::shared_ptr< int32_t > m_LineNumberCountBy;
        std::shared_ptr< double > m_LineNumberDistanceFromText;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::LineNumberRestartMode > m_LineNumberRestartMode;
        std::shared_ptr< int32_t > m_LineStartingNumber;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::Orientation > m_Orientation;
        std::shared_ptr< int32_t > m_OtherPagesTray;
        std::shared_ptr< double > m_PageHeight;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::PageNumberStyle > m_PageNumberStyle;
        std::shared_ptr< int32_t > m_PageStartingNumber;
        std::shared_ptr< double > m_PageWidth;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::PaperSize > m_PaperSize;
        std::shared_ptr< bool > m_RestartPageNumbering;
        std::shared_ptr< double > m_RightMargin;
        std::shared_ptr< bool > m_RtlGutter;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::SectionStart > m_SectionStart;
        std::shared_ptr< bool > m_SuppressEndnotes;
        std::shared_ptr< double > m_TopMargin;
        std::shared_ptr< aspose::words::cloud::models::PageSetup::VerticalAlignment > m_VerticalAlignment;
    };
}

