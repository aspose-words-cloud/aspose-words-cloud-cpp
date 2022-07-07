/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compress_options.h">
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
    /// Options of document compress.
    /// </summary>
    class CompressOptions : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~CompressOptions() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the quality level of images from 0 to 100. Default value is 75.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getImagesQuality() const;

        /// <summary>
        /// Gets or sets the quality level of images from 0 to 100. Default value is 75.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImagesQuality(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the resize factor of images.
        /// This value determines how many times the size of the images in the document will be reduced.
        /// The parameter value must be greater than 1 for resizing. Default value is 1 and has no effect on images size.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getImagesReduceSizeFactor() const;

        /// <summary>
        /// Gets or sets the resize factor of images.
        /// This value determines how many times the size of the images in the document will be reduced.
        /// The parameter value must be greater than 1 for resizing. Default value is 1 and has no effect on images size.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setImagesReduceSizeFactor(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< int32_t > m_ImagesQuality;
        std::shared_ptr< int32_t > m_ImagesReduceSizeFactor;
    };
}

