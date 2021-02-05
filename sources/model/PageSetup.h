/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageSetup.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents the page setup properties of a section.
/// </summary>
class PageSetup
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
    /// Gets or sets a value indicating whether this section contains bidirectional (complex scripts) text.
    /// </summary>
    bool isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether the page border is positioned relative to intersecting texts and objects.
    /// </summary>
    bool isBorderAlwaysInFront() const;
    bool borderAlwaysInFrontIsSet() const;
    void unsetBorderAlwaysInFront();
    void setBorderAlwaysInFront(bool value);

    /// <summary>
    /// Gets or sets the option that controls which pages the page border is printed on.
    /// </summary>
    utility::string_t getBorderAppliesTo() const;
    bool borderAppliesToIsSet() const;
    void unsetBorderAppliesTo();
    void setBorderAppliesTo(utility::string_t value);

    /// <summary>
    /// Gets or sets the value, that indicates whether the specified page border is measured from the edge of the page or from the text it surrounds.
    /// </summary>
    utility::string_t getBorderDistanceFrom() const;
    bool borderDistanceFromIsSet() const;
    void unsetBorderDistanceFrom();
    void setBorderDistanceFrom(utility::string_t value);

    /// <summary>
    /// Gets or sets the distance (in points) between the bottom edge of the page and the bottom boundary of the body text.
    /// </summary>
    double getBottomMargin() const;
    bool bottomMarginIsSet() const;
    void unsetBottomMargin();
    void setBottomMargin(double value);

    /// <summary>
    /// Gets or sets a value indicating whether a different header or footer is used on the first page.
    /// </summary>
    bool isDifferentFirstPageHeaderFooter() const;
    bool differentFirstPageHeaderFooterIsSet() const;
    void unsetDifferentFirstPageHeaderFooter();
    void setDifferentFirstPageHeaderFooter(bool value);

    /// <summary>
    /// Gets or sets the paper tray (bin) to use for the first page of a section.
    /// The value is implementation (printer) specific.
    /// </summary>
    int32_t getFirstPageTray() const;
    bool firstPageTrayIsSet() const;
    void unsetFirstPageTray();
    void setFirstPageTray(int32_t value);

    /// <summary>
    /// Gets or sets the distance (in points) between the footer and the bottom of the page.
    /// </summary>
    double getFooterDistance() const;
    bool footerDistanceIsSet() const;
    void unsetFooterDistance();
    void setFooterDistance(double value);

    /// <summary>
    /// Gets or sets the amount of extra space added to the margin for document binding.
    /// </summary>
    double getGutter() const;
    bool gutterIsSet() const;
    void unsetGutter();
    void setGutter(double value);

    /// <summary>
    /// Gets or sets the distance (in points) between the header and the top of the page.
    /// </summary>
    double getHeaderDistance() const;
    bool headerDistanceIsSet() const;
    void unsetHeaderDistance();
    void setHeaderDistance(double value);

    /// <summary>
    /// Gets or sets the distance (in points) between the left edge of the page and the left boundary of the body text.
    /// </summary>
    double getLeftMargin() const;
    bool leftMarginIsSet() const;
    void unsetLeftMargin();
    void setLeftMargin(double value);

    /// <summary>
    /// Gets or sets the numeric increment for line numbers.
    /// </summary>
    int32_t getLineNumberCountBy() const;
    bool lineNumberCountByIsSet() const;
    void unsetLineNumberCountBy();
    void setLineNumberCountBy(int32_t value);

    /// <summary>
    /// Gets or sets the distance between the right edge of line numbers and the left edge of the document.
    /// </summary>
    double getLineNumberDistanceFromText() const;
    bool lineNumberDistanceFromTextIsSet() const;
    void unsetLineNumberDistanceFromText();
    void setLineNumberDistanceFromText(double value);

    /// <summary>
    /// Gets or sets the way line numbering runs  that is, whether it starts over at the beginning of a new page or section or runs continuously.
    /// </summary>
    utility::string_t getLineNumberRestartMode() const;
    bool lineNumberRestartModeIsSet() const;
    void unsetLineNumberRestartMode();
    void setLineNumberRestartMode(utility::string_t value);

    /// <summary>
    /// Gets or sets the starting line number.
    /// </summary>
    int32_t getLineStartingNumber() const;
    bool lineStartingNumberIsSet() const;
    void unsetLineStartingNumber();
    void setLineStartingNumber(int32_t value);

    /// <summary>
    /// Gets or sets the orientation of the page.
    /// </summary>
    utility::string_t getOrientation() const;
    bool orientationIsSet() const;
    void unsetOrientation();
    void setOrientation(utility::string_t value);

    /// <summary>
    /// Gets or sets the paper tray (bin) to be used for all but the first page of a section.
    /// The value is implementation (printer) specific.
    /// </summary>
    int32_t getOtherPagesTray() const;
    bool otherPagesTrayIsSet() const;
    void unsetOtherPagesTray();
    void setOtherPagesTray(int32_t value);

    /// <summary>
    /// Gets or sets the height of the page in points.
    /// </summary>
    double getPageHeight() const;
    bool pageHeightIsSet() const;
    void unsetPageHeight();
    void setPageHeight(double value);

    /// <summary>
    /// Gets or sets the page number format.
    /// </summary>
    utility::string_t getPageNumberStyle() const;
    bool pageNumberStyleIsSet() const;
    void unsetPageNumberStyle();
    void setPageNumberStyle(utility::string_t value);

    /// <summary>
    /// Gets or sets the starting page number of the section.
    /// </summary>
    int32_t getPageStartingNumber() const;
    bool pageStartingNumberIsSet() const;
    void unsetPageStartingNumber();
    void setPageStartingNumber(int32_t value);

    /// <summary>
    /// Gets or sets the width of the page in points.
    /// </summary>
    double getPageWidth() const;
    bool pageWidthIsSet() const;
    void unsetPageWidth();
    void setPageWidth(double value);

    /// <summary>
    /// Gets or sets the paper size.
    /// </summary>
    utility::string_t getPaperSize() const;
    bool paperSizeIsSet() const;
    void unsetPaperSize();
    void setPaperSize(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether page numbering restarts at the beginning of the section.
    /// </summary>
    bool isRestartPageNumbering() const;
    bool restartPageNumberingIsSet() const;
    void unsetRestartPageNumbering();
    void setRestartPageNumbering(bool value);

    /// <summary>
    /// Gets or sets the distance (in points) between the right edge of the page and the right boundary of the body text.
    /// </summary>
    double getRightMargin() const;
    bool rightMarginIsSet() const;
    void unsetRightMargin();
    void setRightMargin(double value);

    /// <summary>
    /// Gets or sets a value indicating whether Microsoft Word uses gutters for the section based on a right-to-left language or a left-to-right language.
    /// </summary>
    bool isRtlGutter() const;
    bool rtlGutterIsSet() const;
    void unsetRtlGutter();
    void setRtlGutter(bool value);

    /// <summary>
    /// Gets or sets the type of section break for the specified object.
    /// </summary>
    utility::string_t getSectionStart() const;
    bool sectionStartIsSet() const;
    void unsetSectionStart();
    void setSectionStart(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether endnotes are printed at the end of the next section that doesn't suppress endnotes. Suppressed endnotes are printed before the endnotes in that section.
    /// </summary>
    bool isSuppressEndnotes() const;
    bool suppressEndnotesIsSet() const;
    void unsetSuppressEndnotes();
    void setSuppressEndnotes(bool value);

    /// <summary>
    /// Gets or sets the distance (in points) between the top edge of the page and the top boundary of the body text.
    /// </summary>
    double getTopMargin() const;
    bool topMarginIsSet() const;
    void unsetTopMargin();
    void setTopMargin(double value);

    /// <summary>
    /// Gets or sets the vertical alignment of text on each page in the document.or section.
    /// </summary>
    utility::string_t getVerticalAlignment() const;
    bool verticalAlignmentIsSet() const;
    void unsetVerticalAlignment();
    void setVerticalAlignment(utility::string_t value);

protected:
    bool m_Bidi;
    bool m_BidiIsSet;

    bool m_BorderAlwaysInFront;
    bool m_BorderAlwaysInFrontIsSet;

    utility::string_t m_BorderAppliesTo;
    bool m_BorderAppliesToIsSet;

    utility::string_t m_BorderDistanceFrom;
    bool m_BorderDistanceFromIsSet;

    double m_BottomMargin;
    bool m_BottomMarginIsSet;

    bool m_DifferentFirstPageHeaderFooter;
    bool m_DifferentFirstPageHeaderFooterIsSet;

    int32_t m_FirstPageTray;
    bool m_FirstPageTrayIsSet;

    double m_FooterDistance;
    bool m_FooterDistanceIsSet;

    double m_Gutter;
    bool m_GutterIsSet;

    double m_HeaderDistance;
    bool m_HeaderDistanceIsSet;

    double m_LeftMargin;
    bool m_LeftMarginIsSet;

    int32_t m_LineNumberCountBy;
    bool m_LineNumberCountByIsSet;

    double m_LineNumberDistanceFromText;
    bool m_LineNumberDistanceFromTextIsSet;

    utility::string_t m_LineNumberRestartMode;
    bool m_LineNumberRestartModeIsSet;

    int32_t m_LineStartingNumber;
    bool m_LineStartingNumberIsSet;

    utility::string_t m_Orientation;
    bool m_OrientationIsSet;

    int32_t m_OtherPagesTray;
    bool m_OtherPagesTrayIsSet;

    double m_PageHeight;
    bool m_PageHeightIsSet;

    utility::string_t m_PageNumberStyle;
    bool m_PageNumberStyleIsSet;

    int32_t m_PageStartingNumber;
    bool m_PageStartingNumberIsSet;

    double m_PageWidth;
    bool m_PageWidthIsSet;

    utility::string_t m_PaperSize;
    bool m_PaperSizeIsSet;

    bool m_RestartPageNumbering;
    bool m_RestartPageNumberingIsSet;

    double m_RightMargin;
    bool m_RightMarginIsSet;

    bool m_RtlGutter;
    bool m_RtlGutterIsSet;

    utility::string_t m_SectionStart;
    bool m_SectionStartIsSet;

    bool m_SuppressEndnotes;
    bool m_SuppressEndnotesIsSet;

    double m_TopMargin;
    bool m_TopMarginIsSet;

    utility::string_t m_VerticalAlignment;
    bool m_VerticalAlignmentIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PageSetup_H_ */
