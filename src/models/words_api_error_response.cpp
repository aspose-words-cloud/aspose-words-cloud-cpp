/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="words_api_error_response.cpp">
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

#include "aspose_words_cloud/models/words_api_error_response.h"
#include "../thirdparty/json.hpp"

namespace aspose::words::cloud::api::models {
    void WordsApiErrorResponse::toJson(::nlohmann::json& json) const
    {
        WordsResponse::toJson(json);
        if (m_Error) m_Error->toJson(json["Error"]);
    }

    void WordsApiErrorResponse::fromJson(const ::nlohmann::json& json)
    {
        WordsResponse::fromJson(json);
        if (json.contains("Error") && !json["Error"].is_null()) m_Error->fromJson(json["Error"]);
    }

    std::shared_ptr< ApiError >& WordsApiErrorResponse::getError()
    {
        return m_Error;
    }

    void WordsApiErrorResponse::setError(std::shared_ptr< ApiError >& value)
    {
        m_Error = value;
    }
}
