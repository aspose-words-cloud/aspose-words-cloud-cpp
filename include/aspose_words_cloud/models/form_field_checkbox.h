﻿/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="form_field_checkbox.h">
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
#include "form_field.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// FormField checkbox element.
    /// </summary>
    class FormFieldCheckbox : public FormField
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FormFieldCheckbox() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void getFileReferences(std::vector< FileReference* >& result) override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void validate() override;

        void abstractFormField() override {}



        /// <summary>
        /// Gets or sets a value indicating whether the size of the textbox is automatic or specified explicitly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getIsCheckBoxExactSize() const;

        /// <summary>
        /// Gets or sets a value indicating whether the size of the textbox is automatic or specified explicitly.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setIsCheckBoxExactSize(std::shared_ptr< bool > value);


        /// <summary>
        /// Gets or sets the size of the checkbox in points. Has effect only when IsCheckBoxExactSize is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< double > getCheckBoxSize() const;

        /// <summary>
        /// Gets or sets the size of the checkbox in points. Has effect only when IsCheckBoxExactSize is true.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setCheckBoxSize(std::shared_ptr< double > value);


        /// <summary>
        /// Gets or sets the checked status of the check box form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< bool > getChecked() const;

        /// <summary>
        /// Gets or sets the checked status of the check box form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setChecked(std::shared_ptr< bool > value);


    protected:
        std::shared_ptr< bool > m_IsCheckBoxExactSize;
        std::shared_ptr< double > m_CheckBoxSize;
        std::shared_ptr< bool > m_Checked;
    };
}

