/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="list_insert.h">
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
    /// Insert document to document list.
    /// </summary>
    class ListInsert : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls how list should be restarted at each section.
        /// </summary>
        enum class Template
        { 
            BULLET_DEFAULT,
            BULLET_DISK,
            BULLET_CIRCLE,
            BULLET_SQUARE,
            BULLET_DIAMONDS,
            BULLET_ARROW_HEAD,
            BULLET_TICK,
            NUMBER_DEFAULT,
            NUMBER_ARABIC_DOT,
            NUMBER_ARABIC_PARENTHESIS,
            NUMBER_UPPERCASE_ROMAN_DOT,
            NUMBER_UPPERCASE_LETTER_DOT,
            NUMBER_LOWERCASE_LETTER_PARENTHESIS,
            NUMBER_LOWERCASE_LETTER_DOT,
            NUMBER_LOWERCASE_ROMAN_DOT,
            OUTLINE_NUMBERS,
            OUTLINE_LEGAL,
            OUTLINE_BULLETS,
            OUTLINE_HEADINGS_ARTICLE_SECTION,
            OUTLINE_HEADINGS_LEGAL,
            OUTLINE_HEADINGS_NUMBERS,
            OUTLINE_HEADINGS_CHAPTER
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ListInsert() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the option that controls how list should be restarted at each section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListInsert::Template > getTemplate() const;

        /// <summary>
        /// Gets or sets the option that controls how list should be restarted at each section.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTemplate(std::shared_ptr< aspose::words::cloud::models::ListInsert::Template > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::ListInsert::Template > m_Template;
    };
}

