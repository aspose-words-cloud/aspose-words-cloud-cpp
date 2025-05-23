﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="structured_document_tag_list_item.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a SdtListItem for StructuredDocumentTag.
    /// </summary>
    class StructuredDocumentTagListItem : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StructuredDocumentTagListItem() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the text to display in the run content in place of the Aspose.Words.Markup.SdtListItem.Value attribute contents for this list item.
        /// Cannot be null and cannot be an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getDisplayText() const;

        /// <summary>
        /// Gets or sets the text to display in the run content in place of the Aspose.Words.Markup.SdtListItem.Value attribute contents for this list item.
        /// Cannot be null and cannot be an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDisplayText(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the value of this list item.
        /// Cannot be null and cannot be an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getValue() const;

        /// <summary>
        /// Gets or sets the value of this list item.
        /// Cannot be null and cannot be an empty string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setValue(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_DisplayText;
        std::shared_ptr< std::wstring > m_Value;
    };
}

