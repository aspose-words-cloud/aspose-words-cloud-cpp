/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="html_fixed_save_options_data.h">
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
#include "fixed_page_save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for fixed html save options.
    /// </summary>
    class HtmlFixedSaveOptionsData : public FixedPageSaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the export format of fonts.
        /// </summary>
        enum class FontFormat
        { 
            WOFF,
            TTF
        };

        /// <summary>
        /// Gets or sets the horizontal alignment of pages in the HTML document.
        /// The default value is HtmlFixedHorizontalPageAlignment.Center.
        /// </summary>
        enum class PageHorizontalAlignment
        { 
            LEFT,
            CENTER,
            RIGHT
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~HtmlFixedSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractFixedPageSaveOptionsData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the prefix which is added to all class names in style.css file.
        /// Default value is "aw".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getCssClassNamesPrefix() const;

        /// <summary>
        /// Gets or sets the prefix which is added to all class names in style.css file.
        /// Default value is "aw".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCssClassNamesPrefix(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the character encoding.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getEncoding() const;

        /// <summary>
        /// Gets or sets the character encoding.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEncoding(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether the CSS (Cascading Style Sheet) should be embedded into the Html document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportEmbeddedCss() const;

        /// <summary>
        /// Gets or sets a value indicating whether the CSS (Cascading Style Sheet) should be embedded into the Html document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportEmbeddedCss(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether fonts should be embedded into the Html document in Base64 format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportEmbeddedFonts() const;

        /// <summary>
        /// Gets or sets a value indicating whether fonts should be embedded into the Html document in Base64 format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportEmbeddedFonts(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether images should be embedded into the Html document in Base64 format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportEmbeddedImages() const;

        /// <summary>
        /// Gets or sets a value indicating whether images should be embedded into the Html document in Base64 format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportEmbeddedImages(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether form fields are exported as interactive items (as 'input' tag) rather than converted to text or graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportFormFields() const;

        /// <summary>
        /// Gets or sets a value indicating whether form fields are exported as interactive items (as 'input' tag) rather than converted to text or graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportFormFields(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the export format of fonts.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlFixedSaveOptionsData::FontFormat > getFontFormat() const;

        /// <summary>
        /// Gets or sets the export format of fonts.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFontFormat(std::shared_ptr< aspose::words::cloud::models::HtmlFixedSaveOptionsData::FontFormat > value);


        /// <summary>
        /// Gets or sets the horizontal alignment of pages in the HTML document.
        /// The default value is HtmlFixedHorizontalPageAlignment.Center.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::HtmlFixedSaveOptionsData::PageHorizontalAlignment > getPageHorizontalAlignment() const;

        /// <summary>
        /// Gets or sets the horizontal alignment of pages in the HTML document.
        /// The default value is HtmlFixedHorizontalPageAlignment.Center.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageHorizontalAlignment(std::shared_ptr< aspose::words::cloud::models::HtmlFixedSaveOptionsData::PageHorizontalAlignment > value);


        /// <summary>
        /// Gets or sets the margin around pages in HTML document.
        /// The margins value is measured in points and should be equal to or greater than 0.
        /// Default value is 10 points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getPageMargins() const;

        /// <summary>
        /// Gets or sets the margin around pages in HTML document.
        /// The margins value is measured in points and should be equal to or greater than 0.
        /// Default value is 10 points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageMargins(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the physical folder where resources are saved when exporting the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourcesFolder() const;

        /// <summary>
        /// Gets or sets the physical folder where resources are saved when exporting the document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourcesFolder(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the folder used to construct resource URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourcesFolderAlias() const;

        /// <summary>
        /// Gets or sets the name of the folder used to construct resource URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourcesFolderAlias(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether "@font-face" CSS rules should be placed into a separate file "fontFaces.css" when a document is being saved with external stylesheet (that is, when Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedCss is false). The default value is false, all CSS rules are written into single file "styles.css".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSaveFontFaceCssSeparately() const;

        /// <summary>
        /// Gets or sets a value indicating whether "@font-face" CSS rules should be placed into a separate file "fontFaces.css" when a document is being saved with external stylesheet (that is, when Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedCss is false). The default value is false, all CSS rules are written into single file "styles.css".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSaveFontFaceCssSeparately(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



        /// <summary>
        /// Gets or sets a value indicating whether to show border around pages.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getShowPageBorder() const;

        /// <summary>
        /// Gets or sets a value indicating whether to show border around pages.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setShowPageBorder(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether fonts from target machine must be used to display the document. If this flag is set to true, Aspose.Words.Saving.HtmlFixedSaveOptions.FontFormat and Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedFonts properties do not have effect, also Aspose.Words.Saving.HtmlFixedSaveOptions.ResourceSavingCallback is not fired for fonts. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUseTargetMachineFonts() const;

        /// <summary>
        /// Gets or sets a value indicating whether fonts from target machine must be used to display the document. If this flag is set to true, Aspose.Words.Saving.HtmlFixedSaveOptions.FontFormat and Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedFonts properties do not have effect, also Aspose.Words.Saving.HtmlFixedSaveOptions.ResourceSavingCallback is not fired for fonts. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUseTargetMachineFonts(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< std::wstring > m_CssClassNamesPrefix;
        std::shared_ptr< std::wstring > m_Encoding;
        std::shared_ptr< bool > m_ExportEmbeddedCss;
        std::shared_ptr< bool > m_ExportEmbeddedFonts;
        std::shared_ptr< bool > m_ExportEmbeddedImages;
        std::shared_ptr< bool > m_ExportFormFields;
        std::shared_ptr< aspose::words::cloud::models::HtmlFixedSaveOptionsData::FontFormat > m_FontFormat;
        std::shared_ptr< aspose::words::cloud::models::HtmlFixedSaveOptionsData::PageHorizontalAlignment > m_PageHorizontalAlignment;
        std::shared_ptr< double > m_PageMargins;
        std::shared_ptr< std::wstring > m_ResourcesFolder;
        std::shared_ptr< std::wstring > m_ResourcesFolderAlias;
        std::shared_ptr< bool > m_SaveFontFaceCssSeparately;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"htmlfixed");
        std::shared_ptr< bool > m_ShowPageBorder;
        std::shared_ptr< bool > m_UseTargetMachineFonts;
    };
}

