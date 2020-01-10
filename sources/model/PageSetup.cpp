/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageSetup.cpp">
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
    m_BorderAppliesTo = utility::conversions::to_string_t("");
    m_BorderAppliesToIsSet = false;
    m_BorderDistanceFrom = utility::conversions::to_string_t("");
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
    m_LineNumberRestartMode = utility::conversions::to_string_t("");
    m_LineNumberRestartModeIsSet = false;
    m_LineStartingNumber = 0;
    m_LineStartingNumberIsSet = false;
    m_Orientation = utility::conversions::to_string_t("");
    m_OrientationIsSet = false;
    m_OtherPagesTray = 0;
    m_OtherPagesTrayIsSet = false;
    m_PageHeight = 0.0;
    m_PageHeightIsSet = false;
    m_PageNumberStyle = utility::conversions::to_string_t("");
    m_PageNumberStyleIsSet = false;
    m_PageStartingNumber = 0;
    m_PageStartingNumberIsSet = false;
    m_PageWidth = 0.0;
    m_PageWidthIsSet = false;
    m_PaperSize = utility::conversions::to_string_t("");
    m_PaperSizeIsSet = false;
    m_RestartPageNumbering = false;
    m_RestartPageNumberingIsSet = false;
    m_RightMargin = 0.0;
    m_RightMarginIsSet = false;
    m_RtlGutter = false;
    m_RtlGutterIsSet = false;
    m_SectionStart = utility::conversions::to_string_t("");
    m_SectionStartIsSet = false;
    m_SuppressEndnotes = false;
    m_SuppressEndnotesIsSet = false;
    m_TopMargin = 0.0;
    m_TopMarginIsSet = false;
    m_VerticalAlignment = utility::conversions::to_string_t("");
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
        val[_XPLATSTR("bidi")] = ModelBase::toJson(m_Bidi);
    }
    if(m_BorderAlwaysInFrontIsSet)
    {
        val[_XPLATSTR("borderAlwaysInFront")] = ModelBase::toJson(m_BorderAlwaysInFront);
    }
    if(m_BorderAppliesToIsSet)
    {
        val[_XPLATSTR("borderAppliesTo")] = ModelBase::toJson(m_BorderAppliesTo);
    }
    if(m_BorderDistanceFromIsSet)
    {
        val[_XPLATSTR("borderDistanceFrom")] = ModelBase::toJson(m_BorderDistanceFrom);
    }
    if(m_BottomMarginIsSet)
    {
        val[_XPLATSTR("bottomMargin")] = ModelBase::toJson(m_BottomMargin);
    }
    if(m_DifferentFirstPageHeaderFooterIsSet)
    {
        val[_XPLATSTR("differentFirstPageHeaderFooter")] = ModelBase::toJson(m_DifferentFirstPageHeaderFooter);
    }
    if(m_FirstPageTrayIsSet)
    {
        val[_XPLATSTR("firstPageTray")] = ModelBase::toJson(m_FirstPageTray);
    }
    if(m_FooterDistanceIsSet)
    {
        val[_XPLATSTR("footerDistance")] = ModelBase::toJson(m_FooterDistance);
    }
    if(m_GutterIsSet)
    {
        val[_XPLATSTR("gutter")] = ModelBase::toJson(m_Gutter);
    }
    if(m_HeaderDistanceIsSet)
    {
        val[_XPLATSTR("headerDistance")] = ModelBase::toJson(m_HeaderDistance);
    }
    if(m_LeftMarginIsSet)
    {
        val[_XPLATSTR("leftMargin")] = ModelBase::toJson(m_LeftMargin);
    }
    if(m_LineNumberCountByIsSet)
    {
        val[_XPLATSTR("lineNumberCountBy")] = ModelBase::toJson(m_LineNumberCountBy);
    }
    if(m_LineNumberDistanceFromTextIsSet)
    {
        val[_XPLATSTR("lineNumberDistanceFromText")] = ModelBase::toJson(m_LineNumberDistanceFromText);
    }
    if(m_LineNumberRestartModeIsSet)
    {
        val[_XPLATSTR("lineNumberRestartMode")] = ModelBase::toJson(m_LineNumberRestartMode);
    }
    if(m_LineStartingNumberIsSet)
    {
        val[_XPLATSTR("lineStartingNumber")] = ModelBase::toJson(m_LineStartingNumber);
    }
    if(m_OrientationIsSet)
    {
        val[_XPLATSTR("orientation")] = ModelBase::toJson(m_Orientation);
    }
    if(m_OtherPagesTrayIsSet)
    {
        val[_XPLATSTR("otherPagesTray")] = ModelBase::toJson(m_OtherPagesTray);
    }
    if(m_PageHeightIsSet)
    {
        val[_XPLATSTR("pageHeight")] = ModelBase::toJson(m_PageHeight);
    }
    if(m_PageNumberStyleIsSet)
    {
        val[_XPLATSTR("pageNumberStyle")] = ModelBase::toJson(m_PageNumberStyle);
    }
    if(m_PageStartingNumberIsSet)
    {
        val[_XPLATSTR("pageStartingNumber")] = ModelBase::toJson(m_PageStartingNumber);
    }
    if(m_PageWidthIsSet)
    {
        val[_XPLATSTR("pageWidth")] = ModelBase::toJson(m_PageWidth);
    }
    if(m_PaperSizeIsSet)
    {
        val[_XPLATSTR("paperSize")] = ModelBase::toJson(m_PaperSize);
    }
    if(m_RestartPageNumberingIsSet)
    {
        val[_XPLATSTR("restartPageNumbering")] = ModelBase::toJson(m_RestartPageNumbering);
    }
    if(m_RightMarginIsSet)
    {
        val[_XPLATSTR("rightMargin")] = ModelBase::toJson(m_RightMargin);
    }
    if(m_RtlGutterIsSet)
    {
        val[_XPLATSTR("rtlGutter")] = ModelBase::toJson(m_RtlGutter);
    }
    if(m_SectionStartIsSet)
    {
        val[_XPLATSTR("sectionStart")] = ModelBase::toJson(m_SectionStart);
    }
    if(m_SuppressEndnotesIsSet)
    {
        val[_XPLATSTR("suppressEndnotes")] = ModelBase::toJson(m_SuppressEndnotes);
    }
    if(m_TopMarginIsSet)
    {
        val[_XPLATSTR("topMargin")] = ModelBase::toJson(m_TopMargin);
    }
    if(m_VerticalAlignmentIsSet)
    {
        val[_XPLATSTR("verticalAlignment")] = ModelBase::toJson(m_VerticalAlignment);
    }

    return val;
}

