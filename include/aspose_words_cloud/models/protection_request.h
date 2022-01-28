/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="protection_request.h">
*   Copyright (c) 2022 Aspose.Words for Cloud
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Request on changing of protection.
    /// </summary>
    class ProtectionRequest : public ModelBase
    {
    public:

        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ProtectionRequest() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void toJson(void* jsonIfc) const override;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void fromJson(const void* jsonIfc) override;


        /// <summary>
        /// Gets or sets the new password.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getNewPassword() const;

        /// <summary>
        /// Gets or sets the new password.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setNewPassword(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the current password.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getPassword() const;

        /// <summary>
        /// Gets or sets the current password.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setPassword(std::shared_ptr< std::wstring > value);


        /// <summary>
        /// Gets or sets the new type of protection.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual std::shared_ptr< std::wstring > getProtectionType() const;

        /// <summary>
        /// Gets or sets the new type of protection.
        /// </summary>
        ASPOSE_WORDS_CLOUD_EXPORT virtual void setProtectionType(std::shared_ptr< std::wstring > value);


    protected:
        std::shared_ptr< std::wstring > m_NewPassword;
        std::shared_ptr< std::wstring > m_Password;
        std::shared_ptr< std::wstring > m_ProtectionType;
    };
}

