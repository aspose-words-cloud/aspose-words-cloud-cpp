/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="string_format_data.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Allows to specify System.Drawing.StringFormat options.
    /// </summary>
    class StringFormatData : public ModelBase
    {
    public:
        /// <summary>
        /// Gets or sets horizontal alignment of the string.
        /// </summary>
        enum class Alignment
        { 
            _NEAR,
            CENTER,
            _FAR
        };

        /// <summary>
        /// Gets or sets the System.Drawing.StringFormatFlags enumeration, that contains formatting information.
        /// </summary>
        enum class FormatFlags
        { 
            DIRECTION_RIGHT_TO_LEFT,
            DIRECTION_VERTICAL,
            FIT_BLACK_BOX,
            DISPLAY_FORMAT_CONTROL,
            NO_FONT_FALLBACK,
            MEASURE_TRAILING_SPACES,
            NO_WRAP,
            LINE_LIMIT,
            NO_CLIP
        };

        /// <summary>
        /// Gets or sets the System.Drawing.Text.HotkeyPrefix object for this System.Drawing.StringFormat object.
        /// </summary>
        enum class HotkeyPrefix
        { 
            NONE,
            SHOW,
            HIDE
        };

        /// <summary>
        /// Gets or sets the vertical alignment of the string.
        /// </summary>
        enum class LineAlignment
        { 
            _NEAR,
            CENTER,
            _FAR
        };

        /// <summary>
        /// Gets or sets the System.Drawing.StringTrimming enumeration for this System.Drawing.StringFormat object.
        /// </summary>
        enum class Trimming
        { 
            NONE,
            CHARACTER,
            WORD,
            ELLIPSIS_CHARACTER,
            ELLIPSIS_WORD,
            ELLIPSIS_PATH
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StringFormatData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets horizontal alignment of the string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::StringFormatData::Alignment > getAlignment();

        /// <summary>
        /// Gets or sets horizontal alignment of the string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setAlignment(std::shared_ptr< aspose::words::cloud::models::StringFormatData::Alignment > value);

        /// <summary>
        /// Gets or sets the System.Drawing.StringFormatFlags enumeration, that contains formatting information.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::StringFormatData::FormatFlags > getFormatFlags();

        /// <summary>
        /// Gets or sets the System.Drawing.StringFormatFlags enumeration, that contains formatting information.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setFormatFlags(std::shared_ptr< aspose::words::cloud::models::StringFormatData::FormatFlags > value);

        /// <summary>
        /// Gets or sets the System.Drawing.Text.HotkeyPrefix object for this System.Drawing.StringFormat object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::StringFormatData::HotkeyPrefix > getHotkeyPrefix();

        /// <summary>
        /// Gets or sets the System.Drawing.Text.HotkeyPrefix object for this System.Drawing.StringFormat object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setHotkeyPrefix(std::shared_ptr< aspose::words::cloud::models::StringFormatData::HotkeyPrefix > value);

        /// <summary>
        /// Gets or sets the vertical alignment of the string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::StringFormatData::LineAlignment > getLineAlignment();

        /// <summary>
        /// Gets or sets the vertical alignment of the string.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setLineAlignment(std::shared_ptr< aspose::words::cloud::models::StringFormatData::LineAlignment > value);

        /// <summary>
        /// Gets or sets the System.Drawing.StringTrimming enumeration for this System.Drawing.StringFormat object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< aspose::words::cloud::models::StringFormatData::Trimming > getTrimming();

        /// <summary>
        /// Gets or sets the System.Drawing.StringTrimming enumeration for this System.Drawing.StringFormat object.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setTrimming(std::shared_ptr< aspose::words::cloud::models::StringFormatData::Trimming > value);

    protected:
        std::shared_ptr< aspose::words::cloud::models::StringFormatData::Alignment > m_Alignment;
        std::shared_ptr< aspose::words::cloud::models::StringFormatData::FormatFlags > m_FormatFlags;
        std::shared_ptr< aspose::words::cloud::models::StringFormatData::HotkeyPrefix > m_HotkeyPrefix;
        std::shared_ptr< aspose::words::cloud::models::StringFormatData::LineAlignment > m_LineAlignment;
        std::shared_ptr< aspose::words::cloud::models::StringFormatData::Trimming > m_Trimming;
    };
}

