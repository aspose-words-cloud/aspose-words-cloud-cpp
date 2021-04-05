/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="image_save_options_data.h">
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
#include "fixed_page_save_options_data.h"
#include "graphics_quality_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container abstract class for image save options.
    /// </summary>
    class ImageSaveOptionsData : public FixedPageSaveOptionsData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ImageSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets the additional System.Drawing.Graphics quality options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData > getGraphicsQualityOptions() const;

        /// <summary>
        /// Gets or sets the additional System.Drawing.Graphics quality options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setGraphicsQualityOptions(std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData > value);

        /// <summary>
        /// Gets or sets the horizontal resolution in dots per inch for the generated images.
        /// This property has effect only when saving to raster image formats.
        /// The default value is 96.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< double > getHorizontalResolution() const;

        /// <summary>
        /// Gets or sets the horizontal resolution in dots per inch for the generated images.
        /// This property has effect only when saving to raster image formats.
        /// The default value is 96.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setHorizontalResolution(std::shared_ptr< double > value);

        /// <summary>
        /// Gets or sets the brightness level of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< double > getImageBrightness() const;

        /// <summary>
        /// Gets or sets the brightness level of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setImageBrightness(std::shared_ptr< double > value);

        /// <summary>
        /// Gets or sets the color mode of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getImageColorMode() const;

        /// <summary>
        /// Gets or sets the color mode of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setImageColorMode(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the contrast level of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< double > getImageContrast() const;

        /// <summary>
        /// Gets or sets the contrast level of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setImageContrast(std::shared_ptr< double > value);

        /// <summary>
        /// Gets or sets the background (paper) color of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getPaperColor() const;

        /// <summary>
        /// Gets or sets the background (paper) color of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setPaperColor(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the pixel format of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getPixelFormat() const;

        /// <summary>
        /// Gets or sets the pixel format of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setPixelFormat(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets both horizontal and vertical resolution in dots per inch for the generated images.
        /// This property has effect only when saving to raster image formats.
        /// The default value is 96.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< double > getResolution() const;

        /// <summary>
        /// Gets or sets both horizontal and vertical resolution in dots per inch for the generated images.
        /// This property has effect only when saving to raster image formats.
        /// The default value is 96.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setResolution(std::shared_ptr< double > value);

        /// <summary>
        /// Gets or sets the zoom factor of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< double > getScale() const;

        /// <summary>
        /// Gets or sets the zoom factor of the image.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setScale(std::shared_ptr< double > value);

        /// <summary>
        /// Gets or sets a value indicating whether to use anti-aliasing for rendering.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getUseAntiAliasing() const;

        /// <summary>
        /// Gets or sets a value indicating whether to use anti-aliasing for rendering.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setUseAntiAliasing(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether to use GDI+ or Aspose.Words metafile renderer when saving to EMF.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getUseGdiEmfRenderer() const;

        /// <summary>
        /// Gets or sets a value indicating whether to use GDI+ or Aspose.Words metafile renderer when saving to EMF.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setUseGdiEmfRenderer(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether to use high quality (i.e. slow) rendering algorithms.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getUseHighQualityRendering() const;

        /// <summary>
        /// Gets or sets a value indicating whether to use high quality (i.e. slow) rendering algorithms.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setUseHighQualityRendering(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets the vertical resolution in dots per inch for the generated images.
        /// This property has effect only when saving to raster image formats.
        /// The default value is 96.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< double > getVerticalResolution() const;

        /// <summary>
        /// Gets or sets the vertical resolution in dots per inch for the generated images.
        /// This property has effect only when saving to raster image formats.
        /// The default value is 96.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setVerticalResolution(std::shared_ptr< double > value);

    protected:
        std::shared_ptr< aspose::words::cloud::models::GraphicsQualityOptionsData > m_GraphicsQualityOptions;
        std::shared_ptr< double > m_HorizontalResolution;
        std::shared_ptr< double > m_ImageBrightness;
        std::shared_ptr< std::wstring > m_ImageColorMode;
        std::shared_ptr< double > m_ImageContrast;
        std::shared_ptr< std::wstring > m_PaperColor;
        std::shared_ptr< std::wstring > m_PixelFormat;
        std::shared_ptr< double > m_Resolution;
        std::shared_ptr< double > m_Scale;
        std::shared_ptr< bool > m_UseAntiAliasing;
        std::shared_ptr< bool > m_UseGdiEmfRenderer;
        std::shared_ptr< bool > m_UseHighQualityRendering;
        std::shared_ptr< double > m_VerticalResolution;
    };
}

