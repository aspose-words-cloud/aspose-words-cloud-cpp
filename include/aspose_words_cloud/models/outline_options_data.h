/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="outline_options_data.h">
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
#include "bookmarks_outline_level_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for outline options.
    /// </summary>
    class OutlineOptionsData : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~OutlineOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the individual bookmarks outline level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::BookmarksOutlineLevelData>> > getBookmarksOutlineLevels() const;

        /// <summary>
        /// Gets or sets the individual bookmarks outline level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBookmarksOutlineLevels(std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::BookmarksOutlineLevelData>> > value);


        /// <summary>
        /// Gets or sets a value indicating whether to create missing outline levels when the document is exported. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getCreateMissingOutlineLevels() const;

        /// <summary>
        /// Gets or sets a value indicating whether to create missing outline levels when the document is exported. The default value is false.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCreateMissingOutlineLevels(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether to create outlines for headings (paragraphs formatted with the Heading styles) inside tables.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getCreateOutlinesForHeadingsInTables() const;

        /// <summary>
        /// Gets or sets a value indicating whether to create outlines for headings (paragraphs formatted with the Heading styles) inside tables.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCreateOutlinesForHeadingsInTables(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the default level in the document outline at which to display Word bookmarks.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getDefaultBookmarksOutlineLevel() const;

        /// <summary>
        /// Gets or sets the default level in the document outline at which to display Word bookmarks.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDefaultBookmarksOutlineLevel(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the number of levels in the document outline to show expanded when the file is viewed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getExpandedOutlineLevels() const;

        /// <summary>
        /// Gets or sets the number of levels in the document outline to show expanded when the file is viewed.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExpandedOutlineLevels(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the number of levels of headings (paragraphs formatted with the Heading styles) to include in the document outline.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getHeadingsOutlineLevels() const;

        /// <summary>
        /// Gets or sets the number of levels of headings (paragraphs formatted with the Heading styles) to include in the document outline.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeadingsOutlineLevels(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< std::vector<std::shared_ptr<aspose::words::cloud::models::BookmarksOutlineLevelData>> > m_BookmarksOutlineLevels;
        std::shared_ptr< bool > m_CreateMissingOutlineLevels;
        std::shared_ptr< bool > m_CreateOutlinesForHeadingsInTables;
        std::shared_ptr< int32_t > m_DefaultBookmarksOutlineLevel;
        std::shared_ptr< int32_t > m_ExpandedOutlineLevels;
        std::shared_ptr< int32_t > m_HeadingsOutlineLevels;
    };
}

