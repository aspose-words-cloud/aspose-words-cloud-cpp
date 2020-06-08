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
    m_InterpolateImages = false;
    m_InterpolateImagesIsSet = false;
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
    if(m_InterpolateImagesIsSet)
    {
        val[_XPLATSTR("InterpolateImages")] = ModelBase::toJson(m_InterpolateImages);
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
            setCreateNoteHyperlinks(ModelBase::bool?FromJson(fieldValue));
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
            <DATA_TYPE_START>PdfDigitalSignatureDetailsData<DATA_TYPE_END> newItem(new PdfDigitalSignatureDetailsData());
            newItem->fromJson(fieldValue);
            setDigitalSignatureDetails( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("DisplayDocTitle")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DisplayDocTitle")];
        if(!fieldValue.is_null())
        {
            setDisplayDocTitle(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("DownsampleOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("DownsampleOptions")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>DownsampleOptionsData<DATA_TYPE_END> newItem(new DownsampleOptionsData());
            newItem->fromJson(fieldValue);
            setDownsampleOptions( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("EmbedFullFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EmbedFullFonts")];
        if(!fieldValue.is_null())
        {
            setEmbedFullFonts(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("EncryptionDetails")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EncryptionDetails")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>PdfEncryptionDetailsData<DATA_TYPE_END> newItem(new PdfEncryptionDetailsData());
            newItem->fromJson(fieldValue);
            setEncryptionDetails( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("EscapeUri")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("EscapeUri")];
        if(!fieldValue.is_null())
        {
            setEscapeUri(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ExportDocumentStructure")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ExportDocumentStructure")];
        if(!fieldValue.is_null())
        {
            setExportDocumentStructure(ModelBase::bool?FromJson(fieldValue));
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
    if(val.has_field(_XPLATSTR("InterpolateImages")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("InterpolateImages")];
        if(!fieldValue.is_null())
        {
            setInterpolateImages(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OpenHyperlinksInNewWindow")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OpenHyperlinksInNewWindow")];
        if(!fieldValue.is_null())
        {
            setOpenHyperlinksInNewWindow(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OutlineOptions")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OutlineOptions")];
        if(!fieldValue.is_null())
        {
            <DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> newItem(new OutlineOptionsData());
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
            setPreblendImages(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("PreserveFormFields")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("PreserveFormFields")];
        if(!fieldValue.is_null())
        {
            setPreserveFormFields(ModelBase::bool?FromJson(fieldValue));
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
            setUseBookFoldPrintingSettings(ModelBase::bool?FromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("UseCoreFonts")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("UseCoreFonts")];
        if(!fieldValue.is_null())
        {
            setUseCoreFonts(ModelBase::bool?FromJson(fieldValue));
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
            setZoomFactor(ModelBase::int?FromJson(fieldValue));
        }
    }
}

void PdfSaveOptionsData::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    FixedPageSaveOptionsData::toMultipart(multipart, prefix);
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

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
    if(m_InterpolateImagesIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("InterpolateImages"), m_InterpolateImages));
        
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
    FixedPageSaveOptionsData::fromMultiPart(multipart, prefix);

    if(multipart->hasContent(_XPLATSTR("Compliance")))
    {
        setCompliance(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Compliance"))));
    }
    if(multipart->hasContent(_XPLATSTR("CreateNoteHyperlinks")))
    {
        setCreateNoteHyperlinks(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("CreateNoteHyperlinks"))));
    }
    if(multipart->hasContent(_XPLATSTR("CustomPropertiesExport")))
    {
        setCustomPropertiesExport(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("CustomPropertiesExport"))));
    }
    if(multipart->hasContent(_XPLATSTR("DigitalSignatureDetails")))
    {
        if(multipart->hasContent(_XPLATSTR("DigitalSignatureDetails")))
        {
            <DATA_TYPE_START>PdfDigitalSignatureDetailsData<DATA_TYPE_END> newItem(new PdfDigitalSignatureDetailsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("DigitalSignatureDetails."));
            setDigitalSignatureDetails( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("DisplayDocTitle")))
    {
        setDisplayDocTitle(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("DisplayDocTitle"))));
    }
    if(multipart->hasContent(_XPLATSTR("DownsampleOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("DownsampleOptions")))
        {
            <DATA_TYPE_START>DownsampleOptionsData<DATA_TYPE_END> newItem(new DownsampleOptionsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("DownsampleOptions."));
            setDownsampleOptions( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("EmbedFullFonts")))
    {
        setEmbedFullFonts(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("EmbedFullFonts"))));
    }
    if(multipart->hasContent(_XPLATSTR("EncryptionDetails")))
    {
        if(multipart->hasContent(_XPLATSTR("EncryptionDetails")))
        {
            <DATA_TYPE_START>PdfEncryptionDetailsData<DATA_TYPE_END> newItem(new PdfEncryptionDetailsData());
            newItem->fromMultiPart(multipart, _XPLATSTR("EncryptionDetails."));
            setEncryptionDetails( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("EscapeUri")))
    {
        setEscapeUri(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("EscapeUri"))));
    }
    if(multipart->hasContent(_XPLATSTR("ExportDocumentStructure")))
    {
        setExportDocumentStructure(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("ExportDocumentStructure"))));
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
    if(multipart->hasContent(_XPLATSTR("InterpolateImages")))
    {
        setInterpolateImages(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("InterpolateImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("OpenHyperlinksInNewWindow")))
    {
        setOpenHyperlinksInNewWindow(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("OpenHyperlinksInNewWindow"))));
    }
    if(multipart->hasContent(_XPLATSTR("OutlineOptions")))
    {
        if(multipart->hasContent(_XPLATSTR("OutlineOptions")))
        {
            <DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> newItem(new OutlineOptionsData());
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
        setPreblendImages(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("PreblendImages"))));
    }
    if(multipart->hasContent(_XPLATSTR("PreserveFormFields")))
    {
        setPreserveFormFields(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("PreserveFormFields"))));
    }
    if(multipart->hasContent(_XPLATSTR("TextCompression")))
    {
        setTextCompression(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("TextCompression"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseBookFoldPrintingSettings")))
    {
        setUseBookFoldPrintingSettings(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("UseBookFoldPrintingSettings"))));
    }
    if(multipart->hasContent(_XPLATSTR("UseCoreFonts")))
    {
        setUseCoreFonts(ModelBase::bool?FromHttpContent(multipart->getContent(_XPLATSTR("UseCoreFonts"))));
    }
    if(multipart->hasContent(_XPLATSTR("ZoomBehavior")))
    {
        setZoomBehavior(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ZoomBehavior"))));
    }
    if(multipart->hasContent(_XPLATSTR("ZoomFactor")))
    {
        setZoomFactor(ModelBase::int?FromHttpContent(multipart->getContent(_XPLATSTR("ZoomFactor"))));
    }
}

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getCompliance() const
{
    return m_Compliance;
}


void PdfSaveOptionsData::setCompliance(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isCreateNoteHyperlinks() const
{
    return m_CreateNoteHyperlinks;
}


void PdfSaveOptionsData::setCreateNoteHyperlinks(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getCustomPropertiesExport() const
{
    return m_CustomPropertiesExport;
}


void PdfSaveOptionsData::setCustomPropertiesExport(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>PdfDigitalSignatureDetailsData<DATA_TYPE_END> PdfSaveOptionsData::getDigitalSignatureDetails() const
{
    return m_DigitalSignatureDetails;
}


void PdfSaveOptionsData::setDigitalSignatureDetails(<DATA_TYPE_START>PdfDigitalSignatureDetailsData<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isDisplayDocTitle() const
{
    return m_DisplayDocTitle;
}


void PdfSaveOptionsData::setDisplayDocTitle(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>DownsampleOptionsData<DATA_TYPE_END> PdfSaveOptionsData::getDownsampleOptions() const
{
    return m_DownsampleOptions;
}


void PdfSaveOptionsData::setDownsampleOptions(<DATA_TYPE_START>DownsampleOptionsData<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isEmbedFullFonts() const
{
    return m_EmbedFullFonts;
}


void PdfSaveOptionsData::setEmbedFullFonts(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>PdfEncryptionDetailsData<DATA_TYPE_END> PdfSaveOptionsData::getEncryptionDetails() const
{
    return m_EncryptionDetails;
}


void PdfSaveOptionsData::setEncryptionDetails(<DATA_TYPE_START>PdfEncryptionDetailsData<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isEscapeUri() const
{
    return m_EscapeUri;
}


void PdfSaveOptionsData::setEscapeUri(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isExportDocumentStructure() const
{
    return m_ExportDocumentStructure;
}


void PdfSaveOptionsData::setExportDocumentStructure(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getFontEmbeddingMode() const
{
    return m_FontEmbeddingMode;
}


void PdfSaveOptionsData::setFontEmbeddingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getHeaderFooterBookmarksExportMode() const
{
    return m_HeaderFooterBookmarksExportMode;
}


void PdfSaveOptionsData::setHeaderFooterBookmarksExportMode(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getImageColorSpaceExportMode() const
{
    return m_ImageColorSpaceExportMode;
}


void PdfSaveOptionsData::setImageColorSpaceExportMode(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getImageCompression() const
{
    return m_ImageCompression;
}


void PdfSaveOptionsData::setImageCompression(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isInterpolateImages() const
{
    return m_InterpolateImages;
}


void PdfSaveOptionsData::setInterpolateImages(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
{
    m_InterpolateImages = value;
    m_InterpolateImagesIsSet = true;
}
bool PdfSaveOptionsData::interpolateImagesIsSet() const
{
    return m_InterpolateImagesIsSet;
}

void PdfSaveOptionsData::unsetInterpolateImages()
{
    m_InterpolateImagesIsSet = false;
}

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isOpenHyperlinksInNewWindow() const
{
    return m_OpenHyperlinksInNewWindow;
}


void PdfSaveOptionsData::setOpenHyperlinksInNewWindow(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> PdfSaveOptionsData::getOutlineOptions() const
{
    return m_OutlineOptions;
}


void PdfSaveOptionsData::setOutlineOptions(<DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getPageMode() const
{
    return m_PageMode;
}


void PdfSaveOptionsData::setPageMode(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isPreblendImages() const
{
    return m_PreblendImages;
}


void PdfSaveOptionsData::setPreblendImages(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isPreserveFormFields() const
{
    return m_PreserveFormFields;
}


void PdfSaveOptionsData::setPreserveFormFields(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getTextCompression() const
{
    return m_TextCompression;
}


void PdfSaveOptionsData::setTextCompression(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isUseBookFoldPrintingSettings() const
{
    return m_UseBookFoldPrintingSettings;
}


void PdfSaveOptionsData::setUseBookFoldPrintingSettings(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>bool?<DATA_TYPE_END> PdfSaveOptionsData::isUseCoreFonts() const
{
    return m_UseCoreFonts;
}


void PdfSaveOptionsData::setUseCoreFonts(<DATA_TYPE_START>bool?<DATA_TYPE_END> value)
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

<DATA_TYPE_START>string<DATA_TYPE_END> PdfSaveOptionsData::getZoomBehavior() const
{
    return m_ZoomBehavior;
}


void PdfSaveOptionsData::setZoomBehavior(<DATA_TYPE_START>string<DATA_TYPE_END> value)
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

<DATA_TYPE_START>int?<DATA_TYPE_END> PdfSaveOptionsData::getZoomFactor() const
{
    return m_ZoomFactor;
}


void PdfSaveOptionsData::setZoomFactor(<DATA_TYPE_START>int?<DATA_TYPE_END> value)
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

