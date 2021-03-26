/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="form_field.h">
*   Copyright (c) 2021 Aspose.Words for Cloud
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
#include "node_link.h"

namespace aspose::words::cloud::models {
    /// <summary>
    /// FromField.
    /// </summary>
    class FormField : public NodeLink
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~FormField() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets a value indicating whether references to the specified form field are automatically updated whenever the field is exited.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getCalculateOnExit();

        /// <summary>
        /// Gets or sets a value indicating whether references to the specified form field are automatically updated whenever the field is exited.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setCalculateOnExit(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether a form field is enabled.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getEnabled();

        /// <summary>
        /// Gets or sets a value indicating whether a form field is enabled.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setEnabled(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets the entry macro name for the form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getEntryMacro();

        /// <summary>
        /// Gets or sets the entry macro name for the form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setEntryMacro(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the exit macro name for the form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getExitMacro();

        /// <summary>
        /// Gets or sets the exit macro name for the form field.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setExitMacro(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets text, displayed in a message box when the form field has the focus and the user presses F1.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getHelpText();

        /// <summary>
        /// Gets or sets text, displayed in a message box when the form field has the focus and the user presses F1.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setHelpText(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets the form field name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getName();

        /// <summary>
        /// Gets or sets the form field name.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setName(std::shared_ptr< std::wstring > value);

        /// <summary>
        /// Gets or sets a value indicating whether the source of the text that's displayed in a message box when a form field has the focus and the user presses F1.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getOwnHelp();

        /// <summary>
        /// Gets or sets a value indicating whether the source of the text that's displayed in a message box when a form field has the focus and the user presses F1.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setOwnHelp(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets a value indicating whether the source of the text that's displayed in the status bar when a form field has the focus.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< bool > getOwnStatus();

        /// <summary>
        /// Gets or sets a value indicating whether the source of the text that's displayed in the status bar when a form field has the focus.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setOwnStatus(std::shared_ptr< bool > value);

        /// <summary>
        /// Gets or sets text, displayed in the status bar when a form field has the focus.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT std::shared_ptr< std::wstring > getStatusText();

        /// <summary>
        /// Gets or sets text, displayed in the status bar when a form field has the focus.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT void setStatusText(std::shared_ptr< std::wstring > value);

    protected:
        std::shared_ptr< bool > m_CalculateOnExit;
        std::shared_ptr< bool > m_Enabled;
        std::shared_ptr< std::wstring > m_EntryMacro;
        std::shared_ptr< std::wstring > m_ExitMacro;
        std::shared_ptr< std::wstring > m_HelpText;
        std::shared_ptr< std::wstring > m_Name;
        std::shared_ptr< bool > m_OwnHelp;
        std::shared_ptr< bool > m_OwnStatus;
        std::shared_ptr< std::wstring > m_StatusText;
    };
}

