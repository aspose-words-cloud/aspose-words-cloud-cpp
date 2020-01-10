
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldCheckbox.h">
*   Copyright (c) 2019 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldCheckbox_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldCheckbox_H_


#include "FormField.h"
#include <cpprest/details/basic_types.h>
#include "WordsApiLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// FormField checkbox element.
/// </summary>
class  FormFieldCheckbox
    : public FormField
{
public:
    FormFieldCheckbox();
    virtual ~FormFieldCheckbox();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FormFieldCheckbox members

    /// <summary>
    /// Gets or sets the size of the checkbox in points. Has effect only when IsCheckBoxExactSize is true.
    /// </summary>
    double getCheckBoxSize() const;
    bool checkBoxSizeIsSet() const;
    void unsetCheckBoxSize();
    void setCheckBoxSize(double value);
    /// <summary>
    /// Gets or sets the checked status of the check box form field.
    /// </summary>
    bool isChecked() const;
    bool checkedIsSet() const;
    void unsetChecked();
    void setChecked(bool value);
    /// <summary>
    /// Gets or sets the boolean value that indicates whether the size of the textbox is automatic or specified explicitly.
    /// </summary>
    bool isIsCheckBoxExactSize() const;
    bool isCheckBoxExactSizeIsSet() const;
    void unsetIsCheckBoxExactSize();
    void setIsCheckBoxExactSize(bool value);

protected:
    double m_CheckBoxSize;
    bool m_CheckBoxSizeIsSet;
    bool m_Checked;
    bool m_CheckedIsSet;
    bool m_IsCheckBoxExactSize;
    bool m_IsCheckBoxExactSizeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldCheckbox_H_ */
