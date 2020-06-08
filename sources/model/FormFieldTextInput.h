/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormFieldTextInput.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldTextInput_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldTextInput_H_


#include "FormField.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// FormField text input element.
/// </summary>
class  FormFieldTextInput
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
    /// Gets or sets maximum length for the text field. Zero when the length is not limited.
    /// </summary>
    <DATA_TYPE_START>int?<DATA_TYPE_END> getMaxLength() const;
    bool maxLengthIsSet() const;
    void unsetMaxLength();
    void setMaxLength(<DATA_TYPE_START>int?<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the default string or a calculation expression of a text form field.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTextInputDefault() const;
    bool textInputDefaultIsSet() const;
    void unsetTextInputDefault();
    void setTextInputDefault(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets returns or sets the text formatting for a text form field.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTextInputFormat() const;
    bool textInputFormatIsSet() const;
    void unsetTextInputFormat();
    void setTextInputFormat(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the type of a text form field.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTextInputType() const;
    bool textInputTypeIsSet() const;
    void unsetTextInputType();
    void setTextInputType(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>int?<DATA_TYPE_END> m_MaxLength;
    bool m_MaxLengthIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_TextInputDefault;
    bool m_TextInputDefaultIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_TextInputFormat;
    bool m_TextInputFormatIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_TextInputType;
    bool m_TextInputTypeIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FormFieldTextInput_H_ */
