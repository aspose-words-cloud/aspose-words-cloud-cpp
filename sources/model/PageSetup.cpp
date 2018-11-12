/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PageSetup.cpp">
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


#include "PageSetup.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
        val[utility::conversions::to_string_t("Bidi")] = ModelBase::toJson(m_Bidi);
    }
    if(m_BorderAlwaysInFrontIsSet)
    {
        val[utility::conversions::to_string_t("BorderAlwaysInFront")] = ModelBase::toJson(m_BorderAlwaysInFront);
    }
    if(m_BorderAppliesToIsSet)
    {
        val[utility::conversions::to_string_t("BorderAppliesTo")] = ModelBase::toJson(m_BorderAppliesTo);
    }
    if(m_BorderDistanceFromIsSet)
    {
        val[utility::conversions::to_string_t("BorderDistanceFrom")] = ModelBase::toJson(m_BorderDistanceFrom);
    }
    if(m_BottomMarginIsSet)
    {
        val[utility::conversions::to_string_t("BottomMargin")] = ModelBase::toJson(m_BottomMargin);
    }
    if(m_DifferentFirstPageHeaderFooterIsSet)
    {
        val[utility::conversions::to_string_t("DifferentFirstPageHeaderFooter")] = ModelBase::toJson(m_DifferentFirstPageHeaderFooter);
    }
    if(m_FirstPageTrayIsSet)
    {
        val[utility::conversions::to_string_t("FirstPageTray")] = ModelBase::toJson(m_FirstPageTray);
    }
    if(m_FooterDistanceIsSet)
    {
        val[utility::conversions::to_string_t("FooterDistance")] = ModelBase::toJson(m_FooterDistance);
    }
    if(m_GutterIsSet)
    {
        val[utility::conversions::to_string_t("Gutter")] = ModelBase::toJson(m_Gutter);
    }
    if(m_HeaderDistanceIsSet)
    {
        val[utility::conversions::to_string_t("HeaderDistance")] = ModelBase::toJson(m_HeaderDistance);
    }
    if(m_LeftMarginIsSet)
    {
        val[utility::conversions::to_string_t("LeftMargin")] = ModelBase::toJson(m_LeftMargin);
    }
    if(m_LineNumberCountByIsSet)
    {
        val[utility::conversions::to_string_t("LineNumberCountBy")] = ModelBase::toJson(m_LineNumberCountBy);
    }
    if(m_LineNumberDistanceFromTextIsSet)
    {
        val[utility::conversions::to_string_t("LineNumberDistanceFromText")] = ModelBase::toJson(m_LineNumberDistanceFromText);
    }
    if(m_LineNumberRestartModeIsSet)
    {
        val[utility::conversions::to_string_t("LineNumberRestartMode")] = ModelBase::toJson(m_LineNumberRestartMode);
    }
    if(m_LineStartingNumberIsSet)
    {
        val[utility::conversions::to_string_t("LineStartingNumber")] = ModelBase::toJson(m_LineStartingNumber);
    }
    if(m_OrientationIsSet)
    {
        val[utility::conversions::to_string_t("Orientation")] = ModelBase::toJson(m_Orientation);
    }
    if(m_OtherPagesTrayIsSet)
    {
        val[utility::conversions::to_string_t("OtherPagesTray")] = ModelBase::toJson(m_OtherPagesTray);
    }
    if(m_PageHeightIsSet)
    {
        val[utility::conversions::to_string_t("PageHeight")] = ModelBase::toJson(m_PageHeight);
    }
    if(m_PageNumberStyleIsSet)
    {
        val[utility::conversions::to_string_t("PageNumberStyle")] = ModelBase::toJson(m_PageNumberStyle);
    }
    if(m_PageStartingNumberIsSet)
    {
        val[utility::conversions::to_string_t("PageStartingNumber")] = ModelBase::toJson(m_PageStartingNumber);
    }
    if(m_PageWidthIsSet)
    {
        val[utility::conversions::to_string_t("PageWidth")] = ModelBase::toJson(m_PageWidth);
    }
    if(m_PaperSizeIsSet)
    {
        val[utility::conversions::to_string_t("PaperSize")] = ModelBase::toJson(m_PaperSize);
    }
    if(m_RestartPageNumberingIsSet)
    {
        val[utility::conversions::to_string_t("RestartPageNumbering")] = ModelBase::toJson(m_RestartPageNumbering);
    }
    if(m_RightMarginIsSet)
    {
        val[utility::conversions::to_string_t("RightMargin")] = ModelBase::toJson(m_RightMargin);
    }
    if(m_RtlGutterIsSet)
    {
        val[utility::conversions::to_string_t("RtlGutter")] = ModelBase::toJson(m_RtlGutter);
    }
    if(m_SectionStartIsSet)
    {
        val[utility::conversions::to_string_t("SectionStart")] = ModelBase::toJson(m_SectionStart);
    }
    if(m_SuppressEndnotesIsSet)
    {
        val[utility::conversions::to_string_t("SuppressEndnotes")] = ModelBase::toJson(m_SuppressEndnotes);
    }
    if(m_TopMarginIsSet)
    {
        val[utility::conversions::to_string_t("TopMargin")] = ModelBase::toJson(m_TopMargin);
    }
    if(m_VerticalAlignmentIsSet)
    {
        val[utility::conversions::to_string_t("VerticalAlignment")] = ModelBase::toJson(m_VerticalAlignment);
    }

    return val;
}

