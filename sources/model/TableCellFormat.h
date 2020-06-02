/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableCellFormat.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents all formatting for a table row.
/// </summary>
class TableCellFormat
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
    double getBottomPadding() const;
    bool bottomPaddingIsSet() const;
    void unsetBottomPadding();
    void setBottomPadding(double value);

    /// <summary>
    /// Gets or sets if true, fits text in the cell, compressing each paragraph to the width of the cell.
    /// </summary>
    bool isFitText() const;
    bool fitTextIsSet() const;
    void unsetFitText();
    void setFitText(bool value);

    /// <summary>
    /// Gets or sets specifies how the cell is merged horizontally with other cells in the row.
    /// </summary>
    utility::string_t getHorizontalMerge() const;
    bool horizontalMergeIsSet() const;
    void unsetHorizontalMerge();
    void setHorizontalMerge(utility::string_t value);

    /// <summary>
    /// Gets or sets returns or sets the amount of space (in points) to add to the left of the contents of cell.
    /// </summary>
    double getLeftPadding() const;
    bool leftPaddingIsSet() const;
    void unsetLeftPadding();
    void setLeftPadding(double value);

    /// <summary>
    /// Gets or sets returns or sets the orientation of text in a table cell.
    /// </summary>
    utility::string_t getOrientation() const;
    bool orientationIsSet() const;
    void unsetOrientation();
    void setOrientation(utility::string_t value);

    /// <summary>
    /// Gets or sets returns or sets the preferred width of the cell.
    /// </summary>
    std::shared_ptr<PreferredWidth> getPreferredWidth() const;
    bool preferredWidthIsSet() const;
    void unsetPreferredWidth();
    void setPreferredWidth(std::shared_ptr<PreferredWidth> value);

    /// <summary>
    /// Gets or sets returns or sets the amount of space (in points) to add to the right of the contents of cell.
    /// </summary>
    double getRightPadding() const;
    bool rightPaddingIsSet() const;
    void unsetRightPadding();
    void setRightPadding(double value);

    /// <summary>
    /// Gets or sets returns or sets the amount of space (in points) to add above the contents of cell.
    /// </summary>
    double getTopPadding() const;
    bool topPaddingIsSet() const;
    void unsetTopPadding();
    void setTopPadding(double value);

    /// <summary>
    /// Gets or sets returns or sets the vertical alignment of text in the cell.
    /// </summary>
    utility::string_t getVerticalAlignment() const;
    bool verticalAlignmentIsSet() const;
    void unsetVerticalAlignment();
    void setVerticalAlignment(utility::string_t value);

    /// <summary>
    /// Gets or sets specifies how the cell is merged with other cells vertically.
    /// </summary>
    utility::string_t getVerticalMerge() const;
    bool verticalMergeIsSet() const;
    void unsetVerticalMerge();
    void setVerticalMerge(utility::string_t value);

    /// <summary>
    /// Gets or sets the width of the cell in points.
    /// </summary>
    double getWidth() const;
    bool widthIsSet() const;
    void unsetWidth();
    void setWidth(double value);

    /// <summary>
    /// Gets or sets if true, wrap text for the cell.
    /// </summary>
    bool isWrapText() const;
    bool wrapTextIsSet() const;
    void unsetWrapText();
    void setWrapText(bool value);

protected:
    double m_BottomPadding;
    bool m_BottomPaddingIsSet;

    bool m_FitText;
    bool m_FitTextIsSet;

    utility::string_t m_HorizontalMerge;
    bool m_HorizontalMergeIsSet;

    double m_LeftPadding;
    bool m_LeftPaddingIsSet;

    utility::string_t m_Orientation;
    bool m_OrientationIsSet;

    std::shared_ptr<PreferredWidth> m_PreferredWidth;
    bool m_PreferredWidthIsSet;

    double m_RightPadding;
    bool m_RightPaddingIsSet;

    double m_TopPadding;
    bool m_TopPaddingIsSet;

    utility::string_t m_VerticalAlignment;
    bool m_VerticalAlignmentIsSet;

    utility::string_t m_VerticalMerge;
    bool m_VerticalMergeIsSet;

    double m_Width;
    bool m_WidthIsSet;

    bool m_WrapText;
    bool m_WrapTextIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TableCellFormat_H_ */
