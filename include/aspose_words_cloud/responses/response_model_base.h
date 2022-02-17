/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="response_model_base.h">
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
#include <iostream>
#include <memory>
#include <string>
#include <string_view>
#include "aspose_words_cloud/common.h"

namespace aspose::words::cloud::responses {
    class ResponseModelBase
    {
    public:
        ASPOSE_WORDS_CLOUD_EXPORT virtual ~ResponseModelBase() = default;
        ASPOSE_WORDS_CLOUD_EXPORT virtual void deserialize(const std::string& contentType, const std::string_view& response) = 0;
        ASPOSE_WORDS_CLOUD_EXPORT void setStatusCode(int statusCode);
        ASPOSE_WORDS_CLOUD_EXPORT int getStatusCode() const;
        ASPOSE_WORDS_CLOUD_EXPORT void setErrorData(const std::string_view& errorData);
        ASPOSE_WORDS_CLOUD_EXPORT const std::wstring& getErrorMessage() const;

    private:
        int m_StatusCode = 0;
        std::wstring m_ErrorMessage;
    };
}