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
    utility::string_t getCompliance() const;
    bool complianceIsSet() const;
    void unsetCompliance();
    void setCompliance(utility::string_t value);
    /// <summary>
    /// Gets or sets specifies whether to convert footnote/endnote references in main text story into active hyperlinks. When clicked the hyperlink will lead to the corresponding footnote/endnote. Default is false.
    /// </summary>
    bool isCreateNoteHyperlinks() const;
    bool createNoteHyperlinksIsSet() const;
    void unsetCreateNoteHyperlinks();
    void setCreateNoteHyperlinks(bool value);
    /// <summary>
    /// Gets or sets a value determining the way CustomDocumentProperties are exported to PDF file. Default value is None.
    /// </summary>
    utility::string_t getCustomPropertiesExport() const;
    bool customPropertiesExportIsSet() const;
    void unsetCustomPropertiesExport();
    void setCustomPropertiesExport(utility::string_t value);
    /// <summary>
    /// Gets or sets DigitalSignatureDetails.
    /// </summary>
    std::shared_ptr<PdfDigitalSignatureDetailsData> getDigitalSignatureDetails() const;
    bool digitalSignatureDetailsIsSet() const;
    void unsetDigitalSignatureDetails();
    void setDigitalSignatureDetails(std::shared_ptr<PdfDigitalSignatureDetailsData> value);
    /// <summary>
    /// Gets or sets a flag specifying whether the window’s title bar should display the document title taken from the Title entry of the document information dictionary.
    /// </summary>
    bool isDisplayDocTitle() const;
    bool displayDocTitleIsSet() const;
    void unsetDisplayDocTitle();
    void setDisplayDocTitle(bool value);
    /// <summary>
    /// Gets or sets DownsampleOptions.
    /// </summary>
    std::shared_ptr<DownsampleOptionsData> getDownsampleOptions() const;
    bool downsampleOptionsIsSet() const;
    void unsetDownsampleOptions();
    void setDownsampleOptions(std::shared_ptr<DownsampleOptionsData> value);
    /// <summary>
    /// Gets or sets controls how fonts are embedded into the resulting PDF documents.
    /// </summary>
    bool isEmbedFullFonts() const;
    bool embedFullFontsIsSet() const;
    void unsetEmbedFullFonts();
    void setEmbedFullFonts(bool value);
    /// <summary>
    /// Gets or sets EncryptionDetails.
    /// </summary>
    std::shared_ptr<PdfEncryptionDetailsData> getEncryptionDetails() const;
    bool encryptionDetailsIsSet() const;
    void unsetEncryptionDetails();
    void setEncryptionDetails(std::shared_ptr<PdfEncryptionDetailsData> value);
    /// <summary>
    /// Gets or sets a flag specifying whether URI should be escaped before writing.             
    /// </summary>
    bool isEscapeUri() const;
    bool escapeUriIsSet() const;
    void unsetEscapeUri();
    void setEscapeUri(bool value);
    /// <summary>
    /// Gets or sets determines whether or not to export document structure.
    /// </summary>
    bool isExportDocumentStructure() const;
    bool exportDocumentStructureIsSet() const;
    void unsetExportDocumentStructure();
    void setExportDocumentStructure(bool value);
    /// <summary>
    /// Gets or sets specifies the font embedding mode.
    /// </summary>
    utility::string_t getFontEmbeddingMode() const;
    bool fontEmbeddingModeIsSet() const;
    void unsetFontEmbeddingMode();
    void setFontEmbeddingMode(utility::string_t value);
    /// <summary>
    /// Gets or sets determines how bookmarks in headers/footers are exported. The default value is Aspose.Words.Saving.HeaderFooterBookmarksExportMode.All.
    /// </summary>
    utility::string_t getHeaderFooterBookmarksExportMode() const;
    bool headerFooterBookmarksExportModeIsSet() const;
    void unsetHeaderFooterBookmarksExportMode();
    void setHeaderFooterBookmarksExportMode(utility::string_t value);
    /// <summary>
    /// Gets or sets specifies how the color space will be selected for the images in PDF document.
    /// </summary>
    utility::string_t getImageColorSpaceExportMode() const;
    bool imageColorSpaceExportModeIsSet() const;
    void unsetImageColorSpaceExportMode();
    void setImageColorSpaceExportMode(utility::string_t value);
    /// <summary>
    /// Gets or sets specifies compression type to be used for all images in the document.
    /// </summary>
    utility::string_t getImageCompression() const;
    bool imageCompressionIsSet() const;
    void unsetImageCompression();
    void setImageCompression(utility::string_t value);
    /// <summary>
    /// Gets or sets a flag indicating whether image interpolation shall be performed by a conforming reader. When false is specified, the flag is not written to the output document and the default behaviour of reader is used instead.
    /// </summary>
    bool isInterpolateImages() const;
    bool interpolateImagesIsSet() const;
    void unsetInterpolateImages();
    void setInterpolateImages(bool value);
    /// <summary>
    /// Gets or sets determines whether hyperlinks in the output Pdf document are forced to be opened in a new window (or tab) of a browser.
    /// </summary>
    bool isOpenHyperlinksInNewWindow() const;
    bool openHyperlinksInNewWindowIsSet() const;
    void unsetOpenHyperlinksInNewWindow();
    void setOpenHyperlinksInNewWindow(bool value);
    /// <summary>
    /// Gets or sets OutlineOptions.
    /// </summary>
    std::shared_ptr<OutlineOptionsData> getOutlineOptions() const;
    bool outlineOptionsIsSet() const;
    void unsetOutlineOptions();
    void setOutlineOptions(std::shared_ptr<OutlineOptionsData> value);
    /// <summary>
    /// Gets or sets specifies how the PDF document should be displayed when opened in the PDF reader.
    /// </summary>
    utility::string_t getPageMode() const;
    bool pageModeIsSet() const;
    void unsetPageMode();
    void setPageMode(utility::string_t value);
    /// <summary>
    /// Gets or sets a value determining whether or not to preblend transparent images with black background color.
    /// </summary>
    bool isPreblendImages() const;
    bool preblendImagesIsSet() const;
    void unsetPreblendImages();
    void setPreblendImages(bool value);
    /// <summary>
    /// Gets or sets specifies whether to preserve Microsoft Word form fields as form fields in PDF or convert them to text.
    /// </summary>
    bool isPreserveFormFields() const;
    bool preserveFormFieldsIsSet() const;
    void unsetPreserveFormFields();
    void setPreserveFormFields(bool value);
    /// <summary>
    /// Gets or sets specifies compression type to be used for all textual content in the document.
    /// </summary>
    utility::string_t getTextCompression() const;
    bool textCompressionIsSet() const;
    void unsetTextCompression();
    void setTextCompression(utility::string_t value);
    /// <summary>
    /// Gets or sets determines whether the document should be saved using a booklet printing layout.
    /// </summary>
    bool isUseBookFoldPrintingSettings() const;
    bool useBookFoldPrintingSettingsIsSet() const;
    void unsetUseBookFoldPrintingSettings();
    void setUseBookFoldPrintingSettings(bool value);
    /// <summary>
    /// Gets or sets determines whether or not to substitute TrueType fonts Arial, Times New Roman, Courier New and Symbol with core PDF Type 1 fonts.
    /// </summary>
    bool isUseCoreFonts() const;
    bool useCoreFontsIsSet() const;
    void unsetUseCoreFonts();
    void setUseCoreFonts(bool value);
    /// <summary>
    /// Gets or sets determines what type of zoom should be applied when a document is opened with a PDF viewer.
    /// </summary>
    utility::string_t getZoomBehavior() const;
    bool zoomBehaviorIsSet() const;
    void unsetZoomBehavior();
    void setZoomBehavior(utility::string_t value);
    /// <summary>
    /// Gets or sets determines zoom factor (in percentages) for a document.
    /// </summary>
    int32_t getZoomFactor() const;
    bool zoomFactorIsSet() const;
    void unsetZoomFactor();
    void setZoomFactor(int32_t value);

