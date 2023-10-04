/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="list_level_update.h">
*   Copyright (c) 2023 Aspose.Words for Cloud
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
    /// Represents a document list levels.
    /// </summary>
    class ListLevelUpdate : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets the number style for this list level.
        /// </summary>
        enum class NumberStyle
        { 
            ARABIC,
            UPPERCASE_ROMAN,
            LOWERCASE_ROMAN,
            UPPERCASE_LETTER,
            LOWERCASE_LETTER,
            ORDINAL,
            NUMBER,
            ORDINAL_TEXT,
            HEX,
            CHICAGO_MANUAL,
            KANJI,
            KANJI_DIGIT,
            AIUEO_HALF_WIDTH,
            IROHA_HALF_WIDTH,
            ARABIC_FULL_WIDTH,
            ARABIC_HALF_WIDTH,
            KANJI_TRADITIONAL,
            KANJI_TRADITIONAL2,
            NUMBER_IN_CIRCLE,
            DECIMAL_FULL_WIDTH,
            AIUEO,
            IROHA,
            LEADING_ZERO,
            BULLET,
            GANADA,
            CHOSUNG,
            G_B1,
            G_B2,
            G_B3,
            G_B4,
            ZODIAC1,
            ZODIAC2,
            ZODIAC3,
            TRAD_CHIN_NUM1,
            TRAD_CHIN_NUM2,
            TRAD_CHIN_NUM3,
            TRAD_CHIN_NUM4,
            SIMP_CHIN_NUM1,
            SIMP_CHIN_NUM2,
            SIMP_CHIN_NUM3,
            SIMP_CHIN_NUM4,
            HANJA_READ,
            HANJA_READ_DIGIT,
            HANGUL,
            HANJA,
            HEBREW1,
            ARABIC1,
            HEBREW2,
            ARABIC2,
            HINDI_LETTER1,
            HINDI_LETTER2,
            HINDI_ARABIC,
            HINDI_CARDINAL_TEXT,
            THAI_LETTER,
            THAI_ARABIC,
            THAI_CARDINAL_TEXT,
            VIET_CARDINAL_TEXT,
            NUMBER_IN_DASH,
            LOWERCASE_RUSSIAN,
            UPPERCASE_RUSSIAN,
            NONE,
            CUSTOM
        };

        /// <summary>
        /// Gets or sets the justification of the actual number of the list item.
        /// The list label is justified relative to the Aspose.Words.Lists.ListLevel.NumberPosition
        /// property.
        /// </summary>
        enum class Alignment
        { 
            LEFT,
            CENTER,
            RIGHT
        };

        /// <summary>
        /// Gets or sets the character to be inserted after the number for the list level.
        /// </summary>
        enum class TrailingCharacter
        { 
            TAB,
            SPACE,
            NOTHING
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ListLevelUpdate() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;


        /// <summary>
        /// Gets or sets the starting number for this list level.
        /// Default value is 1.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getStartAt() const;

        /// <summary>
        /// Gets or sets the starting number for this list level.
        /// Default value is 1.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStartAt(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the number style for this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::NumberStyle > getNumberStyle() const;

        /// <summary>
        /// Gets or sets the number style for this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNumberStyle(std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::NumberStyle > value);


        /// <summary>
        /// Gets or sets the number format for the list level.
        /// Among normal text characters, the string can contain placeholder characters \\x0000 to \\x0008 representing the numbers from the corresponding list levels. For example, the string "\\x0000.\\x0001)" will generate a list label that looks something like "1.5)". The number "1" is the current number from the 1st list level, the number "5" is the current number from the 2nd list level. Null is not allowed, but an empty string meaning no number is valid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNumberFormat() const;

        /// <summary>
        /// Gets or sets the number format for the list level.
        /// Among normal text characters, the string can contain placeholder characters \\x0000 to \\x0008 representing the numbers from the corresponding list levels. For example, the string "\\x0000.\\x0001)" will generate a list label that looks something like "1.5)". The number "1" is the current number from the 1st list level, the number "5" is the current number from the 2nd list level. Null is not allowed, but an empty string meaning no number is valid.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNumberFormat(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the justification of the actual number of the list item.
        /// The list label is justified relative to the Aspose.Words.Lists.ListLevel.NumberPosition
        /// property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::Alignment > getAlignment() const;

        /// <summary>
        /// Gets or sets the justification of the actual number of the list item.
        /// The list label is justified relative to the Aspose.Words.Lists.ListLevel.NumberPosition
        /// property.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlignment(std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::Alignment > value);


        /// <summary>
        /// Gets or sets a value indicating whether the level turns all inherited numbers to Arabic, false if it preserves their number style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsLegal() const;

        /// <summary>
        /// Gets or sets a value indicating whether the level turns all inherited numbers to Arabic, false if it preserves their number style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsLegal(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the list level that must appear before the specified list level restarts numbering.
        /// The value of -1 means the numbering will continue.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getRestartAfterLevel() const;

        /// <summary>
        /// Gets or sets the list level that must appear before the specified list level restarts numbering.
        /// The value of -1 means the numbering will continue.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRestartAfterLevel(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the character to be inserted after the number for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::TrailingCharacter > getTrailingCharacter() const;

        /// <summary>
        /// Gets or sets the character to be inserted after the number for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTrailingCharacter(std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::TrailingCharacter > value);


        /// <summary>
        /// Gets or sets the tab position (in points) for the list level.
        /// Has effect only when Aspose.Words.Lists.ListLevel.TrailingCharacter is a tab.
        /// Aspose.Words.Lists.ListLevel.NumberPosition Aspose.Words.Lists.ListLevel.TextPosition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTabPosition() const;

        /// <summary>
        /// Gets or sets the tab position (in points) for the list level.
        /// Has effect only when Aspose.Words.Lists.ListLevel.TrailingCharacter is a tab.
        /// Aspose.Words.Lists.ListLevel.NumberPosition Aspose.Words.Lists.ListLevel.TextPosition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTabPosition(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the position (in points) of the number or bullet for the list level.
        /// Aspose.Words.Lists.ListLevel.NumberPosition corresponds to LeftIndent plus FirstLineIndent of the paragraph. Aspose.Words.Lists.ListLevel.TextPosition Aspose.Words.Lists.ListLevel.TabPosition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getNumberPosition() const;

        /// <summary>
        /// Gets or sets the position (in points) of the number or bullet for the list level.
        /// Aspose.Words.Lists.ListLevel.NumberPosition corresponds to LeftIndent plus FirstLineIndent of the paragraph. Aspose.Words.Lists.ListLevel.TextPosition Aspose.Words.Lists.ListLevel.TabPosition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNumberPosition(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the position (in points) for the second line of wrapping text for the list level.
        /// Aspose.Words.Lists.ListLevel.TextPosition corresponds to LeftIndent of the paragraph.
        /// Aspose.Words.Lists.ListLevel.NumberPosition Aspose.Words.Lists.ListLevel.TabPosition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTextPosition() const;

        /// <summary>
        /// Gets or sets the position (in points) for the second line of wrapping text for the list level.
        /// Aspose.Words.Lists.ListLevel.TextPosition corresponds to LeftIndent of the paragraph.
        /// Aspose.Words.Lists.ListLevel.NumberPosition Aspose.Words.Lists.ListLevel.TabPosition.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextPosition(std::shared_ptr< double > value);


    protected:
        std::shared_ptr< int32_t > m_StartAt;
        std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::NumberStyle > m_NumberStyle;
        std::shared_ptr< std::wstring > m_NumberFormat;
        std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::Alignment > m_Alignment;
        std::shared_ptr< bool > m_IsLegal;
        std::shared_ptr< int32_t > m_RestartAfterLevel;
        std::shared_ptr< aspose::words::cloud::models::ListLevelUpdate::TrailingCharacter > m_TrailingCharacter;
        std::shared_ptr< double > m_TabPosition;
        std::shared_ptr< double > m_NumberPosition;
        std::shared_ptr< double > m_TextPosition;
    };
}

