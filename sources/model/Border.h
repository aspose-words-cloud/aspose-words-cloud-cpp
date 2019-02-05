
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="Border.h">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

#ifndef IO_SWAGGER_CLIENT_MODEL_Border_H_
#define IO_SWAGGER_CLIENT_MODEL_Border_H_


#include "XmlColor.h"
#include <cpprest/details/basic_types.h>
#include "LinkElement.h"
#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
    utility::string_t getBorderType() const;
    bool borderTypeIsSet() const;
    void unsetBorderType();
    void setBorderType(utility::string_t value);
    /// <summary>
    /// Gets or sets the border color.             
    /// </summary>
    std::shared_ptr<XmlColor> getColor() const;
    bool colorIsSet() const;
    void unsetColor();
    void setColor(std::shared_ptr<XmlColor> value);
    /// <summary>
    /// Gets or sets distance of the border from text or from the page edge in points.
    /// </summary>
    double getDistanceFromText() const;
    bool distanceFromTextIsSet() const;
    void unsetDistanceFromText();
    void setDistanceFromText(double value);
    /// <summary>
    /// Gets or sets the border style.
    /// </summary>
    utility::string_t getLineStyle() const;
    bool lineStyleIsSet() const;
    void unsetLineStyle();
    void setLineStyle(utility::string_t value);
    /// <summary>
    /// Gets or sets the border width in points.
    /// </summary>
    double getLineWidth() const;
    bool lineWidthIsSet() const;
    void unsetLineWidth();
    void setLineWidth(double value);
    /// <summary>
    /// Gets or sets a value indicating whether the border has a shadow.
    /// </summary>
    bool isShadow() const;
    bool shadowIsSet() const;
    void unsetShadow();
    void setShadow(bool value);

protected:
    utility::string_t m_BorderType;
    bool m_BorderTypeIsSet;
    std::shared_ptr<XmlColor> m_Color;
    bool m_ColorIsSet;
    double m_DistanceFromText;
    bool m_DistanceFromTextIsSet;
    utility::string_t m_LineStyle;
    bool m_LineStyleIsSet;
    double m_LineWidth;
    bool m_LineWidthIsSet;
    bool m_Shadow;
    bool m_ShadowIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_Border_H_ */
