/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TextSaveOptionsData.cpp">
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


#include "TextSaveOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

TextSaveOptionsData::TextSaveOptionsData()
{
    m_Encoding = _XPLATSTR("");
    m_EncodingIsSet = false;
    m_ExportHeadersFooters = false;
    m_ExportHeadersFootersIsSet = false;
    m_ForcePageBreaks = false;
    m_ForcePageBreaksIsSet = false;
    m_ParagraphBreak = _XPLATSTR("");
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

    if(m_EncodingIsSet)
    {
        val[_XPLATSTR("Encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportHeadersFootersIsSet)
    {
        val[_XPLATSTR("ExportHeadersFooters")] = ModelBase::toJson(m_ExportHeadersFooters);
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

    if(val.has_field(_XPLATSTR("Encoding")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Encoding")];
        if(!fieldValue.is_null())
        {
            setEncoding(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportHeadersFooters")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportHeadersFooters")];
        if(!fieldValue.is_null())
        {
            setExportHeadersFooters(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ForcePageBreaks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ForcePageBreaks")];
        if(!fieldValue.is_null())
        {
            setForcePageBreaks(ModelBase::boolFromJson(fieldValue));
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
            setPreserveTableLayout(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("SimplifyListLabels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SimplifyListLabels")];
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
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ColorMode"), m_ColorMode));
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SaveFormat"), m_SaveFormat));
        
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FileName"), m_FileName));
        
    }
    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DmlRenderingMode"), m_DmlRenderingMode));
        
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
        
    }
    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ZipOutput"), m_ZipOutput));
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }
    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateSdtContent"), m_UpdateSdtContent));
    }
    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UpdateFields"), m_UpdateFields));
    }
    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Encoding"), m_Encoding));
        
    }
    if(m_ExportHeadersFootersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportHeadersFooters"), m_ExportHeadersFooters));
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
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(multipart->hasContent(_XPLATSTR("ColorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ColorMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("SaveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("SaveFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("FileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FileName"))));
    }
    if(multipart->hasContent(_XPLATSTR("DmlRenderingMode")))
    {
        setDmlRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DmlRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("DmlEffectsRenderingMode")))
    {
        setDmlEffectsRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DmlEffectsRenderingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("ZipOutput")))
    {
        setZipOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ZipOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("UpdateLastSavedTimeProperty")))
    {
        setUpdateLastSavedTimeProperty(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UpdateLastSavedTimeProperty"))));
    }
    if(multipart->hasContent(_XPLATSTR("UpdateSdtContent")))
    {
        setUpdateSdtContent(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UpdateSdtContent"))));
    }
    if(multipart->hasContent(_XPLATSTR("UpdateFields")))
    {
        setUpdateFields(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UpdateFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("Encoding")))
    {
        setEncoding(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Encoding"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportHeadersFooters")))
    {
        setExportHeadersFooters(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportHeadersFooters"))));
    }
    if(multipart->hasContent(_XPLATSTR("ForcePageBreaks")))
    {
        setForcePageBreaks(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ForcePageBreaks"))));
    }
    if(multipart->hasContent(_XPLATSTR("ParagraphBreak")))
    {
        setParagraphBreak(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ParagraphBreak"))));
    }
    if(multipart->hasContent(_XPLATSTR("PreserveTableLayout")))
    {
        setPreserveTableLayout(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("PreserveTableLayout"))));
    }
    if(multipart->hasContent(_XPLATSTR("SimplifyListLabels")))
    {
        setSimplifyListLabels(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("SimplifyListLabels"))));
    }
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

bool TextSaveOptionsData::isExportHeadersFooters() const
{
    return m_ExportHeadersFooters;
}


void TextSaveOptionsData::setExportHeadersFooters(bool value)
{
    m_ExportHeadersFooters = value;
    m_ExportHeadersFootersIsSet = true;
}
bool TextSaveOptionsData::exportHeadersFootersIsSet() const
{
    return m_ExportHeadersFootersIsSet;
}

void TextSaveOptionsData::unsetExportHeadersFooters()
{
    m_ExportHeadersFootersIsSet = false;
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

