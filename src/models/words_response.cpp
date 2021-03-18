/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="words_response.cpp">
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

#include "aspose_words_cloud/models/words_response.h"
#include "../thirdparty/json.hpp"

namespace aspose::words::cloud::models {
    void WordsResponse::toJson(void* jsonIfc) const
    {
        ::nlohmann::json& json = *((::nlohmann::json*)jsonIfc);
        if (m_RequestId) json["RequestId"] = *m_RequestId;
    }

    void WordsResponse::fromJson(const void* jsonIfc)
    {
        ::nlohmann::json& json = *((::nlohmann::json*)jsonIfc);
        if (json.contains("RequestId") && !json["RequestId"].is_null()) m_RequestId = std::make_shared< std::wstring >(json["RequestId"].get< std::wstring >());
    }

    std::shared_ptr< std::wstring >& WordsResponse::getRequestId()
    {
        return m_RequestId;
    }

    void WordsResponse::setRequestId(std::shared_ptr< std::wstring >& value)
    {
        m_RequestId = value;
    }
}
