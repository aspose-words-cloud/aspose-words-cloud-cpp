/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="MhtmlSaveOptionsData.cpp">
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


#include "MhtmlSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

MhtmlSaveOptionsData::MhtmlSaveOptionsData()
{
    m_ExportCidUrlsForMhtmlResources = false;
    m_ExportCidUrlsForMhtmlResourcesIsSet = false;
}

MhtmlSaveOptionsData::~MhtmlSaveOptionsData()
{
}

void MhtmlSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value MhtmlSaveOptionsData::toJson() const
{
    web::json::value val = this->HtmlSaveOptionsData::toJson();

    if(m_ExportCidUrlsForMhtmlResourcesIsSet)
    {
        val[_XPLATSTR("exportCidUrlsForMhtmlResources")] = ModelBase::toJson(m_ExportCidUrlsForMhtmlResources);
    }

    return val;
}

void MhtmlSaveOptionsData::fromJson(web::json::value& val)
{
    this->HtmlSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("exportCidUrlsForMhtmlResources")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportCidUrlsForMhtmlResources")];
        if(!fieldValue.is_null())
        {
            setExportCidUrlsForMhtmlResources(ModelBase::boolFromJson(fieldValue));
        }
    }
}

void MhtmlSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_ExportCidUrlsForMhtmlResourcesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportCidUrlsForMhtmlResources"), m_ExportCidUrlsForMhtmlResources));
    }
}

void MhtmlSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("exportCidUrlsForMhtmlResources")))
    {
        setExportCidUrlsForMhtmlResources(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportCidUrlsForMhtmlResources"))));
    }
}

bool MhtmlSaveOptionsData::isExportCidUrlsForMhtmlResources() const
{
    return m_ExportCidUrlsForMhtmlResources;
}


void MhtmlSaveOptionsData::setExportCidUrlsForMhtmlResources(bool value)
{
    m_ExportCidUrlsForMhtmlResources = value;
    m_ExportCidUrlsForMhtmlResourcesIsSet = true;
}
bool MhtmlSaveOptionsData::exportCidUrlsForMhtmlResourcesIsSet() const
{
    return m_ExportCidUrlsForMhtmlResourcesIsSet;
}

void MhtmlSaveOptionsData::unsetExportCidUrlsForMhtmlResources()
{
    m_ExportCidUrlsForMhtmlResourcesIsSet = false;
}

}
}
}
}
}

