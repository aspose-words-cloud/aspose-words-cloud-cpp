/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_error.h">
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

namespace aspose::words::cloud::models {
    /// <summary>
    /// Api error.
    /// </summary>
    class ApiError : public ModelBase
    {
    public:
        virtual ~ApiError() = default;
        virtual void toJson(void* jsonIfc) const override;
        virtual void fromJson(const void* jsonIfc) override;

        /// <summary>
        /// Gets or sets the API error code.
        /// </summary>
        std::shared_ptr< std::wstring >& getCode();

        /// <summary>
        /// Gets or sets the API error code.
        /// </summary>
        void setCode(std::shared_ptr< std::wstring >& value);

        /// <summary>
        /// Gets or sets the server DateTime.
        /// </summary>
        std::shared_ptr< std::time_t >& getDateTime();

        /// <summary>
        /// Gets or sets the server DateTime.
        /// </summary>
        void setDateTime(std::shared_ptr< std::time_t >& value);

        /// <summary>
        /// Gets or sets the error description.
        /// </summary>
        std::shared_ptr< std::wstring >& getDescription();

        /// <summary>
        /// Gets or sets the error description.
        /// </summary>
        void setDescription(std::shared_ptr< std::wstring >& value);

        /// <summary>
        /// Gets or sets the inner error.
        /// </summary>
        std::shared_ptr< ApiError >& getInnerError();

        /// <summary>
        /// Gets or sets the inner error.
        /// </summary>
        void setInnerError(std::shared_ptr< ApiError >& value);

        /// <summary>
        /// Gets or sets the error message.
        /// </summary>
        std::shared_ptr< std::wstring >& getMessage();

        /// <summary>
        /// Gets or sets the error message.
        /// </summary>
        void setMessage(std::shared_ptr< std::wstring >& value);

    protected:
        std::shared_ptr< std::wstring > m_Code;
        std::shared_ptr< std::time_t > m_DateTime;
        std::shared_ptr< std::wstring > m_Description;
        std::shared_ptr< ApiError > m_InnerError;
        std::shared_ptr< std::wstring > m_Message;
    };
}

