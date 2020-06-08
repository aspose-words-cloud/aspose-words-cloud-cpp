/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GraphicsQualityOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_GraphicsQualityOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_GraphicsQualityOptionsData_H_


#include "../ModelBase.h"

#include "StringFormatData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Allows to specify additional System.Drawing.Graphics quality options.
/// </summary>
class  GraphicsQualityOptionsData
    : public ModelBase
{
public:
    GraphicsQualityOptionsData();
    virtual ~GraphicsQualityOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// GraphicsQualityOptionsData members

    /// <summary>
    /// Gets or sets a value that specifies how composited images are drawn to this Graphics.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getCompositingMode() const;
    bool compositingModeIsSet() const;
    void unsetCompositingMode();
    void setCompositingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the rendering quality of composited images drawn to this Graphics.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getCompositingQuality() const;
    bool compositingQualityIsSet() const;
    void unsetCompositingQuality();
    void setCompositingQuality(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the interpolation mode associated with this Graphics.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getInterpolationMode() const;
    bool interpolationModeIsSet() const;
    void unsetInterpolationMode();
    void setInterpolationMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the rendering quality for this Graphics.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getSmoothingMode() const;
    bool smoothingModeIsSet() const;
    void unsetSmoothingMode();
    void setSmoothingMode(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets StringFormat.
    /// </summary>
    <DATA_TYPE_START>StringFormatData<DATA_TYPE_END> getStringFormat() const;
    bool stringFormatIsSet() const;
    void unsetStringFormat();
    void setStringFormat(<DATA_TYPE_START>StringFormatData<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the rendering mode for text associated with this Graphics.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTextRenderingHint() const;
    bool textRenderingHintIsSet() const;
    void unsetTextRenderingHint();
    void setTextRenderingHint(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_CompositingMode;
    bool m_CompositingModeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_CompositingQuality;
    bool m_CompositingQualityIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_InterpolationMode;
    bool m_InterpolationModeIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_SmoothingMode;
    bool m_SmoothingModeIsSet;
    <DATA_TYPE_START>StringFormatData<DATA_TYPE_END> m_StringFormat;
    bool m_StringFormatIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_TextRenderingHint;
    bool m_TextRenderingHintIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_GraphicsQualityOptionsData_H_ */
