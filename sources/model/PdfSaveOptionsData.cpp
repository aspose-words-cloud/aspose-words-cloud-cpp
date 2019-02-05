/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PdfSaveOptionsData.cpp">
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


#include "PdfSaveOptionsData.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

PdfSaveOptionsData::PdfSaveOptionsData()
{
    m_Compliance = _XPLATSTR("");
    m_ComplianceIsSet = false;
    m_CreateNoteHyperlinks = false;
    m_CreateNoteHyperlinksIsSet = false;
    m_CustomPropertiesExport = _XPLATSTR("");
    m_CustomPropertiesExportIsSet = false;
    m_DigitalSignatureDetailsIsSet = false;
    m_DisplayDocTitle = false;
    m_DisplayDocTitleIsSet = false;
    m_DownsampleOptionsIsSet = false;
    m_EmbedFullFonts = false;
    m_EmbedFullFontsIsSet = false;
    m_EncryptionDetailsIsSet = false;
    m_EscapeUri = false;
    m_EscapeUriIsSet = false;
    m_ExportDocumentStructure = false;
    m_ExportDocumentStructureIsSet = false;
    m_FontEmbeddingMode = _XPLATSTR("");
    m_FontEmbeddingModeIsSet = false;
    m_HeaderFooterBookmarksExportMode = _XPLATSTR("");
    m_HeaderFooterBookmarksExportModeIsSet = false;
    m_ImageColorSpaceExportMode = _XPLATSTR("");
    m_ImageColorSpaceExportModeIsSet = false;
    m_ImageCompression = _XPLATSTR("");
    m_ImageCompressionIsSet = false;
    m_OpenHyperlinksInNewWindow = false;
    m_OpenHyperlinksInNewWindowIsSet = false;
    m_OutlineOptionsIsSet = false;
    m_PageMode = _XPLATSTR("");
    m_PageModeIsSet = false;
    m_PreblendImages = false;
    m_PreblendImagesIsSet = false;
    m_PreserveFormFields = false;
    m_PreserveFormFieldsIsSet = false;
    m_TextCompression = _XPLATSTR("");
    m_TextCompressionIsSet = false;
    m_UseBookFoldPrintingSettings = false;
    m_UseBookFoldPrintingSettingsIsSet = false;
    m_UseCoreFonts = false;
    m_UseCoreFontsIsSet = false;
    m_ZoomBehavior = _XPLATSTR("");
    m_ZoomBehaviorIsSet = false;
    m_ZoomFactor = 0;
    m_ZoomFactorIsSet = false;
}

PdfSaveOptionsData::~PdfSaveOptionsData()
{
}

void PdfSaveOptionsData::validate()
{
    // TODO: implement validation
}

