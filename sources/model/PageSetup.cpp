/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageSetup.cpp">
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

#include "PageSetup.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

PageSetup::PageSetup()
{
    m_Bidi = false;
    m_BidiIsSet = false;
    m_BorderAlwaysInFront = false;
    m_BorderAlwaysInFrontIsSet = false;

    m_BorderAppliesToIsSet = false;

    m_BorderDistanceFromIsSet = false;
    m_BottomMargin = 0.0;
    m_BottomMarginIsSet = false;
    m_DifferentFirstPageHeaderFooter = false;
    m_DifferentFirstPageHeaderFooterIsSet = false;
    m_FirstPageTray = 0;
    m_FirstPageTrayIsSet = false;
    m_FooterDistance = 0.0;
    m_FooterDistanceIsSet = false;
    m_Gutter = 0.0;
    m_GutterIsSet = false;
    m_HeaderDistance = 0.0;
    m_HeaderDistanceIsSet = false;
    m_LeftMargin = 0.0;
    m_LeftMarginIsSet = false;
    m_LineNumberCountBy = 0;
    m_LineNumberCountByIsSet = false;
    m_LineNumberDistanceFromText = 0.0;
    m_LineNumberDistanceFromTextIsSet = false;

    m_LineNumberRestartModeIsSet = false;
    m_LineStartingNumber = 0;
    m_LineStartingNumberIsSet = false;

    m_OrientationIsSet = false;
    m_OtherPagesTray = 0;
    m_OtherPagesTrayIsSet = false;
    m_PageHeight = 0.0;
    m_PageHeightIsSet = false;

    m_PageNumberStyleIsSet = false;
    m_PageStartingNumber = 0;
    m_PageStartingNumberIsSet = false;
    m_PageWidth = 0.0;
    m_PageWidthIsSet = false;

    m_PaperSizeIsSet = false;
    m_RestartPageNumbering = false;
    m_RestartPageNumberingIsSet = false;
    m_RightMargin = 0.0;
    m_RightMarginIsSet = false;
    m_RtlGutter = false;
    m_RtlGutterIsSet = false;

    m_SectionStartIsSet = false;
    m_SuppressEndnotes = false;
    m_SuppressEndnotesIsSet = false;
    m_TopMargin = 0.0;
    m_TopMarginIsSet = false;

    m_VerticalAlignmentIsSet = false;

}

PageSetup::~PageSetup()
{
}

void PageSetup::validate()
{
    // TODO: implement validation
}

