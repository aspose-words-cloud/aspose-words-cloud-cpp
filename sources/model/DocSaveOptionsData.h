/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="DocSaveOptionsData.h">
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

#ifndef ASPOSE_WORDS_CLOUD_API_MODELS_DocSaveOptionsData_H_
#define ASPOSE_WORDS_CLOUD_API_MODELS_DocSaveOptionsData_H_


#include "SaveOptionsData.h"
#include <cpprest/details/basic_types.h>

namespace aspose {
namespace words {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// container class for doc/dot save options.
/// </summary>
class  DocSaveOptionsData
    : public SaveOptionsData
{
public:
    DocSaveOptionsData();
    virtual ~DocSaveOptionsData();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// DocSaveOptionsData members

    /// <summary>
    /// Gets or sets When false, small metafiles are not compressed for performance reason. Default value is true, all metafiles are compressed regardless of its size.
    /// </summary>
    bool isAlwaysCompressMetafiles() const;
    bool alwaysCompressMetafilesIsSet() const;
    void unsetAlwaysCompressMetafiles();
    void setAlwaysCompressMetafiles(bool value);
    /// <summary>
    /// Gets or sets password.
    /// </summary>
    utility::string_t getPassword() const;
    bool passwordIsSet() const;
    void unsetPassword();
    void setPassword(utility::string_t value);
    /// <summary>
    /// Gets or sets When false, PictureBullet data is not saved to output document. Default value is true.
    /// </summary>
    bool isSavePictureBullet() const;
    bool savePictureBulletIsSet() const;
    void unsetSavePictureBullet();
    void setSavePictureBullet(bool value);
    /// <summary>
    /// Gets or sets determine whether or not save RoutingSlip data saved to output document.
    /// </summary>
    bool isSaveRoutingSlip() const;
    bool saveRoutingSlipIsSet() const;
    void unsetSaveRoutingSlip();
    void setSaveRoutingSlip(bool value);

protected:
    bool m_AlwaysCompressMetafiles;
    bool m_AlwaysCompressMetafilesIsSet;
    utility::string_t m_Password;
    bool m_PasswordIsSet;
    bool m_SavePictureBullet;
    bool m_SavePictureBulletIsSet;
    bool m_SaveRoutingSlip;
    bool m_SaveRoutingSlipIsSet;
};

}
}
}
}
}

#endif /* ASPOSE_WORDS_CLOUD_API_MODELS_DocSaveOptionsData_H_ */
