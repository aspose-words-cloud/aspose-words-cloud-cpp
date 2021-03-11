/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="ApiError.h">
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

#include "../ModelBase.h"

namespace aspose::words::cloud::api::models {
    /// <summary>
    /// Api error.
    /// </summary>
    class ApiError
        : public ModelBase
    {
    public:
        ApiError();
        virtual ~ApiError();

        /////////////////////////////////////////////
        /// ModelBase overrides

        void validate() override;

        web::json::value toJson() const override;
        void fromJson(web::json::value& json) override;

        void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const std::wstring& namePrefix) const override;
        void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const std::wstring& namePrefix) override;

        /////////////////////////////////////////////
        /// ApiError members

        /// <summary>
        /// Gets or sets the API error code.
        /// </summary>
        std::wstring getCode() const;
        bool codeIsSet() const;
        void unsetCode();
        void setCode(std::wstring value);

        /// <summary>
        /// Gets or sets the server DateTime.
        /// </summary>
        utility::datetime getDateTime() const;
        bool dateTimeIsSet() const;
        void unsetDateTime();
        void setDateTime(utility::datetime value);

        /// <summary>
        /// Gets or sets the error description.
        /// </summary>
        std::wstring getDescription() const;
        bool descriptionIsSet() const;
        void unsetDescription();
        void setDescription(std::wstring value);

        /// <summary>
        /// Gets or sets the inner error.
        /// </summary>
        std::shared_ptr<ApiError> getInnerError() const;
        bool innerErrorIsSet() const;
        void unsetInnerError();
        void setInnerError(std::shared_ptr<ApiError> value);

        /// <summary>
        /// Gets or sets the error message.
        /// </summary>
        std::wstring getMessage() const;
        bool messageIsSet() const;
        void unsetMessage();
        void setMessage(std::wstring value);

    protected:
        std::wstring m_Code;
        bool m_CodeIsSet;

        utility::datetime m_DateTime;
        bool m_DateTimeIsSet;

        std::wstring m_Description;
        bool m_DescriptionIsSet;

        std::shared_ptr<ApiError> m_InnerError;
        bool m_InnerErrorIsSet;

        std::wstring m_Message;
        bool m_MessageIsSet;
    };
}

