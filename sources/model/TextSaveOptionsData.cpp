/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TextSaveOptionsData.cpp">
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


#include "TextSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

TextSaveOptionsData::TextSaveOptionsData()
{
    m_AddBidiMarks = false;
    m_AddBidiMarksIsSet = false;
    m_Encoding = utility::conversions::to_string_t("");
    m_EncodingIsSet = false;
    m_ExportHeadersFootersMode = utility::conversions::to_string_t("");
    m_ExportHeadersFootersModeIsSet = false;
    m_ForcePageBreaks = false;
    m_ForcePageBreaksIsSet = false;
    m_ParagraphBreak = utility::conversions::to_string_t("");
    m_ParagraphBreakIsSet = false;
    m_PreserveTableLayout = false;
    m_PreserveTableLayoutIsSet = false;
    m_SimplifyListLabels = false;
    m_SimplifyListLabelsIsSet = false;
}

TextSaveOptionsData::~TextSaveOptionsData()
{
}

void TextSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value TextSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_AddBidiMarksIsSet)
    {
        val[_XPLATSTR("AddBidiMarks")] = ModelBase::toJson(m_AddBidiMarks);
    }
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
    if(m_PreserveTableLayoutIsSet)
    {
        val[_XPLATSTR("PreserveTableLayout")] = ModelBase::toJson(m_PreserveTableLayout);
    }
    if(m_SimplifyListLabelsIsSet)
    {
        val[_XPLATSTR("SimplifyListLabels")] = ModelBase::toJson(m_SimplifyListLabels);
    }

    return val;
}

void TextSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("AddBidiMarks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AddBidiMarks")];
        if(!fieldValue.is_null())
        {
            setAddBidiMarks(ModelBase::bool?FromJson(fieldValue));
        }
    }
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
            setExportHeadersFootersMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ForcePageBreaks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ForcePageBreaks")];
        if(!fieldValue.is_null())
        {
            setForcePageBreaks(ModelBase::bool?FromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("PreserveTableLayout")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PreserveTableLayout")];
        if(!fieldValue.is_null())
        {
            setPreserveTableLayout(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SimplifyListLabels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SimplifyListLabels")];
        if(!fieldValue.is_null())
        {
            setSimplifyListLabels(ModelBase::bool?FromJson(fieldValue));
        }
    }
}

void TextSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    SaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_AddBidiMarksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AddBidiMarks"), m_AddBidiMarks));
        
    }
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
    if(m_PreserveTableLayoutIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PreserveTableLayout"), m_PreserveTableLayout));
        
    }
    if(m_SimplifyListLabelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SimplifyListLabels"), m_SimplifyListLabels));
        
    }
}

void TextSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    SaveOptionsData::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("AddBidiMarks")))
    {
        setAddBidiMarks(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("AddBidiMarks"))));
    }
    if(multipart->hasContent(_XPLATSTR("Encoding")))
    {
        setEncoding(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Encoding"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportHeadersFootersMode")))
    {
        setExportHeadersFootersMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ExportHeadersFootersMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("ForcePageBreaks")))
    {
        setForcePageBreaks(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("ForcePageBreaks"))));
    }
    if(multipart->hasContent(_XPLATSTR("ParagraphBreak")))
    {
        setParagraphBreak(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ParagraphBreak"))));
    }
    if(multipart->hasContent(_XPLATSTR("PreserveTableLayout")))
    {
        setPreserveTableLayout(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("PreserveTableLayout"))));
    }
    if(multipart->hasContent(_XPLATSTR("SimplifyListLabels")))
    {
        setSimplifyListLabels(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("SimplifyListLabels"))));
    }
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TextSaveOptionsData::isAddBidiMarks() const
{
    return m_AddBidiMarks;
}


void TextSaveOptionsData::setAddBidiMarks(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_AddBidiMarks = value;
    m_AddBidiMarksIsSet = true;
}
bool TextSaveOptionsData::addBidiMarksIsSet() const
{
    return m_AddBidiMarksIsSet;
}

void TextSaveOptionsData::unsetAddBidiMarks()
{
    m_AddBidiMarksIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TextSaveOptionsData::getEncoding() const
{
    return m_Encoding;
}


void TextSaveOptionsData::setEncoding(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_Encoding = value;
    m_EncodingIsSet = true;
}
bool TextSaveOptionsData::encodingIsSet() const
{
    return m_EncodingIsSet;
}

void TextSaveOptionsData::unsetEncoding()
{
    m_EncodingIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TextSaveOptionsData::getExportHeadersFootersMode() const
{
    return m_ExportHeadersFootersMode;
}


void TextSaveOptionsData::setExportHeadersFootersMode(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_ExportHeadersFootersMode = value;
    m_ExportHeadersFootersModeIsSet = true;
}
bool TextSaveOptionsData::exportHeadersFootersModeIsSet() const
{
    return m_ExportHeadersFootersModeIsSet;
}

void TextSaveOptionsData::unsetExportHeadersFootersMode()
{
    m_ExportHeadersFootersModeIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TextSaveOptionsData::isForcePageBreaks() const
{
    return m_ForcePageBreaks;
}


void TextSaveOptionsData::setForcePageBreaks(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_ForcePageBreaks = value;
    m_ForcePageBreaksIsSet = true;
}
bool TextSaveOptionsData::forcePageBreaksIsSet() const
{
    return m_ForcePageBreaksIsSet;
}

void TextSaveOptionsData::unsetForcePageBreaks()
{
    m_ForcePageBreaksIsSet = false;
}

<DATA_TYPE_START>string<DATA_TYPE_END> TextSaveOptionsData::getParagraphBreak() const
{
    return m_ParagraphBreak;
}


void TextSaveOptionsData::setParagraphBreak(<DATA_TYPE_START>string<DATA_TYPE_END> value)
{
    m_ParagraphBreak = value;
    m_ParagraphBreakIsSet = true;
}
bool TextSaveOptionsData::paragraphBreakIsSet() const
{
    return m_ParagraphBreakIsSet;
}

void TextSaveOptionsData::unsetParagraphBreak()
{
    m_ParagraphBreakIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TextSaveOptionsData::isPreserveTableLayout() const
{
    return m_PreserveTableLayout;
}


void TextSaveOptionsData::setPreserveTableLayout(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_PreserveTableLayout = value;
    m_PreserveTableLayoutIsSet = true;
}
bool TextSaveOptionsData::preserveTableLayoutIsSet() const
{
    return m_PreserveTableLayoutIsSet;
}

void TextSaveOptionsData::unsetPreserveTableLayout()
{
    m_PreserveTableLayoutIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> TextSaveOptionsData::isSimplifyListLabels() const
{
    return m_SimplifyListLabels;
}


void TextSaveOptionsData::setSimplifyListLabels(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_SimplifyListLabels = value;
    m_SimplifyListLabelsIsSet = true;
}
bool TextSaveOptionsData::simplifyListLabelsIsSet() const
{
    return m_SimplifyListLabelsIsSet;
}

void TextSaveOptionsData::unsetSimplifyListLabels()
{
    m_SimplifyListLabelsIsSet = false;
}

}
}
}
}
}

