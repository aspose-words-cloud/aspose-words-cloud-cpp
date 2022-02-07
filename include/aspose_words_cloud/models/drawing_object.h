/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="drawing_object.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

#pragma once
#include "./model_base.h"
#include "drawing_object_link.h"
#include "words_api_link.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a DrawingObject.
    /// </summary>
    class DrawingObject : public DrawingObjectLink
    {
    public:
        /// <summary>
        /// Gets or sets the relative horizontal position, from which the distance to the image is measured.
        /// </summary>
        enum class RelativeHorizontalPosition
        { 
            MARGIN,
            PAGE,
            COLUMN,
            DEFAULT,
            CHARACTER,
            LEFT_MARGIN,
            RIGHT_MARGIN,
            INSIDE_MARGIN,
            OUTSIDE_MARGIN
        };

        /// <summary>
        /// Gets or sets the relative vertical position, from which the distance to the image is measured.
        /// </summary>
        enum class RelativeVerticalPosition
        { 
            MARGIN,
            TABLE_DEFAULT,
            PAGE,
            PARAGRAPH,
            TEXT_FRAME_DEFAULT,
            LINE,
            TOP_MARGIN,
            BOTTOM_MARGIN,
            INSIDE_MARGIN,
            OUTSIDE_MARGIN
        };

        /// <summary>
        /// Gets or sets the option that controls how to wrap text around the image.
        /// </summary>
        enum class WrapType
        { 
            INLINE,
            TOP_BOTTOM,
            SQUARE,
            NONE,
            TIGHT,
            THROUGH
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~DrawingObject() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the height of the DrawingObject in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getHeight() const;

        /// <summary>
        /// Gets or sets the height of the DrawingObject in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeight(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the link to image data. Can be null if shape does not have an image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::WordsApiLink > getImageDataLink() const;

        /// <summary>
        /// Gets or sets the link to image data. Can be null if shape does not have an image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImageDataLink(std::shared_ptr< aspose::words::cloud::models::WordsApiLink > value);


        /// <summary>
        /// Gets or sets the distance in points from the origin to the left side of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLeft() const;

        /// <summary>
        /// Gets or sets the distance in points from the origin to the left side of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLeft(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the link to OLE object. Can be null if shape does not have OLE data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::WordsApiLink > getOleDataLink() const;

        /// <summary>
        /// Gets or sets the link to OLE object. Can be null if shape does not have OLE data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOleDataLink(std::shared_ptr< aspose::words::cloud::models::WordsApiLink > value);


        /// <summary>
        /// Gets or sets the relative horizontal position, from which the distance to the image is measured.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::DrawingObject::RelativeHorizontalPosition > getRelativeHorizontalPosition() const;

        /// <summary>
        /// Gets or sets the relative horizontal position, from which the distance to the image is measured.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRelativeHorizontalPosition(std::shared_ptr< aspose::words::cloud::models::DrawingObject::RelativeHorizontalPosition > value);


        /// <summary>
        /// Gets or sets the relative vertical position, from which the distance to the image is measured.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::DrawingObject::RelativeVerticalPosition > getRelativeVerticalPosition() const;

        /// <summary>
        /// Gets or sets the relative vertical position, from which the distance to the image is measured.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRelativeVerticalPosition(std::shared_ptr< aspose::words::cloud::models::DrawingObject::RelativeVerticalPosition > value);


        /// <summary>
        /// Gets or sets the list of links that originate from this DrawingObjectDto.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::WordsApiLink>> > getRenderLinks() const;

        /// <summary>
        /// Gets or sets the list of links that originate from this DrawingObjectDto.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRenderLinks(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::WordsApiLink>> > value);


        /// <summary>
        /// Gets or sets the distance in points from the origin to the top side of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTop() const;

        /// <summary>
        /// Gets or sets the distance in points from the origin to the top side of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTop(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the width of the DrawingObjects in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getWidth() const;

        /// <summary>
        /// Gets or sets the width of the DrawingObjects in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setWidth(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the option that controls how to wrap text around the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::DrawingObject::WrapType > getWrapType() const;

        /// <summary>
        /// Gets or sets the option that controls how to wrap text around the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setWrapType(std::shared_ptr< aspose::words::cloud::models::DrawingObject::WrapType > value);


    protected:
        std::shared_ptr< double > m_Height;
        std::shared_ptr< aspose::words::cloud::models::WordsApiLink > m_ImageDataLink;
        std::shared_ptr< double > m_Left;
        std::shared_ptr< aspose::words::cloud::models::WordsApiLink > m_OleDataLink;
        std::shared_ptr< aspose::words::cloud::models::DrawingObject::RelativeHorizontalPosition > m_RelativeHorizontalPosition;
        std::shared_ptr< aspose::words::cloud::models::DrawingObject::RelativeVerticalPosition > m_RelativeVerticalPosition;
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::WordsApiLink>> > m_RenderLinks;
        std::shared_ptr< double > m_Top;
        std::shared_ptr< double > m_Width;
        std::shared_ptr< aspose::words::cloud::models::DrawingObject::WrapType > m_WrapType;
    };
}

