/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="HtmlFixedSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_HtmlFixedSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_HtmlFixedSaveOptionsData_H_


#include "FixedPageSaveOptionsData.h"
#include "MetafileRenderingOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for fixed html save options.
/// </summary>
class  HtmlFixedSaveOptionsData
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
    /// Gets or sets specifies prefix which is added to all class names in style.css file. Default value is \&quot;aw\&quot;.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getCssClassNamesPrefix() const;
    bool cssClassNamesPrefixIsSet() const;
    void unsetCssClassNamesPrefix();
    void setCssClassNamesPrefix(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets encoding.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getEncoding() const;
    bool encodingIsSet() const;
    void unsetEncoding();
    void setEncoding(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether the CSS (Cascading Style Sheet) should be embedded into Html document.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isExportEmbeddedCss() const;
    bool exportEmbeddedCssIsSet() const;
    void unsetExportEmbeddedCss();
    void setExportEmbeddedCss(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether fonts should be embedded into Html document in Base64 format.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isExportEmbeddedFonts() const;
    bool exportEmbeddedFontsIsSet() const;
    void unsetExportEmbeddedFonts();
    void setExportEmbeddedFonts(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether images should be embedded into Html document in Base64 format.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isExportEmbeddedImages() const;
    bool exportEmbeddedImagesIsSet() const;
    void unsetExportEmbeddedImages();
    void setExportEmbeddedImages(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets indication of whether form fields are exported as interactive items (as &#x27;input&#x27; tag) rather than converted to text or graphics.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isExportFormFields() const;
    bool exportFormFieldsIsSet() const;
    void unsetExportFormFields();
    void setExportFormFields(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies export format of fonts.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFontFormat() const;
    bool fontFormatIsSet() const;
    void unsetFontFormat();
    void setFontFormat(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the horizontal alignment of pages in an HTML document. Default value is HtmlFixedHorizontalPageAlignment.Center.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPageHorizontalAlignment() const;
    bool pageHorizontalAlignmentIsSet() const;
    void unsetPageHorizontalAlignment();
    void setPageHorizontalAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the margins around pages in an HTML document. The margins value is measured in points and should be equal to or greater than 0. Default value is 10 points.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getPageMargins() const;
    bool pageMarginsIsSet() const;
    void unsetPageMargins();
    void setPageMargins(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the physical folder where resources are saved when exporting a document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getResourcesFolder() const;
    bool resourcesFolderIsSet() const;
    void unsetResourcesFolder();
    void setResourcesFolder(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the name of the folder used to construct resource URIs.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getResourcesFolderAlias() const;
    bool resourcesFolderAliasIsSet() const;
    void unsetResourcesFolderAlias();
    void setResourcesFolderAlias(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets flag indicates whether \&quot;@font-face\&quot; CSS rules should be placed into a separate file \&quot;fontFaces.css\&quot; when a document is being saved with external stylesheet (that is, when Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedCss is false). Default value is false, all CSS rules are written into single file \&quot;styles.css\&quot;.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isSaveFontFaceCssSeparately() const;
    bool saveFontFaceCssSeparatelyIsSet() const;
    void unsetSaveFontFaceCssSeparately();
    void setSaveFontFaceCssSeparately(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies whether border around pages should be shown.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isShowPageBorder() const;
    bool showPageBorderIsSet() const;
    void unsetShowPageBorder();
    void setShowPageBorder(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets flag indicates whether fonts from target machine must be used to display the document. If this flag is set to true, Aspose.Words.Saving.HtmlFixedSaveOptions.FontFormat and Aspose.Words.Saving.HtmlFixedSaveOptions.ExportEmbeddedFonts properties do not have effect, also Aspose.Words.Saving.HtmlFixedSaveOptions.ResourceSavingCallback is not fired for fonts. Default is false.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isUseTargetMachineFonts() const;
    bool useTargetMachineFontsIsSet() const;
    void unsetUseTargetMachineFonts();
    void setUseTargetMachineFonts(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_CssClassNamesPrefix;
    bool m_CssClassNamesPrefixIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Encoding;
    bool m_EncodingIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ExportEmbeddedCss;
    bool m_ExportEmbeddedCssIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ExportEmbeddedFonts;
    bool m_ExportEmbeddedFontsIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ExportEmbeddedImages;
    bool m_ExportEmbeddedImagesIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ExportFormFields;
    bool m_ExportFormFieldsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FontFormat;
    bool m_FontFormatIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_PageHorizontalAlignment;
    bool m_PageHorizontalAlignmentIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_PageMargins;
    bool m_PageMarginsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ResourcesFolder;
    bool m_ResourcesFolderIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ResourcesFolderAlias;
    bool m_ResourcesFolderAliasIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_SaveFontFaceCssSeparately;
    bool m_SaveFontFaceCssSeparatelyIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_ShowPageBorder;
    bool m_ShowPageBorderIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_UseTargetMachineFonts;
    bool m_UseTargetMachineFontsIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_HtmlFixedSaveOptionsData_H_ */
