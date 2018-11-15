
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DrawingObject.h">
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

#ifndef IO_SWAGGER_CLIENT_MODEL_DrawingObject_H_
#define IO_SWAGGER_CLIENT_MODEL_DrawingObject_H_


#include <cpprest/details/basic_types.h>
#include "DrawingObjectLink.h"
#include <vector>
#include "WordsApiLink.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

/// <summary>
/// Represents Drawing Object DTO.
/// </summary>
class  DrawingObject
    : public DrawingObjectLink
{
public:
    DrawingObject();
    virtual ~DrawingObject();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DrawingObject members

    /// <summary>
    /// Height of the drawing object in points.
    /// </summary>
    double getHeight() const;
    bool heightIsSet() const;
    void unsetHeight();
    void setHeight(double value);
    /// <summary>
    /// Link to image data. Can be null if shape does not have an image.
    /// </summary>
    std::shared_ptr<WordsApiLink> getImageDataLink() const;
    bool imageDataLinkIsSet() const;
    void unsetImageDataLink();
    void setImageDataLink(std::shared_ptr<WordsApiLink> value);
    /// <summary>
    /// Distance in points from the origin to the left side of the image.             
    /// </summary>
    double getLeft() const;
    bool leftIsSet() const;
    void unsetLeft();
    void setLeft(double value);
    /// <summary>
    /// Link to ole object. Can be null if shape does not have ole data.
    /// </summary>
    std::shared_ptr<WordsApiLink> getOleDataLink() const;
    bool oleDataLinkIsSet() const;
    void unsetOleDataLink();
    void setOleDataLink(std::shared_ptr<WordsApiLink> value);
    /// <summary>
    /// Specifies where the distance to the image is measured from.             
    /// </summary>
    utility::string_t getRelativeHorizontalPosition() const;
    bool relativeHorizontalPositionIsSet() const;
    void unsetRelativeHorizontalPosition();
    void setRelativeHorizontalPosition(utility::string_t value);
    /// <summary>
    /// Specifies where the distance to the image measured from.
    /// </summary>
    utility::string_t getRelativeVerticalPosition() const;
    bool relativeVerticalPositionIsSet() const;
    void unsetRelativeVerticalPosition();
    void setRelativeVerticalPosition(utility::string_t value);
    /// <summary>
    /// A list of links that originate from this .
    /// </summary>
    std::vector<std::shared_ptr<WordsApiLink>>& getRenderLinks();
    bool renderLinksIsSet() const;
    void unsetRenderLinks();
    void setRenderLinks(std::vector<std::shared_ptr<WordsApiLink>> value);
    /// <summary>
    /// Distance in points from the origin to the top side of the image.
    /// </summary>
    double getTop() const;
    bool topIsSet() const;
    void unsetTop();
    void setTop(double value);
    /// <summary>
    /// Width of the drawing objects in points.
    /// </summary>
    double getWidth() const;
    bool widthIsSet() const;
    void unsetWidth();
    void setWidth(double value);
    /// <summary>
    /// Specifies how to wrap text around the image.
    /// </summary>
    utility::string_t getWrapType() const;
    bool wrapTypeIsSet() const;
    void unsetWrapType();
    void setWrapType(utility::string_t value);

protected:
    double m_Height;
    bool m_HeightIsSet;
    std::shared_ptr<WordsApiLink> m_ImageDataLink;
    bool m_ImageDataLinkIsSet;
    double m_Left;
    bool m_LeftIsSet;
    std::shared_ptr<WordsApiLink> m_OleDataLink;
    bool m_OleDataLinkIsSet;
    utility::string_t m_RelativeHorizontalPosition;
    bool m_RelativeHorizontalPositionIsSet;
    utility::string_t m_RelativeVerticalPosition;
    bool m_RelativeVerticalPositionIsSet;
    std::vector<std::shared_ptr<WordsApiLink>> m_RenderLinks;
    bool m_RenderLinksIsSet;
    double m_Top;
    bool m_TopIsSet;
    double m_Width;
    bool m_WidthIsSet;
    utility::string_t m_WrapType;
    bool m_WrapTypeIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_DrawingObject_H_ */
