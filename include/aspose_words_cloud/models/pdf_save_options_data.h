/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="pdf_save_options_data.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include "./model_base.h"
#include "downsample_options_data.h"
#include "fixed_page_save_options_data.h"
#include "outline_options_data.h"
#include "pdf_digital_signature_details_data.h"
#include "pdf_encryption_details_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for pdf save options.
    /// </summary>
    class PdfSaveOptionsData : public FixedPageSaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the PDF standards compliance level for output documents.
        /// </summary>
        enum class Compliance
        { 
            PDF17,
            PDF20,
            PDF_A1A,
            PDF_A1B,
            PDF_A2A,
            PDF_A2U,
            PDF_A4,
            PDF_UA1
        };

        /// <summary>
        /// Gets or sets the option that controls the way CustomDocumentProperties are exported to PDF file.
        /// The default value is None.
        /// </summary>
        enum class CustomPropertiesExport
        { 
            NONE,
            STANDARD,
            METADATA
        };

        /// <summary>
        /// Gets or sets the font embedding mode.
        /// </summary>
        enum class FontEmbeddingMode
        { 
            EMBED_ALL,
            EMBED_NONSTANDARD,
            EMBED_NONE
        };

        /// <summary>
        /// Gets or sets the option that controls how bookmarks in headers/footers are exported.
        /// The default value is Aspose.Words.Saving.HeaderFooterBookmarksExportMode.All.
        /// </summary>
        enum class HeaderFooterBookmarksExportMode
        { 
            NONE,
            FIRST,
            ALL
        };

        /// <summary>
        /// Gets or sets the option that controls how the color space will be selected for the images in PDF document.
        /// </summary>
        enum class ImageColorSpaceExportMode
        { 
            AUTO,
            SIMPLE_CMYK
        };

        /// <summary>
        /// Gets or sets the option that controls how the PDF document should be displayed when opened in the PDF reader.
        /// </summary>
        enum class PageMode
        { 
            USE_NONE,
            USE_OUTLINES,
            USE_THUMBS,
            FULL_SCREEN,
            USE_OC,
            USE_ATTACHMENTS
        };

        /// <summary>
        /// Gets or sets the compression type to be used for all textual content in the document.
        /// </summary>
        enum class TextCompression
        { 
            NONE,
            FLATE
        };

        /// <summary>
        /// Gets or sets the option that controls what type of zoom should be applied when a document is opened with a PDF viewer.
        /// </summary>
        enum class ZoomBehavior
        { 
            NONE,
            ZOOM_FACTOR,
            FIT_PAGE,
            FIT_WIDTH,
            FIT_HEIGHT,
            FIT_BOX
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~PdfSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractFixedPageSaveOptionsData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the PDF standards compliance level for output documents.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::Compliance > getCompliance() const;

        /// <summary>
        /// Gets or sets the PDF standards compliance level for output documents.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCompliance(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::Compliance > value);


        /// <summary>
        /// Gets or sets a value indicating whether to convert footnote/endnote references in main text story into active hyperlinks.
        /// When clicked the hyperlink will lead to the corresponding footnote/endnote.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getCreateNoteHyperlinks() const;

        /// <summary>
        /// Gets or sets a value indicating whether to convert footnote/endnote references in main text story into active hyperlinks.
        /// When clicked the hyperlink will lead to the corresponding footnote/endnote.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCreateNoteHyperlinks(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls the way CustomDocumentProperties are exported to PDF file.
        /// The default value is None.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::CustomPropertiesExport > getCustomPropertiesExport() const;

        /// <summary>
        /// Gets or sets the option that controls the way CustomDocumentProperties are exported to PDF file.
        /// The default value is None.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCustomPropertiesExport(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::CustomPropertiesExport > value);


        /// <summary>
        /// Gets or sets the details for signing the output PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfDigitalSignatureDetailsData > getDigitalSignatureDetails() const;

        /// <summary>
        /// Gets or sets the details for signing the output PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDigitalSignatureDetails(std::shared_ptr< aspose::words::cloud::models::PdfDigitalSignatureDetailsData > value);


        /// <summary>
        /// Gets or sets a value indicating whether the window’s title bar should display the document title taken from the Title entry of the document information dictionary.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getDisplayDocTitle() const;

        /// <summary>
        /// Gets or sets a value indicating whether the window’s title bar should display the document title taken from the Title entry of the document information dictionary.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDisplayDocTitle(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the downsample options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::DownsampleOptionsData > getDownsampleOptions() const;

        /// <summary>
        /// Gets or sets the downsample options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDownsampleOptions(std::shared_ptr< aspose::words::cloud::models::DownsampleOptionsData > value);


        /// <summary>
        /// Gets or sets a value indicating whether fonts are embedded into the resulting PDF documents.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getEmbedFullFonts() const;

        /// <summary>
        /// Gets or sets a value indicating whether fonts are embedded into the resulting PDF documents.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEmbedFullFonts(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the details for encrypting the output PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfEncryptionDetailsData > getEncryptionDetails() const;

        /// <summary>
        /// Gets or sets the details for encrypting the output PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEncryptionDetails(std::shared_ptr< aspose::words::cloud::models::PdfEncryptionDetailsData > value);


        /// <summary>
        /// Gets or sets a value indicating whether to export document structure.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportDocumentStructure() const;

        /// <summary>
        /// Gets or sets a value indicating whether to export document structure.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportDocumentStructure(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value determining whether or not to create a "Span" tag in the document structure to export the text language.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportLanguageToSpanTag() const;

        /// <summary>
        /// Gets or sets a value determining whether or not to create a "Span" tag in the document structure to export the text language.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportLanguageToSpanTag(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the font embedding mode.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::FontEmbeddingMode > getFontEmbeddingMode() const;

        /// <summary>
        /// Gets or sets the font embedding mode.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFontEmbeddingMode(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::FontEmbeddingMode > value);


        /// <summary>
        /// Gets or sets the option that controls how bookmarks in headers/footers are exported.
        /// The default value is Aspose.Words.Saving.HeaderFooterBookmarksExportMode.All.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::HeaderFooterBookmarksExportMode > getHeaderFooterBookmarksExportMode() const;

        /// <summary>
        /// Gets or sets the option that controls how bookmarks in headers/footers are exported.
        /// The default value is Aspose.Words.Saving.HeaderFooterBookmarksExportMode.All.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeaderFooterBookmarksExportMode(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::HeaderFooterBookmarksExportMode > value);


        /// <summary>
        /// Gets or sets the option that controls how the color space will be selected for the images in PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::ImageColorSpaceExportMode > getImageColorSpaceExportMode() const;

        /// <summary>
        /// Gets or sets the option that controls how the color space will be selected for the images in PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImageColorSpaceExportMode(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::ImageColorSpaceExportMode > value);


        /// <summary>
        /// Gets or sets the compression type to be used for all images in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getImageCompression() const;

        /// <summary>
        /// Gets or sets the compression type to be used for all images in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImageCompression(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether image interpolation shall be performed by a conforming reader. When false is specified, the flag is not written to the output document and the default behavior of reader is used instead.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getInterpolateImages() const;

        /// <summary>
        /// Gets or sets a value indicating whether image interpolation shall be performed by a conforming reader. When false is specified, the flag is not written to the output document and the default behavior of reader is used instead.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setInterpolateImages(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether hyperlinks in the output Pdf document are forced to be opened in a new window (or tab) of a browser.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getOpenHyperlinksInNewWindow() const;

        /// <summary>
        /// Gets or sets a value indicating whether hyperlinks in the output Pdf document are forced to be opened in a new window (or tab) of a browser.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOpenHyperlinksInNewWindow(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the outline options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OutlineOptionsData > getOutlineOptions() const;

        /// <summary>
        /// Gets or sets the outline options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOutlineOptions(std::shared_ptr< aspose::words::cloud::models::OutlineOptionsData > value);


        /// <summary>
        /// Gets or sets the option that controls how the PDF document should be displayed when opened in the PDF reader.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::PageMode > getPageMode() const;

        /// <summary>
        /// Gets or sets the option that controls how the PDF document should be displayed when opened in the PDF reader.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageMode(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::PageMode > value);


        /// <summary>
        /// Gets or sets a value indicating whether to preblend transparent images with black background color.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getPreblendImages() const;

        /// <summary>
        /// Gets or sets a value indicating whether to preblend transparent images with black background color.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPreblendImages(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to preserve Microsoft Word form fields as form fields in PDF or convert them to text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getPreserveFormFields() const;

        /// <summary>
        /// Gets or sets a value indicating whether to preserve Microsoft Word form fields as form fields in PDF or convert them to text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPreserveFormFields(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



        /// <summary>
        /// Gets or sets the compression type to be used for all textual content in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::TextCompression > getTextCompression() const;

        /// <summary>
        /// Gets or sets the compression type to be used for all textual content in the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextCompression(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::TextCompression > value);


        /// <summary>
        /// Gets or sets a value indicating whether the document should be saved using a booklet printing layout.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUseBookFoldPrintingSettings() const;

        /// <summary>
        /// Gets or sets a value indicating whether the document should be saved using a booklet printing layout.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUseBookFoldPrintingSettings(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to substitute TrueType fonts Arial, Times New Roman, Courier New and Symbol with core PDF Type 1 fonts.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUseCoreFonts() const;

        /// <summary>
        /// Gets or sets a value indicating whether to substitute TrueType fonts Arial, Times New Roman, Courier New and Symbol with core PDF Type 1 fonts.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUseCoreFonts(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls what type of zoom should be applied when a document is opened with a PDF viewer.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::ZoomBehavior > getZoomBehavior() const;

        /// <summary>
        /// Gets or sets the option that controls what type of zoom should be applied when a document is opened with a PDF viewer.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setZoomBehavior(std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::ZoomBehavior > value);


        /// <summary>
        /// Gets or sets the zoom factor (in percentages) for a document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getZoomFactor() const;

        /// <summary>
        /// Gets or sets the zoom factor (in percentages) for a document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setZoomFactor(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::Compliance > m_Compliance;
        std::shared_ptr< bool > m_CreateNoteHyperlinks;
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::CustomPropertiesExport > m_CustomPropertiesExport;
        std::shared_ptr< aspose::words::cloud::models::PdfDigitalSignatureDetailsData > m_DigitalSignatureDetails;
        std::shared_ptr< bool > m_DisplayDocTitle;
        std::shared_ptr< aspose::words::cloud::models::DownsampleOptionsData > m_DownsampleOptions;
        std::shared_ptr< bool > m_EmbedFullFonts;
        std::shared_ptr< aspose::words::cloud::models::PdfEncryptionDetailsData > m_EncryptionDetails;
        std::shared_ptr< bool > m_ExportDocumentStructure;
        std::shared_ptr< bool > m_ExportLanguageToSpanTag;
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::FontEmbeddingMode > m_FontEmbeddingMode;
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::HeaderFooterBookmarksExportMode > m_HeaderFooterBookmarksExportMode;
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::ImageColorSpaceExportMode > m_ImageColorSpaceExportMode;
        std::shared_ptr< std::wstring > m_ImageCompression;
        std::shared_ptr< bool > m_InterpolateImages;
        std::shared_ptr< bool > m_OpenHyperlinksInNewWindow;
        std::shared_ptr< aspose::words::cloud::models::OutlineOptionsData > m_OutlineOptions;
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::PageMode > m_PageMode;
        std::shared_ptr< bool > m_PreblendImages;
        std::shared_ptr< bool > m_PreserveFormFields;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"pdf");
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::TextCompression > m_TextCompression;
        std::shared_ptr< bool > m_UseBookFoldPrintingSettings;
        std::shared_ptr< bool > m_UseCoreFonts;
        std::shared_ptr< aspose::words::cloud::models::PdfSaveOptionsData::ZoomBehavior > m_ZoomBehavior;
        std::shared_ptr< int32_t > m_ZoomFactor;
    };
}

