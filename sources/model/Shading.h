/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Shading.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_Shading_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_Shading_H_


#include "../ModelBase.h"

#include "XmlColor.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Paragraph format shading element.             
/// </summary>
class  Shading
    : public ModelBase
{
public:
    Shading();
    virtual ~Shading();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Shading members

    /// <summary>
    /// Gets or sets BackgroundPatternColor.
    /// </summary>
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> getBackgroundPatternColor() const;
    bool backgroundPatternColorIsSet() const;
    void unsetBackgroundPatternColor();
    void setBackgroundPatternColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets ForegroundPatternColor.
    /// </summary>
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> getForegroundPatternColor() const;
    bool foregroundPatternColorIsSet() const;
    void unsetForegroundPatternColor();
    void setForegroundPatternColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the shading texture.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTexture() const;
    bool textureIsSet() const;
    void unsetTexture();
    void setTexture(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> m_BackgroundPatternColor;
    bool m_BackgroundPatternColorIsSet;
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> m_ForegroundPatternColor;
    bool m_ForegroundPatternColorIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Texture;
    bool m_TextureIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_Shading_H_ */
