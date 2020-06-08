/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellFormat.h">
*   Copyright (c) 2019 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_TableCellFormat_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_TableCellFormat_H_


#include "LinkElement.h"
#include "PreferredWidth.h"
#include "WordsApiLink.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents all formatting for a table row.
/// </summary>
class  TableCellFormat
    : public LinkElement
{
public:
    TableCellFormat();
    virtual ~TableCellFormat();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TableCellFormat members

    /// <summary>
    /// Gets or sets returns or sets the amount of space (in points) to add below the contents of cell.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getBottomPadding() const;
    bool bottomPaddingIsSet() const;
    void unsetBottomPadding();
    void setBottomPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets if true, fits text in the cell, compressing each paragraph to the width of the cell.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isFitText() const;
    bool fitTextIsSet() const;
    void unsetFitText();
    void setFitText(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies how the cell is merged horizontally with other cells in the row.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getHorizontalMerge() const;
    bool horizontalMergeIsSet() const;
    void unsetHorizontalMerge();
    void setHorizontalMerge(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the amount of space (in points) to add to the left of the contents of cell.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLeftPadding() const;
    bool leftPaddingIsSet() const;
    void unsetLeftPadding();
    void setLeftPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the orientation of text in a table cell.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getOrientation() const;
    bool orientationIsSet() const;
    void unsetOrientation();
    void setOrientation(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets PreferredWidth.
    /// </summary>
    <DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> getPreferredWidth() const;
    bool preferredWidthIsSet() const;
    void unsetPreferredWidth();
    void setPreferredWidth(<DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the amount of space (in points) to add to the right of the contents of cell.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getRightPadding() const;
    bool rightPaddingIsSet() const;
    void unsetRightPadding();
    void setRightPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the amount of space (in points) to add above the contents of cell.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getTopPadding() const;
    bool topPaddingIsSet() const;
    void unsetTopPadding();
    void setTopPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the vertical alignment of text in the cell.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getVerticalAlignment() const;
    bool verticalAlignmentIsSet() const;
    void unsetVerticalAlignment();
    void setVerticalAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies how the cell is merged with other cells vertically.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getVerticalMerge() const;
    bool verticalMergeIsSet() const;
    void unsetVerticalMerge();
    void setVerticalMerge(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the width of the cell in points.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getWidth() const;
    bool widthIsSet() const;
    void unsetWidth();
    void setWidth(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets if true, wrap text for the cell.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isWrapText() const;
    bool wrapTextIsSet() const;
    void unsetWrapText();
    void setWrapText(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_BottomPadding;
    bool m_BottomPaddingIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_FitText;
    bool m_FitTextIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_HorizontalMerge;
    bool m_HorizontalMergeIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LeftPadding;
    bool m_LeftPaddingIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Orientation;
    bool m_OrientationIsSet;
    <DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> m_PreferredWidth;
    bool m_PreferredWidthIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_RightPadding;
    bool m_RightPaddingIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_TopPadding;
    bool m_TopPaddingIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_VerticalAlignment;
    bool m_VerticalAlignmentIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_VerticalMerge;
    bool m_VerticalMergeIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_Width;
    bool m_WidthIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_WrapText;
    bool m_WrapTextIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TableCellFormat_H_ */
