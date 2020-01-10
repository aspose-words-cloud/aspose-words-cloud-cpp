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
        val[_XPLATSTR("addBidiMarks")] = ModelBase::toJson(m_AddBidiMarks);
    }
    if(m_EncodingIsSet)
    {
        val[_XPLATSTR("encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportHeadersFootersModeIsSet)
    {
        val[_XPLATSTR("exportHeadersFootersMode")] = ModelBase::toJson(m_ExportHeadersFootersMode);
    }
    if(m_ForcePageBreaksIsSet)
    {
        val[_XPLATSTR("forcePageBreaks")] = ModelBase::toJson(m_ForcePageBreaks);
    }
    if(m_ParagraphBreakIsSet)
    {
        val[_XPLATSTR("paragraphBreak")] = ModelBase::toJson(m_ParagraphBreak);
    }
    if(m_PreserveTableLayoutIsSet)
    {
        val[_XPLATSTR("preserveTableLayout")] = ModelBase::toJson(m_PreserveTableLayout);
    }
    if(m_SimplifyListLabelsIsSet)
    {
        val[_XPLATSTR("simplifyListLabels")] = ModelBase::toJson(m_SimplifyListLabels);
    }

    return val;
}

void TextSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("addBidiMarks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("addBidiMarks")];
        if(!fieldValue.is_null())
        {
            setAddBidiMarks(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("encoding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("encoding")];
        if(!fieldValue.is_null())
        {
            setEncoding(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportHeadersFootersMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportHeadersFootersMode")];
        if(!fieldValue.is_null())
        {
            setExportHeadersFootersMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("forcePageBreaks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("forcePageBreaks")];
        if(!fieldValue.is_null())
        {
            setForcePageBreaks(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("paragraphBreak")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("paragraphBreak")];
        if(!fieldValue.is_null())
        {
            setParagraphBreak(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("preserveTableLayout")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("preserveTableLayout")];
        if(!fieldValue.is_null())
        {
            setPreserveTableLayout(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("simplifyListLabels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("simplifyListLabels")];
        if(!fieldValue.is_null())
        {
            setSimplifyListLabels(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void TextSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_ColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("colorMode"), m_ColorMode));
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("saveFormat"), m_SaveFormat));
        
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fileName"), m_FileName));
        
    }
    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dmlRenderingMode"), m_DmlRenderingMode));
        
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("dmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
        
    }
    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("zipOutput"), m_ZipOutput));
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("updateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }
    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("updateSdtContent"), m_UpdateSdtContent));
    }
    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("updateFields"), m_UpdateFields));
    }
    if(m_AddBidiMarksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("addBidiMarks"), m_AddBidiMarks));
    }
    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("encoding"), m_Encoding));
        
    }
    if(m_ExportHeadersFootersModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportHeadersFootersMode"), m_ExportHeadersFootersMode));
        
    }
    if(m_ForcePageBreaksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("forcePageBreaks"), m_ForcePageBreaks));
    }
    if(m_ParagraphBreakIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("paragraphBreak"), m_ParagraphBreak));
        
    }
    if(m_PreserveTableLayoutIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("preserveTableLayout"), m_PreserveTableLayout));
    }
    if(m_SimplifyListLabelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("simplifyListLabels"), m_SimplifyListLabels));
    }
}

void TextSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("colorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("colorMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("saveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("saveFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("fileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fileName"))));
    }
    if(multipart->hasContent(_XPLATSTR("dmlRenderingMode")))
    {
        setDmlRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("dmlRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("dmlEffectsRenderingMode")))
    {
        setDmlEffectsRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("dmlEffectsRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("zipOutput")))
    {
        setZipOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("zipOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("updateLastSavedTimeProperty")))
    {
        setUpdateLastSavedTimeProperty(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("updateLastSavedTimeProperty"))));
    }
    if(multipart->hasContent(_XPLATSTR("updateSdtContent")))
    {
        setUpdateSdtContent(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("updateSdtContent"))));
    }
    if(multipart->hasContent(_XPLATSTR("updateFields")))
    {
        setUpdateFields(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("updateFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("addBidiMarks")))
    {
        setAddBidiMarks(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("addBidiMarks"))));
    }
    if(multipart->hasContent(_XPLATSTR("encoding")))
    {
        setEncoding(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("encoding"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportHeadersFootersMode")))
    {
        setExportHeadersFootersMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("exportHeadersFootersMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("forcePageBreaks")))
    {
        setForcePageBreaks(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("forcePageBreaks"))));
    }
    if(multipart->hasContent(_XPLATSTR("paragraphBreak")))
    {
        setParagraphBreak(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("paragraphBreak"))));
    }
    if(multipart->hasContent(_XPLATSTR("preserveTableLayout")))
    {
        setPreserveTableLayout(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("preserveTableLayout"))));
    }
    if(multipart->hasContent(_XPLATSTR("simplifyListLabels")))
    {
        setSimplifyListLabels(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("simplifyListLabels"))));
    }
}

bool TextSaveOptionsData::isAddBidiMarks() const
{
    return m_AddBidiMarks;
}


void TextSaveOptionsData::setAddBidiMarks(bool value)
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

utility::string_t TextSaveOptionsData::getEncoding() const
{
    return m_Encoding;
}


void TextSaveOptionsData::setEncoding(utility::string_t value)
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

utility::string_t TextSaveOptionsData::getExportHeadersFootersMode() const
{
    return m_ExportHeadersFootersMode;
}


void TextSaveOptionsData::setExportHeadersFootersMode(utility::string_t value)
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

bool TextSaveOptionsData::isForcePageBreaks() const
{
    return m_ForcePageBreaks;
}


void TextSaveOptionsData::setForcePageBreaks(bool value)
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

utility::string_t TextSaveOptionsData::getParagraphBreak() const
{
    return m_ParagraphBreak;
}


void TextSaveOptionsData::setParagraphBreak(utility::string_t value)
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

bool TextSaveOptionsData::isPreserveTableLayout() const
{
    return m_PreserveTableLayout;
}


void TextSaveOptionsData::setPreserveTableLayout(bool value)
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

bool TextSaveOptionsData::isSimplifyListLabels() const
{
    return m_SimplifyListLabels;
}


void TextSaveOptionsData::setSimplifyListLabels(bool value)
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

