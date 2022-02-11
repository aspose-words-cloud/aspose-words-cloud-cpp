/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="downsample_options_data.h">
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
    /// Container class for Downsample options.
    /// </summary>
    class DownsampleOptionsData : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~DownsampleOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets a value indicating whether images should be downsampled.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getDownsampleImages() const;

        /// <summary>
        /// Gets or sets a value indicating whether images should be downsampled.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDownsampleImages(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the resolution in pixels per inch which the images should be downsampled to.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getResolution() const;

        /// <summary>
        /// Gets or sets the resolution in pixels per inch which the images should be downsampled to.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResolution(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the threshold resolution in pixels per inch. If resolution of an image in the document is less than threshold value, the downsampling algorithm will not be applied. A value of 0 means the threshold check is not used and all images that can be reduced in size are downsampled.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getResolutionThreshold() const;

        /// <summary>
        /// Gets or sets the threshold resolution in pixels per inch. If resolution of an image in the document is less than threshold value, the downsampling algorithm will not be applied. A value of 0 means the threshold check is not used and all images that can be reduced in size are downsampled.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResolutionThreshold(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< bool > m_DownsampleImages;
        std::shared_ptr< int32_t > m_Resolution;
        std::shared_ptr< int32_t > m_ResolutionThreshold;
    };
}

