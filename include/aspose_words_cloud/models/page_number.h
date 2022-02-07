/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="page_number.h">
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
    /// Class is used for insert page number request building.
    /// </summary>
    class PageNumber : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~PageNumber() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets text alignment, possible values are left, right, center or justify.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getAlignment() const;

        /// <summary>
        /// Gets or sets text alignment, possible values are left, right, center or justify.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAlignment(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the page number format, e.g. "{PAGE} of {NUMPAGES}".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getFormat() const;

        /// <summary>
        /// Gets or sets the page number format, e.g. "{PAGE} of {NUMPAGES}".
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setFormat(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets a value indicating whether if true the page number is added at the top of the page, else at the bottom.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsTop() const;

        /// <summary>
        /// Gets or sets a value indicating whether if true the page number is added at the top of the page, else at the bottom.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsTop(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets a value indicating whether if true the page number is added on first page too.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSetPageNumberOnFirstPage() const;

        /// <summary>
        /// Gets or sets a value indicating whether if true the page number is added on first page too.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSetPageNumberOnFirstPage(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< std::wstring > m_Alignment;
        std::shared_ptr< std::wstring > m_Format;
        std::shared_ptr< bool > m_IsTop;
        std::shared_ptr< bool > m_SetPageNumberOnFirstPage;
    };
}