web::json::value PdfSaveOptionsData::toJson() const
{
    web::json::value val = this->FixedPageSaveOptionsData::toJson();

    if(m_ComplianceIsSet)
    {
        val[_XPLATSTR("Compliance")] = ModelBase::toJson(m_Compliance);
    }
    if(m_CreateNoteHyperlinksIsSet)
    {
        val[_XPLATSTR("CreateNoteHyperlinks")] = ModelBase::toJson(m_CreateNoteHyperlinks);
    }
    if(m_CustomPropertiesExportIsSet)
    {
        val[_XPLATSTR("CustomPropertiesExport")] = ModelBase::toJson(m_CustomPropertiesExport);
    }
    if(m_DigitalSignatureDetailsIsSet)
    {
        val[_XPLATSTR("DigitalSignatureDetails")] = ModelBase::toJson(m_DigitalSignatureDetails);
    }
    if(m_DisplayDocTitleIsSet)
    {
        val[_XPLATSTR("DisplayDocTitle")] = ModelBase::toJson(m_DisplayDocTitle);
    }
    if(m_DownsampleOptionsIsSet)
    {
        val[_XPLATSTR("DownsampleOptions")] = ModelBase::toJson(m_DownsampleOptions);
    }
    if(m_EmbedFullFontsIsSet)
    {
        val[_XPLATSTR("EmbedFullFonts")] = ModelBase::toJson(m_EmbedFullFonts);
    }
    if(m_EncryptionDetailsIsSet)
    {
        val[_XPLATSTR("EncryptionDetails")] = ModelBase::toJson(m_EncryptionDetails);
    }
    if(m_EscapeUriIsSet)
    {
        val[_XPLATSTR("EscapeUri")] = ModelBase::toJson(m_EscapeUri);
    }
    if(m_ExportDocumentStructureIsSet)
    {
        val[_XPLATSTR("ExportDocumentStructure")] = ModelBase::toJson(m_ExportDocumentStructure);
    }
    if(m_FontEmbeddingModeIsSet)
    {
        val[_XPLATSTR("FontEmbeddingMode")] = ModelBase::toJson(m_FontEmbeddingMode);
    }
    if(m_HeaderFooterBookmarksExportModeIsSet)
    {
        val[_XPLATSTR("HeaderFooterBookmarksExportMode")] = ModelBase::toJson(m_HeaderFooterBookmarksExportMode);
    }
    if(m_ImageColorSpaceExportModeIsSet)
    {
        val[_XPLATSTR("ImageColorSpaceExportMode")] = ModelBase::toJson(m_ImageColorSpaceExportMode);
    }
    if(m_ImageCompressionIsSet)
    {
        val[_XPLATSTR("ImageCompression")] = ModelBase::toJson(m_ImageCompression);
    }
    if(m_OpenHyperlinksInNewWindowIsSet)
    {
        val[_XPLATSTR("OpenHyperlinksInNewWindow")] = ModelBase::toJson(m_OpenHyperlinksInNewWindow);
    }
    if(m_OutlineOptionsIsSet)
    {
        val[_XPLATSTR("OutlineOptions")] = ModelBase::toJson(m_OutlineOptions);
    }
    if(m_PageModeIsSet)
    {
        val[_XPLATSTR("PageMode")] = ModelBase::toJson(m_PageMode);
    }
    if(m_PreblendImagesIsSet)
    {
        val[_XPLATSTR("PreblendImages")] = ModelBase::toJson(m_PreblendImages);
    }
    if(m_PreserveFormFieldsIsSet)
    {
        val[_XPLATSTR("PreserveFormFields")] = ModelBase::toJson(m_PreserveFormFields);
    }
    if(m_TextCompressionIsSet)
    {
        val[_XPLATSTR("TextCompression")] = ModelBase::toJson(m_TextCompression);
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        val[_XPLATSTR("UseBookFoldPrintingSettings")] = ModelBase::toJson(m_UseBookFoldPrintingSettings);
    }
    if(m_UseCoreFontsIsSet)
    {
        val[_XPLATSTR("UseCoreFonts")] = ModelBase::toJson(m_UseCoreFonts);
    }
    if(m_ZoomBehaviorIsSet)
    {
        val[_XPLATSTR("ZoomBehavior")] = ModelBase::toJson(m_ZoomBehavior);
    }
    if(m_ZoomFactorIsSet)
    {
        val[_XPLATSTR("ZoomFactor")] = ModelBase::toJson(m_ZoomFactor);
    }

    return val;
}

void PdfSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("Compliance")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Compliance")];
        if(!fieldValue.is_null())
        {
            setCompliance(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CreateNoteHyperlinks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CreateNoteHyperlinks")];
        if(!fieldValue.is_null())
        {
            setCreateNoteHyperlinks(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("CustomPropertiesExport")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("CustomPropertiesExport")];
        if(!fieldValue.is_null())
        {
            setCustomPropertiesExport(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("DigitalSignatureDetails")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DigitalSignatureDetails")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<PdfDigitalSignatureDetailsData> newItem(new PdfDigitalSignatureDetailsData());
            newItem->fromJson(fieldValue);
            setDigitalSignatureDetails( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("DisplayDocTitle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DisplayDocTitle")];
        if(!fieldValue.is_null())
        {
            setDisplayDocTitle(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("DownsampleOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DownsampleOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DownsampleOptionsData> newItem(new DownsampleOptionsData());
            newItem->fromJson(fieldValue);
            setDownsampleOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("EmbedFullFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EmbedFullFonts")];
        if(!fieldValue.is_null())
        {
            setEmbedFullFonts(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("EncryptionDetails")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EncryptionDetails")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<PdfEncryptionDetailsData> newItem(new PdfEncryptionDetailsData());
            newItem->fromJson(fieldValue);
            setEncryptionDetails( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("EscapeUri")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EscapeUri")];
        if(!fieldValue.is_null())
        {
            setEscapeUri(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportDocumentStructure")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportDocumentStructure")];
        if(!fieldValue.is_null())
        {
            setExportDocumentStructure(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("FontEmbeddingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FontEmbeddingMode")];
        if(!fieldValue.is_null())
        {
            setFontEmbeddingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("HeaderFooterBookmarksExportMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("HeaderFooterBookmarksExportMode")];
        if(!fieldValue.is_null())
        {
            setHeaderFooterBookmarksExportMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImageColorSpaceExportMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImageColorSpaceExportMode")];
        if(!fieldValue.is_null())
        {
            setImageColorSpaceExportMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ImageCompression")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ImageCompression")];
        if(!fieldValue.is_null())
        {
            setImageCompression(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OpenHyperlinksInNewWindow")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OpenHyperlinksInNewWindow")];
        if(!fieldValue.is_null())
        {
            setOpenHyperlinksInNewWindow(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OutlineOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OutlineOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromJson(fieldValue);
            setOutlineOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("PageMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PageMode")];
        if(!fieldValue.is_null())
        {
            setPageMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PreblendImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PreblendImages")];
        if(!fieldValue.is_null())
        {
            setPreblendImages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PreserveFormFields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PreserveFormFields")];
        if(!fieldValue.is_null())
        {
            setPreserveFormFields(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("TextCompression")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TextCompression")];
        if(!fieldValue.is_null())
        {
            setTextCompression(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UseBookFoldPrintingSettings")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseBookFoldPrintingSettings")];
        if(!fieldValue.is_null())
        {
            setUseBookFoldPrintingSettings(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UseCoreFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseCoreFonts")];
        if(!fieldValue.is_null())
        {
            setUseCoreFonts(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ZoomBehavior")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ZoomBehavior")];
        if(!fieldValue.is_null())
        {
            setZoomBehavior(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ZoomFactor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ZoomFactor")];
        if(!fieldValue.is_null())
        {
            setZoomFactor(ModelBase::int32_tFromJson(fieldValue));
        }
    }
}

void PdfSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
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
    if(m_JpegQualityIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("JpegQuality"), m_JpegQuality));
    }
    if(m_MetafileRenderingOptionsIsSet)
    {
        if (m_MetafileRenderingOptions.get())
        {
            m_MetafileRenderingOptions->toMultipart(multipart, _XPLATSTR("MetafileRenderingOptions."));
        }
        
    }
    if(m_NumeralFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("NumeralFormat"), m_NumeralFormat));
        
    }
    if(m_OptimizeOutputIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OptimizeOutput"), m_OptimizeOutput));
    }
    if(m_PageCountIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageCount"), m_PageCount));
    }
    if(m_PageIndexIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageIndex"), m_PageIndex));
    }
    if(m_ComplianceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Compliance"), m_Compliance));
        
    }
    if(m_CreateNoteHyperlinksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CreateNoteHyperlinks"), m_CreateNoteHyperlinks));
    }
    if(m_CustomPropertiesExportIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("CustomPropertiesExport"), m_CustomPropertiesExport));
        
    }
    if(m_DigitalSignatureDetailsIsSet)
    {
        if (m_DigitalSignatureDetails.get())
        {
            m_DigitalSignatureDetails->toMultipart(multipart, _XPLATSTR("DigitalSignatureDetails."));
        }
        
    }
    if(m_DisplayDocTitleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("DisplayDocTitle"), m_DisplayDocTitle));
    }
    if(m_DownsampleOptionsIsSet)
    {
        if (m_DownsampleOptions.get())
        {
            m_DownsampleOptions->toMultipart(multipart, _XPLATSTR("DownsampleOptions."));
        }
        
    }
    if(m_EmbedFullFontsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EmbedFullFonts"), m_EmbedFullFonts));
    }
    if(m_EncryptionDetailsIsSet)
    {
        if (m_EncryptionDetails.get())
        {
            m_EncryptionDetails->toMultipart(multipart, _XPLATSTR("EncryptionDetails."));
        }
        
    }
    if(m_EscapeUriIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("EscapeUri"), m_EscapeUri));
    }
    if(m_ExportDocumentStructureIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ExportDocumentStructure"), m_ExportDocumentStructure));
    }
    if(m_FontEmbeddingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FontEmbeddingMode"), m_FontEmbeddingMode));
        
    }
    if(m_HeaderFooterBookmarksExportModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("HeaderFooterBookmarksExportMode"), m_HeaderFooterBookmarksExportMode));
        
    }
    if(m_ImageColorSpaceExportModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImageColorSpaceExportMode"), m_ImageColorSpaceExportMode));
        
    }
    if(m_ImageCompressionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ImageCompression"), m_ImageCompression));
        
    }
    if(m_OpenHyperlinksInNewWindowIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OpenHyperlinksInNewWindow"), m_OpenHyperlinksInNewWindow));
    }
    if(m_OutlineOptionsIsSet)
    {
        if (m_OutlineOptions.get())
        {
            m_OutlineOptions->toMultipart(multipart, _XPLATSTR("OutlineOptions."));
        }
        
    }
    if(m_PageModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PageMode"), m_PageMode));
        
    }
    if(m_PreblendImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PreblendImages"), m_PreblendImages));
    }
    if(m_PreserveFormFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("PreserveFormFields"), m_PreserveFormFields));
    }
    if(m_TextCompressionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("TextCompression"), m_TextCompression));
        
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseBookFoldPrintingSettings"), m_UseBookFoldPrintingSettings));
    }
    if(m_UseCoreFontsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("UseCoreFonts"), m_UseCoreFonts));
    }
    if(m_ZoomBehaviorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ZoomBehavior"), m_ZoomBehavior));
        
    }
    if(m_ZoomFactorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ZoomFactor"), m_ZoomFactor));
    }
}

void PdfSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("JpegQuality")))
    {
        setJpegQuality(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("JpegQuality"))));
    }
    if(multipart->hasContent(_XPLATSTR("MetafileRenderingOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("MetafileRenderingOptions")))
        {
            std::shared_ptr<MetafileRenderingOptionsData> newItem(new MetafileRenderingOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("MetafileRenderingOptions."));
            setMetafileRenderingOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("NumeralFormat")))
    {
        setNumeralFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("NumeralFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("OptimizeOutput")))
    {
        setOptimizeOutput(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("OptimizeOutput"))));
    }
    if(multipart->hasContent(_XPLATSTR("PageCount")))
    {
        setPageCount(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("PageCount"))));
    }
    if(multipart->hasContent(_XPLATSTR("PageIndex")))
    {
        setPageIndex(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("PageIndex"))));
    }
    if(multipart->hasContent(_XPLATSTR("Compliance")))
    {
        setCompliance(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Compliance"))));
    }
    if(multipart->hasContent(_XPLATSTR("CreateNoteHyperlinks")))
    {
        setCreateNoteHyperlinks(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("CreateNoteHyperlinks"))));
    }
    if(multipart->hasContent(_XPLATSTR("CustomPropertiesExport")))
    {
        setCustomPropertiesExport(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CustomPropertiesExport"))));
    }
    if(multipart->hasContent(_XPLATSTR("DigitalSignatureDetails")))
    {
        if(multipart->hasContent(_XPLATSTR("DigitalSignatureDetails")))
        {
            std::shared_ptr<PdfDigitalSignatureDetailsData> newItem(new PdfDigitalSignatureDetailsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("DigitalSignatureDetails."));
            setDigitalSignatureDetails( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("DisplayDocTitle")))
    {
        setDisplayDocTitle(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("DisplayDocTitle"))));
    }
    if(multipart->hasContent(_XPLATSTR("DownsampleOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("DownsampleOptions")))
        {
            std::shared_ptr<DownsampleOptionsData> newItem(new DownsampleOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("DownsampleOptions."));
            setDownsampleOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("EmbedFullFonts")))
    {
        setEmbedFullFonts(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("EmbedFullFonts"))));
    }
    if(multipart->hasContent(_XPLATSTR("EncryptionDetails")))
    {
        if(multipart->hasContent(_XPLATSTR("EncryptionDetails")))
        {
            std::shared_ptr<PdfEncryptionDetailsData> newItem(new PdfEncryptionDetailsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("EncryptionDetails."));
            setEncryptionDetails( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("EscapeUri")))
    {
        setEscapeUri(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("EscapeUri"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportDocumentStructure")))
    {
        setExportDocumentStructure(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("ExportDocumentStructure"))));
    }
    if(multipart->hasContent(_XPLATSTR("FontEmbeddingMode")))
    {
        setFontEmbeddingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FontEmbeddingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("HeaderFooterBookmarksExportMode")))
    {
        setHeaderFooterBookmarksExportMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("HeaderFooterBookmarksExportMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImageColorSpaceExportMode")))
    {
        setImageColorSpaceExportMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ImageColorSpaceExportMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("ImageCompression")))
    {
        setImageCompression(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ImageCompression"))));
    }
    if(multipart->hasContent(_XPLATSTR("OpenHyperlinksInNewWindow")))
    {
        setOpenHyperlinksInNewWindow(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("OpenHyperlinksInNewWindow"))));
    }
    if(multipart->hasContent(_XPLATSTR("OutlineOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("OutlineOptions")))
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("OutlineOptions."));
            setOutlineOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("PageMode")))
    {
        setPageMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("PageMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("PreblendImages")))
    {
        setPreblendImages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("PreblendImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("PreserveFormFields")))
    {
        setPreserveFormFields(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("PreserveFormFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextCompression")))
    {
        setTextCompression(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextCompression"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseBookFoldPrintingSettings")))
    {
        setUseBookFoldPrintingSettings(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UseBookFoldPrintingSettings"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseCoreFonts")))
    {
        setUseCoreFonts(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("UseCoreFonts"))));
    }
    if(multipart->hasContent(_XPLATSTR("ZoomBehavior")))
    {
        setZoomBehavior(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ZoomBehavior"))));
    }
    if(multipart->hasContent(_XPLATSTR("ZoomFactor")))
    {
        setZoomFactor(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("ZoomFactor"))));
    }
}

