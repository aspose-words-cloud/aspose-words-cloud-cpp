/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="watermark_text.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Class for insert watermark text request building.
    /// </summary>
    class WatermarkText : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~WatermarkText() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the watermark rotation angle.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getRotationAngle() const;

        /// <summary>
        /// Gets or sets the watermark rotation angle.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRotationAngle(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the watermark text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getText() const;

        /// <summary>
        /// Gets or sets the watermark text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setText(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< double > m_RotationAngle;
        std::shared_ptr< std::wstring > m_Text;
    };
}

