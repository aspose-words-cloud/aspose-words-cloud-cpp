/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="list_level.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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
#include "./model_base.h"
#include "font.h"
#include "link_element.h"
#include "style.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// DTO container with a document list level.
    /// </summary>
    class ListLevel : public LinkElement
    {
    public:
        /// <summary>
        /// Gets or sets the justification of the actual number of the list item.
        /// </summary>
        enum class Alignment
        { 
            LEFT,
            CENTER,
            RIGHT
        };

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
        /// Gets or sets the character inserted after the number for the list level.
        /// </summary>
        enum class TrailingCharacter
        { 
            TAB,
            SPACE,
            NOTHING
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ListLevel() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the justification of the actual number of the list item.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevel::Alignment > getAlignment() const;

        /// <summary>
        /// Gets or sets the justification of the actual number of the list item.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlignment(std::shared_ptr< aspose::words::cloud::models::ListLevel::Alignment > value);


        /// <summary>
        /// Gets or sets character formatting used for the list label.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Font > getFont() const;

        /// <summary>
        /// Gets or sets character formatting used for the list label.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFont(std::shared_ptr< aspose::words::cloud::models::Font > value);


        /// <summary>
        /// Gets or sets a value indicating whether the level turns all inherited numbers to Arabic, false if it preserves their number style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsLegal() const;

        /// <summary>
        /// Gets or sets a value indicating whether the level turns all inherited numbers to Arabic, false if it preserves their number style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsLegal(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the paragraph style that is linked to this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::Style > getLinkedStyle() const;

        /// <summary>
        /// Gets or sets the paragraph style that is linked to this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setLinkedStyle(std::shared_ptr< aspose::words::cloud::models::Style > value);


        /// <summary>
        /// Gets or sets the number format for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNumberFormat() const;

        /// <summary>
        /// Gets or sets the number format for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNumberFormat(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the position (in points) of the number or bullet for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getNumberPosition() const;

        /// <summary>
        /// Gets or sets the position (in points) of the number or bullet for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNumberPosition(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the number style for this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevel::NumberStyle > getNumberStyle() const;

        /// <summary>
        /// Gets or sets the number style for this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNumberStyle(std::shared_ptr< aspose::words::cloud::models::ListLevel::NumberStyle > value);


        /// <summary>
        /// Gets or sets the list level, that must appear before the specified list level restarts numbering.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getRestartAfterLevel() const;

        /// <summary>
        /// Gets or sets the list level, that must appear before the specified list level restarts numbering.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setRestartAfterLevel(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the starting number for this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getStartAt() const;

        /// <summary>
        /// Gets or sets the starting number for this list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setStartAt(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the tab position (in points) for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTabPosition() const;

        /// <summary>
        /// Gets or sets the tab position (in points) for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTabPosition(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the position (in points) for the second line of wrapping text for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getTextPosition() const;

        /// <summary>
        /// Gets or sets the position (in points) for the second line of wrapping text for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextPosition(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the character inserted after the number for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::ListLevel::TrailingCharacter > getTrailingCharacter() const;

        /// <summary>
        /// Gets or sets the character inserted after the number for the list level.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTrailingCharacter(std::shared_ptr< aspose::words::cloud::models::ListLevel::TrailingCharacter > value);


    protected:
        std::shared_ptr< aspose::words::cloud::models::ListLevel::Alignment > m_Alignment;
        std::shared_ptr< aspose::words::cloud::models::Font > m_Font;
        std::shared_ptr< bool > m_IsLegal;
        std::shared_ptr< aspose::words::cloud::models::Style > m_LinkedStyle;
        std::shared_ptr< std::wstring > m_NumberFormat;
        std::shared_ptr< double > m_NumberPosition;
        std::shared_ptr< aspose::words::cloud::models::ListLevel::NumberStyle > m_NumberStyle;
        std::shared_ptr< int32_t > m_RestartAfterLevel;
        std::shared_ptr< int32_t > m_StartAt;
        std::shared_ptr< double > m_TabPosition;
        std::shared_ptr< double > m_TextPosition;
        std::shared_ptr< aspose::words::cloud::models::ListLevel::TrailingCharacter > m_TrailingCharacter;
    };
}

