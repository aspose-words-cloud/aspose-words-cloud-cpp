/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="structured_document_tag_insert.h">
*   Copyright (c) 2024 Aspose.Words for Cloud
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
#include "position.h"
#include "structured_document_tag_base.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a StructuredDocumentTag.
    /// </summary>
    class StructuredDocumentTagInsert : public StructuredDocumentTagBase
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


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StructuredDocumentTagInsert() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractStructuredDocumentTagBase() override {}



        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagInsert::Level > getLevel() const;

        /// <summary>
        /// Gets or sets the level at which this SDT occurs in the document tree.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLevel(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagInsert::Level > value);


        /// <summary>
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagInsert::SdtType > getSdtType() const;

        /// <summary>
        /// Gets or sets type of this Structured document tag.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSdtType(std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagInsert::SdtType > value);


        /// <summary>
        /// Gets or sets the position of the node that will be used to determine the placement of a new node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Position > getPosition() const;

        /// <summary>
        /// Gets or sets the position of the node that will be used to determine the placement of a new node.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPosition(std::shared_ptr< aspose::words::cloud::models::Position > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagInsert::Level > m_Level;
        std::shared_ptr< aspose::words::cloud::models::StructuredDocumentTagInsert::SdtType > m_SdtType;
        std::shared_ptr< aspose::words::cloud::models::Position > m_Position;
    };
}