web::json::value PageSetup::toJson() const
{
    web::json::value val = this->LinkElement::toJson();
    if(m_BidiIsSet)
    {
        val[_XPLATSTR("Bidi")] = ModelBase::toJson(m_Bidi);
    }
    if(m_BorderAlwaysInFrontIsSet)
    {
        val[_XPLATSTR("BorderAlwaysInFront")] = ModelBase::toJson(m_BorderAlwaysInFront);
    }
    if(m_BorderAppliesToIsSet)
    {
        val[_XPLATSTR("BorderAppliesTo")] = ModelBase::toJson(m_BorderAppliesTo);
    }
    if(m_BorderDistanceFromIsSet)
    {
        val[_XPLATSTR("BorderDistanceFrom")] = ModelBase::toJson(m_BorderDistanceFrom);
    }
    if(m_BottomMarginIsSet)
    {
        val[_XPLATSTR("BottomMargin")] = ModelBase::toJson(m_BottomMargin);
    }
    if(m_DifferentFirstPageHeaderFooterIsSet)
    {
        val[_XPLATSTR("DifferentFirstPageHeaderFooter")] = ModelBase::toJson(m_DifferentFirstPageHeaderFooter);
    }
    if(m_FirstPageTrayIsSet)
    {
        val[_XPLATSTR("FirstPageTray")] = ModelBase::toJson(m_FirstPageTray);
    }
    if(m_FooterDistanceIsSet)
    {
        val[_XPLATSTR("FooterDistance")] = ModelBase::toJson(m_FooterDistance);
    }
    if(m_GutterIsSet)
    {
        val[_XPLATSTR("Gutter")] = ModelBase::toJson(m_Gutter);
    }
    if(m_HeaderDistanceIsSet)
    {
        val[_XPLATSTR("HeaderDistance")] = ModelBase::toJson(m_HeaderDistance);
    }
    if(m_LeftMarginIsSet)
    {
        val[_XPLATSTR("LeftMargin")] = ModelBase::toJson(m_LeftMargin);
    }
    if(m_LineNumberCountByIsSet)
    {
        val[_XPLATSTR("LineNumberCountBy")] = ModelBase::toJson(m_LineNumberCountBy);
    }
    if(m_LineNumberDistanceFromTextIsSet)
    {
        val[_XPLATSTR("LineNumberDistanceFromText")] = ModelBase::toJson(m_LineNumberDistanceFromText);
    }
    if(m_LineNumberRestartModeIsSet)
    {
        val[_XPLATSTR("LineNumberRestartMode")] = ModelBase::toJson(m_LineNumberRestartMode);
    }
    if(m_LineStartingNumberIsSet)
    {
        val[_XPLATSTR("LineStartingNumber")] = ModelBase::toJson(m_LineStartingNumber);
    }
    if(m_OrientationIsSet)
    {
        val[_XPLATSTR("Orientation")] = ModelBase::toJson(m_Orientation);
    }
    if(m_OtherPagesTrayIsSet)
    {
        val[_XPLATSTR("OtherPagesTray")] = ModelBase::toJson(m_OtherPagesTray);
    }
    if(m_PageHeightIsSet)
    {
        val[_XPLATSTR("PageHeight")] = ModelBase::toJson(m_PageHeight);
    }
    if(m_PageNumberStyleIsSet)
    {
        val[_XPLATSTR("PageNumberStyle")] = ModelBase::toJson(m_PageNumberStyle);
    }
    if(m_PageStartingNumberIsSet)
    {
        val[_XPLATSTR("PageStartingNumber")] = ModelBase::toJson(m_PageStartingNumber);
    }
    if(m_PageWidthIsSet)
    {
        val[_XPLATSTR("PageWidth")] = ModelBase::toJson(m_PageWidth);
    }
    if(m_PaperSizeIsSet)
    {
        val[_XPLATSTR("PaperSize")] = ModelBase::toJson(m_PaperSize);
    }
    if(m_RestartPageNumberingIsSet)
    {
        val[_XPLATSTR("RestartPageNumbering")] = ModelBase::toJson(m_RestartPageNumbering);
    }
    if(m_RightMarginIsSet)
    {
        val[_XPLATSTR("RightMargin")] = ModelBase::toJson(m_RightMargin);
    }
    if(m_RtlGutterIsSet)
    {
        val[_XPLATSTR("RtlGutter")] = ModelBase::toJson(m_RtlGutter);
    }
    if(m_SectionStartIsSet)
    {
        val[_XPLATSTR("SectionStart")] = ModelBase::toJson(m_SectionStart);
    }
    if(m_SuppressEndnotesIsSet)
    {
        val[_XPLATSTR("SuppressEndnotes")] = ModelBase::toJson(m_SuppressEndnotes);
    }
    if(m_TopMarginIsSet)
    {
        val[_XPLATSTR("TopMargin")] = ModelBase::toJson(m_TopMargin);
    }
    if(m_VerticalAlignmentIsSet)
    {
        val[_XPLATSTR("VerticalAlignment")] = ModelBase::toJson(m_VerticalAlignment);
    }

    return val;
}

