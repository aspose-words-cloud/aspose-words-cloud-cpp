/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PdfSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_PdfSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_PdfSaveOptionsData_H_


#include "DownsampleOptionsData.h"
#include "FixedPageSaveOptionsData.h"
#include "MetafileRenderingOptionsData.h"
#include "OutlineOptionsData.h"
#include "PdfDigitalSignatureDetailsData.h"
#include "PdfEncryptionDetailsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for pdf save options.
/// </summary>
class  PdfSaveOptionsData
    : public FixedPageSaveOptionsData
{
public:
    PdfSaveOptionsData();
    virtual ~PdfSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// PdfSaveOptionsData members

    /// <summary>
    /// Gets or sets specifies the PDF standards compliance level for output documents.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getCompliance() const;
    bool complianceIsSet() const;
    void unsetCompliance();
    void setCompliance(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether to convert footnote/endnote references in main text story into active hyperlinks. When clicked the hyperlink will lead to the corresponding footnote/endnote. Default is false.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isCreateNoteHyperlinks() const;
    bool createNoteHyperlinksIsSet() const;
    void unsetCreateNoteHyperlinks();
    void setCreateNoteHyperlinks(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining the way CustomDocumentProperties are exported to PDF file. Default value is None.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getCustomPropertiesExport() const;
    bool customPropertiesExportIsSet() const;
    void unsetCustomPropertiesExport();
    void setCustomPropertiesExport(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets DigitalSignatureDetails.
    /// </summary>
    <DATA_TYPE_START>PdfDigitalSignatureDetailsData<DATA_TYPE_END> getDigitalSignatureDetails() const;
    bool digitalSignatureDetailsIsSet() const;
    void unsetDigitalSignatureDetails();
    void setDigitalSignatureDetails(<DATA_TYPE_START>PdfDigitalSignatureDetailsData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a flag specifying whether the window’s title bar should display the document title taken from the Title entry of the document information dictionary.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isDisplayDocTitle() const;
    bool displayDocTitleIsSet() const;
    void unsetDisplayDocTitle();
    void setDisplayDocTitle(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets DownsampleOptions.
    /// </summary>
    <DATA_TYPE_START>DownsampleOptionsData<DATA_TYPE_END> getDownsampleOptions() const;
    bool downsampleOptionsIsSet() const;
    void unsetDownsampleOptions();
    void setDownsampleOptions(<DATA_TYPE_START>DownsampleOptionsData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets controls how fonts are embedded into the resulting PDF documents.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isEmbedFullFonts() const;
    bool embedFullFontsIsSet() const;
    void unsetEmbedFullFonts();
    void setEmbedFullFonts(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets EncryptionDetails.
    /// </summary>
    <DATA_TYPE_START>PdfEncryptionDetailsData<DATA_TYPE_END> getEncryptionDetails() const;
    bool encryptionDetailsIsSet() const;
    void unsetEncryptionDetails();
    void setEncryptionDetails(<DATA_TYPE_START>PdfEncryptionDetailsData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a flag specifying whether URI should be escaped before writing.             
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isEscapeUri() const;
    bool escapeUriIsSet() const;
    void unsetEscapeUri();
    void setEscapeUri(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines whether or not to export document structure.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isExportDocumentStructure() const;
    bool exportDocumentStructureIsSet() const;
    void unsetExportDocumentStructure();
    void setExportDocumentStructure(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the font embedding mode.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFontEmbeddingMode() const;
    bool fontEmbeddingModeIsSet() const;
    void unsetFontEmbeddingMode();
    void setFontEmbeddingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines how bookmarks in headers/footers are exported. The default value is Aspose.Words.Saving.HeaderFooterBookmarksExportMode.All.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getHeaderFooterBookmarksExportMode() const;
    bool headerFooterBookmarksExportModeIsSet() const;
    void unsetHeaderFooterBookmarksExportMode();
    void setHeaderFooterBookmarksExportMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies how the color space will be selected for the images in PDF document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getImageColorSpaceExportMode() const;
    bool imageColorSpaceExportModeIsSet() const;
    void unsetImageColorSpaceExportMode();
    void setImageColorSpaceExportMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies compression type to be used for all images in the document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getImageCompression() const;
    bool imageCompressionIsSet() const;
    void unsetImageCompression();
    void setImageCompression(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a flag indicating whether image interpolation shall be performed by a conforming reader. When false is specified, the flag is not written to the output document and the default behaviour of reader is used instead.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isInterpolateImages() const;
    bool interpolateImagesIsSet() const;
    void unsetInterpolateImages();
    void setInterpolateImages(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines whether hyperlinks in the output Pdf document are forced to be opened in a new window (or tab) of a browser.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isOpenHyperlinksInNewWindow() const;
    bool openHyperlinksInNewWindowIsSet() const;
    void unsetOpenHyperlinksInNewWindow();
    void setOpenHyperlinksInNewWindow(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets OutlineOptions.
    /// </summary>
    <DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> getOutlineOptions() const;
    bool outlineOptionsIsSet() const;
    void unsetOutlineOptions();
    void setOutlineOptions(<DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies how the PDF document should be displayed when opened in the PDF reader.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPageMode() const;
    bool pageModeIsSet() const;
    void unsetPageMode();
    void setPageMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value determining whether or not to preblend transparent images with black background color.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isPreblendImages() const;
    bool preblendImagesIsSet() const;
    void unsetPreblendImages();
    void setPreblendImages(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether to preserve Microsoft Word form fields as form fields in PDF or convert them to text.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isPreserveFormFields() const;
    bool preserveFormFieldsIsSet() const;
    void unsetPreserveFormFields();
    void setPreserveFormFields(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies compression type to be used for all textual content in the document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTextCompression() const;
    bool textCompressionIsSet() const;
    void unsetTextCompression();
    void setTextCompression(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines whether the document should be saved using a booklet printing layout.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseBookFoldPrintingSettings() const;
    bool useBookFoldPrintingSettingsIsSet() const;
    void unsetUseBookFoldPrintingSettings();
    void setUseBookFoldPrintingSettings(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines whether or not to substitute TrueType fonts Arial, Times New Roman, Courier New and Symbol with core PDF Type 1 fonts.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseCoreFonts() const;
    bool useCoreFontsIsSet() const;
    void unsetUseCoreFonts();
    void setUseCoreFonts(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines what type of zoom should be applied when a document is opened with a PDF viewer.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getZoomBehavior() const;
    bool zoomBehaviorIsSet() const;
    void unsetZoomBehavior();
    void setZoomBehavior(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines zoom factor (in percentages) for a document.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getZoomFactor() const;
    bool zoomFactorIsSet() const;
    void unsetZoomFactor();
    void setZoomFactor(<DATA_TYPE_START>int?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Compliance;
    bool m_ComplianceIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_CreateNoteHyperlinks;
    bool m_CreateNoteHyperlinksIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_CustomPropertiesExport;
    bool m_CustomPropertiesExportIsSet;
    <DATA_TYPE_START>PdfDigitalSignatureDetailsData<DATA_TYPE_END> m_DigitalSignatureDetails;
    bool m_DigitalSignatureDetailsIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_DisplayDocTitle;
    bool m_DisplayDocTitleIsSet;
    <DATA_TYPE_START>DownsampleOptionsData<DATA_TYPE_END> m_DownsampleOptions;
    bool m_DownsampleOptionsIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_EmbedFullFonts;
    bool m_EmbedFullFontsIsSet;
    <DATA_TYPE_START>PdfEncryptionDetailsData<DATA_TYPE_END> m_EncryptionDetails;
    bool m_EncryptionDetailsIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_EscapeUri;
    bool m_EscapeUriIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ExportDocumentStructure;
    bool m_ExportDocumentStructureIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FontEmbeddingMode;
    bool m_FontEmbeddingModeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_HeaderFooterBookmarksExportMode;
    bool m_HeaderFooterBookmarksExportModeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ImageColorSpaceExportMode;
    bool m_ImageColorSpaceExportModeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ImageCompression;
    bool m_ImageCompressionIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_InterpolateImages;
    bool m_InterpolateImagesIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_OpenHyperlinksInNewWindow;
    bool m_OpenHyperlinksInNewWindowIsSet;
    <DATA_TYPE_START>OutlineOptionsData<DATA_TYPE_END> m_OutlineOptions;
    bool m_OutlineOptionsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_PageMode;
    bool m_PageModeIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_PreblendImages;
    bool m_PreblendImagesIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_PreserveFormFields;
    bool m_PreserveFormFieldsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_TextCompression;
    bool m_TextCompressionIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseBookFoldPrintingSettings;
    bool m_UseBookFoldPrintingSettingsIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseCoreFonts;
    bool m_UseCoreFontsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ZoomBehavior;
    bool m_ZoomBehaviorIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_ZoomFactor;
    bool m_ZoomFactorIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PdfSaveOptionsData_H_ */
