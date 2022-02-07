/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="style_update.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Represents a single document style properties to update.
    /// </summary>
    class StyleUpdate : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~StyleUpdate() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the name of the style this style is based on.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getBaseStyleName() const;

        /// <summary>
        /// Gets or sets the name of the style this style is based on.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setBaseStyleName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether this style is shown in the Quick Style gallery inside MS Word UI.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsQuickStyle() const;

        /// <summary>
        /// Gets or sets a value indicating whether this style is shown in the Quick Style gallery inside MS Word UI.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsQuickStyle(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the name of the style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getName() const;

        /// <summary>
        /// Gets or sets the name of the style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setName(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the name of the style to be applied automatically to a new paragraph inserted after a paragraph formatted with the specified style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNextParagraphStyleName() const;

        /// <summary>
        /// Gets or sets the name of the style to be applied automatically to a new paragraph inserted after a paragraph formatted with the specified style.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNextParagraphStyleName(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_BaseStyleName;
        std::shared_ptr< bool > m_IsQuickStyle;
        std::shared_ptr< std::wstring > m_Name;
        std::shared_ptr< std::wstring > m_NextParagraphStyleName;
    };
}

