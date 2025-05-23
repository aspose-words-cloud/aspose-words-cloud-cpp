﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="bookmark_insert.h">
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
#include "position.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents a bookmark to insert.
    /// </summary>
    class BookmarkInsert : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~BookmarkInsert() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the name of the bookmark.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getName() const;

        /// <summary>
        /// Gets or sets the name of the bookmark.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets text, enclosed in the bookmark.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getText() const;

        /// <summary>
        /// Gets or sets text, enclosed in the bookmark.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setText(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the link to start bookmark node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Position > getStartRange() const;

        /// <summary>
        /// Gets or sets the link to start bookmark node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStartRange(std::shared_ptr< aspose::words::cloud::models::Position > value);


        /// <summary>
        /// Gets or sets the link to end bookmark node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Position > getEndRange() const;

        /// <summary>
        /// Gets or sets the link to end bookmark node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setEndRange(std::shared_ptr< aspose::words::cloud::models::Position > value);


    protected:
        std::shared_ptr< std::wstring > m_Name;
        std::shared_ptr< std::wstring > m_Text;
        std::shared_ptr< aspose::words::cloud::models::Position > m_StartRange;
        std::shared_ptr< aspose::words::cloud::models::Position > m_EndRange;
    };
}

