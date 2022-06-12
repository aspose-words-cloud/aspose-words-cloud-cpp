/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="html_save_options_data.h">
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
#include "save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for html save options.
    /// </summary>
    class HtmlSaveOptionsData : public SaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls how the CSS styles are exported.
        /// </summary>
        enum class CssStyleSheetType
        { 
            INLINE,
            EMBEDDED,
            EXTERNAL
        };

        /// <summary>
        /// Gets or sets the option that controls how the document should be split when saving.
        /// </summary>
        enum class DocumentSplitCriteria
        { 
            NONE,
            PAGE_BREAK,
            COLUMN_BREAK,
            SECTION_BREAK,
            HEADING_PARAGRAPH
        };

        /// <summary>
        /// Gets or sets the option that controls how headers and footers are exported.
        /// </summary>
        enum class ExportHeadersFootersMode
        { 
            NONE,
            PER_SECTION,
            FIRST_SECTION_HEADER_LAST_SECTION_FOOTER,
            FIRST_PAGE_HEADER_FOOTER_PER_SECTION
        };

        /// <summary>
        /// Gets or sets the option that controls how list labels are exported.
        /// </summary>
        enum class ExportListLabels
        { 
            AUTO,
            AS_INLINE_TEXT,
            BY_HTML_TAGS
        };

        /// <summary>
        /// Gets or sets the version of HTML standard, that should be used when saving the document to HTML or MHTML.
        /// Default value is Aspose.Words.Saving.HtmlVersion.Xhtml.
        /// </summary>
        enum class HtmlVersion
        { 
            XHTML,
            HTML5
        };

        /// <summary>
        /// Gets or sets the options, that controls in what format metafiles are saved when exporting to HTML, MHTML, or EPUB.
        /// The default value is Aspose.Words.Saving.HtmlMetafileFormat.Png, meaning that metafiles are rendered to raster PNG images.
        /// Metafiles are not natively displayed by HTML browsers. By default, Aspose.Words converts WMF and EMF images into PNG files when exporting to HTML.Other options are to convert metafiles to SVG images or to export them as is without conversion.
        /// Some image transforms, in particular image cropping, will not be applied to metafile images if they are exported to HTML without conversion.
        /// </summary>
        enum class MetafileFormat
        { 
            PNG,
            SVG,
            EMF_OR_WMF
        };

        /// <summary>
        /// Gets or sets the option that controls how OfficeMath objects are exported to HTML, MHTML or EPUB. The default value is HtmlOfficeMathOutputMode.Image.
        /// </summary>
        enum class OfficeMathOutputMode
        { 
            IMAGE,
            MATH_ML,
            TEXT
        };

        /// <summary>
        /// Gets or sets the option that controls how table, row and cell widths are exported.
        /// </summary>
        enum class TableWidthOutputMode
        { 
            ALL,
            RELATIVE_ONLY,
            NONE
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~HtmlSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets a value indicating whether negative left and right indents of paragraphs are allowed (not normalized).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAllowNegativeIndent() const;

        /// <summary>
        /// Gets or sets a value indicating whether negative left and right indents of paragraphs are allowed (not normalized).
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAllowNegativeIndent(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the prefix which is added to all CSS class names. The default value is an empty string and generated CSS class names have no common prefix.
        /// If this value is not empty, all CSS classes generated by Aspose.Words will start with the specified prefix.This might be useful, for example, if you add custom CSS to generated documents and want to prevent class name conflicts.
        /// If the value is not null or empty, it must be a valid CSS identifier.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getCssClassNamePrefix() const;

        /// <summary>
        /// Gets or sets the prefix which is added to all CSS class names. The default value is an empty string and generated CSS class names have no common prefix.
        /// If this value is not empty, all CSS classes generated by Aspose.Words will start with the specified prefix.This might be useful, for example, if you add custom CSS to generated documents and want to prevent class name conflicts.
        /// If the value is not null or empty, it must be a valid CSS identifier.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCssClassNamePrefix(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the CSS file written when the document is exported to HTML.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getCssStyleSheetFileName() const;

        /// <summary>
        /// Gets or sets the name of the CSS file written when the document is exported to HTML.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCssStyleSheetFileName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the option that controls how the CSS styles are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::CssStyleSheetType > getCssStyleSheetType() const;

        /// <summary>
        /// Gets or sets the option that controls how the CSS styles are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCssStyleSheetType(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::CssStyleSheetType > value);


        /// <summary>
        /// Gets or sets the option that controls how the document should be split when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::DocumentSplitCriteria > getDocumentSplitCriteria() const;

        /// <summary>
        /// Gets or sets the option that controls how the document should be split when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDocumentSplitCriteria(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::DocumentSplitCriteria > value);


        /// <summary>
        /// Gets or sets the maximum level of headings at which to split the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getDocumentSplitHeadingLevel() const;

        /// <summary>
        /// Gets or sets the maximum level of headings at which to split the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDocumentSplitHeadingLevel(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the character encoding to use when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getEncoding() const;

        /// <summary>
        /// Gets or sets the character encoding to use when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEncoding(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether to export built-in and custom document properties.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportDocumentProperties() const;

        /// <summary>
        /// Gets or sets a value indicating whether to export built-in and custom document properties.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportDocumentProperties(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the flag, that controls how drop-down form fields are saved to HTML.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportDropDownFormFieldAsText() const;

        /// <summary>
        /// Gets or sets the flag, that controls how drop-down form fields are saved to HTML.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportDropDownFormFieldAsText(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether font resources should be exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportFontResources() const;

        /// <summary>
        /// Gets or sets a value indicating whether font resources should be exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportFontResources(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether fonts resources should be embedded to HTML in Base64 encoding. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportFontsAsBase64() const;

        /// <summary>
        /// Gets or sets a value indicating whether fonts resources should be embedded to HTML in Base64 encoding. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportFontsAsBase64(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls how headers and footers are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::ExportHeadersFootersMode > getExportHeadersFootersMode() const;

        /// <summary>
        /// Gets or sets the option that controls how headers and footers are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportHeadersFootersMode(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::ExportHeadersFootersMode > value);


        /// <summary>
        /// Gets or sets a value indicating whether images are saved in Base64 format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportImagesAsBase64() const;

        /// <summary>
        /// Gets or sets a value indicating whether images are saved in Base64 format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportImagesAsBase64(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether language information is exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportLanguageInformation() const;

        /// <summary>
        /// Gets or sets a value indicating whether language information is exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportLanguageInformation(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls how list labels are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::ExportListLabels > getExportListLabels() const;

        /// <summary>
        /// Gets or sets the option that controls how list labels are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportListLabels(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::ExportListLabels > value);


        /// <summary>
        /// Gets or sets a value indicating whether the original URL should be used as the URL of the linked images.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportOriginalUrlForLinkedImages() const;

        /// <summary>
        /// Gets or sets a value indicating whether the original URL should be used as the URL of the linked images.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportOriginalUrlForLinkedImages(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether page margins are exported to HTML, MHTML or EPUB.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportPageMargins() const;

        /// <summary>
        /// Gets or sets a value indicating whether page margins are exported to HTML, MHTML or EPUB.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportPageMargins(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether page setup is exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportPageSetup() const;

        /// <summary>
        /// Gets or sets a value indicating whether page setup is exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportPageSetup(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether font sizes should be output in relative units when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportRelativeFontSize() const;

        /// <summary>
        /// Gets or sets a value indicating whether font sizes should be output in relative units when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportRelativeFontSize(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to write the roundtrip information when saving to HTML. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportRoundtripInformation() const;

        /// <summary>
        /// Gets or sets a value indicating whether to write the roundtrip information when saving to HTML. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportRoundtripInformation(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the flag, that controls how text input form fields are saved.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportTextInputFormFieldAsText() const;

        /// <summary>
        /// Gets or sets the flag, that controls how text input form fields are saved.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportTextInputFormFieldAsText(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to write page numbers to table of contents when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportTocPageNumbers() const;

        /// <summary>
        /// Gets or sets a value indicating whether to write page numbers to table of contents when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportTocPageNumbers(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to write the DOCTYPE declaration when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportXhtmlTransitional() const;

        /// <summary>
        /// Gets or sets a value indicating whether to write the DOCTYPE declaration when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportXhtmlTransitional(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls which font resources need subsetting when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getFontResourcesSubsettingSizeThreshold() const;

        /// <summary>
        /// Gets or sets the option that controls which font resources need subsetting when saving.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFontResourcesSubsettingSizeThreshold(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the physical folder where fonts are saved when exporting a document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFontsFolder() const;

        /// <summary>
        /// Gets or sets the physical folder where fonts are saved when exporting a document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFontsFolder(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the folder used to construct font URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFontsFolderAlias() const;

        /// <summary>
        /// Gets or sets the name of the folder used to construct font URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFontsFolderAlias(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the version of HTML standard, that should be used when saving the document to HTML or MHTML.
        /// Default value is Aspose.Words.Saving.HtmlVersion.Xhtml.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::HtmlVersion > getHtmlVersion() const;

        /// <summary>
        /// Gets or sets the version of HTML standard, that should be used when saving the document to HTML or MHTML.
        /// Default value is Aspose.Words.Saving.HtmlVersion.Xhtml.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHtmlVersion(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::HtmlVersion > value);


        /// <summary>
        /// Gets or sets the output resolution for images when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getImageResolution() const;

        /// <summary>
        /// Gets or sets the output resolution for images when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImageResolution(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the physical folder where images are saved when exporting a document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getImagesFolder() const;

        /// <summary>
        /// Gets or sets the physical folder where images are saved when exporting a document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImagesFolder(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getImagesFolderAlias() const;

        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImagesFolderAlias(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the options, that controls in what format metafiles are saved when exporting to HTML, MHTML, or EPUB.
        /// The default value is Aspose.Words.Saving.HtmlMetafileFormat.Png, meaning that metafiles are rendered to raster PNG images.
        /// Metafiles are not natively displayed by HTML browsers. By default, Aspose.Words converts WMF and EMF images into PNG files when exporting to HTML.Other options are to convert metafiles to SVG images or to export them as is without conversion.
        /// Some image transforms, in particular image cropping, will not be applied to metafile images if they are exported to HTML without conversion.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::MetafileFormat > getMetafileFormat() const;

        /// <summary>
        /// Gets or sets the options, that controls in what format metafiles are saved when exporting to HTML, MHTML, or EPUB.
        /// The default value is Aspose.Words.Saving.HtmlMetafileFormat.Png, meaning that metafiles are rendered to raster PNG images.
        /// Metafiles are not natively displayed by HTML browsers. By default, Aspose.Words converts WMF and EMF images into PNG files when exporting to HTML.Other options are to convert metafiles to SVG images or to export them as is without conversion.
        /// Some image transforms, in particular image cropping, will not be applied to metafile images if they are exported to HTML without conversion.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMetafileFormat(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::MetafileFormat > value);


        /// <summary>
        /// Gets or sets the option that controls how OfficeMath objects are exported to HTML, MHTML or EPUB. The default value is HtmlOfficeMathOutputMode.Image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::OfficeMathOutputMode > getOfficeMathOutputMode() const;

        /// <summary>
        /// Gets or sets the option that controls how OfficeMath objects are exported to HTML, MHTML or EPUB. The default value is HtmlOfficeMathOutputMode.Image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOfficeMathOutputMode(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::OfficeMathOutputMode > value);


        /// <summary>
        /// Gets or sets a value indicating whether to use pretty formats output.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getPrettyFormat() const;

        /// <summary>
        /// Gets or sets a value indicating whether to use pretty formats output.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPrettyFormat(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether font family names used in the document are resolved and substituted according to FontSettings when being written into HTML-based formats.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getResolveFontNames() const;

        /// <summary>
        /// Gets or sets a value indicating whether font family names used in the document are resolved and substituted according to FontSettings when being written into HTML-based formats.
        /// The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResolveFontNames(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the physical folder where all resources like images, fonts, and external CSS are saved when a document is exported to HTML. The default value is an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourceFolder() const;

        /// <summary>
        /// Gets or sets the physical folder where all resources like images, fonts, and external CSS are saved when a document is exported to HTML. The default value is an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourceFolder(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the folder used to construct URIs of all resources written into HTML document. The default value is an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourceFolderAlias() const;

        /// <summary>
        /// Gets or sets the name of the folder used to construct URIs of all resources written into HTML document. The default value is an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourceFolderAlias(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



        /// <summary>
        /// Gets or sets a value indicating whether images are scaled by Aspose.Words to the bounding shape size when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getScaleImageToShapeSize() const;

        /// <summary>
        /// Gets or sets a value indicating whether images are scaled by Aspose.Words to the bounding shape size when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setScaleImageToShapeSize(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls how table, row and cell widths are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::TableWidthOutputMode > getTableWidthOutputMode() const;

        /// <summary>
        /// Gets or sets the option that controls how table, row and cell widths are exported.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTableWidthOutputMode(std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::TableWidthOutputMode > value);


    protected:
        std::shared_ptr< bool > m_AllowNegativeIndent;
        std::shared_ptr< std::wstring > m_CssClassNamePrefix;
        std::shared_ptr< std::wstring > m_CssStyleSheetFileName;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::CssStyleSheetType > m_CssStyleSheetType;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::DocumentSplitCriteria > m_DocumentSplitCriteria;
        std::shared_ptr< int32_t > m_DocumentSplitHeadingLevel;
        std::shared_ptr< std::wstring > m_Encoding;
        std::shared_ptr< bool > m_ExportDocumentProperties;
        std::shared_ptr< bool > m_ExportDropDownFormFieldAsText;
        std::shared_ptr< bool > m_ExportFontResources;
        std::shared_ptr< bool > m_ExportFontsAsBase64;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::ExportHeadersFootersMode > m_ExportHeadersFootersMode;
        std::shared_ptr< bool > m_ExportImagesAsBase64;
        std::shared_ptr< bool > m_ExportLanguageInformation;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::ExportListLabels > m_ExportListLabels;
        std::shared_ptr< bool > m_ExportOriginalUrlForLinkedImages;
        std::shared_ptr< bool > m_ExportPageMargins;
        std::shared_ptr< bool > m_ExportPageSetup;
        std::shared_ptr< bool > m_ExportRelativeFontSize;
        std::shared_ptr< bool > m_ExportRoundtripInformation;
        std::shared_ptr< bool > m_ExportTextInputFormFieldAsText;
        std::shared_ptr< bool > m_ExportTocPageNumbers;
        std::shared_ptr< bool > m_ExportXhtmlTransitional;
        std::shared_ptr< int32_t > m_FontResourcesSubsettingSizeThreshold;
        std::shared_ptr< std::wstring > m_FontsFolder;
        std::shared_ptr< std::wstring > m_FontsFolderAlias;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::HtmlVersion > m_HtmlVersion;
        std::shared_ptr< int32_t > m_ImageResolution;
        std::shared_ptr< std::wstring > m_ImagesFolder;
        std::shared_ptr< std::wstring > m_ImagesFolderAlias;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::MetafileFormat > m_MetafileFormat;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::OfficeMathOutputMode > m_OfficeMathOutputMode;
        std::shared_ptr< bool > m_PrettyFormat;
        std::shared_ptr< bool > m_ResolveFontNames;
        std::shared_ptr< std::wstring > m_ResourceFolder;
        std::shared_ptr< std::wstring > m_ResourceFolderAlias;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"html");
        std::shared_ptr< bool > m_ScaleImageToShapeSize;
        std::shared_ptr< aspose::words::cloud::models::HtmlSaveOptionsData::TableWidthOutputMode > m_TableWidthOutputMode;
    };
}

