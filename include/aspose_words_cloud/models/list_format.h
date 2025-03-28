﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="list_format.h">
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
#include "link_element.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a paragraph list format element.
    /// </summary>
    class ListFormat : public LinkElement
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ListFormat() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the list level number (0 to 8) for the paragraph.
        /// In Word documents, lists may consist of 1 or 9 levels, numbered 0 to 8. Has effect only when the Aspose.Words.ListFormat.List property is set to reference a valid list. Aspose.Words.ListFormat.List.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getListLevelNumber() const;

        /// <summary>
        /// Gets or sets the list level number (0 to 8) for the paragraph.
        /// In Word documents, lists may consist of 1 or 9 levels, numbered 0 to 8. Has effect only when the Aspose.Words.ListFormat.List property is set to reference a valid list. Aspose.Words.ListFormat.List.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListLevelNumber(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the list id of this paragraph.
        /// The list that is being assigned to this property must belong to the current document.The list that is being assigned to this property must not be a list style definition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getListId() const;

        /// <summary>
        /// Gets or sets the list id of this paragraph.
        /// The list that is being assigned to this property must belong to the current document.The list that is being assigned to this property must not be a list style definition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setListId(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets a value indicating whether the paragraph has bulleted or numbered formatting applied to it.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsListItem() const;

        /// <summary>
        /// Gets or sets a value indicating whether the paragraph has bulleted or numbered formatting applied to it.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsListItem(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< int32_t > m_ListLevelNumber;
        std::shared_ptr< int32_t > m_ListId;
        std::shared_ptr< bool > m_IsListItem;
    };
}