void PageSetup::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(_XPLATSTR("bidi")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("bidi")];
        if(!fieldValue.is_null())
        {
            setBidi(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("borderAlwaysInFront")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("borderAlwaysInFront")];
        if(!fieldValue.is_null())
        {
            setBorderAlwaysInFront(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("borderAppliesTo")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("borderAppliesTo")];
        if(!fieldValue.is_null())
        {
            setBorderAppliesTo(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("borderDistanceFrom")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("borderDistanceFrom")];
        if(!fieldValue.is_null())
        {
            setBorderDistanceFrom(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("bottomMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("bottomMargin")];
        if(!fieldValue.is_null())
        {
            setBottomMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("differentFirstPageHeaderFooter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("differentFirstPageHeaderFooter")];
        if(!fieldValue.is_null())
        {
            setDifferentFirstPageHeaderFooter(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("firstPageTray")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("firstPageTray")];
        if(!fieldValue.is_null())
        {
            setFirstPageTray(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("footerDistance")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("footerDistance")];
        if(!fieldValue.is_null())
        {
            setFooterDistance(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("gutter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("gutter")];
        if(!fieldValue.is_null())
        {
            setGutter(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("headerDistance")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("headerDistance")];
        if(!fieldValue.is_null())
        {
            setHeaderDistance(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("leftMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("leftMargin")];
        if(!fieldValue.is_null())
        {
            setLeftMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineNumberCountBy")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineNumberCountBy")];
        if(!fieldValue.is_null())
        {
            setLineNumberCountBy(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineNumberDistanceFromText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineNumberDistanceFromText")];
        if(!fieldValue.is_null())
        {
            setLineNumberDistanceFromText(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineNumberRestartMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineNumberRestartMode")];
        if(!fieldValue.is_null())
        {
            setLineNumberRestartMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("lineStartingNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("lineStartingNumber")];
        if(!fieldValue.is_null())
        {
            setLineStartingNumber(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("orientation")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("orientation")];
        if(!fieldValue.is_null())
        {
            setOrientation(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("otherPagesTray")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("otherPagesTray")];
        if(!fieldValue.is_null())
        {
            setOtherPagesTray(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageHeight")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageHeight")];
        if(!fieldValue.is_null())
        {
            setPageHeight(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageNumberStyle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageNumberStyle")];
        if(!fieldValue.is_null())
        {
            setPageNumberStyle(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageStartingNumber")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageStartingNumber")];
        if(!fieldValue.is_null())
        {
            setPageStartingNumber(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageWidth")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageWidth")];
        if(!fieldValue.is_null())
        {
            setPageWidth(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("paperSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("paperSize")];
        if(!fieldValue.is_null())
        {
            setPaperSize(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("restartPageNumbering")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("restartPageNumbering")];
        if(!fieldValue.is_null())
        {
            setRestartPageNumbering(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("rightMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rightMargin")];
        if(!fieldValue.is_null())
        {
            setRightMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("rtlGutter")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("rtlGutter")];
        if(!fieldValue.is_null())
        {
            setRtlGutter(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("sectionStart")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("sectionStart")];
        if(!fieldValue.is_null())
        {
            setSectionStart(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("suppressEndnotes")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("suppressEndnotes")];
        if(!fieldValue.is_null())
        {
            setSuppressEndnotes(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("topMargin")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("topMargin")];
        if(!fieldValue.is_null())
        {
            setTopMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("verticalAlignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("verticalAlignment")];
        if(!fieldValue.is_null())
        {
            setVerticalAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void PageSetup::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, _XPLATSTR("link."));
        }
        
    }
    if(m_BidiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bidi"), m_Bidi));
    }
    if(m_BorderAlwaysInFrontIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("borderAlwaysInFront"), m_BorderAlwaysInFront));
    }
    if(m_BorderAppliesToIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("borderAppliesTo"), m_BorderAppliesTo));
        
    }
    if(m_BorderDistanceFromIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("borderDistanceFrom"), m_BorderDistanceFrom));
        
    }
    if(m_BottomMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("bottomMargin"), m_BottomMargin));
    }
    if(m_DifferentFirstPageHeaderFooterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("differentFirstPageHeaderFooter"), m_DifferentFirstPageHeaderFooter));
    }
    if(m_FirstPageTrayIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("firstPageTray"), m_FirstPageTray));
    }
    if(m_FooterDistanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("footerDistance"), m_FooterDistance));
    }
    if(m_GutterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("gutter"), m_Gutter));
    }
    if(m_HeaderDistanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("headerDistance"), m_HeaderDistance));
    }
    if(m_LeftMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("leftMargin"), m_LeftMargin));
    }
    if(m_LineNumberCountByIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineNumberCountBy"), m_LineNumberCountBy));
    }
    if(m_LineNumberDistanceFromTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineNumberDistanceFromText"), m_LineNumberDistanceFromText));
    }
    if(m_LineNumberRestartModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineNumberRestartMode"), m_LineNumberRestartMode));
        
    }
    if(m_LineStartingNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("lineStartingNumber"), m_LineStartingNumber));
    }
    if(m_OrientationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("orientation"), m_Orientation));
        
    }
    if(m_OtherPagesTrayIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("otherPagesTray"), m_OtherPagesTray));
    }
    if(m_PageHeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageHeight"), m_PageHeight));
    }
    if(m_PageNumberStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageNumberStyle"), m_PageNumberStyle));
        
    }
    if(m_PageStartingNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageStartingNumber"), m_PageStartingNumber));
    }
    if(m_PageWidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageWidth"), m_PageWidth));
    }
    if(m_PaperSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("paperSize"), m_PaperSize));
        
    }
    if(m_RestartPageNumberingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("restartPageNumbering"), m_RestartPageNumbering));
    }
    if(m_RightMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("rightMargin"), m_RightMargin));
    }
    if(m_RtlGutterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("rtlGutter"), m_RtlGutter));
    }
    if(m_SectionStartIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("sectionStart"), m_SectionStart));
        
    }
    if(m_SuppressEndnotesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("suppressEndnotes"), m_SuppressEndnotes));
    }
    if(m_TopMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("topMargin"), m_TopMargin));
    }
    if(m_VerticalAlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("verticalAlignment"), m_VerticalAlignment));
        
    }
}