utility::string_t PdfSaveOptionsData::getCompliance() const
{
    return m_Compliance;
}


void PdfSaveOptionsData::setCompliance(utility::string_t value)
{
    m_Compliance = value;
    m_ComplianceIsSet = true;
}
bool PdfSaveOptionsData::complianceIsSet() const
{
    return m_ComplianceIsSet;
}

void PdfSaveOptionsData::unsetCompliance()
{
    m_ComplianceIsSet = false;
}

bool PdfSaveOptionsData::isCreateNoteHyperlinks() const
{
    return m_CreateNoteHyperlinks;
}


void PdfSaveOptionsData::setCreateNoteHyperlinks(bool value)
{
    m_CreateNoteHyperlinks = value;
    m_CreateNoteHyperlinksIsSet = true;
}
bool PdfSaveOptionsData::createNoteHyperlinksIsSet() const
{
    return m_CreateNoteHyperlinksIsSet;
}

void PdfSaveOptionsData::unsetCreateNoteHyperlinks()
{
    m_CreateNoteHyperlinksIsSet = false;
}

utility::string_t PdfSaveOptionsData::getCustomPropertiesExport() const
{
    return m_CustomPropertiesExport;
}


void PdfSaveOptionsData::setCustomPropertiesExport(utility::string_t value)
{
    m_CustomPropertiesExport = value;
    m_CustomPropertiesExportIsSet = true;
}
bool PdfSaveOptionsData::customPropertiesExportIsSet() const
{
    return m_CustomPropertiesExportIsSet;
}

