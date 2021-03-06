/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HtmlFixedSaveOptionsData.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_HtmlFixedSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_HtmlFixedSaveOptionsData_H_

#include "FixedPageSaveOptionsData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for fixed html save options.
/// </summary>
class HtmlFixedSaveOptionsData
    : public FixedPageSaveOptionsData
{
public:
    HtmlFixedSaveOptionsData();
    virtual ~HtmlFixedSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// HtmlFixedSaveOptionsData members

    /// <summary>
    /// Gets or sets the prefix which is added to all class names in style.css file.
    /// Default value is "aw".
    /// </summary>
    utility::string_t getCssClassNamesPrefix() const;
    bool cssClassNamesPrefixIsSet() const;
    void unsetCssClassNamesPrefix();
    void setCssClassNamesPrefix(utility::string_t value);

    /// <summary>
    /// Gets or sets the character encoding.
    /// </summary>
    utility::string_t getEncoding() const;
    bool encodingIsSet() const;
    void unsetEncoding();
    void setEncoding(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether the CSS (Cascading Style Sheet) should be embedded into the Html document.
    /// </summary>
    bool isExportEmbeddedCss() const;
    bool exportEmbeddedCssIsSet() const;
    void unsetExportEmbeddedCss();
    void setExportEmbeddedCss(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether fonts should be embedded into the Html document in Base64 format.
    /// </summary>
    bool isExportEmbeddedFonts() const;
    bool exportEmbeddedFontsIsSet() const;
    void unsetExportEmbeddedFonts();
    void setExportEmbeddedFonts(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether images should be embedded into the Html document in Base64 format.
    /// </summary>
    bool isExportEmbeddedImages() const;
    bool exportEmbeddedImagesIsSet() const;
    void unsetExportEmbeddedImages();
    void setExportEmbeddedImages(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether form fields are exported as interactive items (as 'input' tag) rather than converted to text or graphics.
    /// </summary>
    bool isExportFormFields() const;
    bool exportFormFieldsIsSet() const;
    void unsetExportFormFields();
    void setExportFormFields(bool value);

    /// <summary>
    /// Gets or sets the export format of fonts.
    /// </summary>
    utility::string_t getFontFormat() const;
    bool fontFormatIsSet() const;
    void unsetFontFormat();
    void setFontFormat(utility::string_t value);

    /// <summary>
    /// Gets or sets the horizontal alignment of pages in the HTML document.
    /// The default value is HtmlFixedHorizontalPageAlignment.Center.
    /// </summary>
    utility::string_t getPageHorizontalAlignment() const;
    bool pageHorizontalAlignmentIsSet() const;
    void unsetPageHorizontalAlignment();
    void setPageHorizontalAlignment(utility::string_t value);

    /// <summary>
    /// Gets or sets the margin around pages in HTML document.
    /// The margins value is measured in points and should be equal to or greater than 0.
    /// Default value is 10 points.
    /// </summary>
    double getPageMargins() const;
    bool pageMarginsIsSet() const;
    void unsetPageMargins();
    void setPageMargins(double value);

    /// <summary>
    /// Gets or sets the physical folder where resources are saved when exporting the document.
    /// </summary>
    utility::string_t getResourcesFolder() const;
    bool resourcesFolderIsSet() const;
    void unsetResourcesFolder();
    void setResourcesFolder(utility::string_t value);

    /// <summary>
    /// Gets or sets the name of the folder used to construct resource URIs.
    /// </summary>
    utility::string_t getResourcesFolderAlias() const;
    bool resourcesFolderAliasIsSet() const;
    void unsetResourcesFolderAlias();
    void setResourcesFolderAlias(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether "@font-face" CSS rules should be placed into a separate file "fontFaces.css" when a document is being saved with external stylesheet (that is, when Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedCss is false). The default value is false, all CSS rules are written into single file "styles.css".
    /// </summary>
    bool isSaveFontFaceCssSeparately() const;
    bool saveFontFaceCssSeparatelyIsSet() const;
    void unsetSaveFontFaceCssSeparately();
    void setSaveFontFaceCssSeparately(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether to show border around pages.
    /// </summary>
    bool isShowPageBorder() const;
    bool showPageBorderIsSet() const;
    void unsetShowPageBorder();
    void setShowPageBorder(bool value);

    /// <summary>
    /// Gets or sets a value indicating whether fonts from target machine must be used to display the document. If this flag is set to true, Aspose.Words.Saving.HtmlFixedSaveOptions.FontFormat and Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedFonts properties do not have effect, also Aspose.Words.Saving.HtmlFixedSaveOptions.ResourceSavingCallback is not fired for fonts. The default value is false.
    /// </summary>
    bool isUseTargetMachineFonts() const;
    bool useTargetMachineFontsIsSet() const;
    void unsetUseTargetMachineFonts();
    void setUseTargetMachineFonts(bool value);

protected:
    utility::string_t m_CssClassNamesPrefix;
    bool m_CssClassNamesPrefixIsSet;

    utility::string_t m_Encoding;
    bool m_EncodingIsSet;

    bool m_ExportEmbeddedCss;
    bool m_ExportEmbeddedCssIsSet;

    bool m_ExportEmbeddedFonts;
    bool m_ExportEmbeddedFontsIsSet;

    bool m_ExportEmbeddedImages;
    bool m_ExportEmbeddedImagesIsSet;

    bool m_ExportFormFields;
    bool m_ExportFormFieldsIsSet;

    utility::string_t m_FontFormat;
    bool m_FontFormatIsSet;

    utility::string_t m_PageHorizontalAlignment;
    bool m_PageHorizontalAlignmentIsSet;

    double m_PageMargins;
    bool m_PageMarginsIsSet;

    utility::string_t m_ResourcesFolder;
    bool m_ResourcesFolderIsSet;

    utility::string_t m_ResourcesFolderAlias;
    bool m_ResourcesFolderAliasIsSet;

    bool m_SaveFontFaceCssSeparately;
    bool m_SaveFontFaceCssSeparatelyIsSet;

    bool m_ShowPageBorder;
    bool m_ShowPageBorderIsSet;

    bool m_UseTargetMachineFonts;
    bool m_UseTargetMachineFontsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_HtmlFixedSaveOptionsData_H_ */
