﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="table_cell_insert.h">
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
#include "position.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a table cell.
    /// </summary>
    class TableCellInsert : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TableCellInsert() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the position of the table cell that will be used to determine the placement of a new cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Position > getExistingCellPosition() const;

        /// <summary>
        /// Gets or sets the position of the table cell that will be used to determine the placement of a new cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setExistingCellPosition(std::shared_ptr< aspose::words::cloud::models::Position > value);


        /// <summary>
        /// Gets or sets the 0-based index, the table cell will be inserted after.
        /// </summary>
        [[deprecated("This property will be removed in the future.")]]
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getInsertAfter() const;

        /// <summary>
        /// Gets or sets the 0-based index, the table cell will be inserted after.
        /// </summary>
        [[deprecated("This property will be removed in the future.")]]
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setInsertAfter(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::Position > m_ExistingCellPosition;
        std::shared_ptr< int32_t > m_InsertAfter;
    };
}

