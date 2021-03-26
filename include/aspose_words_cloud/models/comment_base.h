/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="comment_base.h">
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
#include "document_position.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Comment.
    /// </summary>
    class CommentBase : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~CommentBase() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets the author name for a comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getAuthor();

        /// <summary>
        /// Gets or sets the author name for a comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setAuthor(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the date and time that the comment was made.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getDateTime();

        /// <summary>
        /// Gets or sets the date and time that the comment was made.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setDateTime(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the initials of the user associated with a specific comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getInitial();

        /// <summary>
        /// Gets or sets the initials of the user associated with a specific comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setInitial(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the link to comment range end node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::DocumentPosition > getRangeEnd();

        /// <summary>
        /// Gets or sets the link to comment range end node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setRangeEnd(std::shared_ptr< aspose::words::cloud::models::DocumentPosition > value);

        /// <summary>
        /// Gets or sets the link to comment range start node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::DocumentPosition > getRangeStart();

        /// <summary>
        /// Gets or sets the link to comment range start node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setRangeStart(std::shared_ptr< aspose::words::cloud::models::DocumentPosition > value);

        /// <summary>
        /// Gets or sets text of the comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getText();

        /// <summary>
        /// Gets or sets text of the comment.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setText(std::shared_ptr< std::wstring > value);

    protected:
        std::shared_ptr< std::wstring > m_Author;
        std::shared_ptr< std::wstring > m_DateTime;
        std::shared_ptr< std::wstring > m_Initial;
        std::shared_ptr< aspose::words::cloud::models::DocumentPosition > m_RangeEnd;
        std::shared_ptr< aspose::words::cloud::models::DocumentPosition > m_RangeStart;
        std::shared_ptr< std::wstring > m_Text;
    };
}

