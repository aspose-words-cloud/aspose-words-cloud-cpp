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
        val[_XPLATSTR("AllowNegativeIndent")] = ModelBase::toJson(m_AllowNegativeIndent);
    }
    if(m_CssClassNamePrefixIsSet)
    {
        val[_XPLATSTR("CssClassNamePrefix")] = ModelBase::toJson(m_CssClassNamePrefix);
    }
    if(m_CssStyleSheetFileNameIsSet)
    {
        val[_XPLATSTR("CssStyleSheetFileName")] = ModelBase::toJson(m_CssStyleSheetFileName);
    }
    if(m_CssStyleSheetTypeIsSet)
    {
        val[_XPLATSTR("CssStyleSheetType")] = ModelBase::toJson(m_CssStyleSheetType);
    }
    if(m_DocumentSplitCriteriaIsSet)
    {
        val[_XPLATSTR("DocumentSplitCriteria")] = ModelBase::toJson(m_DocumentSplitCriteria);
    }
    if(m_DocumentSplitHeadingLevelIsSet)
    {
        val[_XPLATSTR("DocumentSplitHeadingLevel")] = ModelBase::toJson(m_DocumentSplitHeadingLevel);
    }
    if(m_EncodingIsSet)
    {
        val[_XPLATSTR("Encoding")] = ModelBase::toJson(m_Encoding);
    }
    if(m_ExportDocumentPropertiesIsSet)
    {
        val[_XPLATSTR("ExportDocumentProperties")] = ModelBase::toJson(m_ExportDocumentProperties);
    }
    if(m_ExportDropDownFormFieldAsTextIsSet)
    {
        val[_XPLATSTR("ExportDropDownFormFieldAsText")] = ModelBase::toJson(m_ExportDropDownFormFieldAsText);
    }
    if(m_ExportFontResourcesIsSet)
    {
        val[_XPLATSTR("ExportFontResources")] = ModelBase::toJson(m_ExportFontResources);
    }
    if(m_ExportFontsAsBase64IsSet)
    {
        val[_XPLATSTR("ExportFontsAsBase64")] = ModelBase::toJson(m_ExportFontsAsBase64);
    }
    if(m_ExportHeadersFootersModeIsSet)
    {
        val[_XPLATSTR("ExportHeadersFootersMode")] = ModelBase::toJson(m_ExportHeadersFootersMode);
    }
    if(m_ExportImagesAsBase64IsSet)
    {
        val[_XPLATSTR("ExportImagesAsBase64")] = ModelBase::toJson(m_ExportImagesAsBase64);
    }
    if(m_ExportLanguageInformationIsSet)
    {
        val[_XPLATSTR("ExportLanguageInformation")] = ModelBase::toJson(m_ExportLanguageInformation);
    }
    if(m_ExportListLabelsIsSet)
    {
        val[_XPLATSTR("ExportListLabels")] = ModelBase::toJson(m_ExportListLabels);
    }
    if(m_ExportOriginalUrlForLinkedImagesIsSet)
    {
        val[_XPLATSTR("ExportOriginalUrlForLinkedImages")] = ModelBase::toJson(m_ExportOriginalUrlForLinkedImages);
    }
    if(m_ExportPageMarginsIsSet)
    {
        val[_XPLATSTR("ExportPageMargins")] = ModelBase::toJson(m_ExportPageMargins);
    }
    if(m_ExportPageSetupIsSet)
    {
        val[_XPLATSTR("ExportPageSetup")] = ModelBase::toJson(m_ExportPageSetup);
    }
    if(m_ExportRelativeFontSizeIsSet)
    {
        val[_XPLATSTR("ExportRelativeFontSize")] = ModelBase::toJson(m_ExportRelativeFontSize);
    }
    if(m_ExportRoundtripInformationIsSet)
    {
        val[_XPLATSTR("ExportRoundtripInformation")] = ModelBase::toJson(m_ExportRoundtripInformation);
    }
    if(m_ExportTextBoxAsSvgIsSet)
    {
        val[_XPLATSTR("ExportTextBoxAsSvg")] = ModelBase::toJson(m_ExportTextBoxAsSvg);
    }
    if(m_ExportTextInputFormFieldAsTextIsSet)
    {
        val[_XPLATSTR("ExportTextInputFormFieldAsText")] = ModelBase::toJson(m_ExportTextInputFormFieldAsText);
    }
    if(m_ExportTocPageNumbersIsSet)
    {
        val[_XPLATSTR("ExportTocPageNumbers")] = ModelBase::toJson(m_ExportTocPageNumbers);
    }
    if(m_ExportXhtmlTransitionalIsSet)
    {
        val[_XPLATSTR("ExportXhtmlTransitional")] = ModelBase::toJson(m_ExportXhtmlTransitional);
    }
    if(m_FontResourcesSubsettingSizeThresholdIsSet)
    {
        val[_XPLATSTR("FontResourcesSubsettingSizeThreshold")] = ModelBase::toJson(m_FontResourcesSubsettingSizeThreshold);
    }
    if(m_FontsFolderIsSet)
    {
        val[_XPLATSTR("FontsFolder")] = ModelBase::toJson(m_FontsFolder);
    }
    if(m_FontsFolderAliasIsSet)
    {
        val[_XPLATSTR("FontsFolderAlias")] = ModelBase::toJson(m_FontsFolderAlias);
    }
    if(m_HtmlVersionIsSet)
    {
        val[_XPLATSTR("HtmlVersion")] = ModelBase::toJson(m_HtmlVersion);
    }
    if(m_ImageResolutionIsSet)
    {
        val[_XPLATSTR("ImageResolution")] = ModelBase::toJson(m_ImageResolution);
    }
    if(m_ImagesFolderIsSet)
    {
        val[_XPLATSTR("ImagesFolder")] = ModelBase::toJson(m_ImagesFolder);
    }
    if(m_ImagesFolderAliasIsSet)
    {
        val[_XPLATSTR("ImagesFolderAlias")] = ModelBase::toJson(m_ImagesFolderAlias);
    }
    if(m_MetafileFormatIsSet)
    {
        val[_XPLATSTR("MetafileFormat")] = ModelBase::toJson(m_MetafileFormat);
    }
    if(m_OfficeMathOutputModeIsSet)
    {
        val[_XPLATSTR("OfficeMathOutputMode")] = ModelBase::toJson(m_OfficeMathOutputMode);
    }
    if(m_PrettyFormatIsSet)
    {
        val[_XPLATSTR("PrettyFormat")] = ModelBase::toJson(m_PrettyFormat);
    }
    if(m_ResolveFontNamesIsSet)
    {
        val[_XPLATSTR("ResolveFontNames")] = ModelBase::toJson(m_ResolveFontNames);
    }
    if(m_ResourceFolderIsSet)
    {
        val[_XPLATSTR("ResourceFolder")] = ModelBase::toJson(m_ResourceFolder);
    }
    if(m_ResourceFolderAliasIsSet)
    {
        val[_XPLATSTR("ResourceFolderAlias")] = ModelBase::toJson(m_ResourceFolderAlias);
    }
    if(m_ScaleImageToShapeSizeIsSet)
    {
        val[_XPLATSTR("ScaleImageToShapeSize")] = ModelBase::toJson(m_ScaleImageToShapeSize);
    }
    if(m_TableWidthOutputModeIsSet)
    {
        val[_XPLATSTR("TableWidthOutputMode")] = ModelBase::toJson(m_TableWidthOutputMode);
    }

    return val;
}

