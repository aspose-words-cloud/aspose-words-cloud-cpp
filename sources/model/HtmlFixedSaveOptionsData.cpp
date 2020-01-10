/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HtmlFixedSaveOptionsData.cpp">
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
        val[_XPLATSTR("cssClassNamesPrefix")] = ModelBase::toJson(m_CssClassNamesPrefix);
    }
    if(m_EncodingIsSet)
    {
        val[_XPLATSTR("encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportEmbeddedCssIsSet)
    {
        val[_XPLATSTR("exportEmbeddedCss")] = ModelBase::toJson(m_ExportEmbeddedCss);
    }
    if(m_ExportEmbeddedFontsIsSet)
    {
        val[_XPLATSTR("exportEmbeddedFonts")] = ModelBase::toJson(m_ExportEmbeddedFonts);
    }
    if(m_ExportEmbeddedImagesIsSet)
    {
        val[_XPLATSTR("exportEmbeddedImages")] = ModelBase::toJson(m_ExportEmbeddedImages);
    }
    if(m_ExportFormFieldsIsSet)
    {
        val[_XPLATSTR("exportFormFields")] = ModelBase::toJson(m_ExportFormFields);
    }
    if(m_FontFormatIsSet)
    {
        val[_XPLATSTR("fontFormat")] = ModelBase::toJson(m_FontFormat);
    }
    if(m_PageHorizontalAlignmentIsSet)
    {
        val[_XPLATSTR("pageHorizontalAlignment")] = ModelBase::toJson(m_PageHorizontalAlignment);
    }
    if(m_PageMarginsIsSet)
    {
        val[_XPLATSTR("pageMargins")] = ModelBase::toJson(m_PageMargins);
    }
    if(m_ResourcesFolderIsSet)
    {
        val[_XPLATSTR("resourcesFolder")] = ModelBase::toJson(m_ResourcesFolder);
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        val[_XPLATSTR("resourcesFolderAlias")] = ModelBase::toJson(m_ResourcesFolderAlias);
    }
    if(m_SaveFontFaceCssSeparatelyIsSet)
    {
        val[_XPLATSTR("saveFontFaceCssSeparately")] = ModelBase::toJson(m_SaveFontFaceCssSeparately);
    }
    if(m_ShowPageBorderIsSet)
    {
        val[_XPLATSTR("showPageBorder")] = ModelBase::toJson(m_ShowPageBorder);
    }

    return val;
}

void HtmlFixedSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("cssClassNamesPrefix")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("cssClassNamesPrefix")];
        if(!fieldValue.is_null())
        {
            setCssClassNamesPrefix(ModelBase::stringFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("exportEmbeddedCss")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportEmbeddedCss")];
        if(!fieldValue.is_null())
        {
            setExportEmbeddedCss(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportEmbeddedFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportEmbeddedFonts")];
        if(!fieldValue.is_null())
        {
            setExportEmbeddedFonts(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportEmbeddedImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportEmbeddedImages")];
        if(!fieldValue.is_null())
        {
            setExportEmbeddedImages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportFormFields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportFormFields")];
        if(!fieldValue.is_null())
        {
            setExportFormFields(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("fontFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fontFormat")];
        if(!fieldValue.is_null())
        {
            setFontFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageHorizontalAlignment")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageHorizontalAlignment")];
        if(!fieldValue.is_null())
        {
            setPageHorizontalAlignment(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("pageMargins")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageMargins")];
        if(!fieldValue.is_null())
        {
            setPageMargins(ModelBase::doubleFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resourcesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resourcesFolder")];
        if(!fieldValue.is_null())
        {
            setResourcesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resourcesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resourcesFolderAlias")];
        if(!fieldValue.is_null())
        {
            setResourcesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("saveFontFaceCssSeparately")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("saveFontFaceCssSeparately")];
        if(!fieldValue.is_null())
        {
            setSaveFontFaceCssSeparately(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("showPageBorder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("showPageBorder")];
        if(!fieldValue.is_null())
        {
            setShowPageBorder(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void HtmlFixedSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_JpegQualityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("jpegQuality"), m_JpegQuality));
    }
    if(m_MetafileRenderingOptionsIsSet)
    {
        if (m_MetafileRenderingOptions.get())
        {
            m_MetafileRenderingOptions->toMultipart(multipart, _XPLATSTR("metafileRenderingOptions."));
        }
        
    }
    if(m_NumeralFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("numeralFormat"), m_NumeralFormat));
        
    }
    if(m_OptimizeOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("optimizeOutput"), m_OptimizeOutput));
    }
    if(m_PageCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageCount"), m_PageCount));
    }
    if(m_PageIndexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageIndex"), m_PageIndex));
    }
    if(m_CssClassNamesPrefixIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("cssClassNamesPrefix"), m_CssClassNamesPrefix));
        
    }
    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("encoding"), m_Encoding));
        
    }
    if(m_ExportEmbeddedCssIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportEmbeddedCss"), m_ExportEmbeddedCss));
    }
    if(m_ExportEmbeddedFontsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportEmbeddedFonts"), m_ExportEmbeddedFonts));
    }
    if(m_ExportEmbeddedImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportEmbeddedImages"), m_ExportEmbeddedImages));
    }
    if(m_ExportFormFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportFormFields"), m_ExportFormFields));
    }
    if(m_FontFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fontFormat"), m_FontFormat));
        
    }
    if(m_PageHorizontalAlignmentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageHorizontalAlignment"), m_PageHorizontalAlignment));
        
    }
    if(m_PageMarginsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageMargins"), m_PageMargins));
    }
    if(m_ResourcesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resourcesFolder"), m_ResourcesFolder));
        
    }
    if(m_ResourcesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resourcesFolderAlias"), m_ResourcesFolderAlias));
        
    }
    if(m_SaveFontFaceCssSeparatelyIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("saveFontFaceCssSeparately"), m_SaveFontFaceCssSeparately));
    }
    if(m_ShowPageBorderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("showPageBorder"), m_ShowPageBorder));
    }
}

void HtmlFixedSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("jpegQuality")))
    {
        setJpegQuality(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("jpegQuality"))));
    }
    if(multipart->hasContent(_XPLATSTR("metafileRenderingOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("metafileRenderingOptions")))
        {
            std::shared_ptr<MetafileRenderingOptionsData> newItem(new MetafileRenderingOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("metafileRenderingOptions."));
            setMetafileRenderingOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("numeralFormat")))
    {
        setNumeralFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("numeralFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("optimizeOutput")))
    {
        setOptimizeOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("optimizeOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageCount")))
    {
        setPageCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("pageCount"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageIndex")))
    {
        setPageIndex(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("pageIndex"))));
    }
    if(multipart->hasContent(_XPLATSTR("cssClassNamesPrefix")))
    {
        setCssClassNamesPrefix(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("cssClassNamesPrefix"))));
    }
    if(multipart->hasContent(_XPLATSTR("encoding")))
    {
        setEncoding(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("encoding"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportEmbeddedCss")))
    {
        setExportEmbeddedCss(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportEmbeddedCss"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportEmbeddedFonts")))
    {
        setExportEmbeddedFonts(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportEmbeddedFonts"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportEmbeddedImages")))
    {
        setExportEmbeddedImages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportEmbeddedImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportFormFields")))
    {
        setExportFormFields(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportFormFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("fontFormat")))
    {
        setFontFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fontFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageHorizontalAlignment")))
    {
        setPageHorizontalAlignment(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("pageHorizontalAlignment"))));
    }
    if(multipart->hasContent(_XPLATSTR("pageMargins")))
    {
        setPageMargins(ModelBase::doubleFromHttpContent(multipart->getContent(_XPLATSTR("pageMargins"))));
    }
    if(multipart->hasContent(_XPLATSTR("resourcesFolder")))
    {
        setResourcesFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("resourcesFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("resourcesFolderAlias")))
    {
        setResourcesFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("resourcesFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("saveFontFaceCssSeparately")))
    {
        setSaveFontFaceCssSeparately(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("saveFontFaceCssSeparately"))));
    }
    if(multipart->hasContent(_XPLATSTR("showPageBorder")))
    {
        setShowPageBorder(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("showPageBorder"))));
    }
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

}
}
}
}
}

