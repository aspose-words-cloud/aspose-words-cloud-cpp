/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableProperties.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_TableProperties_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_TableProperties_H_


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
/// Represents the table properties.             
/// </summary>
class  TableProperties
    : public LinkElement
{
public:
    TableProperties();
    virtual ~TableProperties();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// TableProperties members

    /// <summary>
    /// Gets or sets specifies how an inline table is aligned in the document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets allows Microsoft Word and Aspose.Words to automatically resize cells in a table to fit their contents.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isAllowAutoFit() const;
    bool allowAutoFitIsSet() const;
    void unsetAllowAutoFit();
    void setAllowAutoFit(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets whether this is a right-to-left table.
    /// </summary>
    <DATA_TYPE_START>bool?<DATA_TYPE_END> isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(<DATA_TYPE_START>bool?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add below the contents of cells.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getBottomPadding() const;
    bool bottomPaddingIsSet() const;
    void unsetBottomPadding();
    void setBottomPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of space (in points) between the cells.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getCellSpacing() const;
    bool cellSpacingIsSet() const;
    void unsetCellSpacing();
    void setCellSpacing(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the value that represents the left indent of the table.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLeftIndent() const;
    bool leftIndentIsSet() const;
    void unsetLeftIndent();
    void setLeftIndent(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add to the left of the contents of cells.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getLeftPadding() const;
    bool leftPaddingIsSet() const;
    void unsetLeftPadding();
    void setLeftPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets PreferredWidth.
    /// </summary>
    <DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> getPreferredWidth() const;
    bool preferredWidthIsSet() const;
    void unsetPreferredWidth();
    void setPreferredWidth(<DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add to the right of the contents of cells.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getRightPadding() const;
    bool rightPaddingIsSet() const;
    void unsetRightPadding();
    void setRightPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the locale independent style identifier of the table style applied to this table.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleIdentifier() const;
    bool styleIdentifierIsSet() const;
    void unsetStyleIdentifier();
    void setStyleIdentifier(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the name of the table style applied to this table.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleName() const;
    bool styleNameIsSet() const;
    void unsetStyleName();
    void setStyleName(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets bit flags that specify how a table style is applied to this table.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getStyleOptions() const;
    bool styleOptionsIsSet() const;
    void unsetStyleOptions();
    void setStyleOptions(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets get or sets TextWrapping for table.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTextWrapping() const;
    bool textWrappingIsSet() const;
    void unsetTextWrapping();
    void setTextWrapping(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add above the contents of cells.
    /// </summary>
    <DATA_TYPE_START>double?<DATA_TYPE_END> getTopPadding() const;
    bool topPaddingIsSet() const;
    void unsetTopPadding();
    void setTopPadding(<DATA_TYPE_START>double?<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Alignment;
    bool m_AlignmentIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_AllowAutoFit;
    bool m_AllowAutoFitIsSet;
    <DATA_TYPE_START>bool?<DATA_TYPE_END> m_Bidi;
    bool m_BidiIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_BottomPadding;
    bool m_BottomPaddingIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_CellSpacing;
    bool m_CellSpacingIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LeftIndent;
    bool m_LeftIndentIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_LeftPadding;
    bool m_LeftPaddingIsSet;
    <DATA_TYPE_START>PreferredWidth<DATA_TYPE_END> m_PreferredWidth;
    bool m_PreferredWidthIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_RightPadding;
    bool m_RightPaddingIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleIdentifier;
    bool m_StyleIdentifierIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleName;
    bool m_StyleNameIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_StyleOptions;
    bool m_StyleOptionsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_TextWrapping;
    bool m_TextWrappingIsSet;
    <DATA_TYPE_START>double?<DATA_TYPE_END> m_TopPadding;
    bool m_TopPaddingIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_TableProperties_H_ */
