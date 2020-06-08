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
    utility::string_t getColorMode() const;
    bool colorModeIsSet() const;
    void unsetColorMode();
    void setColorMode(utility::string_t value);
    /// <summary>
    /// Gets or sets determines the quality of the JPEG images inside PDF document.
    /// </summary>
    int32_t getJpegQuality() const;
    bool jpegQualityIsSet() const;
    void unsetJpegQuality();
    void setJpegQuality(int32_t value);
    /// <summary>
    /// Gets or sets MetafileRenderingOptions.
    /// </summary>
    std::shared_ptr<MetafileRenderingOptionsData> getMetafileRenderingOptions() const;
    bool metafileRenderingOptionsIsSet() const;
    void unsetMetafileRenderingOptions();
    void setMetafileRenderingOptions(std::shared_ptr<MetafileRenderingOptionsData> value);
    /// <summary>
    /// Gets or sets indicates the symbol set that is used to represent numbers while rendering to fixed page formats.
    /// </summary>
    utility::string_t getNumeralFormat() const;
    bool numeralFormatIsSet() const;
    void unsetNumeralFormat();
    void setNumeralFormat(utility::string_t value);
    /// <summary>
    /// Gets or sets flag indicates whether it is required to optimize output of XPS. If this flag is set redundant nested canvases and empty canvases are removed, also neighbor glyphs with the same formatting are concatenated. Note: The accuracy of the content display may be affected if this property is set to true.  Default is false.
    /// </summary>
    bool isOptimizeOutput() const;
    bool optimizeOutputIsSet() const;
    void unsetOptimizeOutput();
    void setOptimizeOutput(bool value);
    /// <summary>
    /// Gets or sets determines number of pages to render.
    /// </summary>
    int32_t getPageCount() const;
    bool pageCountIsSet() const;
    void unsetPageCount();
    void setPageCount(int32_t value);
    /// <summary>
    /// Gets or sets determines 0-based index of the first page to render.
    /// </summary>
    int32_t getPageIndex() const;
    bool pageIndexIsSet() const;
    void unsetPageIndex();
    void setPageIndex(int32_t value);

protected:
    utility::string_t m_ColorMode;
    bool m_ColorModeIsSet;
    int32_t m_JpegQuality;
    bool m_JpegQualityIsSet;
    std::shared_ptr<MetafileRenderingOptionsData> m_MetafileRenderingOptions;
    bool m_MetafileRenderingOptionsIsSet;
    utility::string_t m_NumeralFormat;
    bool m_NumeralFormatIsSet;
    bool m_OptimizeOutput;
    bool m_OptimizeOutputIsSet;
    int32_t m_PageCount;
    bool m_PageCountIsSet;
    int32_t m_PageIndex;
    bool m_PageIndexIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FixedPageSaveOptionsData_H_ */