void PdfSaveOptionsData::unsetCustomPropertiesExport()
{
    m_CustomPropertiesExportIsSet = false;
}

std::shared_ptr<PdfDigitalSignatureDetailsData> PdfSaveOptionsData::getDigitalSignatureDetails() const
{
    return m_DigitalSignatureDetails;
}


void PdfSaveOptionsData::setDigitalSignatureDetails(std::shared_ptr<PdfDigitalSignatureDetailsData> value)
{
    m_DigitalSignatureDetails = value;
    m_DigitalSignatureDetailsIsSet = true;
}
bool PdfSaveOptionsData::digitalSignatureDetailsIsSet() const
{
    return m_DigitalSignatureDetailsIsSet;
}

void PdfSaveOptionsData::unsetDigitalSignatureDetails()
{
    m_DigitalSignatureDetailsIsSet = false;
}

bool PdfSaveOptionsData::isDisplayDocTitle() const
{
    return m_DisplayDocTitle;
}


void PdfSaveOptionsData::setDisplayDocTitle(bool value)
{
    m_DisplayDocTitle = value;
    m_DisplayDocTitleIsSet = true;
}
bool PdfSaveOptionsData::displayDocTitleIsSet() const
{
    return m_DisplayDocTitleIsSet;
}

void PdfSaveOptionsData::unsetDisplayDocTitle()
{
    m_DisplayDocTitleIsSet = false;
}

