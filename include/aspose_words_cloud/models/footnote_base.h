/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="footnote_base.h">
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
#include "document_position.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Footnote base class.
    /// </summary>
    class FootnoteBase : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the option, that specifies whether this is a footnote or endnote.
        /// </summary>
        enum class FootnoteType
        { 
            FOOTNOTE,
            ENDNOTE
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FootnoteBase() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        virtual void abstractFootnoteBase() = 0;

        /// <summary>
        /// Gets or sets the option, that specifies whether this is a footnote or endnote.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FootnoteBase::FootnoteType > getFootnoteType() const;

        /// <summary>
        /// Gets or sets the option, that specifies whether this is a footnote or endnote.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFootnoteType(std::shared_ptr< aspose::words::cloud::models::FootnoteBase::FootnoteType > value);


        /// <summary>
        /// Gets or sets the link to comment range start node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::DocumentPosition > getPosition() const;

        /// <summary>
        /// Gets or sets the link to comment range start node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPosition(std::shared_ptr< aspose::words::cloud::models::DocumentPosition > value);


        /// <summary>
        /// Gets or sets the custom reference mark to be used for this footnote.
        /// Default value is Empty, meaning auto-numbered footnotes are used.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getReferenceMark() const;

        /// <summary>
        /// Gets or sets the custom reference mark to be used for this footnote.
        /// Default value is Empty, meaning auto-numbered footnotes are used.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setReferenceMark(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets text of the footnote.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getText() const;

        /// <summary>
        /// Gets or sets text of the footnote.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setText(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::FootnoteBase::FootnoteType > m_FootnoteType;
        std::shared_ptr< aspose::words::cloud::models::DocumentPosition > m_Position;
        std::shared_ptr< std::wstring > m_ReferenceMark;
        std::shared_ptr< std::wstring > m_Text;
    };
}

