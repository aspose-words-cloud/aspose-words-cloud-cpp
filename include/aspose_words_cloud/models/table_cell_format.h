/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="table_cell_format.h">
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
#include "link_element.h"
#include "preferred_width.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with all formatting for a table row.
    /// </summary>
    class TableCellFormat : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the option that controls how the cell is merged horizontally with other cells in the row.
        /// </summary>
        enum class HorizontalMerge
        { 
            NONE,
            FIRST,
            PREVIOUS
        };

        /// <summary>
        /// Gets or sets the orientation of text in a table cell.
        /// </summary>
        enum class Orientation
        { 
            HORIZONTAL,
            DOWNWARD,
            UPWARD,
            HORIZONTAL_ROTATED_FAR_EAST,
            VERTICAL_FAR_EAST,
            VERTICAL_ROTATED_FAR_EAST
        };

        /// <summary>
        /// Gets or sets the vertical alignment of text in the cell.
        /// </summary>
        enum class VerticalAlignment
        { 
            TOP,
            CENTER,
            BOTTOM
        };

        /// <summary>
        /// Gets or sets the option that controls how the cell is merged with other cells vertically.
        /// Cells can only be merged vertically if their left and right boundaries are identical.When cells are vertically merged, the display areas of the merged cells are consolidated. The consolidated area is used to display the contents of the first vertically merged cell and all other vertically merged cells must be empty.
        /// </summary>
        enum class VerticalMerge
        { 
            NONE,
            FIRST,
            PREVIOUS
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TableCellFormat() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets the amount of space (in points) to add below the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getBottomPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add below the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBottomPadding(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether to fit text in the cell, compress each paragraph to the width of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getFitText() const;

        /// <summary>
        /// Gets or sets a value indicating whether to fit text in the cell, compress each paragraph to the width of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFitText(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the option that controls how the cell is merged horizontally with other cells in the row.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableCellFormat::HorizontalMerge > getHorizontalMerge() const;

        /// <summary>
        /// Gets or sets the option that controls how the cell is merged horizontally with other cells in the row.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setHorizontalMerge(std::shared_ptr< aspose::words::cloud::models::TableCellFormat::HorizontalMerge > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the left of the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getLeftPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the left of the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLeftPadding(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the orientation of text in a table cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableCellFormat::Orientation > getOrientation() const;

        /// <summary>
        /// Gets or sets the orientation of text in a table cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOrientation(std::shared_ptr< aspose::words::cloud::models::TableCellFormat::Orientation > value);


        /// <summary>
        /// Gets or sets the preferred width of the cell.
        /// The preferred width (along with the table's Auto Fit option) determines how the actual width of the cell is calculated by the table layout algorithm. Table layout can be performed by Aspose.Words when it saves the document or by Microsoft Word when it displays the document.The preferred width can be specified in points or in percent. The preferred width can also be specified as "auto", which means no preferred width is specified.The default value is Auto.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::PreferredWidth > getPreferredWidth() const;

        /// <summary>
        /// Gets or sets the preferred width of the cell.
        /// The preferred width (along with the table's Auto Fit option) determines how the actual width of the cell is calculated by the table layout algorithm. Table layout can be performed by Aspose.Words when it saves the document or by Microsoft Word when it displays the document.The preferred width can be specified in points or in percent. The preferred width can also be specified as "auto", which means no preferred width is specified.The default value is Auto.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPreferredWidth(std::shared_ptr< aspose::words::cloud::models::PreferredWidth > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the right of the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getRightPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add to the right of the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRightPadding(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the amount of space (in points) to add above the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTopPadding() const;

        /// <summary>
        /// Gets or sets the amount of space (in points) to add above the contents of the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTopPadding(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the vertical alignment of text in the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableCellFormat::VerticalAlignment > getVerticalAlignment() const;

        /// <summary>
        /// Gets or sets the vertical alignment of text in the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setVerticalAlignment(std::shared_ptr< aspose::words::cloud::models::TableCellFormat::VerticalAlignment > value);


        /// <summary>
        /// Gets or sets the option that controls how the cell is merged with other cells vertically.
        /// Cells can only be merged vertically if their left and right boundaries are identical.When cells are vertically merged, the display areas of the merged cells are consolidated. The consolidated area is used to display the contents of the first vertically merged cell and all other vertically merged cells must be empty.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::TableCellFormat::VerticalMerge > getVerticalMerge() const;

        /// <summary>
        /// Gets or sets the option that controls how the cell is merged with other cells vertically.
        /// Cells can only be merged vertically if their left and right boundaries are identical.When cells are vertically merged, the display areas of the merged cells are consolidated. The consolidated area is used to display the contents of the first vertically merged cell and all other vertically merged cells must be empty.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setVerticalMerge(std::shared_ptr< aspose::words::cloud::models::TableCellFormat::VerticalMerge > value);


        /// <summary>
        /// Gets or sets the width of the cell in points.
        /// The width is calculated by Aspose.Words on document loading and saving. Currently, not every combination of table, cell and document properties is supported. The returned value may not be accurate for some documents. It may not exactly match the cell width as calculated by MS Word when the document is opened in MS Word.Setting this property is not recommended. There is no guarantee that the cell will actually have the set width. The width may be adjusted to accommodate cell contents in an auto-fit table layout. Cells in other rows may have conflicting width settings. The table may be resized to fit into the container or to meet table width settings. Consider using PreferredWidth for setting the cell width. Setting this property sets PreferredWidth implicitly since version 15.8.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getWidth() const;

        /// <summary>
        /// Gets or sets the width of the cell in points.
        /// The width is calculated by Aspose.Words on document loading and saving. Currently, not every combination of table, cell and document properties is supported. The returned value may not be accurate for some documents. It may not exactly match the cell width as calculated by MS Word when the document is opened in MS Word.Setting this property is not recommended. There is no guarantee that the cell will actually have the set width. The width may be adjusted to accommodate cell contents in an auto-fit table layout. Cells in other rows may have conflicting width settings. The table may be resized to fit into the container or to meet table width settings. Consider using PreferredWidth for setting the cell width. Setting this property sets PreferredWidth implicitly since version 15.8.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setWidth(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets a value indicating whether to wrap text in the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getWrapText() const;

        /// <summary>
        /// Gets or sets a value indicating whether to wrap text in the cell.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setWrapText(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< double > m_BottomPadding;
        std::shared_ptr< bool > m_FitText;
        std::shared_ptr< aspose::words::cloud::models::TableCellFormat::HorizontalMerge > m_HorizontalMerge;
        std::shared_ptr< double > m_LeftPadding;
        std::shared_ptr< aspose::words::cloud::models::TableCellFormat::Orientation > m_Orientation;
        std::shared_ptr< aspose::words::cloud::models::PreferredWidth > m_PreferredWidth;
        std::shared_ptr< double > m_RightPadding;
        std::shared_ptr< double > m_TopPadding;
        std::shared_ptr< aspose::words::cloud::models::TableCellFormat::VerticalAlignment > m_VerticalAlignment;
        std::shared_ptr< aspose::words::cloud::models::TableCellFormat::VerticalMerge > m_VerticalMerge;
        std::shared_ptr< double > m_Width;
        std::shared_ptr< bool > m_WrapText;
    };
}

