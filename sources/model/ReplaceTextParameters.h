
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ReplaceTextParameters.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceTextParameters_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceTextParameters_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Class for document replace text request building.
/// </summary>
class  ReplaceTextParameters
    : public ModelBase
{
public:
    ReplaceTextParameters();
    virtual ~ReplaceTextParameters();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// ReplaceTextParameters members

    /// <summary>
    /// Gets or sets old text value (or regex pattern ) to replace.
    /// </summary>
    utility::string_t getOldValue() const;
    bool oldValueIsSet() const;
    void unsetOldValue();
    void setOldValue(utility::string_t value);
    /// <summary>
    /// Gets or sets new text value to replace by.
    /// </summary>
    utility::string_t getNewValue() const;
    bool newValueIsSet() const;
    void unsetNewValue();
    void setNewValue(utility::string_t value);
    /// <summary>
    /// Gets or sets a value indicating whether flag, true means the search is case-sensitive; false means the search is not case-sensitive.
    /// </summary>
    bool isIsMatchCase() const;
        void setIsMatchCase(bool value);
    /// <summary>
    /// Gets or sets a value indicating whether flag, means that only whole word matched are replaced.
    /// </summary>
    bool isIsMatchWholeWord() const;
        void setIsMatchWholeWord(bool value);
    /// <summary>
    /// Gets or sets a value indicating whether flag, means that  contains regex expression.
    /// </summary>
    bool isIsOldValueRegex() const;
        void setIsOldValueRegex(bool value);

protected:
    utility::string_t m_OldValue;
    bool m_OldValueIsSet;
    utility::string_t m_NewValue;
    bool m_NewValueIsSet;
    bool m_IsMatchCase;
        bool m_IsMatchWholeWord;
        bool m_IsOldValueRegex;
    };

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_ReplaceTextParameters_H_ */
