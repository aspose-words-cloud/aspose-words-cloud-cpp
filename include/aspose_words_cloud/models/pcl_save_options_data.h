﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="pcl_save_options_data.h">
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
    /// Container class for pcl save options.
    /// </summary>
    class PclSaveOptionsData : public FixedPageSaveOptionsData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~PclSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractFixedPageSaveOptionsData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the font name, that will be used if no expected font is found in printer and built-in fonts collections.
        /// If no fallback is found, "Arial" font is used.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFalllbackFontName() const;

        /// <summary>
        /// Gets or sets the font name, that will be used if no expected font is found in printer and built-in fonts collections.
        /// If no fallback is found, "Arial" font is used.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFalllbackFontName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether complex transformed elements should be rasterized before saving to PCL document.. The default value is true.
        /// PCL doesn't support some kind of transformations that are used by Aspose Words.  E.g. rotated, skewed images and texture brushes. To properly render such elements rasterization process is used, i.e. saving to image and clipping.  This process can take additional time and memory.  If flag is set to false, some content in output may be different as compared with the source document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getRasterizeTransformedElements() const;

        /// <summary>
        /// Gets or sets a value indicating whether complex transformed elements should be rasterized before saving to PCL document.. The default value is true.
        /// PCL doesn't support some kind of transformations that are used by Aspose Words.  E.g. rotated, skewed images and texture brushes. To properly render such elements rasterization process is used, i.e. saving to image and clipping.  This process can take additional time and memory.  If flag is set to false, some content in output may be different as compared with the source document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRasterizeTransformedElements(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



    protected:
        std::shared_ptr< std::wstring > m_FalllbackFontName;
        std::shared_ptr< bool > m_RasterizeTransformedElements;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"pcl");
    };
}

