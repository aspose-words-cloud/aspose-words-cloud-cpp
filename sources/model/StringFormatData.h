
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="StringFormatData.h">
*   Copyright (c) 2018 Aspose.Words for Cloud
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

#ifndef IO_SWAGGER_CLIENT_MODEL_StringFormatData_H_
#define IO_SWAGGER_CLIENT_MODEL_StringFormatData_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace io {
namespace swagger {
namespace client {
namespace model {

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

    void toMultipart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(std::shared_ptr<MultipartFormData> multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// StringFormatData members

    /// <summary>
    /// Gets or sets horizontal alignment of the string.
    /// </summary>
    utility::string_t getAlignment() const;
    bool alignmentIsSet() const;
    void unsetAlignment();
    void setAlignment(utility::string_t value);
    /// <summary>
    /// Gets or sets a System.Drawing.StringFormatFlags enumeration that contains formatting information.
    /// </summary>
    utility::string_t getFormatFlags() const;
    bool formatFlagsIsSet() const;
    void unsetFormatFlags();
    void setFormatFlags(utility::string_t value);
    /// <summary>
    /// Gets or sets the System.Drawing.Text.HotkeyPrefix object for this System.Drawing.StringFormat object.
    /// </summary>
    utility::string_t getHotkeyPrefix() const;
    bool hotkeyPrefixIsSet() const;
    void unsetHotkeyPrefix();
    void setHotkeyPrefix(utility::string_t value);
    /// <summary>
    /// Gets or sets the vertical alignment of the string.
    /// </summary>
    utility::string_t getLineAlignment() const;
    bool lineAlignmentIsSet() const;
    void unsetLineAlignment();
    void setLineAlignment(utility::string_t value);
    /// <summary>
    /// Gets or sets the System.Drawing.StringTrimming enumeration for this System.Drawing.StringFormat object.
    /// </summary>
    utility::string_t getTrimming() const;
    bool trimmingIsSet() const;
    void unsetTrimming();
    void setTrimming(utility::string_t value);

protected:
    utility::string_t m_Alignment;
    bool m_AlignmentIsSet;
    utility::string_t m_FormatFlags;
    bool m_FormatFlagsIsSet;
    utility::string_t m_HotkeyPrefix;
    bool m_HotkeyPrefixIsSet;
    utility::string_t m_LineAlignment;
    bool m_LineAlignmentIsSet;
    utility::string_t m_Trimming;
    bool m_TrimmingIsSet;
};

}
}
}
}

#endif /* IO_SWAGGER_CLIENT_MODEL_StringFormatData_H_ */
