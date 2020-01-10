/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PdfSaveOptionsData.cpp">
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


#include "PdfSaveOptionsData.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

PdfSaveOptionsData::PdfSaveOptionsData()
{
    m_Compliance = utility::conversions::to_string_t("");
    m_ComplianceIsSet = false;
    m_CreateNoteHyperlinks = false;
    m_CreateNoteHyperlinksIsSet = false;
    m_CustomPropertiesExport = utility::conversions::to_string_t("");
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
    m_FontEmbeddingMode = utility::conversions::to_string_t("");
    m_FontEmbeddingModeIsSet = false;
    m_HeaderFooterBookmarksExportMode = utility::conversions::to_string_t("");
    m_HeaderFooterBookmarksExportModeIsSet = false;
    m_ImageColorSpaceExportMode = utility::conversions::to_string_t("");
    m_ImageColorSpaceExportModeIsSet = false;
    m_ImageCompression = utility::conversions::to_string_t("");
    m_ImageCompressionIsSet = false;
    m_OpenHyperlinksInNewWindow = false;
    m_OpenHyperlinksInNewWindowIsSet = false;
    m_OutlineOptionsIsSet = false;
    m_PageMode = utility::conversions::to_string_t("");
    m_PageModeIsSet = false;
    m_PreblendImages = false;
    m_PreblendImagesIsSet = false;
    m_PreserveFormFields = false;
    m_PreserveFormFieldsIsSet = false;
    m_TextCompression = utility::conversions::to_string_t("");
    m_TextCompressionIsSet = false;
    m_UseBookFoldPrintingSettings = false;
    m_UseBookFoldPrintingSettingsIsSet = false;
    m_UseCoreFonts = false;
    m_UseCoreFontsIsSet = false;
    m_ZoomBehavior = utility::conversions::to_string_t("");
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
        val[_XPLATSTR("compliance")] = ModelBase::toJson(m_Compliance);
    }
    if(m_CreateNoteHyperlinksIsSet)
    {
        val[_XPLATSTR("createNoteHyperlinks")] = ModelBase::toJson(m_CreateNoteHyperlinks);
    }
    if(m_CustomPropertiesExportIsSet)
    {
        val[_XPLATSTR("customPropertiesExport")] = ModelBase::toJson(m_CustomPropertiesExport);
    }
    if(m_DigitalSignatureDetailsIsSet)
    {
        val[_XPLATSTR("digitalSignatureDetails")] = ModelBase::toJson(m_DigitalSignatureDetails);
    }
    if(m_DisplayDocTitleIsSet)
    {
        val[_XPLATSTR("displayDocTitle")] = ModelBase::toJson(m_DisplayDocTitle);
    }
    if(m_DownsampleOptionsIsSet)
    {
        val[_XPLATSTR("downsampleOptions")] = ModelBase::toJson(m_DownsampleOptions);
    }
    if(m_EmbedFullFontsIsSet)
    {
        val[_XPLATSTR("embedFullFonts")] = ModelBase::toJson(m_EmbedFullFonts);
    }
    if(m_EncryptionDetailsIsSet)
    {
        val[_XPLATSTR("encryptionDetails")] = ModelBase::toJson(m_EncryptionDetails);
    }
    if(m_EscapeUriIsSet)
    {
        val[_XPLATSTR("escapeUri")] = ModelBase::toJson(m_EscapeUri);
    }
    if(m_ExportDocumentStructureIsSet)
    {
        val[_XPLATSTR("exportDocumentStructure")] = ModelBase::toJson(m_ExportDocumentStructure);
    }
    if(m_FontEmbeddingModeIsSet)
    {
        val[_XPLATSTR("fontEmbeddingMode")] = ModelBase::toJson(m_FontEmbeddingMode);
    }
    if(m_HeaderFooterBookmarksExportModeIsSet)
    {
        val[_XPLATSTR("headerFooterBookmarksExportMode")] = ModelBase::toJson(m_HeaderFooterBookmarksExportMode);
    }
    if(m_ImageColorSpaceExportModeIsSet)
    {
        val[_XPLATSTR("imageColorSpaceExportMode")] = ModelBase::toJson(m_ImageColorSpaceExportMode);
    }
    if(m_ImageCompressionIsSet)
    {
        val[_XPLATSTR("imageCompression")] = ModelBase::toJson(m_ImageCompression);
    }
    if(m_OpenHyperlinksInNewWindowIsSet)
    {
        val[_XPLATSTR("openHyperlinksInNewWindow")] = ModelBase::toJson(m_OpenHyperlinksInNewWindow);
    }
    if(m_OutlineOptionsIsSet)
    {
        val[_XPLATSTR("outlineOptions")] = ModelBase::toJson(m_OutlineOptions);
    }
    if(m_PageModeIsSet)
    {
        val[_XPLATSTR("pageMode")] = ModelBase::toJson(m_PageMode);
    }
    if(m_PreblendImagesIsSet)
    {
        val[_XPLATSTR("preblendImages")] = ModelBase::toJson(m_PreblendImages);
    }
    if(m_PreserveFormFieldsIsSet)
    {
        val[_XPLATSTR("preserveFormFields")] = ModelBase::toJson(m_PreserveFormFields);
    }
    if(m_TextCompressionIsSet)
    {
        val[_XPLATSTR("textCompression")] = ModelBase::toJson(m_TextCompression);
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        val[_XPLATSTR("useBookFoldPrintingSettings")] = ModelBase::toJson(m_UseBookFoldPrintingSettings);
    }
    if(m_UseCoreFontsIsSet)
    {
        val[_XPLATSTR("useCoreFonts")] = ModelBase::toJson(m_UseCoreFonts);
    }
    if(m_ZoomBehaviorIsSet)
    {
        val[_XPLATSTR("zoomBehavior")] = ModelBase::toJson(m_ZoomBehavior);
    }
    if(m_ZoomFactorIsSet)
    {
        val[_XPLATSTR("zoomFactor")] = ModelBase::toJson(m_ZoomFactor);
    }

    return val;
}

