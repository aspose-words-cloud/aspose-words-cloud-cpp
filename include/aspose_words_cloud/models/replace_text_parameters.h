﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="replace_text_parameters.h">
*   Copyright (c) 2025 Aspose.Words for Cloud
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
    /// Class for document replace text request building.
    /// </summary>
    class ReplaceTextParameters : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ReplaceTextParameters() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;


        /// <summary>
        /// Gets or sets a value indicating whether apply superscript to font or not.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getApplySuperscript() const;

        /// <summary>
        /// Gets or sets a value indicating whether apply superscript to font or not.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setApplySuperscript(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether flag, true means the search is case-sensitive; false means the search is not case-sensitive.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsMatchCase() const;

        /// <summary>
        /// Gets or sets a value indicating whether flag, true means the search is case-sensitive; false means the search is not case-sensitive.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsMatchCase(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether flag, means that only whole word matched are replaced.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsMatchWholeWord() const;

        /// <summary>
        /// Gets or sets a value indicating whether flag, means that only whole word matched are replaced.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsMatchWholeWord(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether flag, means that OldValue contains regex expression.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsOldValueRegex() const;

        /// <summary>
        /// Gets or sets a value indicating whether flag, means that OldValue contains regex expression.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsOldValueRegex(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the new text value to replace by.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNewValue() const;

        /// <summary>
        /// Gets or sets the new text value to replace by.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNewValue(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the old text value (or regex pattern IsOldValueRegex) to replace.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getOldValue() const;

        /// <summary>
        /// Gets or sets the old text value (or regex pattern IsOldValueRegex) to replace.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setOldValue(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< bool > m_ApplySuperscript;
        std::shared_ptr< bool > m_IsMatchCase;
        std::shared_ptr< bool > m_IsMatchWholeWord;
        std::shared_ptr< bool > m_IsOldValueRegex;
        std::shared_ptr< std::wstring > m_NewValue;
        std::shared_ptr< std::wstring > m_OldValue;
    };
}

