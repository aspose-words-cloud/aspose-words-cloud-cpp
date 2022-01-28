/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="shading.h">
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
#include "xml_color.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a paragraph format shading element.
    /// </summary>
    class Shading : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the shading texture.
        /// </summary>
        enum class Texture
        { 
            TEXTURE_NONE,
            TEXTURE_SOLID,
            TEXTURE5_PERCENT,
            TEXTURE10_PERCENT,
            TEXTURE20_PERCENT,
            TEXTURE25_PERCENT,
            TEXTURE30_PERCENT,
            TEXTURE40_PERCENT,
            TEXTURE50_PERCENT,
            TEXTURE60_PERCENT,
            TEXTURE70_PERCENT,
            TEXTURE75_PERCENT,
            TEXTURE80_PERCENT,
            TEXTURE90_PERCENT,
            TEXTURE_DARK_HORIZONTAL,
            TEXTURE_DARK_VERTICAL,
            TEXTURE_DARK_DIAGONAL_DOWN,
            TEXTURE_DARK_DIAGONAL_UP,
            TEXTURE_DARK_CROSS,
            TEXTURE_DARK_DIAGONAL_CROSS,
            TEXTURE_HORIZONTAL,
            TEXTURE_VERTICAL,
            TEXTURE_DIAGONAL_DOWN,
            TEXTURE_DIAGONAL_UP,
            TEXTURE_CROSS,
            TEXTURE_DIAGONAL_CROSS,
            TEXTURE2_PT5_PERCENT,
            TEXTURE7_PT5_PERCENT,
            TEXTURE12_PT5_PERCENT,
            TEXTURE15_PERCENT,
            TEXTURE17_PT5_PERCENT,
            TEXTURE22_PT5_PERCENT,
            TEXTURE27_PT5_PERCENT,
            TEXTURE32_PT5_PERCENT,
            TEXTURE35_PERCENT,
            TEXTURE37_PT5_PERCENT,
            TEXTURE42_PT5_PERCENT,
            TEXTURE45_PERCENT,
            TEXTURE47_PT5_PERCENT,
            TEXTURE52_PT5_PERCENT,
            TEXTURE55_PERCENT,
            TEXTURE57_PT5_PERCENT,
            TEXTURE62_PT5_PERCENT,
            TEXTURE65_PERCENT,
            TEXTURE67_PT5_PERCENT,
            TEXTURE72_PT5_PERCENT,
            TEXTURE77_PT5_PERCENT,
            TEXTURE82_PT5_PERCENT,
            TEXTURE85_PERCENT,
            TEXTURE87_PT5_PERCENT,
            TEXTURE92_PT5_PERCENT,
            TEXTURE95_PERCENT,
            TEXTURE97_PT5_PERCENT,
            TEXTURE_NIL
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~Shading() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the color that's applied to the background of the Shading object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getBackgroundPatternColor() const;

        /// <summary>
        /// Gets or sets the color that's applied to the background of the Shading object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBackgroundPatternColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


        /// <summary>
        /// Gets or sets the color that's applied to the foreground of the Shading object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::XmlColor > getForegroundPatternColor() const;

        /// <summary>
        /// Gets or sets the color that's applied to the foreground of the Shading object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setForegroundPatternColor(std::shared_ptr< aspose::words::cloud::models::XmlColor > value);


        /// <summary>
        /// Gets or sets the shading texture.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Shading::Texture > getTexture() const;

        /// <summary>
        /// Gets or sets the shading texture.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTexture(std::shared_ptr< aspose::words::cloud::models::Shading::Texture > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_BackgroundPatternColor;
        std::shared_ptr< aspose::words::cloud::models::XmlColor > m_ForegroundPatternColor;
        std::shared_ptr< aspose::words::cloud::models::Shading::Texture > m_Texture;
    };
}

