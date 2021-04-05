/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="graphics_quality_options_data.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
#include "string_format_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Allows to specify additional System.Drawing.Graphics quality options.
    /// </summary>
    class GraphicsQualityOptionsData : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the value, that specifies how composited images are drawn to this Graphics.
        /// </summary>
        enum class CompositingMode
        { 
            SOURCE_OVER,
            SOURCE_COPY
        };

        /// <summary>
        /// Gets or sets the rendering quality of composited images drawn to this Graphics.
        /// </summary>
        enum class CompositingQuality
        { 
            DEFAULT,
            HIGH_SPEED,
            HIGH_QUALITY,
            GAMMA_CORRECTED,
            ASSUME_LINEAR,
            INVALID
        };

        /// <summary>
        /// Gets or sets the interpolation mode associated with this Graphics.
        /// </summary>
        enum class InterpolationMode
        { 
            DEFAULT,
            LOW,
            HIGH,
            BILINEAR,
            BICUBIC,
            NEAREST_NEIGHBOR,
            HIGH_QUALITY_BILINEAR,
            HIGH_QUALITY_BICUBIC,
            INVALID
        };

        /// <summary>
        /// Gets or sets the rendering quality for this Graphics.
        /// </summary>
        enum class SmoothingMode
        { 
            DEFAULT,
            HIGH_SPEED,
            HIGH_QUALITY,
            NONE,
            ANTI_ALIAS,
            INVALID
        };

        /// <summary>
        /// Gets or sets the rendering mode for text associated with this Graphics.
        /// </summary>
        enum class TextRenderingHint
        { 
            SYSTEM_DEFAULT,
            SINGLE_BIT_PER_PIXEL_GRID_FIT,
            SINGLE_BIT_PER_PIXEL,
            ANTI_ALIAS_GRID_FIT,
            ANTI_ALIAS,
            CLEAR_TYPE_GRID_FIT
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~GraphicsQualityOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets the value, that specifies how composited images are drawn to this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::CompositingMode > getCompositingMode() const;

        /// <summary>
        /// Gets or sets the value, that specifies how composited images are drawn to this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setCompositingMode(std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::CompositingMode > value);

        /// <summary>
        /// Gets or sets the rendering quality of composited images drawn to this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::CompositingQuality > getCompositingQuality() const;

        /// <summary>
        /// Gets or sets the rendering quality of composited images drawn to this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setCompositingQuality(std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::CompositingQuality > value);

        /// <summary>
        /// Gets or sets the interpolation mode associated with this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::InterpolationMode > getInterpolationMode() const;

        /// <summary>
        /// Gets or sets the interpolation mode associated with this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setInterpolationMode(std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::InterpolationMode > value);

        /// <summary>
        /// Gets or sets the rendering quality for this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::SmoothingMode > getSmoothingMode() const;

        /// <summary>
        /// Gets or sets the rendering quality for this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setSmoothingMode(std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::SmoothingMode > value);

        /// <summary>
        /// Gets or sets text layout information (such as alignment, orientation and tab stops) display manipulations (such as ellipsis insertion and national digit substitution) and OpenType features.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::StringFormatData > getStringFormat() const;

        /// <summary>
        /// Gets or sets text layout information (such as alignment, orientation and tab stops) display manipulations (such as ellipsis insertion and national digit substitution) and OpenType features.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setStringFormat(std::shared_ptr< aspose::words::cloud::models::StringFormatData > value);

        /// <summary>
        /// Gets or sets the rendering mode for text associated with this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::TextRenderingHint > getTextRenderingHint() const;

        /// <summary>
        /// Gets or sets the rendering mode for text associated with this Graphics.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setTextRenderingHint(std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::TextRenderingHint > value);

    protected:
        std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::CompositingMode > m_CompositingMode;
        std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::CompositingQuality > m_CompositingQuality;
        std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::InterpolationMode > m_InterpolationMode;
        std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::SmoothingMode > m_SmoothingMode;
        std::shared_ptr< aspose::words::cloud::models::StringFormatData > m_StringFormat;
        std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData::TextRenderingHint > m_TextRenderingHint;
    };
}

