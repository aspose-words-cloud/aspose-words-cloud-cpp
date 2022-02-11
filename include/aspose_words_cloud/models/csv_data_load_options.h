/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="csv_data_load_options.h">
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
    /// Represents options for parsing CSV data.
    /// </summary>
    class CsvDataLoadOptions : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~CsvDataLoadOptions() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the character that is used to comment lines of CSV data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getCommentChar() const;

        /// <summary>
        /// Gets or sets the character that is used to comment lines of CSV data.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCommentChar(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the character to be used as a column delimiter.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDelimiter() const;

        /// <summary>
        /// Gets or sets the character to be used as a column delimiter.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDelimiter(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether the first record of CSV data contains column names.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getHasHeaders() const;

        /// <summary>
        /// Gets or sets a value indicating whether the first record of CSV data contains column names.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHasHeaders(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the character that is used to quote field values.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getQuoteChar() const;

        /// <summary>
        /// Gets or sets the character that is used to quote field values.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setQuoteChar(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_CommentChar;
        std::shared_ptr< std::wstring > m_Delimiter;
        std::shared_ptr< bool > m_HasHeaders;
        std::shared_ptr< std::wstring > m_QuoteChar;
    };
}