void PageSetup::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("link")))
    {
        if(multipart->hasContent(_XPLATSTR("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, _XPLATSTR("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("bidi")))
    {
        setBidi(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("bidi"))));
    }
    if(multipart->hasContent(_XPLATSTR("borderAlwaysInFront")))
    {
        setBorderAlwaysInFront(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("borderAlwaysInFront"))));
    }
    if(multipart->hasContent(_XPLATSTR("borderAppliesTo")))
    {
        setBorderAppliesTo(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("borderAppliesTo"))));
    }
    if(multipart->hasContent(_XPLATSTR("borderDistanceFrom")))
    {
        setBorderDistanceFrom(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("borderDistanceFrom"))));
    }
    if(multipart->hasContent(_XPLATSTR("bottomMargin")))
    {
        setBottomMargin(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("bottomMargin"))));
    }
    if(multipart->hasContent(_XPLATSTR("differentFirstPageHeaderFooter")))
    {
        setDifferentFirstPageHeaderFooter(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("differentFirstPageHeaderFooter"))));
    }
    if(multipart->hasContent(_XPLATSTR("firstPageTray")))
    {
        setFirstPageTray(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("firstPageTray"))));
    }
    if(multipart->hasContent(_XPLATSTR("footerDistance")))
    {
        setFooterDistance(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("footerDistance"))));
    }
    if(multipart->hasContent(_XPLATSTR("gutter")))
    {
        setGutter(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("gutter"))));
    }
    if(multipart->hasContent(_XPLATSTR("headerDistance")))
    {
        setHeaderDistance(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("headerDistance"))));
    }
    if(multipart->hasContent(_XPLATSTR("leftMargin")))
    {
        setLeftMargin(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("leftMargin"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineNumberCountBy")))
    {
        setLineNumberCountBy(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("lineNumberCountBy"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineNumberDistanceFromText")))
    {
        setLineNumberDistanceFromText(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("lineNumberDistanceFromText"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineNumberRestartMode")))
    {
        setLineNumberRestartMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("lineNumberRestartMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("lineStartingNumber")))
    {
        setLineStartingNumber(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("lineStartingNumber"))));
    }
    if(multipart->hasContent(_XPLATSTR("orientation")))
    {
        setOrientation(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("orientation"))));
    }
    if(multipart->hasContent(_XPLATSTR("otherPagesTray")))
    {
        setOtherPagesTray(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("otherPagesTray"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageHeight")))
    {
        setPageHeight(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("pageHeight"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageNumberStyle")))
    {
        setPageNumberStyle(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("pageNumberStyle"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageStartingNumber")))
    {
        setPageStartingNumber(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("pageStartingNumber"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageWidth")))
    {
        setPageWidth(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("pageWidth"))));
    }
    if(multipart->hasContent(_XPLATSTR("paperSize")))
    {
        setPaperSize(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("paperSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("restartPageNumbering")))
    {
        setRestartPageNumbering(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("restartPageNumbering"))));
    }
    if(multipart->hasContent(_XPLATSTR("rightMargin")))
    {
        setRightMargin(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("rightMargin"))));
    }
    if(multipart->hasContent(_XPLATSTR("rtlGutter")))
    {
        setRtlGutter(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("rtlGutter"))));
    }
    if(multipart->hasContent(_XPLATSTR("sectionStart")))
    {
        setSectionStart(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("sectionStart"))));
    }
    if(multipart->hasContent(_XPLATSTR("suppressEndnotes")))
    {
        setSuppressEndnotes(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("suppressEndnotes"))));
    }
    if(multipart->hasContent(_XPLATSTR("topMargin")))
    {
        setTopMargin(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("topMargin"))));
    }
    if(multipart->hasContent(_XPLATSTR("verticalAlignment")))
    {
        setVerticalAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("verticalAlignment"))));
    }
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