std::shared_ptr<DownsampleOptionsData> PdfSaveOptionsData::getDownsampleOptions() const
{
    return m_DownsampleOptions;
}


void PdfSaveOptionsData::setDownsampleOptions(std::shared_ptr<DownsampleOptionsData> value)
{
    m_DownsampleOptions = value;
    m_DownsampleOptionsIsSet = true;
}
bool PdfSaveOptionsData::downsampleOptionsIsSet() const
{
    return m_DownsampleOptionsIsSet;
}

void PdfSaveOptionsData::unsetDownsampleOptions()
{
    m_DownsampleOptionsIsSet = false;
}

bool PdfSaveOptionsData::isEmbedFullFonts() const
{
    return m_EmbedFullFonts;
}


void PdfSaveOptionsData::setEmbedFullFonts(bool value)
{
    m_EmbedFullFonts = value;
    m_EmbedFullFontsIsSet = true;
}
bool PdfSaveOptionsData::embedFullFontsIsSet() const
{
    return m_EmbedFullFontsIsSet;
}

void PdfSaveOptionsData::unsetEmbedFullFonts()
{
    m_EmbedFullFontsIsSet = false;
}

std::shared_ptr<PdfEncryptionDetailsData> PdfSaveOptionsData::getEncryptionDetails() const
{
    return m_EncryptionDetails;
}


void PdfSaveOptionsData::setEncryptionDetails(std::shared_ptr<PdfEncryptionDetailsData> value)
{
    m_EncryptionDetails = value;
    m_EncryptionDetailsIsSet = true;
}
bool PdfSaveOptionsData::encryptionDetailsIsSet() const
{
    return m_EncryptionDetailsIsSet;
}

void PdfSaveOptionsData::unsetEncryptionDetails()
{
    m_EncryptionDetailsIsSet = false;
}

bool PdfSaveOptionsData::isEscapeUri() const
{
    return m_EscapeUri;
}


void PdfSaveOptionsData::setEscapeUri(bool value)
{
    m_EscapeUri = value;
    m_EscapeUriIsSet = true;
}
bool PdfSaveOptionsData::escapeUriIsSet() const
{
    return m_EscapeUriIsSet;
}

void PdfSaveOptionsData::unsetEscapeUri()
{
    m_EscapeUriIsSet = false;
}

bool PdfSaveOptionsData::isExportDocumentStructure() const
{
    return m_ExportDocumentStructure;
}


void PdfSaveOptionsData::setExportDocumentStructure(bool value)
{
    m_ExportDocumentStructure = value;
    m_ExportDocumentStructureIsSet = true;
}
bool PdfSaveOptionsData::exportDocumentStructureIsSet() const
{
    return m_ExportDocumentStructureIsSet;
}

