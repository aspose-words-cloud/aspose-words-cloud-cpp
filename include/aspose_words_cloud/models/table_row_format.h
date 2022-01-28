/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="table_row_format.h">
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
#include "link_element.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with formatting for a table row.
    /// </summary>
    class TableRowFormat : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the rule for determining the height of the table row.
        /// </summary>
        enum class HeightRule
        { 
            AT_LEAST,
            EXACTLY,
            AUTO
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TableRowFormat() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets a value indicating whether the text in a table row is allowed to split across a page break.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAllowBreakAcrossPages() const;

        /// <summary>
        /// Gets or sets a value indicating whether the text in a table row is allowed to split across a page break.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAllowBreakAcrossPages(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether the row is repeated as a table heading on every page when the table spans more than one page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getHeadingFormat() const;

        /// <summary>
        /// Gets or sets a value indicating whether the row is repeated as a table heading on every page when the table spans more than one page.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeadingFormat(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the height of the table row in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getHeight() const;

        /// <summary>
        /// Gets or sets the height of the table row in points.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeight(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the rule for determining the height of the table row.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableRowFormat::HeightRule > getHeightRule() const;

        /// <summary>
        /// Gets or sets the rule for determining the height of the table row.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHeightRule(std::shared_ptr< aspose::words::cloud::models::TableRowFormat::HeightRule > value);


    protected:
        std::shared_ptr< bool > m_AllowBreakAcrossPages;
        std::shared_ptr< bool > m_HeadingFormat;
        std::shared_ptr< double > m_Height;
        std::shared_ptr< aspose::words::cloud::models::TableRowFormat::HeightRule > m_HeightRule;
    };
}

