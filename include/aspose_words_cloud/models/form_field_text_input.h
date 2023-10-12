/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="form_field_text_input.h">
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
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;

        void abstractFormField() override {}



        /// <summary>
        /// Gets or sets text formatting for the text form field.
        /// If the text form field contains regular text, then valid format strings are "", "UPPERCASE", "LOWERCASE", "FIRST CAPITAL" and "TITLE CASE". The strings are case-insensitive.If the text form field contains a number or a date/time value, then valid format strings are number or date and time format strings.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTextInputFormat() const;

        /// <summary>
        /// Gets or sets text formatting for the text form field.
        /// If the text form field contains regular text, then valid format strings are "", "UPPERCASE", "LOWERCASE", "FIRST CAPITAL" and "TITLE CASE". The strings are case-insensitive.If the text form field contains a number or a date/time value, then valid format strings are number or date and time format strings.
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


        /// <summary>
        /// Gets or sets the default string or a calculation expression of the text form field.
        /// The meaning of this property depends on the value of the TextInputType property.When TextInputType is Regular or Number, this string specifies the default string for the text form field. This string is the content that Microsoft Word will display in the document when the form field is empty.When TextInputType is Calculated, then this string holds the expression to be calculated. The expression needs to be a formula valid according to Microsoft Word formula field requirements. When you set a new expression using this property, Aspose.Words calculates the formula result automatically and inserts it into the form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getTextInputDefault() const;

        /// <summary>
        /// Gets or sets the default string or a calculation expression of the text form field.
        /// The meaning of this property depends on the value of the TextInputType property.When TextInputType is Regular or Number, this string specifies the default string for the text form field. This string is the content that Microsoft Word will display in the document when the form field is empty.When TextInputType is Calculated, then this string holds the expression to be calculated. The expression needs to be a formula valid according to Microsoft Word formula field requirements. When you set a new expression using this property, Aspose.Words calculates the formula result automatically and inserts it into the form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setTextInputDefault(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the maximum length for the text field. Zero when the length is not limited.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getMaxLength() const;

        /// <summary>
        /// Gets or sets the maximum length for the text field. Zero when the length is not limited.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setMaxLength(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< std::wstring > m_TextInputFormat;
        std::shared_ptr< aspose::words::cloud::models::FormFieldTextInput::TextInputType > m_TextInputType;
        std::shared_ptr< std::wstring > m_TextInputDefault;
        std::shared_ptr< int32_t > m_MaxLength;
    };
}

