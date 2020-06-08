/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StringFormatData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_StringFormatData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_StringFormatData_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Allows to specify System.Drawing.StringFormat options.
/// </summary>
class  StringFormatData
    : public ModelBase
{
public:
    StringFormatData();
    virtual ~StringFormatData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StringFormatData members

    /// <summary>
    /// Gets or sets horizontal alignment of the string.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets a System.Drawing.StringFormatFlags enumeration that contains formatting information.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getFormatFlags() const;
    bool formatFlagsIsSet() const;
    void unsetFormatFlags();
    void setFormatFlags(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the System.Drawing.Text.HotkeyPrefix object for this System.Drawing.StringFormat object.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getHotkeyPrefix() const;
    bool hotkeyPrefixIsSet() const;
    void unsetHotkeyPrefix();
    void setHotkeyPrefix(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the vertical alignment of the string.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getLineAlignment() const;
    bool lineAlignmentIsSet() const;
    void unsetLineAlignment();
    void setLineAlignment(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets the System.Drawing.StringTrimming enumeration for this System.Drawing.StringFormat object.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getTrimming() const;
    bool trimmingIsSet() const;
    void unsetTrimming();
    void setTrimming(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Alignment;
    bool m_AlignmentIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_FormatFlags;
    bool m_FormatFlagsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_HotkeyPrefix;
    bool m_HotkeyPrefixIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_LineAlignment;
    bool m_LineAlignmentIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Trimming;
    bool m_TrimmingIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_StringFormatData_H_ */
