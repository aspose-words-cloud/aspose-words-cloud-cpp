/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="OoxmlSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_OoxmlSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_OoxmlSaveOptionsData_H_

#include "SaveOptionsData.h"
#include "../ModelBase.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Container class for docx/docm/dotx/dotm/flatopc save options.
/// </summary>
class OoxmlSaveOptionsData
    : public SaveOptionsData
{
public:
    OoxmlSaveOptionsData();
    virtual ~OoxmlSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// OoxmlSaveOptionsData members

    /// <summary>
    /// Gets or sets the oOXML version for the output document.
    /// </summary>
    utility::string_t getCompliance() const;
    bool complianceIsSet() const;
    void unsetCompliance();
    void setCompliance(utility::string_t value);

    /// <summary>
    /// Gets or sets the compression level.
    /// </summary>
    utility::string_t getCompressionLevel() const;
    bool compressionLevelIsSet() const;
    void unsetCompressionLevel();
    void setCompressionLevel(utility::string_t value);

    /// <summary>
    /// Gets or sets the password to encrypt document using ECMA376 Standard encryption algorithm.
    /// </summary>
    utility::string_t getPassword() const;
    bool passwordIsSet() const;
    void unsetPassword();
    void setPassword(utility::string_t value);

    /// <summary>
    /// Gets or sets a value indicating whether to use pretty formats output.
    /// </summary>
    bool isPrettyFormat() const;
    bool prettyFormatIsSet() const;
    void unsetPrettyFormat();
    void setPrettyFormat(bool value);

protected:
    utility::string_t m_Compliance;
    bool m_ComplianceIsSet;

    utility::string_t m_CompressionLevel;
    bool m_CompressionLevelIsSet;

    utility::string_t m_Password;
    bool m_PasswordIsSet;

    bool m_PrettyFormat;
    bool m_PrettyFormatIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_OoxmlSaveOptionsData_H_ */
