/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="fixed_page_save_options_data.h">
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
#include "metafile_rendering_options_data.h"
#include "save_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Contains common options that can be specified when saving a document into fixed page formats (PDF, XPS, images etc).
    /// </summary>
    class FixedPageSaveOptionsData : public SaveOptionsData
    {
    public:
        /// <summary>
        /// Gets or sets the value determining how colors are rendered.
        /// { Normal | Grayscale}.
        /// </summary>
        enum class ColorMode
        { 
            NORMAL,
            GRAYSCALE
        };

        /// <summary>
        /// Gets or sets the symbol set, that is used to represent numbers while rendering to fixed page formats.
        /// </summary>
        enum class NumeralFormat
        { 
            EUROPEAN,
            ARABIC_INDIC,
            EASTERN_ARABIC_INDIC,
            CONTEXT,
            SYSTEM
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FixedPageSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        virtual void abstractFixedPageSaveOptionsData() = 0;
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the value determining how colors are rendered.
        /// { Normal | Grayscale}.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FixedPageSaveOptionsData::ColorMode > getColorMode() const;

        /// <summary>
        /// Gets or sets the value determining how colors are rendered.
        /// { Normal | Grayscale}.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setColorMode(std::shared_ptr< aspose::words::cloud::models::FixedPageSaveOptionsData::ColorMode > value);


        /// <summary>
        /// Gets or sets the quality of the JPEG images inside PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getJpegQuality() const;

        /// <summary>
        /// Gets or sets the quality of the JPEG images inside PDF document.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setJpegQuality(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the metafile rendering options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData > getMetafileRenderingOptions() const;

        /// <summary>
        /// Gets or sets the metafile rendering options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMetafileRenderingOptions(std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData > value);


        /// <summary>
        /// Gets or sets the symbol set, that is used to represent numbers while rendering to fixed page formats.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FixedPageSaveOptionsData::NumeralFormat > getNumeralFormat() const;

        /// <summary>
        /// Gets or sets the symbol set, that is used to represent numbers while rendering to fixed page formats.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNumeralFormat(std::shared_ptr< aspose::words::cloud::models::FixedPageSaveOptionsData::NumeralFormat > value);


        /// <summary>
        /// Gets or sets a value indicating whether it is required to optimize output of XPS.
        /// If this flag is set redundant nested canvases and empty canvases are removed, also neighbor glyphs with the same formatting are concatenated.
        /// Note: The accuracy of the content display may be affected if this property is set to true.. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getOptimizeOutput() const;

        /// <summary>
        /// Gets or sets a value indicating whether it is required to optimize output of XPS.
        /// If this flag is set redundant nested canvases and empty canvases are removed, also neighbor glyphs with the same formatting are concatenated.
        /// Note: The accuracy of the content display may be affected if this property is set to true.. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOptimizeOutput(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the number of pages to render.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getPageCount() const;

        /// <summary>
        /// Gets or sets the number of pages to render.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageCount(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the 0-based index of the first page to render.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getPageIndex() const;

        /// <summary>
        /// Gets or sets the 0-based index of the first page to render.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPageIndex(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::FixedPageSaveOptionsData::ColorMode > m_ColorMode;
        std::shared_ptr< int32_t > m_JpegQuality;
        std::shared_ptr< aspose::words::cloud::models::MetafileRenderingOptionsData > m_MetafileRenderingOptions;
        std::shared_ptr< aspose::words::cloud::models::FixedPageSaveOptionsData::NumeralFormat > m_NumeralFormat;
        std::shared_ptr< bool > m_OptimizeOutput;
        std::shared_ptr< int32_t > m_PageCount;
        std::shared_ptr< int32_t > m_PageIndex;
    };
}

