/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HtmlSaveOptionsData.cpp">
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


#include "HtmlSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

HtmlSaveOptionsData::HtmlSaveOptionsData()
{
    m_AllowNegativeIndent = false;
    m_AllowNegativeIndentIsSet = false;
    m_CssClassNamePrefix = utility::conversions::to_string_t("");
    m_CssClassNamePrefixIsSet = false;
    m_CssStyleSheetFileName = utility::conversions::to_string_t("");
    m_CssStyleSheetFileNameIsSet = false;
    m_CssStyleSheetType = utility::conversions::to_string_t("");
    m_CssStyleSheetTypeIsSet = false;
    m_DocumentSplitCriteria = utility::conversions::to_string_t("");
    m_DocumentSplitCriteriaIsSet = false;
    m_DocumentSplitHeadingLevel = 0;
    m_DocumentSplitHeadingLevelIsSet = false;
    m_Encoding = utility::conversions::to_string_t("");
    m_EncodingIsSet = false;
    m_ExportDocumentProperties = false;
    m_ExportDocumentPropertiesIsSet = false;
    m_ExportDropDownFormFieldAsText = false;
    m_ExportDropDownFormFieldAsTextIsSet = false;
    m_ExportFontResources = false;
    m_ExportFontResourcesIsSet = false;
    m_ExportFontsAsBase64 = false;
    m_ExportFontsAsBase64IsSet = false;
    m_ExportHeadersFootersMode = utility::conversions::to_string_t("");
    m_ExportHeadersFootersModeIsSet = false;
    m_ExportImagesAsBase64 = false;
    m_ExportImagesAsBase64IsSet = false;
    m_ExportLanguageInformation = false;
    m_ExportLanguageInformationIsSet = false;
    m_ExportListLabels = utility::conversions::to_string_t("");
    m_ExportListLabelsIsSet = false;
    m_ExportOriginalUrlForLinkedImages = false;
    m_ExportOriginalUrlForLinkedImagesIsSet = false;
    m_ExportPageMargins = false;
    m_ExportPageMarginsIsSet = false;
    m_ExportPageSetup = false;
    m_ExportPageSetupIsSet = false;
    m_ExportRelativeFontSize = false;
    m_ExportRelativeFontSizeIsSet = false;
    m_ExportRoundtripInformation = false;
    m_ExportRoundtripInformationIsSet = false;
    m_ExportTextBoxAsSvg = false;
    m_ExportTextBoxAsSvgIsSet = false;
    m_ExportTextInputFormFieldAsText = false;
    m_ExportTextInputFormFieldAsTextIsSet = false;
    m_ExportTocPageNumbers = false;
    m_ExportTocPageNumbersIsSet = false;
    m_ExportXhtmlTransitional = false;
    m_ExportXhtmlTransitionalIsSet = false;
    m_FontResourcesSubsettingSizeThreshold = 0;
    m_FontResourcesSubsettingSizeThresholdIsSet = false;
    m_FontsFolder = utility::conversions::to_string_t("");
    m_FontsFolderIsSet = false;
    m_FontsFolderAlias = utility::conversions::to_string_t("");
    m_FontsFolderAliasIsSet = false;
    m_HtmlVersion = utility::conversions::to_string_t("");
    m_HtmlVersionIsSet = false;
    m_ImageResolution = 0;
    m_ImageResolutionIsSet = false;
    m_ImagesFolder = utility::conversions::to_string_t("");
    m_ImagesFolderIsSet = false;
    m_ImagesFolderAlias = utility::conversions::to_string_t("");
    m_ImagesFolderAliasIsSet = false;
    m_MetafileFormat = utility::conversions::to_string_t("");
    m_MetafileFormatIsSet = false;
    m_OfficeMathOutputMode = utility::conversions::to_string_t("");
    m_OfficeMathOutputModeIsSet = false;
    m_PrettyFormat = false;
    m_PrettyFormatIsSet = false;
    m_ResolveFontNames = false;
    m_ResolveFontNamesIsSet = false;
    m_ResourceFolder = utility::conversions::to_string_t("");
    m_ResourceFolderIsSet = false;
    m_ResourceFolderAlias = utility::conversions::to_string_t("");
    m_ResourceFolderAliasIsSet = false;
    m_ScaleImageToShapeSize = false;
    m_ScaleImageToShapeSizeIsSet = false;
    m_TableWidthOutputMode = utility::conversions::to_string_t("");
    m_TableWidthOutputModeIsSet = false;
}

HtmlSaveOptionsData::~HtmlSaveOptionsData()
{
}

void HtmlSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value HtmlSaveOptionsData::toJson() const
{
    web::json::value val = this->SaveOptionsData::toJson();

    if(m_AllowNegativeIndentIsSet)
    {
        val[_XPLATSTR("allowNegativeIndent")] = ModelBase::toJson(m_AllowNegativeIndent);
    }
    if(m_CssClassNamePrefixIsSet)
    {
        val[_XPLATSTR("cssClassNamePrefix")] = ModelBase::toJson(m_CssClassNamePrefix);
    }
    if(m_CssStyleSheetFileNameIsSet)
    {
        val[_XPLATSTR("cssStyleSheetFileName")] = ModelBase::toJson(m_CssStyleSheetFileName);
    }
    if(m_CssStyleSheetTypeIsSet)
    {
        val[_XPLATSTR("cssStyleSheetType")] = ModelBase::toJson(m_CssStyleSheetType);
    }
    if(m_DocumentSplitCriteriaIsSet)
    {
        val[_XPLATSTR("documentSplitCriteria")] = ModelBase::toJson(m_DocumentSplitCriteria);
    }
    if(m_DocumentSplitHeadingLevelIsSet)
    {
        val[_XPLATSTR("documentSplitHeadingLevel")] = ModelBase::toJson(m_DocumentSplitHeadingLevel);
    }
    if(m_EncodingIsSet)
    {
        val[_XPLATSTR("encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportDocumentPropertiesIsSet)
    {
        val[_XPLATSTR("exportDocumentProperties")] = ModelBase::toJson(m_ExportDocumentProperties);
    }
    if(m_ExportDropDownFormFieldAsTextIsSet)
    {
        val[_XPLATSTR("exportDropDownFormFieldAsText")] = ModelBase::toJson(m_ExportDropDownFormFieldAsText);
    }
    if(m_ExportFontResourcesIsSet)
    {
        val[_XPLATSTR("exportFontResources")] = ModelBase::toJson(m_ExportFontResources);
    }
    if(m_ExportFontsAsBase64IsSet)
    {
        val[_XPLATSTR("exportFontsAsBase64")] = ModelBase::toJson(m_ExportFontsAsBase64);
    }
    if(m_ExportHeadersFootersModeIsSet)
    {
        val[_XPLATSTR("exportHeadersFootersMode")] = ModelBase::toJson(m_ExportHeadersFootersMode);
    }
    if(m_ExportImagesAsBase64IsSet)
    {
        val[_XPLATSTR("exportImagesAsBase64")] = ModelBase::toJson(m_ExportImagesAsBase64);
    }
    if(m_ExportLanguageInformationIsSet)
    {
        val[_XPLATSTR("exportLanguageInformation")] = ModelBase::toJson(m_ExportLanguageInformation);
    }
    if(m_ExportListLabelsIsSet)
    {
        val[_XPLATSTR("exportListLabels")] = ModelBase::toJson(m_ExportListLabels);
    }
    if(m_ExportOriginalUrlForLinkedImagesIsSet)
    {
        val[_XPLATSTR("exportOriginalUrlForLinkedImages")] = ModelBase::toJson(m_ExportOriginalUrlForLinkedImages);
    }
    if(m_ExportPageMarginsIsSet)
    {
        val[_XPLATSTR("exportPageMargins")] = ModelBase::toJson(m_ExportPageMargins);
    }
    if(m_ExportPageSetupIsSet)
    {
        val[_XPLATSTR("exportPageSetup")] = ModelBase::toJson(m_ExportPageSetup);
    }
    if(m_ExportRelativeFontSizeIsSet)
    {
        val[_XPLATSTR("exportRelativeFontSize")] = ModelBase::toJson(m_ExportRelativeFontSize);
    }
    if(m_ExportRoundtripInformationIsSet)
    {
        val[_XPLATSTR("exportRoundtripInformation")] = ModelBase::toJson(m_ExportRoundtripInformation);
    }
    if(m_ExportTextBoxAsSvgIsSet)
    {
        val[_XPLATSTR("exportTextBoxAsSvg")] = ModelBase::toJson(m_ExportTextBoxAsSvg);
    }
    if(m_ExportTextInputFormFieldAsTextIsSet)
    {
        val[_XPLATSTR("exportTextInputFormFieldAsText")] = ModelBase::toJson(m_ExportTextInputFormFieldAsText);
    }
    if(m_ExportTocPageNumbersIsSet)
    {
        val[_XPLATSTR("exportTocPageNumbers")] = ModelBase::toJson(m_ExportTocPageNumbers);
    }
    if(m_ExportXhtmlTransitionalIsSet)
    {
        val[_XPLATSTR("exportXhtmlTransitional")] = ModelBase::toJson(m_ExportXhtmlTransitional);
    }
    if(m_FontResourcesSubsettingSizeThresholdIsSet)
    {
        val[_XPLATSTR("fontResourcesSubsettingSizeThreshold")] = ModelBase::toJson(m_FontResourcesSubsettingSizeThreshold);
    }
    if(m_FontsFolderIsSet)
    {
        val[_XPLATSTR("fontsFolder")] = ModelBase::toJson(m_FontsFolder);
    }
    if(m_FontsFolderAliasIsSet)
    {
        val[_XPLATSTR("fontsFolderAlias")] = ModelBase::toJson(m_FontsFolderAlias);
    }
    if(m_HtmlVersionIsSet)
    {
        val[_XPLATSTR("htmlVersion")] = ModelBase::toJson(m_HtmlVersion);
    }
    if(m_ImageResolutionIsSet)
    {
        val[_XPLATSTR("imageResolution")] = ModelBase::toJson(m_ImageResolution);
    }
    if(m_ImagesFolderIsSet)
    {
        val[_XPLATSTR("imagesFolder")] = ModelBase::toJson(m_ImagesFolder);
    }
    if(m_ImagesFolderAliasIsSet)
    {
        val[_XPLATSTR("imagesFolderAlias")] = ModelBase::toJson(m_ImagesFolderAlias);
    }
    if(m_MetafileFormatIsSet)
    {
        val[_XPLATSTR("metafileFormat")] = ModelBase::toJson(m_MetafileFormat);
    }
    if(m_OfficeMathOutputModeIsSet)
    {
        val[_XPLATSTR("officeMathOutputMode")] = ModelBase::toJson(m_OfficeMathOutputMode);
    }
    if(m_PrettyFormatIsSet)
    {
        val[_XPLATSTR("prettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }
    if(m_ResolveFontNamesIsSet)
    {
        val[_XPLATSTR("resolveFontNames")] = ModelBase::toJson(m_ResolveFontNames);
    }
    if(m_ResourceFolderIsSet)
    {
        val[_XPLATSTR("resourceFolder")] = ModelBase::toJson(m_ResourceFolder);
    }
    if(m_ResourceFolderAliasIsSet)
    {
        val[_XPLATSTR("resourceFolderAlias")] = ModelBase::toJson(m_ResourceFolderAlias);
    }
    if(m_ScaleImageToShapeSizeIsSet)
    {
        val[_XPLATSTR("scaleImageToShapeSize")] = ModelBase::toJson(m_ScaleImageToShapeSize);
    }
    if(m_TableWidthOutputModeIsSet)
    {
        val[_XPLATSTR("tableWidthOutputMode")] = ModelBase::toJson(m_TableWidthOutputMode);
    }

    return val;
}

void HtmlSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("allowNegativeIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("allowNegativeIndent")];
        if(!fieldValue.is_null())
        {
            setAllowNegativeIndent(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("cssClassNamePrefix")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("cssClassNamePrefix")];
        if(!fieldValue.is_null())
        {
            setCssClassNamePrefix(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("cssStyleSheetFileName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("cssStyleSheetFileName")];
        if(!fieldValue.is_null())
        {
            setCssStyleSheetFileName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("cssStyleSheetType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("cssStyleSheetType")];
        if(!fieldValue.is_null())
        {
            setCssStyleSheetType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("documentSplitCriteria")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("documentSplitCriteria")];
        if(!fieldValue.is_null())
        {
            setDocumentSplitCriteria(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("documentSplitHeadingLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("documentSplitHeadingLevel")];
        if(!fieldValue.is_null())
        {
            setDocumentSplitHeadingLevel(ModelBase::int32_tFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("exportDocumentProperties")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportDocumentProperties")];
        if(!fieldValue.is_null())
        {
            setExportDocumentProperties(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportDropDownFormFieldAsText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportDropDownFormFieldAsText")];
        if(!fieldValue.is_null())
        {
            setExportDropDownFormFieldAsText(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportFontResources")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportFontResources")];
        if(!fieldValue.is_null())
        {
            setExportFontResources(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportFontsAsBase64")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportFontsAsBase64")];
        if(!fieldValue.is_null())
        {
            setExportFontsAsBase64(ModelBase::boolFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("exportImagesAsBase64")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportImagesAsBase64")];
        if(!fieldValue.is_null())
        {
            setExportImagesAsBase64(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportLanguageInformation")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportLanguageInformation")];
        if(!fieldValue.is_null())
        {
            setExportLanguageInformation(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportListLabels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportListLabels")];
        if(!fieldValue.is_null())
        {
            setExportListLabels(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportOriginalUrlForLinkedImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportOriginalUrlForLinkedImages")];
        if(!fieldValue.is_null())
        {
            setExportOriginalUrlForLinkedImages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportPageMargins")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportPageMargins")];
        if(!fieldValue.is_null())
        {
            setExportPageMargins(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportPageSetup")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportPageSetup")];
        if(!fieldValue.is_null())
        {
            setExportPageSetup(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportRelativeFontSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportRelativeFontSize")];
        if(!fieldValue.is_null())
        {
            setExportRelativeFontSize(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportRoundtripInformation")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportRoundtripInformation")];
        if(!fieldValue.is_null())
        {
            setExportRoundtripInformation(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportTextBoxAsSvg")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportTextBoxAsSvg")];
        if(!fieldValue.is_null())
        {
            setExportTextBoxAsSvg(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportTextInputFormFieldAsText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportTextInputFormFieldAsText")];
        if(!fieldValue.is_null())
        {
            setExportTextInputFormFieldAsText(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportTocPageNumbers")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportTocPageNumbers")];
        if(!fieldValue.is_null())
        {
            setExportTocPageNumbers(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportXhtmlTransitional")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportXhtmlTransitional")];
        if(!fieldValue.is_null())
        {
            setExportXhtmlTransitional(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("fontResourcesSubsettingSizeThreshold")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fontResourcesSubsettingSizeThreshold")];
        if(!fieldValue.is_null())
        {
            setFontResourcesSubsettingSizeThreshold(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("fontsFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fontsFolder")];
        if(!fieldValue.is_null())
        {
            setFontsFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("fontsFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fontsFolderAlias")];
        if(!fieldValue.is_null())
        {
            setFontsFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("htmlVersion")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("htmlVersion")];
        if(!fieldValue.is_null())
        {
            setHtmlVersion(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imageResolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imageResolution")];
        if(!fieldValue.is_null())
        {
            setImageResolution(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imagesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imagesFolder")];
        if(!fieldValue.is_null())
        {
            setImagesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imagesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imagesFolderAlias")];
        if(!fieldValue.is_null())
        {
            setImagesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("metafileFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("metafileFormat")];
        if(!fieldValue.is_null())
        {
            setMetafileFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("officeMathOutputMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("officeMathOutputMode")];
        if(!fieldValue.is_null())
        {
            setOfficeMathOutputMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("prettyFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("prettyFormat")];
        if(!fieldValue.is_null())
        {
            setPrettyFormat(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resolveFontNames")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resolveFontNames")];
        if(!fieldValue.is_null())
        {
            setResolveFontNames(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resourceFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resourceFolder")];
        if(!fieldValue.is_null())
        {
            setResourceFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("resourceFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("resourceFolderAlias")];
        if(!fieldValue.is_null())
        {
            setResourceFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("scaleImageToShapeSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("scaleImageToShapeSize")];
        if(!fieldValue.is_null())
        {
            setScaleImageToShapeSize(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("tableWidthOutputMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("tableWidthOutputMode")];
        if(!fieldValue.is_null())
        {
            setTableWidthOutputMode(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void HtmlSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_AllowNegativeIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("allowNegativeIndent"), m_AllowNegativeIndent));
    }
    if(m_CssClassNamePrefixIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("cssClassNamePrefix"), m_CssClassNamePrefix));
        
    }
    if(m_CssStyleSheetFileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("cssStyleSheetFileName"), m_CssStyleSheetFileName));
        
    }
    if(m_CssStyleSheetTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("cssStyleSheetType"), m_CssStyleSheetType));
        
    }
    if(m_DocumentSplitCriteriaIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("documentSplitCriteria"), m_DocumentSplitCriteria));
        
    }
    if(m_DocumentSplitHeadingLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("documentSplitHeadingLevel"), m_DocumentSplitHeadingLevel));
    }
    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("encoding"), m_Encoding));
        
    }
    if(m_ExportDocumentPropertiesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportDocumentProperties"), m_ExportDocumentProperties));
    }
    if(m_ExportDropDownFormFieldAsTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportDropDownFormFieldAsText"), m_ExportDropDownFormFieldAsText));
    }
    if(m_ExportFontResourcesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportFontResources"), m_ExportFontResources));
    }
    if(m_ExportFontsAsBase64IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportFontsAsBase64"), m_ExportFontsAsBase64));
    }
    if(m_ExportHeadersFootersModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportHeadersFootersMode"), m_ExportHeadersFootersMode));
        
    }
    if(m_ExportImagesAsBase64IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportImagesAsBase64"), m_ExportImagesAsBase64));
    }
    if(m_ExportLanguageInformationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportLanguageInformation"), m_ExportLanguageInformation));
    }
    if(m_ExportListLabelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportListLabels"), m_ExportListLabels));
        
    }
    if(m_ExportOriginalUrlForLinkedImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportOriginalUrlForLinkedImages"), m_ExportOriginalUrlForLinkedImages));
    }
    if(m_ExportPageMarginsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportPageMargins"), m_ExportPageMargins));
    }
    if(m_ExportPageSetupIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportPageSetup"), m_ExportPageSetup));
    }
    if(m_ExportRelativeFontSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportRelativeFontSize"), m_ExportRelativeFontSize));
    }
    if(m_ExportRoundtripInformationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportRoundtripInformation"), m_ExportRoundtripInformation));
    }
    if(m_ExportTextBoxAsSvgIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportTextBoxAsSvg"), m_ExportTextBoxAsSvg));
    }
    if(m_ExportTextInputFormFieldAsTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportTextInputFormFieldAsText"), m_ExportTextInputFormFieldAsText));
    }
    if(m_ExportTocPageNumbersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportTocPageNumbers"), m_ExportTocPageNumbers));
    }
    if(m_ExportXhtmlTransitionalIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportXhtmlTransitional"), m_ExportXhtmlTransitional));
    }
    if(m_FontResourcesSubsettingSizeThresholdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fontResourcesSubsettingSizeThreshold"), m_FontResourcesSubsettingSizeThreshold));
    }
    if(m_FontsFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fontsFolder"), m_FontsFolder));
        
    }
    if(m_FontsFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fontsFolderAlias"), m_FontsFolderAlias));
        
    }
    if(m_HtmlVersionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("htmlVersion"), m_HtmlVersion));
        
    }
    if(m_ImageResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imageResolution"), m_ImageResolution));
    }
    if(m_ImagesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imagesFolder"), m_ImagesFolder));
        
    }
    if(m_ImagesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imagesFolderAlias"), m_ImagesFolderAlias));
        
    }
    if(m_MetafileFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("metafileFormat"), m_MetafileFormat));
        
    }
    if(m_OfficeMathOutputModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("officeMathOutputMode"), m_OfficeMathOutputMode));
        
    }
    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("prettyFormat"), m_PrettyFormat));
    }
    if(m_ResolveFontNamesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resolveFontNames"), m_ResolveFontNames));
    }
    if(m_ResourceFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resourceFolder"), m_ResourceFolder));
        
    }
    if(m_ResourceFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("resourceFolderAlias"), m_ResourceFolderAlias));
        
    }
    if(m_ScaleImageToShapeSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("scaleImageToShapeSize"), m_ScaleImageToShapeSize));
    }
    if(m_TableWidthOutputModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("tableWidthOutputMode"), m_TableWidthOutputMode));
        
    }
}

void HtmlSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("allowNegativeIndent")))
    {
        setAllowNegativeIndent(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("allowNegativeIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("cssClassNamePrefix")))
    {
        setCssClassNamePrefix(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("cssClassNamePrefix"))));
    }
    if(multipart->hasContent(_XPLATSTR("cssStyleSheetFileName")))
    {
        setCssStyleSheetFileName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("cssStyleSheetFileName"))));
    }
    if(multipart->hasContent(_XPLATSTR("cssStyleSheetType")))
    {
        setCssStyleSheetType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("cssStyleSheetType"))));
    }
    if(multipart->hasContent(_XPLATSTR("documentSplitCriteria")))
    {
        setDocumentSplitCriteria(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("documentSplitCriteria"))));
    }
    if(multipart->hasContent(_XPLATSTR("documentSplitHeadingLevel")))
    {
        setDocumentSplitHeadingLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("documentSplitHeadingLevel"))));
    }
    if(multipart->hasContent(_XPLATSTR("encoding")))
    {
        setEncoding(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("encoding"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportDocumentProperties")))
    {
        setExportDocumentProperties(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportDocumentProperties"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportDropDownFormFieldAsText")))
    {
        setExportDropDownFormFieldAsText(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportDropDownFormFieldAsText"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportFontResources")))
    {
        setExportFontResources(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportFontResources"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportFontsAsBase64")))
    {
        setExportFontsAsBase64(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportFontsAsBase64"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportHeadersFootersMode")))
    {
        setExportHeadersFootersMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("exportHeadersFootersMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportImagesAsBase64")))
    {
        setExportImagesAsBase64(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportImagesAsBase64"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportLanguageInformation")))
    {
        setExportLanguageInformation(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportLanguageInformation"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportListLabels")))
    {
        setExportListLabels(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("exportListLabels"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportOriginalUrlForLinkedImages")))
    {
        setExportOriginalUrlForLinkedImages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportOriginalUrlForLinkedImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportPageMargins")))
    {
        setExportPageMargins(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportPageMargins"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportPageSetup")))
    {
        setExportPageSetup(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportPageSetup"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportRelativeFontSize")))
    {
        setExportRelativeFontSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportRelativeFontSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportRoundtripInformation")))
    {
        setExportRoundtripInformation(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportRoundtripInformation"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportTextBoxAsSvg")))
    {
        setExportTextBoxAsSvg(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportTextBoxAsSvg"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportTextInputFormFieldAsText")))
    {
        setExportTextInputFormFieldAsText(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportTextInputFormFieldAsText"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportTocPageNumbers")))
    {
        setExportTocPageNumbers(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportTocPageNumbers"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportXhtmlTransitional")))
    {
        setExportXhtmlTransitional(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportXhtmlTransitional"))));
    }
    if(multipart->hasContent(_XPLATSTR("fontResourcesSubsettingSizeThreshold")))
    {
        setFontResourcesSubsettingSizeThreshold(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("fontResourcesSubsettingSizeThreshold"))));
    }
    if(multipart->hasContent(_XPLATSTR("fontsFolder")))
    {
        setFontsFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fontsFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("fontsFolderAlias")))
    {
        setFontsFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fontsFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("htmlVersion")))
    {
        setHtmlVersion(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("htmlVersion"))));
    }
    if(multipart->hasContent(_XPLATSTR("imageResolution")))
    {
        setImageResolution(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("imageResolution"))));
    }
    if(multipart->hasContent(_XPLATSTR("imagesFolder")))
    {
        setImagesFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("imagesFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("imagesFolderAlias")))
    {
        setImagesFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("imagesFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("metafileFormat")))
    {
        setMetafileFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("metafileFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("officeMathOutputMode")))
    {
        setOfficeMathOutputMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("officeMathOutputMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("prettyFormat")))
    {
        setPrettyFormat(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("prettyFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("resolveFontNames")))
    {
        setResolveFontNames(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("resolveFontNames"))));
    }
    if(multipart->hasContent(_XPLATSTR("resourceFolder")))
    {
        setResourceFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("resourceFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("resourceFolderAlias")))
    {
        setResourceFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("resourceFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("scaleImageToShapeSize")))
    {
        setScaleImageToShapeSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("scaleImageToShapeSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("tableWidthOutputMode")))
    {
        setTableWidthOutputMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("tableWidthOutputMode"))));
    }
}

bool HtmlSaveOptionsData::isAllowNegativeIndent() const
{
    return m_AllowNegativeIndent;
}


void HtmlSaveOptionsData::setAllowNegativeIndent(bool value)
{
    m_AllowNegativeIndent = value;
    m_AllowNegativeIndentIsSet = true;
}
bool HtmlSaveOptionsData::allowNegativeIndentIsSet() const
{
    return m_AllowNegativeIndentIsSet;
}

void HtmlSaveOptionsData::unsetAllowNegativeIndent()
{
    m_AllowNegativeIndentIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getCssClassNamePrefix() const
{
    return m_CssClassNamePrefix;
}


void HtmlSaveOptionsData::setCssClassNamePrefix(utility::string_t value)
{
    m_CssClassNamePrefix = value;
    m_CssClassNamePrefixIsSet = true;
}
bool HtmlSaveOptionsData::cssClassNamePrefixIsSet() const
{
    return m_CssClassNamePrefixIsSet;
}

void HtmlSaveOptionsData::unsetCssClassNamePrefix()
{
    m_CssClassNamePrefixIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getCssStyleSheetFileName() const
{
    return m_CssStyleSheetFileName;
}


void HtmlSaveOptionsData::setCssStyleSheetFileName(utility::string_t value)
{
    m_CssStyleSheetFileName = value;
    m_CssStyleSheetFileNameIsSet = true;
}
bool HtmlSaveOptionsData::cssStyleSheetFileNameIsSet() const
{
    return m_CssStyleSheetFileNameIsSet;
}

void HtmlSaveOptionsData::unsetCssStyleSheetFileName()
{
    m_CssStyleSheetFileNameIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getCssStyleSheetType() const
{
    return m_CssStyleSheetType;
}


void HtmlSaveOptionsData::setCssStyleSheetType(utility::string_t value)
{
    m_CssStyleSheetType = value;
    m_CssStyleSheetTypeIsSet = true;
}
bool HtmlSaveOptionsData::cssStyleSheetTypeIsSet() const
{
    return m_CssStyleSheetTypeIsSet;
}

void HtmlSaveOptionsData::unsetCssStyleSheetType()
{
    m_CssStyleSheetTypeIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getDocumentSplitCriteria() const
{
    return m_DocumentSplitCriteria;
}


void HtmlSaveOptionsData::setDocumentSplitCriteria(utility::string_t value)
{
    m_DocumentSplitCriteria = value;
    m_DocumentSplitCriteriaIsSet = true;
}
bool HtmlSaveOptionsData::documentSplitCriteriaIsSet() const
{
    return m_DocumentSplitCriteriaIsSet;
}

void HtmlSaveOptionsData::unsetDocumentSplitCriteria()
{
    m_DocumentSplitCriteriaIsSet = false;
}

int32_t HtmlSaveOptionsData::getDocumentSplitHeadingLevel() const
{
    return m_DocumentSplitHeadingLevel;
}


void HtmlSaveOptionsData::setDocumentSplitHeadingLevel(int32_t value)
{
    m_DocumentSplitHeadingLevel = value;
    m_DocumentSplitHeadingLevelIsSet = true;
}
bool HtmlSaveOptionsData::documentSplitHeadingLevelIsSet() const
{
    return m_DocumentSplitHeadingLevelIsSet;
}

void HtmlSaveOptionsData::unsetDocumentSplitHeadingLevel()
{
    m_DocumentSplitHeadingLevelIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getEncoding() const
{
    return m_Encoding;
}


void HtmlSaveOptionsData::setEncoding(utility::string_t value)
{
    m_Encoding = value;
    m_EncodingIsSet = true;
}
bool HtmlSaveOptionsData::encodingIsSet() const
{
    return m_EncodingIsSet;
}

void HtmlSaveOptionsData::unsetEncoding()
{
    m_EncodingIsSet = false;
}

bool HtmlSaveOptionsData::isExportDocumentProperties() const
{
    return m_ExportDocumentProperties;
}


void HtmlSaveOptionsData::setExportDocumentProperties(bool value)
{
    m_ExportDocumentProperties = value;
    m_ExportDocumentPropertiesIsSet = true;
}
bool HtmlSaveOptionsData::exportDocumentPropertiesIsSet() const
{
    return m_ExportDocumentPropertiesIsSet;
}

void HtmlSaveOptionsData::unsetExportDocumentProperties()
{
    m_ExportDocumentPropertiesIsSet = false;
}

bool HtmlSaveOptionsData::isExportDropDownFormFieldAsText() const
{
    return m_ExportDropDownFormFieldAsText;
}


void HtmlSaveOptionsData::setExportDropDownFormFieldAsText(bool value)
{
    m_ExportDropDownFormFieldAsText = value;
    m_ExportDropDownFormFieldAsTextIsSet = true;
}
bool HtmlSaveOptionsData::exportDropDownFormFieldAsTextIsSet() const
{
    return m_ExportDropDownFormFieldAsTextIsSet;
}

void HtmlSaveOptionsData::unsetExportDropDownFormFieldAsText()
{
    m_ExportDropDownFormFieldAsTextIsSet = false;
}

bool HtmlSaveOptionsData::isExportFontResources() const
{
    return m_ExportFontResources;
}


void HtmlSaveOptionsData::setExportFontResources(bool value)
{
    m_ExportFontResources = value;
    m_ExportFontResourcesIsSet = true;
}
bool HtmlSaveOptionsData::exportFontResourcesIsSet() const
{
    return m_ExportFontResourcesIsSet;
}

void HtmlSaveOptionsData::unsetExportFontResources()
{
    m_ExportFontResourcesIsSet = false;
}

bool HtmlSaveOptionsData::isExportFontsAsBase64() const
{
    return m_ExportFontsAsBase64;
}


void HtmlSaveOptionsData::setExportFontsAsBase64(bool value)
{
    m_ExportFontsAsBase64 = value;
    m_ExportFontsAsBase64IsSet = true;
}
bool HtmlSaveOptionsData::exportFontsAsBase64IsSet() const
{
    return m_ExportFontsAsBase64IsSet;
}

void HtmlSaveOptionsData::unsetExportFontsAsBase64()
{
    m_ExportFontsAsBase64IsSet = false;
}

utility::string_t HtmlSaveOptionsData::getExportHeadersFootersMode() const
{
    return m_ExportHeadersFootersMode;
}


void HtmlSaveOptionsData::setExportHeadersFootersMode(utility::string_t value)
{
    m_ExportHeadersFootersMode = value;
    m_ExportHeadersFootersModeIsSet = true;
}
bool HtmlSaveOptionsData::exportHeadersFootersModeIsSet() const
{
    return m_ExportHeadersFootersModeIsSet;
}

void HtmlSaveOptionsData::unsetExportHeadersFootersMode()
{
    m_ExportHeadersFootersModeIsSet = false;
}

bool HtmlSaveOptionsData::isExportImagesAsBase64() const
{
    return m_ExportImagesAsBase64;
}


void HtmlSaveOptionsData::setExportImagesAsBase64(bool value)
{
    m_ExportImagesAsBase64 = value;
    m_ExportImagesAsBase64IsSet = true;
}
bool HtmlSaveOptionsData::exportImagesAsBase64IsSet() const
{
    return m_ExportImagesAsBase64IsSet;
}

void HtmlSaveOptionsData::unsetExportImagesAsBase64()
{
    m_ExportImagesAsBase64IsSet = false;
}

bool HtmlSaveOptionsData::isExportLanguageInformation() const
{
    return m_ExportLanguageInformation;
}


void HtmlSaveOptionsData::setExportLanguageInformation(bool value)
{
    m_ExportLanguageInformation = value;
    m_ExportLanguageInformationIsSet = true;
}
bool HtmlSaveOptionsData::exportLanguageInformationIsSet() const
{
    return m_ExportLanguageInformationIsSet;
}

void HtmlSaveOptionsData::unsetExportLanguageInformation()
{
    m_ExportLanguageInformationIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getExportListLabels() const
{
    return m_ExportListLabels;
}


void HtmlSaveOptionsData::setExportListLabels(utility::string_t value)
{
    m_ExportListLabels = value;
    m_ExportListLabelsIsSet = true;
}
bool HtmlSaveOptionsData::exportListLabelsIsSet() const
{
    return m_ExportListLabelsIsSet;
}

void HtmlSaveOptionsData::unsetExportListLabels()
{
    m_ExportListLabelsIsSet = false;
}

bool HtmlSaveOptionsData::isExportOriginalUrlForLinkedImages() const
{
    return m_ExportOriginalUrlForLinkedImages;
}


void HtmlSaveOptionsData::setExportOriginalUrlForLinkedImages(bool value)
{
    m_ExportOriginalUrlForLinkedImages = value;
    m_ExportOriginalUrlForLinkedImagesIsSet = true;
}
bool HtmlSaveOptionsData::exportOriginalUrlForLinkedImagesIsSet() const
{
    return m_ExportOriginalUrlForLinkedImagesIsSet;
}

void HtmlSaveOptionsData::unsetExportOriginalUrlForLinkedImages()
{
    m_ExportOriginalUrlForLinkedImagesIsSet = false;
}

bool HtmlSaveOptionsData::isExportPageMargins() const
{
    return m_ExportPageMargins;
}


void HtmlSaveOptionsData::setExportPageMargins(bool value)
{
    m_ExportPageMargins = value;
    m_ExportPageMarginsIsSet = true;
}
bool HtmlSaveOptionsData::exportPageMarginsIsSet() const
{
    return m_ExportPageMarginsIsSet;
}

void HtmlSaveOptionsData::unsetExportPageMargins()
{
    m_ExportPageMarginsIsSet = false;
}

bool HtmlSaveOptionsData::isExportPageSetup() const
{
    return m_ExportPageSetup;
}


void HtmlSaveOptionsData::setExportPageSetup(bool value)
{
    m_ExportPageSetup = value;
    m_ExportPageSetupIsSet = true;
}
bool HtmlSaveOptionsData::exportPageSetupIsSet() const
{
    return m_ExportPageSetupIsSet;
}

void HtmlSaveOptionsData::unsetExportPageSetup()
{
    m_ExportPageSetupIsSet = false;
}

bool HtmlSaveOptionsData::isExportRelativeFontSize() const
{
    return m_ExportRelativeFontSize;
}


void HtmlSaveOptionsData::setExportRelativeFontSize(bool value)
{
    m_ExportRelativeFontSize = value;
    m_ExportRelativeFontSizeIsSet = true;
}
bool HtmlSaveOptionsData::exportRelativeFontSizeIsSet() const
{
    return m_ExportRelativeFontSizeIsSet;
}

void HtmlSaveOptionsData::unsetExportRelativeFontSize()
{
    m_ExportRelativeFontSizeIsSet = false;
}

bool HtmlSaveOptionsData::isExportRoundtripInformation() const
{
    return m_ExportRoundtripInformation;
}


void HtmlSaveOptionsData::setExportRoundtripInformation(bool value)
{
    m_ExportRoundtripInformation = value;
    m_ExportRoundtripInformationIsSet = true;
}
bool HtmlSaveOptionsData::exportRoundtripInformationIsSet() const
{
    return m_ExportRoundtripInformationIsSet;
}

void HtmlSaveOptionsData::unsetExportRoundtripInformation()
{
    m_ExportRoundtripInformationIsSet = false;
}

bool HtmlSaveOptionsData::isExportTextBoxAsSvg() const
{
    return m_ExportTextBoxAsSvg;
}


void HtmlSaveOptionsData::setExportTextBoxAsSvg(bool value)
{
    m_ExportTextBoxAsSvg = value;
    m_ExportTextBoxAsSvgIsSet = true;
}
bool HtmlSaveOptionsData::exportTextBoxAsSvgIsSet() const
{
    return m_ExportTextBoxAsSvgIsSet;
}

void HtmlSaveOptionsData::unsetExportTextBoxAsSvg()
{
    m_ExportTextBoxAsSvgIsSet = false;
}

bool HtmlSaveOptionsData::isExportTextInputFormFieldAsText() const
{
    return m_ExportTextInputFormFieldAsText;
}


void HtmlSaveOptionsData::setExportTextInputFormFieldAsText(bool value)
{
    m_ExportTextInputFormFieldAsText = value;
    m_ExportTextInputFormFieldAsTextIsSet = true;
}
bool HtmlSaveOptionsData::exportTextInputFormFieldAsTextIsSet() const
{
    return m_ExportTextInputFormFieldAsTextIsSet;
}

void HtmlSaveOptionsData::unsetExportTextInputFormFieldAsText()
{
    m_ExportTextInputFormFieldAsTextIsSet = false;
}

bool HtmlSaveOptionsData::isExportTocPageNumbers() const
{
    return m_ExportTocPageNumbers;
}


void HtmlSaveOptionsData::setExportTocPageNumbers(bool value)
{
    m_ExportTocPageNumbers = value;
    m_ExportTocPageNumbersIsSet = true;
}
bool HtmlSaveOptionsData::exportTocPageNumbersIsSet() const
{
    return m_ExportTocPageNumbersIsSet;
}

void HtmlSaveOptionsData::unsetExportTocPageNumbers()
{
    m_ExportTocPageNumbersIsSet = false;
}

bool HtmlSaveOptionsData::isExportXhtmlTransitional() const
{
    return m_ExportXhtmlTransitional;
}


void HtmlSaveOptionsData::setExportXhtmlTransitional(bool value)
{
    m_ExportXhtmlTransitional = value;
    m_ExportXhtmlTransitionalIsSet = true;
}
bool HtmlSaveOptionsData::exportXhtmlTransitionalIsSet() const
{
    return m_ExportXhtmlTransitionalIsSet;
}

void HtmlSaveOptionsData::unsetExportXhtmlTransitional()
{
    m_ExportXhtmlTransitionalIsSet = false;
}

int32_t HtmlSaveOptionsData::getFontResourcesSubsettingSizeThreshold() const
{
    return m_FontResourcesSubsettingSizeThreshold;
}


void HtmlSaveOptionsData::setFontResourcesSubsettingSizeThreshold(int32_t value)
{
    m_FontResourcesSubsettingSizeThreshold = value;
    m_FontResourcesSubsettingSizeThresholdIsSet = true;
}
bool HtmlSaveOptionsData::fontResourcesSubsettingSizeThresholdIsSet() const
{
    return m_FontResourcesSubsettingSizeThresholdIsSet;
}

void HtmlSaveOptionsData::unsetFontResourcesSubsettingSizeThreshold()
{
    m_FontResourcesSubsettingSizeThresholdIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getFontsFolder() const
{
    return m_FontsFolder;
}


void HtmlSaveOptionsData::setFontsFolder(utility::string_t value)
{
    m_FontsFolder = value;
    m_FontsFolderIsSet = true;
}
bool HtmlSaveOptionsData::fontsFolderIsSet() const
{
    return m_FontsFolderIsSet;
}

void HtmlSaveOptionsData::unsetFontsFolder()
{
    m_FontsFolderIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getFontsFolderAlias() const
{
    return m_FontsFolderAlias;
}


void HtmlSaveOptionsData::setFontsFolderAlias(utility::string_t value)
{
    m_FontsFolderAlias = value;
    m_FontsFolderAliasIsSet = true;
}
bool HtmlSaveOptionsData::fontsFolderAliasIsSet() const
{
    return m_FontsFolderAliasIsSet;
}

void HtmlSaveOptionsData::unsetFontsFolderAlias()
{
    m_FontsFolderAliasIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getHtmlVersion() const
{
    return m_HtmlVersion;
}


void HtmlSaveOptionsData::setHtmlVersion(utility::string_t value)
{
    m_HtmlVersion = value;
    m_HtmlVersionIsSet = true;
}
bool HtmlSaveOptionsData::htmlVersionIsSet() const
{
    return m_HtmlVersionIsSet;
}

void HtmlSaveOptionsData::unsetHtmlVersion()
{
    m_HtmlVersionIsSet = false;
}

int32_t HtmlSaveOptionsData::getImageResolution() const
{
    return m_ImageResolution;
}


void HtmlSaveOptionsData::setImageResolution(int32_t value)
{
    m_ImageResolution = value;
    m_ImageResolutionIsSet = true;
}
bool HtmlSaveOptionsData::imageResolutionIsSet() const
{
    return m_ImageResolutionIsSet;
}

void HtmlSaveOptionsData::unsetImageResolution()
{
    m_ImageResolutionIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getImagesFolder() const
{
    return m_ImagesFolder;
}


void HtmlSaveOptionsData::setImagesFolder(utility::string_t value)
{
    m_ImagesFolder = value;
    m_ImagesFolderIsSet = true;
}
bool HtmlSaveOptionsData::imagesFolderIsSet() const
{
    return m_ImagesFolderIsSet;
}

void HtmlSaveOptionsData::unsetImagesFolder()
{
    m_ImagesFolderIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getImagesFolderAlias() const
{
    return m_ImagesFolderAlias;
}


void HtmlSaveOptionsData::setImagesFolderAlias(utility::string_t value)
{
    m_ImagesFolderAlias = value;
    m_ImagesFolderAliasIsSet = true;
}
bool HtmlSaveOptionsData::imagesFolderAliasIsSet() const
{
    return m_ImagesFolderAliasIsSet;
}

void HtmlSaveOptionsData::unsetImagesFolderAlias()
{
    m_ImagesFolderAliasIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getMetafileFormat() const
{
    return m_MetafileFormat;
}


void HtmlSaveOptionsData::setMetafileFormat(utility::string_t value)
{
    m_MetafileFormat = value;
    m_MetafileFormatIsSet = true;
}
bool HtmlSaveOptionsData::metafileFormatIsSet() const
{
    return m_MetafileFormatIsSet;
}

void HtmlSaveOptionsData::unsetMetafileFormat()
{
    m_MetafileFormatIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getOfficeMathOutputMode() const
{
    return m_OfficeMathOutputMode;
}


void HtmlSaveOptionsData::setOfficeMathOutputMode(utility::string_t value)
{
    m_OfficeMathOutputMode = value;
    m_OfficeMathOutputModeIsSet = true;
}
bool HtmlSaveOptionsData::officeMathOutputModeIsSet() const
{
    return m_OfficeMathOutputModeIsSet;
}

void HtmlSaveOptionsData::unsetOfficeMathOutputMode()
{
    m_OfficeMathOutputModeIsSet = false;
}

bool HtmlSaveOptionsData::isPrettyFormat() const
{
    return m_PrettyFormat;
}


void HtmlSaveOptionsData::setPrettyFormat(bool value)
{
    m_PrettyFormat = value;
    m_PrettyFormatIsSet = true;
}
bool HtmlSaveOptionsData::prettyFormatIsSet() const
{
    return m_PrettyFormatIsSet;
}

void HtmlSaveOptionsData::unsetPrettyFormat()
{
    m_PrettyFormatIsSet = false;
}

bool HtmlSaveOptionsData::isResolveFontNames() const
{
    return m_ResolveFontNames;
}


void HtmlSaveOptionsData::setResolveFontNames(bool value)
{
    m_ResolveFontNames = value;
    m_ResolveFontNamesIsSet = true;
}
bool HtmlSaveOptionsData::resolveFontNamesIsSet() const
{
    return m_ResolveFontNamesIsSet;
}

void HtmlSaveOptionsData::unsetResolveFontNames()
{
    m_ResolveFontNamesIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getResourceFolder() const
{
    return m_ResourceFolder;
}


void HtmlSaveOptionsData::setResourceFolder(utility::string_t value)
{
    m_ResourceFolder = value;
    m_ResourceFolderIsSet = true;
}
bool HtmlSaveOptionsData::resourceFolderIsSet() const
{
    return m_ResourceFolderIsSet;
}

void HtmlSaveOptionsData::unsetResourceFolder()
{
    m_ResourceFolderIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getResourceFolderAlias() const
{
    return m_ResourceFolderAlias;
}


void HtmlSaveOptionsData::setResourceFolderAlias(utility::string_t value)
{
    m_ResourceFolderAlias = value;
    m_ResourceFolderAliasIsSet = true;
}
bool HtmlSaveOptionsData::resourceFolderAliasIsSet() const
{
    return m_ResourceFolderAliasIsSet;
}

void HtmlSaveOptionsData::unsetResourceFolderAlias()
{
    m_ResourceFolderAliasIsSet = false;
}

bool HtmlSaveOptionsData::isScaleImageToShapeSize() const
{
    return m_ScaleImageToShapeSize;
}


void HtmlSaveOptionsData::setScaleImageToShapeSize(bool value)
{
    m_ScaleImageToShapeSize = value;
    m_ScaleImageToShapeSizeIsSet = true;
}
bool HtmlSaveOptionsData::scaleImageToShapeSizeIsSet() const
{
    return m_ScaleImageToShapeSizeIsSet;
}

void HtmlSaveOptionsData::unsetScaleImageToShapeSize()
{
    m_ScaleImageToShapeSizeIsSet = false;
}

utility::string_t HtmlSaveOptionsData::getTableWidthOutputMode() const
{
    return m_TableWidthOutputMode;
}


void HtmlSaveOptionsData::setTableWidthOutputMode(utility::string_t value)
{
    m_TableWidthOutputMode = value;
    m_TableWidthOutputModeIsSet = true;
}
bool HtmlSaveOptionsData::tableWidthOutputModeIsSet() const
{
    return m_TableWidthOutputModeIsSet;
}

void HtmlSaveOptionsData::unsetTableWidthOutputMode()
{
    m_TableWidthOutputModeIsSet = false;
}

}
}
}
}
}