void PdfSaveOptionsData::fromJson(web::json::value& val)
{
    this->FixedPageSaveOptionsData::fromJson(val);

    if(val.has_field(_XPLATSTR("compliance")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("compliance")];
        if(!fieldValue.is_null())
        {
            setCompliance(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("createNoteHyperlinks")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("createNoteHyperlinks")];
        if(!fieldValue.is_null())
        {
            setCreateNoteHyperlinks(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("customPropertiesExport")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("customPropertiesExport")];
        if(!fieldValue.is_null())
        {
            setCustomPropertiesExport(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("digitalSignatureDetails")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("digitalSignatureDetails")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<PdfDigitalSignatureDetailsData> newItem(new PdfDigitalSignatureDetailsData());
            newItem->fromJson(fieldValue);
            setDigitalSignatureDetails( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("displayDocTitle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("displayDocTitle")];
        if(!fieldValue.is_null())
        {
            setDisplayDocTitle(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("downsampleOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("downsampleOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<DownsampleOptionsData> newItem(new DownsampleOptionsData());
            newItem->fromJson(fieldValue);
            setDownsampleOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("embedFullFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("embedFullFonts")];
        if(!fieldValue.is_null())
        {
            setEmbedFullFonts(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("encryptionDetails")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("encryptionDetails")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<PdfEncryptionDetailsData> newItem(new PdfEncryptionDetailsData());
            newItem->fromJson(fieldValue);
            setEncryptionDetails( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("escapeUri")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("escapeUri")];
        if(!fieldValue.is_null())
        {
            setEscapeUri(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("exportDocumentStructure")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("exportDocumentStructure")];
        if(!fieldValue.is_null())
        {
            setExportDocumentStructure(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("fontEmbeddingMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("fontEmbeddingMode")];
        if(!fieldValue.is_null())
        {
            setFontEmbeddingMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("headerFooterBookmarksExportMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("headerFooterBookmarksExportMode")];
        if(!fieldValue.is_null())
        {
            setHeaderFooterBookmarksExportMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imageColorSpaceExportMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imageColorSpaceExportMode")];
        if(!fieldValue.is_null())
        {
            setImageColorSpaceExportMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("imageCompression")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("imageCompression")];
        if(!fieldValue.is_null())
        {
            setImageCompression(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("openHyperlinksInNewWindow")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("openHyperlinksInNewWindow")];
        if(!fieldValue.is_null())
        {
            setOpenHyperlinksInNewWindow(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("outlineOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("outlineOptions")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromJson(fieldValue);
            setOutlineOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("pageMode")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("pageMode")];
        if(!fieldValue.is_null())
        {
            setPageMode(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("preblendImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("preblendImages")];
        if(!fieldValue.is_null())
        {
            setPreblendImages(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("preserveFormFields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("preserveFormFields")];
        if(!fieldValue.is_null())
        {
            setPreserveFormFields(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("textCompression")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("textCompression")];
        if(!fieldValue.is_null())
        {
            setTextCompression(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("useBookFoldPrintingSettings")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("useBookFoldPrintingSettings")];
        if(!fieldValue.is_null())
        {
            setUseBookFoldPrintingSettings(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("useCoreFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("useCoreFonts")];
        if(!fieldValue.is_null())
        {
            setUseCoreFonts(ModelBase::boolFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("zoomBehavior")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("zoomBehavior")];
        if(!fieldValue.is_null())
        {
            setZoomBehavior(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("zoomFactor")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("zoomFactor")];
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
    if(m_ComplianceIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("compliance"), m_Compliance));
        
    }
    if(m_CreateNoteHyperlinksIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("createNoteHyperlinks"), m_CreateNoteHyperlinks));
    }
    if(m_CustomPropertiesExportIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("customPropertiesExport"), m_CustomPropertiesExport));
        
    }
    if(m_DigitalSignatureDetailsIsSet)
    {
        if (m_DigitalSignatureDetails.get())
        {
            m_DigitalSignatureDetails->toMultipart(multipart, _XPLATSTR("digitalSignatureDetails."));
        }
        
    }
    if(m_DisplayDocTitleIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("displayDocTitle"), m_DisplayDocTitle));
    }
    if(m_DownsampleOptionsIsSet)
    {
        if (m_DownsampleOptions.get())
        {
            m_DownsampleOptions->toMultipart(multipart, _XPLATSTR("downsampleOptions."));
        }
        
    }
    if(m_EmbedFullFontsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("embedFullFonts"), m_EmbedFullFonts));
    }
    if(m_EncryptionDetailsIsSet)
    {
        if (m_EncryptionDetails.get())
        {
            m_EncryptionDetails->toMultipart(multipart, _XPLATSTR("encryptionDetails."));
        }
        
    }
    if(m_EscapeUriIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("escapeUri"), m_EscapeUri));
    }
    if(m_ExportDocumentStructureIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("exportDocumentStructure"), m_ExportDocumentStructure));
    }
    if(m_FontEmbeddingModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("fontEmbeddingMode"), m_FontEmbeddingMode));
        
    }
    if(m_HeaderFooterBookmarksExportModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("headerFooterBookmarksExportMode"), m_HeaderFooterBookmarksExportMode));
        
    }
    if(m_ImageColorSpaceExportModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imageColorSpaceExportMode"), m_ImageColorSpaceExportMode));
        
    }
    if(m_ImageCompressionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("imageCompression"), m_ImageCompression));
        
    }
    if(m_OpenHyperlinksInNewWindowIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("openHyperlinksInNewWindow"), m_OpenHyperlinksInNewWindow));
    }
    if(m_OutlineOptionsIsSet)
    {
        if (m_OutlineOptions.get())
        {
            m_OutlineOptions->toMultipart(multipart, _XPLATSTR("outlineOptions."));
        }
        
    }
    if(m_PageModeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("pageMode"), m_PageMode));
        
    }
    if(m_PreblendImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("preblendImages"), m_PreblendImages));
    }
    if(m_PreserveFormFieldsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("preserveFormFields"), m_PreserveFormFields));
    }
    if(m_TextCompressionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("textCompression"), m_TextCompression));
        
    }
    if(m_UseBookFoldPrintingSettingsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("useBookFoldPrintingSettings"), m_UseBookFoldPrintingSettings));
    }
    if(m_UseCoreFontsIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("useCoreFonts"), m_UseCoreFonts));
    }
    if(m_ZoomBehaviorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("zoomBehavior"), m_ZoomBehavior));
        
    }
    if(m_ZoomFactorIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("zoomFactor"), m_ZoomFactor));
    }
}

