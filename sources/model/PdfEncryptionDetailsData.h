/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="PdfEncryptionDetailsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_PdfEncryptionDetailsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_PdfEncryptionDetailsData_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for details of encryption.
/// </summary>
class  PdfEncryptionDetailsData
    : public ModelBase
{
public:
    PdfEncryptionDetailsData();
    virtual ~PdfEncryptionDetailsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// PdfEncryptionDetailsData members

    /// <summary>
    /// Gets or sets specifies the encryption algorithm to use.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getEncryptionAlgorithm() const;
    bool encryptionAlgorithmIsSet() const;
    void unsetEncryptionAlgorithm();
    void setEncryptionAlgorithm(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the owner password for the encrypted PDF document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getOwnerPassword() const;
    bool ownerPasswordIsSet() const;
    void unsetOwnerPassword();
    void setOwnerPassword(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the operations that are allowed to a user on an encrypted PDF document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getPermissions() const;
    bool permissionsIsSet() const;
    void unsetPermissions();
    void setPermissions(<DATA_TYPE_START>string<DATA_TYPE_END> value);
    /// <summary>
    /// Gets or sets specifies the user password required for opening the encrypted PDF document.
    /// </summary>
    <DATA_TYPE_START>string<DATA_TYPE_END> getUserPassword() const;
    bool userPasswordIsSet() const;
    void unsetUserPassword();
    void setUserPassword(<DATA_TYPE_START>string<DATA_TYPE_END> value);

protected:
    <DATA_TYPE_START>string<DATA_TYPE_END> m_EncryptionAlgorithm;
    bool m_EncryptionAlgorithmIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_OwnerPassword;
    bool m_OwnerPasswordIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_Permissions;
    bool m_PermissionsIsSet;
    <DATA_TYPE_START>string<DATA_TYPE_END> m_UserPassword;
    bool m_UserPasswordIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_PdfEncryptionDetailsData_H_ */
