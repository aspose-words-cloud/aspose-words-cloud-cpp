
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TableProperties.h">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

#ifndef IO_SWAGGER_CLIENT_MODEL_TableProperties_H_
#define IO_SWAGGER_CLIENT_MODEL_TableProperties_H_


#include <cpprest/details/basic_types.h>
#include "LinkElement.h"
#include "WordsApiLink.h"
#include "PreferredWidth.h"

namespace io {
namespace swagger {
namespace client {
namespace model {

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
    /// Specifies how an inline table is aligned in the document.
    /// </summary>
    utility::string_t getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(utility::string_t value);
    /// <summary>
    /// Allows Microsoft Word and Aspose.Words to automatically resize cells in a table to fit their contents.
    /// </summary>
    bool isAllowAutoFit() const;
    bool allowAutoFitIsSet() const;
    void unsetAllowAutoFit();
    void setAllowAutoFit(bool value);
    /// <summary>
    /// Gets or sets whether this is a right-to-left table.
    /// </summary>
    bool isBidi() const;
    bool bidiIsSet() const;
    void unsetBidi();
    void setBidi(bool value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add below the contents of cells.
    /// </summary>
    double getBottomPadding() const;
    bool bottomPaddingIsSet() const;
    void unsetBottomPadding();
    void setBottomPadding(double value);
    /// <summary>
    /// Gets or sets the amount of space (in points) between the cells.
    /// </summary>
    double getCellSpacing() const;
    bool cellSpacingIsSet() const;
    void unsetCellSpacing();
    void setCellSpacing(double value);
    /// <summary>
    /// Gets or sets the value that represents the left indent of the table.
    /// </summary>
    double getLeftIndent() const;
    bool leftIndentIsSet() const;
    void unsetLeftIndent();
    void setLeftIndent(double value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add to the left of the contents of cells.
    /// </summary>
    double getLeftPadding() const;
    bool leftPaddingIsSet() const;
    void unsetLeftPadding();
    void setLeftPadding(double value);
    /// <summary>
    /// Gets or sets the table preferred width.  Preferred width can be specified as a percentage, number of points or a special \&quot;auto\&quot; value.
    /// </summary>
    std::shared_ptr<PreferredWidth> getPreferredWidth() const;
    bool preferredWidthIsSet() const;
    void unsetPreferredWidth();
    void setPreferredWidth(std::shared_ptr<PreferredWidth> value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add to the right of the contents of cells.
    /// </summary>
    double getRightPadding() const;
    bool rightPaddingIsSet() const;
    void unsetRightPadding();
    void setRightPadding(double value);
    /// <summary>
    /// Gets or sets the locale independent style identifier of the table style applied to this table.
    /// </summary>
    utility::string_t getStyleIdentifier() const;
    bool styleIdentifierIsSet() const;
    void unsetStyleIdentifier();
    void setStyleIdentifier(utility::string_t value);
    /// <summary>
    /// Gets or sets the name of the table style applied to this table.
    /// </summary>
    utility::string_t getStyleName() const;
    bool styleNameIsSet() const;
    void unsetStyleName();
    void setStyleName(utility::string_t value);
    /// <summary>
    /// Gets or sets bit flags that specify how a table style is applied to this table.
    /// </summary>
    utility::string_t getStyleOptions() const;
    bool styleOptionsIsSet() const;
    void unsetStyleOptions();
    void setStyleOptions(utility::string_t value);
    /// <summary>
    /// Get or sets TextWrapping  for table.
    /// </summary>
    utility::string_t getTextWrapping() const;
    bool textWrappingIsSet() const;
    void unsetTextWrapping();
    void setTextWrapping(utility::string_t value);
    /// <summary>
    /// Gets or sets the amount of space (in points) to add above the contents of cells.
    /// </summary>
    double getTopPadding() const;
    bool topPaddingIsSet() const;
    void unsetTopPadding();
    void setTopPadding(double value);

protected:
    utility::string_t m_Alignment;
    bool m_AlignmentIsSet;
    bool m_AllowAutoFit;
    bool m_AllowAutoFitIsSet;
    bool m_Bidi;
    bool m_BidiIsSet;
    double m_BottomPadding;
    bool m_BottomPaddingIsSet;
    double m_CellSpacing;
    bool m_CellSpacingIsSet;
    double m_LeftIndent;
    bool m_LeftIndentIsSet;
    double m_LeftPadding;
    bool m_LeftPaddingIsSet;
    std::shared_ptr<PreferredWidth> m_PreferredWidth;
    bool m_PreferredWidthIsSet;
    double m_RightPadding;
    bool m_RightPaddingIsSet;
    utility::string_t m_StyleIdentifier;
    bool m_StyleIdentifierIsSet;
    utility::string_t m_StyleName;
    bool m_StyleNameIsSet;
    utility::string_t m_StyleOptions;
    bool m_StyleOptionsIsSet;
    utility::string_t m_TextWrapping;
    bool m_TextWrappingIsSet;
    double m_TopPadding;
    bool m_TopPaddingIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_TableProperties_H_ */