void HtmlSaveOptionsData::fromJson(web::json::value& val)
{
    this->SaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("AllowNegativeIndent")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("AllowNegativeIndent")];
        if(!fieldValue.is_null())
        {
            setAllowNegativeIndent(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CssClassNamePrefix")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CssClassNamePrefix")];
        if(!fieldValue.is_null())
        {
            setCssClassNamePrefix(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CssStyleSheetFileName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CssStyleSheetFileName")];
        if(!fieldValue.is_null())
        {
            setCssStyleSheetFileName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CssStyleSheetType")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CssStyleSheetType")];
        if(!fieldValue.is_null())
        {
            setCssStyleSheetType(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("DocumentSplitCriteria")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DocumentSplitCriteria")];
        if(!fieldValue.is_null())
        {
            setDocumentSplitCriteria(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("DocumentSplitHeadingLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DocumentSplitHeadingLevel")];
        if(!fieldValue.is_null())
        {
            setDocumentSplitHeadingLevel(ModelBase::int32_tFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("ExportDocumentProperties")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportDocumentProperties")];
        if(!fieldValue.is_null())
        {
            setExportDocumentProperties(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportDropDownFormFieldAsText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportDropDownFormFieldAsText")];
        if(!fieldValue.is_null())
        {
            setExportDropDownFormFieldAsText(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportFontResources")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportFontResources")];
        if(!fieldValue.is_null())
        {
            setExportFontResources(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportFontsAsBase64")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportFontsAsBase64")];
        if(!fieldValue.is_null())
        {
            setExportFontsAsBase64(ModelBase::boolFromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("ExportImagesAsBase64")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportImagesAsBase64")];
        if(!fieldValue.is_null())
        {
            setExportImagesAsBase64(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportLanguageInformation")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportLanguageInformation")];
        if(!fieldValue.is_null())
        {
            setExportLanguageInformation(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportListLabels")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportListLabels")];
        if(!fieldValue.is_null())
        {
            setExportListLabels(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportOriginalUrlForLinkedImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportOriginalUrlForLinkedImages")];
        if(!fieldValue.is_null())
        {
            setExportOriginalUrlForLinkedImages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportPageMargins")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportPageMargins")];
        if(!fieldValue.is_null())
        {
            setExportPageMargins(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportPageSetup")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportPageSetup")];
        if(!fieldValue.is_null())
        {
            setExportPageSetup(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportRelativeFontSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportRelativeFontSize")];
        if(!fieldValue.is_null())
        {
            setExportRelativeFontSize(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportRoundtripInformation")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportRoundtripInformation")];
        if(!fieldValue.is_null())
        {
            setExportRoundtripInformation(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportTextBoxAsSvg")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportTextBoxAsSvg")];
        if(!fieldValue.is_null())
        {
            setExportTextBoxAsSvg(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportTextInputFormFieldAsText")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportTextInputFormFieldAsText")];
        if(!fieldValue.is_null())
        {
            setExportTextInputFormFieldAsText(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportTocPageNumbers")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportTocPageNumbers")];
        if(!fieldValue.is_null())
        {
            setExportTocPageNumbers(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportXhtmlTransitional")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportXhtmlTransitional")];
        if(!fieldValue.is_null())
        {
            setExportXhtmlTransitional(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FontResourcesSubsettingSizeThreshold")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FontResourcesSubsettingSizeThreshold")];
        if(!fieldValue.is_null())
        {
            setFontResourcesSubsettingSizeThreshold(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FontsFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FontsFolder")];
        if(!fieldValue.is_null())
        {
            setFontsFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FontsFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FontsFolderAlias")];
        if(!fieldValue.is_null())
        {
            setFontsFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("HtmlVersion")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HtmlVersion")];
        if(!fieldValue.is_null())
        {
            setHtmlVersion(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImageResolution")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImageResolution")];
        if(!fieldValue.is_null())
        {
            setImageResolution(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImagesFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImagesFolder")];
        if(!fieldValue.is_null())
        {
            setImagesFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImagesFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImagesFolderAlias")];
        if(!fieldValue.is_null())
        {
            setImagesFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("MetafileFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("MetafileFormat")];
        if(!fieldValue.is_null())
        {
            setMetafileFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OfficeMathOutputMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OfficeMathOutputMode")];
        if(!fieldValue.is_null())
        {
            setOfficeMathOutputMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PrettyFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PrettyFormat")];
        if(!fieldValue.is_null())
        {
            setPrettyFormat(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ResolveFontNames")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResolveFontNames")];
        if(!fieldValue.is_null())
        {
            setResolveFontNames(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ResourceFolder")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourceFolder")];
        if(!fieldValue.is_null())
        {
            setResourceFolder(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ResourceFolderAlias")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ResourceFolderAlias")];
        if(!fieldValue.is_null())
        {
            setResourceFolderAlias(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ScaleImageToShapeSize")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ScaleImageToShapeSize")];
        if(!fieldValue.is_null())
        {
            setScaleImageToShapeSize(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TableWidthOutputMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TableWidthOutputMode")];
        if(!fieldValue.is_null())
        {
            setTableWidthOutputMode(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void HtmlSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

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
    if(m_AllowNegativeIndentIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("AllowNegativeIndent"), m_AllowNegativeIndent));
    }
    if(m_CssClassNamePrefixIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CssClassNamePrefix"), m_CssClassNamePrefix));
        
    }
    if(m_CssStyleSheetFileNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CssStyleSheetFileName"), m_CssStyleSheetFileName));
        
    }
    if(m_CssStyleSheetTypeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CssStyleSheetType"), m_CssStyleSheetType));
        
    }
    if(m_DocumentSplitCriteriaIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DocumentSplitCriteria"), m_DocumentSplitCriteria));
        
    }
    if(m_DocumentSplitHeadingLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DocumentSplitHeadingLevel"), m_DocumentSplitHeadingLevel));
    }
    if(m_EncodingIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Encoding"), m_Encoding));
        
    }
    if(m_ExportDocumentPropertiesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportDocumentProperties"), m_ExportDocumentProperties));
    }
    if(m_ExportDropDownFormFieldAsTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportDropDownFormFieldAsText"), m_ExportDropDownFormFieldAsText));
    }
    if(m_ExportFontResourcesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportFontResources"), m_ExportFontResources));
    }
    if(m_ExportFontsAsBase64IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportFontsAsBase64"), m_ExportFontsAsBase64));
    }
    if(m_ExportHeadersFootersModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportHeadersFootersMode"), m_ExportHeadersFootersMode));
        
    }
    if(m_ExportImagesAsBase64IsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportImagesAsBase64"), m_ExportImagesAsBase64));
    }
    if(m_ExportLanguageInformationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportLanguageInformation"), m_ExportLanguageInformation));
    }
    if(m_ExportListLabelsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportListLabels"), m_ExportListLabels));
        
    }
    if(m_ExportOriginalUrlForLinkedImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportOriginalUrlForLinkedImages"), m_ExportOriginalUrlForLinkedImages));
    }
    if(m_ExportPageMarginsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportPageMargins"), m_ExportPageMargins));
    }
    if(m_ExportPageSetupIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportPageSetup"), m_ExportPageSetup));
    }
    if(m_ExportRelativeFontSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportRelativeFontSize"), m_ExportRelativeFontSize));
    }
    if(m_ExportRoundtripInformationIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportRoundtripInformation"), m_ExportRoundtripInformation));
    }
    if(m_ExportTextBoxAsSvgIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportTextBoxAsSvg"), m_ExportTextBoxAsSvg));
    }
    if(m_ExportTextInputFormFieldAsTextIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportTextInputFormFieldAsText"), m_ExportTextInputFormFieldAsText));
    }
    if(m_ExportTocPageNumbersIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportTocPageNumbers"), m_ExportTocPageNumbers));
    }
    if(m_ExportXhtmlTransitionalIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportXhtmlTransitional"), m_ExportXhtmlTransitional));
    }
    if(m_FontResourcesSubsettingSizeThresholdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FontResourcesSubsettingSizeThreshold"), m_FontResourcesSubsettingSizeThreshold));
    }
    if(m_FontsFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FontsFolder"), m_FontsFolder));
        
    }
    if(m_FontsFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FontsFolderAlias"), m_FontsFolderAlias));
        
    }
    if(m_HtmlVersionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HtmlVersion"), m_HtmlVersion));
        
    }
    if(m_ImageResolutionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImageResolution"), m_ImageResolution));
    }
    if(m_ImagesFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImagesFolder"), m_ImagesFolder));
        
    }
    if(m_ImagesFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImagesFolderAlias"), m_ImagesFolderAlias));
        
    }
    if(m_MetafileFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("MetafileFormat"), m_MetafileFormat));
        
    }
    if(m_OfficeMathOutputModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OfficeMathOutputMode"), m_OfficeMathOutputMode));
        
    }
    if(m_PrettyFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PrettyFormat"), m_PrettyFormat));
    }
    if(m_ResolveFontNamesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResolveFontNames"), m_ResolveFontNames));
    }
    if(m_ResourceFolderIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourceFolder"), m_ResourceFolder));
        
    }
    if(m_ResourceFolderAliasIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ResourceFolderAlias"), m_ResourceFolderAlias));
        
    }
    if(m_ScaleImageToShapeSizeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ScaleImageToShapeSize"), m_ScaleImageToShapeSize));
    }
    if(m_TableWidthOutputModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TableWidthOutputMode"), m_TableWidthOutputMode));
        
    }
}

void HtmlSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
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
    if(multipart->hasContent(_XPLATSTR("AllowNegativeIndent")))
    {
        setAllowNegativeIndent(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("AllowNegativeIndent"))));
    }
    if(multipart->hasContent(_XPLATSTR("CssClassNamePrefix")))
    {
        setCssClassNamePrefix(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CssClassNamePrefix"))));
    }
    if(multipart->hasContent(_XPLATSTR("CssStyleSheetFileName")))
    {
        setCssStyleSheetFileName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CssStyleSheetFileName"))));
    }
    if(multipart->hasContent(_XPLATSTR("CssStyleSheetType")))
    {
        setCssStyleSheetType(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CssStyleSheetType"))));
    }
    if(multipart->hasContent(_XPLATSTR("DocumentSplitCriteria")))
    {
        setDocumentSplitCriteria(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("DocumentSplitCriteria"))));
    }
    if(multipart->hasContent(_XPLATSTR("DocumentSplitHeadingLevel")))
    {
        setDocumentSplitHeadingLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("DocumentSplitHeadingLevel"))));
    }
    if(multipart->hasContent(_XPLATSTR("Encoding")))
    {
        setEncoding(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Encoding"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportDocumentProperties")))
    {
        setExportDocumentProperties(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportDocumentProperties"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportDropDownFormFieldAsText")))
    {
        setExportDropDownFormFieldAsText(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportDropDownFormFieldAsText"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportFontResources")))
    {
        setExportFontResources(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportFontResources"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportFontsAsBase64")))
    {
        setExportFontsAsBase64(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportFontsAsBase64"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportHeadersFootersMode")))
    {
        setExportHeadersFootersMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ExportHeadersFootersMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportImagesAsBase64")))
    {
        setExportImagesAsBase64(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportImagesAsBase64"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportLanguageInformation")))
    {
        setExportLanguageInformation(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportLanguageInformation"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportListLabels")))
    {
        setExportListLabels(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ExportListLabels"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportOriginalUrlForLinkedImages")))
    {
        setExportOriginalUrlForLinkedImages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportOriginalUrlForLinkedImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportPageMargins")))
    {
        setExportPageMargins(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportPageMargins"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportPageSetup")))
    {
        setExportPageSetup(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportPageSetup"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportRelativeFontSize")))
    {
        setExportRelativeFontSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportRelativeFontSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportRoundtripInformation")))
    {
        setExportRoundtripInformation(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportRoundtripInformation"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportTextBoxAsSvg")))
    {
        setExportTextBoxAsSvg(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportTextBoxAsSvg"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportTextInputFormFieldAsText")))
    {
        setExportTextInputFormFieldAsText(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportTextInputFormFieldAsText"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportTocPageNumbers")))
    {
        setExportTocPageNumbers(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportTocPageNumbers"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportXhtmlTransitional")))
    {
        setExportXhtmlTransitional(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportXhtmlTransitional"))));
    }
    if(multipart->hasContent(_XPLATSTR("FontResourcesSubsettingSizeThreshold")))
    {
        setFontResourcesSubsettingSizeThreshold(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("FontResourcesSubsettingSizeThreshold"))));
    }
    if(multipart->hasContent(_XPLATSTR("FontsFolder")))
    {
        setFontsFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FontsFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("FontsFolderAlias")))
    {
        setFontsFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FontsFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("HtmlVersion")))
    {
        setHtmlVersion(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("HtmlVersion"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImageResolution")))
    {
        setImageResolution(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("ImageResolution"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImagesFolder")))
    {
        setImagesFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ImagesFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImagesFolderAlias")))
    {
        setImagesFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ImagesFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("MetafileFormat")))
    {
        setMetafileFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("MetafileFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("OfficeMathOutputMode")))
    {
        setOfficeMathOutputMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("OfficeMathOutputMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("PrettyFormat")))
    {
        setPrettyFormat(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("PrettyFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("ResolveFontNames")))
    {
        setResolveFontNames(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ResolveFontNames"))));
    }
    if(multipart->hasContent(_XPLATSTR("ResourceFolder")))
    {
        setResourceFolder(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ResourceFolder"))));
    }
    if(multipart->hasContent(_XPLATSTR("ResourceFolderAlias")))
    {
        setResourceFolderAlias(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ResourceFolderAlias"))));
    }
    if(multipart->hasContent(_XPLATSTR("ScaleImageToShapeSize")))
    {
        setScaleImageToShapeSize(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ScaleImageToShapeSize"))));
    }
    if(multipart->hasContent(_XPLATSTR("TableWidthOutputMode")))
    {
        setTableWidthOutputMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TableWidthOutputMode"))));
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