void PageSetup::fromJson(web::json::value& val)
{
    this->LinkElement::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("Bidi")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Bidi")];
        if(!fieldValue.is_null())
        {
            setBidi(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("BorderAlwaysInFront")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("BorderAlwaysInFront")];
        if(!fieldValue.is_null())
        {
            setBorderAlwaysInFront(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("BorderAppliesTo")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("BorderAppliesTo")];
        if(!fieldValue.is_null())
        {
            setBorderAppliesTo(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("BorderDistanceFrom")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("BorderDistanceFrom")];
        if(!fieldValue.is_null())
        {
            setBorderDistanceFrom(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("BottomMargin")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("BottomMargin")];
        if(!fieldValue.is_null())
        {
            setBottomMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("DifferentFirstPageHeaderFooter")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("DifferentFirstPageHeaderFooter")];
        if(!fieldValue.is_null())
        {
            setDifferentFirstPageHeaderFooter(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("FirstPageTray")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FirstPageTray")];
        if(!fieldValue.is_null())
        {
            setFirstPageTray(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("FooterDistance")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("FooterDistance")];
        if(!fieldValue.is_null())
        {
            setFooterDistance(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Gutter")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Gutter")];
        if(!fieldValue.is_null())
        {
            setGutter(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("HeaderDistance")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("HeaderDistance")];
        if(!fieldValue.is_null())
        {
            setHeaderDistance(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("LeftMargin")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("LeftMargin")];
        if(!fieldValue.is_null())
        {
            setLeftMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("LineNumberCountBy")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("LineNumberCountBy")];
        if(!fieldValue.is_null())
        {
            setLineNumberCountBy(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("LineNumberDistanceFromText")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("LineNumberDistanceFromText")];
        if(!fieldValue.is_null())
        {
            setLineNumberDistanceFromText(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("LineNumberRestartMode")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("LineNumberRestartMode")];
        if(!fieldValue.is_null())
        {
            setLineNumberRestartMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("LineStartingNumber")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("LineStartingNumber")];
        if(!fieldValue.is_null())
        {
            setLineStartingNumber(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("Orientation")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Orientation")];
        if(!fieldValue.is_null())
        {
            setOrientation(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("OtherPagesTray")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("OtherPagesTray")];
        if(!fieldValue.is_null())
        {
            setOtherPagesTray(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PageHeight")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PageHeight")];
        if(!fieldValue.is_null())
        {
            setPageHeight(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PageNumberStyle")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PageNumberStyle")];
        if(!fieldValue.is_null())
        {
            setPageNumberStyle(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PageStartingNumber")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PageStartingNumber")];
        if(!fieldValue.is_null())
        {
            setPageStartingNumber(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PageWidth")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PageWidth")];
        if(!fieldValue.is_null())
        {
            setPageWidth(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PaperSize")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PaperSize")];
        if(!fieldValue.is_null())
        {
            setPaperSize(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("RestartPageNumbering")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("RestartPageNumbering")];
        if(!fieldValue.is_null())
        {
            setRestartPageNumbering(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("RightMargin")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("RightMargin")];
        if(!fieldValue.is_null())
        {
            setRightMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("RtlGutter")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("RtlGutter")];
        if(!fieldValue.is_null())
        {
            setRtlGutter(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("SectionStart")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("SectionStart")];
        if(!fieldValue.is_null())
        {
            setSectionStart(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("SuppressEndnotes")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("SuppressEndnotes")];
        if(!fieldValue.is_null())
        {
            setSuppressEndnotes(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("TopMargin")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("TopMargin")];
        if(!fieldValue.is_null())
        {
            setTopMargin(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("VerticalAlignment")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("VerticalAlignment")];
        if(!fieldValue.is_null())
        {
            setVerticalAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void PageSetup::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_LinkIsSet)
    {
        if (m_Link.get())
        {
            m_Link->toMultipart(multipart, utility::conversions::to_string_t("link."));
        }
        
    }
    if(m_BidiIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Bidi"), m_Bidi));
    }
    if(m_BorderAlwaysInFrontIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("BorderAlwaysInFront"), m_BorderAlwaysInFront));
    }
    if(m_BorderAppliesToIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("BorderAppliesTo"), m_BorderAppliesTo));
        
    }
    if(m_BorderDistanceFromIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("BorderDistanceFrom"), m_BorderDistanceFrom));
        
    }
    if(m_BottomMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("BottomMargin"), m_BottomMargin));
    }
    if(m_DifferentFirstPageHeaderFooterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DifferentFirstPageHeaderFooter"), m_DifferentFirstPageHeaderFooter));
    }
    if(m_FirstPageTrayIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FirstPageTray"), m_FirstPageTray));
    }
    if(m_FooterDistanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FooterDistance"), m_FooterDistance));
    }
    if(m_GutterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Gutter"), m_Gutter));
    }
    if(m_HeaderDistanceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("HeaderDistance"), m_HeaderDistance));
    }
    if(m_LeftMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("LeftMargin"), m_LeftMargin));
    }
    if(m_LineNumberCountByIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("LineNumberCountBy"), m_LineNumberCountBy));
    }
    if(m_LineNumberDistanceFromTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("LineNumberDistanceFromText"), m_LineNumberDistanceFromText));
    }
    if(m_LineNumberRestartModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("LineNumberRestartMode"), m_LineNumberRestartMode));
        
    }
    if(m_LineStartingNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("LineStartingNumber"), m_LineStartingNumber));
    }
    if(m_OrientationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Orientation"), m_Orientation));
        
    }
    if(m_OtherPagesTrayIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("OtherPagesTray"), m_OtherPagesTray));
    }
    if(m_PageHeightIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageHeight"), m_PageHeight));
    }
    if(m_PageNumberStyleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageNumberStyle"), m_PageNumberStyle));
        
    }
    if(m_PageStartingNumberIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageStartingNumber"), m_PageStartingNumber));
    }
    if(m_PageWidthIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PageWidth"), m_PageWidth));
    }
    if(m_PaperSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PaperSize"), m_PaperSize));
        
    }
    if(m_RestartPageNumberingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RestartPageNumbering"), m_RestartPageNumbering));
    }
    if(m_RightMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RightMargin"), m_RightMargin));
    }
    if(m_RtlGutterIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("RtlGutter"), m_RtlGutter));
    }
    if(m_SectionStartIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SectionStart"), m_SectionStart));
        
    }
    if(m_SuppressEndnotesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SuppressEndnotes"), m_SuppressEndnotes));
    }
    if(m_TopMarginIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("TopMargin"), m_TopMargin));
    }
    if(m_VerticalAlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("VerticalAlignment"), m_VerticalAlignment));
        
    }
}

