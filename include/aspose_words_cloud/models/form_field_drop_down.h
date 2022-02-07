/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="form_field_drop_down.h">
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
    /// FormField dropdownlist element.
    /// </summary>
    class FormFieldDropDown : public FormField
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FormFieldDropDown() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the items array of a dropdown form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > getDropDownItems() const;

        /// <summary>
        /// Gets or sets the items array of a dropdown form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDropDownItems(std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > value);


        /// <summary>
        /// Gets or sets the index specifying the currently selected item in a dropdown form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< int32_t > getDropDownSelectedIndex() const;

        /// <summary>
        /// Gets or sets the index specifying the currently selected item in a dropdown form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setDropDownSelectedIndex(std::shared_ptr< int32_t > value);


    protected:
        std::shared_ptr< std::vector<std::shared_ptr<std::wstring>> > m_DropDownItems;
        std::shared_ptr< int32_t > m_DropDownSelectedIndex;
    };
}

