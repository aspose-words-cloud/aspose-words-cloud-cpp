/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="border.h">
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
#include "link_element.h"
#include "xml_color.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents a border of an object.
    /// </summary>
    class Border : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the border type.
        /// </summary>
        enum class BorderType
        { 
            BOTTOM,
            LEFT,
            RIGHT,
            TOP,
            HORIZONTAL,
            VERTICAL,
            DIAGONAL_DOWN,
            DIAGONAL_UP,
            NONE
        };

        /// <summary>
        /// Gets or sets the border style.
        /// </summary>
        enum class LineStyle
        { 
            NONE,
            SINGLE,
            THICK,
            DOUBLE,
            HAIRLINE,
            DOT,
            DASH_LARGE_GAP,
            DOT_DASH,
            DOT_DOT_DASH,
            TRIPLE,
            THIN_THICK_SMALL_GAP,
            THICK_THIN_SMALL_GAP,
            THIN_THICK_THIN_SMALL_GAP,
            THIN_THICK_MEDIUM_GAP,
            THICK_THIN_MEDIUM_GAP,
            THIN_THICK_THIN_MEDIUM_GAP,
            THIN_THICK_LARGE_GAP,
            THICK_THIN_LARGE_GAP,
            THIN_THICK_THIN_LARGE_GAP,
            WAVE,
            DOUBLE_WAVE,
            DASH_SMALL_GAP,
            DASH_DOT_STROKER,
            EMBOSS3_D,
            ENGRAVE3_D,
            OUTSET,
            INSET
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~Border() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the border type.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Border::BorderType > getBorderType() const;

        /// <summary>
        /// Gets or sets the border type.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBorderType(std::shared_ptr< aspose::words::cloud::models::Border::BorderType > value);


        /// <summary>
        /// Gets or sets the border color.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getColor() const;

        /// <summary>
        /// Gets or sets the border color.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


        /// <summary>
        /// Gets or sets the distance of the border from text or from the page edge in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getDistanceFromText() const;

        /// <summary>
        /// Gets or sets the distance of the border from text or from the page edge in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDistanceFromText(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the border style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Border::LineStyle > getLineStyle() const;

        /// <summary>
        /// Gets or sets the border style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineStyle(std::shared_ptr< aspose::words::cloud::models::Border::LineStyle > value);


        /// <summary>
        /// Gets or sets the border width in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLineWidth() const;

        /// <summary>
        /// Gets or sets the border width in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLineWidth(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether the border has a shadow.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getShadow() const;

        /// <summary>
        /// Gets or sets a value indicating whether the border has a shadow.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setShadow(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::Border::BorderType > m_BorderType;
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_Color;
        std::shared_ptr< double > m_DistanceFromText;
        std::shared_ptr< aspose::words::cloud::models::Border::LineStyle > m_LineStyle;
        std::shared_ptr< double > m_LineWidth;
        std::shared_ptr< bool > m_Shadow;
    };
}

