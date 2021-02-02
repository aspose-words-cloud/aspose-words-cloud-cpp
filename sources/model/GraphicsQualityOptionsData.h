/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="GraphicsQualityOptionsData.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#include "StringFormatData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Allows to specify additional System.Drawing.Graphics quality options.
/// </summary>
class GraphicsQualityOptionsData
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
    /// Gets or sets the value, that specifies how composited images are drawn to this Graphics.
    /// </summary>
    utility::string_t getCompositingMode() const;
    bool compositingModeIsSet() const;
    void unsetCompositingMode();
    void setCompositingMode(utility::string_t value);

    /// <summary>
    /// Gets or sets the rendering quality of composited images drawn to this Graphics.
    /// </summary>
    utility::string_t getCompositingQuality() const;
    bool compositingQualityIsSet() const;
    void unsetCompositingQuality();
    void setCompositingQuality(utility::string_t value);

    /// <summary>
    /// Gets or sets the interpolation mode associated with this Graphics.
    /// </summary>
    utility::string_t getInterpolationMode() const;
    bool interpolationModeIsSet() const;
    void unsetInterpolationMode();
    void setInterpolationMode(utility::string_t value);

    /// <summary>
    /// Gets or sets the rendering quality for this Graphics.
    /// </summary>
    utility::string_t getSmoothingMode() const;
    bool smoothingModeIsSet() const;
    void unsetSmoothingMode();
    void setSmoothingMode(utility::string_t value);

    /// <summary>
    /// Gets or sets text layout information (such as alignment, orientation and tab stops) display manipulations (such as ellipsis insertion and national digit substitution) and OpenType features.
    /// </summary>
    std::shared_ptr<StringFormatData> getStringFormat() const;
    bool stringFormatIsSet() const;
    void unsetStringFormat();
    void setStringFormat(std::shared_ptr<StringFormatData> value);

    /// <summary>
    /// Gets or sets the rendering mode for text associated with this Graphics.
    /// </summary>
    utility::string_t getTextRenderingHint() const;
    bool textRenderingHintIsSet() const;
    void unsetTextRenderingHint();
    void setTextRenderingHint(utility::string_t value);

protected:
    utility::string_t m_CompositingMode;
    bool m_CompositingModeIsSet;

    utility::string_t m_CompositingQuality;
    bool m_CompositingQualityIsSet;

    utility::string_t m_InterpolationMode;
    bool m_InterpolationModeIsSet;

    utility::string_t m_SmoothingMode;
    bool m_SmoothingModeIsSet;

    std::shared_ptr<StringFormatData> m_StringFormat;
    bool m_StringFormatIsSet;

    utility::string_t m_TextRenderingHint;
    bool m_TextRenderingHintIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_GraphicsQualityOptionsData_H_ */
