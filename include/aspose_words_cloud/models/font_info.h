﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="font_info.h">
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
    /// DTO container with font info.
    /// </summary>
    class FontInfo : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FontInfo() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets the path to the font file if any.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getFilePath() const;

        /// <summary>
        /// Gets or sets the path to the font file if any.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setFilePath(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the family name of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getFontFamilyName() const;

        /// <summary>
        /// Gets or sets the family name of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setFontFamilyName(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the full name of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getFullFontName() const;

        /// <summary>
        /// Gets or sets the full name of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setFullFontName(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the version string of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getVersion() const;

        /// <summary>
        /// Gets or sets the version string of the font.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setVersion(std::shared_ptr< std::wstring > value);

    protected:
        std::shared_ptr< std::wstring > m_FilePath;
        std::shared_ptr< std::wstring > m_FontFamilyName;
        std::shared_ptr< std::wstring > m_FullFontName;
        std::shared_ptr< std::wstring > m_Version;
    };
}