void PdfSaveOptionsData::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
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
    if(multipart->hasContent(_XPLATSTR("compliance")))
    {
        setCompliance(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("compliance"))));
    }
    if(multipart->hasContent(_XPLATSTR("createNoteHyperlinks")))
    {
        setCreateNoteHyperlinks(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("createNoteHyperlinks"))));
    }
    if(multipart->hasContent(_XPLATSTR("customPropertiesExport")))
    {
        setCustomPropertiesExport(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("customPropertiesExport"))));
    }
    if(multipart->hasContent(_XPLATSTR("digitalSignatureDetails")))
    {
        if(multipart->hasContent(_XPLATSTR("digitalSignatureDetails")))
        {
            std::shared_ptr<PdfDigitalSignatureDetailsData> newItem(new PdfDigitalSignatureDetailsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("digitalSignatureDetails."));
            setDigitalSignatureDetails( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("displayDocTitle")))
    {
        setDisplayDocTitle(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("displayDocTitle"))));
    }
    if(multipart->hasContent(_XPLATSTR("downsampleOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("downsampleOptions")))
        {
            std::shared_ptr<DownsampleOptionsData> newItem(new DownsampleOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("downsampleOptions."));
            setDownsampleOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("embedFullFonts")))
    {
        setEmbedFullFonts(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("embedFullFonts"))));
    }
    if(multipart->hasContent(_XPLATSTR("encryptionDetails")))
    {
        if(multipart->hasContent(_XPLATSTR("encryptionDetails")))
        {
            std::shared_ptr<PdfEncryptionDetailsData> newItem(new PdfEncryptionDetailsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("encryptionDetails."));
            setEncryptionDetails( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("escapeUri")))
    {
        setEscapeUri(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("escapeUri"))));
    }
    if(multipart->hasContent(_XPLATSTR("exportDocumentStructure")))
    {
        setExportDocumentStructure(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("exportDocumentStructure"))));
    }
    if(multipart->hasContent(_XPLATSTR("fontEmbeddingMode")))
    {
        setFontEmbeddingMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("fontEmbeddingMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("headerFooterBookmarksExportMode")))
    {
        setHeaderFooterBookmarksExportMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("headerFooterBookmarksExportMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("imageColorSpaceExportMode")))
    {
        setImageColorSpaceExportMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("imageColorSpaceExportMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("imageCompression")))
    {
        setImageCompression(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("imageCompression"))));
    }
    if(multipart->hasContent(_XPLATSTR("openHyperlinksInNewWindow")))
    {
        setOpenHyperlinksInNewWindow(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("openHyperlinksInNewWindow"))));
    }
    if(multipart->hasContent(_XPLATSTR("outlineOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("outlineOptions")))
        {
            std::shared_ptr<OutlineOptionsData> newItem(new OutlineOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("outlineOptions."));
            setOutlineOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("pageMode")))
    {
        setPageMode(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("pageMode"))));
    }
    if(multipart->hasContent(_XPLATSTR("preblendImages")))
    {
        setPreblendImages(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("preblendImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("preserveFormFields")))
    {
        setPreserveFormFields(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("preserveFormFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("textCompression")))
    {
        setTextCompression(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("textCompression"))));
    }
    if(multipart->hasContent(_XPLATSTR("useBookFoldPrintingSettings")))
    {
        setUseBookFoldPrintingSettings(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("useBookFoldPrintingSettings"))));
    }
    if(multipart->hasContent(_XPLATSTR("useCoreFonts")))
    {
        setUseCoreFonts(ModelBase::boolFromHttpContent(multipart->getContent(_XPLATSTR("useCoreFonts"))));
    }
    if(multipart->hasContent(_XPLATSTR("zoomBehavior")))
    {
        setZoomBehavior(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("zoomBehavior"))));
    }
    if(multipart->hasContent(_XPLATSTR("zoomFactor")))
    {
        setZoomFactor(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("zoomFactor"))));
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
}

