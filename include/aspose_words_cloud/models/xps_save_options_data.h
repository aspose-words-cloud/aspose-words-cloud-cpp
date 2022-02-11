/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="xps_save_options_data.h">
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
#include "fixed_page_save_options_data.h"
#include "outline_options_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for xps save options.
    /// </summary>
    class XpsSaveOptionsData : public FixedPageSaveOptionsData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~XpsSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractFixedPageSaveOptionsData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets the level in the XPS document outline at which to display Word bookmarks.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getBookmarksOutlineLevel() const;

        /// <summary>
        /// Gets or sets the level in the XPS document outline at which to display Word bookmarks.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBookmarksOutlineLevel(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the number of heading levels (paragraphs formatted with the Heading styles) to include in the XPS document outline.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getHeadingsOutlineLevels() const;

        /// <summary>
        /// Gets or sets the number of heading levels (paragraphs formatted with the Heading styles) to include in the XPS document outline.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeadingsOutlineLevels(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the outline options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::OutlineOptionsData > getOutlineOptions() const;

        /// <summary>
        /// Gets or sets the outline options.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOutlineOptions(std::shared_ptr< aspose::words::cloud::models::OutlineOptionsData > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



        /// <summary>
        /// Gets or sets a value indicating whether the document should be saved using a booklet printing layout.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getUseBookFoldPrintingSettings() const;

        /// <summary>
        /// Gets or sets a value indicating whether the document should be saved using a booklet printing layout.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setUseBookFoldPrintingSettings(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< int32_t > m_BookmarksOutlineLevel;
        std::shared_ptr< int32_t > m_HeadingsOutlineLevels;
        std::shared_ptr< aspose::words::cloud::models::OutlineOptionsData > m_OutlineOptions;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"xps");
        std::shared_ptr< bool > m_UseBookFoldPrintingSettings;
    };
}

