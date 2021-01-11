/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TxtSaveOptionsBaseData.cpp">
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

#include "TxtSaveOptionsBaseData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TxtSaveOptionsBaseData::TxtSaveOptionsBaseData()
{
    m_Encoding = utility::conversions::to_string_t("");
    m_EncodingIsSet = false;

    m_ExportHeadersFootersModeIsSet = false;
    m_ForcePageBreaks = false;
    m_ForcePageBreaksIsSet = false;
    m_ParagraphBreak = utility::conversions::to_string_t("");
    m_ParagraphBreakIsSet = false;

}

TxtSaveOptionsBaseData::~TxtSaveOptionsBaseData()
{
}

void TxtSaveOptionsBaseData::validate()
{
    // TODO: implement validation
}

web::json::value TxtSaveOptionsBaseData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();
    if(m_EncodingIsSet)
    {
        val[_XPLATSTR("Encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportHeadersFootersModeIsSet)
    {
        val[_XPLATSTR("ExportHeadersFootersMode")] = ModelBase::toJson(m_ExportHeadersFootersMode);
    }
    if(m_ForcePageBreaksIsSet)
    {
        val[_XPLATSTR("ForcePageBreaks")] = ModelBase::toJson(m_ForcePageBreaks);
    }
    if(m_ParagraphBreakIsSet)
    {
        val[_XPLATSTR("ParagraphBreak")] = ModelBase::toJson(m_ParagraphBreak);
    }

    return val;
}

void TxtSaveOptionsBaseData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("Encoding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Encoding")];
        if(!fieldValue.is_null())
        {
           setEncoding(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ExportHeadersFootersMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportHeadersFootersMode")];
        if(!fieldValue.is_null())
        {
           setExportHeadersFootersMode(ModelBase::enumFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ForcePageBreaks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ForcePageBreaks")];
        if(!fieldValue.is_null())
        {
           setForcePageBreaks(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ParagraphBreak")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ParagraphBreak")];
        if(!fieldValue.is_null())
        {
           setParagraphBreak(ModelBase::stringFromJson(fieldValue));
        }
    }

}

void TxtSaveOptionsBaseData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    SaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Encoding"), m_Encoding));
    }


    if(m_ExportHeadersFootersModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportHeadersFootersMode"), m_ExportHeadersFootersMode));
    }


    if(m_ForcePageBreaksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ForcePageBreaks"), m_ForcePageBreaks));
    }


    if(m_ParagraphBreakIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ParagraphBreak"), m_ParagraphBreak));
    }

}

void TxtSaveOptionsBaseData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t TxtSaveOptionsBaseData::getEncoding() const
{
    return m_Encoding;
}


void TxtSaveOptionsBaseData::setEncoding(utility::string_t value)
{
    m_Encoding = value;
    m_EncodingIsSet = true;
}

bool TxtSaveOptionsBaseData::encodingIsSet() const
{
    return m_EncodingIsSet;
}

void TxtSaveOptionsBaseData::unsetEncoding()
{
    m_EncodingIsSet = false;
}

utility::string_t TxtSaveOptionsBaseData::getExportHeadersFootersMode() const
{
    return m_ExportHeadersFootersMode;
}


void TxtSaveOptionsBaseData::setExportHeadersFootersMode(utility::string_t value)
{
    m_ExportHeadersFootersMode = value;
    m_ExportHeadersFootersModeIsSet = true;
}

bool TxtSaveOptionsBaseData::exportHeadersFootersModeIsSet() const
{
    return m_ExportHeadersFootersModeIsSet;
}

void TxtSaveOptionsBaseData::unsetExportHeadersFootersMode()
{
    m_ExportHeadersFootersModeIsSet = false;
}

bool TxtSaveOptionsBaseData::isForcePageBreaks() const
{
    return m_ForcePageBreaks;
}


void TxtSaveOptionsBaseData::setForcePageBreaks(bool value)
{
    m_ForcePageBreaks = value;
    m_ForcePageBreaksIsSet = true;
}

bool TxtSaveOptionsBaseData::forcePageBreaksIsSet() const
{
    return m_ForcePageBreaksIsSet;
}

void TxtSaveOptionsBaseData::unsetForcePageBreaks()
{
    m_ForcePageBreaksIsSet = false;
}

utility::string_t TxtSaveOptionsBaseData::getParagraphBreak() const
{
    return m_ParagraphBreak;
}


void TxtSaveOptionsBaseData::setParagraphBreak(utility::string_t value)
{
    m_ParagraphBreak = value;
    m_ParagraphBreakIsSet = true;
}

bool TxtSaveOptionsBaseData::paragraphBreakIsSet() const
{
    return m_ParagraphBreakIsSet;
}

void TxtSaveOptionsBaseData::unsetParagraphBreak()
{
    m_ParagraphBreakIsSet = false;
}

}
}
}
}
}