void PageSetup::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("link")))
    {
        if(multipart->hasContent(utility::conversions::to_string_t("link")))
        {
            std::shared_ptr<WordsApiLink> newItem(new WordsApiLink());
            newItem->fromMultiPart(multipart, utility::conversions::to_string_t("link."));
            setLink( newItem );
        }
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Bidi")))
    {
        setBidi(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Bidi"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("BorderAlwaysInFront")))
    {
        setBorderAlwaysInFront(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("BorderAlwaysInFront"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("BorderAppliesTo")))
    {
        setBorderAppliesTo(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("BorderAppliesTo"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("BorderDistanceFrom")))
    {
        setBorderDistanceFrom(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("BorderDistanceFrom"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("BottomMargin")))
    {
        setBottomMargin(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("BottomMargin"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DifferentFirstPageHeaderFooter")))
    {
        setDifferentFirstPageHeaderFooter(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DifferentFirstPageHeaderFooter"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FirstPageTray")))
    {
        setFirstPageTray(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FirstPageTray"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FooterDistance")))
    {
        setFooterDistance(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FooterDistance"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Gutter")))
    {
        setGutter(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Gutter"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("HeaderDistance")))
    {
        setHeaderDistance(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("HeaderDistance"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("LeftMargin")))
    {
        setLeftMargin(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("LeftMargin"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("LineNumberCountBy")))
    {
        setLineNumberCountBy(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("LineNumberCountBy"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("LineNumberDistanceFromText")))
    {
        setLineNumberDistanceFromText(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("LineNumberDistanceFromText"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("LineNumberRestartMode")))
    {
        setLineNumberRestartMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("LineNumberRestartMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("LineStartingNumber")))
    {
        setLineStartingNumber(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("LineStartingNumber"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Orientation")))
    {
        setOrientation(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Orientation"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("OtherPagesTray")))
    {
        setOtherPagesTray(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("OtherPagesTray"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PageHeight")))
    {
        setPageHeight(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageHeight"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PageNumberStyle")))
    {
        setPageNumberStyle(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageNumberStyle"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PageStartingNumber")))
    {
        setPageStartingNumber(ModelBase::int32_tFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageStartingNumber"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PageWidth")))
    {
        setPageWidth(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PageWidth"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PaperSize")))
    {
        setPaperSize(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PaperSize"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("RestartPageNumbering")))
    {
        setRestartPageNumbering(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RestartPageNumbering"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("RightMargin")))
    {
        setRightMargin(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RightMargin"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("RtlGutter")))
    {
        setRtlGutter(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("RtlGutter"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("SectionStart")))
    {
        setSectionStart(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SectionStart"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("SuppressEndnotes")))
    {
        setSuppressEndnotes(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SuppressEndnotes"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("TopMargin")))
    {
        setTopMargin(ModelBase::doubleFromHttpContent(multipart->getContent(utility::conversions::to_string_t("TopMargin"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("VerticalAlignment")))
    {
        setVerticalAlignment(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("VerticalAlignment"))));
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

