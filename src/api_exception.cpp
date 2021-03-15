/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="api_exception.cpp">
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

#include "aspose_words_cloud/api_exception.h"

namespace aspose::words::cloud::api {
    ApiException::ApiException(
        int errorCode,
        const std::wstring& message,
        std::shared_ptr< aspose::words::cloud::api::models::WordsApiErrorResponse > response
    ) : m_ErrorCode(errorCode), m_Message(message), m_Response(response) {}

    std::shared_ptr< aspose::words::cloud::api::models::WordsApiErrorResponse > ApiException::getResponse() const
    {
        return m_Response;
    }

    int ApiException::getErrorCode() const
    {
        return m_ErrorCode;
    }

    const std::wstring& ApiException::getMessage() const
    {
        return m_Message;
    }
}