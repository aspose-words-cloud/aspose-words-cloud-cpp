/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageSetup.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_PageSetup_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_PageSetup_H_


#include "LinkElement.h"
#include "WordsApiLink.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents the page setup properties of a section.             
/// </summary>
class  PageSetup
    : public LinkElement
{
public:
    PageSetup();
    virtual ~PageSetup();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// PageSetup members

    /// <summary>
    /// Gets or sets specifies that this section contains bidirectional (complex scripts) text.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies where the page border is positioned relative to intersecting texts and objects.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBorderAlwaysInFront() const;
    bool borderAlwaysInFrontIsSet() const;
    void unsetBorderAlwaysInFront();
    void setBorderAlwaysInFront(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies which pages the page border is printed on.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getBorderAppliesTo() const;
    bool borderAppliesToIsSet() const;
    void unsetBorderAppliesTo();
    void setBorderAppliesTo(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value that indicates whether the specified page border is measured from the edge of the page or from the text it surrounds.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getBorderDistanceFrom() const;
    bool borderDistanceFromIsSet() const;
    void unsetBorderDistanceFrom();
    void setBorderDistanceFrom(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the distance (in points) between the bottom edge of the page and the bottom boundary of the body text.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getBottomMargin() const;
    bool bottomMarginIsSet() const;
    void unsetBottomMargin();
    void setBottomMargin(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if a different header or footer is used on the first page.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isDifferentFirstPageHeaderFooter() const;
    bool differentFirstPageHeaderFooterIsSet() const;
    void unsetDifferentFirstPageHeaderFooter();
    void setDifferentFirstPageHeaderFooter(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the paper tray (bin) to use for the first page of a section. The value is implementation (printer) specific.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getFirstPageTray() const;
    bool firstPageTrayIsSet() const;
    void unsetFirstPageTray();
    void setFirstPageTray(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the distance (in points) between the footer and the bottom of the page.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getFooterDistance() const;
    bool footerDistanceIsSet() const;
    void unsetFooterDistance();
    void setFooterDistance(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of extra space added to the margin for document binding.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getGutter() const;
    bool gutterIsSet() const;
    void unsetGutter();
    void setGutter(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the distance (in points) between the header and the top of the page.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getHeaderDistance() const;
    bool headerDistanceIsSet() const;
    void unsetHeaderDistance();
    void setHeaderDistance(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the distance (in points) between the left edge of the page and the left boundary of the body text.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLeftMargin() const;
    bool leftMarginIsSet() const;
    void unsetLeftMargin();
    void setLeftMargin(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the numeric increment for line numbers.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getLineNumberCountBy() const;
    bool lineNumberCountByIsSet() const;
    void unsetLineNumberCountBy();
    void setLineNumberCountBy(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets distance between the right edge of line numbers and the left edge of the document.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLineNumberDistanceFromText() const;
    bool lineNumberDistanceFromTextIsSet() const;
    void unsetLineNumberDistanceFromText();
    void setLineNumberDistanceFromText(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the way line numbering runs  that is, whether it starts over at the beginning of a new page or section or runs continuously.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getLineNumberRestartMode() const;
    bool lineNumberRestartModeIsSet() const;
    void unsetLineNumberRestartMode();
    void setLineNumberRestartMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the starting line number.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getLineStartingNumber() const;
    bool lineStartingNumberIsSet() const;
    void unsetLineStartingNumber();
    void setLineStartingNumber(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the orientation of the page.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getOrientation() const;
    bool orientationIsSet() const;
    void unsetOrientation();
    void setOrientation(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the paper tray (bin) to be used for all but the first page of a section. The value is implementation (printer) specific.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getOtherPagesTray() const;
    bool otherPagesTrayIsSet() const;
    void unsetOtherPagesTray();
    void setOtherPagesTray(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the height of the page in points.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getPageHeight() const;
    bool pageHeightIsSet() const;
    void unsetPageHeight();
    void setPageHeight(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the page number format.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPageNumberStyle() const;
    bool pageNumberStyleIsSet() const;
    void unsetPageNumberStyle();
    void setPageNumberStyle(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the starting page number of the section.             
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getPageStartingNumber() const;
    bool pageStartingNumberIsSet() const;
    void unsetPageStartingNumber();
    void setPageStartingNumber(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the width of the page in points.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getPageWidth() const;
    bool pageWidthIsSet() const;
    void unsetPageWidth();
    void setPageWidth(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the paper size.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPaperSize() const;
    bool paperSizeIsSet() const;
    void unsetPaperSize();
    void setPaperSize(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if page numbering restarts at the beginning of the section.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isRestartPageNumbering() const;
    bool restartPageNumberingIsSet() const;
    void unsetRestartPageNumbering();
    void setRestartPageNumbering(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the distance (in points) between the right edge of the page and the right boundary of the body text.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getRightMargin() const;
    bool rightMarginIsSet() const;
    void unsetRightMargin();
    void setRightMargin(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets whether Microsoft Word uses gutters for the section based on a right-to-left language or a left-to-right language.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isRtlGutter() const;
    bool rtlGutterIsSet() const;
    void unsetRtlGutter();
    void setRtlGutter(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the type of section break for the specified object.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getSectionStart() const;
    bool sectionStartIsSet() const;
    void unsetSectionStart();
    void setSectionStart(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets true if endnotes are printed at the end of the next section that doesn&#x27;t suppress endnotes. Suppressed endnotes are printed before the endnotes in that section.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSuppressEndnotes() const;
    bool suppressEndnotesIsSet() const;
    void unsetSuppressEndnotes();
    void setSuppressEndnotes(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the distance (in points) between the top edge of the page and the top boundary of the body text.             
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getTopMargin() const;
    bool topMarginIsSet() const;
    void unsetTopMargin();
    void setTopMargin(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the vertical alignment of text on each page in a document or section.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getVerticalAlignment() const;
    bool verticalAlignmentIsSet() const;
    void unsetVerticalAlignment();
    void setVerticalAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Bidi;
    bool m_BidiIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_BorderAlwaysInFront;
    bool m_BorderAlwaysInFrontIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_BorderAppliesTo;
    bool m_BorderAppliesToIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_BorderDistanceFrom;
    bool m_BorderDistanceFromIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_BottomMargin;
    bool m_BottomMarginIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_DifferentFirstPageHeaderFooter;
    bool m_DifferentFirstPageHeaderFooterIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_FirstPageTray;
    bool m_FirstPageTrayIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_FooterDistance;
    bool m_FooterDistanceIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Gutter;
    bool m_GutterIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_HeaderDistance;
    bool m_HeaderDistanceIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LeftMargin;
    bool m_LeftMarginIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_LineNumberCountBy;
    bool m_LineNumberCountByIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LineNumberDistanceFromText;
    bool m_LineNumberDistanceFromTextIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_LineNumberRestartMode;
    bool m_LineNumberRestartModeIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_LineStartingNumber;
    bool m_LineStartingNumberIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Orientation;
    bool m_OrientationIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_OtherPagesTray;
    bool m_OtherPagesTrayIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_PageHeight;
    bool m_PageHeightIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_PageNumberStyle;
    bool m_PageNumberStyleIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_PageStartingNumber;
    bool m_PageStartingNumberIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_PageWidth;
    bool m_PageWidthIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_PaperSize;
    bool m_PaperSizeIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_RestartPageNumbering;
    bool m_RestartPageNumberingIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_RightMargin;
    bool m_RightMarginIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_RtlGutter;
    bool m_RtlGutterIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_SectionStart;
    bool m_SectionStartIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_SuppressEndnotes;
    bool m_SuppressEndnotesIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_TopMargin;
    bool m_TopMarginIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_VerticalAlignment;
    bool m_VerticalAlignmentIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PageSetup_H_ */
