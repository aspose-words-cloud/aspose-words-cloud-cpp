/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="EpubSaveOptionsData.cpp">
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


#include "EpubSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

EpubSaveOptionsData::EpubSaveOptionsData()
{
    m_EpubNavigationMapLevel = 0;
    m_EpubNavigationMapLevelIsSet = false;
}

EpubSaveOptionsData::~EpubSaveOptionsData()
{
}

void EpubSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value EpubSaveOptionsData::toJson() const
{
    web::json::value val = this->HtmlSaveOptionsData::toJson();

    if(m_EpubNavigationMapLevelIsSet)
    {
        val[_XPLATSTR("EpubNavigationMapLevel")] = ModelBase::toJson(m_EpubNavigationMapLevel);
    }

    return val;
}

void EpubSaveOptionsData::fromJson(web::json::value& val)
{
    this->HtmlSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("EpubNavigationMapLevel")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EpubNavigationMapLevel")];
        if(!fieldValue.is_null())
        {
            setEpubNavigationMapLevel(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void EpubSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_EpubNavigationMapLevelIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EpubNavigationMapLevel"), m_EpubNavigationMapLevel));
    }
}

void EpubSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("EpubNavigationMapLevel")))
    {
        setEpubNavigationMapLevel(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("EpubNavigationMapLevel"))));
    }
}

int32_t EpubSaveOptionsData::getEpubNavigationMapLevel() const
{
    return m_EpubNavigationMapLevel;
}


void EpubSaveOptionsData::setEpubNavigationMapLevel(int32_t value)
{
    m_EpubNavigationMapLevel = value;
    m_EpubNavigationMapLevelIsSet = true;
}
bool EpubSaveOptionsData::epubNavigationMapLevelIsSet() const
{
    return m_EpubNavigationMapLevelIsSet;
}

void EpubSaveOptionsData::unsetEpubNavigationMapLevel()
{
    m_EpubNavigationMapLevelIsSet = false;
}

}
}
}
}
}

