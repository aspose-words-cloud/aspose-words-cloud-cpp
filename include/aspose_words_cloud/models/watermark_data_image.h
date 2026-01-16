/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="watermark_data_image.h">
*   Copyright (c) 2026 Aspose.Words for Cloud
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
#include "model_base.h"
#include "file_reference.h"
#include "watermark_data_base.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Class for insert watermark image request building.
    /// </summary>
    class WatermarkDataImage : public WatermarkDataBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~WatermarkDataImage() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractWatermarkDataBase() override {}

        /// <summary>
        /// Gets or sets the watermark image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FileReference > getImage() const;

        /// <summary>
        /// Gets or sets the watermark image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImage(std::shared_ptr< aspose::words::cloud::models::FileReference > value);


        /// <summary>
        /// Gets or sets a boolean value which is responsible for washout effect of the watermark. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsWashout() const;

        /// <summary>
        /// Gets or sets a boolean value which is responsible for washout effect of the watermark. The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsWashout(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the scale factor expressed as a fraction of the image. The default value is 0 - auto.
        /// Valid values range from 0 to 65.5 inclusive. Auto scale means that the watermark will be scaled to its max width and max height relative to the page margins.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getScale() const;

        /// <summary>
        /// Gets or sets the scale factor expressed as a fraction of the image. The default value is 0 - auto.
        /// Valid values range from 0 to 65.5 inclusive. Auto scale means that the watermark will be scaled to its max width and max height relative to the page margins.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setScale(std::shared_ptr< double > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::FileReference > m_Image;
        std::shared_ptr< bool > m_IsWashout;
        std::shared_ptr< double > m_Scale;
    };
}

