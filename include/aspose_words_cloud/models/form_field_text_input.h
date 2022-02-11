/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="form_field_text_input.h">
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
#include "form_field.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// FormField text input element.
    /// </summary>
    class FormFieldTextInput : public FormField
    {
    public:
        /// <summary>
        /// Gets or sets the type of the text form field.
        /// </summary>
        enum class TextInputType
        { 
            REGULAR,
            NUMBER,
            DATE,
            CURRENT_DATE,
            CURRENT_TIME,
            CALCULATED
        };


        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FormFieldTextInput() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the maximum length for the text field. Zero when the length is not limited.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getMaxLength() const;

        /// <summary>
        /// Gets or sets the maximum length for the text field. Zero when the length is not limited.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMaxLength(std::shared_ptr< int32_t > value);


        /// <summary>
        /// Gets or sets the default string or a calculation expression of the text form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTextInputDefault() const;

        /// <summary>
        /// Gets or sets the default string or a calculation expression of the text form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextInputDefault(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets text formatting for the text form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTextInputFormat() const;

        /// <summary>
        /// Gets or sets text formatting for the text form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextInputFormat(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the type of the text form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< aspose::words::cloud::models::FormFieldTextInput::TextInputType > getTextInputType() const;

        /// <summary>
        /// Gets or sets the type of the text form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextInputType(std::shared_ptr< aspose::words::cloud::models::FormFieldTextInput::TextInputType > value);


    protected:
        std::shared_ptr< int32_t > m_MaxLength;
        std::shared_ptr< std::wstring > m_TextInputDefault;
        std::shared_ptr< std::wstring > m_TextInputFormat;
        std::shared_ptr< aspose::words::cloud::models::FormFieldTextInput::TextInputType > m_TextInputType;
    };
}

