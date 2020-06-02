/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ListLevelUpdate.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ListLevelUpdate_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ListLevelUpdate_H_

#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Represents a document list levels.
/// </summary>
class ListLevelUpdate
    : public ModelBase
{
public:
    ListLevelUpdate();
    virtual ~ListLevelUpdate();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ListLevelUpdate members

    /// <summary>
    /// Gets or sets the justification of the actual number of the list item.
    /// </summary>
    utility::string_t getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether true if the level turns all inherited numbers to Arabic, false if it preserves
    /// their number style.
    /// </summary>
    bool isIsLegal() const;
    bool isLegalIsSet() const;
    void unsetIsLegal();
    void setIsLegal(bool value);

    /// <summary>
    /// Gets or sets returns or sets the number format for the list level.
    /// </summary>
    utility::string_t getNumberFormat() const;
    bool numberFormatIsSet() const;
    void unsetNumberFormat();
    void setNumberFormat(utility::string_t value);

    /// <summary>
    /// Gets or sets returns or sets the position (in points) of the number or bullet for the list
    /// level.
    /// </summary>
    double getNumberPosition() const;
    bool numberPositionIsSet() const;
    void unsetNumberPosition();
    void setNumberPosition(double value);

    /// <summary>
    /// Gets or sets returns or sets the number style for this list level.
    /// </summary>
    utility::string_t getNumberStyle() const;
    bool numberStyleIsSet() const;
    void unsetNumberStyle();
    void setNumberStyle(utility::string_t value);

    /// <summary>
    /// Gets or sets or returns the list level that must appear before the specified list level
    /// restarts numbering.
    /// </summary>
    int32_t getRestartAfterLevel() const;
    bool restartAfterLevelIsSet() const;
    void unsetRestartAfterLevel();
    void setRestartAfterLevel(int32_t value);

    /// <summary>
    /// Gets or sets returns or sets the starting number for this list level.
    /// </summary>
    int32_t getStartAt() const;
    bool startAtIsSet() const;
    void unsetStartAt();
    void setStartAt(int32_t value);

    /// <summary>
    /// Gets or sets returns or sets the tab position (in points) for the list level.
    /// </summary>
    double getTabPosition() const;
    bool tabPositionIsSet() const;
    void unsetTabPosition();
    void setTabPosition(double value);

    /// <summary>
    /// Gets or sets returns or sets the position (in points) for the second line of wrapping text
    /// for the list level.
    /// </summary>
    double getTextPosition() const;
    bool textPositionIsSet() const;
    void unsetTextPosition();
    void setTextPosition(double value);

    /// <summary>
    /// Gets or sets returns or sets the character inserted after the number for the list level.
    /// </summary>
    utility::string_t getTrailingCharacter() const;
    bool trailingCharacterIsSet() const;
    void unsetTrailingCharacter();
    void setTrailingCharacter(utility::string_t value);

protected:
    utility::string_t m_Alignment;
    bool m_AlignmentIsSet;

    bool m_IsLegal;
    bool m_IsLegalIsSet;

    utility::string_t m_NumberFormat;
    bool m_NumberFormatIsSet;

    double m_NumberPosition;
    bool m_NumberPositionIsSet;

    utility::string_t m_NumberStyle;
    bool m_NumberStyleIsSet;

    int32_t m_RestartAfterLevel;
    bool m_RestartAfterLevelIsSet;

    int32_t m_StartAt;
    bool m_StartAtIsSet;

    double m_TabPosition;
    bool m_TabPositionIsSet;

    double m_TextPosition;
    bool m_TextPositionIsSet;

    utility::string_t m_TrailingCharacter;
    bool m_TrailingCharacterIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ListLevelUpdate_H_ */
