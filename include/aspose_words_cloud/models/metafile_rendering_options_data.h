/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="metafile_rendering_options_data.h">
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
    /// Container class for options of metafile rendering.
    /// </summary>
    class MetafileRenderingOptionsData : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls how EMF+ Dual metafiles should be rendered.
        /// </summary>
        enum class EmfPlusDualRenderingMode
        { 
            EMF_PLUS_WITH_FALLBACK,
            EMF_PLUS,
            EMF
        };

        /// <summary>
        /// Gets or sets the option that controls how metafile images should be rendered.
        /// </summary>
        enum class RenderingMode
        { 
            VECTOR_WITH_FALLBACK,
            VECTOR,
            BITMAP
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~MetafileRenderingOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the option that controls how EMF+ Dual metafiles should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData::EmfPlusDualRenderingMode > getEmfPlusDualRenderingMode() const;

        /// <summary>
        /// Gets or sets the option that controls how EMF+ Dual metafiles should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEmfPlusDualRenderingMode(std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData::EmfPlusDualRenderingMode > value);


        /// <summary>
        /// Gets or sets a value indicating whether the raster operations should be emulated.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getEmulateRasterOperations() const;

        /// <summary>
        /// Gets or sets a value indicating whether the raster operations should be emulated.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEmulateRasterOperations(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls how metafile images should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData::RenderingMode > getRenderingMode() const;

        /// <summary>
        /// Gets or sets the option that controls how metafile images should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRenderingMode(std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData::RenderingMode > value);


        /// <summary>
        /// Gets or sets a value indicating whether to scale fonts in WMF metafile according to metafile size on the page.
        /// The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getScaleWmfFontsToMetafileSize() const;

        /// <summary>
        /// Gets or sets a value indicating whether to scale fonts in WMF metafile according to metafile size on the page.
        /// The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setScaleWmfFontsToMetafileSize(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the flag, that controls how WMF metafiles with embedded EMF metafiles should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUseEmfEmbeddedToWmf() const;

        /// <summary>
        /// Gets or sets the flag, that controls how WMF metafiles with embedded EMF metafiles should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUseEmfEmbeddedToWmf(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData::EmfPlusDualRenderingMode > m_EmfPlusDualRenderingMode;
        std::shared_ptr< bool > m_EmulateRasterOperations;
        std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData::RenderingMode > m_RenderingMode;
        std::shared_ptr< bool > m_ScaleWmfFontsToMetafileSize;
        std::shared_ptr< bool > m_UseEmfEmbeddedToWmf;
    };
}