protected:
    utility::string_t m_Compliance;
    bool m_ComplianceIsSet;
    bool m_CreateNoteHyperlinks;
    bool m_CreateNoteHyperlinksIsSet;
    utility::string_t m_CustomPropertiesExport;
    bool m_CustomPropertiesExportIsSet;
    std::shared_ptr<PdfDigitalSignatureDetailsData> m_DigitalSignatureDetails;
    bool m_DigitalSignatureDetailsIsSet;
    bool m_DisplayDocTitle;
    bool m_DisplayDocTitleIsSet;
    std::shared_ptr<DownsampleOptionsData> m_DownsampleOptions;
    bool m_DownsampleOptionsIsSet;
    bool m_EmbedFullFonts;
    bool m_EmbedFullFontsIsSet;
    std::shared_ptr<PdfEncryptionDetailsData> m_EncryptionDetails;
    bool m_EncryptionDetailsIsSet;
    bool m_EscapeUri;
    bool m_EscapeUriIsSet;
    bool m_ExportDocumentStructure;
    bool m_ExportDocumentStructureIsSet;
    utility::string_t m_FontEmbeddingMode;
    bool m_FontEmbeddingModeIsSet;
    utility::string_t m_HeaderFooterBookmarksExportMode;
    bool m_HeaderFooterBookmarksExportModeIsSet;
    utility::string_t m_ImageColorSpaceExportMode;
    bool m_ImageColorSpaceExportModeIsSet;
    utility::string_t m_ImageCompression;
    bool m_ImageCompressionIsSet;
    bool m_InterpolateImages;
    bool m_InterpolateImagesIsSet;
    bool m_OpenHyperlinksInNewWindow;
    bool m_OpenHyperlinksInNewWindowIsSet;
    std::shared_ptr<OutlineOptionsData> m_OutlineOptions;
    bool m_OutlineOptionsIsSet;
    utility::string_t m_PageMode;
    bool m_PageModeIsSet;
    bool m_PreblendImages;
    bool m_PreblendImagesIsSet;
    bool m_PreserveFormFields;
    bool m_PreserveFormFieldsIsSet;
    utility::string_t m_TextCompression;
    bool m_TextCompressionIsSet;
    bool m_UseBookFoldPrintingSettings;
    bool m_UseBookFoldPrintingSettingsIsSet;
    bool m_UseCoreFonts;
    bool m_UseCoreFontsIsSet;
    utility::string_t m_ZoomBehavior;
    bool m_ZoomBehaviorIsSet;
    int32_t m_ZoomFactor;
    bool m_ZoomFactorIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PdfSaveOptionsData_H_ */
