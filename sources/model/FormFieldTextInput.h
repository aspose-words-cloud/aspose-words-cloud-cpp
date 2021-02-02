/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldTextInput.h">
*   Copyright (c) 2020 Aspose.Words for Cloud
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldTextInput_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldTextInput_H_

#include "FormField.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// FormField text input element.
/// </summary>
class FormFieldTextInput
    : public FormField
{
public:
    FormFieldTextInput();
    virtual ~FormFieldTextInput();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FormFieldTextInput members

    /// <summary>
    /// Gets or sets the maximum length for the text field. Zero when the length is not limited.
    /// </summary>
    int32_t getMaxLength() const;
    bool maxLengthIsSet() const;
    void unsetMaxLength();
    void setMaxLength(int32_t value);

    /// <summary>
    /// Gets or sets the default string or a calculation expression of the text form field.
    /// </summary>
    utility::string_t getTextInputDefault() const;
    bool textInputDefaultIsSet() const;
    void unsetTextInputDefault();
    void setTextInputDefault(utility::string_t value);

    /// <summary>
    /// Gets or sets text formatting for the text form field.
    /// </summary>
    utility::string_t getTextInputFormat() const;
    bool textInputFormatIsSet() const;
    void unsetTextInputFormat();
    void setTextInputFormat(utility::string_t value);

    /// <summary>
    /// Gets or sets the type of the text form field.
    /// </summary>
    utility::string_t getTextInputType() const;
    bool textInputTypeIsSet() const;
    void unsetTextInputType();
    void setTextInputType(utility::string_t value);

protected:
    int32_t m_MaxLength;
    bool m_MaxLengthIsSet;

    utility::string_t m_TextInputDefault;
    bool m_TextInputDefaultIsSet;

    utility::string_t m_TextInputFormat;
    bool m_TextInputFormatIsSet;

    utility::string_t m_TextInputType;
    bool m_TextInputTypeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldTextInput_H_ */
