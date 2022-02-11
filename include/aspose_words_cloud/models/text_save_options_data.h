/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="text_save_options_data.h">
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
#include "txt_save_options_base_data.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// Container class for text save options.
    /// </summary>
    class TextSaveOptionsData : public TxtSaveOptionsBaseData
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~TextSaveOptionsData() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        void abstractTxtSaveOptionsBaseData() override {}
        void abstractSaveOptionsData() override {}

        /// <summary>
        /// Gets or sets a value indicating whether to add bi-directional marks before each BiDi run when exporting in plain text format.
        /// The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getAddBidiMarks() const;

        /// <summary>
        /// Gets or sets a value indicating whether to add bi-directional marks before each BiDi run when exporting in plain text format.
        /// The default value is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setAddBidiMarks(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets an integer value that specifies the maximum number of characters per one line.
        /// The default value is 0, that means no limit.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getMaxCharactersPerLine() const;

        /// <summary>
        /// Gets or sets an integer value that specifies the maximum number of characters per one line.
        /// The default value is 0, that means no limit.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMaxCharactersPerLine(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets a value indicating whether the program should attempt to preserve layout of tables when saving in the plain text format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getPreserveTableLayout() const;

        /// <summary>
        /// Gets or sets a value indicating whether the program should attempt to preserve layout of tables when saving in the plain text format.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPreserveTableLayout(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets the format of save.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getSaveFormat() const override;



        /// <summary>
        /// Gets or sets a value indicating whether the program should simplify list labels in case of complex label formatting not being adequately represented by plain text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getSimplifyListLabels() const;

        /// <summary>
        /// Gets or sets a value indicating whether the program should simplify list labels in case of complex label formatting not being adequately represented by plain text.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setSimplifyListLabels(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< bool > m_AddBidiMarks;
        std::shared_ptr< int32_t > m_MaxCharactersPerLine;
        std::shared_ptr< bool > m_PreserveTableLayout;
        std::shared_ptr< std::wstring > m_SaveFormat = std::make_shared<std::wstring>(L"txt");
        std::shared_ptr< bool > m_SimplifyListLabels;
    };
}