void PdfSaveOptionsData::unsetExportDocumentStructure()
{
    m_ExportDocumentStructureIsSet = false;
}

utility::string_t PdfSaveOptionsData::getFontEmbeddingMode() const
{
    return m_FontEmbeddingMode;
}


void PdfSaveOptionsData::setFontEmbeddingMode(utility::string_t value)
{
    m_FontEmbeddingMode = value;
    m_FontEmbeddingModeIsSet = true;
}
bool PdfSaveOptionsData::fontEmbeddingModeIsSet() const
{
    return m_FontEmbeddingModeIsSet;
}

void PdfSaveOptionsData::unsetFontEmbeddingMode()
{
    m_FontEmbeddingModeIsSet = false;
}

utility::string_t PdfSaveOptionsData::getHeaderFooterBookmarksExportMode() const
{
    return m_HeaderFooterBookmarksExportMode;
}


void PdfSaveOptionsData::setHeaderFooterBookmarksExportMode(utility::string_t value)
{
    m_HeaderFooterBookmarksExportMode = value;
    m_HeaderFooterBookmarksExportModeIsSet = true;
}
bool PdfSaveOptionsData::headerFooterBookmarksExportModeIsSet() const
{
    return m_HeaderFooterBookmarksExportModeIsSet;
}

void PdfSaveOptionsData::unsetHeaderFooterBookmarksExportMode()
{
    m_HeaderFooterBookmarksExportModeIsSet = false;
}

utility::string_t PdfSaveOptionsData::getImageColorSpaceExportMode() const
{
    return m_ImageColorSpaceExportMode;
}


void PdfSaveOptionsData::setImageColorSpaceExportMode(utility::string_t value)
{
    m_ImageColorSpaceExportMode = value;
    m_ImageColorSpaceExportModeIsSet = true;
}
bool PdfSaveOptionsData::imageColorSpaceExportModeIsSet() const
{
    return m_ImageColorSpaceExportModeIsSet;
}

void PdfSaveOptionsData::unsetImageColorSpaceExportMode()
{
    m_ImageColorSpaceExportModeIsSet = false;
}

utility::string_t PdfSaveOptionsData::getImageCompression() const
{
    return m_ImageCompression;
}


void PdfSaveOptionsData::setImageCompression(utility::string_t value)
{
    m_ImageCompression = value;
    m_ImageCompressionIsSet = true;
}
bool PdfSaveOptionsData::imageCompressionIsSet() const
{
    return m_ImageCompressionIsSet;
}

void PdfSaveOptionsData::unsetImageCompression()
{
    m_ImageCompressionIsSet = false;
}

bool PdfSaveOptionsData::isOpenHyperlinksInNewWindow() const
{
    return m_OpenHyperlinksInNewWindow;
}


void PdfSaveOptionsData::setOpenHyperlinksInNewWindow(bool value)
{
    m_OpenHyperlinksInNewWindow = value;
    m_OpenHyperlinksInNewWindowIsSet = true;
}
bool PdfSaveOptionsData::openHyperlinksInNewWindowIsSet() const
{
    return m_OpenHyperlinksInNewWindowIsSet;
}

void PdfSaveOptionsData::unsetOpenHyperlinksInNewWindow()
{
    m_OpenHyperlinksInNewWindowIsSet = false;
}

std::shared_ptr<OutlineOptionsData> PdfSaveOptionsData::getOutlineOptions() const
{
    return m_OutlineOptions;
}


void PdfSaveOptionsData::setOutlineOptions(std::shared_ptr<OutlineOptionsData> value)
{
    m_OutlineOptions = value;
    m_OutlineOptionsIsSet = true;
}
bool PdfSaveOptionsData::outlineOptionsIsSet() const
{
    return m_OutlineOptionsIsSet;
}

void PdfSaveOptionsData::unsetOutlineOptions()
{
    m_OutlineOptionsIsSet = false;
}

utility::string_t PdfSaveOptionsData::getPageMode() const
{
    return m_PageMode;
}


