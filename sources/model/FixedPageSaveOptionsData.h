/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FixedPageSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_FixedPageSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_FixedPageSaveOptionsData_H_


#include "MetafileRenderingOptionsData.h"
#include "SaveOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Contains common options that can be specified when saving a document into fixed page formats (PDF, XPS, images etc).
/// </summary>
class  FixedPageSaveOptionsData
    : public SaveOptionsData
{
public:
    FixedPageSaveOptionsData();
    virtual ~FixedPageSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FixedPageSaveOptionsData members

    /// <summary>
    /// Gets or sets a value determining how colors are rendered. { Normal | Grayscale}.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getColorMode() const;
    bool colorModeIsSet() const;
    void unsetColorMode();
    void setColorMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines the quality of the JPEG images inside PDF document.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getJpegQuality() const;
    bool jpegQualityIsSet() const;
    void unsetJpegQuality();
    void setJpegQuality(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets MetafileRenderingOptions.
    /// </summary>
    <DATA_TYPE_START>MetafileRenderingOptionsData<DATA_TYPE_END> getMetafileRenderingOptions() const;
    bool metafileRenderingOptionsIsSet() const;
    void unsetMetafileRenderingOptions();
    void setMetafileRenderingOptions(<DATA_TYPE_START>MetafileRenderingOptionsData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets indicates the symbol set that is used to represent numbers while rendering to fixed page formats.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getNumeralFormat() const;
    bool numeralFormatIsSet() const;
    void unsetNumeralFormat();
    void setNumeralFormat(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets flag indicates whether it is required to optimize output of XPS. If this flag is set redundant nested canvases and empty canvases are removed, also neighbor glyphs with the same formatting are concatenated. Note: The accuracy of the content display may be affected if this property is set to true.  Default is false.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isOptimizeOutput() const;
    bool optimizeOutputIsSet() const;
    void unsetOptimizeOutput();
    void setOptimizeOutput(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines number of pages to render.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getPageCount() const;
    bool pageCountIsSet() const;
    void unsetPageCount();
    void setPageCount(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets determines 0-based index of the first page to render.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getPageIndex() const;
    bool pageIndexIsSet() const;
    void unsetPageIndex();
    void setPageIndex(<DATA_TYPE_START>int?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_ColorMode;
    bool m_ColorModeIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_JpegQuality;
    bool m_JpegQualityIsSet;
    <DATA_TYPE_START>MetafileRenderingOptionsData<DATA_TYPE_END> m_MetafileRenderingOptions;
    bool m_MetafileRenderingOptionsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_NumeralFormat;
    bool m_NumeralFormatIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_OptimizeOutput;
    bool m_OptimizeOutputIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_PageCount;
    bool m_PageCountIsSet;
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_PageIndex;
    bool m_PageIndexIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FixedPageSaveOptionsData_H_ */
