/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="footnotes_stat_data.h">
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
    /// Container for the footnotes statistical data.
    /// </summary>
    class FootnotesStatData : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FootnotesStatData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the total count of paragraphs in footnotes.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getParagraphCount() const;

        /// <summary>
        /// Gets or sets the total count of paragraphs in footnotes.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setParagraphCount(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the total count of words in footnotes.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getWordCount() const;

        /// <summary>
        /// Gets or sets the total count of words in footnotes.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setWordCount(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< int32_t > m_ParagraphCount;
        std::shared_ptr< int32_t > m_WordCount;
    };
}

