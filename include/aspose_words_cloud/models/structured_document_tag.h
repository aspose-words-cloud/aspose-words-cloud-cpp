/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="structured_document_tag.h">
*   Copyright (c) 2026 Aspose.Words for Cloud
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
#include "structured_document_tag_base.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a StructuredDocumentTag.
    /// </summary>
    class StructuredDocumentTag : public StructuredDocumentTagBase
    {
    public:
        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        enum class Level
        { 
            UNKNOWN,
            INLINE,
            BLOCK,
            ROW,
            CELL
        };

        /// <summary>
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        enum class SdtType
        { 
            NONE,
            BIBLIOGRAPHY,
            CITATION,
            EQUATION,
            DROP_DOWN_LIST,
            COMBO_BOX,
            DATE,
            BUILDING_BLOCK_GALLERY,
            DOC_PART_OBJ,
            GROUP,
            PICTURE,
            RICH_TEXT,
            PLAIN_TEXT,
            CHECKBOX,
            REPEATING_SECTION,
            REPEATING_SECTION_ITEM,
            ENTITY_PICKER
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StructuredDocumentTag() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractStructuredDocumentTagBase() override {}



        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Level > getLevel() const;

        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLevel(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Level > value);


        /// <summary>
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::SdtType > getSdtType() const;

        /// <summary>
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSdtType(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::SdtType > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::Level > m_Level;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTag::SdtType > m_SdtType;
    };
}

