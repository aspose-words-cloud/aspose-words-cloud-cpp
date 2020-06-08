/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Border.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_Border_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_Border_H_


#include "LinkElement.h"
#include "WordsApiLink.h"
#include "XmlColor.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents a border of an object.
/// </summary>
class  Border
    : public LinkElement
{
public:
    Border();
    virtual ~Border();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// Border members

    /// <summary>
    /// Gets or sets the border type.             
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getBorderType() const;
    bool borderTypeIsSet() const;
    void unsetBorderType();
    void setBorderType(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets Color.
    /// </summary>
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> getColor() const;
    bool colorIsSet() const;
    void unsetColor();
    void setColor(<DATA_TYPE_START>XmlColor<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets distance of the border from text or from the page edge in points.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getDistanceFromText() const;
    bool distanceFromTextIsSet() const;
    void unsetDistanceFromText();
    void setDistanceFromText(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the border style.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getLineStyle() const;
    bool lineStyleIsSet() const;
    void unsetLineStyle();
    void setLineStyle(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the border width in points.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLineWidth() const;
    bool lineWidthIsSet() const;
    void unsetLineWidth();
    void setLineWidth(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a value indicating whether the border has a shadow.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isShadow() const;
    bool shadowIsSet() const;
    void unsetShadow();
    void setShadow(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_BorderType;
    bool m_BorderTypeIsSet;
    <DATA_TYPE_START>XmlColor<DATA_TYPE_END> m_Color;
    bool m_ColorIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_DistanceFromText;
    bool m_DistanceFromTextIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_LineStyle;
    bool m_LineStyleIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LineWidth;
    bool m_LineWidthIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Shadow;
    bool m_ShadowIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_Border_H_ */
