﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="svg_save_options_data.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
#include "fixed_page_save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for svg save options.
    /// </summary>
    class SvgSaveOptionsData : public FixedPageSaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls how text should be rendered.
        /// </summary>
        enum class TextOutputMode
        { 
            USE_SVG_FONTS,
            USE_TARGET_MACHINE_FONTS,
            USE_PLACED_GLYPHS
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~SvgSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractFixedPageSaveOptionsData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets a value indicating whether images should be embedded into SVG document as base64.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getExportEmbeddedImages() const;

        /// <summary>
        /// Gets or sets a value indicating whether images should be embedded into SVG document as base64.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExportEmbeddedImages(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the output SVG should fill the available viewport area (browser window or container). When set to true width and height of output SVG are set to 100%.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getFitToViewPort() const;

        /// <summary>
        /// Gets or sets a value indicating whether the output SVG should fill the available viewport area (browser window or container). When set to true width and height of output SVG are set to 100%.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFitToViewPort(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets specifies a prefix that is prepended to all generated element IDs in the output document.
        /// Default value is null and no prefix is prepended.
        /// If the prefix is specified, it can contain only letters, digits, underscores, and hyphens,
        /// and must start with a letter.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getIdPrefix() const;

        /// <summary>
        /// Gets or sets specifies a prefix that is prepended to all generated element IDs in the output document.
        /// Default value is null and no prefix is prepended.
        /// If the prefix is specified, it can contain only letters, digits, underscores, and hyphens,
        /// and must start with a letter.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIdPrefix(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value in pixels per inch that limits resolution of exported raster images.
        /// If the value of this property is non-zero, it limits resolution of exported raster images.
        /// That is, higher-resolution images are resampled down to the limit and lower-resolution images are exported as is.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getMaxImageResolution() const;

        /// <summary>
        /// Gets or sets a value in pixels per inch that limits resolution of exported raster images.
        /// If the value of this property is non-zero, it limits resolution of exported raster images.
        /// That is, higher-resolution images are resampled down to the limit and lower-resolution images are exported as is.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMaxImageResolution(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the physical folder where resources (images) are saved when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourcesFolder() const;

        /// <summary>
        /// Gets or sets the physical folder where resources (images) are saved when exporting.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourcesFolder(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getResourcesFolderAlias() const;

        /// <summary>
        /// Gets or sets the name of the folder used to construct image URIs.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setResourcesFolderAlias(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether to show or hide page stepper.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getShowPageBorder() const;

        /// <summary>
        /// Gets or sets a value indicating whether to show or hide page stepper.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setShowPageBorder(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls how text should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::SvgSaveOptionsData::TextOutputMode > getTextOutputMode() const;

        /// <summary>
        /// Gets or sets the option that controls how text should be rendered.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextOutputMode(std::shared_ptr< aspose::words::cloud::models::SvgSaveOptionsData::TextOutputMode > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



    protected:
        std::shared_ptr< bool > m_ExportEmbeddedImages;
        std::shared_ptr< bool > m_FitToViewPort;
        std::shared_ptr< std::wstring > m_IdPrefix;
        std::shared_ptr< int32_t > m_MaxImageResolution;
        std::shared_ptr< std::wstring > m_ResourcesFolder;
        std::shared_ptr< std::wstring > m_ResourcesFolderAlias;
        std::shared_ptr< bool > m_ShowPageBorder;
        std::shared_ptr< aspose::words::cloud::models::SvgSaveOptionsData::TextOutputMode > m_TextOutputMode;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"svg");
    };
}

