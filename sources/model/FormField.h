
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormField.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_FormField_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_FormField_H_


#include "NodeLink.h"
#include <cpprest/details/basic_types.h>
#include "WordsApiLink.h"

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// FromField
/// </summary>
class  FormField
    : public NodeLink
{
public:
    FormField();
    virtual ~FormField();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// FormField members

    /// <summary>
    /// True if references to the specified form field are automatically updated whenever the field is exited.
    /// </summary>
    bool isCalculateOnExit() const;
    bool calculateOnExitIsSet() const;
    void unsetCalculateOnExit();
    void setCalculateOnExit(bool value);
    /// <summary>
    /// True if a form field is enabled.
    /// </summary>
    bool isEnabled() const;
    bool enabledIsSet() const;
    void unsetEnabled();
    void setEnabled(bool value);
    /// <summary>
    /// Returns or sets an entry macro name for the form field.
    /// </summary>
    utility::string_t getEntryMacro() const;
    bool entryMacroIsSet() const;
    void unsetEntryMacro();
    void setEntryMacro(utility::string_t value);
    /// <summary>
    /// Returns or sets an exit macro name for the form field.
    /// </summary>
    utility::string_t getExitMacro() const;
    bool exitMacroIsSet() const;
    void unsetExitMacro();
    void setExitMacro(utility::string_t value);
    /// <summary>
    /// Returns or sets the text that&#39;s displayed in a message box when the form field has the focus and the user presses F1.
    /// </summary>
    utility::string_t getHelpText() const;
    bool helpTextIsSet() const;
    void unsetHelpText();
    void setHelpText(utility::string_t value);
    /// <summary>
    /// Gets or sets the form field name.
    /// </summary>
    utility::string_t getName() const;
    bool nameIsSet() const;
    void unsetName();
    void setName(utility::string_t value);
    /// <summary>
    /// Specifies the source of the text that&#39;s displayed in a message box when a form field has the focus and the user presses F1.
    /// </summary>
    bool isOwnHelp() const;
    bool ownHelpIsSet() const;
    void unsetOwnHelp();
    void setOwnHelp(bool value);
    /// <summary>
    /// Specifies the source of the text that&#39;s displayed in the status bar when a form field has the focus.
    /// </summary>
    bool isOwnStatus() const;
    bool ownStatusIsSet() const;
    void unsetOwnStatus();
    void setOwnStatus(bool value);
    /// <summary>
    /// Returns or sets the text that&#39;s displayed in the status bar when a form field has the focus.
    /// </summary>
    utility::string_t getStatusText() const;
    bool statusTextIsSet() const;
    void unsetStatusText();
    void setStatusText(utility::string_t value);

protected:
    bool m_CalculateOnExit;
    bool m_CalculateOnExitIsSet;
    bool m_Enabled;
    bool m_EnabledIsSet;
    utility::string_t m_EntryMacro;
    bool m_EntryMacroIsSet;
    utility::string_t m_ExitMacro;
    bool m_ExitMacroIsSet;
    utility::string_t m_HelpText;
    bool m_HelpTextIsSet;
    utility::string_t m_Name;
    bool m_NameIsSet;
    bool m_OwnHelp;
    bool m_OwnHelpIsSet;
    bool m_OwnStatus;
    bool m_OwnStatusIsSet;
    utility::string_t m_StatusText;
    bool m_StatusTextIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_FormField_H_ */
