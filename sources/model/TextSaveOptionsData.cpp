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
    m_Encoding = utility::conversions::to_string_t("");
    m_EncodingIsSet = false;
    m_ExportHeadersFooters = false;
    m_ExportHeadersFootersIsSet = false;
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

    if(m_EncodingIsSet)
    {
        val[utility::conversions::to_string_t("Encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportHeadersFootersIsSet)
    {
        val[utility::conversions::to_string_t("ExportHeadersFooters")] = ModelBase::toJson(m_ExportHeadersFooters);
    }
    if(m_ForcePageBreaksIsSet)
    {
        val[utility::conversions::to_string_t("ForcePageBreaks")] = ModelBase::toJson(m_ForcePageBreaks);
    }
    if(m_ParagraphBreakIsSet)
    {
        val[utility::conversions::to_string_t("ParagraphBreak")] = ModelBase::toJson(m_ParagraphBreak);
    }
    if(m_PreserveTableLayoutIsSet)
    {
        val[utility::conversions::to_string_t("PreserveTableLayout")] = ModelBase::toJson(m_PreserveTableLayout);
    }
    if(m_SimplifyListLabelsIsSet)
    {
        val[utility::conversions::to_string_t("SimplifyListLabels")] = ModelBase::toJson(m_SimplifyListLabels);
    }

    return val;
}

void TextSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(utility::conversions::to_string_t("Encoding")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("Encoding")];
        if(!fieldValue.is_null())
        {
            setEncoding(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ExportHeadersFooters")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ExportHeadersFooters")];
        if(!fieldValue.is_null())
        {
            setExportHeadersFooters(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ForcePageBreaks")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ForcePageBreaks")];
        if(!fieldValue.is_null())
        {
            setForcePageBreaks(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("ParagraphBreak")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("ParagraphBreak")];
        if(!fieldValue.is_null())
        {
            setParagraphBreak(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("PreserveTableLayout")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("PreserveTableLayout")];
        if(!fieldValue.is_null())
        {
            setPreserveTableLayout(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(utility::conversions::to_string_t("SimplifyListLabels")))
    {
        web::json::value& fieldValue = val[utility::conversions::to_string_t("SimplifyListLabels")];
        if(!fieldValue.is_null())
        {
            setSimplifyListLabels(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void TextSaveOptionsData::toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix) const
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(m_ColorModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ColorMode"), m_ColorMode));
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SaveFormat"), m_SaveFormat));
        
    }
    if(m_FileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("FileName"), m_FileName));
        
    }
    if(m_DmlRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DmlRenderingMode"), m_DmlRenderingMode));
        
    }
    if(m_DmlEffectsRenderingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("DmlEffectsRenderingMode"), m_DmlEffectsRenderingMode));
        
    }
    if(m_ZipOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ZipOutput"), m_ZipOutput));
    }
    if(m_UpdateLastSavedTimePropertyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateLastSavedTimeProperty"), m_UpdateLastSavedTimeProperty));
    }
    if(m_UpdateSdtContentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateSdtContent"), m_UpdateSdtContent));
    }
    if(m_UpdateFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("UpdateFields"), m_UpdateFields));
    }
    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("Encoding"), m_Encoding));
        
    }
    if(m_ExportHeadersFootersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ExportHeadersFooters"), m_ExportHeadersFooters));
    }
    if(m_ForcePageBreaksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ForcePageBreaks"), m_ForcePageBreaks));
    }
    if(m_ParagraphBreakIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("ParagraphBreak"), m_ParagraphBreak));
        
    }
    if(m_PreserveTableLayoutIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("PreserveTableLayout"), m_PreserveTableLayout));
    }
    if(m_SimplifyListLabelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + utility::conversions::to_string_t("SimplifyListLabels"), m_SimplifyListLabels));
    }
}

void TextSaveOptionsData::fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& prefix)
{
    utility::string_t namePrefix = prefix;
    if(namePrefix.size() > 0 && namePrefix.substr(namePrefix.size() - 1) != utility::conversions::to_string_t("."))
    {
        namePrefix += utility::conversions::to_string_t(".");
    }

    if(multipart->hasContent(utility::conversions::to_string_t("ColorMode")))
    {
        setColorMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ColorMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("SaveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SaveFormat"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("FileName")))
    {
        setFileName(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("FileName"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DmlRenderingMode")))
    {
        setDmlRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DmlRenderingMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("DmlEffectsRenderingMode")))
    {
        setDmlEffectsRenderingMode(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("DmlEffectsRenderingMode"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ZipOutput")))
    {
        setZipOutput(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ZipOutput"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateLastSavedTimeProperty")))
    {
        setUpdateLastSavedTimeProperty(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateLastSavedTimeProperty"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateSdtContent")))
    {
        setUpdateSdtContent(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateSdtContent"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("UpdateFields")))
    {
        setUpdateFields(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("UpdateFields"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("Encoding")))
    {
        setEncoding(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("Encoding"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ExportHeadersFooters")))
    {
        setExportHeadersFooters(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ExportHeadersFooters"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ForcePageBreaks")))
    {
        setForcePageBreaks(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ForcePageBreaks"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("ParagraphBreak")))
    {
        setParagraphBreak(ModelBase::stringFromHttpContent(multipart->getContent(utility::conversions::to_string_t("ParagraphBreak"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("PreserveTableLayout")))
    {
        setPreserveTableLayout(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("PreserveTableLayout"))));
    }
    if(multipart->hasContent(utility::conversions::to_string_t("SimplifyListLabels")))
    {
        setSimplifyListLabels(ModelBase::boolFromHttpContent(multipart->getContent(utility::conversions::to_string_t("SimplifyListLabels"))));
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