void PdfSaveOptionsData::setPageMode(utility::string_t value)
{
    m_PageMode = value;
    m_PageModeIsSet = true;
}
bool PdfSaveOptionsData::pageModeIsSet() const
{
    return m_PageModeIsSet;
}

void PdfSaveOptionsData::unsetPageMode()
{
    m_PageModeIsSet = false;
}

bool PdfSaveOptionsData::isPreblendImages() const
{
    return m_PreblendImages;
}


void PdfSaveOptionsData::setPreblendImages(bool value)
{
    m_PreblendImages = value;
    m_PreblendImagesIsSet = true;
}
bool PdfSaveOptionsData::preblendImagesIsSet() const
{
    return m_PreblendImagesIsSet;
}

void PdfSaveOptionsData::unsetPreblendImages()
{
    m_PreblendImagesIsSet = false;
}

bool PdfSaveOptionsData::isPreserveFormFields() const
{
    return m_PreserveFormFields;
}


void PdfSaveOptionsData::setPreserveFormFields(bool value)
{
    m_PreserveFormFields = value;
    m_PreserveFormFieldsIsSet = true;
}
bool PdfSaveOptionsData::preserveFormFieldsIsSet() const
{
    return m_PreserveFormFieldsIsSet;
}

void PdfSaveOptionsData::unsetPreserveFormFields()
{
    m_PreserveFormFieldsIsSet = false;
}

utility::string_t PdfSaveOptionsData::getTextCompression() const
{
    return m_TextCompression;
}


void PdfSaveOptionsData::setTextCompression(utility::string_t value)
{
    m_TextCompression = value;
    m_TextCompressionIsSet = true;
}
bool PdfSaveOptionsData::textCompressionIsSet() const
{
    return m_TextCompressionIsSet;
}

void PdfSaveOptionsData::unsetTextCompression()
{
    m_TextCompressionIsSet = false;
}

bool PdfSaveOptionsData::isUseBookFoldPrintingSettings() const
{
    return m_UseBookFoldPrintingSettings;
}


void PdfSaveOptionsData::setUseBookFoldPrintingSettings(bool value)
{
    m_UseBookFoldPrintingSettings = value;
    m_UseBookFoldPrintingSettingsIsSet = true;
}
bool PdfSaveOptionsData::useBookFoldPrintingSettingsIsSet() const
{
    return m_UseBookFoldPrintingSettingsIsSet;
}

void PdfSaveOptionsData::unsetUseBookFoldPrintingSettings()
{
    m_UseBookFoldPrintingSettingsIsSet = false;
}

bool PdfSaveOptionsData::isUseCoreFonts() const
{
    return m_UseCoreFonts;
}


void PdfSaveOptionsData::setUseCoreFonts(bool value)
{
    m_UseCoreFonts = value;
    m_UseCoreFontsIsSet = true;
}
bool PdfSaveOptionsData::useCoreFontsIsSet() const
{
    return m_UseCoreFontsIsSet;
}

void PdfSaveOptionsData::unsetUseCoreFonts()
{
    m_UseCoreFontsIsSet = false;
}

utility::string_t PdfSaveOptionsData::getZoomBehavior() const
{
    return m_ZoomBehavior;
}


void PdfSaveOptionsData::setZoomBehavior(utility::string_t value)
{
    m_ZoomBehavior = value;
    m_ZoomBehaviorIsSet = true;
}
bool PdfSaveOptionsData::zoomBehaviorIsSet() const
{
    return m_ZoomBehaviorIsSet;
}

void PdfSaveOptionsData::unsetZoomBehavior()
{
    m_ZoomBehaviorIsSet = false;
}

int32_t PdfSaveOptionsData::getZoomFactor() const
{
    return m_ZoomFactor;
}


void PdfSaveOptionsData::setZoomFactor(int32_t value)
{
    m_ZoomFactor = value;
    m_ZoomFactorIsSet = true;
}
bool PdfSaveOptionsData::zoomFactorIsSet() const
{
    return m_ZoomFactorIsSet;
}

void PdfSaveOptionsData::unsetZoomFactor()
{
    m_ZoomFactorIsSet = false;
}

}
}
}
}

