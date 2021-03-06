/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HtmlFixedSaveOptionsData.cpp">
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

#include "HtmlFixedSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

HtmlFixedSaveOptionsData::HtmlFixedSaveOptionsData()
{
    m_CssClassNamesPrefix = utility::conversions::to_string_t("");
    m_CssClassNamesPrefixIsSet = false;
    m_Encoding = utility::conversions::to_string_t("");
    m_EncodingIsSet = false;
    m_ExportEmbeddedCss = false;
    m_ExportEmbeddedCssIsSet = false;
    m_ExportEmbeddedFonts = false;
    m_ExportEmbeddedFontsIsSet = false;
    m_ExportEmbeddedImages = false;
    m_ExportEmbeddedImagesIsSet = false;
    m_ExportFormFields = false;
    m_ExportFormFieldsIsSet = false;
    m_FontFormat = utility::conversions::to_string_t("");
    m_FontFormatIsSet = false;
    m_PageHorizontalAlignment = utility::conversions::to_string_t("");
    m_PageHorizontalAlignmentIsSet = false;
    m_PageMargins = 0.0;
    m_PageMarginsIsSet = false;
    m_ResourcesFolder = utility::conversions::to_string_t("");
    m_ResourcesFolderIsSet = false;
    m_ResourcesFolderAlias = utility::conversions::to_string_t("");
    m_ResourcesFolderAliasIsSet = false;
    m_SaveFontFaceCssSeparately = false;
    m_SaveFontFaceCssSeparatelyIsSet = false;
    m_ShowPageBorder = false;
    m_ShowPageBorderIsSet = false;
    m_UseTargetMachineFonts = false;
    m_UseTargetMachineFontsIsSet = false;

}

HtmlFixedSaveOptionsData::~HtmlFixedSaveOptionsData()
{
}

void HtmlFixedSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value HtmlFixedSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();
    if(m_CssClassNamesPrefixIsSet)
    {
        val[_XPLATSTR("CssClassNamesPrefix")] = ModelBase::toJson(m_CssClassNamesPrefix);
    }
    if(m_EncodingIsSet)
    {
        val[_XPLATSTR("Encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportEmbeddedCssIsSet)
    {
        val[_XPLATSTR("ExportEmbeddedCss")] = ModelBase::toJson(m_ExportEmbeddedCss);
    }
    if(m_ExportEmbeddedFontsIsSet)
    {
        val[_XPLATSTR("ExportEmbeddedFonts")] = ModelBase::toJson(m_ExportEmbeddedFonts);
    }
    if(m_ExportEmbeddedImagesIsSet)
    {
        val[_XPLATSTR("ExportEmbeddedImages")] = ModelBase::toJson(m_ExportEmbeddedImages);
    }
    if(m_ExportFormFieldsIsSet)
    {
        val[_XPLATSTR("ExportFormFields")] = ModelBase::toJson(m_ExportFormFields);
    }
    if(m_FontFormatIsSet)
    {
        val[_XPLATSTR("FontFormat")] = ModelBase::toJson(m_FontFormat);
    }
    if(m_PageHorizontalAlignmentIsSet)
    {
        val[_XPLATSTR("PageHorizontalAlignment")] = ModelBase::toJson(m_PageHorizontalAlignment);
    }
    if(m_PageMarginsIsSet)
    {
        val[_XPLATSTR("PageMargins")] = ModelBase::toJson(m_PageMargins);
    }
    if(m_ResourcesFolderIsSet)
    {
        val[_XPLATSTR("ResourcesFolder")] = ModelBase::toJson(m_ResourcesFolder);
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        val[_XPLATSTR("ResourcesFolderAlias")] = ModelBase::toJson(m_ResourcesFolderAlias);
    }
    if(m_SaveFontFaceCssSeparatelyIsSet)
    {
        val[_XPLATSTR("SaveFontFaceCssSeparately")] = ModelBase::toJson(m_SaveFontFaceCssSeparately);
    }
    if(m_ShowPageBorderIsSet)
    {
        val[_XPLATSTR("ShowPageBorder")] = ModelBase::toJson(m_ShowPageBorder);
    }
    if(m_UseTargetMachineFontsIsSet)
    {
        val[_XPLATSTR("UseTargetMachineFonts")] = ModelBase::toJson(m_UseTargetMachineFonts);
    }

    return val;
}

void HtmlFixedSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("CssClassNamesPrefix")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CssClassNamesPrefix")];
        if(!fieldValue.is_null())
        {
           setCssClassNamesPrefix(ModelBase::stringFromJson(fieldValue));
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


    if(val.has_field(_XPLATSTR("ExportEmbeddedCss")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportEmbeddedCss")];
        if(!fieldValue.is_null())
        {
           setExportEmbeddedCss(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ExportEmbeddedFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportEmbeddedFonts")];
        if(!fieldValue.is_null())
        {
           setExportEmbeddedFonts(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ExportEmbeddedImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportEmbeddedImages")];
        if(!fieldValue.is_null())
        {
           setExportEmbeddedImages(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ExportFormFields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportFormFields")];
        if(!fieldValue.is_null())
        {
           setExportFormFields(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("FontFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FontFormat")];
        if(!fieldValue.is_null())
        {
           setFontFormat(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PageHorizontalAlignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageHorizontalAlignment")];
        if(!fieldValue.is_null())
        {
           setPageHorizontalAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("PageMargins")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageMargins")];
        if(!fieldValue.is_null())
        {
           setPageMargins(ModelBase::floatingFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ResourcesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourcesFolder")];
        if(!fieldValue.is_null())
        {
           setResourcesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ResourcesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourcesFolderAlias")];
        if(!fieldValue.is_null())
        {
           setResourcesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("SaveFontFaceCssSeparately")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SaveFontFaceCssSeparately")];
        if(!fieldValue.is_null())
        {
           setSaveFontFaceCssSeparately(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("ShowPageBorder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ShowPageBorder")];
        if(!fieldValue.is_null())
        {
           setShowPageBorder(ModelBase::booleanFromJson(fieldValue));
        }
    }


    if(val.has_field(_XPLATSTR("UseTargetMachineFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseTargetMachineFonts")];
        if(!fieldValue.is_null())
        {
           setUseTargetMachineFonts(ModelBase::booleanFromJson(fieldValue));
        }
    }

}

void HtmlFixedSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    FixedPageSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);
    if(m_CssClassNamesPrefixIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CssClassNamesPrefix"), m_CssClassNamesPrefix));
    }


    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Encoding"), m_Encoding));
    }


    if(m_ExportEmbeddedCssIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportEmbeddedCss"), m_ExportEmbeddedCss));
    }


    if(m_ExportEmbeddedFontsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportEmbeddedFonts"), m_ExportEmbeddedFonts));
    }


    if(m_ExportEmbeddedImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportEmbeddedImages"), m_ExportEmbeddedImages));
    }


    if(m_ExportFormFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportFormFields"), m_ExportFormFields));
    }


    if(m_FontFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FontFormat"), m_FontFormat));
    }


    if(m_PageHorizontalAlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageHorizontalAlignment"), m_PageHorizontalAlignment));
    }


    if(m_PageMarginsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageMargins"), m_PageMargins));
    }


    if(m_ResourcesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolder"), m_ResourcesFolder));
    }


    if(m_ResourcesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourcesFolderAlias"), m_ResourcesFolderAlias));
    }


    if(m_SaveFontFaceCssSeparatelyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SaveFontFaceCssSeparately"), m_SaveFontFaceCssSeparately));
    }


    if(m_ShowPageBorderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ShowPageBorder"), m_ShowPageBorder));
    }


    if(m_UseTargetMachineFontsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseTargetMachineFonts"), m_UseTargetMachineFonts));
    }

}

void HtmlFixedSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    // TODO: implement fromMultiPart
}

utility::string_t HtmlFixedSaveOptionsData::getCssClassNamesPrefix() const
{
    return m_CssClassNamesPrefix;
}


void HtmlFixedSaveOptionsData::setCssClassNamesPrefix(utility::string_t value)
{
    m_CssClassNamesPrefix = value;
    m_CssClassNamesPrefixIsSet = true;
}

bool HtmlFixedSaveOptionsData::cssClassNamesPrefixIsSet() const
{
    return m_CssClassNamesPrefixIsSet;
}

void HtmlFixedSaveOptionsData::unsetCssClassNamesPrefix()
{
    m_CssClassNamesPrefixIsSet = false;
}

utility::string_t HtmlFixedSaveOptionsData::getEncoding() const
{
    return m_Encoding;
}


void HtmlFixedSaveOptionsData::setEncoding(utility::string_t value)
{
    m_Encoding = value;
    m_EncodingIsSet = true;
}

bool HtmlFixedSaveOptionsData::encodingIsSet() const
{
    return m_EncodingIsSet;
}

void HtmlFixedSaveOptionsData::unsetEncoding()
{
    m_EncodingIsSet = false;
}

bool HtmlFixedSaveOptionsData::isExportEmbeddedCss() const
{
    return m_ExportEmbeddedCss;
}


void HtmlFixedSaveOptionsData::setExportEmbeddedCss(bool value)
{
    m_ExportEmbeddedCss = value;
    m_ExportEmbeddedCssIsSet = true;
}

bool HtmlFixedSaveOptionsData::exportEmbeddedCssIsSet() const
{
    return m_ExportEmbeddedCssIsSet;
}

void HtmlFixedSaveOptionsData::unsetExportEmbeddedCss()
{
    m_ExportEmbeddedCssIsSet = false;
}

bool HtmlFixedSaveOptionsData::isExportEmbeddedFonts() const
{
    return m_ExportEmbeddedFonts;
}


void HtmlFixedSaveOptionsData::setExportEmbeddedFonts(bool value)
{
    m_ExportEmbeddedFonts = value;
    m_ExportEmbeddedFontsIsSet = true;
}

bool HtmlFixedSaveOptionsData::exportEmbeddedFontsIsSet() const
{
    return m_ExportEmbeddedFontsIsSet;
}

void HtmlFixedSaveOptionsData::unsetExportEmbeddedFonts()
{
    m_ExportEmbeddedFontsIsSet = false;
}

bool HtmlFixedSaveOptionsData::isExportEmbeddedImages() const
{
    return m_ExportEmbeddedImages;
}


void HtmlFixedSaveOptionsData::setExportEmbeddedImages(bool value)
{
    m_ExportEmbeddedImages = value;
    m_ExportEmbeddedImagesIsSet = true;
}

bool HtmlFixedSaveOptionsData::exportEmbeddedImagesIsSet() const
{
    return m_ExportEmbeddedImagesIsSet;
}

void HtmlFixedSaveOptionsData::unsetExportEmbeddedImages()
{
    m_ExportEmbeddedImagesIsSet = false;
}

bool HtmlFixedSaveOptionsData::isExportFormFields() const
{
    return m_ExportFormFields;
}


void HtmlFixedSaveOptionsData::setExportFormFields(bool value)
{
    m_ExportFormFields = value;
    m_ExportFormFieldsIsSet = true;
}

bool HtmlFixedSaveOptionsData::exportFormFieldsIsSet() const
{
    return m_ExportFormFieldsIsSet;
}

void HtmlFixedSaveOptionsData::unsetExportFormFields()
{
    m_ExportFormFieldsIsSet = false;
}

utility::string_t HtmlFixedSaveOptionsData::getFontFormat() const
{
    return m_FontFormat;
}


void HtmlFixedSaveOptionsData::setFontFormat(utility::string_t value)
{
    m_FontFormat = value;
    m_FontFormatIsSet = true;
}

bool HtmlFixedSaveOptionsData::fontFormatIsSet() const
{
    return m_FontFormatIsSet;
}

void HtmlFixedSaveOptionsData::unsetFontFormat()
{
    m_FontFormatIsSet = false;
}

utility::string_t HtmlFixedSaveOptionsData::getPageHorizontalAlignment() const
{
    return m_PageHorizontalAlignment;
}


void HtmlFixedSaveOptionsData::setPageHorizontalAlignment(utility::string_t value)
{
    m_PageHorizontalAlignment = value;
    m_PageHorizontalAlignmentIsSet = true;
}

bool HtmlFixedSaveOptionsData::pageHorizontalAlignmentIsSet() const
{
    return m_PageHorizontalAlignmentIsSet;
}

void HtmlFixedSaveOptionsData::unsetPageHorizontalAlignment()
{
    m_PageHorizontalAlignmentIsSet = false;
}

double HtmlFixedSaveOptionsData::getPageMargins() const
{
    return m_PageMargins;
}


void HtmlFixedSaveOptionsData::setPageMargins(double value)
{
    m_PageMargins = value;
    m_PageMarginsIsSet = true;
}

bool HtmlFixedSaveOptionsData::pageMarginsIsSet() const
{
    return m_PageMarginsIsSet;
}

void HtmlFixedSaveOptionsData::unsetPageMargins()
{
    m_PageMarginsIsSet = false;
}

utility::string_t HtmlFixedSaveOptionsData::getResourcesFolder() const
{
    return m_ResourcesFolder;
}


void HtmlFixedSaveOptionsData::setResourcesFolder(utility::string_t value)
{
    m_ResourcesFolder = value;
    m_ResourcesFolderIsSet = true;
}

bool HtmlFixedSaveOptionsData::resourcesFolderIsSet() const
{
    return m_ResourcesFolderIsSet;
}

void HtmlFixedSaveOptionsData::unsetResourcesFolder()
{
    m_ResourcesFolderIsSet = false;
}

utility::string_t HtmlFixedSaveOptionsData::getResourcesFolderAlias() const
{
    return m_ResourcesFolderAlias;
}


void HtmlFixedSaveOptionsData::setResourcesFolderAlias(utility::string_t value)
{
    m_ResourcesFolderAlias = value;
    m_ResourcesFolderAliasIsSet = true;
}

bool HtmlFixedSaveOptionsData::resourcesFolderAliasIsSet() const
{
    return m_ResourcesFolderAliasIsSet;
}

void HtmlFixedSaveOptionsData::unsetResourcesFolderAlias()
{
    m_ResourcesFolderAliasIsSet = false;
}

bool HtmlFixedSaveOptionsData::isSaveFontFaceCssSeparately() const
{
    return m_SaveFontFaceCssSeparately;
}


void HtmlFixedSaveOptionsData::setSaveFontFaceCssSeparately(bool value)
{
    m_SaveFontFaceCssSeparately = value;
    m_SaveFontFaceCssSeparatelyIsSet = true;
}

bool HtmlFixedSaveOptionsData::saveFontFaceCssSeparatelyIsSet() const
{
    return m_SaveFontFaceCssSeparatelyIsSet;
}

void HtmlFixedSaveOptionsData::unsetSaveFontFaceCssSeparately()
{
    m_SaveFontFaceCssSeparatelyIsSet = false;
}

bool HtmlFixedSaveOptionsData::isShowPageBorder() const
{
    return m_ShowPageBorder;
}


void HtmlFixedSaveOptionsData::setShowPageBorder(bool value)
{
    m_ShowPageBorder = value;
    m_ShowPageBorderIsSet = true;
}

bool HtmlFixedSaveOptionsData::showPageBorderIsSet() const
{
    return m_ShowPageBorderIsSet;
}

void HtmlFixedSaveOptionsData::unsetShowPageBorder()
{
    m_ShowPageBorderIsSet = false;
}

bool HtmlFixedSaveOptionsData::isUseTargetMachineFonts() const
{
    return m_UseTargetMachineFonts;
}


void HtmlFixedSaveOptionsData::setUseTargetMachineFonts(bool value)
{
    m_UseTargetMachineFonts = value;
    m_UseTargetMachineFontsIsSet = true;
}

bool HtmlFixedSaveOptionsData::useTargetMachineFontsIsSet() const
{
    return m_UseTargetMachineFontsIsSet;
}

void HtmlFixedSaveOptionsData::unsetUseTargetMachineFonts()
{
    m_UseTargetMachineFontsIsSet = false;
}

}
}
}
}
}