void PageSetup::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("Bidi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Bidi")];
        if(!fieldValue.is_null())
        {
           setBidi(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("BorderAlwaysInFront")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BorderAlwaysInFront")];
        if(!fieldValue.is_null())
        {
           setBorderAlwaysInFront(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("BorderAppliesTo")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BorderAppliesTo")];
        if(!fieldValue.is_null())
        {
           setBorderAppliesTo(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("BorderDistanceFrom")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BorderDistanceFrom")];
        if(!fieldValue.is_null())
        {
           setBorderDistanceFrom(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("BottomMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("BottomMargin")];
        if(!fieldValue.is_null())
        {
           setBottomMargin(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("DifferentFirstPageHeaderFooter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DifferentFirstPageHeaderFooter")];
        if(!fieldValue.is_null())
        {
           setDifferentFirstPageHeaderFooter(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("FirstPageTray")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FirstPageTray")];
        if(!fieldValue.is_null())
        {
           setFirstPageTray(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("FooterDistance")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FooterDistance")];
        if(!fieldValue.is_null())
        {
           setFooterDistance(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Gutter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Gutter")];
        if(!fieldValue.is_null())
        {
           setGutter(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("HeaderDistance")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HeaderDistance")];
        if(!fieldValue.is_null())
        {
           setHeaderDistance(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LeftMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LeftMargin")];
        if(!fieldValue.is_null())
        {
           setLeftMargin(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LineNumberCountBy")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineNumberCountBy")];
        if(!fieldValue.is_null())
        {
           setLineNumberCountBy(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LineNumberDistanceFromText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineNumberDistanceFromText")];
        if(!fieldValue.is_null())
        {
           setLineNumberDistanceFromText(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LineNumberRestartMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineNumberRestartMode")];
        if(!fieldValue.is_null())
        {
           setLineNumberRestartMode(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("LineStartingNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("LineStartingNumber")];
        if(!fieldValue.is_null())
        {
           setLineStartingNumber(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("Orientation")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Orientation")];
        if(!fieldValue.is_null())
        {
           setOrientation(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("OtherPagesTray")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OtherPagesTray")];
        if(!fieldValue.is_null())
        {
           setOtherPagesTray(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PageHeight")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageHeight")];
        if(!fieldValue.is_null())
        {
           setPageHeight(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PageNumberStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageNumberStyle")];
        if(!fieldValue.is_null())
        {
           setPageNumberStyle(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PageStartingNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageStartingNumber")];
        if(!fieldValue.is_null())
        {
           setPageStartingNumber(ModelBase::integerFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PageWidth")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageWidth")];
        if(!fieldValue.is_null())
        {
           setPageWidth(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PaperSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PaperSize")];
        if(!fieldValue.is_null())
        {
           setPaperSize(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RestartPageNumbering")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RestartPageNumbering")];
        if(!fieldValue.is_null())
        {
           setRestartPageNumbering(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RightMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RightMargin")];
        if(!fieldValue.is_null())
        {
           setRightMargin(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("RtlGutter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("RtlGutter")];
        if(!fieldValue.is_null())
        {
           setRtlGutter(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SectionStart")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SectionStart")];
        if(!fieldValue.is_null())
        {
           setSectionStart(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SuppressEndnotes")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SuppressEndnotes")];
        if(!fieldValue.is_null())
        {
           setSuppressEndnotes(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("TopMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TopMargin")];
        if(!fieldValue.is_null())
        {
           setTopMargin(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("VerticalAlignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("VerticalAlignment")];
        if(!fieldValue.is_null())
        {
           setVerticalAlignment(ModelBase::enumFromJson(fieldValue));
        }
    }

}

void PageSetup::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    LinkElement::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_BidiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Bidi"), m_Bidi));
    }


    if(m_BorderAlwaysInFrontIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BorderAlwaysInFront"), m_BorderAlwaysInFront));
    }


    if(m_BorderAppliesToIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BorderAppliesTo"), m_BorderAppliesTo));
    }


    if(m_BorderDistanceFromIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BorderDistanceFrom"), m_BorderDistanceFrom));
    }


    if(m_BottomMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("BottomMargin"), m_BottomMargin));
    }


    if(m_DifferentFirstPageHeaderFooterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DifferentFirstPageHeaderFooter"), m_DifferentFirstPageHeaderFooter));
    }


    if(m_FirstPageTrayIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FirstPageTray"), m_FirstPageTray));
    }


    if(m_FooterDistanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FooterDistance"), m_FooterDistance));
    }


    if(m_GutterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Gutter"), m_Gutter));
    }


    if(m_HeaderDistanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HeaderDistance"), m_HeaderDistance));
    }


    if(m_LeftMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LeftMargin"), m_LeftMargin));
    }


    if(m_LineNumberCountByIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineNumberCountBy"), m_LineNumberCountBy));
    }


    if(m_LineNumberDistanceFromTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineNumberDistanceFromText"), m_LineNumberDistanceFromText));
    }


    if(m_LineNumberRestartModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineNumberRestartMode"), m_LineNumberRestartMode));
    }


    if(m_LineStartingNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("LineStartingNumber"), m_LineStartingNumber));
    }


    if(m_OrientationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Orientation"), m_Orientation));
    }


    if(m_OtherPagesTrayIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OtherPagesTray"), m_OtherPagesTray));
    }


    if(m_PageHeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageHeight"), m_PageHeight));
    }


    if(m_PageNumberStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageNumberStyle"), m_PageNumberStyle));
    }


    if(m_PageStartingNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageStartingNumber"), m_PageStartingNumber));
    }


    if(m_PageWidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageWidth"), m_PageWidth));
    }


    if(m_PaperSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PaperSize"), m_PaperSize));
    }


    if(m_RestartPageNumberingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RestartPageNumbering"), m_RestartPageNumbering));
    }


    if(m_RightMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RightMargin"), m_RightMargin));
    }


    if(m_RtlGutterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RtlGutter"), m_RtlGutter));
    }


    if(m_SectionStartIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SectionStart"), m_SectionStart));
    }


    if(m_SuppressEndnotesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SuppressEndnotes"), m_SuppressEndnotes));
    }


    if(m_TopMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TopMargin"), m_TopMargin));
    }


    if(m_VerticalAlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("VerticalAlignment"), m_VerticalAlignment));
    }

}

void PageSetup::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

bool PageSetup::isBidi() const
{
    return m_Bidi;
}


void PageSetup::setBidi(bool value)
{
    m_Bidi = value;
    m_BidiIsSet = true;
}

bool PageSetup::bidiIsSet() const
{
    return m_BidiIsSet;
}

void PageSetup::unsetBidi()
{
    m_BidiIsSet = false;
}

bool PageSetup::isBorderAlwaysInFront() const
{
    return m_BorderAlwaysInFront;
}


void PageSetup::setBorderAlwaysInFront(bool value)
{
    m_BorderAlwaysInFront = value;
    m_BorderAlwaysInFrontIsSet = true;
}

bool PageSetup::borderAlwaysInFrontIsSet() const
{
    return m_BorderAlwaysInFrontIsSet;
}

void PageSetup::unsetBorderAlwaysInFront()
{
    m_BorderAlwaysInFrontIsSet = false;
}

utility::string_t PageSetup::getBorderAppliesTo() const
{
    return m_BorderAppliesTo;
}


void PageSetup::setBorderAppliesTo(utility::string_t value)
{
    m_BorderAppliesTo = value;
    m_BorderAppliesToIsSet = true;
}

bool PageSetup::borderAppliesToIsSet() const
{
    return m_BorderAppliesToIsSet;
}

void PageSetup::unsetBorderAppliesTo()
{
    m_BorderAppliesToIsSet = false;
}

utility::string_t PageSetup::getBorderDistanceFrom() const
{
    return m_BorderDistanceFrom;
}


void PageSetup::setBorderDistanceFrom(utility::string_t value)
{
    m_BorderDistanceFrom = value;
    m_BorderDistanceFromIsSet = true;
}

bool PageSetup::borderDistanceFromIsSet() const
{
    return m_BorderDistanceFromIsSet;
}

void PageSetup::unsetBorderDistanceFrom()
{
    m_BorderDistanceFromIsSet = false;
}

double PageSetup::getBottomMargin() const
{
    return m_BottomMargin;
}


void PageSetup::setBottomMargin(double value)
{
    m_BottomMargin = value;
    m_BottomMarginIsSet = true;
}

bool PageSetup::bottomMarginIsSet() const
{
    return m_BottomMarginIsSet;
}

void PageSetup::unsetBottomMargin()
{
    m_BottomMarginIsSet = false;
}

bool PageSetup::isDifferentFirstPageHeaderFooter() const
{
    return m_DifferentFirstPageHeaderFooter;
}


void PageSetup::setDifferentFirstPageHeaderFooter(bool value)
{
    m_DifferentFirstPageHeaderFooter = value;
    m_DifferentFirstPageHeaderFooterIsSet = true;
}

bool PageSetup::differentFirstPageHeaderFooterIsSet() const
{
    return m_DifferentFirstPageHeaderFooterIsSet;
}

void PageSetup::unsetDifferentFirstPageHeaderFooter()
{
    m_DifferentFirstPageHeaderFooterIsSet = false;
}

int32_t PageSetup::getFirstPageTray() const
{
    return m_FirstPageTray;
}


void PageSetup::setFirstPageTray(int32_t value)
{
    m_FirstPageTray = value;
    m_FirstPageTrayIsSet = true;
}

bool PageSetup::firstPageTrayIsSet() const
{
    return m_FirstPageTrayIsSet;
}

void PageSetup::unsetFirstPageTray()
{
    m_FirstPageTrayIsSet = false;
}

double PageSetup::getFooterDistance() const
{
    return m_FooterDistance;
}


void PageSetup::setFooterDistance(double value)
{
    m_FooterDistance = value;
    m_FooterDistanceIsSet = true;
}

bool PageSetup::footerDistanceIsSet() const
{
    return m_FooterDistanceIsSet;
}

void PageSetup::unsetFooterDistance()
{
    m_FooterDistanceIsSet = false;
}

double PageSetup::getGutter() const
{
    return m_Gutter;
}


void PageSetup::setGutter(double value)
{
    m_Gutter = value;
    m_GutterIsSet = true;
}

bool PageSetup::gutterIsSet() const
{
    return m_GutterIsSet;
}

void PageSetup::unsetGutter()
{
    m_GutterIsSet = false;
}

double PageSetup::getHeaderDistance() const
{
    return m_HeaderDistance;
}


void PageSetup::setHeaderDistance(double value)
{
    m_HeaderDistance = value;
    m_HeaderDistanceIsSet = true;
}

bool PageSetup::headerDistanceIsSet() const
{
    return m_HeaderDistanceIsSet;
}

void PageSetup::unsetHeaderDistance()
{
    m_HeaderDistanceIsSet = false;
}

double PageSetup::getLeftMargin() const
{
    return m_LeftMargin;
}


void PageSetup::setLeftMargin(double value)
{
    m_LeftMargin = value;
    m_LeftMarginIsSet = true;
}

bool PageSetup::leftMarginIsSet() const
{
    return m_LeftMarginIsSet;
}

void PageSetup::unsetLeftMargin()
{
    m_LeftMarginIsSet = false;
}

int32_t PageSetup::getLineNumberCountBy() const
{
    return m_LineNumberCountBy;
}


void PageSetup::setLineNumberCountBy(int32_t value)
{
    m_LineNumberCountBy = value;
    m_LineNumberCountByIsSet = true;
}

bool PageSetup::lineNumberCountByIsSet() const
{
    return m_LineNumberCountByIsSet;
}

void PageSetup::unsetLineNumberCountBy()
{
    m_LineNumberCountByIsSet = false;
}

double PageSetup::getLineNumberDistanceFromText() const
{
    return m_LineNumberDistanceFromText;
}


void PageSetup::setLineNumberDistanceFromText(double value)
{
    m_LineNumberDistanceFromText = value;
    m_LineNumberDistanceFromTextIsSet = true;
}

bool PageSetup::lineNumberDistanceFromTextIsSet() const
{
    return m_LineNumberDistanceFromTextIsSet;
}

void PageSetup::unsetLineNumberDistanceFromText()
{
    m_LineNumberDistanceFromTextIsSet = false;
}

utility::string_t PageSetup::getLineNumberRestartMode() const
{
    return m_LineNumberRestartMode;
}


void PageSetup::setLineNumberRestartMode(utility::string_t value)
{
    m_LineNumberRestartMode = value;
    m_LineNumberRestartModeIsSet = true;
}

bool PageSetup::lineNumberRestartModeIsSet() const
{
    return m_LineNumberRestartModeIsSet;
}

void PageSetup::unsetLineNumberRestartMode()
{
    m_LineNumberRestartModeIsSet = false;
}

int32_t PageSetup::getLineStartingNumber() const
{
    return m_LineStartingNumber;
}


void PageSetup::setLineStartingNumber(int32_t value)
{
    m_LineStartingNumber = value;
    m_LineStartingNumberIsSet = true;
}

bool PageSetup::lineStartingNumberIsSet() const
{
    return m_LineStartingNumberIsSet;
}

void PageSetup::unsetLineStartingNumber()
{
    m_LineStartingNumberIsSet = false;
}

utility::string_t PageSetup::getOrientation() const
{
    return m_Orientation;
}


void PageSetup::setOrientation(utility::string_t value)
{
    m_Orientation = value;
    m_OrientationIsSet = true;
}

bool PageSetup::orientationIsSet() const
{
    return m_OrientationIsSet;
}

void PageSetup::unsetOrientation()
{
    m_OrientationIsSet = false;
}

int32_t PageSetup::getOtherPagesTray() const
{
    return m_OtherPagesTray;
}


void PageSetup::setOtherPagesTray(int32_t value)
{
    m_OtherPagesTray = value;
    m_OtherPagesTrayIsSet = true;
}

bool PageSetup::otherPagesTrayIsSet() const
{
    return m_OtherPagesTrayIsSet;
}

void PageSetup::unsetOtherPagesTray()
{
    m_OtherPagesTrayIsSet = false;
}

double PageSetup::getPageHeight() const
{
    return m_PageHeight;
}


void PageSetup::setPageHeight(double value)
{
    m_PageHeight = value;
    m_PageHeightIsSet = true;
}

bool PageSetup::pageHeightIsSet() const
{
    return m_PageHeightIsSet;
}

void PageSetup::unsetPageHeight()
{
    m_PageHeightIsSet = false;
}

utility::string_t PageSetup::getPageNumberStyle() const
{
    return m_PageNumberStyle;
}


void PageSetup::setPageNumberStyle(utility::string_t value)
{
    m_PageNumberStyle = value;
    m_PageNumberStyleIsSet = true;
}

bool PageSetup::pageNumberStyleIsSet() const
{
    return m_PageNumberStyleIsSet;
}

void PageSetup::unsetPageNumberStyle()
{
    m_PageNumberStyleIsSet = false;
}

int32_t PageSetup::getPageStartingNumber() const
{
    return m_PageStartingNumber;
}


void PageSetup::setPageStartingNumber(int32_t value)
{
    m_PageStartingNumber = value;
    m_PageStartingNumberIsSet = true;
}

bool PageSetup::pageStartingNumberIsSet() const
{
    return m_PageStartingNumberIsSet;
}

void PageSetup::unsetPageStartingNumber()
{
    m_PageStartingNumberIsSet = false;
}

double PageSetup::getPageWidth() const
{
    return m_PageWidth;
}


void PageSetup::setPageWidth(double value)
{
    m_PageWidth = value;
    m_PageWidthIsSet = true;
}

bool PageSetup::pageWidthIsSet() const
{
    return m_PageWidthIsSet;
}

void PageSetup::unsetPageWidth()
{
    m_PageWidthIsSet = false;
}

utility::string_t PageSetup::getPaperSize() const
{
    return m_PaperSize;
}


void PageSetup::setPaperSize(utility::string_t value)
{
    m_PaperSize = value;
    m_PaperSizeIsSet = true;
}

bool PageSetup::paperSizeIsSet() const
{
    return m_PaperSizeIsSet;
}

void PageSetup::unsetPaperSize()
{
    m_PaperSizeIsSet = false;
}

bool PageSetup::isRestartPageNumbering() const
{
    return m_RestartPageNumbering;
}


void PageSetup::setRestartPageNumbering(bool value)
{
    m_RestartPageNumbering = value;
    m_RestartPageNumberingIsSet = true;
}

bool PageSetup::restartPageNumberingIsSet() const
{
    return m_RestartPageNumberingIsSet;
}

void PageSetup::unsetRestartPageNumbering()
{
    m_RestartPageNumberingIsSet = false;
}

double PageSetup::getRightMargin() const
{
    return m_RightMargin;
}


void PageSetup::setRightMargin(double value)
{
    m_RightMargin = value;
    m_RightMarginIsSet = true;
}

bool PageSetup::rightMarginIsSet() const
{
    return m_RightMarginIsSet;
}

void PageSetup::unsetRightMargin()
{
    m_RightMarginIsSet = false;
}

bool PageSetup::isRtlGutter() const
{
    return m_RtlGutter;
}


void PageSetup::setRtlGutter(bool value)
{
    m_RtlGutter = value;
    m_RtlGutterIsSet = true;
}

bool PageSetup::rtlGutterIsSet() const
{
    return m_RtlGutterIsSet;
}

void PageSetup::unsetRtlGutter()
{
    m_RtlGutterIsSet = false;
}

utility::string_t PageSetup::getSectionStart() const
{
    return m_SectionStart;
}


void PageSetup::setSectionStart(utility::string_t value)
{
    m_SectionStart = value;
    m_SectionStartIsSet = true;
}

bool PageSetup::sectionStartIsSet() const
{
    return m_SectionStartIsSet;
}

void PageSetup::unsetSectionStart()
{
    m_SectionStartIsSet = false;
}

bool PageSetup::isSuppressEndnotes() const
{
    return m_SuppressEndnotes;
}


void PageSetup::setSuppressEndnotes(bool value)
{
    m_SuppressEndnotes = value;
    m_SuppressEndnotesIsSet = true;
}

bool PageSetup::suppressEndnotesIsSet() const
{
    return m_SuppressEndnotesIsSet;
}

void PageSetup::unsetSuppressEndnotes()
{
    m_SuppressEndnotesIsSet = false;
}

double PageSetup::getTopMargin() const
{
    return m_TopMargin;
}


void PageSetup::setTopMargin(double value)
{
    m_TopMargin = value;
    m_TopMarginIsSet = true;
}

bool PageSetup::topMarginIsSet() const
{
    return m_TopMarginIsSet;
}

void PageSetup::unsetTopMargin()
{
    m_TopMarginIsSet = false;
}

utility::string_t PageSetup::getVerticalAlignment() const
{
    return m_VerticalAlignment;
}


void PageSetup::setVerticalAlignment(utility::string_t value)
{
    m_VerticalAlignment = value;
    m_VerticalAlignmentIsSet = true;
}

bool PageSetup::verticalAlignmentIsSet() const
{
    return m_VerticalAlignmentIsSet;
}

void PageSetup::unsetVerticalAlignment()
{
    m_VerticalAlignmentIsSet = false;
}

}
}
}
}
}
