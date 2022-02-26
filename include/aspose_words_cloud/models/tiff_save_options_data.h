/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="tiff_save_options_data.h">
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
#include "image_save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for tiff save options.
    /// </summary>
    class TiffSaveOptionsData : public ImageSaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the method used while converting images to 1 bpp format.
        /// </summary>
        enum class TiffBinarizationMethod
        { 
            THRESHOLD,
            FLOYD_STEINBERG_DITHERING
        };

        /// <summary>
        /// Gets or sets the type of compression.
        /// </summary>
        enum class TiffCompression
        { 
            NONE,
            RLE,
            LZW,
            CCITT3,
            CCITT4
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TiffSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractImageSaveOptionsData() override {}
        void abstractFixedPageSaveOptionsData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



        /// <summary>
        /// Gets or sets the threshold that determines the value of the binarization error in the Floyd-Steinberg method. when ImageBinarizationMethod is ImageBinarizationMethod.FloydSteinbergDithering.
        /// Default value is 128.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getThresholdForFloydSteinbergDithering() const;

        /// <summary>
        /// Gets or sets the threshold that determines the value of the binarization error in the Floyd-Steinberg method. when ImageBinarizationMethod is ImageBinarizationMethod.FloydSteinbergDithering.
        /// Default value is 128.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setThresholdForFloydSteinbergDithering(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the method used while converting images to 1 bpp format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData::TiffBinarizationMethod > getTiffBinarizationMethod() const;

        /// <summary>
        /// Gets or sets the method used while converting images to 1 bpp format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTiffBinarizationMethod(std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData::TiffBinarizationMethod > value);


        /// <summary>
        /// Gets or sets the type of compression.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData::TiffCompression > getTiffCompression() const;

        /// <summary>
        /// Gets or sets the type of compression.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTiffCompression(std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData::TiffCompression > value);


    protected:
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"tiff");
        std::shared_ptr< int32_t > m_ThresholdForFloydSteinbergDithering;
        std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData::TiffBinarizationMethod > m_TiffBinarizationMethod;
        std::shared_ptr< aspose::words::cloud::models::TiffSaveOptionsData::TiffCompression > m_TiffCompression;
    };
}

