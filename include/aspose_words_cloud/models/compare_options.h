/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="compare_options.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
    /// DTO container with compare documents options.
    /// </summary>
    class CompareOptions : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls which document shall be used as a target during comparison.
        /// </summary>
        enum class Target
        { 
            CURRENT,
            NEW
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~CompareOptions() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets a value indicating whether documents comparison is case insensitive. By default comparison is case sensitive.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreCaseChanges();

        /// <summary>
        /// Gets or sets a value indicating whether documents comparison is case insensitive. By default comparison is case sensitive.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreCaseChanges(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether comments content is ignored. By default comments are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreComments();

        /// <summary>
        /// Gets or sets a value indicating whether comments content is ignored. By default comments are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreComments(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether fields content is ignored. By default fields are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreFields();

        /// <summary>
        /// Gets or sets a value indicating whether fields content is ignored. By default fields are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreFields(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether footnotes/endnotes content is ignored. By default footnotes/endnotes are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreFootnotes();

        /// <summary>
        /// Gets or sets a value indicating whether footnotes/endnotes content is ignored. By default footnotes/endnotes are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreFootnotes(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether formatting is ignored. By default document formatting is not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreFormatting();

        /// <summary>
        /// Gets or sets a value indicating whether formatting is ignored. By default document formatting is not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreFormatting(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether headers and footers content is ignored. By default headers and footers are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreHeadersAndFooters();

        /// <summary>
        /// Gets or sets a value indicating whether headers and footers content is ignored. By default headers and footers are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreHeadersAndFooters(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether tables content is ignored. By default tables are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreTables();

        /// <summary>
        /// Gets or sets a value indicating whether tables content is ignored. By default tables are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreTables(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether textboxes content is ignored. By default textboxes are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getIgnoreTextboxes();

        /// <summary>
        /// Gets or sets a value indicating whether textboxes content is ignored. By default textboxes are not ignored.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setIgnoreTextboxes(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets the option that controls which document shall be used as a target during comparison.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::CompareOptions::Target > getTarget();

        /// <summary>
        /// Gets or sets the option that controls which document shall be used as a target during comparison.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setTarget(std::shared_ptr< aspose::words::cloud::models::CompareOptions::Target > value);

    protected:
        std::shared_ptr< bool > m_IgnoreCaseChanges;
        std::shared_ptr< bool > m_IgnoreComments;
        std::shared_ptr< bool > m_IgnoreFields;
        std::shared_ptr< bool > m_IgnoreFootnotes;
        std::shared_ptr< bool > m_IgnoreFormatting;
        std::shared_ptr< bool > m_IgnoreHeadersAndFooters;
        std::shared_ptr< bool > m_IgnoreTables;
        std::shared_ptr< bool > m_IgnoreTextboxes;
        std::shared_ptr< aspose::words::cloud::models::CompareOptions::Target > m_Target;
    };
}

